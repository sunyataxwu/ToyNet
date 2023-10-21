
#ifndef __CPP_PRIMER_STR_BLOB_H__
#define __CPP_PRIMER_STR_BLOB_H__

#include <string>
#include <memory>
#include <vector>
#include <utility>

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
public:
    StrBlob();
    StrBlob(const std::initializer_list<std::string> &il);

    StrBlob(std::vector<std::string> *p);
    StrBlob(const StrBlob &rhs);
    StrBlob& operator=(const StrBlob &rhs);
public:
    size_type   Size() const { return data_->size(); }
    bool        Empty() const { return data_->empty(); }
    void        PushBack(const std::string &t) { data_->push_back(t); }
    void        PushBack(std::string &&t) { data_->push_back(std::move(t)); }   //
    void        PopBack();

    std::string& Front();
    std::string& Back();
    const std::string& Front() const;
    const std::string& Back() const;
public:
    StrBlobPtr Begin();
    StrBlobPtr End();
    StrBlobPtr Begin() const;
    StrBlobPtr End() const;
private:
    std::shared_ptr<std::vector<std::string>> data_;
    void CheckSize(size_type i, const std::string &msg) const;
public:
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
public:
    std::string& operator[](size_t n) { return (*data_)[n]; }
    const std::string& operator[](size_t n) const {return (*data_)[n]; }
public:    
    StrBlob(StrBlob &&rhs);
    
    StrBlob& operator=(StrBlob &&rhs);
    //StrBlob(std::string *, std::string*);

};

bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
bool operator<(const StrBlob &lhs, const StrBlob &rhs);
bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
bool operator>(const StrBlob &lhs, const StrBlob &rhs);
bool operator>=(const StrBlob &lhs, const StrBlob &rhs);

#endif // __CPP_PRIMER_STR_BLOB_H__
