

#ifndef __CPP_PRIMER_ACCOUNT_H__
#define __CPP_PRIMER_ACCOUNT_H__

#include <string>

class Account
{
public:
    /* 7-6 ��̬��Ա */
    //�����κζ����
    //������const
    //������this
    static double   Rate() { return interest_rate_; }
    static void     Rate(double new_rate);

    //��Ա��������ֱ��ʹ�þ�̬��Ա
    void            Calculate() { amount_ += amount_ * interest_rate_; }
private:
    std::string     owner_;
    double          amount_;

    static double   interest_rate_;    //����
    static double   InitRate();

    /* ��̬��Ա���ڳ�ʼ�� */
    //constexpr���Ϳ������ڳ�ʼ��,��ʼֵ�ǳ������ʽ
    static constexpr int period_ = 30;
    double daily_tbl[period_];
};

#endif // __CPP_PRIMER_ACCOUNT_H__
