#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 3

#define FILE_MAX 19

// 字典结构图
typedef struct dict
{
	char* key;
	char* content;
} dict;

// 读取（手写内容）
void getDict(dict **tmp) { // 这里要传入dict指针的地址，所以是二级指针**
	// *tmp = p 使用的时候*tmp相当于一级指针p

	*tmp = (dict *)malloc(sizeof(dict) * MAX);

	//(*tmp)[0].key    (*(*tmp + 0)).key    (*tmp + 0)->key 这三者等价
	(*tmp + 0)->key = (char *)malloc(strlen("a") + 1);
	strcpy((*tmp + 0)->key, "a");

	(*tmp + 0)->content = (char*)malloc(strlen("字母A") + 1);
	strcpy((*tmp + 0)->content, "字母A");


	(*(*tmp + 1)).key = (char*)malloc(strlen("b") + 1);
	strcpy((*(*tmp + 1)).key, "b");

	(*(*tmp + 1)).content = (char*)malloc(strlen("字母B") + 1);
	strcpy((*(*tmp + 1)).content, "字母B");


	(*tmp)[2].key = (char*)malloc(strlen("c") + 1);
	strcpy((*tmp)[2].key, "c");

	(*tmp)[2].content = (char*)malloc(strlen("字母C") + 1);
	strcpy((*tmp)[2].content, "字母C");

}

// 格式化数据
void formatString(char *str) { // 去掉字符串结尾的回车和空格
	size_t i;
	for (i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\r') {
			str[i + 1] = '\0';
			break;
		}
	}

}

// 从文件读取内容
void getDictByTxt(dict** tmp, char * fileName) { // 这里要传入dict指针的地址，所以是二级指针**
	// *tmp = p 使用的时候*tmp相当于一级指针p
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf("打开文件%s失败\n", fileName);
		return 0;
	}

	*tmp = (dict *)malloc(sizeof(dict) * FILE_MAX);
	memset(*tmp, 0, sizeof(dict) * FILE_MAX); // 初始化为0

	//开始读取文件
	char buf[50] = { 0 };
	size_t len = 0;
	int i = 0;
	while (!feof(fp)) { // 文件不为空
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp); // 读一行
		len = strlen(buf); // 读取到的长度
		if (len > 0) {
			// 分配内存
			(*tmp)[i].key = (char *)malloc(len); // 分配内存
			memset((*tmp)[i].key, 0, len);
			formatString(buf);
			strcpy((*tmp)[i].key, buf);

			(*tmp)[i].content = (char*)malloc(len); // 分配内存
		}

		// 再读content一行
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp); // 读一行
		len = strlen(buf); // 读取到的长度
		if (len > 0) {
			// 分配内存
			(*tmp)[i].content = (char*)malloc(len); // 分配内存
			formatString(buf);
			memset((*tmp)[i].content, 0, len);
			strcpy((*tmp)[i].content, buf);
		}
		i++;
	}
	
	// 关闭文件
	fclose(fp);
	return i;
}

// 遍历
void printDict(dict *tmp) {
	for (int i = 0; i < FILE_MAX; i++) {
		printf("dict index = %d, key = %s, content = %s\n", i, tmp[i].key, tmp[i].content);
	}
}

/*
	tmp 查找地址
	key 查找key
	content 内容拷贝
	return flag 0 没找到 1 找到
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

// 释放空间
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
	// 1、定义一个字典结构体
	dict* p = NULL;
	// 2、给结构体分配空间，然后打开文件，读取字典内容，读取完毕后关闭文件
	// 3、实现对字典内容的遍历、查找
	// 4、释放内存
	//getDict(&p);
	getDictByTxt(&p, "./dict.txt");

	printDict(p);

	char inputStr[20];
	char content[100];
	printf("请输入一个单词：\n");
	scanf("%s", inputStr);

	int flag = findDict(p, inputStr, content);
	if (flag == 0) {
		printf("没有这个单词:%s\n", inputStr);
	}
	else {
		printf("单词:%s 内容:%s\n", inputStr, content);
	}

	freeDict(p);
	return 0;
}