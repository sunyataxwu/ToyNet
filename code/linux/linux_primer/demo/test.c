#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // C接口（有缓冲）
    printf("hello printf\n");
    fprintf(stdout, "hello fprintf\n");
    fputs("hello fputs\n", stdout);

    // 系统调用接口（无缓冲，直接输出）
    const char* msg = "hello write\n";
    write(1, msg, strlen(msg)); // 不要把 \0 带上

    // 🔥 如果你注释这一行，就可能看到重复输出（C缓冲区被子进程复制）
    // fflush(stdout);
sleep(5);
    fork(); // 创建子进程

    return 0;
}
