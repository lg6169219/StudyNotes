#include<stdio.h>
#include"test.h"

int main() {
	printf("%d\n",testFunc());

	int a = 10;
	int* p = &a;

	*p = 100;

	int* q = p;
	*q = 200;

	printf("===aaaa %d %d %d\n", a, *p, *q);

	return 0;
}