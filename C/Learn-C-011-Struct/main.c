#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student {
	char name[30];
	int age;
}Student;

typedef struct Teacher {
	char *name;
	int age;
}Teacher;

int main() {
	Student st1 = {"john", 18};

	Student sts[3] = { "john", 18 , "tom", 19 , "lily", 20 };
	int i = 0;
	for (i = 0; i < 3; i++) {
		printf("%s, %d\n", sts[i].name, sts[i].age);
	}

	Student *sts2 = (Student*)malloc(3 * sizeof(Student));
	char buff[30];
	for (i = 0; i < 3; i++) {
		sprintf(buff, "name%d", i);
		strcpy(sts2[i].name, buff);
		sts2[i].age = 18 + i;
	}
	
	for (i = 0; i < 3; i++) {
		printf("%s, %d\n", sts2[i].name, sts2[i].age);
	}

	// 结构体套指针
	Teacher* t1 = (Teacher*)malloc(3 * sizeof(Teacher));
	for (i = 0; i < 3; i++) {
		t1[i].name = (char*)malloc(30);
		sprintf(buff, "name%d", i);
		strcpy(t1[i].name, buff);
		t1[i].age = 18 + i;
	}
	for (i = 0; i < 3; i++) {
		printf("t1 %s, %d\n", t1[i].name, t1[i].age);
		free(t1[i].name);
	}
	free(t1);

	Teacher t2;
	t2.name = (char*)malloc(30);
	strcpy(t2.name, "hello");
	t2.age = 30;
	printf("t2 %s, %d\n", t2.name, t2.age);
	free(t2.name);

	Teacher *t3 = (Teacher*)malloc(sizeof(Teacher));
	t3->name = (char*)malloc(30);
	strcpy(t3->name, "world");
	t3->age = 30;
	printf("t3 %s, %d\n", t3->name, t3->age);
	free(t3->name);
	free(t3);

	return 0;
}