//
// Created by anita on 2022/10/11.
//

#ifndef PROJECT2_DYNAMICARRAY_H
#define PROJECT2_DYNAMICARRAY_H

#endif //PROJECT2_DYNAMICARRAY_H


typedef struct{
    //size_t *array;
    void **array;
    size_t capacity;
    size_t count;
    int (*isEmpty)(struct DynamicArray*, void*);
    void (*pushBack)(struct DynamicArray*, void*);
    void (*removeAt)(struct DynamicArray*, void*);
    void (*clear)(struct DynamicArray*);
    //void (*init)(struct DynamicArray*, void*);
}DynamicArray;

int isEmpty(DynamicArray *a);
void pushBack(DynamicArray *a, void* element);
void removeAt(DynamicArray *a, int index);
void clear(DynamicArray *a);
void init(DynamicArray *a);
