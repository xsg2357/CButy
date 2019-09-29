//
// Created by Administrator on 2019/9/29.
//
#include <iostream>
#include <string>

using namespace std;

/**
 * 以子类命名传进父类的白能量时，需要地址晚绑定，实现动态多态
 * 实现地址晚绑定，使用虚函数，在父类中进行
 *  语法：virtual 函数类型  函数名
 * 动态多态满足条件：
 *      1.有继承关系
 *      2.子类重写父类的虚函数 函数返回值类型、函数名、函数参数列表完全相同 virtual可写不可泄
 * 动态多态使用：
 *      父类的指针和引用 指向0子类对象
 */
class Animal {
public:

    /**
     * vfptr v-virtual f-function ptr-pointrt
     * 虚函数指针
     * vfptr ->vftable(虚函数表)：记录虚函数的地址
     * 当子类重写父类的虚函数
     * 子类中的虚函数表内部会替换成子类的虚函数地址
     * 当父类的指针或者引用指向子类的对象时，会发生多态
     *
     */
    virtual void speak() {

        cout << "animal is speaking..." << endl;

    }

};

class Cat : public Animal {

    void speak() {

        cout << "Cat is speaking..." << endl;

    }
};

class Dog : public Animal {

    void speak() {

        cout << "Dog is speaking..." << endl;

    }
};

void doSpeak(Animal &animal) {
    animal.speak();
}

int main134() {

    Cat cat;
    doSpeak(cat); //Animal &animal =  cat

    Dog dog;
    doSpeak(dog); //Animal &animal =  dog

    /* Cat is speaking...
     Dog is speaking...*/

    cout << "sizeof(Animal) == " << sizeof(Animal) << endl; // 1 byte<-virtual -> 4 byte

    return 0;
}

class Calculter {
public:

    int getResult(string oper) {
        if (oper == "+") {
            return num1 + num2;
        } else if (oper == "-") {
            return num1 - num2;
        } else if (oper == "*") {
            return num1 * num2;
        } else if (oper == "/") {
            return num1 / num2;
        }

        return 0;
    }


    int num1;
    int num2;
};

/**
 * 多态eg： 计算器（普通实现）
 */
void cal_test01() {
    Calculter cal;

    int num1 = 10;
    int num2 = 10;

    cal.num1 = num1;
    cal.num2 = num2;

    cout << num1 << " + " << num2 << " = " << cal.getResult("+") << endl;
    cout << num1 << " - " << num2 << " = " << cal.getResult("-") << endl;
    cout << num1 << " * " << num2 << " = " << cal.getResult("*") << endl;
    cout << num1 << " / " << num2 << " = " << cal.getResult("/") << endl;

    //    10 + 10 = 20
    //    10 - 10 = 0
    //    10 * 10 = 100
    //    10 / 10 = 1

}


/**
 * 多态eg： 计算器
 */
class AbstractCalculator {
public:

    virtual int getResult() {

        return 0;
    }

    int num1;
    int num2;
};

class AddCalculator : public AbstractCalculator {
public:

    int getResult() {

        return num1 + num2;
    }

};

class SubCalculator : public AbstractCalculator {
public:

    int getResult() {

        return num1 - num2;
    }

};

class MulCalculator : public AbstractCalculator {
public:

    int getResult() {

        return num1 * num2;
    }

};

/**
 * 开闭原则：对修改进行关闭 对扩展进行开放
 */
int main135() {

//    cal_test01();

    AbstractCalculator *abs = new AddCalculator;
    abs->num1 = 10;
    abs->num2 = 10;
    cout << abs->num1 << " + " << abs->num2 << " = " << abs->getResult() << endl;
    delete abs;

    abs = new SubCalculator;
    abs->num1 = 10;
    abs->num2 = 10;
    cout << abs->num1 << " - " << abs->num2 << " = " << abs->getResult() << endl;
    delete abs;

    abs = new MulCalculator;
    abs->num1 = 10;
    abs->num2 = 10;
    cout << abs->num1 << " * " << abs->num2 << " = " << abs->getResult() << endl;
    //    10 + 10 = 20
    //    10 - 10 = 0
    //    10 * 10 = 100
    return 0;
}


/**
 * 抽象类-纯虚函数
 *  纯虚函数语法：vitural 返回值类型 函数名（参数列表） = 0
 */
class BaseClass {
public:
    virtual void func() = 0;
};

class ChildClass : public BaseClass {

public:
    void func() {
        cout << "ChildClass func" << endl;
    }
};

/**
 * 抽象类eg:制作饮品
 */
class AbstractDrinking {

public:

    /**
     * 烧水
     */
    virtual void boil() = 0;

    /**
     * 冲泡
     */
    virtual void brew() = 0;

    /**
     * 导入杯中
     */
    virtual void pourInCup() = 0;

    /**
     * 加入辅料
     */
    virtual void putSomething() = 0;

    /**
     * 制作饮品
     */
    void makeDrink() {
        boil();
        brew();
        pourInCup();
        putSomething();
    }

};

class Coffee : public AbstractDrinking {


    void boil() override {
        cout << "Coffee boil func" << endl;
    }

    void brew() override {
        cout << "Coffee brew func" << endl;
    }

