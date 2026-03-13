// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputAction.h"


APlayerPawn::APlayerPawn()
{
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("TSpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 300.0f;
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	
}


void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
				LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (DefaultMappingContext)
				{
					InputSubsystem->AddMappingContext(DefaultMappingContext, 0);
				}
			}
		}
	}
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInputComponent)
	{
		return;
	}
	
	if (MoveAction)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
	}
	
	if (LookAction)
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerPawn::Look);
	}
	
	if (MoveUpAction)
	{
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &APlayerPawn::MoveUp);
	}
	
}

void APlayerPawn::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	
	if (Controller == nullptr)
	{
		return;
	}
	
	const FRotator ControlRotation = Controller->GetControlRotation();
	// FRotator — углы поворота в Unreal
	
	const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
	//Оставляем только поворот по горизонтали
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation). GetUnitAxis(EAxis::X);
	
	const FVector RightDirection = FRotationMatrix(YawRotation). GetUnitAxis(EAxis::Y);
	
	AddMovementInput(ForwardDirection, MovementVector.Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void APlayerPawn::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	// FVector2D = смещение мыши или стика по двум осям. 
	
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void APlayerPawn::MoveUp(const FInputActionValue& Value)
{
	const float AxisValue = Value.Get<float>();
	// float - значение оси вверх/вниз
	
	AddMovementInput(FVector::UpVector, AxisValue);
}


void APlayerPawn::Server_Move_Implementation(const FVector& Direction, float Scale)
{
	AddMovementInput(Direction, Scale);
}