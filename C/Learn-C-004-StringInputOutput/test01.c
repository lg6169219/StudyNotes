#include<stdio.h>

int main0() {
	char buf[100];

	// fgets
	// 可以有空格,会把换行符读入
	// 从stdin(代表标准输入，键盘)，读取内容
	// 如果输入内容大于sizeof(buf)-1，只取sizeof(buf)-1,放在buf的数组
	fgets(buf, sizeof(buf), stdin);
	printf("buf=%s\n", buf);

	char buf2[] = "hello";
	puts(buf2); // 把buf内容输出到屏幕，自动在屏幕加换行，只是在显示时候加，字符串本身没有改变
	printf("%s", buf2);
	return 0;
}

int main1() {
	char buf[] = "hello";

	// stdout（代表屏幕 标准输出） 往屏幕输出buf的内容
	fputs(buf, stdout);

	return 0;
}

int main2() {
	char buf[] = "123";
	int a, b, c;
	sscanf_s(buf, "%d %d %d", &a, &b, &c);
	printf("a = %d b = %d c = %d\n", a, b, c);

	// 字符串查询
	char* p = strstr(buf, "12");
	printf("%s\n", p);

	// 字符查询
	char* p1 = strchr(buf, '2');
	printf("%s\n", p1);
	return 0;
}

int main() {
	// 字符串切割
	char buf[] = "abc@defg@igk";
	char* p = strtok(buf, "@");;
	while (p)
	{
		printf("%s\n", p);
		p = strtok(NULL, "@");
	}

	char str1[] = "-10";
	int num1 = atoi(str1);
	printf("num1 = %d\n", num1);

	char str2[] = "0.123";
	double num2 = atof(str2);
	printf("num2 = %d\n", num2);

	return 0;
}