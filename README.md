#  JNI_1
JNI test demo

#  LogUtils.h 工具类
如果想要关掉 log，注释掉 #define DEBUG 的定义就行。当然更好的做法是动态的定义这个宏。

在 CmakeLists.txt 中添加如下代码：

        IF (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows")
            ADD_DEFINITIONS(-DWindows)
        ELSE (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Linux")
            ADD_DEFINITIONS(-DLinux)
        ENDIF ()

#  使用方式
使用方式和 prinft 等函数一样。

        LOGD("hello world");
        LOGD("%d", 10);
        LOGD("%s : %d", "num", 20);
        LOGD();

#  效果展示
最终效果将是：[文件名][方法名][行号]: format... 的形式，例如

        [main.cpp][main][5]: hello world
        [main.cpp][main][6]: 10
        [main.cpp][main][7]: num : 20
        [main.cpp][main][8]:
---------------------