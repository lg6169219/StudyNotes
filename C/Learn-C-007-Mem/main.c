#include<stdio.h>
#include<string.h>

int main() {
	char a[10];
	memset(a, 'a', sizeof(char) * 4);
	printf("=======set a = %s\n", a);
	//memcpy // ��strcpy�Ƚϣ��ŵ���������\0�ַ�Ҳ���������

	int a1[3] = { 1,2,3 };
	int a2[3];

	memcpy(a2, a1, sizeof(a1));
	for (int i = 0; i < 3; i++) {
		printf("====val %d \n", a2[i]);
	}

	// �ַ��Ƚ�memcmp
	int a3[5] = { 1,2,3,4,5 };
	int a4[5] = { 1,2,3,4,6 };
	int a5[5] = { 5,1,2,3,4 };

	int flag = memcmp(a3, a4, sizeof(a3)); // flag < 0
	int flag2 = memcmp(a4, a5, sizeof(a3)); // flag < 0
	printf("====memcmp %d  %d\n", flag, flag2);


	// int a ��ջ��������ڴ� ջ�Ƚ�С

	// malloc �ڶ��ﶯ̬�����ڴ�
	int* p;
	p = (int*)malloc(sizeof(int)); // malloc����ֵ��void * ����ָ��  ʹ��ʱ����Ҫǿ��ת����ָ������
	*p = 10;
	printf("%d\n", *p);

	if (NULL != p) {
		free(p); // ��Ҫ�ֶ��ͷ�
		p = NULL;
	}

	printf("free %d\n", *p);
	return 0;
}