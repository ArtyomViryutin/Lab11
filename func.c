#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <stdlib.h>	
#include <string.h>
#define A 100


int check_string(char *str) 
{
	if (str[0] == '.')  // Проверка на случай,если строка состоит из одной точки
	{
		printf("String can't consist of only point.Try again.\n");
		system("pause");
		return -1; // В случае срабатывания проверки возвращаем -1 и повторяем ввод
	}

	for (int i = 0; i < strlen(str) - 1; i++)  // Проверка на ввод только латинских букв
	{

		if (!(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z' || str[i] == ' ' || str[i] == '\n'))
		{
			printf("Entered unacceptable string.Try again.\n");
			system("pause");
			return -1;
		}

	}
	if (str[strlen(str) - 1] != '.') // Проверка на наличие точки в конце строки

	{
		printf("Entered unacceptable string.At the end of the string must be point.Try again.\n");
		system("pause");
		return -1;
	}
	return 0;
}


list *create_head(char *field) 
{
	list *head;
	head = (struct list*)malloc(sizeof(struct list)); // Выделение памяти под корень списка
	head->field = field;
	head->next = NULL; // Указатель на следующий узел
	head->prev = NULL; // Указатель на предыдущий узел
	return head;
}


list * add_elem(list *lst, char *s)
{
	list *temp, *p;
	temp = (struct list*)malloc(sizeof(list)); // Выделение памяти под узел списка
	p = lst->next; // Сохранение указателя на следующий узел
	lst->next = temp; // Предыдущий узел указывает на создаваемый
	temp->field = s; // Сохранение поля данных добавляемого узла
	temp->next = p; // Созданный узел указывает на следующий узел
	temp->prev = lst; // Созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return temp;
}


void print_list(list *head) 
{
	list *p;
	p = head; // Пока указатель на следующий узел не равен нулю выводим элементы
	do {
		printf("%s\n", p->field); // Вывод значения элемента p
		p = p->next; // Переход к следующему узлу
	} while (p != NULL); // Условие окончания обхода
}


char *search_max(list *head, char *max) 
{
	list *p;
	p = head;
	do {
		if (strcmp(max, p->field) > 0) // Сравниваем слова
			strcpy(max, p->field); // Если слово больше максимального , то копируем его в массив max
		p = p->next; // Переход к следующему узлу
	} while (p != NULL); // Условие окончания обхода

	return max; // Возвращаем казатель на максимальное слово
}

list *delete_elem(list *lst) 
{
	list *prev, *next;
	prev = lst->prev; // Узел, предшествующий lst
	next = lst->next; // Узел, следующий за lst
	if (prev != NULL)
		prev->next = lst->next; // Переставляем указатель
	if (next != NULL)
		next->prev = lst->prev; // Переставляем указатель
	free(lst); // Освобождаем память удаляемого элемента
	return(prev); // Возвращаем казатель на предыдущий узел
}


list *delete_head(list *head) 
{
	struct list *temp;
	temp = head->next;
	if (head->next == NULL) { // Случай когда все элементы списка одинаковые
		printf("All items of the list were the same and were deleted.\n");
		system("pause");
		exit(0);
	}
	temp->prev = NULL;
	free(head);   // Освобождение памяти текущего корня
	return(temp); // Возвращаем указатель на новый корень списка
}


list *delete_equal(list *head, char *max) 
{
	list *p, *new = NULL;
	p = head;
	do {
		if (p == NULL) // Проверка ,чтобы исключить выход за границы списка
			break;

		if (strcmp(max, p->field) == 0) { // Сравниваем максимальное слово с текуущим словом в узле
			if (p->prev == NULL) { // Если это корень списка ,то переходим к фнкции удаления головы и присваиваем указатель на нее переменной new
				p = delete_head(p);
				new = p;
			}
			else
				p = delete_elem(p); // Если это не корень списка , то переходим к функции даления узла
		}

		else
			p = p->next; // Переход к следующему узлу

	} while (p != NULL); // Условие окончания обхода

	return new; // Возвращение указателя на новый корень , если корень не удалялся то возвращается NULL
}


void print_reverse(list *lst) 
{
	list *p;
	p = lst;
	while (p->next != NULL) // Условие окончания обхода
		p = p->next;  // Переход к концу списка
	do {
		printf("%s\n", p->field); // Вывод значения элемента p
		p = p->prev; // Переход к предыдущему узлу
	} while (p != NULL); // Условие окончания обхода
}

void create(list *head,char *sep,char *s) 
{
	list *temp;
	temp = head;
	// Выделение последующих частей
	while (s != NULL)
	{
		s = strtok(NULL, sep); // Выделение очередной части строки
		if (s == NULL)
			break;

		temp = add_elem(temp, s); // Добавления узла списка и возвращение указатель на него
	}
}

void free_list(list *head) 
{
	list* p;
	while (head != NULL) { // Условие окончания обхода
		p = head;
		head = head->next;
		free(p); // Очистка узла списка
	}
}
