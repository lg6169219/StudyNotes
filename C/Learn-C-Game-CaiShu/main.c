#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

static int max = 51;

void OnInit() {
	system("cls");
	printf_s("���������ʼ:\n");
}

void OnEnd(int sum, int totalTime) {
	printf_s("��Ϸ����\n");
	printf_s("��ʱ:%d��\n", totalTime);
	printf_s("��ȷ��:%lf %%\n", (float)sum / max * 100);

	system("pause");
}
void OnGame() {
	_getch(); // getchar�л��� _getch�޻���

	srand(time(NULL));
	// ���� 0~50�������ĸ 51��Ž�����'\0'
	char randStr[51];
	char* p = malloc(sizeof(randStr[0]) * 51);
	int i = 0; // ����
	for (; i < max - 1; i++) {
		p[i] = rand() % 26 + 'a'; // ����0~25������ Ȼ��+�ַ�'a' �������'a'-'z'���ַ�
	}
	p[i] = '\0';

	printf("���ɵ�����ַ�:\n%s\n", p);

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