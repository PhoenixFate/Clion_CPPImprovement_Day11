#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/

class Person1
{
public:
    Person1(string name,int score):name(name),score(score)
    {

    }
    Person1(const Person1&p)
    {
        this->name=p.name;
        this->score=p.score;
        //cout<<"Person(const Prson1&p)"<<endl;
    }
    string name;
    int score;//平均分
};

void createPersonVector(vector<Person1> &v)
{
    string nameSeed="abcde";
    for(int i=0;i<5;++i)
    {
        //cout<<i<<endl;
        string name="name";
        name+=nameSeed[i];
        int score=0;
        Person1 p(name,score);
        v.push_back(p);
    }
    cout<<"-----------------"<<endl;
//    for(vector<Person1>::iterator it=v.begin();it!=v.end();++it)
//    {
//        cout<<&(*it)<<endl;
//    }
}

void setScore(vector<Person1>&v)
{
    for(vector<Person1>::iterator it=v.begin();it!=v.end();++it)
    {
        //对5个人分别进行打分
        deque<int> d;
        for(int i=0;i<10;++i)
        {
            int score=rand()%41+60;//0-39+60 //60-100
            d.push_back(score);
        }
        //先看一下打分
//        for(deque<int>::iterator dIt=d.begin();dIt!=d.end();++dIt)
//        {
//            cout<<*dIt<<"  ";
//        }
//        cout<<endl;
        //排序   从小到大
        sort(d.begin(),d.end());
        //去除最高最低
        d.pop_front();//最低
        d.pop_back();//最高

        //计算平均分
        int sum=0;
        for(deque<int>::iterator dIt=d.begin();dIt!=d.end();++dIt)
        {
            sum+=(*dIt);
        }
        int score=sum/d.size();
        (*it).score=score;
    }
}

void showScore(vector<Person1> &v)
{
    for(vector<Person1>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<(*it).name<<endl;
        cout<<(*it).score<<endl;
    }
}


void test101()
{
    //设置随机种子
    srand(time(NULL));
    //创建容器存选手
    vector<Person1> v;
    createPersonVector(v);
    setScore(v);
    showScore(v);
}

int main1() {
    test101();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}