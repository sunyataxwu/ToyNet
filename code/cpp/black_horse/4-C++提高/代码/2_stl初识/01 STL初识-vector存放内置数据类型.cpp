
/* vector������������������� */

#include<iostream>
#include <vector>
#include <algorithm> //��׼�㷨ͷ�ļ�

using namespace std;

void myPrint(int val)
{
    cout << val << ' ';
}

void test01()
{
    //������һ��vector����������
    vector<int> v;

    //�������в�������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //ͨ�����������������е�����
    vector<int>::iterator itBegin = v.begin(); //��ʼ������  ָ�������е�һ��Ԫ��
    vector<int>::iterator itEnd = v.end();  //���������� ָ�����������һ��Ԫ�ص���һ��λ��

    //��һ�ֱ�����ʽ
    while (itBegin != itEnd)
    {
        cout << *itBegin << ' ';
        itBegin++;
    }
    cout << endl;

    //�ڶ��ֱ�����ʽ
    for (vector<int>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    //�����ֱ�����ʽ  ����STL�ṩ�����㷨
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main() {

    test01();

    return 0;
}
