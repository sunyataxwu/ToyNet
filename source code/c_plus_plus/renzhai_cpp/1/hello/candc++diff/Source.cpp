//#include "stdio.h"
//#include "stdlib.h"
#include <iostream> 
//#include "stdbool.h"//c������Ҫ��������

using namespace std;

struct FHello
{
	int a;
	int b;
	long int c;

};

void Fun(FHello &cc)//C++ ֧�ִ�����  c���Բ�֧�ִ�����
{
	cc.a = 0;
}

//4
void FunPtr(FHello* cc)//C++ ֧�ִ�����  
{
	cc->a = 0;
}

FHello* CreateObject()
{
	return NULL;
}

struct FFF
{
	int q;
	int w;
};

struct FTest :public FFF
{
	void Hello(int a,int b){}



};

int main()
{
	FTest Test;

	//1.��ӡ��ʽ��ͬ
	//printf("Hello World \n");//C��
	cout << "Hello World" << "www" << endl;//C++�Ĵ�ӡ

	//2.bool������ͬ
	bool bOk = false;

	//3.c �β� ����
	//���õ�����
	//���ñ����ʼ��
	//Ψһ��

	//
	//�ײ�ʵ�ֵķ�ʽ��һ�� ָ�뷽ʽʵ��

	FHello o;
	FHello o333;
	FHello& o1 = o;
	FHello& o2 = o;//����
//	sizeof(o1)
	//o2 = o333;

	FHello *optr = &o;
	optr = &o333;

	char** y = new char*[100];

	//
	if (CreateObject())
	{

	}
	Fun(o);
	system("pause");
	return 0;
}