#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

//gcc -o p_thread_cancel p_thread_cancel.c -lpthread && ./p_thread_cancel

void* child(void* p) {
    while(1) {
        sleep(5);
        printf("Hey mister!\n");
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t child_thread;
    int code;

    code = pthread_create(&child_thread, NULL, child, NULL);
    if (code) {
        fprintf(stderr, "pthread_create failed with code %d\n", code);
    }

    while(1) {
        char c = getchar();
        if (c = '\n') {
            break;
        }
    }

    //sleep(5);
    printf("THE CHILD (THREAD) HAS BEEN ELIMINATED.\n");
    pthread_cancel(child_thread);
    pthread_exit(NULL);
    return 0;
}