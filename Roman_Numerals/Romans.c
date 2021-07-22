#include <stdio.h>
#include <string.h>

int indeex(char array[], char num, int size);

int ind;

int main()
{
  int size;
  int nums[7] = {1, 5, 10, 50, 100, 500, 1000};
  char romans[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  char input[10];
  while(1)
  {
    int sum = 0;
    printf("\nEnter your roman numeral: ");
    scanf("%s", input);

    size = strlen(input);

    for(int l = 0; l < size; l++)
    {
      printf("%d ", nums[indeex(romans, input[l], 7)]);
    }

    for(int j = 0; j < size-1; j++)
    {
      if(nums[indeex(romans, input[j+1], 7)] > nums[indeex(romans, input[j], 7)])
      {
        sum = sum + (nums[indeex(romans, input[j+1], 7)] - nums[indeex(romans, input[j], 7)]);
      }
      else
      {
        sum = sum + (nums[indeex(romans, input[j+1], 7)] + nums[indeex(romans, input[j], 7)]);
      }
    }

    for(int k = 1; k <= size - 2; k++)
    {
      sum = sum - (nums[indeex(romans, input[k], 7)]);
    }

    printf("\n%s = %d\n", input, sum);
  }

}


int indeex(char array[], char num, int size)
{
  for(int i = 0; i < size; i++)
  {
    if(num == array[i])
    {
      ind = i;
      return ind;
    }
  }
}
