
#include <iostream>
#include "gz_person.h"
#include "gz_operate.h"

using namespace std;

void ShowMenu();

int main()
{
    AddressBooks abs;
    abs.size = 0;

    int select = 0;

    while (true)
    {
        ShowMenu();

        cin >> select;
        switch (select)
        {
            case 1:  //�����ϵ��
                AddPerson(&abs);
                break;
            case 2:  //��ʾ��ϵ��
                ShowPerson(&abs);
                break;
            case 3:  //ɾ����ϵ��
                DeletePerson(&abs);
                break;
            case 4:  //������ϵ��
                FindPerson(&abs);
                break;
            case 5:  //�޸���ϵ��
                ModifyPerson(&abs);
                break;
            case 6:  //�����ϵ��
                break;
            case 0:  //�˳�ͨѶ¼
                cout << "��ӭ�´�ʹ��" << endl;
                return 0;
            default: break;
        }
    }

    return 0;
}

void ShowMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1�������ϵ��  *****" << endl;
    cout << "*****  2����ʾ��ϵ��  *****" << endl;
    cout << "*****  3��ɾ����ϵ��  *****" << endl;
    cout << "*****  4��������ϵ��  *****" << endl;
    cout << "*****  5���޸���ϵ��  *****" << endl;
    cout << "*****  6�������ϵ��  *****" << endl;
    cout << "*****  0���˳�ͨѶ¼  *****" << endl;
    cout << "***************************" << endl;
}
