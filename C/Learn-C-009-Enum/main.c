#include<stdio.h>

///////////////// ö�� enum
enum Color1{
	// ��һ����Ա���û�и�ֵ��Ĭ��Ϊ0����һ����Ա����һ����1
	pink,red,green // 0 1 2 ...
	// pink = 1000, red, green...
};

enum Color2{
	// ��һ����Ա���û�и�ֵ��Ĭ��Ϊ0����һ����Ա����һ����1
	blue = 1000, yellow, white
};

enum Num1{
	// ��һ����Ա���û�и�ֵ��Ĭ��Ϊ0����һ����Ա����һ����1
	one, two, three
};

///////////////////////// �ṹ�� typedef������
struct Test
{
	int a;
};
struct Test t1;

typedef struct Test2  // ��struct Test2�������Test2
{
	int b;
}Test2;
Test2 t2;


int main() {

	printf("enum1 %d\n", pink);

	printf("enum1 %d %d %d\n", blue, yellow, white);

	// ö�ٱ���
	enum Num1 flag;
	flag = blue;
	printf("enum3 %d\n", flag);

	// typedef ���Ѵ��ڵķ������߽ṹ�������
	// typedef ���ܴ����µ�����
	typedef enum Num1 newNum;
	newNum flag2 = yellow;
	printf("enum4 %d\n", flag2);
	// typedef struct Student newStudent;
	// newStudent stu;

	// typedef int int64; ��int��һ��������int64

	// �궨����Ԥ����׶Σ�typedef�����ڱ���׶�
	return 0;
}