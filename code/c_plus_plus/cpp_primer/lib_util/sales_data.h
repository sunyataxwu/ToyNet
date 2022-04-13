
#ifndef __CPP_PRIMER_SALESDATE_H__
#define __CPP_PRIMER_SALESDATE_H__

#include <string>
#include <iostream>

class SalesData
{
public:

    /* 7-1-2-1 ����this & const & ���������ͳ�Ա���� */
    //��Ա�����ɶ�����õ���ʹ��: total.Isbn() --> SalesData::Isbn(&total)
    //��ͨ����:this������ SalesData *const --> const������const SalesData *const
    std::string Isdn() const
    {
        // ����ֱ��ʹ�ó�Ա: �ȱ��������ٱ��뺯����
        //return this->book_no_;
        return book_no_;
    }

    /* 7-1-2-3 ����this����ĺ��� */
    SalesData& Combine(const SalesData &item);

private:
    /* 7-1-2-2 ���ⶨ���Ա���� */
    double AvgPrice() const ;
public:
    /* 7-1-4-1 Ĭ�Ϲ��캯�� */
    //ĳЩ�಻��ʹ�úϳ�Ĭ�Ϲ��캯��
    //�Զ��幹�캯��֮��Ҫ��ʹ��Ĭ�Ϲ��캯���ͱ�������default
    //default�ȿ��Գ���������Ҳ���Գ����ڶ���֮��
    SalesData() = default;

    /* 7-1-4-2 ���캯����ʼֵ�б� */
    //���Գ�Ա�Ժϳ�Ĭ�Ϲ��캯����ͬ��ʽ��ʽ��ʼ��
    explicit SalesData(const std::string &s) : book_no_(s)
    {
        std::cout << "SalesData::SalesData(s) --- consturctor\n";
    }

    SalesData(const std::string &s, unsigned n, double p)
        : book_no_(s), units_sold_(n), revenue_(p * n)
    {
        std::cout << "SalesData::SalesData(s,n,p) --- consturctor\n";
    }

    /* 7-1-4-2 ���ⶨ�幹�캯�� */
    explicit SalesData(std::istream &in);
public:
    /* 7-2-1 ��Ԫ*/
    //���ڷ��ʿ��� ---> ��Ҫ��Ԫ����
    //����λ�ò��� ---> ���ܷ��ʿ��Ʒ�Լ��
    //����ָ������Ȩ��,��������,������Ҫ�ٴ�����
    //���ⲿ������ͬһͷ�ļ�����
    friend std::istream& Read(std::istream &in, SalesData &item);
    friend std::ostream& Print(std::ostream &out, const SalesData &item);
    friend SalesData Add(const SalesData &lhs, const SalesData &rhs);
public:
    /* 7-5-1 Ĭ��ʵ�κ͹��캯�� */
    //warn:��ֹ��ͻ...
//    SalesData(std::istream &in = std::cin);

    /* 7-5-2 ί�й��캯�� */
//    SalesData() : SalesData("", 0, 0) { }
//    SalesData(const std::string &s) : SalesData(s, 0, 0) { }
//    SalesData(std::istream &in) : SalesData() { Read(in, *this); }
    // -->SalesData()-->SalesData(const std::string &s, unsigned n, double p) -->Read
public:
    friend std::ostream& operator<<(std::ostream &os, const SalesData &item);
    friend std::istream& operator>>(std::istream &in, SalesData &item);
    friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);
public:
    SalesData(const SalesData &rhs) : book_no_(rhs.book_no_), units_sold_(rhs.units_sold_), revenue_(rhs.revenue_) {}
    SalesData& operator=(const SalesData &rhs);
    SalesData& operator=(const std::string &isbn);
    SalesData& operator+=(const SalesData &rhs);

    //std::string operator std::string() const { return book_no_; }
    // double operator double() const { return revenue_; }

private:
    std::string     book_no_;       //isbn
    unsigned        units_sold_;    //����
    double          revenue_;       //������
};

/* 7-1-3 ������صķǳ�Ա���� ---> ����������ͬһͷ�ļ� */
std::istream& Read(std::istream &in, SalesData &item);
std::ostream& Print(std::ostream &out, const SalesData &item);
SalesData Add(const SalesData &lhs, const SalesData &rhs);

std::ostream& operator<<(std::ostream &os, const SalesData &item);
std::istream& operator>>(std::istream &in, SalesData &item);

#endif // __CPP_PRIMER_SALESDATE_H__
