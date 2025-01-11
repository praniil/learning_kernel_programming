#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct thread_data {
    int number1;
    int number2;
};

void *multiplyFunc(void *vargp) {
    struct thread_data *data = (struct thread_data*)vargp;
    int result = data->number1 * data-> number2;
    printf("result of mul: %d \n", result);
}

void *addFunc(void *vargp) {
    struct thread_data *data = (struct thread_data*)vargp;
    int result = data->number1 + data-> number2;
    printf("result of addion: %d \n", result);
}

void *subFunc(void *vargp) {
    struct thread_data *data = (struct thread_data*)vargp;
    int result = data->number1 - data-> number2;
    printf("result of sub: %d \n", result);
}

void *divFunc(void *vargp) {
    struct thread_data *data = (struct thread_data*)vargp;
    float result = (float)data->number1 / (float)data-> number2;
    printf("result of div: %f \n", result);
}

int main() {
    struct thread_data t1;
    t1.number1 = 2;
    t1.number2 = 3;
    pthread_t thread_id1;
    pthread_t thread_id2;
    pthread_t thread_id3;
    pthread_t thread_id4;
    pthread_create(&thread_id1, NULL, multiplyFunc, (void*) &t1);
    pthread_create(&thread_id2, NULL, addFunc, (void *) &t1);
    pthread_create(&thread_id3, NULL, divFunc, (void*) &t1);
    pthread_create(&thread_id4, NULL, subFunc, (void *) &t1);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
    pthread_join(thread_id4, NULL);
    return 0;
}