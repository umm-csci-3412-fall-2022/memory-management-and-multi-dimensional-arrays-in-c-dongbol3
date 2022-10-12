#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int arraySizeCount(int num_arrays, int* sizes) {
	int arraySizeCount = 0;
	for (int i = 0; i < num_arrays; i++) {
		arraySizeCount = sizes[i] + arraySizeCount;
	}
	return arraySizeCount;
}

int* arrayCombination(int num_arrays, int* sizes, int** values) {
	int arraySize = arraySizeCount(num_arrays, sizes);
	int* arrayMerged = (int*) calloc(arraySize, sizeof(int));
	int indexNum = 0;

	for (int i = 0; i < num_arrays; i++) {
		for (int j = 0; j < sizes[i]; j++) {
			arrayMerged[indexNum] = values[i][j];
			indexNum++;
		}
	}
	return arrayMerged;
}

int specNumsFind(int arraySize, int* values) {
	if (arraySize == 0){
		return 0;
	}

	int specNums = 1;
	int prevNum = values[0];

	for (int i = 1; i < arraySize; i++) {
		if (values[i] != prevNum) {
			specNums++;
			prevNum = values[i];
		}
	}
	return specNums;
}

int* dedupe(int arraySize, int* values) {
	int specNums = specNumsFind(arraySize, values);
	int* arrayFinal = (int*) calloc(specNums + 1, sizeof(int));
	arrayFinal[0] = specNums;

	if (arraySize == 0) {
		return arrayFinal;
	}

	arrayFinal[1] = values[0];
	int prevNums = values[0];
	int indexNum = 2;

	for (int i = 1; i < arraySize; i++) {
		if (values[i] != prevNums) {
			arrayFinal[indexNum] = values[i];
			prevNums = values[i];
			indexNum++;
		}
	}
	return arrayFinal;
}
	
int* array_merge(int num_arrays, int* sizes, int** values) {
  int* arrayCombinationResult = arrayCombination(num_arrays, sizes, values);
  int arraySizeResult = arraySizeCount(num_arrays, sizes);
  mergesort(arraySizeResult, arrayCombinationResult);
  int* arrayFinal = dedupe(arraySizeResult, arrayCombinationResult);

  free(arrayCombinationResult);

  return arrayFinal;
}
