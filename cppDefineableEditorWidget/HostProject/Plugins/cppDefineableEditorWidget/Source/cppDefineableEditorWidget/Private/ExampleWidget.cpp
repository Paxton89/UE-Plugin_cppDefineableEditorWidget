#include "ExampleWidget.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/VerticalBox.h"
#include "EngineUtils.h"

UExampleWidget::UExampleWidget()
{
}

void UExampleWidget::UpdateText()
{
	ToolNameTextBlock->SetText(FText::FromString(ToolNameText));
}

void UExampleWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateText();
}

void UExampleWidget::DiscoButtonPressed()
{
	DiscoButton->SetBackgroundColor(FLinearColor::MakeRandomColor());
	auto Text = DiscoButton->GetChildAt(0);
	Cast<UTextBlock>(Text)->SetColorAndOpacity(FLinearColor::MakeRandomColor());
	
}

void UExampleWidget::UsefulButtonPressed()
{
	TActorIterator<AActor> Actoritr = TActorIterator<AActor>(GetWorld());
	while (Actoritr)
	{
		FRotator rotation = FRotator(0,15,0);
		Actoritr->SetActorRotation(Actoritr->GetActorRotation() + rotation);
		++Actoritr;
	}
}

void UExampleWidget::RenameButtonPressed()
{
	if(myTextBox->Text.IsEmpty())
		return;
	
	int counter = 1;
	TActorIterator<AActor> Actoritr = TActorIterator<AActor>(GetWorld());
	while (Actoritr)
	{
		//	Increase counter if new name already exist - then skip renaming this actor
		if(!Actoritr->IsSelected())
		{
			auto BaseNameAlreadyExist = Actoritr->GetActorLabel().Contains(myTextBox->Text.ToString());
			auto NameHasThisNumberAlready = Actoritr->GetActorLabel().Contains(FString::FromInt(counter));
			if(BaseNameAlreadyExist && NameHasThisNumberAlready)
			{
				counter++;
			}
		}
		//	Rename this actor
		else
		{
			FString UserText = myTextBox->Text.ToString();
			UserText.AppendInt(counter);
			Actoritr->SetActorLabel(UserText);
			counter++;
		}
		++Actoritr;	
	}
}
