#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0])) 

void bubble_sort(int arr[], int arr_len);
void swap(int *a, int *b);
void print_array(int arr[], int arr_size);

int main(){
  int arr[] = {5, 4, 2, 3, 1, 6, 7, 9, 8};
  
  printf("Initial array:\n");
  print_array(arr,9);

  bubble_sort(arr, 9);

  printf("Array after bubble sort:\n");
  print_array(arr, 9);

  return 0;
}

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int arr[], int arr_len){
  for(int i=0;i<arr_len-1;i++)
  {
    for(int j=0;j<arr_len-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

void print_array(int arr[], int arr_size){
  for(int i=0;i<arr_size;i++)
    printf("%d ", arr[i]);
  printf("\n");
}
