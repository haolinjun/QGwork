#include"Link.hpp"
#include<iostream>
#include<string.h>
#include<typeinfo>

using namespace std;

int main()
{
    LinkList<int> List1(10, 1);
    List1.Displasy();

    LinkList<string> List2;
    List2.Insert(0, "a");
    List2.Insert(1, "b");
    List2.Insert(2, "c");
    List2.Insert(2, "c");
    List2.Insert(5, "e"); //超出范围的插入
    List2.Displasy();
    List2.Delete(1);        //删除指定位置的节点
    List2.Displasy();
    List2.Remove("c");    //删除所有拥有该数据的节点
    List2.Displasy();


    system("pause");
    return 0;
}