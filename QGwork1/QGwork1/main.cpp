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
    List2.Insert(5, "e"); //������Χ�Ĳ���
    List2.Displasy();
    List2.Delete(1);        //ɾ��ָ��λ�õĽڵ�
    List2.Displasy();
    List2.Remove("c");    //ɾ������ӵ�и����ݵĽڵ�
    List2.Displasy();


    system("pause");
    return 0;
}