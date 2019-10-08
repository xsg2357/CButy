# CButy
    这是C ++研究的起源
    C ++基础学习代码
## 文件操作
   — 程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
     通过文件可将数据持久化
     C++中对文件操作需要包含文件<fstream>
     - 文件类型可以分为两种
       1.文本文件 - 文件以文本的ASCII吗的形式存贮在计算机中
       2.二进制文件 - 文件以文本的二进制形式存储在计算机中 用户一般不能读他们
     - 操作文件的三大类
       1.写操作-ofstream 2.读操作 - ifstream 3.读写操作 - fstream
     - 文件打开方式，文件打开方式可以配合使用，利用|操作符
       ios::in 为读文件而打开文件
       ios::out 为写文件而打开文件
       ios::ate 初始位置：文件结尾
       ios::app 追加方式写文件爱你
       ios::trunc 如果文件存在先删除，在创建
       ios::binary 二进制方式，例如二进制写文件 ios::in|ios::binary
       - 二进制写文件 二进制写文件 ios::out|ios::binary
         二进制方式写文件主要利用流对象调用成员函数write
         函数原型：ostream&write（const char *buffer,int len）
         参数解释：字符指针buffer指向内存中一段存储空间，len读写的字节数
       - 二进制读文件 二进制写文件 ios::in|ios::binary
         二进制方式写文件主要利用流对象调用成员函数read
         函数原型：ostream&read（ char *buffer,int len）
         参数解释：字符指针buffer指向内存中一段存储空间，len读写的字节数  

