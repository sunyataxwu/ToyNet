#include <iostream>
#include <algorithm>
#include <vector>
#include <string>//char
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <forward_list>
#include <array>
#include "Myiterator.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

//���������˫������
template<class T>
struct FNode
{
	FNode()
		:Nest(NULL)
		,Previous(NULL)
	{

	}
	FNode* Nest;
	FNode* Previous;
	T Data;
};

struct FHello
{
	FHello(int newprice)
		:price(newprice)
	{

	}
	string name;
	int price;

	friend bool operator< (const FHello& A, const FHello& B)
	{
		return A.price < B.price;
	}
};

//vector<string> cc; cc[1];

//stl��׼ģ���

//template<class T>
//class vector
//{
//	T* Data;
//};
//
//vector<int> a;
class FObject {};

int main()
{
	
	//ԭ��list
	FNode<string> Node;
	Node.Data = "Hello1";
	{
		Node.Nest = new FNode<string>();
		Node.Nest->Data = "Hello2";
		Node.Nest->Previous = &Node;

		Node.Nest->Nest = new FNode<string>();
		Node.Nest->Nest->Data = "Hello3";
		Node.Nest->Nest->Previous = Node.Nest;

		Node.Nest->Nest->Nest = new FNode<string>();
		Node.Nest->Nest->Nest->Data = "Hello4";
		Node.Nest->Nest->Nest->Previous = Node.Nest->Nest;
	}

	auto PrintfNode = [&]()
	{
		FNode<string>* NodePtr = &Node;
		while (NodePtr)
		{
			cout << NodePtr->Data << endl;
			NodePtr = NodePtr->Nest;
		}
	};

	auto RemoveNode = [&](const string &RemoveString)
	{
		FNode<string>* NodePtr = &Node;
		while (NodePtr)
		{
			if (NodePtr->Data == RemoveString)
			{
				NodePtr->Previous->Nest = NodePtr->Nest;
				NodePtr->Nest->Previous = NodePtr->Previous;
				delete NodePtr;

				NodePtr = NULL;
			}

			if (NodePtr)
			{
				NodePtr = NodePtr->Nest;
			}
		}
	};

	RemoveNode("Hello3");
	PrintfNode();

	//std list
	//��ʼ����ʽ
	list<string> NodeList;
	list<string> NodeList1({"asdasd","weqwe","cvsv","qweqwegyjh"});
	list<string> NodeList2 = { "asdasd","weqwe","cvsv","qweqwegyjh" };
	list<string> NodeList3 = NodeList1;//���
	list<string> NodeList6(NodeList1);//���
	string a11[] = { "asdasd","weqwe","cvsv","qweqwegyjh" };
	list<string> NodeList4(a11, a11 + 2);

	//List���
	NodeList4.push_back("xxxxxx");
	NodeList4.push_back("xxxxxx1");
	NodeList4.push_front("TTTTTTT");
	NodeList4.push_front("TTTTTTT");

	NodeList4.pop_back();
	NodeList4.pop_front();

	NodeList4.emplace_back("RRRRR");//��push_back ��ִ��һ�ο�������
	NodeList4.emplace_front("FFFFF");

	//��ֵ
	NodeList4.assign({ "adasd","asdas","adawqesd","sdf" });
	NodeList4.assign({});
	NodeList4.assign(NodeList1.begin(), NodeList1.end());
	//NodeList4.assign(100, "OOOOO");
	NodeList4.emplace_front("FFFFF1111");

	NodeList4.size();
	NodeList4.clear();
	NodeList4.swap(NodeList3);

	//����
	NodeList4.insert(NodeList4.begin(),"WQQQQQQ");
	NodeList4.insert(NodeList4.begin(), { "WQQQQQQ" ,"WSD" ,"WQQasdQQQQ" ,"WQQwqweQQQQ" });
	NodeList4.insert(NodeList4.end(), NodeList1.begin(), NodeList1.end());

	NodeList4.sort();

	list<int> ddd = { 3,4,6,7,83,0,34,1,1,5,57,8 };
	ddd.sort();//����
	ddd.sort(greater<int>());//����

	//�Ƴ�
	ddd.remove(7);
	ddd.remove_if([](int v) {return v > 50; });//��Χ�Ե��Ƴ�

	ddd.unique();
	struct FHJellp
	{
		FHJellp()
		{
			a = 0;
		}
		FHJellp(int newa)
			:a(newa)
		{

		}

		int a;

		bool operator==(const FHJellp &v)
		{
			return a == v.a;
		}
	};

	list<FHJellp> llp;
	llp.push_front(FHJellp(1));
	llp.push_front(FHJellp(2));
	llp.push_front(FHJellp(2));
	llp.push_front(FHJellp(2));
	llp.push_front(FHJellp(6));
	llp.push_front(FHJellp(8));
	llp.unique();

	//list����
	for (/*list<string> ::iterator*/auto It = NodeList4.begin();It != NodeList4.end(); It++)
	{
		//NodeList4.erase(It);
		cout << *It << endl;
	}

	for (auto &Tmp : NodeList4)
	{
		cout << Tmp << endl;
	}

	for (auto It = NodeList4.cbegin(); It != NodeList4.cend(); It++)
	{
		cout << *It << endl;
	}
	auto It1 = NodeList4.rbegin();
	
	for (advance(It1, 2);It1 != NodeList4.rend(); It1++)
	{
		cout << *It1 << endl;
	}

	//����
	auto ListV = { 1,2,3,4,5,65,67 };
	for (auto It = rbegin(ListV);It != rend(ListV);++It)
	{
		cout << *It << endl;
	}

	//����
	for (auto It = begin(ListV); It != end(ListV); ++It)
	{
		cout << *It << endl;
	}

	////��̬����
	vector<int> array1;//����
	array1.push_back(1);//�㷨
	array1.push_back(44);//�㷨
	array1.push_back(441);//�㷨
	array1.push_back(424);//�㷨
	array1.push_back(1144);//�㷨
	array1.push_back(443);//�㷨
	cout << array1.size() * sizeof(int) << endl;

	//vector<int>::iterator v = array1.begin();//������
	//while (v != array1.end())
	//{
	//	cout << *v << endl;
	//	v++;
	//}
	//
	////
	////��ӡ
	//for (vector<int>::iterator It = array1.begin(); It != array1.end(); It++)
	//{
	//	cout << *v << endl;
	//}

	//1.vector ��ʼ����ʽ
	vector<int> v1(10);//Ԥ���� 10������

	vector<int> v2(10,2);//����10�� ÿ������ֵλ0

	vector<int> v3(v1);//�ö���������ʼ��

	vector<int> v4(v1.begin(), v1.end());
	vector<int> v5(v1.begin(), v1.begin() + 4);

	int hello[10] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> v6(hello, hello + 5);

	//2.vector�������ú���
	vector<int> v7,v8;
	v7.assign(v1.begin(), v1.begin() + 4);
	v8.assign(7, 4);
	//auto &Tmp = v8.front();
	int& Tmp1 = v8.front();	
	v8.push_back(11);
	int& Tmp2 = v8.back();
	int& Tmp4 = v8[3];
	v8.clear();
	if (v8.empty())
	{
		cout << "�յ�" << endl;
	}
	v8.assign(v1.begin(), v1.begin() + 6);
	v8.pop_back();
	v8.erase(v8.begin(), v8.begin() + 2);//ɾ��

	v8.push_back(1111);
	v8.insert(v8.begin()+1,999);
	v8.insert(v8.begin() + 1, 1999);

	int num = v8.size();//���� ��ʵռ�õĴ�С
	int n1 = v8.capacity();//Ԥ������ڴ�ռ� realloc

	v8.resize(100);//���100 �����ֵ���
	v8.resize(120,123); //���100 �����ֵ 123
	v8.resize(70, 123);
	v8.resize(50);//ԭ��  ������������ ֱ��ɾ��
	v8.reserve(60);
	v8.reserve(160);
	v8.swap(v5);

	if (v8 == v5)
	{

	}
	if (v8 != v5)
	{

	}

	//3.vector����
	int av[] = { 6,2,5,8,9,122,32,345,67,1 };
	vector<int> a1;
	for (int i =0;i < 10 ;i++)
	{
		a1.push_back(av[i]);
	}

	//���ʷ�ʽ1
	for (vector<int>::iterator It = a1.begin(); It != a1.end(); It++)
	{
		cout << *It << endl;
	}

	//���ʷ�ʽ2
	for (int i = 0; i< a1.size() ;i++)
	{
		cout << a1[i] << endl;
	}

	//���ʷ�ʽ3
	for (auto &Tmp : a1)
	{
		cout << Tmp << endl;
	}

	//���ʷ�ʽ4
	for (int i = 0; i < a1.size() - 1; ++i)
	{
		cout << a1[i] << endl;
	}

	int i = 0;
	int i1 = 0;
	int q1 = i++;//�ȼ���++Ȼ���ֵ����q1
	int q2 = ++i;//ֵ����q2Ȼ�����++
	int v = ++i + i++;//6 ���ǲ���8
//	a[i++] = b[i--]
	vector<int> b1;
	b1.resize(a1.size());
	//4.vector �㷨
	//1>sort ��С����
	sort(a1.begin(), a1.end());
	//2>reverse ���� ������
	reverse(a1.begin(), a1.end());
	//3>copy ����
	copy(a1.begin(), a1.end(), b1.begin());
	//Ѱ��
	auto pos = find(a1.begin(), a1.end(),122);

	//�ַ���
	char PP[] = "Hello World";//����
	string pps1 = "Hello World";;
	string pps2 = "Hello World";;
	string s = pps1 + pps2;

	//�ַ����ĺ���	
	for (string::iterator It = pps1.begin(); It != pps1.end(); It++)
	{
		cout << *It << endl;
	}
	 
	int ssize = pps1.size();//��ȡ�����ַ������� char
	int slength = pps1.length();//��ȡ��С

	int smaxsize = pps1.max_size();
	int scapacity = pps1.capacity();

	int bEmpty = pps1.empty();
	pps1.c_str();//�ǳ���Ҫconst char //FString
	pps1.data(); //�ڴ��ַ

	pps1.reserve(1024);//Ԥ������ٿռ�
	string hellos = "hello";
	pps1.swap(hellos);

	char newstring[] = "ooooo";
	pps1.insert(2, newstring);
	pps1.append(hellos);

	char cchar = 'p';
	pps1.push_back(cchar);

	pps1.erase(5);
	pps1.clear();

	pps1 = "NewString  sdsasd";
	pps1.assign("NewString  sdsasd2");

	char arraychar[] = "NewString";
	char arraychar2[] = "CCCCCC";
	string Hello = pps1.replace(0,strlen(arraychar), arraychar2);

	pps1.copy(arraychar, strlen(arraychar) - 3);
	
	char ppcc[] = "CC";
	int pos1 = pps1.find(ppcc);
	char pos1char = pps1[pos1];

	int pos2 = pps1.rfind(ppcc);
	char pos1char1= pps1[pos2];

	pos1 = pps1.find_first_of(ppcc);
	pos2 = pps1.find_last_of(ppcc);

	pos1 = pps1.find_first_not_of(ppcc);
	pos2 = pps1.find_last_not_of(ppcc);

	string cccc = pps1.substr(2,8);

	pps1.compare(ppcc);

	std::cout << cccc;

//	pps1 += hellos;
	//Map
	//����
	//����
	//ӳ��
	//��ֵΨһ
	//������ allocator
	map<int, string> MapHello1{ {1,"ddd"},{3,"asd"} };
	map<int, string> MapHello;
	string ccc = MapHello[3];//���ƽ�������
	MapHello[3] = "Hello";
	MapHello.insert(make_pair(1, "CCCCC"));
	MapHello.insert(pair<int,string>(2,"CCCCC"));
	MapHello.insert(map<int, string>::value_type(34, "CCCCC"));
	MapHello.insert({ {8,"ddd"},{9,"asd"} });
	//for (const pair<int, string> &Tmp : MapHello)
	string cccc1 = MapHello.at(8);
	auto c1 = MapHello.equal_range(8);
	MapHello.size();
	//MapHello.erase(8);
	auto iterator111 = MapHello.find(8);

	//�Ƿ�������Ԫ��
	if (!MapHello.count(7))
	{
		MapHello.insert(make_pair(7, "IIII"));
	}

	//����
	for (auto& Tmp : MapHello)
	{
		//Tmp.Key
		//	Tmp.Value
		if (Tmp.first == 3)
		{
			cout << Tmp.second << endl;
			break;
		}
	}
	//����
	for (map<int, string>::iterator It = MapHello.begin(); It != MapHello.end();It++)
	{
		if (It->first == 3)
		{
			cout << It->second << endl;
			break;
		}
	}

	cout << endl;
	cout << MapHello[3] << endl;
	cout << MapHello[1] << endl;

	//����
	//1.�Ƚ��ȳ�
	//2.��ͷ ��β
	//3.ɾ����β�Ǻ��鷳�� pop
	//4.���ԵĴ洢��
	//��ʼ��
	queue<int> q3;
	queue<int> q4({ 3,4,6,8,9,0 });
	queue<int> q5(q4);

	//���
	q3.push(1);
	q3.push(34);
	q3.push(15);
	q3.push(17);
	q3.push(18);
	q3.push(91);
	q3.push(10);

	//
	int v100 = q3.front(); //��ɾ��
	int v101 = q3.back();//��ɾ��

	//���еķ�ʽ���
	while (!q3.empty())
	{
		int tempa = q3.front();
		cout << tempa << endl;
		q3.pop();//����ͷ��
	}

	q3.emplace(100);
	q3.size();

	queue<int> q100;
	q3.swap(q100);

	/*std::*/swap(q100, q3);
	//��Ϣ����

	//ջ
	//ջ�ĳ�ʼ��
	stack<int> stacktemp({1,2,3,4,5,6});
	stack<int> stacktemp1(stacktemp);
	stack<int> stacktemp2 = stacktemp;
	vector<int> hello111({ 1,2,3,4,5,6 });
	stack<int,vector<int>> stacktemp3(hello111);

	//���
	stacktemp2.push(333);
	stacktemp2.push(3323);
	stacktemp2.push(3333);
	stacktemp2.push(333);
	stacktemp2.push(33453);
	stacktemp2.push(3733);
	stacktemp2.push(3633);

	stacktemp2.emplace(3123633);
	stacktemp2.emplace(36433);
	stacktemp2.emplace(36433);
	stacktemp2.emplace(36133);
	stacktemp2.emplace(362333);

	int len111 = stacktemp2.size();
	stacktemp2.swap(stacktemp);//����
	swap(stacktemp2, stacktemp);

	//����
	while (!stacktemp2.empty())
	{
		int topstack = stacktemp2.top();
		cout << topstack << endl;
		stacktemp2.pop();
	}

	//void func(int float)
	//{

	//}

	//Set
	//��ʼ��
	set<int> a100({ 100,1,2,3,4,5,6 });
	set<int> a1001(a100);
	set<int> a1002(a100.begin(), a100.end());
	int arrraint[] = { 100,1,2,3,4,5,6 };
	set<int> a1003(arrraint, arrraint + 3);

	//set 
	//1.����ʽ������
	//2.�ڲ�Ԫ���ǻ��Զ�����
	//3.������Ψһ��


	a100.insert(100);
	a100.swap(a1002);

	//������
	auto cc11 = a100.begin();
	auto cc22 = a100.end();
	auto cc33 = a100.cbegin();
	auto cc44 = a100.cend();
	auto cc55 = a100.rbegin();
	auto cc66 = a100.rend();
	auto cc88  =a100.crbegin();
	auto cc00  =a100.crend();
	//��ȡԪ��
	for (auto &Tmp : a100)
	{
		cout << Tmp << endl;
	}

	//������ʽ������
	for (set<int>::const_iterator It = a100.cbegin(); It != a100.cend(); It++)
	{
		cout << *It << endl;
	}

	a100.emplace(102);
	a100.emplace_hint(a100.cend(), 10);
	bool bEmpty1 = a100.empty();
	int len10000 = a100.size();
	if (!a100.count(1077))
	{
		a100.emplace(1077);
	}
	a100.erase(102);
//	a100.clear();
	a100.erase(a100.find(1077));
	int maxsize = a100.max_size();
	auto pair111 = a100.equal_range(100);

	auto www = a100.lower_bound(10);
	auto www1 = a100.upper_bound(6);
	
	//��������
	forward_list<int> aaa;
//	list<int> aaa1

	aaa.assign(100,10);

	for (auto &Tmp : aaa)
	{
		cout << Tmp << endl;
	}

	aaa.remove(10);
	aaa.remove_if([](int a) {return a == 10; });

	aaa.push_front(100);
	aaa.push_front(1001);
	aaa.push_front(1002);
	aaa.push_front(1003);

	aaa.emplace_after(aaa.begin(),10000);
	aaa.emplace_front(20000);

	for (forward_list<int>::const_iterator It = aaa.cbegin(); It != aaa.cend(); It++)
	{
		cout << *It << endl;
	}

	//while (!aaa.empty())
	//{
	//	int valueccc = aaa.front();
	//	cout << valueccc << endl;
	//	aaa.pop_front();
	//}

//	aaa.erase_after(aaa.begin());
	forward_list<int> dddd({3,4,6,7,9,8,9,1,2,3});
	aaa.splice_after(aaa.before_begin(), dddd);
	
	priority_queue<int> ccccc1;

	ccccc1.emplace(222222);
	ccccc1.push(312312);
	ccccc1.push(3123);
	ccccc1.push(323);
	ccccc1.push(23);
	ccccc1.push(3);

	ccccc1.empty();

	ccccc1.size();
	//ccccc1.swap();
	int newtop = ccccc1.top();
	ccccc1.pop();
	while (!ccccc1.empty())
	{
		cout << ccccc1.top();
		ccccc1.pop();
	}

	priority_queue<FHello> ccccc12;
	ccccc12.emplace(FHello(100));
	ccccc12.emplace(FHello(13));
	ccccc12.emplace(FHello(10));
	ccccc12.emplace(FHello(1001));

	while (!ccccc12.empty())
	{
		cout << ccccc12.top().price << endl;;
		ccccc12.pop();
	}

	//int double char

	hash<int> HHHHHHHH;
	int ooo = 123123123;
	auto ooo1 = HHHHHHHH._Do_hash(ooo);

	auto ooo2 = HHHHHHHH(ooo);
	if (ooo1 == ooo2)
	{
	}

	//RSA AES
	//MD5
	//set

	multiset<int> mset;
	mset.insert(100);
	mset.insert(100);
	mset.insert(100);

	auto autoccc = mset.find(100);
	mset.erase(autoccc);
	set<int> testset;
	testset.insert(100);
	testset.insert(100);
	testset.insert(100);

	//testset.find()
	//map<>
	multimap<int, string> mMap;
	mMap.insert(make_pair(10, "Hello World"));
	mMap.insert(make_pair(10, "Hello"));
	mMap.insert(make_pair(10, "World"));

	auto value_c = mMap.find(10);

	//TArray<int>
	array<int, 4> farray({ 1,2,3,4 });//����
	//farray.fill(100);
	auto pppp = farray.data();
	auto value4 = farray[3];
	auto value5 = farray.at(3);

	auto back1 = farray.back();
	auto front2 = farray.front();

	for (auto &Tmp : farray)
	{
		cout << Tmp << endl;
	}

	for (array<int,4>::iterator It = farray.begin(); It != farray.end(); It++)
	{
		cout << *It << endl;
	}

	farray[2] = 0;
	int len = farray.size();
	
	//farray.assign();
	
	//ʵս������
	struct FTestA
	{
		FTestA(){}
		FTestA(int InA)
			:ID(InA)
		{

		}

		bool operator!=(const FTestA &A)
		{
			return A.ID != ID;
		}

		inline int GetID() { return ID; }
	protected:
		int ID;
	};

	TArray<FTestA> ArrayA;
	FTestA A1(1);
	ArrayA.Add(A1);
	ArrayA.Add(FTestA(100));
	ArrayA.Add(FTestA(1001));
	ArrayA.Add(FTestA(1002));
	ArrayA.Add(FTestA(1003));
	ArrayA.Add(FTestA(1004));
	ArrayA.Add(FTestA(1005));
	ArrayA.Add(FTestA(1006));
	ArrayA.Add(FTestA(1007));
	ArrayA.Add(FTestA(1008));
	ArrayA.Add(FTestA(1009));
	ArrayA.Add(FTestA(10010));
	ArrayA.Add(FTestA(10011));
	ArrayA.Add(FTestA(10012));
	ArrayA.Add(FTestA(10013));
	ArrayA.RemoveAt(1);
	for (int i =0;i < ArrayA.Num();i++)
	{
 		cout << ArrayA[i]->GetID() << endl;
	}

	for (TArray<FTestA>::TIterator It = ArrayA.Begin();It != ArrayA.End();It++)
	{
		cout << (*It).GetID() << endl;
	}

	
	//����
	map<int, int>aaa1;
	aaa1.insert(make_pair(1, 2));
	aaa1.insert(make_pair(10, 2));
	aaa1.insert(make_pair(3, 2));
	aaa1.insert(make_pair(2, 2));
	//�����
	//

	//����
	unordered_map<int, int>aaa2;
	aaa2.insert(make_pair(1, 2));
	aaa2.insert(make_pair(10, 2));
	aaa2.insert(make_pair(3, 2));
	aaa2.insert(make_pair(2, 2));
	//��ϣ
	//
	//for (auto &Tmp : aaa2)
	//{
	//	Tmp.first;
	//	Tmp.second;
	//}

	int elememnt = aaa2.at(10);
	elememnt = aaa2[10];

	int ccc123 = aaa2.count(10);
	auto HHHH11 = aaa2.hash_function();

	/*int ssss = 344556;
	HHHH11._Do_hash(ssss);*/

	auto ccc111 = aaa2.bucket(10);
	auto ooooo = aaa2.bucket_count();
	aaa2.rehash(ccc111);

	auto vvvv = aaa2.load_factor();
//	aaa2.key_eq();
	multimap<int, int>aaa4;
	unordered_multimap<int, int> aaa3;
//	aaa3[1];
	//aaa4[11];
	auto ppp = aaa3.key_eq();
	auto c1ccc1 = ppp(1, 1);
	if (aaa3.key_eq()(1, 1))
	{

	}

	set<int> nset;//�������ƽ�������
	nset.insert(12312325);
	nset.insert(123);
	nset.insert(5676);
	nset.insert(13423);
	nset.insert(1123);
	nset.insert(12672323);

	//��ϣ
	unordered_set<int> uset;
	uset.insert(12312325);
	uset.insert(123);
	uset.insert(5676);
	uset.insert(13423);
	uset.insert(1123);
	uset.insert(12672323);

	for (auto &Tmp : uset)
	{

	}

	uset.erase(1123);

	auto ccc1234 = uset.find(123);
	if (ccc1234 == uset.end())
	{

	}

	unordered_multiset<int> umset = {10,20,30,30,30,100,100,20,30,40,50};
	for (auto &Tmp : umset)
	{
		cout << Tmp << endl;
	}

	for (auto It = umset.begin();It != umset.end();++It)
	{
		cout << *It << endl;
	}

	return 0;
}

//class string
//{
//
//};

