#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fRead() {
	// ���ļ�
	FILE* fp = fopen("./test01.txt", "rb");

	// ��ȡ�ļ�
	char buf[4 * 1024];
	memset(buf, 0, sizeof(buf));
	fread(buf, 1, sizeof(buf), fp);
	printf("======aaa %s\n", buf);
	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

void fWrite() {
	// ���ļ�
	FILE* fp = fopen("./test01.txt", "a+");

	// д���ļ�
	char buf[] = "abcd\n";
	fwrite(buf, 1, sizeof(buf), fp);
	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

void cpWord() {
	// ��Դ�ļ�
	FILE* fpFrom = fopen("./test01.txt", "rb");
	// ��Ŀ���ļ�
	FILE* fpTo = fopen("./text.txt", "wb");

	// ��Դ�ļ���ȡXX��С�����ݣ�д�뵽Ŀ���ļ��У�ѭ����ȡ֪��û������
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

	// �ر�Ŀ���ļ�
	fclose(fpTo);
	// �ر�Դ�ļ�
	fclose(fpFrom);
}

#define MAX 3
struct dict {
	char* key;
	char* content;
};

void getDict(struct dict **tmp) { // tmp��һ��ָ������������һ��ָ��*�ĵ�ַ ����**
}