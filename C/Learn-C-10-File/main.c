#define _CRT_SECURE_NO_DEPRECATE
#include<string.h>
#include<stdio.h>
#include"fgetc.h"

int main1()
{
	//FILE* fp = NULL;
	printf("====aaaaa\n");
	fclose(stdout); // �رձ�׼���ָ��
	printf("====bbbbb\n");

	perror("====bbbbb"); // ��ӡ�ַ�������ʧ�ܵ�ԭ��
	fclose(stderr); // �ر�perror��ӡ
	return 0;
}

// ���ļ�
int main2()
{
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "./text.txt", "w"); // w����ʽ ����ļ������� ���½� ������ھʹ򿪲���������� w+�����+д
	if (err != NULL) {
		printf("err\n");
	}

	fclose(fp);
	fp = NULL;
	return 0;
}

// ���� ����ַ�fgetc��fputc
int main3()
{
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "./text.txt", "r"); // w����ʽ ����ļ������� ���½� ������ھʹ򿪲���������� w+�����+д
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