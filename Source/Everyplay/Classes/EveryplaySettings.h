#pragma once

#include "EveryplaySettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UEveryplaySettings : public UObject
{
	GENERATED_BODY()
	
public:
	UEveryplaySettings(const FObjectInitializer& ObjectInitializer);
	
	// General

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "Client Id"))
	FString ClientId;

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "Client Secret"))
	FString ClientSecret;

	
	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "Redirect URI"))
	FString RedirectURI;

};
