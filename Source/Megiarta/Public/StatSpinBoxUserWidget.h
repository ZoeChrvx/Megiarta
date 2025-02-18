// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CommonTextBlock.h"
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
	/** TextBox pour la categorie */
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Characteristic;
	
	/** SpinBox pour la valeur de base */
	UPROPERTY(meta = (BindWidget))
	class USpinBox* SpinBoxBaseValue;  

	/** SpinBox pour les bonus/malus */
	UPROPERTY(meta = (BindWidget))
	class USpinBox* SpinBoxBonus;
	UPROPERTY(meta = (BindWidget))
	class USpinBox* SpinBoxMalus;

	/** TextBox pour la valeur final */
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

public:
	/** Variables pour les GD */
	
	/** Titre de la charactéristique */
	UPROPERTY(EditAnywhere, Category = "Nom des catégories")
	FString NameCategory = "Default";

	/** Initial */
	UPROPERTY(EditAnywhere, Category = "Caractéristique | Initial Value")
	float MinInitValue = 0;
	UPROPERTY(EditAnywhere, Category = "Caractéristique | Initial Value")
	float MaxInitValue = 0;

	/** Bonus */
	UPROPERTY(EditAnywhere, Category = "Caractéristique | Bonus Value")
	float MinBonusValue = 0;
	UPROPERTY(EditAnywhere, Category = "Caractéristique | Bonus Value")
	float MaxBonusValue = 0;

	/** Malus */
	UPROPERTY(EditAnywhere, Category = "Caractéristique | Malus Value")
	float MinMalusValue = 0;
	UPROPERTY(EditAnywhere, Category = "Caractéristique | Malus Value")
	float MaxMalusValue = 0;
};