    void pourInCup() override {
        cout << "Coffee pourInCup func" << endl;
    }

    void putSomething() override {
        cout << "Coffee putSomething func" << endl;
    }
};

class Teas : public AbstractDrinking {

    void boil() override {
        cout << "Tea boil func" << endl;
    }

    void brew() override {
        cout << "Tea brew func" << endl;
    }

    void pourInCup() override {
        cout << "Tea pourInCup func" << endl;
    }

    void putSomething() override {
        cout << "Tea putSomething func" << endl;
    }
};

void doDrinkWork(AbstractDrinking *abstractDrinking){

    abstractDrinking->makeDrink();

    delete  abstractDrinking; //释放
    abstractDrinking = NULL;
}

int main136() {

    BaseClass *baseClass = new ChildClass;
    baseClass->func(); //ChildClass func

    doDrinkWork(new Coffee);
    //    Coffee boil func
    //    Coffee brew func
    //    Coffee pourInCup func
    //    Coffee putSomething func
    doDrinkWork(new Teas);
    //    Tea boil func
    //    Tea brew func
    //    Tea pourInCup func
    //    Tea putSomething func

    return 0;
}

/**
 * 虚析构或者纯虚析构
 * 纯虚析构声明和实现都需要进行
 */
class Car{
public:

    Car()  {
        cout <<" Car " << endl;
    }

     virtual void speak() = 0;

    /*virtual  ~Car()  { // 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
        //解决方式：将父类中的析构函数改为虚析构或者纯虚析构
        cout <<" ~ Car " << endl;
    }*/

    virtual  ~ Car() = 0; //纯虚析构声明


};

//纯虚析构实现
Car::~Car() {
    cout <<" ~ Car " << endl;
}

class ShopCar : public  Car{
public:

    ShopCar(string name)  {
        cout <<" ShopCar " << endl;
        _name = new string(name);
    }

    void speak() override {
        cout << *_name <<"ShopCar speak..." << endl;
    }

    ~ShopCar(){
        if(_name != NULL){
            //多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
            //会内存泄漏
            cout <<"~ ShopCar " << endl;

            delete _name;
            _name = NULL;
        }
    }

    string *_name;
};

void car_test01(){

    Car *car = new ShopCar("Tom");
    car->speak();
    delete car;
    car = NULL;

   /* Car
            ShopCar
    TomShopCar speak...
            ~ ShopCar
    ~ Car*/


}

/**
 * 多态综合eg：电脑组装
 */
class  CPU {
public:
    virtual  void calculator() =0;
};
class  VideoCard {
public:
    virtual  void display() =0;
};
class  Memory {
public:
    virtual  void storage() =0;
};
class  Computer {

public:
    Computer(CPU *cpu, VideoCard *videoCard, Memory *memory) : cpu(cpu), videoCard(videoCard), memory(memory) {}

    void vork(){
        cpu->calculator();
        videoCard->display();
        memory->storage();
    }

    ~Computer(){
        if (cpu != NULL){
            delete cpu;
            cpu = NULL;
        }
        if (videoCard != NULL){
            delete videoCard;
            videoCard = NULL;
        }
        if (memory != NULL){
            delete memory;
            memory = NULL;
        }
    }


private:
    CPU *cpu;
    VideoCard *videoCard;
    Memory *memory;
};

class INtelCPU:public CPU{

public:

    void calculator() override {
        cout << "INtelCPU calculator..." << endl;
    }
};
class INtelVideoCard:public VideoCard{

public:

    void display() override {
        cout << "INtelCPU display..." << endl;
    }
};
class INtelMemory:public Memory{

public:

    void storage() override {
        cout << "INtelCPU storage..." << endl;
    }
};
class LenovoINtelCPU:public CPU{

public:

    void calculator() override {
        cout << "LenovoINtelCPU calculator..." << endl;
    }
};
class LenovoINtelVideoCard:public VideoCard{

public:

    void display() override {
        cout << "LenovoINtelVideoCard display..." << endl;
    }
};
class LenovoINtelMemory:public Memory{

public:

    void storage() override {
        cout << "LenovoINtelMemory storage..." << endl;
    }
};


int main137(){
    car_test01();

    CPU *intelCpu = new INtelCPU;
    CPU *leIntelCpu = new LenovoINtelCPU;

    VideoCard *videoCard = new INtelVideoCard;
    VideoCard *leVideoCard = new LenovoINtelVideoCard;

    Memory * intelmemory = new INtelMemory;
    Memory * leintelmemory = new LenovoINtelMemory;

    Computer * computer = new Computer(intelCpu,videoCard,intelmemory);
    Computer * computer1 = new Computer(leIntelCpu,leVideoCard,leintelmemory);
    Computer * computer2 = new Computer(leIntelCpu,videoCard,leintelmemory);
    computer->vork();
    computer1->vork();
    computer2->vork();

    delete computer;
    delete computer1;
    delete computer2;

   /* INtelCPU calculator...
    INtelCPU display...
    INtelCPU storage...
    LenovoINtelCPU calculator...
    LenovoINtelVideoCard display...
    LenovoINtelMemory storage...
    LenovoINtelCPU calculator...
    INtelCPU display...
    LenovoINtelMemory storage...*/


    return  0;
}