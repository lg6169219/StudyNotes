#include<stdio.h>
#include<string.h>
#include "StructTest01.h"

struct Student {
	int age;
	char name[50];
	int score;
};

// �ṹ��Ƕ��
struct BigStudent {
	int newAge;
	struct Student info;
};

int main(int argc, char* argv[]) {
	StuctPoint();

	StuctHeapTest();

	struct Student stu; // ������һ���ṹ�����
	struct Student stu2 = { 18, "mike", 59 }; // �ṹ��ĳ�ʼ��������һ�������ţ��ṹ��ֻ���ڶ���ʱ����ܳ�ʼ��

	// �������ͨ����
	struct Student temp;
	temp.age = 18;
	//temp.name = "mike"; // err
	strcpy_s(temp.name, 5, "mike");
	temp.score = 59;

	// �����ָ�����,ָ����Ҫ�кϷ�ָ�򣬲��ܲ����ṹ��
	struct Student* p;
	p = &temp;
	p->age = 18;
	strcpy_s(p->name, 5, "mike");
	p->score = 59;

	// �κνṹ������������� -> ���� . ������Ա
	(&temp)->age = 19;
	(*p).score = 59;

	// �ṹ������
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

	// �ṹ��Ƕ��
	struct BigStudent bStu;
	bStu.info.age = 18;

	struct BigStudent* bStu2 = &bStu;
	bStu2->info.age = 19;


	// ��ͬ���ͽṹ�����ֱ�Ӹ�ֵ
	struct Student newA;
	newA = temp;

	// ָ��ָ��ջ���ռ�
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