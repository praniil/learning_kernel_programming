#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void* myThreadFunc(void *vargp) {
    sleep(1);
    printf("Hello world from the thread \n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFunc, NULL);
    pthread_join(thread_id, NULL);
    printf("after thread \n");
    return 0;
}