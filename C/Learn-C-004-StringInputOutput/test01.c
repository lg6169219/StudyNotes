#include<stdio.h>

int main0() {
	char buf[100];

	// fgets
	// �����пո�,��ѻ��з�����
	// ��stdin(�����׼���룬����)����ȡ����
	// ����������ݴ���sizeof(buf)-1��ֻȡsizeof(buf)-1,����buf������
	fgets(buf, sizeof(buf), stdin);
	printf("buf=%s\n", buf);

	char buf2[] = "hello";
	puts(buf2); // ��buf�����������Ļ���Զ�����Ļ�ӻ��У�ֻ������ʾʱ��ӣ��ַ�������û�иı�
	printf("%s", buf2);
	return 0;
}

int main1() {
	char buf[] = "hello";

	// stdout��������Ļ ��׼����� ����Ļ���buf������
	fputs(buf, stdout);

	return 0;
}

int main2() {
	char buf[] = "123";
	int a, b, c;
	sscanf_s(buf, "%d %d %d", &a, &b, &c);
	printf("a = %d b = %d c = %d\n", a, b, c);

	// �ַ�����ѯ
	char* p = strstr(buf, "12");
	printf("%s\n", p);

	// �ַ���ѯ
	char* p1 = strchr(buf, '2');
	printf("%s\n", p1);
	return 0;
}

int main() {
	// �ַ����и�
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