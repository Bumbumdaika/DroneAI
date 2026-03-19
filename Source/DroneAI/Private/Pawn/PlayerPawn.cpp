#include "Pawn/PlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	SetReplicateMovement(true);

	AutoPossessAI = EAutoPossessAI::Disabled;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 300.0f;
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay: %s | LocalRole=%d | RemoteRole=%d | Controller=%s"),
		*GetName(),
		(int32)GetLocalRole(),
		(int32)GetRemoteRole(),
		*GetNameSafe(GetController()));

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
				LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (DefaultMappingContext)
				{
					InputSubsystem->ClearAllMappings();
					InputSubsystem->AddMappingContext(DefaultMappingContext, 0);

					UE_LOG(LogTemp, Warning, TEXT("MappingContext added on %s"), *GetName());
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("DefaultMappingContext is NULL on %s"), *GetName());
				}
			}
		}
	}
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!HasAuthority())
	{
		return;
	}

	AController* CurrentController = GetController();
	if (!CurrentController)
	{
		return;
	}

	const FRotator ControlRotation = CurrentController->GetControlRotation();
	const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	const FVector UpDirection = FVector::UpVector;

	FVector MoveDirection = ForwardDirection * CachedMoveInput.Y
		+ RightDirection * CachedMoveInput.X
		+ UpDirection * CachedUpInput;

	if (!MoveDirection.IsNearlyZero())
	{
		MoveDirection = MoveDirection.GetSafeNormal();

		const FVector DeltaMove = MoveDirection * MoveSpeed * DeltaTime;
		AddActorWorldOffset(DeltaMove, true);

		UE_LOG(LogTemp, Warning, TEXT("Server Move Tick: %s | Input=(%s, %f) | Location=%s"),
			*GetName(),
			*CachedMoveInput.ToString(),
			CachedUpInput,
			*GetActorLocation().ToString());
	}
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent called on %s"), *GetName());

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("EnhancedInputComponent is NULL on %s"), *GetName());
		return;
	}

	if (MoveAction)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &APlayerPawn::Move);
		UE_LOG(LogTemp, Warning, TEXT("MoveAction bound on %s"), *GetName());
	}

	if (LookAction)
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerPawn::Look);
		UE_LOG(LogTemp, Warning, TEXT("LookAction bound on %s"), *GetName());
	}

	if (MoveUpAction)
	{
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &APlayerPawn::MoveUp);
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Completed, this, &APlayerPawn::MoveUp);
		UE_LOG(LogTemp, Warning, TEXT("MoveUpAction bound on %s"), *GetName());
	}
}

void APlayerPawn::Move(const FInputActionValue& Value)
{
	CachedMoveInput = Value.Get<FVector2D>();

	UE_LOG(LogTemp, Warning, TEXT("Move called on %s | MoveInput=%s | Owner=%s"),
		*GetName(),
		*CachedMoveInput.ToString(),
		*GetNameSafe(GetOwner()));

	if (HasAuthority())
	{
		return;
	}

	Server_SetMoveInput(CachedMoveInput, CachedUpInput);
}

void APlayerPawn::MoveUp(const FInputActionValue& Value)
{
	CachedUpInput = Value.Get<float>();

	UE_LOG(LogTemp, Warning, TEXT("MoveUp called on %s | UpInput=%f"),
		*GetName(),
		CachedUpInput);

	if (HasAuthority())
	{
		return;
	}

	Server_SetMoveInput(CachedMoveInput, CachedUpInput);
}

void APlayerPawn::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void APlayerPawn::Server_SetMoveInput_Implementation(const FVector2D& NewMoveInput, float NewUpInput)
{
	CachedMoveInput = NewMoveInput;
	CachedUpInput = NewUpInput;

	UE_LOG(LogTemp, Warning, TEXT("Server_SetMoveInput on %s | MoveInput=%s | UpInput=%f"),
		*GetName(),
		*CachedMoveInput.ToString(),
		CachedUpInput);
}