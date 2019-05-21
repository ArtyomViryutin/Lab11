#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <stdlib.h>	
#include <string.h>
#define A 100


int main() {

	char str[A]; // Массив для ввода строки 

	list *head = NULL, *new;

	char *s;

	printf("Enter a string(words are separated by spaces, at the end - point:\n");

	gets(str); // Ввод строки

	while (check_string(str) == -1) { // Проверка на корректность ввода и повторный ввод в случае неправильного

		system("cls");

		printf("Enter a string(words are separated by spaces, at the end - point:\n");

		gets(str);
	}

	char sep[] = { ' ','.' }; 

	s = strtok(str, sep); // Нахождение первой лексемы строки

	head = create_head(s); // Создание головы списка

	char *max = malloc(sizeof(char)*A); // Выделение памяти под максимально слово

	strcpy(max, head->field); // Копирем первое слова строки(первый элемент списка) в массив max

	create(head, sep,s); // Создание списка

	printf("List before modification:\n");

	print_list(head); // Вывод списка до модификации

	max = search_max(head, max); // Поиск максимального в лексеграфическом смысле слова

	new = delete_equal(head, max); // Удаление слов , равных максимальному и в случае, если это голова, возвращение указателя на новую голову

	if (new != NULL)
		head = new;

	printf("List after modification:\n");

	print_list(head); // Вывод списка после модификации

	printf("Print in reverse order:\n");

	print_reverse(head); // Вывод списка в обратном порядке

	free_list(head); // Очищенска списка

	free(max); // Очистка массива с максимальным словом

	system("pause");

	return 0;

}
