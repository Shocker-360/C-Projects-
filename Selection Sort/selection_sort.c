#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

void swap(int *x, int *y);
void sort(int *nums, int n);
void reverse(int *arr, int n);

char ans;

int main(void)
{
  int n;
  printf("How many numbers do you want to add: "); // Asking for total numbers to be stored
  scanf("%d", &n);

  int *nums = malloc(sizeof(int)*n);
  if (nums == NULL)                 // Checking if malloc failed to allocate memory
  {
    return 1;
  }

  printf("Enter your number:\n");   // Input your numbers:
  for (int i = 0; i < n; i++)
  {
    scanf("%d", nums+i);
  }

  printf("\nDo you want list in ascending or descending order? (A/D)");
  ans = getch();

  printf("\n\nBefore Sort: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", *(nums+i));
  }
  printf("\n");
  switch(toupper(ans))
  {
    case 'A':
    sort(nums, n);
    break;

    default:
    sort(nums, n);
    reverse(nums, n);
    break;
  }

  printf("\nAfter sort: ");
  for (int k = 0; k < n; k++)
  {
    printf("%d ", *(nums+k));
  }
  printf("\n");

  free(nums); // Freeing allocated memory
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void sort(int *nums, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int *min = nums+j;
      if (*(nums+j+1) > *min)
      {
        continue;
      }
      else
      {
        min = (nums+j+1);
      }

      swap(min, nums+j);
    }
  }
}

void reverse(int *arr, int n)
{
  if(sizeof(arr)% 2 == 0)
  {
    for(int i = 0; i < n/2; i++)
    {
      swap((arr+i), (arr+((n-1)-i)));
    }
  }
  else
  {
    for(int j = 0; j < (n-1)/2; j++)
    {
      swap(arr+j, arr+((n-1)-j));
    }
  }
}
