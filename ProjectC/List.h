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

Product input(); //�������� �������� � ������
Node* initList(char *n, int *un, int kk, double price); //����������� ������
Product deleteItem(Node **head);//��������� ���������� ��������
Node* getNth(Node* head, int n); //����� �������� �� �������
void addIndex(Node *head, unsigned n, Product val); // ������� �������� �� �������
Product deleteNth(Node **head, int n); //��������� �������� �� �������
void deleteList(Node **head); //��������� ������ ������
void printLinkedList(const Node *head); //���������� ������ ������
void printProduct(const Product *p); //���������� �������� ������
double commonPrice(const Node *head); //�������� ������� ������
void changeAmount(Node** head, int ck, int number); //���� ������� ������ �� �������
void changePrice(Node** head, double ck, int number); //���� ������� ���� �� �������
void searchName(Node* head, char *Name); //����� �������� �� ����

