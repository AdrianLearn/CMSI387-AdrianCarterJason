#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60
#define GREEN "\033[;32m" // color codes for outputting to console
#define YELLOW "\033[;33m"
#define BLUE "\033[;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[;36m"
#define WHITE "\033[0;37m"
static int MB = 1000 * 1000; //for conversion from bytes to megabytes
double videoFileSize, totalSize, documentFileSize, pictureFileSize, audioFileSize, applicationFileSize, otherFileSize;
int isDirectory(const char *path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
    {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

int checkNotDot(char *str)
{
    return strcmp(str, ".") != 0 && strcmp(str, "..") != 0;
}

/*
*   Ensure all types are accurate for comparsion
*/
char *toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

double checkSize(const char *file_name)
{
    double size;
    struct stat st; /*declare stat variable*/

    /*get the size using stat()*/

    if (stat(file_name, &st) == 0)
    {
        stat(file_name, &st);
        size = st.st_size;
        size /= MB;
        return (size);
    }
    else
        return -1;
}

/*
*   So I tried to do this in a switch statement but apparently C doesn't like expressions
*   in cases so it's just one big comparator function kinda cringe but will work
*/
int typing(char *str)
{
    char *dot = strrchr(str, '.');
    char *file = toLowerCase(dot);
    double size = checkSize(str);
    if (file && !strcmp(file, ".txt") || !strcmp(file, ".csv") ||
        !strcmp(file, ".doc") || !strcmp(file, ".xls") ||
        !strcmp(file, ".pdf") || !strcmp(file, ".rtf") ||
        !strcmp(file, ".ppt"))
    {
        printk("document file found ");
        documentFileSize += size;
    }
    else if (file && !strcmp(file, ".mp4") || !strcmp(file, ".avi") ||
             !strcmp(file, ".m4v") || !strcmp(file, ".mov") ||
             !strcmp(file, ".mpg") || !strcmp(file, ".wmv"))
    {
        printk("video file found ");
        videoFileSize += size;
    }
    else if (file && !strcmp(file, ".jpeg") || !strcmp(file, ".jpg") ||
             !strcmp(file, ".gif") || !strcmp(file, ".png") || !strcmp(file, ".ico"))
    {
        printk("picture file found ");
        pictureFileSize += size;
    }
    else if (file && !strcmp(file, ".mp3") || !strcmp(file, ".wav") ||
             !strcmp(file, ".cda") || !strcmp(file, ".mid") || !strcmp(file, ".mpa"))
    {
        printk("audio file found ");
        audioFileSize += size;
    }
    else if (file && !strcmp(file, ".bat") || !strcmp(file, ".exe") ||
             !strcmp(file, ".exe") || !strcmp(file, ".jar") || !strcmp(file, ".py") ||
             !strcmp(file, ".c") || !strcmp(file, ".cpp") || !strcmp(file, ".class") ||
             !strcmp(file, ".h"))
    {
        printk("Application file found ");
        applicationFileSize += size;
    }
    else
    {
        printk("System file/Other file");
        otherFileSize += size;
    }
    totalSize += size;

    return 0;
}

int run(void)
{
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL)
    {
        printk("Could not open current directory");
        return 0;
    }
    while ((de = readdir(dr)) != NULL)
    {
        if (isDirectory(de->d_name) && checkNotDot(de->d_name))
        {
            printk("found dir: %s\n", de->d_name);
            printk("entering Directory: %s\n", de->d_name);
            chdir(de->d_name);
            run();
        }
        else if (checkNotDot(de->d_name))
        {
            typing(de->d_name);
            printk("size: %f ", checkSize(de->d_name));
            printk("%s\n", de->d_name);
            printk("running total: %f\n\n", totalSize);
        }
    }
    printk("exiting directory\n");
    chdir("..");
    return 0;
}
// modified from https://stackoverflow.com/questions/14539867/how-to-display-a-progress-indicator-in-pure-c-c-cout-printf
void printProgress(char *type, char *color, double percentage, double size)
{
    int val = (int)(percentage * 100);
    int lpad = (int)(percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printk("%s", color);
    printk("\r %3d%% [%.*s%*s] %s (%f mb)\n", val, lpad, PBSTR, rpad, "", type, size);
    fflush(stdout);
}

int main(void)
{
    run();
    printk("Total File Size: %f mb\n", totalSize);
    printProgress("Videos ", GREEN, videoFileSize / totalSize, videoFileSize);
    printProgress("Documents", YELLOW, documentFileSize / totalSize, documentFileSize);
    printProgress("Sounds", BLUE, audioFileSize / totalSize, audioFileSize);
    printProgress("Pictures", PURPLE, pictureFileSize / totalSize, pictureFileSize);
    printProgress("Apps", CYAN, applicationFileSize / totalSize, applicationFileSize);
    printProgress("Other", WHITE, otherFileSize / totalSize, otherFileSize);
}
