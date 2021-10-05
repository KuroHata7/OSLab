#include<stdio.h>

void *_realloc(void *ptr, size_t old_size, size_t size){
    void *new_ptr = malloc(size);

    if(ptr == NULL)
    {
        free(ptr);
        return new_ptr;
    }

    if(size <= 0)
    {
        free(ptr);
        return NULL;
    }
    

    if(size > old_size)
        size = old_size;

	memcpy(new_ptr, ptr, size);

    free(ptr);
    return new_ptr;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int *a = malloc(N * sizeof(int));

    for(int i=0;i<N;i++)
        a[i] = i;


    a = _realloc(a, N*sizeof(int), 2*N*sizeof(int));

    for(int i=0;i<2*N;i++){
        printf("%d ", a[i]);
        if(i == 2*N-1)
            printf("\n");
    }

    free(a);

    return 0;
}