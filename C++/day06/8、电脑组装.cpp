#include<iostream>

using namespace std;

//三个组件的抽象类
class CPU{
public:
    //纯虚函数
    virtual void calculate() = 0;
    //虚析构
    virtual ~CPU(){};
};

class VideoCard{
public:
    //纯虚函数
    virtual void display() = 0;
    //虚析构
    virtual ~VideoCard(){};
};

class Memory{
public:
    //纯虚函数
    virtual void storage() = 0;
    //虚析构
    virtual ~Memory(){};
};

//两个厂家
class InterCPU :public CPU{
public:
    //纯虚函数
    virtual void calculate(){
        cout<<"Inter的CPU在计算"<<endl;
    }
};

class InterVideoCard :public VideoCard{
public:
    //纯虚函数
    virtual void display(){
        cout<<"Inter的显卡在显示"<<endl;
    }
};
class InterMemory :public Memory{
public:
    //纯虚函数
    virtual void storage(){
        cout<<"Inter的内存条在存储"<<endl;
    }
};

class LenovoCPU :public CPU{
public:
    //纯虚函数
    virtual void calculate(){
        cout<<"Lenovo的CPU在计算"<<endl;
    }
};

class LenovoVideoCard :public VideoCard{
public:
    //纯虚函数
    virtual void display(){
        cout<<"Lenovo的显卡在显示"<<endl;
    }
};
class LenovoMemory :public Memory{
public:
    //纯虚函数
    virtual void storage(){
        cout<<"Lenovo的内存条在存储"<<endl;
    }
};

//创建电脑类

class Computer{

//组件成员变量
private:
    CPU * m_cpu;//CPU
    VideoCard * m_vc ;//显卡
    Memory * m_m;//内存条
//创建电脑
//构造函数
public:
    Computer(CPU * cpu,VideoCard * videoCard,Memory * memory){
        m_cpu = cpu;
        m_vc  = videoCard;
        m_m   = memory;
    }

    //电脑运行
    void work(){
            //让电脑的零件工作起来
            m_cpu->calculate();
            m_vc->display();
            m_m->storage();
    }

    //析构函数
    ~Computer(){
        //清理干净
        //释放CPU
        if(m_cpu!=NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_vc!=NULL){
            delete m_vc;
            m_vc = NULL;
        }
        if(m_m!=NULL){
            delete m_m;
            m_m = NULL;
        }
    }

};


int main(){

    //创建CPU
    CPU * interCPU = new InterCPU;
    //创建显卡
    VideoCard * interVideoCard = new InterVideoCard;
    //创建内存条
    Memory * interMemory = new InterMemory;

    //组装第一台电脑
    cout<<"第一台电脑："<<endl;
    Computer * c1 = new Computer(interCPU,interVideoCard,interMemory);
    c1->work();
    delete c1;

    cout<<"===================="<<endl;
    cout<<"第二台电脑："<<endl;
    //创建CPU
    CPU * lenovoCPU = new LenovoCPU;
    //创建显卡
    VideoCard * lenovoVideoCard = new LenovoVideoCard;
    //创建内存条
    Memory * lenovoMemory = new LenovoMemory;

    Computer * c2 = new Computer(lenovoCPU,lenovoVideoCard,lenovoMemory);
    c2->work();
    delete c2;
    cout<<"===================="<<endl;
    cout<<"第三台电脑："<<endl;

     Computer * c3 = new Computer(new InterCPU,new InterVideoCard,new LenovoMemory);
     c3->work();
    delete c3;
	
    return 0;
}

