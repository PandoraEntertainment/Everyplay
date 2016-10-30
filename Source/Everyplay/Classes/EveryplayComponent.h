
#pragma once

#include "EveryplayFunctions.h"
#include "EveryplayComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UEveryplayComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	DECLARE_MULTICAST_DELEGATE(FEveryplayHideDelegate);

	static FEveryplayHideDelegate DidEveryplayHideDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEveryplayHideDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FEveryplayHideDynDelegate DidEveryplayHide;

	DECLARE_MULTICAST_DELEGATE_OneParam(FEveryplayIsReadyForRecordingDelegate, int32);

	static FEveryplayIsReadyForRecordingDelegate IsEveryplayReadyForRecordingDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEveryplayIsReadyForRecordingDynDelegate, int32, enabled);

	UPROPERTY(BlueprintAssignable)
	FEveryplayIsReadyForRecordingDynDelegate IsEveryplayReadyForRecording;



	void OnRegister() override;
	void OnUnregister() override;
	
private:	

	void DidEveryplayHide_Handler() { DidEveryplayHide.Broadcast(); }

	void IsEveryplayReadyForRecording_Handler(int enabled) { IsEveryplayReadyForRecording.Broadcast(enabled); }


};
