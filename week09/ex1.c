#include <stdio.h>
#include <stdbool.h>
typedef struct page Page;
const int max_bit = 7;

struct page {
    int id;
    int count;
};

int _iterator;
float hit, miss;

int main(int argc, char *argv[]) {
    int num_of_page_frames = atoi(argv[1]);

    Page ram[num_of_page_frames];

    for(int i=0;i<num_of_page_frames;i++) {
        ram[i].id = -1;
        ram[i].count = -1;
    }
    
    FILE *input = fopen("Lab 09 input.txt", "r");

    fscanf(input, "%d", &_iterator);

    while(!feof(input)) {
        int min_index = 0;
        bool found = 0;
        
        for(int i=0;i<num_of_page_frames;i++) {
            if(ram[min_index].count > ram[i].count) {
                min_index = i;
            }

            ram[i].count = ram[i].count >> 1;

            if(ram[i].id == _iterator) {
                hit++;
                found = 1;
                ram[i].count += (1<<max_bit);
            }
        }

         if(!found) {
            miss++;
            ram[min_index].id = _iterator;
            ram[min_index].count = (1<<max_bit);
        }

        fscanf (input, "%d", &_iterator);
    }
    
    fclose(input);

    printf("hit = %f miss = %f ratio = %f\n", hit, miss, hit/miss);

    return 0;
}