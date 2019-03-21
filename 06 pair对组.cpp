//
// Created by phoenix on 3/21/2019.
//
#include <iostream>
#include <string>

using namespace std;

//创建对组
void test601()
{
    //第一种创建方式
    pair<string,int> p("name",100);

    //取值
    cout<<"first: "<<p.first<<endl;
    cout<<"second: "<<p.second<<endl;

    //第二种创建方式
    pair<string,int> p2=std::make_pair("jerry",20);
    cout<<"first: "<<p2.first<<endl;
    cout<<"second: "<<p2.second<<endl;
}

int main6()
{
    test601();
    return 0;
}
