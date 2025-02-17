// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "StatSpinBoxUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MEGIARTA_API UStatSpinBoxUserWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UStatSpinBoxUserWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

private:
	/** SpinBox pour la valeur de base */
	UPROPERTY(meta = (BindWidget))
	class USpinBox* SpinBoxBaseValue;  

	/** SpinBox pour les bonus/malus */
	UPROPERTY(meta = (BindWidget))
	class USpinBox* SpinBoxBonus;
	UPROPERTY(meta = (BindWidget))
	class USpinBox* SpinBoxMalus;

	/** TextBow pour la valeur final */
	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* TotalText;

	/** Gestion des changements de valeurs */
	UFUNCTION()
	void OnBaseValueChanged(float Value);

	UFUNCTION()
	void OnBonusValueChanged(float Value);
	
	UFUNCTION()
	void OnMalusValueChanged(float Value);

	/** Met à jour le total */
	void UpdateTotal();
	
};
