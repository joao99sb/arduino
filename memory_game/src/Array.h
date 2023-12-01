#pragma once

#include <stdlib.h>

typedef struct Array
{
  int *A;
  int size;
  int length;
} Array;

void verifyArray(Array arr);

// create
Array createArray(int size);

// display
void displayArrayElements(Array *arr);

void destroyArray(Array *arr);

// add/append
void appendArray(Array *arr, int x);
void insertArray(Array *arr, int index, int x);