//
// Created by phoenix on 3/20/2019.
//
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void test401()
{
//    list<int> myList;
//	for (int i = 0; i < 10; i++){
//		myList.push_back(i);
//	}
//	list<int>::_Nodeptr node = myList._Myhead->_Next;
//	for ( int i = 0; i < myList._Mysize * 2; i++){
//		cout << "Node:" << node->_Myval << endl;
//		node = node->_Next;
//		if (node == myList._Myhead){
//			node = node->_Next;
//		}
//	}
}

//list常用API
/*
list构造函数
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。
3.6.4.2 list数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
*/

void printList(list<int>&myList)
{
    cout<<"---------------------printList-----------------"<<endl;
    for(list<int>::iterator it=myList.begin();it!=myList.end();++it)
    {
        cout<<*it<<endl;
    }
    cout<<"---------------------end print------------------"<<endl;
}

void test402()
{
    list<int> myList(10,10);//10个10
    list<int> myList2(myList.begin(),myList.end());
    printList(myList);
    printList(myList2);
    //逆向打印
    myList2.push_back(100);
    for(list<int>::reverse_iterator rIt=myList2.rbegin();rIt!=myList2.rend();++rIt)
    {
        cout<<*rIt<<endl;
    }
    //不支持随机访问
    list<int>::iterator itBegin=myList.begin();
//    itBegin+=1;
    //插入数据
    list<int> myList3;
    myList3.push_back(4);
    myList3.push_back(6);
    myList3.push_back(9);
    myList3.push_back(18);
    myList3.push_front(100);
    myList3.push_front(120);
    myList3.push_front(150);
    printList(myList3);
    //删除两端数据
    myList3.pop_front();
    myList3.pop_back();
    printList(myList3);
    //insert
    myList3.insert(myList3.begin(),1000);
    printList(myList3);
    //remove
    myList3.remove(100);//参数为值，相等时删除（所有相等的值）
    printList(myList3);
}

/*
list大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

3.6.4.4 list赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。
3.6.4.5 list数据的存取
front();//返回第一个元素。
back();//返回最后一个元素。
*/
void test403()
{
    cout<<"-------------------------03------------------------"<<endl;
    list<int> myList;
    myList.push_back(10);
    myList.push_back(15);
    myList.push_back(18);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(50);
    cout<<"list.size():"<<myList.size()<<endl;
    cout<<"list.empty():"<<myList.empty()<<endl;
    myList.resize(10);
    printList(myList);
    list<int> myList2;
    myList2.assign(myList.begin(),myList.end());
    printList(myList2);
    cout<<"list.front(): "<<myList.front()<<endl;
    cout<<"list.back(): "<<myList.back()<<endl;
}

bool myCompare(int v1,int v2)
{
    return v1>v2;
}


/*
list反转排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/
void test404()
{
    list<int> myList;
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(10);
    myList.push_back(9);
    myList.push_back(80);
    myList.reverse();
    printList(myList);
    //sort(myList.begin(),myList.end());//所有不支持随机访问的迭代器不可以用系统提供的sort排序算法。
    //如果不支持系统提供的算法，那么类内部会提供
    myList.sort();//从小到大排序
    printList(myList);
    //从大到小排序
    myList.sort(myCompare);
    printList(myList);
}

//自定义数据
class Person4
{
public:
    Person4(string name,int age,int height):name(name),age(age),height(height)
    {

    }
    //重载==操作符，可以删除自定义数据类型
    bool operator==(const Person4& p) const
    {
        if(this->name==p.name && this->age==p.age)
        {
            return true;
        }
        return false;
    }

    string name;
    int age;
    int height;
};

//Person排序规则
bool comparePerson(Person4 &p1,Person4 &p2)
{
    if(p1.age==p2.age)
    {
        return p1.height<p2.height;
    }
    return p1.age>p2.age;
}

void printList(list<Person4> &myList)
{
    for(list<Person4>::iterator it=myList.begin();it!=myList.end();++it)
    {
        cout<<"name: "<<(*it).name<<"  age: "<<(*it).age<<"  height: "<<(*it).height<<endl;
    }
    cout<<"----------------------------end of print Person--------------------"<<endl;
}

void test405()
{
    list<Person4> myList;
    Person4 p1(" \b亚瑟王",10,166);
    Person4 p2(" \bsaber",29,170);
    Person4 p3(" \b狮子王",20,189);
    Person4 p4(" \b微软",20,176);
    myList.push_back(p1);
    myList.push_back(p2);
    myList.push_back(p3);
    myList.push_back(p4);
    //对于自定义类型，必须指定排序规则
    myList.sort(comparePerson);
    printList(myList);

    //删除某个元素，默认是通过==来删除(需要重写operator==)
    myList.remove(p4);
    printList(myList);
}

int main4()
{
    test401();
    test402();
    test403();
    test404();
    test405();
    return 0;
}
