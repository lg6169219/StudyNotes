#include<stdio.h>
#include<stdlib.h>

int main() {
	// 先设置种子，种子设置一次即可(种子固定，每次程序启动产生的随机数也固定)，可以用当前time做随机数
	//srand(100);
	srand(time(NULL)); // time(NULL)功能获取系统当前时间，由于时间会变，srand的种子也会变

	int i = 0;
	int num;
	for (i = 0; i < 10; i++) {
		num = rand(); // 产生随机数
		printf("num = %d\n", num);
	}

	// rand产生的数是0~足够大
	// 产生4个0~9的数字 rand() % 100
	// 产生1~10 rand() % 100 + 1


	return 0;
}