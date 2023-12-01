#include "Array.h"

void verifyArray(Array arr)
{
  if (arr.A == NULL)
  {
    abort();
  }
}

// create
Array createArray(int size)
{
  Array arr;
  arr.size = size;

  arr.A = (int *)malloc(size * sizeof(int));
  arr.length = 0;

  return arr;
}

// display
void displayArrayElements(Array *arr)
{
  verifyArray(*arr);
  int i;
  printf("Elements are: ");
  printf("[ ");
  for (i = 0; i < arr->length; i++)
  {
    if (i == arr->length - 1)
    {
      printf("%d ", arr->A[i]);
    }
    else
    {

      printf("%d, ", arr->A[i]);
    }
  }
  printf("]");
  printf("\n");
}

void destroyArray(Array *arr)
{
  free(arr->A);
  arr->A = NULL;
}

// add/append
void appendArray(Array *arr, int x)
{

  verifyArray(*arr);

  if (arr->length + 1 > arr->size)
  {
    abort();
  }
  else
  {
    arr->A[arr->length] = x;
    arr->length++;
  }
}

void insertArray(Array *arr, int index, int x)
{
  verifyArray(*arr);
  if (arr->length + 1 > arr->size)
  {
    printf("Error: no memory in array\n");
    abort();
  }
  else if (index >= arr->size)
  {
    printf("Error: invalid array index\n");
    abort();
  }
  else
  {
    for (int i = arr->length; i > index; i--)
    {
      arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
  }
}