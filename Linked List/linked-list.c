#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node
{
  int number;
  struct node *next;
}node;

node *list = NULL;
int choice = 0, counter = 0, numm, integer;

int push(int num);
void printinfo();
int search(int integer);
void freemem();

int main()
{
	while (choice != 5)
	{
		Sleep(300);
    printf("	       OPTIONS\n* * * * * * * * * * * * * * * * * * *\n*1.Add a new number.                *\n*2.Print stored numbers.            *\n*3.Search for a number in the list. *\n*4.Clear Screen                     *\n*5.Exit Program                     *\n* * * * * * * * * * * * * * * * * * *\n");
    printf("\t  [TOTAL NUMBERS = %d]\n", counter);
    printf("Enter a choice: ");
		scanf(" %d[a-z]", &choice);

		switch(choice)
		{
			case 1:
			printf("\nEnter the number you want to add: ");
			scanf(" %d", &numm);
			push(numm);
      counter+=1;
			printf("Number added: %d", numm);
			printf("\n\n");
			break;

			case 2:
			printf("\nThe stored numbers are: ");
			printinfo();
			printf("\n\n");
			break;

			case 3:
			printf("\nEnter the number you want to search for: ");
			scanf(" %d", &integer);
			search(integer);
			break;

      case 4:
      printf("-----------*Clearing Screen*------------");
      Sleep(700);
      system("cls");
      break;

			case 5:
			printf("\n--------*Exiting program*----------\n");
			freemem();
			Sleep(1500);
			break;

			default:
			printf("\n-------!Choice Not Valid!--------\n\n");
			break;
		}
	}
}

int push(int num)
{
  if (list != NULL)
  {
    node *n = malloc(sizeof(node));
    n->number = num;
    n->next = list;
    list= n;
  }
  else
  {
    node *n = malloc(sizeof(node));
    n->number = num;
    n->next = NULL;
    list = n;
  }
}

void printinfo()
{
	if (list != NULL)
	{
		for (node *tmp = list; tmp != NULL; tmp = tmp->next)
		{
			printf("%i ", tmp->number);
		}
	}
}

int search(int integer)
{
  int count = 0;
	node *temporary = list;
	while(temporary != NULL)
	{
		node *temp = temporary->next;
    count+=1;
		if(temporary->number == integer)
		{
			printf("--------*Found at position %d*--------\n\n", count);
			return 0;
		}
		temporary = temp;
	}
	printf("--------*Not found*--------\n\n");
	return 1;
}

void freemem()
{
	while(list!=NULL)
	{
		node *temp = list->next;
		free(list);
		list = temp;
	}
}
