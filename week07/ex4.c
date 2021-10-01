#include<stdio.h>

void *_realloc(void *ptr, int size){
    if(size <= 0){
        free(ptr);
        return NULL;
    }
    
    void *new_ptr = malloc(size);

}