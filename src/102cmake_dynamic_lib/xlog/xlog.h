#ifndef XLOG_H
#define XLOG_H

#ifndef _WIN32
    #define XCPP_API
#else
    // windows encoding use utf-8 with BOM
    // __declspec(dllexport) 到处 XLog 类 的函数到 lib 文件中
    // xlog 库文件调用时，做 dllexport
    // test_xlog 库文件调用时，做 dllimport
    #ifdef xlog_EXPORTS
        #define XCPP_API __declspec(dllexport)
    #else
        #define XCPP_API __declspec(dllimport)
    #endif
#endif // for _WIN32

class XCPP_API XLog
{
public:
    XLog();
};

#endif