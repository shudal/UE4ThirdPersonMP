// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThirdPersonMPProjectile.generated.h"

UCLASS()
class THIRDPERSONMP_API AThirdPersonMPProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThirdPersonMPProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	// ���ڲ�����ײ�����������
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USphereComponent* SphereComponent;

	// �����ṩ�����Ӿ�����Ч���ľ�̬�����塣
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* StaticMesh;

	// ���ڴ���Ͷ�����ƶ����ƶ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UProjectileMovementComponent* ProjectileMovementComponent;

	// ��Ͷ����ײ���������󲢱�ըʱʹ�õ����ӡ�
	UPROPERTY(EditAnywhere, Category = "Effects")
		class UParticleSystem* ExplosionEffect;

	//��Ͷ���ｫ��ɵ��˺����ͺ��˺���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
		TSubclassOf<class UDamageType> DamageType;

	//��Ͷ������ɵ��˺���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
		float Damage;

protected:
	virtual void Destroyed() override;
	
	UFUNCTION(Category = "Projectile")
	void OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
