#include<iostream>
using namespace std;
#include<vector>
#include <map>
#include<ctime>

//部门常量
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
//定义员工类
class Worker{
public:
    string m_name;
    int m_Salary;
};

//容器中添加员工
void createWorker(vector<Worker> & v){
    string nameSeed = "ABCDEFGHIJ";
    for(int i= 0;i<10;i++){
        //创建一个临时员工
        Worker worker;
        //员工姓名赋值
        worker.m_name = "员工";
        worker.m_name += nameSeed[i];
        //员工薪资赋值
        worker.m_Salary = rand()%10001 + 10000;

        //入职
        v.push_back(worker);
    }
}

//分组
void setGroup(vector<Worker> & v,multimap<int,Worker> & m){
    //每个员工进行分部门，循环的是员工
    for(vector<Worker>::iterator it = v.begin();it!=v.end();it++){
        //规定：部门编号  0:策划部  1:美术部  2:研发部
        //随机产生部门编号
        int deptId = rand()%3;
        //将员工插入到  分组中
        //key:部门编号   value：员工
        m.insert(make_pair(deptId,*it));
    }
}

//展示分组信息
void showWorkerByGroup( multimap<int,Worker> & m){

    cout<<"策划部："<<endl;
    //查找  find
   multimap<int,Worker>:: iterator pos =  m.find(CEHUA);//第一个策划部的位置
   // 统计人数
   int count = m.count(CEHUA);
   int index = 0;//计数 ，从0开始，一直到最大人数count
   for(;pos !=m.end()&& pos->first==CEHUA;pos++){
    cout<<"姓名："<<pos->second.m_name<<",薪资："<<pos->second.m_Salary<<endl;
   }

   cout<<"美术部："<<endl;
    //查找  find
    pos =  m.find(MEISHU);
     count = m.count(MEISHU);
    index = 0;//计数 ，从0开始，一直到最大人数count
   for(;pos !=m.end()&& index <count;pos++,index++){
    cout<<"姓名："<<pos->second.m_name<<",薪资："<<pos->second.m_Salary<<endl;
   }

    cout<<"研发部："<<endl;
    //查找  find
    pos =  m.find(YANFA);

    count = m.count(YANFA);
    index = 0;//计数 ，从0开始，一直到最大人数count
   for(;pos !=m.end()&& index <count;pos++,index++){
    cout<<"姓名："<<pos->second.m_name<<",薪资："<<pos->second.m_Salary<<endl;
   }

}


int main(){

    srand(time(NULL));

    //1、创建员工，存放到容器中 vector
    vector<Worker> vWorker;
    createWorker(vWorker);

    //测试
    // for(vector<Worker>::iterator it = vWorker.begin();it!=vWorker.end();it++){
    //     cout<<"姓名："<<it->m_name<<"，薪资："<<it->m_Salary<<endl;
    // }


    //2、每个员工都随机分配到对应的部门  key:部门   value:员工
    multimap<int,Worker> mWorker;
    setGroup(vWorker,mWorker);


    //3、展示信息
    showWorkerByGroup(mWorker);

    
    return 0;
}