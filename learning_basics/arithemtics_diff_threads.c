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
    printf("result of mul: %d", result);
}

int main() {
    struct thread_data t1;
    t1.number1 = 2;
    t1.number2 = 3;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, multiplyFunc, (void*) &t1);
    pthread_join(thread_id, NULL);
    return 0;
}