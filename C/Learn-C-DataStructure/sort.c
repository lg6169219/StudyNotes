#include<stdio.h>
#include<string.h>

void prinfArray(int* arr, int len) {
	for (int a = 0; a < len; a++) {
		printf("%d,", arr[a]);
	}
}
/*
	ѡ������
	21,5,7,4,1,9,8
	˼��
	���ѡ����ǰʣ��Ԫ�ص���Сֵ������ǰ��

	��һ�� �ӵ�0��Ԫ�ؿ�ʼ�Ƚϣ������õ�1��2��3�����һ��λ�õ�Ԫ�أ����0��λ�õ�Ԫ�رȽϣ����С�ڵ�0��λ�õ�Ԫ�أ��򽻻�λ�ã����򲻽��д���
	�ڶ��� �ӵ�1��Ԫ�ؿ�ʼ�Ƚϣ������õ�2��3�����һ��λ�õ�Ԫ�أ����1��λ�õ�Ԫ�رȽϣ����С�ڵ�1��λ�õ�Ԫ�أ��򽻻�λ�ã����򲻽��д���
	ѭ��n-1�ˣ�����ѭ���ó����

	��һ�˽�� 1,21,7,5,4,9,8
	�ڶ��˽�� 1,4,21,7,5,9,8
*/
void SelectionSort() {
	int arr[] = { 21,5,7,4,1,9,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int tmp;
	printf("ѡ������ǰ��");
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

	printf("ѡ�������");
	prinfArray(arr, len);
	printf("\n");
}

void SelectionSortParams(int *arr, int len) {
	int i = 0;
	int j = 0;
	int tmp;
	printf("ѡ������ǰ��");
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

	printf("ѡ�������");
	prinfArray(arr, len);
	printf("\n");
}

/*
	ð������
	21,5,7,4,1,9,8

	˼��
	����Ԫ�ؿ�ʼ����Ƚ���������λ��Ԫ�صĴ�С�����ǰԪ�رȺ�Ԫ�ش��򽻻�λ�ã�1�������ѵ�ǰ����������������ĩβ
	��Ϊ�ǱȽ�����Ԫ�أ��������һ��len-1λ�õ�Ԫ�ز���Ҫ�������ѭ�����������ѭ���ķ�Χ�� < len - 1

	��һ�� �ӵ�0��Ԫ�ؿ�ʼ�Ƚϣ�������0 1, 1 2, 2 3, 3 4λ�õ�Ԫ�رȽϣ����ǰ���С���򽻻�λ�ã����򲻽��д���
	�ڶ��� �ӵ�0��Ԫ�ؿ�ʼ�Ƚϣ�������0 1, 1 2, 2 3, 3 4λ�õ�Ԫ�رȽϣ����ǰ���С���򽻻�λ�ã����򲻽��д�����Ϊ������һ�˺�
	���һ��Ԫ���Ѿ������ֵ�ˣ����Բ���Ҫ�ٱȽϣ��ڶ��˵ıȽϴ���Ϊn - 1 - i��

	��һ�˽�� 5,7,4,1,9,8,   21
	�ڶ��˽�� 5,4,1,7,8,   9,21
*/
void BubbleSort() {
	int arr[] = { 21,5,7,4,1,9,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int tmp;
	printf("ð������ǰ��");
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

	printf("ð�������");
	prinfArray(arr, len);
	printf("\n");
}

void BubbleSortParams(int* arr, int len){
	int i = 0;
	int j = 0;
	int tmp;
	printf("ð������ǰ��");
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

	printf("ð�������");
	prinfArray(arr, len);
	printf("\n");
}