
#ifndef __EFFECTIVE_CPP_ITEM_01_H__
#define __EFFECTIVE_CPP_ITEM_01_H__

#include <string>

void Item01();

#define ASPECT_RATIO    1.653
const double aspect_ratio = 1.654;

const char * const author_name = "Gauo";        // �ڶ���const
const std::string author_name2("Gauo");         // ����

class GamePlayer
{
private:
    /*
     * �����������֧��;
     * �漰��ȡ��ַ��Ҫʵ���ļ�����;
     * �����ڼ�֪��ֵ;
     * ֻ������ͳ���
     */
    static const int num_turns_ = 1024;
    int scores_[num_turns_];
};

class CostEstimate
{
public:
    static const double fudge_factor_;
};

class GamePlayer2
{
private:
    // ����ȡ��ַ
    enum {num_turns2_ = 5};
    int scores_[num_turns2_];
};

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
void f(int i);

template<typename T>
inline void CallWithMax(const T &lhs, const T &rhs)
{
    f(lhs > rhs ? lhs : rhs);
}

#endif // __EFFECTIVE_CPP_ITEM_01_H__
