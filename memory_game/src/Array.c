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
    abort();
  }
  else if (index >= arr->size)
  {
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