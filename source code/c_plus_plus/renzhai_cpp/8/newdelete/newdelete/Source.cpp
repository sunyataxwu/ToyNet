#include <iostream>

using namespace std;

struct FObject
{
public:
	FObject()
	{
		cout << "FObject" << endl;
	}

	virtual ~FObject()
	{
		cout << "~FObject" << endl;
	}
private:
	int a;
	int b;
};

struct FObjectss :public FObject
{
public:
	FObjectss()
	{
		cc = new char;
	}

	~FObjectss()
	{
		cout << "	~FObjectss()" << endl;
		delete cc;
	}
	char* cc;
};

template<class T>
class FPreDistribution
{
public:
	FPreDistribution(int InCount)
		:Numer(InCount)
	{
		Data = new T[InCount];
	}

	~FPreDistribution()
	{
		delete[] Data;
	}

	T* operator[](int Index)
	{
		return &Data[Index];
	}

	inline int Num() { return Numer; }
private:
	T* Data;
	int Numer;
};

int main()
{
	//int* p = new int; //�� �������Ҫ����Ա�ֶ��ͷţ�

	//int p_int = 10;//ջ

	//int* hello = &p_int;

	////*p = p_int;

	//p = hello;

	//cout << *p << endl;

	//delete p;//�ͷ���ջ���ڴ� ���Բ�������

	//int *p_m = (int*)malloc(sizeof(int));//����һƬ�ڴ�
	//int *p_n = new int;

	//delete p_m;
	//free(p_n);


//	FObject* p_m = (FObject*)malloc(sizeof(FObject));//����һƬ�ڴ�
////	p_m->FObject();//���ܵ���
//
//	FObject* p_n = new FObject();
//
//	delete p_m;
//
//	p_n->~FObject(); //����Ե���Ĭ�ϵ�����
//	free(p_n);

	//new delete Ĭ��ʵ�ֹ�������� ���߶���������������
	//malloc free �򵥴ֱ��ķ����ڴ�
	//FObject* p_n = new FObjectss();

//	//delete p_n;
////	char* pc = new char[1024];
//	FObject* p = new FObjectss[1024]; //һά����
//	delete[] p;
////	delete p;
//
//	//��ά����
//	int** Hello = new int* [1024];
//	for (int i = 0 ; i <1024;i++)
//	{
//		Hello[i] = new int[10];
//	}
//
//	for (int i = 0; i < 1024; i++)
//	{
//		delete[] Hello[i];
//	}
//	delete[] Hello;
//
//	//����Ķ�ά����
//	FObjectss** Hello1 = new FObjectss * [1024];
//	for (int i = 0; i < 1024; i++)
//	{
//		Hello1[i] = new FObjectss[10];
//	}
//
//	for (int i = 0; i < 1024; i++)
//	{
//		delete[] Hello1[i];
//	}
//	delete[] Hello1;
//	
//
//	//��ά����Ĵ������ͷ�
//	int*** SSS = new int** [1024];
//	for (int i = 0;i< 1024;i++)
//	{
//		SSS[i] = new int* [10];
//		for (int j = 0;j < 10;j++)
//		{
//			SSS[i][j] = new int[10];
//		}
//	}
//
//	for (int i = 0; i < 1024; i++)
//	{
//		SSS[i] = new int* [10];
//		for (int j = 0; j < 10; j++)
//		{
//			delete[] SSS[i][j];
//		}
//		delete[] SSS[i];
//	}
//	delete[] SSS;


	FObject *p_m = new FObject();
	//��̬�ڴ� ->�ڴ���Ƭ

	//Ԥ�����ڴ�
	FObject* p_mv = new FObject[1024];

	//iocp
	FPreDistribution<FObject> PreDistribution(1024);
	FObject *Hellop = PreDistribution[56];

	return 0;
}