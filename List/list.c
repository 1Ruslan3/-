#include<stdio.h>
#include<stdlib.h>

// Односвязный циклический список
struct list
{
	int field; // поле данных
	struct list* ptr; // указатель на следующий элемент
};

// Инициализация ОЦС
struct list* init(int a) // а- значение первого узла
{
	struct list* lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->ptr = lst; // указатель на сам корневой узел
	return(lst);
}

// Добавление узла в ОЦС
struct list* addelem(struct list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(struct list));
	p = lst->ptr; // сохранение указателя на следующий элемент
	lst->ptr = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->ptr = p; // созданный узел указывает на следующий элемент
	return(temp);
}

// Удаление узла ОЦС
struct list* deletelem(struct list* lst)
{
	struct list* temp;
	temp = lst;
	while (temp->ptr != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла
	return(temp);
}

// Вывод элементов ОЦС
void listprint(struct list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // вывод значения узла p
		p = p->ptr; // переход к следующему узлу
	} while (p != lst); // условие окончания обхода
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