#include<stdio.h>
#include<string.h>

void prinfArray(int* arr, int len) {
	for (int a = 0; a < len; a++) {
		printf("%d,", arr[a]);
	}
}
/*
	选择排序
	21,5,7,4,1,9,8
	思想
	逐个选出当前剩余元素的最小值，放在前面

	第一趟 从第0个元素开始比较，依次拿第1、2、3、最后一个位置的元素，与第0个位置的元素比较，如果小于第0个位置的元素，则交换位置，否则不进行处理
	第二趟 从第1个元素开始比较，依次拿第2、3、最后一个位置的元素，与第1个位置的元素比较，如果小于第1个位置的元素，则交换位置，否则不进行处理
	循环n-1趟，结束循环得出结果

	第一趟结果 1,21,7,5,4,9,8
	第二趟结果 1,4,21,7,5,9,8
*/
void SelectionSort() {
	int arr[] = { 21,5,7,4,1,9,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int tmp;
	printf("选择排序前：");
	prinfArray(arr, len);
	printf("\n");

	for (; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (arr[j] < arr[i]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	printf("选择排序后：");
	prinfArray(arr, len);
	printf("\n");
}

void SelectionSortParams(int *arr, int len) {
	int i = 0;
	int j = 0;
	int tmp;
	printf("选择排序前：");
	prinfArray(arr, len);
	printf("\n");

	for (; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (arr[j] < arr[i]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	printf("选择排序后：");
	prinfArray(arr, len);
	printf("\n");
}

/*
	冒泡排序
	21,5,7,4,1,9,8

	思想
	从首元素开始逐个比较两个相邻位置元素的大小，如果前元素比后元素大，则交换位置，1趟排序后把当前序列中最大的数放在末尾
	因为是比较相邻元素，所以最后一个len-1位置的元素不需要放入外层循环，所以外层循环的范围是 < len - 1

	第一趟 从第0个元素开始比较，依次拿0 1, 1 2, 2 3, 3 4位置的元素比较，如果前大后小，则交换位置，否则不进行处理
	第二趟 从第0个元素开始比较，依次拿0 1, 1 2, 2 3, 3 4位置的元素比较，如果前大后小，则交换位置，否则不进行处理，因为经过第一趟后，
	最后一个元素已经是最大值了，所以不需要再比较，第二趟的比较次数为n - 1 - i次

	第一趟结果 5,7,4,1,9,8,   21
	第二趟结果 5,4,1,7,8,   9,21
*/
void BubbleSort() {
	int arr[] = { 21,5,7,4,1,9,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int tmp;
	printf("冒泡排序前：");
	prinfArray(arr, len);
	printf("\n");

	// len = 7  
	//i = 0  j = 0 ~ 6 -> j < len
	//i = 1  j = 0 ~ 5 -> j < len - 1
	//i = 2  j = 0 ~ 4 -> j < len - 2
	//i = i  j = 0 ~ len - i - 1 -> j < len - i

	for (; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("冒泡排序后：");
	prinfArray(arr, len);
	printf("\n");
}

void BubbleSortParams(int* arr, int len){
	int i = 0;
	int j = 0;
	int tmp;
	printf("冒泡排序前：");
	prinfArray(arr, len);
	printf("\n");

	// len = 7  
	//i = 0  j = 0 ~ 6 -> j < len
	//i = 1  j = 0 ~ 5 -> j < len - 1
	//i = 2  j = 0 ~ 4 -> j < len - 2
	//i = i  j = 0 ~ len - i - 1 -> j < len - i

	for (; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("冒泡排序后：");
	prinfArray(arr, len);
	printf("\n");
}