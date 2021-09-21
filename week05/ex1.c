#include<pthread.h>
#include<stdio.h>
 
 void *thread_function(void *thread_id){
     printf("Thread %d is running\n", thread_id);
     pthread_exit(NULL);
 }

 int main(){
     int n = 13;
     pthread_t threads[n];
     for(int i=0;i<n;i++){
         printf("Creating thread number %d\n", i);
         pthread_create(&threads[i], NULL, thread_function, i);
         pthread_join(threads[i], NULL);
     }
     return 0;
 }