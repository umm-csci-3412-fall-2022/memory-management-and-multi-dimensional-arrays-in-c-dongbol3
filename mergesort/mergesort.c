#include "mergesort.h"
#define MAX_SIZE 10

void merging(int *l, int l_size, int *r, int r_size){
	int i, j, k, temp[MAX_SIZE];
	i=j=k=0;
	while (i<l_size && j<r_size){
		if(l[i]<r[j]){
            temp[k++] = l[i++];
		} else {
            temp[k++] = r[j++];
        }
	}
    while(i<l_size){
        temp[k++] = l[i++];
    }
    while(j<r_size){
        temp[k++] = r[j++];
    }
    for(int i=0; i<l_size + r_size; i++){
        l[i] = temp[i];
    }
}

void mergesort(int size, int values[]) {
    int *l = values;
    int *r = values + size / 2;
    int l_size = size / 2;
    int r_size = size - l_size;
    if(size > 1){
        mergesort(l_size, l);
        mergesort(r_size, r);
        merging(l, l_size, r, r_size);
    }
  // Remember that a key goal here is to learn to use
  // `malloc/calloc` and `free`, so make sure you explicitly
  // allocate any new arrays that you need, even if you
  // might not strictly need to.
}


