#include<stdio.h>
#include<sys/resource.h>

int main(){
    for(int i=0;i<10;i++){
        char *a = malloc(10485760);
        memset(a, 0, 10485760);
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("%lld\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}