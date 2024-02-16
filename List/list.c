#include<stdio.h>
#include<stdlib.h>

// ����������� ����������� ������
struct list
{
	int field; // ���� ������
	struct list* ptr; // ��������� �� ��������� �������
};

// ������������� ���
struct list* init(int a) // �- �������� ������� ����
{
	struct list* lst;
	// ��������� ������ ��� ������ ������
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->ptr = lst; // ��������� �� ��� �������� ����
	return(lst);
}

// ���������� ���� � ���
struct list* addelem(struct list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(struct list));
	p = lst->ptr; // ���������� ��������� �� ��������� �������
	lst->ptr = temp; // ���������� ���� ��������� �� �����������
	temp->field = number; // ���������� ���� ������ ������������ ����
	temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
	return(temp);
}

// �������� ���� ���
struct list* deletelem(struct list* lst)
{
	struct list* temp;
	temp = lst;
	while (temp->ptr != lst) // ������������� ������ ������� � �����
	{ // ���� �� ������ ����, �������������� lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // ������������ ���������
	free(lst); // ����������� ������ ���������� ����
	return(temp);
}

// ����� ��������� ���
void listprint(struct list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // ����� �������� ���� p
		p = p->ptr; // ������� � ���������� ����
	} while (p != lst); // ������� ��������� ������
}



int main()
{
	struct list* lst = NULL;
	struct list* lst1 = NULL;

	lst = init(5);
	addelem(lst, 4);
	addelem(lst, 3);
	addelem(lst, 2);
	addelem(lst, 1);

	listprint(lst);
	printf("\n");
	lst1 = deletelem(lst); 

	listprint(lst1);



	return 0;
}