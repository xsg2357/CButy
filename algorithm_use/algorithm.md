
## STL- 常用算法

    算法主要是由头文件<algorithm> <functional> <numeric>组成。
    <algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
    <numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
    <functional>定义了一些模板类,用以声明函数对象。

### 常用遍历算法

    for_each //遍历容器
    transform //搬运容器到另一个容器中

### 常用查找算法

    find //查找元素
    find_if //按条件查找元素
    adjacent_find //查找相邻重复元素
    binary_search //二分查找法
    count //统计元素个数
    count_if //按条件统计元素个数
    按值统计用count，按条件统计用count_if

### 常用排序算法

    sort //对容器内元素进行排序
    random_shuffle //洗牌 指定范围内的元素随机调整次序
    merge // 容器元素合并，并存储到另一容器中
    reverse // 反转指定范围的元素