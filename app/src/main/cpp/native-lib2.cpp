#include <jni.h>
#include <string>
#include "LogUtils.h"
/**
 * JNI动态注册
 */
extern "C" {

jstring stringFromJNI(JNIEnv *env, jobject instance) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

jint add(JNIEnv *env, jclass clazz, jint a, jint b) {
    LOGD("hello world");
    LOGD("%d", 10);
    LOGD("%s : %d", "num", 20);
    LOGD();
    return a + b;
}

jint RegisterNatives(JNIEnv *env) {
//    com.lisn.jni_1
    jclass clazz = env->FindClass("com/lisn/jni_1/MainActivity");
    if (clazz == NULL) {
        LOGE("con't find class: com/lisn/jni_1/MainActivity");
        return JNI_ERR;
    }
    JNINativeMethod methods_MainActivity[] = {
            {"stringFromJNI", "()Ljava/lang/String;", (void *) stringFromJNI},
            {"add",           "(II)I",                (void *) add}
    };
    // int len = sizeof(methods_MainActivity) / sizeof(methods_MainActivity[0]);
    return env->RegisterNatives(clazz, methods_MainActivity,
                                sizeof(methods_MainActivity) / sizeof(methods_MainActivity[0]));
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    jint result = RegisterNatives(env);
    LOGD("RegisterNatives result: %d", result);
//    if(!RegisterNatives(env)){
//        return -1;
//    }

    return JNI_VERSION_1_6;
}

}
