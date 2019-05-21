#pragma once
typedef struct list {
	char *field;
	struct list *next; // Указатель на следующий элемент списка
	struct list *prev; // Указатель на предыдущий элемент списка
}list;

int check_string(char *str); // Функция проверка корректности ввода(только латинские буквы,в конце точка)
list *create_head(char *field); // Функция создания головы списка
list * add_elem(list *lst, char *s); // Функция добавления элемента в список
void print_list(list *head); // Функция печати списка
void print_reverse(list *lst); // Функция печати списка в обратном порядке
char *search_max(list *head, char *max); // Функция максимального слова в лексеграфическом смысле
list *delete_elem(list *lst); // Функция удаления элементов равных максимальному, если этот элемент не голова списка
list *delete_head(list *head); // Функция удаления элемента равном максимальному , если этот элемент голова списка
list *delete_equal(list *head, char *max); // Функция удаления
void create(list *head, char *sep, char *s); // Фнкция создания списка
void free_list(list *head); // Функция очистки списка
