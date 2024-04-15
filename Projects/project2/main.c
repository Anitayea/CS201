#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "dynamicarray.h"

int isEmpty(DynamicArray *a);
void pushBack(DynamicArray *a, void* element);
void removeAt(DynamicArray *a, int index);
void clear(DynamicArray *a);
void init(DynamicArray *a);

int main (int argc, char** args)
{
    DynamicArray da;
    init(&da);
    printf("Initialization - count: %d, capacity: %d\n", da.count, da.capacity);

    da.pushBack(&da, "Gizem");
    da.pushBack(&da, "NYU");
    da.pushBack(&da, "CSCI");
    da.pushBack(&da, "201");
    da.pushBack(&da, "Fall");
    da.pushBack(&da, "2022");
    da.pushBack(&da, "Project201");
    printf("Step 2 - count: %d, capacity: %d\n", da.count, da.capacity);
    for (int i = 0; i < da.count; i ++)
    {
        printf("%s\n", (char*)da.array[i]);
    }

    da.removeAt(&da, 2);
    printf("Step 3 - count: %d, capacity: %d\n", da.count, da.capacity);
    printf("\nDynamic Array data:\n\n");
    for (int i = 0; i < da.count; i ++)
    {
        printf("%s\n", (char*)da.array[i]);
    }
    da.clear(&da);
    if(da.isEmpty)
        printf("The array is empty now\n");
    return 0;
}

