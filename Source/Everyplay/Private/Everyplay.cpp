#include "EveryplayPrivatePCH.h"
#include "EveryplaySettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogEveryplay);

#define LOCTEXT_NAMESPACE "Everyplay"

class FEveryplay : public IEveryplay
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FEveryplay, Everyplay )

void FEveryplay::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Everyplay",
										 LOCTEXT("RuntimeSettingsName", "Everyplay"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the Everyplay plugin"),
										 GetMutableDefault<UEveryplaySettings>()
										 );
	}

#if PLATFORM_ANDROID
	UEveryplayFunctions::InitJavaFunctions();
#endif
}


void FEveryplay::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
