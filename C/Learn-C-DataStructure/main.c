#include<stdio.h>
#include<string.h>
#include"Sort.h"

int main(int argc, char* argv[]) {
	//SelectionSort();

	//BubbleSort();
	int arr[] = { 21,5,7,4,1,9,8 };
	int len = sizeof(arr) / sizeof(arr[0]);

	SelectionSortParams(arr, len);

	BubbleSortParams(arr, len);
	return 0;
}