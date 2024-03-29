### deque容器

##### deque容器基本概念
      双端数组，可以对头端进行插入删除操作
      deque与vector区别：
        vector对于头部的插入删除效率低，数据量越大，效率越低
        deque相对而言，对头部的插入删除速度回比vector快
        vector访问元素时的速度会比deque快,这和两者内部实现有关
      deque内部工作原理:
        deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
        中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
      deque容器的迭代器也是支持随机访问的

### stack容器

     stack是一种先进后出(First In Last Out,FILO)的数据结构，它只有一个出口
     栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
     栈中进入数据称为 --- 入栈 push
     栈中弹出数据称为 --- 出栈 pop

### queue容器

    Queue是一种先进先出(First In First Out,FIFO)的数据结构，它有两个出口
    队列容器允许从一端新增元素，从另一端移除元素
    队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
    队列中进数据称为 --- 入队 push
    队列中出数据称为 --- 出队 pop

### list容器

    将数据进行链式存储
    链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
    链表的组成：链表由一系列结点组成
    结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
    STL中的链表是一个双向循环链表
    由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器
    list的优点：
        采用动态存储分配，不会造成内存浪费和溢出
        链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
    list的缺点：
        链表灵活，但是空间(指针域) 和 时间（遍历）额外耗费较大
         List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。

    总结：STL中List和vector是两个最常被使用的容器，各有优缺点

### set/ multiset 容器

    set基本概念 简介：
        所有元素都会在插入时自动被排序
    本质：
        set/multiset属于关联式容器，底层结构是用二叉树实现。
    set和multiset区别：
        set不允许容器中有重复的元素
        multiset允许容器中有重复的元素

### map/ multimap容器

    简介：
        map中所有元素都是pair
        pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
        所有元素都会根据元素的键值自动排序
    本质：
        map/multimap属于关联式容器，底层结构是用二叉树实现。
    优点：
        可以根据key值快速找到value值
    map和multimap区别：
        map不允许容器中有重复key值元素
        multimap允许容器中有重复key值元素

### STL- 函数对象

    函数对象概念
    概念：
        重载函数调用操作符的类，其对象常称为函数对象
        函数对象使用重载的()时，行为类似函数调用，也叫仿函数
    本质：
        函数对象(仿函数)是一个类，不是一个函数


    函数对象使用 特点：
        函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
        函数对象超出普通函数的概念，函数对象可以有自己的状态
        函数对象可以作为参数传递

### 谓词

        谓词概念
            返回bool类型的仿函数称为谓词
            如果operator()接受一个参数，那么叫做一元谓词
            如果operator()接受两个参数，那么叫做二元谓词

### 内建函数对象
      内建函数对象意义
        概念：
            STL内建了一些函数对象
        分类:
            算术仿函数
                功能描述：
                     实现四则运算
                其中negate是一元运算，其他都是二元运算
                使用内建函数对象时，需要引入头文件 #include <functional>
                仿函数原型：
                    template<class T> T plus<T> //加法仿函数
                    template<class T> T minus<T> //减法仿函数
                    template<class T> T multiplies<T> //乘法仿函数
                    template<class T> T divides<T> //除法仿函数
                    template<class T> T modulus<T> //取模仿函数
                    template<class T> T negate<T> //取反仿函数
            关系仿函数
                功能描述：
                    实现关系对比
                总结：关系仿函数中最常用的就是greater<>大于
                仿函数原型：
                    template<class T> bool equal_to<T> //等于
                    template<class T> bool not_equal_to<T> //不等于
                    template<class T> bool greater<T> //大于
                    template<class T> bool greater_equal<T> //大于等于
                    template<class T> bool less<T> //小于
                    template<class T> bool less_equal<T> //小于等于
            逻辑仿函数
                功能描述：
                    实现逻辑运算
                总结：逻辑仿函数实际应用较少，了解即可
                函数原型：
                    template<class T> bool logical_and<T> //逻辑与
                    template<class T> bool logical_or<T> //逻辑或
                    template<class T> bool logical_not<T> //逻辑非
        用法：
            这些仿函数所产生的对象，用法和一般函数完全相同
            使用内建函数对象，需要引入头文件 #include<functional>
