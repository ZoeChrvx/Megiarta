// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CharacterSheetUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MEGIARTA_API UCharacterSheetUserWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UCharacterSheetUserWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

	/** Conteneur pour les widgets de caractéristiques */
	UPROPERTY(meta = (BindWidget))
	class UCommonTileView* StatsContainer;

	/** Ajoute une instance de `UStatSpinBoxWidget` */
	void AddStatWidget(FString StatName);
};
