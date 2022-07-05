


#ifndef __CPP_PRIMER_SCREEN_H__
#define __CPP_PRIMER_SCREEN_H__

#include <string>
#include <iostream>

/* 7-3-4 ���غ�����Ϊ��Ԫ */
//ÿ��������Ҫ������Ԫ����
class Screen;
class BitMap;
extern std::ostream& store_on(std::ostream &, Screen &);
extern std::ostream& store_on(std::ostream &, BitMap &);    //����Screen�����--->δ������Ԫ

class Screen
{
public:
    /* ��Ԫ */
    //��Ԫ�����ڴ�����
    friend class WindowMgr;

    //TODO:����ʽ������δ�������
    //friend void WindowMgr::Clear(ScreenIndex i);

    friend std::ostream& store_on(std::ostream &, Screen &);

    /* 7-3-1-1 ���ͱ���*/
    //���ڷ��ʿ���
    //����ϸ��
    //using pos = std::string::size_type;
    typedef std::string::size_type pos;
public:
    /* 7-3-1-2 �����Աû��Ĭ�ϳ�ʼֵ,��Ҫ��ʾ��ʼ����Ա */
    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height_(ht), weight_(wd), contents_(ht * wd, c) {}
    //Screen(pos ht, pos wd, char c) : height_(ht), weight_(wd), contents_(ht * wd, c) {}
public:
    /* 7-3-1-3 ���������ڲ��ĺ����Զ���Ϊ��������(���Բ�ʹ��inline) */
    inline Screen& Move(pos r, pos c)
    {
        cursor_ = r * weight_ + c;
        return *this;
    }

    //����������/��(ͬʱ����) ---> �������
    char Get(pos r, pos c) const;

    /* 7-3-1-4 ��������*/
    char Get() const { return contents_[cursor_]; }

    /* 7-3-1-5 �ɱ����ݳ�Ա */
    void SomeMember() const;

    int GetSomeNum() const { return func_call_num_; }
public:
    /* 7-3-2-1 ����*this��Ա���� */
    Screen& Set(char c);
    Screen& Set(pos r, pos c, char a = '*');

    /* 7-3-2-2 ����const���� */
    Screen& Display(std::ostream &os);
    const Screen& Display(std::ostream &os) const;

    //���ֲ��������������
    void DummyFcn(pos height);
private:
    void DoDisplay(std::ostream &os) const { os << contents_; }

public:
    /* 7-6 ��̬��Ա������ΪĬ�ϲ��� */
    Screen& Clear(char = bak_ground_);
private:
    pos             cursor_ = 0;
    pos             height_ = 1, weight_ = 0;
    std::string     contents_;

    static const char bak_ground_ = ' ';

    mutable size_t  func_call_num_;
};

inline char Screen::Get(pos r, pos c) const
{
    return contents_[r * weight_ + c];
}

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

#endif // __CPP_PRIMER_SCREEN_H__
