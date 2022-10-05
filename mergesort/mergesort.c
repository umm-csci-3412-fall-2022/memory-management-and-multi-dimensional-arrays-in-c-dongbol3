#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void mergesort(int size, int values[]) {
    int i, next, left_min, right_min, right_max, left_max;
    int *temp = (int *)malloc(size * sizeof(int));
    for(i=1; i<size; i*=2){
        for(left_min = 0; left_min < size - i; left_min = right_max){
            right_min = left_max = left_min + i;
            right_max = left_max + i;
            if(right_max > size){
                right_max = size;
            }
            next = 0;
            while(left_min < left_max && right_min < right_max){
                if(values[left_min] < values[right_min]){
                    temp[next++] = values[left_min++];
                } else{
                    temp[next++] = values[right_min++];
                }
            }
            while (left_min < left_max){
                values[--right_min] = values[--left_max];
            }
            while (next > 0){
                values[--right_min] = temp[--next];
            }
        }

    }
    free(temp);
  // Remember that a key goal here is to learn to use
  // `malloc/calloc` and `free`, so make sure you explicitly
  // allocate any new arrays that you need, even if you
  // might not strictly need to.
}


