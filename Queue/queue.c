#include<stdio.h>
#include<stdlib.h>
#define QMAX 100


struct queue {
	int qu[QMAX];
	int rear, frnt;
};

// ������������� �������
void init(struct queue* q) {
	q->frnt = 1;
	q->rear = 0;
	return;
}

// ���������� �������� � �������
void insert(struct queue* q, int x) {
	if (q->rear < QMAX - 1) {
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		printf("������� �����!\n");
	return;
}

// ��������, ����� �� �������
int isempty(struct queue* q) {
	if (q->rear < q->frnt)    return 1;
	else  return 0;
}

// �������� �������� �� �������
int remove(struct queue* q) {
	int x, h;
	if (isempty(q) == 1) {
		printf("������� �����!\n");
		return 0;
	}
	x = q->qu[q->frnt];
	for (h = q->frnt; h < q->rear; h++) {
		q->qu[h] = q->qu[h + 1];
	}
	q->rear--; 
	return x;
}

// ����� ��������� �������
void print(struct queue* q) {
	int h;
	if (isempty(q) == 1) {
		printf("������� �����!\n");
		return;
	}
	for (h = q->frnt; h <= q->rear; h++)
		printf("%d ", q->qu[h]);
	return;
}

int main()
{
	struct queue* q;
	int a;
	system("chcp 1251");
	system("cls");
	q = (struct queue*)malloc(sizeof(struct queue)); 
	init(q);
	print(q);
	for (int i = 0; i < 8; i++) {
		printf("������� ������� �������: ");
		scanf("%d", &a);
		insert(q, a);
	}
	printf("\n");
	print(q);
	while (q->frnt <= q->rear) {
		a = remove(q);
		printf("\n������ ������� %d\n", a);
		print(q);
	}
	getchar();
	getchar();

	return 0;
}