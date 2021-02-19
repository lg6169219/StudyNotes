#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void writeFile() {
	// ���ļ�
	FILE* fp = NULL;
	fp = fopen("./text.txt", "a");
	// д�ļ�
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc(-1, fp);
	fputc('1', fp);
	fputc('2', fp);
	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

void readTextFile() {
	// ���ļ�
	char ch;
	FILE* fp = NULL;
	fp = fopen("./text.txt", "r");
	// ��ȡ�ļ�
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
	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

// �������ƻ����ı��ļ� feof����ļ��������򷵻ط�0ֵ�����򷵻�0
void readBinaryFile() {
	// ���ļ�
	char ch;
	FILE* fp = NULL;
	fp = fopen("./text.txt", "r");
	// ��ȡ�ļ�
	printf("read binary file\n");
	while (1)
	{
		ch = fgetc(fp);
		if (feof(fp)) { // ��βΪtrue �������
			break;
		}
		printf("%c", ch);
	}
	printf("\n");
	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

void myVi(char *fileName) {
	// ���ļ�
	FILE* fp = fopen(fileName, "w");

	char buf[1024];
	while (1)
	{
		//Ĭ���������з����˴�������ȡ�����з�������buf
		// fgets���ж�ȡ
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

	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

void writeRandomNum() {
	srand(time(NULL));

	// ���ļ�
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

	// �ر�
	fclose(fp);
	fp = NULL;
}

void readRandomNum() {
	// ���ļ�
	FILE* fp = fopen("./test01.txt", "r");

	int a[1024] = {0};
	int i = 0;

	char buff[100];
	int num;

	while (1) {
		fgets(buff, sizeof(buff), fp);
		if (feof(fp)) { //�ļ���β
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
	// �ر�
	fclose(fp);
	fp = NULL;
}