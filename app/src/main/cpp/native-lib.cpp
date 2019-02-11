#include <jni.h>
#include <string>
#include "LogUtils.h"

/**
 * JNI静态注册
 */

extern "C" JNIEXPORT jstring
JNICALL
Java_com_lisn_jni_11_MainActivity_stringFromJNI1(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++ 11";

    LOGD("hello world");
    LOGD("%d", 10);
    LOGD("%s : %d", "num", 20);
    LOGD();

    return env->NewStringUTF(hello.c_str());
}
