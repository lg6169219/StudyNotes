#define _CRT_SECURE_NO_DEPRECATE
#include<string.h>
#include<stdio.h>
#include"fgetc.h"

int main1()
{
	//FILE* fp = NULL;
	printf("====aaaaa\n");
	fclose(stdout); // 关闭标准输出指针
	printf("====bbbbb\n");

	perror("====bbbbb"); // 打印字符串调用失败的原因
	fclose(stderr); // 关闭perror打印
	return 0;
}

// 打开文件
int main2()
{
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "./text.txt", "w"); // w的形式 如果文件不存在 就新建 如果存在就打开并且清空内容 w+代表读+写
	if (err != NULL) {
		printf("err\n");
	}

	fclose(fp);
	fp = NULL;
	return 0;
}

// 输入 输出字符fgetc、fputc
int main3()
{
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "./text.txt", "r"); // w的形式 如果文件不存在 就新建 如果存在就打开并且清空内容 w+代表读+写
	if (err != NULL) {
		printf("err\n");
	}

	//char a[] = "abc aaa ddd";
	//int len = strlen(a);
	//for (int i = 0; i < len; i++) {
	//	int ch = fputc(a[i], fp);
	//	printf("ch = %c\n", ch);
	//}

	char ch1;
	while (!feof(fp)) {
		ch1 = fgetc(fp);
		printf("fgetc = %c ", ch1);
	}
	printf("\n");


	fclose(fp);
	fp = NULL;
	return 0;
}

int main(int argc, char* argv[]) {
	//writeFile();
	//readTextFile();
	//readBinaryFile();
	//myVi(argv[1]);
	//myVi("./text.txt");
	//writeRandomNum();
	//readRandomNum();

	//fRead();
	//fWrite();
	cpWord();
	return 0;
}