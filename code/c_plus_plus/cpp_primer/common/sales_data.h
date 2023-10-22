
#ifndef __CPP_PRIMER_SALES_DATA_H__
#define __CPP_PRIMER_SALES_DATA_H__

#include <string>
#include <iostream>

#if 0
class SalesData;
std::istream&   Read(std::istream &is, SalesData &item);                // >>
std::ostream&   Print(std::ostream &os, SalesData &item);               // <<
SalesData       Add(const SalesData& lhs, const SalesData &rhs);        //+
#endif

class SalesData
{
#if 0
    friend std::istream&    Read(std::istream &is, SalesData &item);
    friend std::ostream&    Print(std::ostream &os, SalesData &item);
    friend SalesData        Add(const SalesData& lhs, const SalesData &rhs);
#endif
    friend std::ostream&    operator<<(std::ostream &, const SalesData &);
    friend std::istream&    operator>>(std::istream &, SalesData &);
    friend SalesData        operator+(const SalesData &, const SalesData &);
    friend SalesData        operator-(const SalesData &, const SalesData &);

    friend bool             operator==(const SalesData &, const SalesData &);
    friend bool             operator!=(const SalesData &, const SalesData &);
public:
#if 0
    SalesData() = default;
    SalesData(std::istream &is = std::cin);
    SalesData(const std::string &s = "") : book_no_(s) {}
#endif
    SalesData(const std::string &s, unsigned n, double p) :
        book_no_(s), units_sold_(n), revenue_(p) {}

    SalesData() : SalesData("", 0, 0){}
    SalesData(std::string &s) : SalesData(s, 0, 0) {}
    SalesData(std::istream &is) : SalesData() 
    { 
        //Read(is, *this);
        is >> *this; 
    }

    SalesData(const SalesData &) = default;
    SalesData& operator=(const SalesData &);
    ~SalesData() = default;
public:
    SalesData& operator+=(const SalesData &);
    SalesData& operator-=(const SalesData &);
    SalesData& operator=(const std::string &isbn);
public:
    std::string Isbn() const { return book_no_; }
    //SalesData& Combine(const SalesData &rhs);   // +=
private:
    double AvgPrice() const ;
private:
    std::string     book_no_;
    unsigned int    units_sold_ = 0;
    double          revenue_ = 0.0;
};

std::ostream&   operator<<(std::ostream &, const SalesData &);
std::istream&   operator>>(std::istream &, SalesData &);
SalesData       operator+(const SalesData &, const SalesData &);
SalesData       operator-(const SalesData &, const SalesData &);
bool            operator==(const SalesData &, const SalesData &);
bool            operator!=(const SalesData &, const SalesData &);

#endif // __CPP_PRIMER_SALES_DATA_H__
