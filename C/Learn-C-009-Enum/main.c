#include<stdio.h>

///////////////// 枚举 enum
enum Color1{
	// 第一个成员如果没有赋值，默认为0，下一个成员比上一个多1
	pink,red,green // 0 1 2 ...
	// pink = 1000, red, green...
};

enum Color2{
	// 第一个成员如果没有赋值，默认为0，下一个成员比上一个多1
	blue = 1000, yellow, white
};

enum Num1{
	// 第一个成员如果没有赋值，默认为0，下一个成员比上一个多1
	one, two, three
};

///////////////////////// 结构体 typedef的优势
struct Test
{
	int a;
};
struct Test t1;

typedef struct Test2  // 给struct Test2起别名叫Test2
{
	int b;
}Test2;
Test2 t2;


int main() {

	printf("enum1 %d\n", pink);

	printf("enum1 %d %d %d\n", blue, yellow, white);

	// 枚举变量
	enum Num1 flag;
	flag = blue;
	printf("enum3 %d\n", flag);

	// typedef 给已存在的方法或者结构体起别名
	// typedef 不能创建新的类型
	typedef enum Num1 newNum;
	newNum flag2 = yellow;
	printf("enum4 %d\n", flag2);
	// typedef struct Student newStudent;
	// newStudent stu;

	// typedef int int64; 给int起一个别名叫int64

	// 宏定义在预处理阶段，typedef发生在编译阶段
	return 0;
}