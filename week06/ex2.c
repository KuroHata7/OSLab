#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE* fp = fopen("./input.csv", "r");
    
    int n, at[20], bt[20];

    char buffer[1024];
    int row = -1;
    int column = 0;

    while (fgets(buffer, 1024, fp)){
        column = 0;
        row++;
        char* token = strtok(buffer, ",");
        while(token){
            if(strlen(token) > 1)
                token[1] = '\0';
            
            if(column == 0){
                at[row] = atoi(token);
            }

            if(column == 1){
                bt[row] = atoi(token);
            }
            token = strtok(NULL, ",");
            column++;
        }
    }
    fclose(fp);

    n = row+1;

    bubble_sort(at, bt, n);

    int completion_time[20];
    int turn_around_time[20];
    int waiting_time[20];
    
    return 0;
}