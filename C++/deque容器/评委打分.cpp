#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<ctime>
#include<algorithm>

class Person{
public:
	string m_Name;
	int m_Score;

	Person(string name,int score){
		this->m_Name = name;
		this->m_Score = score;
	}
};


//创建perosn放入vector中
void createPerson(vector<Person> & v){

	string nameSeed = "ABCDE";
	for(int i= 0;i<5;i++){
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		//创建选手
		Person p(name,score);

		//添加到容器中
		v.push_back(p);
	}

}

//设置分数
void setScore(vector<Person> & v){

	for(vector<Person>::iterator it=v.begin();it!=v.end();it++){

		//10名裁判大的分数放入到deque容器中
		deque<int> d;
		for(int i = 0;i<10;i++){
			//随机数    60~100
			int score = rand()%41 + 60;// 0~40  + 60   ==>60~100
			d.push_back(score);
		}
		// cout<<"选手："<<it->m_Name<<",分数："<<endl;
		// for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
		// 	cout<<(*dit)<<" ";
		// }
		// cout<<endl;

		//成绩排序
		sort(d.begin(),d.end());

		//去除最高分和最低分
		d.pop_back();
		d.pop_front();

		//平均值
		int sum = 0;
		for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
			sum += *dit;
		}

		int avg = sum/d.size();


		//平均成绩放入到选手对象中
		it->m_Score = avg;

	}
}
//显示成绩
void showScore(vector<Person> & v){
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++){

		cout<<"姓名："<<it->m_Name<<"，成绩"<<it->m_Score<<endl;
	}
}



int main() {

	//时间种子
	srand(time(NULL));

	//1、创建5名选手
	vector<Person> v;
	//将5个选手放入容器中
	createPerson(v);

	// for(vector<Person>::iterator it= v.begin();it!=v.end();it++){
	// 	cout<<"姓名:"<<(*it).m_Name<<",分数："<<(*it).m_Score<<endl;
	// }


	//2、评委打分
	setScore(v);

	//3、显示分数
	showScore(v);


	return 0;
}