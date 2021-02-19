#include<stdio.h>
#include<string.h>

int main() {
	// C语言没有string类型，所以用一维字符数组表示字符串
	char a[10] = {0};

	// 字符串一定是字符数组，字符数组不一定是字符串，

	// 如果字符数组以字符'\0'（'\0'等价于数字0）结尾，那么这个字符数组就是字符串

	char b[] = { 'a', 'b', 'c' }; // 不是字符串

	char c[] = { 'a', 'b', 'c' , '\0' }; // 字符串

	char d[] = { 'a', 'b', 'c' , 0 }; // 字符串

	// 非字符串打印时候因为没有结束符0，所以后面会出现乱码
	printf("str1 %s  str2 %s\n", b, c);

	// 常用的初始化，使用字符串初始化，在字符串结尾自动加结束符0，结束符0用户看不到但是存在
	char e[] = "abc";

	// \0后最好别跟数组，因为有可能正好组成一个转义字符

	// sizeof测数据类型大小，不会因为结束符提前结束
	char f[] = { 'a', 'b', 'c' };// sizeof长度是3个字符
	char g[] = "abc"; // sizeof长度是4个字符，因为默认有隐藏的0
	char h[4] = { 'a', 'b', 'c' }; // 这里长度为4 最多写三个字符串，留一位给结束符0

	// 字符串的输入

	char str[100];
	// 字符串a不需要&取地址，因为数组名是首元素地址，本来就是地址，其他和数组一样
	scanf_s("%s", str, 20);
	printf("输入的是%s\n", str);



	// 字符串长度 用sizeof判断 或者用strlen
	//sizeof(str)
	char str2[] = "abc";
	int len = strlen(str2); // 字符串长度（从首元素开始，到结束符为止的长度，不包含结束符）
	int len2 = sizeof(str2) / sizeof(char);

	printf("%d   %d\n", len, len2); // len = 3 len2 = 4

	return 0;
}


