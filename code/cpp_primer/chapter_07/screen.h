


#ifndef __CPP_PRIMER_CHAPTER_07_SCREEN_H__
#define __CPP_PRIMER_CHAPTER_07_SCREEN_H__

#include <string>
#include <iostream>

class Screen
{
public:
    //��Ԫ��
    friend class WindowMgr;

    //���ͳ�Ա
    //using pos = std::string::size_type;
    typedef std::string::size_type pos;
public:
    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height_(ht), weight_(wd), contents_(ht * wd, c) {}
    //Screen(pos ht, pos wd, char c) : height_(ht), weight_(wd), contents_(ht * wd, c) {}
public:
    //��������
    char Get() const {return contents_[cursor_];}   //��ʽ����
    char Get(pos r, pos c) const;
    void SomeMember() const;

    //����*this
    Screen& Move(pos r, pos c);
    Screen& Set(char c);
    Screen& Set(pos r, pos c, char a = '*');
    //����const����
    Screen& Display(std::ostream &os);
    const Screen& Display(std::ostream &os) const;

    //���ֲ��������������
    void DummyFcn(pos height);
private:
    void DoDisplay(std::ostream &os) const { os << contents_; }
private:
    pos             cursor_ = 0;
    pos             height_ = 1, weight_ = 0;
    std::string     contents_;

    mutable size_t  func_call_num_;
};

//inline�ؼ��������ⶼ��������,�������������
inline char Screen::Get(pos r, pos c) const
{
    return contents_[r * weight_ + c];
}

//�ı��Ա֮�󷵻�����
inline Screen& Screen::Move(pos r, pos c)
{
    cursor_ = r * weight_ + c;
    return *this;
}

//mutable�ؼ���
inline void Screen::SomeMember() const
{
    ++func_call_num_;
}

inline Screen& Screen::Set(char c)
{
    contents_[cursor_] = c;
    return *this;
}

inline Screen& Screen::Set(pos r, pos c, char a)
{
    contents_[r * weight_ + c] = a;
    return *this;
}

void TestScreen();
//Screen::pos Verify(Screen::pos);
#endif // __CPP_PRIMER_CHAPTER_07_SCREEN_H__
