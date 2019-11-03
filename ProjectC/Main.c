#include <stdio.h> 
#include "List.h"

int main(void)                 
{                               
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*int m1[5] = { 0,  1, -1, -1, -1 }; //��� ����� ��� ��������
	int m2[5] = { 2,  3, -1, -1, -1 };
	int m3[5] = { 4, -1, -1, -1, -1 };
	int m[5] = { 1, 0, -1, -1, -1 };*/

	printf("-------------------������� �������-------------------\n");
	Node* head = NULL;

	while (1) {
		int i;
		printf("1 - �������� ����� ������ ��������, 0 - ���������: ");
		scanf_s("%d", &i);
		if (i == 1) {
			Product p = input();
			head = initList(p.name, p.unit, p.k, p.pricePerOne);

			/*Product p;
			head = initList("��� ���������", m, 930, 3.44); //��� ����� ��� ��������
			pushBack(head, "���", m1, 53, 45.54);
			pushBack(head, "������", m2, 1200, 20.45);
			pushBack(head, "������ ��������", m3, 16, 5.94);
			pushBack(head, "������ ���������", m2, 100, 10.74);
			pushBack(head, "������ �������� ����������", m3, 45, 32.5);
			pushBack(head, "��� �����������", m3, 19, 51.94);
			pushBack(head, "�����", m1, 35, 90.77);*/

			while (1) {
				int i;
				printf("������ �������? 1 - ���, 0 - �: ");
				scanf_s("%d", &i);
				if (i == 1) {
					p = input();
					pushBack(head, p.name, p.unit, p.k, p.pricePerOne);
				}
				else {
					printf("\n");
					while (1) {
						Product *p;
						int i;
						printf("������ ������� �� ������� - 1: \n������ �������� �� ���� - 2\n"
							"�������� ������� �� ������� - 3\n�������� ������� �� ������� - 4\n"
							"�������� ������ - 5\n����������� ������ - 6\n������� �������� ������� ������ - 7\n"
							"������ ������� ������ �� �������� - 8\n������ ���� ������ �� �������� - 9\n"
							"��������� - ���� �����\n������ ��� ����: ");
						scanf_s("%d", &i);
						if (i == 1) {
							int n;
							printf("\n������ ��������� ������(�� 1): ");
							scanf_s("%d", &n);
							p = getNth(head, n - 1);
							printProduct(p);
							printf("\n");
							continue;
						}
						if (i == 2) {
							printf("\n");
							char n[50];
							printf("������ �������� �����: ");
							getchar();
							gets_s(n, 50);
							searchName(head, n);
							printf("\n");
							continue;
						}
						if (i == 3) {
							printf("\n");
							int n;
							printf("������ ��������� ������(�� 1): ");
							scanf_s("%d", &n);
							Product p = input();
							addIndex(head, n - 1, p);
							printf("\n");
							continue;
						}
						if (i == 4) {
							printf("\n");
							int n;
							printf("������ ��������� ������(�� 1): ");
							scanf_s("%d", &n);
							deleteNth(&head, n - 1);
							printf("\n");
							continue;
						}
						if (i == 5) {
							deleteList(&head);
							printf("������ ��������.\n");
							break;
						}
						if (i == 6) {
							printf("\n");
							printLinkedList(head);
							continue;
						}
						if (i == 7) {
							printf("\n");
							commonPrice(head);
							printf("\n");
							continue;
						}
						if (i == 8) {
							printf("\n");
							int n;
							printf("������ ��������� ������(�� 1): ");
							scanf_s("%d", &n);
							int sum;
							printf("������ ����(������� �� ��'����): ");
							scanf_s("%d", &sum);
							changeAmount(&head, sum, n - 1);
							printf("\n");
							continue;
						}
						if (i == 9) {
							printf("\n");
							int n;
							printf("������ ��������� ������(�� 1): ");
							scanf_s("%d", &n);
							double sum;
							printf("������ ���� �������: ");
							scanf_s("%lf", &sum);
							changePrice(&head, sum, n - 1);
							printf("\n");
							continue;
						}
						deleteList(&head);
						break;
					}
					break;
				}
					
			}
		}
		else {
			break;
		}
	}

	getchar();
	getchar();
	return 0;                   
}