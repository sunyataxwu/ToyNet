
#include "account.h"

/* ������ؼ�����֮�������������InitRate()*/
double Account::interest_rate_ = InitRate();
//������붨�徲̬����
double Account::InitRate()
{
    return 0.0;
}

/* static�ؼ�ֻ֮��������������� */
void Account::Rate(double new_rate)
{
    interest_rate_ = new_rate;
}

/*��������*/
constexpr int Account::period_;
