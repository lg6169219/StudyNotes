#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct NewPeople {
	int age;
	int score;
	char* name;
};

struct People {
	int age;
	int score;
	char name[50];
};

// 指针指向栈区空间
void StuctStackTest() {
	struct People* p;
	struct People temp;
	p = &temp;
	p->age = 10;
	strcpy_s(p->name, 5, "john");
	p->score = 60;
	printf("StuctHeapTest %d %s %d\n", p->age, p->name, p->score);
}

// 指针指向堆区空间
void StuctHeapTest() {
	struct People* p;
	p = (struct People *)malloc(sizeof(struct People));
	p->age = 10;
	strcpy_s(p->name, 5, "john");
	p->score = 60;
	printf("StuctHeapTest %d %s %d\n", p->age, p->name, p->score);
	if (p != NULL) {
		free(p);
	}
}

// 结构体套1级指针
void StuctPoint() {
	struct NewPeople* newP;
	newP = (struct NewPeople *)malloc(sizeof(struct NewPeople) * 1);

	newP->age = 18;
	newP->score = 60;

	newP->name = (char*)malloc(strlen("ligang") + 1);
	strcpy_s(newP->name, 7, "ligang");

	printf("StuctPoint %d %d %s\n", newP->age, newP->score, newP->name);

	// 释放 newP 和 newP->name，注意顺序，先释放子节点，再释放父节点
	if (newP->name != NULL) {
		free(newP->name);
		newP->name = NULL;
	}

	if (newP != NULL) {
		free(newP);
		newP = NULL;
	}
}