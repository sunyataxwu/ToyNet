#include "dlllib/Interface.h"
#include "Clib/Header.h"
#include <iostream>

#pragma comment(lib,"FengzhuangCPP.lib")
#pragma comment(lib,"fenzhuangC.lib")
using namespace std;

//ģ��
int main()
{
	//����C++
	IInterface *IF = IInterface::CreateInterface();
	cout << IF->GetName() << endl;
	IF->Init();
	IF->Destroy();

	//����c��
	init_c(1, 2);
	get_c_name(2, 3);

	//Ĭ��
	//ȱʡֵ(Ĭ��)

	//DLL �� Lib exe pdb
	return 0;
}