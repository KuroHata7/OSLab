#include <stdio.h>
#include <pthread.h>

int transactions[200];
int count = 0;

int consumer_sleep = 0;
int producer_sleep = 0;

void sleep(int *sleep_timer){
    while(*sleep_timer){}
}

void *consumer(){
    int i = 0;
    while(1) {
        sleep(&consumer_sleep);
        
        if (count) {
            count--;
            producer_sleep = 0;
            transactions[i % 200] = i++;
        }
        else {
            consumer_sleep = 1;
        }
    }
}

void *producer(){
    int i = 0;
    while(1) {
        sleep(&producer_sleep);

        if (i % 1000 == 0)
            printf("%d\n", count);

        if (count < 200) {
            count++;
            consumer_sleep = 0;
            transactions[i % 200] = i++;
        }
        else {
            producer_sleep = 1;
        }
    }
}

int main(){
    pthread_t id;

    pthread_create(&id, NULL, producer, NULL);
    pthread_create(&id, NULL, consumer, NULL);

    pthread_join(id, NULL);

    return 0;
}