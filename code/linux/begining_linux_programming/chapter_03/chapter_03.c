
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "chapter_03.h"

void Chapter_03(int argc, char **argv)
{
    //chapter_3_4_3();
    //chapter_3_6_2();
    //chapter_3_6_3();
    chapter_3_8(argc, argv);
}

void chapter_3_4_1()
{
    if (write(1, "Here is some data\n", 18) != 18) 
        write(2, "a write error has occurred on file descriptor 1\n", 50);
}

void chapter_3_4_2()
{
    char buf[128];
    int nread;

    nread = read(0, buf, 128);
    if (nread == -1)
        write(2, "a read error has occurred\n", 27);

    if (write(1, buf, nread) != nread)
        write(2, "a write error has occurred\n", 28);
}

/**/
void chapter_3_4_3()
{
    char    c;
    int     in_fd, out_fd;
    char    buf[1024];

    in_fd = open("/home/gao_zhuo/share/snail/code/linux/begining_linux_programming/build/file.in", O_RDONLY);
    out_fd = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    // while (read(in_fd, &c, 1) == 1)
    //     write(out_fd, &c, 1);

    int nread;
    while ((nread = read(in_fd, buf, 1024)) > 0)
        write(out_fd, buf, nread);
   
    printf("write finished.");
    exit(0);
}

void chapter_3_6_2()
{
    char    s[256];
    int     n;
    float   f;
    char    c;

    //scanf("hello, %d,%g, %c, %[^\n]", &n, &f, &c, s);
    //printf("%s\n%d\n%g\n%c\n", s, n, f, c);

    char sss[256];
    //sprintf(sss, "%s-%d-%g-%c\n", s, n, f, c);
    sprintf(sss, "%s-%d-%g-%c\n", "ss123", 9, 3.14, 'a');
    printf("%s\n", sss);
}

void chapter_3_6_3()
{
    int c;
    FILE *in, *out;

    in = fopen("Makefile", "r");
    while ((c = fgetc(in)) != EOF)
        fputc(c, stdout);
    
    printf("%d\n", feof(in));
    printf("file id = %d\n", fileno(in));
    fclose(in);
    exit(0);
}

void PrintDir(void *dir, int depth)
{
    printf("%s\n", dir);
    DIR             *dp;
    struct dirent   *entry;
    struct stat     stat_buf;

    if ((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "cannot open direntry: %s\n", dir);
        return ;
    }

    chdir(dir);
    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &stat_buf);
        if (S_ISDIR(stat_buf.st_mode))
        {
            if (strcmp(".", entry->d_name) == 0||
                strcmp("..", entry->d_name) == 0)
                    continue;
            
            //printf("dir name:%s\n", entry->d_name);
            PrintDir(entry->d_name, depth + 4);
        }
        else
            printf("%*s%s\n", depth, "", entry->d_name);
    }
}

void chapter_3_8(int argc, char **argv)
{
    char *top_dir = ".";
    if (argc >= 2)
        top_dir = argv[1];

    printf("list dir...\n");
    PrintDir(top_dir, 0);
    printf("list dir done\n");

    printf("%s\n", strerror(0));
    //printf("%d\n", );
    perror("prodram");
}