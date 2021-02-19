#include<stdio.h>

void nullPoint() {
	int* p = NULL;

	int a = 100;
	p = &a;

	if (p != NULL) {
		*p = 100;
	}
	printf("%d\n", a);

	printf("%d\n", sizeof(int*));

	// 用[]操作指针

	int b = 200;
	int* q = &b;
	// *q 等价于 *(q + 0) 等价于 q[0]
	printf("*q = %d, q[0] = %d\n", *q, q[0]);

	// void *a 万能指针 定义任何类型的指针，在读取时需要转换指针类型，否则无法读取

	// const 修饰符  const *a,(不能改*a指向的内存) * const a（不能改a保存的地址）
		
	int arr[] = {1, 2, 3, 4, 5, 6};
	// arr[0]  arr[1] 代表的操作数组指针+1 *(a+0)  *(a+1)
	int* pp = arr;

	printf("=========%d  %d  %d\n", *pp, *(pp +2), *(pp + 3));
	return 0;
}

void sortArr() {
	int a[] = {2,4,5,1,7,2,0,1};

	int temp;
	int i = 0;
	int n = sizeof(a) / sizeof(*a);

	for (; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			//if (a[j] > a[j + 1]) {
			//	temp = a[j + 1];
			//	a[j + 1] = a[j];
			//	a[j] = temp;
			//}
			printf("===cmp %d %d \n",*(a+j), *(a + j+1));
			if (*(a+j) > *(a+j+1)) {
				temp = *(a + j + 1);
				*(a + j + 1) = *(a + j);
				*(a + j) = temp;
			}
		}
	}

	i = 0;
	for (; i < n - 1; i++) {
		printf("num = %d\n", *(a + i));
	}
}