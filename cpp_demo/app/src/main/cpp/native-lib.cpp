#include <jni.h>
#include <string>
#include <cstddef>
#include <typeinfo>
#include <iostream>
#include "Test.h"
using namespace std;

int ress(int x,int y){
    return x+y;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cpp_1demo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string strTest;
    strTest = to_string(ress(1,2)) + " is a string.";
    std::string hello = "Hello from C++"+strTest;

    printf("x+y=%d\n",ress(1,2));
//    Test test;
//    test.mode(hello);
    return env->NewStringUTF(hello.c_str());
}