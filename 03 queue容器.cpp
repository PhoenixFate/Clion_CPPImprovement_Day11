//
// Created by phoenix on 3/20/2019.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

/*
queue构造函数
queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
queue(const queue &que);//拷贝构造函数
3.5.3.2 queue存取、插入和删除操作
push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素

3.5.3.3 queue赋值操作
queue& operator=(const queue &que);//重载等号操作符
3.5.3.4 queue大小操作
empty();//判断队列是否为空
size();//返回队列的大小

*/

void test301()
{
    queue<int> q;
    q.push(10);//往队尾添加数据
    q.push(20);
    q.push(30);
    q.push(40);
    //while(!q.empty()){}
    while(q.size()!=0)
    {
        cout<<" \b队头："<<q.front()<<endl;
        cout<<" \b队尾："<<q.back()<<endl;
        //弹出队头数据
        q.pop();
    }

    cout<<"size: "<<q.size()<<endl;
}

int main3()
{
    test301();
    return 0;
}

