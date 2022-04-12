
# 阿里云镜像源加载并创建Android实现java调用C++整形转字符串方法

## 一、静态库构建调用

1、新建C++的Android项目

2、增加C++ 函数调用接口test.cpp/.h

3、在CMAKEtxt文本中增加test_demo、add_library(test_demo SHARED Test.cpp)、target_link_libraries(test_demo ${log-lib} )

4、构建之后生成静态库，路径：
```bash
D:\cpp_demo\app\.cxx\cmake\debug\x86_64\CMakeFiles\native-lib.dir\native-lib.cpp.o
D:\cpp_demo\app\.cxx\cmake\debug\x86_64\CMakeFiles\test_demo.dir\test.cpp.o
```

## 二、动态库构建调用


![image](https://user-images.githubusercontent.com/36963108/162713046-d6a4ab29-587c-46e7-9ded-c144b64b6ac0.png)







参考文献

https://blog.csdn.net/lftaoyuan/article/details/78645814

https://blog.csdn.net/mp624183768/article/details/71965116

https://blog.csdn.net/algorithmPro/article/details/97342638

https://blog.csdn.net/liitdar/article/details/81145791

https://blog.csdn.net/Kazinshy/article/details/120779786


android ndk cmake 编译so库和导入so库:https://blog.csdn.net/r_rock/article/details/112914626
