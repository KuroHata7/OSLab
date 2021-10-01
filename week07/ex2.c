#include<stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    
    int *a = malloc(N * sizeof(int));

    for(int i=0;i<N;i++)
        a[i] = i;

    for(int i=0;i<N;i++){
        printf("%d ", a[i]);
        if(i == N-1)
            printf("\n");
    }
    
    free(a);
    
    return 0;
}