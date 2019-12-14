#include "List.h"

char *Units[5] = { "кг", "г", "л", "мл", "шт" };
enum typeUnit { kg, g, l, ml, p };

void inputFile(Node** head) {
	char *filename = "Input.txt";
	FILE *fp = NULL;
	char cc[256];
	Product pr;
	if (fopen_s(&fp, filename, "r"))
	{
		perror("Помилка відкриття файлу\n");
		return;
	}
	fgets(cc, 256, fp);
	int s = strlen(cc);
	cc[s - 1] = '\0';
	strcpy_s(pr.name, 50, cc);
	for (int i = 0; i < 5; i++)
	{
		fgets(cc, 256, fp);
		int k = atoi(cc);
		pr.unit[i] = k;
	}
	fgets(cc, 256, fp);
	int k = atoi(cc);
	pr.k = k;
	fgets(cc, 256, fp);
	char *ptr;
	pr.pricePerOne = strtod(cc, &ptr);
	*head = initList(pr.name, pr.unit, pr.k, pr.pricePerOne);

	while ((fgets(cc, 256, fp)) != NULL)
	{
		int s = strlen(cc);
		cc[s - 1] = '\0';
		strcpy_s(pr.name, 50, cc);
		for (int i = 0; i < 5; i++)
		{
			fgets(cc, 256, fp);
			int k = atoi(cc);
			pr.unit[i] = k;
		}
		fgets(cc, 256, fp);
		int k = atoi(cc);
		pr.k = k;
		fgets(cc, 256, fp);
		char *ptr;
		pr.pricePerOne = strtod(cc, &ptr);
		pushBack(*head, pr.name, pr.unit, pr.k, pr.pricePerOne);
	}
}

Product input() {
	Product product;
	printf("\nВведіть назву товару: ");
	getchar();
	gets_s(product.name, 50);
	printf("\nВиберіть одиниці виміру(кінець введення -1), \n1 - кілограми, 2 - грами, 3 - літри, 4 - мілілітри, 5 - штуки: \n");
	int u;
	for (int j = 0; j < 5; j++) {
		printf("Одиниця виміру №%d: ", j + 1);
		scanf_s("%d", &u);
		product.unit[j] = u - 1;
		if (u == -1) {
			while (j < 5)
			{
				product.unit[j++] = -1;
			}
			break;
		}
	}
	printf("\nВведіть кількість відповідно до одиниці виміру: ");
	scanf_s("%d", &product.k);
	printf("\nВведіть ціну за одиницю товару: ");
	scanf_s("%lf", &product.pricePerOne);
	printf("\n");
	return product;
}

Node* initList(char *n, int *un, int kk, double price) {
	Node *tmp = (Node*)malloc(sizeof(Node));

	strcpy_s(tmp->name, 50, n);
	for (int i = 0; i < 5; i++) {
		tmp->unit[i] = un[i];
	}
	tmp->k = kk;
	tmp->pricePerOne = price;

	tmp->next = NULL;
	return tmp;
}

Product deleteItem(Node **head) {
	Node *pFwd = NULL;  
	Node *pBwd = NULL;  
	
	if (!head) {
		exit(-1);
	}
	
	if (!(*head)) {
		exit(-1);
	}

	pFwd = *head;
	while (pFwd->next) {
		pBwd = pFwd;
		pFwd = pFwd->next;
	}

	Product val;
	strcpy_s(val.name, 50, pFwd->name);
	for (int i = 0; i < 5; i++) {
		val.unit[i] = pFwd->unit[i];
	}
	val.k = pFwd->k;
	val.pricePerOne = pFwd->pricePerOne;
	
	if (pBwd == NULL) {
		free(*head);
		*head = NULL;
	}
	else {
		free(pFwd->next);
		pBwd->next = NULL;
	}

	return val;
}

Node* getNth(Node* head, int n) {
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}

