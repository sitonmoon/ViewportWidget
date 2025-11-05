// Copyright 2024 Pentangle Studio under EULA https://www.unrealengine.com/en-US/eula/unreal

#pragma once

#include "Widgets/SViewport.h"
#include "ViewportWidgetEntry.h"
#include "Components/Viewport.h"

class FSceneViewport;
class FCustomViewportClient;
class FCustomUMGViewportClient;
class FCustomPreviewScene;
class FPreviewScene;

//------------------------------------------------------
// SViewportWidget
//------------------------------------------------------

class VIEWPORTWIDGET_API SViewportWidget : public SViewport
{
public:
	SLATE_BEGIN_ARGS(SViewportWidget) :_ViewportSize(SViewport::FArguments::GetDefaultViewportSize()), _ViewTransform(FTransform::Identity), _Entries(FViewportWidgetEntry::GetEmptyCollection()) {}
	SLATE_ATTRIBUTE(FVector2D, ViewportSize);
	SLATE_ATTRIBUTE(FTransform, ViewTransform);
	SLATE_ATTRIBUTE(TArray<FViewportWidgetEntry>, Entries);
	SLATE_END_ARGS()

	SViewportWidget();

	void Construct(const FArguments& InArgs);

	void SetViewTransform(const FTransform& viewTransform);

	void SetEntries(TArray<FViewportWidgetEntry>& entries);

	void SetViewportBackgroudColor(FLinearColor InColor);
	void SetViewportFOV(float InFOV);
	void SetViewportCubemap(UTextureCube* InCubemap);
	void UpdateCapture();
	void SetViewportSkyBrightness(float brightness);
	void SetViewportLightBrightness(float brightness);
	void SetViewportLightDirection(FRotator& InLightDir);

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

	/** @return True if the viewport is currently visible */
	virtual bool IsVisible() const;

	TSharedPtr<FCustomUMGViewportClient> GetViewportClient() const { return Client; }

	/**
	 * @return The current FSceneViewport shared pointer
	 */
	TSharedPtr<FSceneViewport> GetSceneViewport() { return SceneViewport; }

	TWeakObjectPtr<AActor> GetSpawnedActor(const int32 entryIndex) const;

protected:

	void CleanEntries();
	void AddEntries();

	virtual void SetupSpawnedActor(AActor* actor, UWorld* world) {}

protected:
	/** Viewport that renders the scene provided by the viewport client */
	TSharedPtr<FSceneViewport> SceneViewport;

	/** The client responsible for setting up the scene */
	TSharedPtr<FCustomUMGViewportClient> Client;

	/** The last time the viewport was ticked (for visibility determination) */
	double LastTickTime;

	TSharedPtr<FPreviewScene> PreviewScene;

	TAttribute<FTransform> ViewTransform;

	TAttribute<TArray<FViewportWidgetEntry>> Entries;
};