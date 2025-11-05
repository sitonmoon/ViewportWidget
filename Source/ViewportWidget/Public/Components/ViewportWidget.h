// Copyright 2024 Pentangle Studio under EULA https://www.unrealengine.com/en-US/eula/unreal

#pragma once

#include "Components/Widget.h"
#include "Components/ContentWidget.h"
#include "Widgets/SViewportWidget.h"

#include "ViewportWidgetEntry.h" // 必须加在这里
#include "ViewportWidget.generated.h"

class FPreviewScene;
//------------------------------------------------------
// UViewportWidget
//------------------------------------------------------

UCLASS()
class VIEWPORTWIDGET_API UViewportWidget : public UContentWidget
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Appearance)
	FColor BackgroundColor;

	UPROPERTY(EditAnywhere, Category = Appearance)
	float FOV = 90.f;

	UPROPERTY(EditAnywhere, Category = Appearance, meta = (ToolTip = "启用预览灯光"))
	bool EnablePreviewLighting = false;

	UPROPERTY(EditAnywhere, Category = Appearance, meta = (EditCondition = "EnablePreviewLighting"))
	float LightBrightness = 3.0f;

	UPROPERTY(EditAnywhere, Category = Appearance, meta = (EditCondition = "EnablePreviewLighting"))
	FRotator LightDirection;

	UPROPERTY(EditAnywhere, Category = Appearance, meta = (EditCondition = "EnablePreviewLighting"))
	float SkyBrightness = 1.0f;

	UFUNCTION(BlueprintCallable, Category="ViewportWidget")
	FTransform GetViewTransform() const { return ViewTransform; }

	UFUNCTION(BlueprintCallable, Category = "ViewportWidget")
	void SetViewTransform(FTransform viewTransform);

	UFUNCTION(BlueprintCallable, Category = "ViewportWidget")
	const TArray<FViewportWidgetEntry>& GetEntries() const { return Entries; }

	UFUNCTION(BlueprintCallable, Category = "ViewportWidget")
	void SetEntries(const TArray<FViewportWidgetEntry>& entries);

	UFUNCTION(BlueprintCallable, Category = "ViewportWidget")
	AActor* GetSpawnedActor(const int32 entryIndex) const;

	//~ UWidget interface
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	//~ End of UVisual interface

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:
	//~ UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~ End of UWidget interface

protected:
	TSharedPtr<SViewportWidget> MyViewport;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ViewportWidget")
	FTransform ViewTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ViewportWidget")
	TArray<FViewportWidgetEntry> Entries;
};