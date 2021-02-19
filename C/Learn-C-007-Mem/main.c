#include<stdio.h>
#include<string.h>

int main() {
	char a[10];
	memset(a, 'a', sizeof(char) * 4);
	printf("=======set a = %s\n", a);
	//memcpy // 跟strcpy比较，优点在于遇到\0字符也会继续拷贝

	int a1[3] = { 1,2,3 };
	int a2[3];

	memcpy(a2, a1, sizeof(a1));
	for (int i = 0; i < 3; i++) {
		printf("====val %d \n", a2[i]);
	}

	// 字符比较memcmp
	int a3[5] = { 1,2,3,4,5 };
	int a4[5] = { 1,2,3,4,6 };
	int a5[5] = { 5,1,2,3,4 };

	int flag = memcmp(a3, a4, sizeof(a3)); // flag < 0
	int flag2 = memcmp(a4, a5, sizeof(a3)); // flag < 0
	printf("====memcmp %d  %d\n", flag, flag2);


	// int a 在栈里面分配内存 栈比较小

	// malloc 在堆里动态分配内存
	int* p;
	p = (int*)malloc(sizeof(int)); // malloc返回值是void * 万能指针  使用时候需要强制转换成指定类型
	*p = 10;
	printf("%d\n", *p);

	if (NULL != p) {
		free(p); // 需要手动释放
		p = NULL;
	}

	printf("free %d\n", *p);
	return 0;
}