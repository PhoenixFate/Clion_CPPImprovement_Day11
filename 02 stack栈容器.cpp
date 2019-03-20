//
// Created by phoenix on 3/20/2019.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <stack>

using namespace std;

/*
stack构造函数
stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式：
stack(const stack &stk);//拷贝构造函数
3.4.3.2 stack赋值操作
stack& operator=(const stack &stk);//重载等号操作符
3.4.3.3 stack数据存取操作
push(elem);//向栈顶添加元素
pop();//从栈顶移除第一个元素
top();//返回栈顶元素
3.4.3.4 stack大小操作
empty();//判断堆栈是否为空
size();//返回堆栈的大小
*/

void test201()
{
    stack<int> s;
    //放入数据
    s.push(1);
    s.push(5);
    s.push(9);
    s.push(23);
    s.push(2);
    while(s.size()!=0)
    {
        cout<<" \b栈顶的数据为："<<s.top()<<endl;
        s.pop();
    }
    cout<<s.size()<<endl;
}

int main2()
{
    test201();
    return 0;
}