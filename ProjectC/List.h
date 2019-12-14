#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct product {
	char name[50];
	int unit[5];
	int k;
	double pricePerOne;
} Product;

typedef struct Node {
	char name[50];
	int unit[5];
	int k;
	double pricePerOne;
	struct Node *next;
} Node;

void inputFile(Node** head);
Product input(); //Введення продукту з консолі
Node* initList(char *n, int *un, int kk, double price); //ініціалізація списку
Product deleteItem(Node **head);//видалення останнього елементу
Node* getNth(Node* head, int n); //пошук продукта по індексу
void addIndex(Node *head, unsigned n, Product val); // вставка елемента по індексу
Product deleteNth(Node **head, int n); //видалення елемента по індексу
void deleteList(Node **head); //видалення списку товарів
void printLinkedList(const Node *head); //друкування списку товарів
void printFile(const Node *head); //друкування списку товарів
void printProductFile(const Product *p, FILE *fp);
void printProduct(const Product *p); //друкування окремого товару
double commonPrice(const Node *head); //загальна вартість товарів
void changeAmount(Node** head, int ck, int number); //зміна кількості товару за номером
void changePrice(Node** head, double ck, int number); //зміна кількості ціни за номером
void searchName(Node* head, char *Name); //пошук продукта по назві
void pushBack(Node *head, char *n, int *un, int kk, double price);

