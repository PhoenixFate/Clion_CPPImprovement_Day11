//
// Created by phoenix on 3/21/2019.
//
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void printSet(set<int> &s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();++it)
    {
        cout<<(*it)<<endl;
    }
}

/*
set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数
3.7.2.2 set赋值操作
set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器
3.7.2.3 set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.7.2.4 set插入和删除操作
insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。

*/
void test501()
{
    set<int> s;
    //关联式容器  根据key值进行排序
    s.insert(5);
    s.insert(10);
    s.insert(12);
    s.insert(8);
    s.insert(20);
    printSet(s);
    cout<<"size: "<<s.size()<<endl;
    cout<<"empty: "<<s.empty()<<endl;
    s.erase(10);
    printSet(s);
}

/*
set查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/
void test502()
{
    set<int> s;
    //关联式容器  根据key值进行排序
    s.insert(5);
    s.insert(10);
    s.insert(12);
    s.insert(8);
    s.insert(20);
    //对于set而言 没有value key就是value

    //find 找到返回元素所在位置的迭代器，未找到则返回end（）
    set<int>::iterator pos=s.find(2);
    if(pos!=s.end())
    {
        cout<<(*pos)<<endl;
    }
    else
    {
        cout<<" \b未找到"<<endl;
    }

    //count 对于set而言 ，结果为0或1
    int num=s.count(5);
    cout<<" \b5的个数为: "<<num<<endl;


    //lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    set<int>::iterator lowerBound=s.lower_bound(5);
    if(lowerBound!=s.end())
    {
        cout<<"lower_bound: "<<(*lowerBound)<<endl;
    }
    else {
        cout<<" \b为找到lower_bound"<<endl;
    }

    //upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器
    set<int>::iterator upperBound=s.upper_bound(5);
    if(upperBound!=s.end())
    {
        cout<<"upper_bound: "<<(*upperBound)<<endl;
    }
    else {
        cout<<" \b为找到upper_bound"<<endl;
    }

    //equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    //第一个为：lower_bound
    //第二个为：upper_bound
    std::pair<set<int>::iterator, set<int>::iterator> myPair=s.equal_range(20);
    if(myPair.first!=s.end())
    {
        cout<<"equal_range first: "<<*(myPair.first)<<endl;
    } else{
        cout<<" \b未找到equal_range first"<<endl;
    }

    if(myPair.second!=s.end())
    {
        cout<<"equal_range second: "<<*(myPair.second)<<endl;
    }else {
        cout<<" \b未找到equal_range second"<<endl;
    }
}


//set容器 不允许插入重复的键值
void test503()
{
    cout<<"------------------------03-----------------"<<endl;
    set<int> s;
    s.insert(10);
    pair<set<int>::iterator,bool> pair1=s.insert(10);
    cout<<pair1.second<<endl;
    printSet(s);
}


//指定set排序规则
//利用仿函数
class MySetCompare
{
public:
    //重载（）
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }
};

//set容器的排序
//自定义排序
void test504()
{
    cout<<"--------------------04-------------------"<<endl;
    set<int,MySetCompare> s;
    //关联式容器  根据key值进行排序
    s.insert(5);
    s.insert(10);
    s.insert(12);
    s.insert(8);
    s.insert(20);
    //printSet(s);

    //从大到小排序
    //如果想要指定排序规则，需要在插入之前就指定排序规则

    for(set<int,MySetCompare> ::iterator it=s.begin();it!=s.end();++it)
    {
        cout<<*it<<endl;
    }
}

class Person5
{
public:
    Person5(string name,int age):name(name),age(age)
    {

    }
    bool operator==(const Person5 &p) const
    {
        if(this->name==p.name && this->age==p.age)
        {
            return true;
        }
        return false;
    }
    string name;
    int age;
};

//指定set排序规则
//利用仿函数
class MyPersonCompare
{
public:
    //重载（）
    bool operator()(const Person5 &p1,const Person5& p2)
    {
        if(p1.age>p2.age)
        {
            return true;
        }
        return false;
    }

};

void test505()
{
    cout<<"-------------------------05------------------------"<<endl;
    //插入自定义数据，需要开始时指定排序规则
    set<Person5,MyPersonCompare> s;
    Person5 p1("tom",11);
    Person5 p2(" \b大娃",20);
    Person5 p3(" \b二娃",21);
    Person5 p4(" \b三娃",22);
    Person5 p5(" \b四娃",20);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);
    for(set<Person5,MySetCompare>::iterator it=s.begin();it!=s.end();++it)
    {
        cout<<"name: "<<(*it).name<<"  age: "<< (*it).age<<endl;
    }
}


int main5()
{
    test501();
    test502();
    test503();
    test504();
    test505();
    return 0;
}
