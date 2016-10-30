#include "EveryplayPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;


DECLARE_JAVA_METHOD(AndroidThunkJava_Everyplay_StartRecording)
DECLARE_JAVA_METHOD(AndroidThunkJava_Everyplay_StopRecording)
DECLARE_JAVA_METHOD(AndroidThunkJava_Everyplay_PauseRecording)
DECLARE_JAVA_METHOD(AndroidThunkJava_Everyplay_ResumeRecording)
DECLARE_JAVA_METHOD(AndroidThunkJava_Everyplay_PlayLastRecording)
DECLARE_JAVA_METHOD(AndroidThunkJava_Everyplay_ShowEveryplaySharingModal)


void UEveryplayFunctions::InitJavaFunctions()
{
	INIT_JAVA_METHOD(AndroidThunkJava_Everyplay_StartRecording, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_Everyplay_StopRecording, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_Everyplay_PauseRecording, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_Everyplay_ResumeRecording, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_Everyplay_PlayLastRecording, "()V");
	INIT_JAVA_METHOD(AndroidThunkJava_Everyplay_ShowEveryplaySharingModal, "()V");
}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD



//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeEveryplayHidden();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeEveryplayHidden(JNIEnv* jenv, jobject thiz)
{


	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UEveryplayComponent::DidEveryplayHideDelegate.Broadcast();
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeEveryplayReadyForRecording(int enabled);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeEveryplayReadyForRecording(JNIEnv* jenv, jobject thiz, jint enabled)
{


	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UEveryplayComponent::IsEveryplayReadyForRecordingDelegate.Broadcast(enabled);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}



#endif




void UEveryplayFunctions::EveryplayStartRecording() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Everyplay_StartRecording);

		

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method EveryplayStartRecording\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}


void UEveryplayFunctions::EveryplayStopRecording() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Everyplay_StopRecording);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method EveryplayStopRecording\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

void UEveryplayFunctions::EveryplayPauseRecording() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Everyplay_PauseRecording);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method EveryplayPauseRecording\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

void UEveryplayFunctions::EveryplayResumeRecording() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Everyplay_ResumeRecording);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method EveryplayResumeRecording\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

void UEveryplayFunctions::EveryplayPlayLastRecording() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Everyplay_PlayLastRecording);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method EveryplayPlayLastRecording\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

void UEveryplayFunctions::EveryplayShowEveryplaySharingModal() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Everyplay_ShowEveryplaySharingModal);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method EveryplaySharingModal\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}


