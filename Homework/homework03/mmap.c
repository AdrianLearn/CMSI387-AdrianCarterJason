// source: https://stackoverflow.com/questions/26259421/use-mmap-in-c-to-write-into-memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    char *src, path[18] = ""; //file name here
    struct stat statbuf;
    int file;
    clock_t start = clock();

    if (argc != 2)
    {
        printf("usage: a.out <filename>");
        return 1;
    }

    if ((file = open(path, O_RDONLY)) < 0)
    {
        printf("cant open");
        return 1;
    }

    if ((src = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, file, 0)) == (caddr_t)-1)
    {
        printf("mmap error");
        return 1;
    }

    if (fstat(file, &statbuf) < 0)
    {
        printf("fstat error");
        return 1;
    }

    for (int i = 0; i < statbuf.st_size; i++)
    {
        if (src[i] == 'x' || src[i] == 'X')
        {
            clock_t end = clock();
            double total_time = (double)(end - start) / CLOCKS_PER_SEC;
            printf("X found in %f\n", total_time);
            free(src);
            return 0;
        }
    }

    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Cound not find an X. Time elapsed: %fs.\n", total_time);
    return 0;
}