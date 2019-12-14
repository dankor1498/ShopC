#include <stdio.h> 
#include "List.h"

int main(void)                 
{                               
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	printf("-------------------ћј√ј«»Ќ ћќЋќ„ј–-------------------\n");
	Node* head = NULL;

	while (1) {
		int i;
		printf("1 - створити новий список продукт≥в, 0 - завершити: ");
		scanf_s("%d", &i);
		if (i == 1) {
			int c;
			printf("1 - створити з файлу, 0 - створити з консол≥: ");
			scanf_s("%d", &c);
			Product p;
			if (c == 1) {				
				inputFile(&head);
			}
			else {
				p = input();
				head = initList(p.name, p.unit, p.k, p.pricePerOne);
			}

			while (1) {
				int i = 0;				
				if (c != 1) {
					printf("ƒодати елемент? 1 - так, 0 - н≥: ");
					scanf_s("%d", &i);
				}					
				if (i == 1) {
					p = input();
					pushBack(head, p.name, p.unit, p.k, p.pricePerOne);
				}
				else {
					printf("\n");
					while (1) {
						Product *p;
						int i;
						printf("«найти продукт по ≥ндексу - 1: \n«найти продукти по назв≥ - 2\n"
							"¬ставити продукт по ≥ндексу - 3\n¬идалити продукт по ≥ндексу - 4\n"
							"¬идалити список - 5\nЌадрукувати список - 6\n¬ивести загальну варт≥сть товар≥в - 7\n"
							"«м≥нити к≥льк≥сть товару за ≥ндексом - 8\n«м≥нити ц≥ну товару за ≥ндексом - 9\n"
							"«авершити - ≥нша цифра\n«роб≥ть ваш виб≥р: ");
						scanf_s("%d", &i);
						if (i == 1) {
							int n;
							printf("\n¬вед≥ть коректний ≥ндекс(в≥д 1): ");
							scanf_s("%d", &n);
							p = getNth(head, n - 1);
							printProduct(p);
							printf("\n");
							continue;
						}
						if (i == 2) {
							printf("\n");
							char n[50];
							printf("¬вед≥ть коректну назву: ");
							getchar();
							gets_s(n, 50);
							searchName(head, n);
							printf("\n");
							continue;
						}
						if (i == 3) {
							printf("\n");
							int n;
							printf("¬вед≥ть коректний ≥ндекс(в≥д 1): ");
							scanf_s("%d", &n);
							Product p = input();
							addIndex(head, n - 1, p);
							printf("\n");
							continue;
						}
						if (i == 4) {
							printf("\n");
							int n;
							printf("¬вед≥ть коректний ≥ндекс(в≥д 1): ");
							scanf_s("%d", &n);
							deleteNth(&head, n - 1);
							printf("\n");
							continue;
						}
						if (i == 5) {
							deleteList(&head);
							printf("—писок видалено.\n");
							break;
						}
						if (i == 6) {
							printf("\n");
							printLinkedList(head);
							printFile(head);
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
							printf("¬вед≥ть коректний ≥ндекс(в≥д 1): ");
							scanf_s("%d", &n);
							int sum;
							printf("¬вед≥ть суму(додатню чи в≥д'Їмну): ");
							scanf_s("%d", &sum);
							changeAmount(&head, sum, n - 1);
							printf("\n");
							continue;
						}
						if (i == 9) {
							printf("\n");
							int n;
							printf("¬вед≥ть коректний ≥ндекс(в≥д 1): ");
							scanf_s("%d", &n);
							double sum;
							printf("¬вед≥ть нову варт≥сть: ");
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