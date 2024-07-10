/*

1.1、为什么要写虚函数？
虚函数的主要目的是实现多态。多态允许我们通过基类指针或引用调用子类的函数，
而不需要知道具体的子类类型。虚函数使得基类的接口可以在子类中实现不同的行为，
这样可以在运行时动态决定调用哪个函数版本。

具体优点包括：
接口一致性：允许基类定义接口，具体实现由子类完成，使得代码结构更加清晰和一致。
代码复用：可以编写更通用的代码，利用基类指针或引用操作不同的子类对象。
扩展性：可以方便地添加新的子类而无需修改现有代码，只需确保新子类实现了基类的虚函数。
1.2、子类为什么要重新父类虚函数？
子类重新父类的虚函数是为了提供特定于子类的实现。这是实现多态的核心，使得相同的接口在不同的子类
中有不同的行为。

具体原因包括：
实现特定行为：不同的子类可以有各自的实现方式。例如，Animal 类可以有一个虚函数 speak，而 Dog 
和 Cat 可以重新这个函数以实现各自的叫声。
遵循设计模式：许多设计模式（如策略模式、状态模式等）依赖于子类重新父类虚函数来实现灵活的行为变化。
扩展功能：可以在子类中扩展或修改基类的功能，而无需修改基类代码。
1.3、多态的定义：父类型引用/指针指向子类对象
多态是一种面向对象编程的特性，它允许父类型的引用或指针指向子类对象，并调用子类的实现。

具体定义：
父类型引用：使用基类的引用来操作子类对象。
父类型指针：使用基类的指针来操作子类对象。
通过这种方式，程序可以在运行时根据实际对象类型调用相应的函数版本，实现动态绑定。

示例代码：
cpp
复制代码
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

void makeAnimalSpeak(Animal& animal) {
    animal.speak();
}

int main() {
    Dog dog;
    Cat cat;
    
    makeAnimalSpeak(dog);  // 输出: Dog barks
    makeAnimalSpeak(cat);  // 输出: Cat meows

    return 0;
}
在这个示例中，makeAnimalSpeak 函数接收一个 Animal 类型的引用，但实际传入的是 Dog 和 Cat 对象。由于 speak 是虚函数，调用时会根据实际对象类型调用相应的实现。

1.4、为什么要在父类中使用虚析构？
在父类中使用虚析构函数是为了确保当我们通过基类指针或引用删除一个对象时，能够正确调用子类的析构函数，防止内存泄漏或资源未正确释放。

具体原因包括：
防止内存泄漏：如果基类析构函数不是虚函数，通过基类指针删除子类对象时只会调用基类的析构函数，而不会调用子类的析构函数，导致子类中的资源无法正确释放。
确保资源正确释放：正确调用子类的析构函数可以确保子类中分配的资源（如动态内存、文件句柄等）能够正确释放。
符合对象生命周期管理：在多态环境下，基类应该负责管理对象的生命周期，确保子类对象在销毁时能够正确释放其所有资源。
示例代码：
cpp
复制代码
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }
    virtual ~Base() { // 虚析构函数
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor" << endl;
    }
    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base* basePtr = new Derived(); // 基类指针指向子类对象
    delete basePtr; // 正确调用基类和子类的析构函数
    return 0;
}
在这个示例中，如果 Base 类的析构函数不是虚函数，delete basePtr 只会调用 Base 的析构函数，
而不会调用 Derived 的析构函数，导致 Derived 中的资源无法正确释放。通过使用虚析构函数，
delete basePtr 会正确调用 Derived 的析构函数，确保资源正确释放。

*/