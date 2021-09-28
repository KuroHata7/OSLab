#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr1[], int arr2[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr1[j] > arr1[j+1]){
              swap(&arr1[j], &arr1[j+1]);
              swap(&arr2[j], &arr2[j+1]);
            }
        }
    }
}

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

    completion_time[0] = at[0] + bt[0];
    turn_around_time[0] = completion_time[0] - at[0];
    waiting_time[0] = 0;

    for(int i=1;i<n;i++){
        completion_time[i] = bt[i] + completion_time[i-1];
        if(completion_time[i-1] < at[i])
            completion_time[i] = completion_time[i] + at[i] - completion_time[i-1];
        turn_around_time[i] = completion_time[i] - at[i];
        waiting_time[i] = turn_around_time[i] - bt[i];
    }

    float sum = 0;
    for(int i=0;i<n;i++)
        sum += waiting_time[i];
    float average_waiting_time = sum/n;

    sum = 0;
    for(int i=0;i<n;i++)
        sum += turn_around_time[i];
    float average_turn_around_time = sum/n;

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], completion_time[i], turn_around_time[i], waiting_time[i]);
    
    printf("Average Turnaround Time = %f\n", average_turn_around_time);
    printf("Average WT = %f\n", average_waiting_time);
    return 0;
}