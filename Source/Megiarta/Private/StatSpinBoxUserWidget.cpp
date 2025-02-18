// Fill out your copyright notice in the Description page of Project Settings.


#include "StatSpinBoxUserWidget.h"

#include "Components/SpinBox.h"

UStatSpinBoxUserWidget::UStatSpinBoxUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UStatSpinBoxUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(Characteristic)
	{
		Characteristic->SetText(FText::FromString(NameCategory));
	}

	// if(SpinBoxBaseValue)
	// {
	// 	SpinBoxBaseValue->SetMinValue(MinInitValue);
	// 	SpinBoxBaseValue->SetMaxValue(MaxInitValue);
	// }
	//
	// if(SpinBoxBonus)
	// {
	// 	SpinBoxBonus->SetMinValue(MinBonusValue);
	// 	SpinBoxBonus->SetMaxValue(MaxBonusValue);
	// }
	//
	// if(SpinBoxMalus)
	// {
	// 	SpinBoxMalus->SetMinValue(MinMalusValue);
	// 	SpinBoxMalus->SetMaxValue(MaxMalusValue);
	// }

	UpdateTotal();
}

void UStatSpinBoxUserWidget::OnBaseValueChanged(float Value)
{
	UpdateTotal();	
}

void UStatSpinBoxUserWidget::OnBonusValueChanged(float Value)
{
	UpdateTotal();
}

void UStatSpinBoxUserWidget::OnMalusValueChanged(float Value)
{
	UpdateTotal();
}

void UStatSpinBoxUserWidget::UpdateTotal()
{
	if (!SpinBoxBaseValue || !SpinBoxBonus || !SpinBoxMalus || !TotalText)
		return;

	float BaseValue = SpinBoxBaseValue->GetValue();
	float BonusValue = SpinBoxBonus->GetValue();
	float MalusValue = SpinBoxMalus->GetValue();
	float Total = BaseValue + BonusValue + MalusValue;

	TotalText->SetText(FText::AsNumber(Total));
} 
