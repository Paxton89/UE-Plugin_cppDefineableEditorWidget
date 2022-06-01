#pragma once
#include "CoreMinimal.h"
#include "Editor/Blutility/Classes/EditorUtilityWidget.h"
#include "ExampleWidget.generated.h"

class UHorizontalBox;
class UVerticalBox;
class UTextBlock;
class UButton;
class UEditableTextBox;

UCLASS(BlueprintType)
class UExampleWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
	UExampleWidget();
	virtual void NativeConstruct() override;
	void UpdateText();
	
		UFUNCTION(BlueprintCallable)
	void DiscoButtonPressed();
		UFUNCTION(BlueprintCallable)
	void UsefulButtonPressed();
		UFUNCTION(BlueprintCallable)
	void RenameButtonPressed();

	//--	ToolTitle	--//
		UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UVerticalBox* MAIN_VertBox;
		UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UHorizontalBox* TitleHzBox;
		UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	UTextBlock* ToolNameTextBlock;
	FString ToolNameText = TEXT("ToolName");

#pragma region VertBox_Buttons
		UPROPERTY(meta=(BindWidgetOptional), BlueprintReadWrite)
	UButton* DiscoButton;
		UPROPERTY(meta=(BindWidgetOptional), BlueprintReadWrite)
	UButton* UsefulButton;
		UPROPERTY(meta=(BindWidgetOptional), BlueprintReadWrite)
	UButton* RenameButton;
#pragma endregion VertBox_Buttons
#pragma region VertBox_Description

#pragma endregion VertBox_Description
#pragma region VertBox_3
		UPROPERTY(meta=(BindWidget))
	UEditableTextBox* myTextBox;
#pragma endregion VertBox_3
};
