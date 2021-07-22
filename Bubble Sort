#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

void swap(int *a, int *b);
int sort(int arr[], int n);
void reverse(int arr[], int n);

int main(void)
{
  int x, n;
  char ans;

  printf("How many numbers do you want to sort?\n");
  scanf("%d", &n);

  int *nums = malloc(n*sizeof(int));

  printf("Enter your numbers: \n");
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    *(nums+i)= x;
  }

  printf("\nDo you want list in descending order (Y/N)?");
  ans = getch();

  printf("\n\nBefore Sort:\n");
  for(int i = 0; i < n; i++)
  {
    printf("%d ", nums[i]);
  }

  printf("\n\nAfter Sort:\n");

  switch(toupper(ans))
  {
    case 'N':
    sort(nums, n);
    break;

    default:
    sort(nums, n);
    reverse(nums, n);
    break;
  }

  for(int i = 0; i < n; i++)
  {
    printf("%d ", nums[i]);
  }
  free(nums);
  printf("\n");
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int sort(int arr[], int n)
{
  int i, j, temp;

  for(i = 0; i < n; i++)
  {
    for(j = 0; j<(n-1)-i; j++)
    {
      if(arr[j] > arr[j+1])
      {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

void reverse(int arr[], int n)
{
  if(n % 2 == 0)
  {
    for(int i = 0; i < n/2; i++)
    {
      swap(&arr[i], &arr[(n-1)-i]);
    }
  }
  else
  {
    for(int j = 0; j < (n-1)/2; j++)
    {
      swap(&arr[j], &arr[(n-1)-j]);
    }
  }
}
