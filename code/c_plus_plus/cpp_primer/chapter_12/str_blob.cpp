
#include "str_blob.h"

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

/*****************************************************************/
/***************************12.1********************************/

GZStrBlob::GZStrBlob() : data_(make_shared<vector<string>>()){}
GZStrBlob::GZStrBlob(const initializer_list<string> &il) : data_(make_shared<vector<string>>(il)){}


void GZStrBlob::CheckSize(size_type i, const string &msg) const
{
    if (i >= data_->size())
        throw out_of_range(msg);
}

string& GZStrBlob::Back()
{
    CheckSize(0, "back on empty GZStrBlob.");
    return data_->back();
}

string& GZStrBlob::Front()
{
    CheckSize(0, "front on empty GZStrBlob.");
    return data_->front();
}

void GZStrBlob::PopBack()
{
    CheckSize(0, "pop back on empty GZStrBlob.");
    return data_->pop_back();
}

/* hw 12.3 */
const string& GZStrBlob::Front() const
{
    CheckSize(0, "front on empty GZStrBlob.");
    return data_->front();
}

const string& GZStrBlob::Back() const
{
    CheckSize(0, "back on empty GZStrBlob.");
    return data_->back();
}

/* ch 12.1.6 */

GZStrBlobPtr GZStrBlob::Begin() { return GZStrBlobPtr(*this); }
GZStrBlobPtr GZStrBlob::End() { return GZStrBlobPtr(*this, data_->size()); }

/* hw 12.22 */
GZStrBlobPtr GZStrBlob::Begin() const { return GZStrBlobPtr(*this); }
GZStrBlobPtr GZStrBlob::End() const { return GZStrBlobPtr(*this, data_->size()); }


GZStrBlob::GZStrBlob(vector<string> *p) : data_(p){}

// homework 13.25��Ϊ��ֵ
//GZStrBlob::GZStrBlob(const GZStrBlob &rhs)
//{
//    data_ = make_shared<vector<string>>(*rhs.data_);
//}

//GZStrBlob& GZStrBlob::operator=(const GZStrBlob &rhs)
//{
//    data_ = make_shared<vector<string>>(*rhs.data_);
//    return *this;
//}

GZStrBlob::GZStrBlob(const GZStrBlob &rhs) : data_(rhs.data_){}
GZStrBlob& GZStrBlob::operator=(const GZStrBlob &rhs)
{
    data_ = rhs.data_;
    return *this;
}




////////////////////////////////////////////////////////

shared_ptr<vector<string>> GZStrBlobPtr::Check(size_t i, const string &msg) const
{
    auto ret = wptr_.lock();
    if (!ret)
        throw runtime_error("unbound GZStrBlobPtr");

    if (i >= ret->size())
        throw out_of_range(msg);

    return ret;
}

string& GZStrBlobPtr::Deref() const
{
    auto p = Check(curr_, "dereference past end.");
    return (*p)[curr_];
}

GZStrBlobPtr& GZStrBlobPtr::Incr()
{
    Check(curr_, "increment past end GZStrBlobPtr");
    ++curr_;    // �˴���������,�������������У��
    return *this;
}

string& GZStrBlobPtr::Deref(int index) const
{
    auto p = Check(curr_ + index, "dereference past end.");
    return (*p)[curr_ + index];
}

GZStrBlobPtr& GZStrBlobPtr::Decr()
{
    --curr_;
    Check(curr_, "decrement past begin of GZStrBlobPtr.");
    return *this;
}

bool Equal(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ == rhs.curr_);  // ��ָ�����ָ����ͬ��vector
    else
        return false;
}

bool NotEqual(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    return !Equal(lhs, rhs);
}

/****************************************************************/
/***************************14.3*********************************/

GZStrBlobPtr operator+(const GZStrBlobPtr &lhs, int n)
{
    GZStrBlobPtr ret(lhs);
    ret.curr_ += n;
    return ret;
}


GZStrBlobPtr operator-(const GZStrBlobPtr &lhs, int n)
{
    GZStrBlobPtr ret = lhs;
    ret.curr_ -= n;
    return ret;
}

bool operator==(const GZStrBlob &lhs, const GZStrBlob &rhs)
{
    return lhs.data_ == rhs.data_;
}

bool operator!=(const GZStrBlob &lhs, const GZStrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator==(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ == rhs.curr_);
    return false;
}

bool operator!=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

GZStrBlobPtr& GZStrBlobPtr::operator++()
{
    Check(curr_, "increment past end GZStrBlobPtr");
    ++curr_;
    return *this;
}

GZStrBlobPtr& GZStrBlobPtr::operator--()
{
    --curr_;
    Check(curr_, "decrement past begin of GZStrBlobPtr.");
    return *this;
}

GZStrBlobPtr GZStrBlobPtr::operator++(int)
{
    GZStrBlobPtr ret = *this;
    ++(*this);
    return ret;
}

GZStrBlobPtr GZStrBlobPtr::operator--(int)
{
    GZStrBlobPtr ret = *this;
    --(*this);
    return ret;
}

string& GZStrBlobPtr::operator*() const
{
    auto ret = Check(curr_, "xxxxx");
    return (*ret)[curr_];
}

string* GZStrBlobPtr::operator->() const
{
    return &(this->operator*());
}

