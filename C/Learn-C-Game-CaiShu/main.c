#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

static int max = 51;

void OnInit() {
	system("cls");
	printf_s("按任意键开始:\n");
}

void OnEnd(int sum, int totalTime) {
	printf_s("游戏结束\n");
	printf_s("用时:%d秒\n", totalTime);
	printf_s("正确率:%lf %%\n", (float)sum / max * 100);

	system("pause");
}
void OnGame() {
	_getch(); // getchar有回显 _getch无回显

	srand(time(NULL));
	// 生成 0~50个随机字母 51存放结束符'\0'
	char randStr[51];
	char* p = malloc(sizeof(randStr[0]) * 51);
	int i = 0; // 堆区
	for (; i < max - 1; i++) {
		p[i] = rand() % 26 + 'a'; // 生成0~25的数字 然后+字符'a' 就是随机'a'-'z'的字符
	}
	p[i] = '\0';

	printf("生成的随机字符:\n%s\n", p);

	int sum = 0;
	int startTime = time(NULL);
	i = 0;
	for (; i < max - 1; i++) {
		char inputChar = _getch();
		if (inputChar == p[i]) {
			sum++;
			printf("%c", inputChar);
		}
		else {
			printf("%c", '-');
		}
	}
	int endTime = time(NULL);
	printf("startTime = %d  endTime = %d", startTime, endTime);
	OnEnd(sum, endTime - startTime);
}



void RePlay() {

}

int main() {
	OnInit();
	OnGame();
}