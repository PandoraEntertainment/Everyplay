
#include "EveryplayPrivatePCH.h"

void UEveryplayComponent::OnRegister()
{
	Super::OnRegister();
	

	UEveryplayComponent::DidEveryplayHideDelegate.AddUObject(this, &UEveryplayComponent::DidEveryplayHide_Handler);

	UEveryplayComponent::IsEveryplayReadyForRecordingDelegate.AddUObject(this, &UEveryplayComponent::IsEveryplayReadyForRecording_Handler);

}

void UEveryplayComponent::OnUnregister()
{
	Super::OnUnregister();

	UEveryplayComponent::DidEveryplayHideDelegate.RemoveAll(this);

	UEveryplayComponent::IsEveryplayReadyForRecordingDelegate.RemoveAll(this);

}


UEveryplayComponent::FEveryplayHideDelegate UEveryplayComponent::DidEveryplayHideDelegate;

UEveryplayComponent::FEveryplayIsReadyForRecordingDelegate UEveryplayComponent::IsEveryplayReadyForRecordingDelegate;

