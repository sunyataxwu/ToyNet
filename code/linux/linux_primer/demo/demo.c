#include <stdio.h>
#include <unistd.h>

int main()
{
    int cnt = 10;
    while (cnt)
    {
        printf("剩余时间:%2d\r", cnt);  // 利用\r回车来实现同一个像素点，显示多个数字，这样看起来就像倒计时
        fflush(stdout);                // 每次刷新一下缓冲区，立马显示数据
        cnt--;
        sleep(1);
    }
    return 0;
}
