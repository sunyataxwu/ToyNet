

#ifndef __GZ_PERSON_INFO_H__
#define __GZ_PERSON_INFO_H__

#include <string>

#define MAX_NUM 1000    //�������

/* ��ϵ�˽ṹ�� */
struct Person
{
    std::string name;   //����
    int         sex;    //�Ա�1�� 2Ů
    int         age;    //����
    std::string phone;  //�绰
    std::string addr;   //סַ
};

//ͨѶ¼�ṹ��
struct AddressBooks
{
    struct Person   person_array[MAX_NUM];      // ͨѶ¼�б������ϵ������
    int             size;                       // ͨѶ¼����Ա����
};

#endif // __GZ_PERSON_INFO_H__
