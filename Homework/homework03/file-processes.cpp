#include <unistd.h>
#include <stdio.h>
//#include <iostream>
#include <fcntl.h>
//#include <sys/wait.h>
#include <sys/stat.h>
using namespace std;
int main()
{
    pid_t returnedValue = fork();
    if (returnedValue < 0)
    {
        perror("error forking");
        return -1;
    }
    else if (returnedValue == 0)
    {
        if (close(STDIN_FILENO) < 0)
        {
            perror("error closing standard output");
            return -1;
        }
        // When there is no error, open returns the smallest file
        // descriptor not already in use by this process, so having
        // closed STDOUT_FILENO, the open should reuse that number.
        //possible STDIN_FILENO
        if (open("/etc/passwd", O_RONLY | S_IUSR) < 0)
        {
            perror("error opening my-processes");
            return -1;
        }
        execlp("tr", "tr", "a-z", "A-Z", NULL); // ps with option letter l
        perror("error executing ps");
        return -1;
    }
    else
    {
        if (waitpid(returnedValue, 0, 0) < 0)
        {
            perror("error waiting for child");
            return -1;
        }
        cout << "Note the parent still has the old standard output."
             << endl;
    }
}
