#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 3

#define FILE_MAX 19

// �ֵ�ṹͼ
typedef struct dict
{
	char* key;
	char* content;
} dict;

// ��ȡ����д���ݣ�
void getDict(dict **tmp) { // ����Ҫ����dictָ��ĵ�ַ�������Ƕ���ָ��**
	// *tmp = p ʹ�õ�ʱ��*tmp�൱��һ��ָ��p

	*tmp = (dict *)malloc(sizeof(dict) * MAX);

	//(*tmp)[0].key    (*(*tmp + 0)).key    (*tmp + 0)->key �����ߵȼ�
	(*tmp + 0)->key = (char *)malloc(strlen("a") + 1);
	strcpy((*tmp + 0)->key, "a");

	(*tmp + 0)->content = (char*)malloc(strlen("��ĸA") + 1);
	strcpy((*tmp + 0)->content, "��ĸA");


	(*(*tmp + 1)).key = (char*)malloc(strlen("b") + 1);
	strcpy((*(*tmp + 1)).key, "b");

	(*(*tmp + 1)).content = (char*)malloc(strlen("��ĸB") + 1);
	strcpy((*(*tmp + 1)).content, "��ĸB");


	(*tmp)[2].key = (char*)malloc(strlen("c") + 1);
	strcpy((*tmp)[2].key, "c");

	(*tmp)[2].content = (char*)malloc(strlen("��ĸC") + 1);
	strcpy((*tmp)[2].content, "��ĸC");

}

// ��ʽ������
void formatString(char *str) { // ȥ���ַ�����β�Ļس��Ϳո�
	size_t i;
	for (i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\r') {
			str[i + 1] = '\0';
			break;
		}
	}

}

// ���ļ���ȡ����
void getDictByTxt(dict** tmp, char * fileName) { // ����Ҫ����dictָ��ĵ�ַ�������Ƕ���ָ��**
	// *tmp = p ʹ�õ�ʱ��*tmp�൱��һ��ָ��p
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf("���ļ�%sʧ��\n", fileName);
		return 0;
	}

	*tmp = (dict *)malloc(sizeof(dict) * FILE_MAX);
	memset(*tmp, 0, sizeof(dict) * FILE_MAX); // ��ʼ��Ϊ0

	//��ʼ��ȡ�ļ�
	char buf[50] = { 0 };
	size_t len = 0;
	int i = 0;
	while (!feof(fp)) { // �ļ���Ϊ��
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp); // ��һ��
		len = strlen(buf); // ��ȡ���ĳ���
		if (len > 0) {
			// �����ڴ�
			(*tmp)[i].key = (char *)malloc(len); // �����ڴ�
			memset((*tmp)[i].key, 0, len);
			formatString(buf);
			strcpy((*tmp)[i].key, buf);

			(*tmp)[i].content = (char*)malloc(len); // �����ڴ�
		}

		// �ٶ�contentһ��
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp); // ��һ��
		len = strlen(buf); // ��ȡ���ĳ���
		if (len > 0) {
			// �����ڴ�
			(*tmp)[i].content = (char*)malloc(len); // �����ڴ�
			formatString(buf);
			memset((*tmp)[i].content, 0, len);
			strcpy((*tmp)[i].content, buf);
		}
		i++;
	}
	
	// �ر��ļ�
	fclose(fp);
	return i;
}

// ����
void printDict(dict *tmp) {
	for (int i = 0; i < FILE_MAX; i++) {
		printf("dict index = %d, key = %s, content = %s\n", i, tmp[i].key, tmp[i].content);
	}
}

/*
	tmp ���ҵ�ַ
	key ����key
	content ���ݿ���
	return flag 0 û�ҵ� 1 �ҵ�
*/
int findDict(dict* tmp, char *key, char * content) {
	int flag = 0;

	for (int i = 0; i < FILE_MAX; i++) {
		if (strcmp(key, tmp[i].key) == 0) {
			flag = 1;
			strcpy(content, tmp[i].content);
			return flag;
		}
	}
	return flag;
}

// �ͷſռ�
void freeDict(dict* tmp) {
	for (int i = 0; i < MAX; i++) {
		if (tmp[i].key != NULL){
			free(tmp[i].key);
			tmp[i].key = NULL;
		}
		if (tmp[i].content != NULL) {
			free(tmp[i].content);
			tmp[i].content = NULL;
		}
	}
	free(tmp);
	tmp = NULL;
}

int main(int argc, char* argv[]) {
	// 1������һ���ֵ�ṹ��
	dict* p = NULL;
	// 2�����ṹ�����ռ䣬Ȼ����ļ�����ȡ�ֵ����ݣ���ȡ��Ϻ�ر��ļ�
	// 3��ʵ�ֶ��ֵ����ݵı���������
	// 4���ͷ��ڴ�
	//getDict(&p);
	getDictByTxt(&p, "./dict.txt");

	printDict(p);

	char inputStr[20];
	char content[100];
	printf("������һ�����ʣ�\n");
	scanf("%s", inputStr);

	int flag = findDict(p, inputStr, content);
	if (flag == 0) {
		printf("û���������:%s\n", inputStr);
	}
	else {
		printf("����:%s ����:%s\n", inputStr, content);
	}

	freeDict(p);
	return 0;
}