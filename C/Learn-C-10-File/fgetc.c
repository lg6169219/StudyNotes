#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void writeFile() {
	// 打开文件
	FILE* fp = NULL;
	fp = fopen("./text.txt", "a");
	// 写文件
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc(-1, fp);
	fputc('1', fp);
	fputc('2', fp);
	// 关闭文件
	fclose(fp);
	fp = NULL;
}

void readTextFile() {
	// 打开文件
	char ch;
	FILE* fp = NULL;
	fp = fopen("./text.txt", "r");
	// 读取文件
	printf("read text file\n");
	while (1)
	{
		ch = fgetc(fp);

		if (ch == EOF) {
			break;
		}
		else {
			printf("%c", ch);
		}
	}
	printf("\n");
	// 关闭文件
	fclose(fp);
	fp = NULL;
}

// 读二进制或者文本文件 feof如果文件结束，则返回非0值，否则返回0
void readBinaryFile() {
	// 打开文件
	char ch;
	FILE* fp = NULL;
	fp = fopen("./text.txt", "r");
	// 读取文件
	printf("read binary file\n");
	while (1)
	{
		ch = fgetc(fp);
		if (feof(fp)) { // 结尾为true 代表结束
			break;
		}
		printf("%c", ch);
	}
	printf("\n");
	// 关闭文件
	fclose(fp);
	fp = NULL;
}

void myVi(char *fileName) {
	// 打开文件
	FILE* fp = fopen(fileName, "w");

	char buf[1024];
	while (1)
	{
		//默认遇到换行符，此处结束读取，换行符都放在buf
		// fgets按行读取
		fgets(buf, sizeof(buf), stdin);
		if (strncmp(buf, ":wq", 3) == 0) {
			break;
		}
		int i = 0;
		while (buf[i] != '\0') {
			fputc(buf[i], fp);
			i++;
		}
	}

	// 关闭文件
	fclose(fp);
	fp = NULL;
}

void writeRandomNum() {
	srand(time(NULL));

	// 打开文件
	FILE* fp = fopen("./test01.txt", "w");
	int num;
	char str[10];

	int i = 0;
	for (; i < 500; i++) {
		num = rand() % 100 + 1;   //(1~100)
		sprintf(str, "%d\n", num);
		printf("=====str %s", str);

		fputs(str, fp);
	}

	// 关闭
	fclose(fp);
	fp = NULL;
}

void readRandomNum() {
	// 打开文件
	FILE* fp = fopen("./test01.txt", "r");

	int a[1024] = {0};
	int i = 0;

	char buff[100];
	int num;

	while (1) {
		fgets(buff, sizeof(buff), fp);
		if (feof(fp)) { //文件结尾
			break;
		}
		sscanf(buff, "%d\n", &num);
		a[i] = num;
		i++;
	}
	int n = i;
	i = 0;
	for (; i < n; i++) {
		printf("num %d \n", a[i]);
	}
	// 关闭
	fclose(fp);
	fp = NULL;
}