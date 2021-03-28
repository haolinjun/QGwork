#include<iostream>
#include"Link.hpp"
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    DLinkList<string> DLink(10, "wozhenshuai");

    DLink.Insert(1, "zjy");
    DLink.Delete(2);
    DLink.Displasy();
    DLink.Remove("wozhenshuai");
    DLink.Displasy();

    system("pause");
    return 0;
}