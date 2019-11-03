#include <stdio.h> 
#include "List.h"

int main(void)                 
{                               
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*int m1[5] = { 0,  1, -1, -1, -1 }; //для тестів без введення
	int m2[5] = { 2,  3, -1, -1, -1 };
	int m3[5] = { 4, -1, -1, -1, -1 };
	int m[5] = { 1, 0, -1, -1, -1 };*/

	printf("-------------------МАГАЗИН МОЛОЧАР-------------------\n");
	Node* head = NULL;

	while (1) {
		int i;
		printf("1 - створити новий список продуктів, 0 - завершити: ");
		scanf_s("%d", &i);
		if (i == 1) {
			Product p = input();
			head = initList(p.name, p.unit, p.k, p.pricePerOne);

			/*Product p;
			head = initList("Сир Особливий", m, 930, 3.44); //для тестів без введення
			pushBack(head, "Сир", m1, 53, 45.54);
			pushBack(head, "Молоко", m2, 1200, 20.45);
			pushBack(head, "Сирний батончик", m3, 16, 5.94);
			pushBack(head, "Молоко селянське", m2, 100, 10.74);
			pushBack(head, "Сирний батончик шоколадний", m3, 45, 32.5);
			pushBack(head, "Сир голандський", m3, 19, 51.94);
			pushBack(head, "Масло", m1, 35, 90.77);*/

			while (1) {
				int i;
				printf("Додати елемент? 1 - так, 0 - ні: ");
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
						printf("Знайти продукт по індексу - 1: \nЗнайти продукти по назві - 2\n"
							"Вставити продукт по індексу - 3\nВидалити продукт по індексу - 4\n"
							"Видалити список - 5\nНадрукувати список - 6\nВивести загальну вартість товарів - 7\n"
							"Змінити кількість товару за індексом - 8\nЗмінити ціну товару за індексом - 9\n"
							"Завершити - інша цифра\nЗробіть ваш вибір: ");
						scanf_s("%d", &i);
						if (i == 1) {
							int n;
							printf("\nВведіть коректний індекс(від 1): ");
							scanf_s("%d", &n);
							p = getNth(head, n - 1);
							printProduct(p);
							printf("\n");
							continue;
						}
						if (i == 2) {
							printf("\n");
							char n[50];
							printf("Введіть коректну назву: ");
							getchar();
							gets_s(n, 50);
							searchName(head, n);
							printf("\n");
							continue;
						}
						if (i == 3) {
							printf("\n");
							int n;
							printf("Введіть коректний індекс(від 1): ");
							scanf_s("%d", &n);
							Product p = input();
							addIndex(head, n - 1, p);
							printf("\n");
							continue;
						}
						if (i == 4) {
							printf("\n");
							int n;
							printf("Введіть коректний індекс(від 1): ");
							scanf_s("%d", &n);
							deleteNth(&head, n - 1);
							printf("\n");
							continue;
						}
						if (i == 5) {
							deleteList(&head);
							printf("Список видалено.\n");
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
							printf("Введіть коректний індекс(від 1): ");
							scanf_s("%d", &n);
							int sum;
							printf("Введіть суму(додатню чи від'ємну): ");
							scanf_s("%d", &sum);
							changeAmount(&head, sum, n - 1);
							printf("\n");
							continue;
						}
						if (i == 9) {
							printf("\n");
							int n;
							printf("Введіть коректний індекс(від 1): ");
							scanf_s("%d", &n);
							double sum;
							printf("Введіть нову вартість: ");
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