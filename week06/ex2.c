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
            if (arr1[j] == arr1[j+1]){
                if(arr2[j] == arr2[j+1]){
                    swap(&arr1[j], &arr1[j+1]);
                    swap(&arr2[j], &arr2[j+1]);
                }
            }
            else if(arr1[j] > arr1[j+1]){
                swap(&arr1[j], &arr1[j+1]);
                swap(&arr2[j], &arr2[j+1]);
            }
        }
    }
}

int main(){
    FILE* fp = fopen("./input.csv", "r");
    
    int n, at[20], bt[20], temp[20], t = 0, cnt = 0, s_p = 0;

    char buffer[1024];
    int row = -1;
    int column = 0;

    while (fgets(buffer, 1024, fp)){
        column = 0;
        row++;
        char* token = strtok(buffer, ",");
        while(token){
            for(int i=0;i<strlen(token);i++){
                if(token[i] == '\n'){
                    token[i] = '\0';
                    break;
                }
            }
            
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

    bubble_sort(at,bt,n);

    for(int i=0;i<n;i++)
        temp[i] = bt[i];

    int completion_time[20];
    int turn_around_time[20];
    int waiting_time[20];
    float sum1 = 0, sum2 = 0;

    bt[19] = 1e4;

    for(t=0;cnt!=n;t++){
        s_p = 19;
        for(int i=0;i<n;i++)
            if(bt[i] < bt[s_p] && (at[i] <= t && bt[i] > 0))
                s_p = i;
        
        bt[s_p]--;

        if(!bt[s_p]){
            cnt++;
            waiting_time[s_p] = t + 1 - at[s_p] - temp[s_p];
            turn_around_time[s_p] = t + 1 - at[s_p];

            sum1 += waiting_time[s_p];
            sum2 += turn_around_time[s_p];

            completion_time[s_p] = turn_around_time[s_p] + at[s_p];
        }
    }

    float average_waiting_time = sum1/n;
    float average_turn_around_time = sum2/n;

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], temp[i], completion_time[i], turn_around_time[i], waiting_time[i]);
    
    printf("Average Turnaround Time = %f\n", average_turn_around_time);
    printf("Average WT = %f\n", average_waiting_time);
    return 0;
}