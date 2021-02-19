#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fRead() {
	// 打开文件
	FILE* fp = fopen("./test01.txt", "rb");

	// 读取文件
	char buf[4 * 1024];
	memset(buf, 0, sizeof(buf));
	fread(buf, 1, sizeof(buf), fp);
	printf("======aaa %s\n", buf);
	// 关闭文件
	fclose(fp);
	fp = NULL;
}

void fWrite() {
	// 打开文件
	FILE* fp = fopen("./test01.txt", "a+");

	// 写入文件
	char buf[] = "abcd\n";
	fwrite(buf, 1, sizeof(buf), fp);
	// 关闭文件
	fclose(fp);
	fp = NULL;
}

void cpWord() {
	// 打开源文件
	FILE* fpFrom = fopen("./test01.txt", "rb");
	// 打开目标文件
	FILE* fpTo = fopen("./text.txt", "wb");

	// 从源文件读取XX大小的内容，写入到目标文件中，循环读取知道没有内容
	char buf[4];
	memset(buf, 0, sizeof(buf));

	int num;
	while (1) {
		num = fread(buf, 1, sizeof(buf), fpFrom);


		if (num == NULL) {
			break;
		}

		printf("======aaa %s \n", buf);
		fwrite(buf, 1, num, fpTo);
	}

	// 关闭目标文件
	fclose(fpTo);
	// 关闭源文件
	fclose(fpFrom);
}

#define MAX 3
struct dict {
	char* key;
	char* content;
};

void getDict(struct dict **tmp) { // tmp是一个指针变量保存的是一个指针*的地址 所以**
}