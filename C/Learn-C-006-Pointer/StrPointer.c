#include<stdio.h>

void StrPoint() {
	char str[] = "hello";

	str[0] = '1';
	*(str + 0) = '1';

	*(str + 1) = '2';
	printf("str = %s\n", str);

	char* p = NULL;
	p = &str[0];
	p = str; // �ȼ� ���������׵�ַ

	*p = 'a';
	p++;
	*p = 'b';

	printf("str = %s\n", str); //abllo
	printf("p = %s\n", p); //bllo

	printf("p = %s\n", p - 1); //abllo
}

void StrCopy(char * dst, const char *src) {
	int i = 0;
	while (*(src + i) != '\0') {
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	printf("str=%s\n", dst);
}

void StrMatching(char *tarStr, char *str) {
	int i = 0;
	char* temp = NULL;

	while (1) // 0��false  !0 ture
	{
		temp = strstr(tarStr, str);
		if (temp == NULL) {
			break;
		}
		else
		{
			i++;
			tarStr = temp + strlen(str);
		}
	} 

	printf("abc����Ϊ%d\n", i);
}

// �ַ����ҿո�(ȥ����Ч�ַ�)
void StrFindSpace() {
	char* str = "    aaabc   ";
	// ͷָ��
	char* head = str;
	// βָ��
	char* tail = str + strlen(str) - 1;

	// ��ͷ��β��
	while (*head == ' ' && *head != '\0')
	{
		head++;
	}
	// ��β����ͷ
	while (*tail == ' ' && tail != head)
	{
		tail--;
	}
	int n = tail - head + 1;
	printf("str num %d\n", n);
}

int isSign(char a) {
	return (a == '+' || a == '-');
}

int isNumber(char a) {
	return (a >= '0' && a <= '9');
}
int MyAtoi(char *str) {
	int i = 0;
	char* start = str;
	int haveSign = 0;
	int errStr = 0;
	char newStr[16] = {0};
	int starIndex = 0; // starIndex��־λ�滻Ϊָ��start

	while (start[i] != '\0') // start[i] �ȼ��� *(start+i) ��������û������ָ��
	{
		if (isSign(start[i])) {
			if (haveSign) {
				errStr = 1;
				break;
			}
			haveSign = 1;
			newStr[starIndex] = start[i];
			starIndex++;
		}

		if (isNumber(start[i])) {
			newStr[starIndex] = start[i];
			starIndex++;
		}
		i++;
	}
	newStr[starIndex] = 0;
	

	printf("======newStr = %s\n", newStr);
	return newStr;
}

int MyAtoiNew(char* str) {
	char* tmp = str;
	int flag = 0; // 0 + 1 -
	if (*tmp == '-') {
		flag = 1;
		tmp++;
	}
	else if (*tmp == '+') {
		flag = 0;
		tmp++;
	}

	int num = 0;
	while (*tmp != '\0') {
		num = num * 10 + (*tmp - '0');
		tmp++;
	}
	if(flag == 0){
		return num;
	}
	else {
		return -num;
	}
}

int GetSum() {
	char a[] = "12,43,55,22,19,35,38";
	char* num[10] = {0};

	char* b = "";

	int i = 0;
	int sum = 0;
	int j = 0;
	char* start = a;
	while (*start != '\0') {
		if (*start == ',') { // ��Ҫ���ַ�
			i++;
			j = 0;
		}
		else {
			char* temp = num[i];
			temp = start;
			printf("=====11 %d \n", (*temp) - 48);
			temp++;
		}
		start++;
	}

	return 1;
}

int GetSum2() {
	char a[] = "12,43,55,22,19,35,38";
	int num = 0;

	char* b;
	b = strtok(a, ",");
	while (b)
	{
		num += atoi(b); // sscanf(b, "%d", &i)
		b = strtok(NULL, ",");
	}
	return num;
}