//
// Created by anita on 2022/10/11.
//
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dynamicarray.h"

int isEmpty(DynamicArray *a)
{
    return a->count == 0;
    //return a->array == NULL;
}

void pushBack(DynamicArray *a, void* element)
{
    if(a->count == a->capacity)
    {
        a->capacity*=3;
        a->array = realloc(a->array, sizeof(*a->array)*3);
    }
    a->array[a->count++] = element;


}

void removeAt(DynamicArray *a, int index)
{
    a->array[index] = a->array[a->count-1];
    a->count -=1;
    /*
    void* temp = &a;
    a[index] = a[a->count+1];
    a->array[a->count+1] = temp;
    a->array[a->count+1] = NULL;
    a->count--;
     */
}

void clear(DynamicArray *a)
{
    /*
    free(a->array);
    a->array = NULL;
    a->count = 0;
     */
}

void init(DynamicArray *a)
{
    //a->array = malloc(sizeof(*a->array)*a->capacity);
    //a->array = malloc(sizeof(void*) * a->capacity);//do we need *sizeof(type)
    a->count = 0;
    a->capacity = 4;
    a->array = malloc(sizeof(*a->array)*a->capacity);
    a->isEmpty = isEmpty;
    a->pushBack = pushBack;
    a->removeAt = removeAt;
    a->clear = clear;
}