void addIndex(Node *head, unsigned n, Product val) {
	n--;
	unsigned i = 0;
	Node *tmp = NULL;

	while (i < n && head->next) {
		head = head->next;
		i++;
	}
	tmp = (Node*)malloc(sizeof(Node));

	strcpy_s(tmp->name, 50, val.name);
	for (int i = 0; i < 5; i++) {
		tmp->unit[i] = val.unit[i];
	}
	tmp->k = val.k;
	tmp->pricePerOne = val.pricePerOne;

	if (head->next) {
		tmp->next = head->next;
	}
	else {
		tmp->next = NULL;
	}
	head->next = tmp;
}

Product deleteNth(Node **head, int n) {
	if (n == 0) {
		return deleteItem(head);
	}
	else {
		Node *prev = getNth(*head, n - 1);
		Node *elm = prev->next;

		Product val;
		strcpy_s(val.name, 50, elm->name);
		for (int i = 0; i < 5; i++) {
			val.unit[i] = elm->unit[i];
		}
		val.k = elm->k;
		val.pricePerOne = elm->pricePerOne;

		prev->next = elm->next;
		free(elm);
		return val;
	}
}

void deleteList(Node **head) {
	Node* prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

void printLinkedList(const Node *head) {
	int c = 0;
	while (head) {
		printf("№%d ", 1 + c++);
		printProduct(head);
		head = head->next;
	}
	printf("\n");
}

void printFile(const Node *head) {
	FILE *fp;
	if (fopen_s(&fp, "Output.txt", "w"))
	{
		perror("Помилка відкриття файлу\n");
		return;
	}
	int c = 0;
	while (head) {
		fprintf_s(fp, "№%d ", 1 + c++);
		printProductFile(head, fp);
		head = head->next;
	}
	fprintf_s(fp, "\n");
}

void printProductFile(const Product *p, FILE *fp) {
	fprintf_s(fp, "Товар \"%s\", %d %s, ціна за одиницю - %.2f грн., ", p->name, p->k, Units[p->unit[0]], p->pricePerOne);
	fprintf_s(fp, "додаткові одиниці виміру(");
	for (int i = 1; i < 5; i++) {
		if ((p->unit[i + 1] == -1 && p->unit[i] != -1) || i == 4) {
			fprintf_s(fp, "%s", Units[p->unit[i]]);
			break;
		}
		if (p->unit[i] != -1) {
			fprintf_s(fp, "%s, ", Units[p->unit[i]]);
		}
		else
			break;
	}
	fprintf_s(fp, ")\n");
}

void printProduct(const Product *p) {
	printf("Товар \"%s\", %d %s, ціна за одиницю - %.2f грн., ", p->name, p->k, Units[p->unit[0]], p->pricePerOne);
	printf("додаткові одиниці виміру(");
	for (int i = 1; i < 5; i++) {
		if ((p->unit[i + 1] == -1 && p->unit[i] != -1) || i == 4) {
			printf("%s", Units[p->unit[i]]);
			break;
		}
		if (p->unit[i] != -1) {
			printf("%s, ", Units[p->unit[i]]);
		}
		else
			break;
	}
	printf(")\n");
}

double commonPrice(const Node *head) {
	double sum = 0.0;
	while (head) {
		sum += head->k * head->pricePerOne;
		head = head->next;
	}
	printf("Загальна вартість товарів в списку - %.2f грн.\n", sum);
	return sum;
}

void changeAmount(Node** head, int ck, int number) {
	Node *value = getNth(*head, number);
	value->k += ck;

	if(value->k < 0) {
		printf("Кількість перевищує наявність. Значення обнулено.\n");
		value->k = 0;
	}
}

void changePrice(Node** head, double ck, int number) {
	Node* value = getNth(*head, number);
	value->pricePerOne = ck;
}

Node* getLast(Node *head) {
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}

void pushBack(Node *head, char *n, int *un, int kk, double price) {
	Node *last = getLast(head);
	Node *tmp = (Node*)malloc(sizeof(Node));

	strcpy_s(tmp->name, 50, n);
	for (int i = 0; i < 5; i++) {
		tmp->unit[i] = un[i];
	}
	tmp->k = kk;
	tmp->pricePerOne = price;
	
	tmp->next = NULL;
	last->next = tmp;
}

void searchName(Node* head, char *Name) {
	while (head) {
		if (strcmp(head->name, Name) == 0) {
			printProduct(head);
		}
		head = head->next;		
	}
}

