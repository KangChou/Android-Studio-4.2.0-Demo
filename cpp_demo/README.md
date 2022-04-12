
# 阿里云镜像源加载并创建Android实现java调用C++整形转字符串方法

## 一、静/动态库构建与调用

1、新建C++的Android项目

2、增加C++ 函数调用接口test.cpp/.h

3、在CMAKEtxt文本中增加test_demo、add_library(test_demo SHARED Test.cpp)、target_link_libraries(test_demo ${log-lib} )

4、构建之后生成静态库，路径：
```bash
D:\cpp_demo\app\.cxx\cmake\debug\x86_64\CMakeFiles\native-lib.dir\native-lib.cpp.o
D:\cpp_demo\app\.cxx\cmake\debug\x86_64\CMakeFiles\test_demo.dir\test.cpp.o
```
生成动态库，路径：
```bash
D:\cpp_demo\app\build\intermediates\cmake\debug\obj\arm64-v8a\libtest_demo.so
D:\cpp_demo\app\build\intermediates\cmake\debug\obj\arm64-v8a\libnative-lib.so
```
![image](https://user-images.githubusercontent.com/36963108/162862171-89e221b8-e605-4377-a8e4-39b327088018.png)



## 二、动态库构建在指定路径下的NDK调用

新建一个android ndk项目，将上个项目的头文件和so库拷贝到cpp文件夹下
![image](https://user-images.githubusercontent.com/36963108/162864045-a9e02f38-455d-402e-9493-6aca10eafb54.png)
编写对应的cmake
```

cmake_minimum_required(VERSION 3.4.1)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp )


find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

add_library(test01 SHARED IMPORTED)#导入外部库 
set_target_properties(test01 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/ku/libtest01.so )#设置导入外部库的路径

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
        test01
        )

```

参考来源:https://blog.csdn.net/r_rock/article/details/112914626

NDK Android CMake 编译so库可参考：https://github.com/seeways/NDKDemo


![image](https://user-images.githubusercontent.com/36963108/162713046-d6a4ab29-587c-46e7-9ded-c144b64b6ac0.png)







参考文献

https://blog.csdn.net/lftaoyuan/article/details/78645814

https://blog.csdn.net/mp624183768/article/details/71965116

https://blog.csdn.net/algorithmPro/article/details/97342638

https://blog.csdn.net/liitdar/article/details/81145791

https://blog.csdn.net/Kazinshy/article/details/120779786


android ndk cmake 编译so库和导入so库:https://blog.csdn.net/r_rock/article/details/112914626
