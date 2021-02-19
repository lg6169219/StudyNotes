#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "test01.h"
#include "StrPointer.h"
#include<stdlib.h>

int b;

int main1() {
	//nullPoint();

	//sortArr();

	//int* p = NULL;
	//p = func(); //err qt中会报错 vs不会 
	//*p = 100;
	//printf("a1 = %d\n", *p);

	//p = GlobalFunc(&b);
	//*p = 10;
	//printf("b1 = %d\n", b);
	StrPoint();

	char dst[100];
	char src[] = "abc";
	int n = strlen(src);
	StrCopy(dst, src);

	// 文字常量，存放在文字常量区，不能修改内容，只读
	char* p = "hello";

	StrMatching("abc123abc33abcdfbabc22", "2");

	//StrFindSpace();

	char* str = "-123ad1";
	MyAtoi(str);

	GetSum();
	return 0;
}

int getMemErr(char *p) {
	p = (char *)malloc(sizeof(char) * 100);
	if (p == NULL) {
		return -1;
	}
	strcpy(p, "aaabbb");
	printf("p = %s\n", p);
	return 0;
}

// 值传递的后果，形参的任何修改不会影响实参
int main0(void) {
	char* p = NULL;
	int ret = 0;

	ret = getMemErr(p);
	if (ret != 0) {
		printf("getMem err: %d\n", ret);
		return ret;
	}

	printf("p = %s\n", p);
}

int getMem(char** p) {
	if (p == NULL) {
		return -1;
	}
	char* tmp = (char*)malloc(sizeof(char) * 100);
	if (tmp == NULL) {
		return -2;
	}
	strcpy(tmp, "aaabbb");
	*p = tmp;
	return 0;
}

int main2(void) {
	char* p = NULL;
	int ret = 0;

	ret = getMem(&p);
	if (ret != 0) {
		printf("getMem err: %d\n", ret);
		return ret;
	}

	printf("p = %s\n", p);

	if (p != NULL) {
		free(p);
		p = NULL;
	}
}


int main3(void) {
	char* p0 = "111"; // char *p = "111" 和char p[] = "111"有区别 p[]可以修改 *p不能修改
	char* p1 = "222";
	char* p2 = "333";

	char* p[] = { "333", "222", "111" };
	int n = sizeof(p) / sizeof(p[0]);
	printf("sizeof(p) =  %d, sizeof(p[0] = %d)\n", sizeof(p), sizeof(p[0]));

	printf("排序前：\n");
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%s", p[i]);
	}

	printf("\n");

	int j = 0;
	char* tmp = (char *)malloc(sizeof(p[0]));
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(p[i], p[j]) > 0) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	printf("排序后：\n");
	i = 0;
	for (i = 0; i < n; i++) {
		printf("%s", p[i]);
	}

	printf("\n");
}



void sort_array(char **p, int n) {
	int j = 0;
	int i = 0;
	char* tmp = (char*)malloc(sizeof(p[0]));
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(p[i], p[j]) > 0) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}
void pritn_array(char*p[], int n) { // char**p
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%s", p[i]);
	}
}
int main(void) {
	char* p[] = { "333", "222", "111", "000" };
	int n = sizeof(p) / sizeof(p[0]);
	printf("排序前：\n");
	pritn_array(p, n);
	printf("\n");

	sort_array(p, n);

	printf("排序后：\n");
	pritn_array(p, n);
	printf("\n");
}