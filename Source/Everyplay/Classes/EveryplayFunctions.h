#pragma once

#include "EveryplayFunctions.generated.h"



UCLASS(NotBlueprintable)
class UEveryplayFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Everyplay"), Category = "Everyplay|Methods")
	static void EveryplayStartRecording();


	UFUNCTION(BlueprintCallable, meta = (Keywords = "Everyplay"), Category = "Everyplay|Methods")
	static void EveryplayStopRecording();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Everyplay"), Category = "Everyplay|Methods")
	static void EveryplayPauseRecording();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Everyplay"), Category = "Everyplay|Methods")
	static void EveryplayResumeRecording();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Everyplay"), Category = "Everyplay|Methods")
	static void EveryplayPlayLastRecording();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Everyplay"), Category = "Everyplay|Methods")
	static void EveryplayShowEveryplaySharingModal();



};
