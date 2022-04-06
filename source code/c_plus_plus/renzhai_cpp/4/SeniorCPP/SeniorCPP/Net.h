#pragma once
#include <iostream>
using namespace std;
typedef unsigned char uint8;

template<uint8 MessageType>
class NetControlMessage
{

};

class FNetControlMessageInfo
{
public:
	template<typename ... ParamTypes>
	static void ReceiveParams(ParamTypes &... Params)
	{
		
	}

	template<typename ... ParamTypes>
	static void SendParams(ParamTypes &... Params)
	{

	}
};

#define DEFINE_CONTROL_CHANNEL_MESSAGE(Name,Index,...) \
enum {NMT_##Name = Index}; \
template<> class NetControlMessage<Index>/*�ػ�*/ \
{ \
public: \
	template<typename ... ParamTypes> \
	static void Send(ParamTypes &...Param) \
	{ \
		FNetControlMessageInfo::SendParams(Param...);\
	}\
	template<typename ... ParamTypes> \
	static void Receive(ParamTypes &...Param) \
	{ \
		FNetControlMessageInfo::ReceiveParams(Param...); \
	} \
};

//����Э����Ϊ
DEFINE_CONTROL_CHANNEL_MESSAGE(Hello, 0, int, float, char);
DEFINE_CONTROL_CHANNEL_MESSAGE(Welcome, 1, int, char);
DEFINE_CONTROL_CHANNEL_MESSAGE(Login, 2, int, char,char);

//1չ����������
template<typename T>
char PrintArg(T& arg)
{
	cout << arg << endl;

	return 0;
}

template<typename ... ParamTypes>
void Func1(ParamTypes &...Param)
{
	//std::forward()
	//char arr[] = { PrintArg(Param)... };
	char arr[] = { PrintArg(Param)... };//����
}

//2��ȡ����
template<typename ... ParamTypes>
void FuncLen(ParamTypes &...Param)
{
	cout << sizeof...(Param)<<endl;
}

void FuncFindParam()
{
	cout << "û������" << endl;
}

//3ͨ���ݹ�����������
template<class T, typename ... ParamTypes>
void FuncFindParam(T &Head,ParamTypes &...Param)
{
	cout << "Heard = " << Head << endl;
	FuncFindParam(Param...);
}

//4��Ͱ���
template<typename ParamTypes>
ParamTypes &FunValue(ParamTypes &Param)
{
	return Param;
}

template<class T, typename ... ParamTypes>
T FunValue(T& Head, ParamTypes &...Param)
{
	return Head + FunValue<T>(Param...);
}

//����:
template<class T,class T2>
class FHello_Class
{
private:
	T a;
};

//ȫ�ػ�
template<>
class FHello_Class<int,char> //����һ�����������
{

};
//����ȫ�ػ�:
template<class T,class T2>
void FunTest()
{
};

template<>
void FunTest<int,char>()
{

}

//ƫ�ػ�
template<class T>
class FHello_Class<int,T> //����һ�����������
{
private:
	T a;
};

//����û��ƫ�ػ�
//template<class T>
//void FunTest<int,T>()
//{
//
//}

template<typename T,class ...ParamTypes>
class FLen
{
public:
	enum
	{
		Number = FLen<T>::Number + FLen<ParamTypes...>::Number
	};
};

template<typename Last>
class FLen<Last>
{
public:
	enum
	{
		Number = sizeof(Last)
	};
};

#define ddddd(Name, ...) FLen<__VA_ARGS__> Name


template<int...>
struct HelloIndex
{

};

//ͨ���̳�չ��
template<int N,int...ParamTypes>
struct SpawnIndex :SpawnIndex<N - 1, N - 1, ParamTypes...>
{

};

template<int...ParamTypes>
struct SpawnIndex<0, ParamTypes...>
{
	typedef HelloIndex<ParamTypes...> Type;
};

//ͨ��using
template<int N, int...ParamTypes>
struct SpawnIndex1
{
	using Type = typename SpawnIndex1<N - 1, N - 1, ParamTypes...>::Type;
};

//ѭ����ֹ
template<int...ParamTypes>
struct SpawnIndex1<0, ParamTypes...>
{
	typedef HelloIndex<ParamTypes...> Type;
};

//template<class T>
//T* CreateObject()
//{
//	return new T();
//}
//
//template<class T,typename Arg0>
//T* CreateObject()
//{
//	return new T(Arg0);
//}
//
//template<class T, typename Arg0, typename Arg1>
//T* CreateObject()
//{
//	return new T(Arg0, Arg1);
//}
//std::move()
//vector<>

template<class T,class ...ParamTyps>
T* CreateObject(ParamTyps &&...Param)//&&
{
	return new T(std::forward<ParamTyps>(Param)...);
}

//void (*Funcation)(int a, int b, int c);

//��򵥵� ֧�ֶ��������
template<class TObjectType, class TReturn,typename ...ParamTypes>
class FDelegate
{
public:
	FDelegate(TObjectType* InObject, TReturn(TObjectType::* InFuncation)(ParamTypes ...))
		:Object(InObject)
		,Funcation(InFuncation)
	{}

	TReturn operator()(ParamTypes &&...Params)
	{
		return (Object->*Funcation)(std::forward<ParamTypes>(Params)...);
	}

private:
	TObjectType *Object;
	TReturn (TObjectType::* Funcation)(ParamTypes ...);
};

template<class TObjectType, class TReturn, typename ...ParamTypes>
FDelegate<TObjectType, TReturn, ParamTypes...> CreateDelegate(TObjectType* InObject, TReturn(TObjectType::* InFuncation)(ParamTypes ...))
{
	return FDelegate<TObjectType, TReturn, ParamTypes...>(InObject, InFuncation);
}
//FDelegate ddd;
//
////....
//
//
//ddd(1, 3, 4, 5, 1);
