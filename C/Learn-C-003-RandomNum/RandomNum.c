#include<stdio.h>
#include<stdlib.h>

int main() {
	// ���������ӣ���������һ�μ���(���ӹ̶���ÿ�γ������������������Ҳ�̶�)�������õ�ǰtime�������
	//srand(100);
	srand(time(NULL)); // time(NULL)���ܻ�ȡϵͳ��ǰʱ�䣬����ʱ���䣬srand������Ҳ���

	int i = 0;
	int num;
	for (i = 0; i < 10; i++) {
		num = rand(); // ���������
		printf("num = %d\n", num);
	}

	// rand����������0~�㹻��
	// ����4��0~9������ rand() % 100
	// ����1~10 rand() % 100 + 1


	return 0;
}