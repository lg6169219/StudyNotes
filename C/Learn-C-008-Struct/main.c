#include<stdio.h>
#include<string.h>
#include "StructTest01.h"

struct Student {
	int age;
	char name[50];
	int score;
};

// 结构体嵌套
struct BigStudent {
	int newAge;
	struct Student info;
};

int main(int argc, char* argv[]) {
	StuctPoint();

	StuctHeapTest();

	struct Student stu; // 定义了一个结构体变量
	struct Student stu2 = { 18, "mike", 59 }; // 结构体的初始化和数组一样大括号，结构体只有在定义时候才能初始化

	// 如果是普通变量
	struct Student temp;
	temp.age = 18;
	//temp.name = "mike"; // err
	strcpy_s(temp.name, 5, "mike");
	temp.score = 59;

	// 如果是指针变量,指针需要有合法指向，才能操作结构体
	struct Student* p;
	p = &temp;
	p->age = 18;
	strcpy_s(p->name, 5, "mike");
	p->score = 59;

	// 任何结构体变量都可以用 -> 或者 . 操作成员
	(&temp)->age = 19;
	(*p).score = 59;

	// 结构体数组
	struct Student a[5]; 
	a[0].age = 18;
	strcpy_s(a[0].name, 5, "mike");
	a[0].score = 59;

	(a + 1)->age = 19;
	strcpy_s((a + 1)->name,5, "mike");
	(a + 1)->score = 60;

	(*(a + 2)).age = 20;
	strcpy_s((*(a + 2)).name, 5, "mike");
	(*(a + 2)).score = 61;

	// 结构体嵌套
	struct BigStudent bStu;
	bStu.info.age = 18;

	struct BigStudent* bStu2 = &bStu;
	bStu2->info.age = 19;


	// 相同类型结构体可以直接赋值
	struct Student newA;
	newA = temp;

	// 指针指向栈区空间
	struct Student* p2;
	struct Student temp2;
	p2 = &temp2;

	p2->age = 18;
	strcpy_s(p2->name, 4, "joy");
	p2->score = 59;
	printf("%d %s %d\n", p2->age, p2->name, p2->score);
	printf("%d %s %d\n", temp2.age, temp2.name, temp2.score);

	return 0;
}