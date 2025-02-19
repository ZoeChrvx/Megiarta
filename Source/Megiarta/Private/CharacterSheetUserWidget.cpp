// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSheetUserWidget.h"

UCharacterSheetUserWidget::UCharacterSheetUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UCharacterSheetUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(StatsContainer)
	{
		
	}
}

void UCharacterSheetUserWidget::AddStatWidget(FString StatName)
{
}
