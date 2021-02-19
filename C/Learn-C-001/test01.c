#include<stdio.h>

// 冒泡排序
int main(int argc, char* argv[]) {
	int a[] = { 0, 1,-1,2,-2,3,-3,4,-4,5,-5 };
	int n = sizeof(a) / sizeof(a[0]);

	/*
		试数
		n = 8
		1、 i = 0; j < 8
			j = 0, j < 8,  a[0] a[1]
			j = 1, j < 8,  a[1] a[2]
			j = 2, j < 8,  a[2] a[3]
			j = 3, j < 8,  a[3] a[4]
			j = 4, j < 8,  a[4] a[5]
			j = 5, j < 8,  a[5] a[6]
			j = 6, j < 8,  a[6] a[7]
			j = 7, j < 8,  a[7] a[8]
			j = 8, j >= 8,  退出本次循环

		2、 i = 0; j < 7
			j = 0, j < 7,  a[0] a[1]
			j = 1, j < 7,  a[1] a[2]
			j = 2, j < 7,  a[2] a[3]
			j = 3, j < 7,  a[3] a[4]
			j = 4, j < 7,  a[4] a[5]
			j = 5, j < 7,  a[5] a[6]
			j = 6, j < 7,  a[6] a[7]
			j = 7, j >= 7,  退出本次循环
	*/
	int start = 0;
	for (start = 0; start < n - 1; start++) {
		for (int j = 0; j < n - 1 - start; j++) {
			if (a[j] > a[j+1]) { // 比较相邻元素，大则交换位置
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	for (start = 0; start < n - 1; start++) {
		printf("num %d\n", a[start]);
	}
	return 0;
}


// 二维数组的初始化
int main(int argc, char* argv[]) {
	int a[3][4] = {
		{1,2,3,4},{1,2,3,4},{1,2,3,4}
	};

	// 这种写法前面缺省，后面必须初始化，不能int a[][4];
	int a[][4] = { 1,2,3,4 ,1,2,3,4 ,1,2,3,4 };

	// 因为计算机内存中没有多维数组，全部用一维数组存储
	int a[3][4] = { 1,2,3,4 ,1,2,3,4 ,1,2,3,4 };

	// 没有初始化的元素赋值为0
	int a[3][4] = { 1,2,3,4 };

	// 所有元素初始化为0
	int a[3][4] = {0};

	int b[5][10];

	// 1、数组名是常量，不能修改

	// 2、sizeof(数组名)，测数组的总大小  5 * int[10] = 5 *4 * 10 = 200

	// 3、sizeof(b[0]) 测的是第0个元素（数组）的大小
}