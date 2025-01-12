#ifndef DLIB_H
#define DLIB_H

#ifndef _WIN32
    #define XCPP_API
#else
    #ifdef dlib_STATIC
        #define XCPP_API
    #else
        // windows encoding use utf-8 with BOM
        // dlib 库文件调用时，做 dllexport
        // 调用 dlib 库时，做 dllimport
        #ifdef dlib_EXPORTS
            #define XCPP_API __declspec(dllexport)
        #else
            #define XCPP_API __declspec(dllimport)
        #endif
    #endif
#endif // for _WIN32

XCPP_API void Dlib();

#endif // for DLIB_H
