//
// Created by anita on 2022/9/29.
//

#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void push(StackNodePtr *topPtr, BizarreNumber_t info)
{
    StackNodePtr newPtr = malloc(sizeof(StackNode));
    if(newPtr != NULL)//if(isEmpty(*newPtr)
    {
        newPtr -> data = info;
        newPtr -> nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
    {
        printf("%d not inserted. No memory avaliable.\n", info);
    }
}
/*
BizarreNumber_t pop(StackNodePtr *topPtr)
{
    if(top==NULL)
    {
        printf("empty stack")
    }
    struct stackNode *temp = top;
    StackNodePtr *
    //return topPtr->StackNodePtr[topPtr->top--];

}
*/
BizarreNumber_t pop(StackNodePtr *topPtr)
{
    StackNodePtr tempPtr = *topPtr;
    BizarreNumber_t popValue = (*topPtr) -> data;
    *topPtr = (*topPtr) -> nextPtr;
    free(tempPtr);
    return popValue;
}

int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr)
{
    if(currentPtr == NULL)
    {
        puts("the stack is empty. \n");
    }
    else
    {
        puts("The stack is:");
        printf("TOP --> ");
        while(currentPtr!=NULL)
        {
            if(currentPtr -> data.num ==-1)
            {
                printf("%s --> ", "NULL");
            }
            else
            {
                printf("%d --> ", currentPtr -> data.num); //test if this works
            }
            //printf("%d --> ", currentPtr -> data.num); //test if this works
            currentPtr = currentPtr -> nextPtr;
        }
        puts("BOTTOM\n");
    }
}

StackNodePtr reverseStack(StackNodePtr currentPtr)
{
    StackNodePtr newPtr = NULL;
    if(isEmpty(currentPtr)==1)
    {
        newPtr = NULL;
        return newPtr;
    }
    else
    {
        while(currentPtr!=NULL)
        {
            push(&newPtr, currentPtr->data);
            currentPtr = currentPtr -> nextPtr;
        }
    }
    return newPtr;
}


void printStackDetailed(StackNodePtr currentPtr)
{
    if(currentPtr == NULL)
    {
        puts("the stack is empty. \n");
    }
    else
    {
        puts("Recovered stack is:");
        printf("  **TOP** \n");
        while(currentPtr!=NULL)
        {
            printf("%2d,", currentPtr -> data.num);
            printf("%2d, ", currentPtr -> data.nrOfOpr);
            printf("%s \n", currentPtr -> data.type);
            currentPtr = currentPtr -> nextPtr;
        }
        printf("**BOTTOM** \n");
    }
}

StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack)
{
    StackNodePtr mainPtr = reverseStack(mainStack);
    StackNodePtr helperPtr = reverseStack(helperStack);
    StackNodePtr newPtr = NULL;
    while(mainPtr!=NULL)
    {
        BizarreNumber_t bn;
        if (strcmp(mainPtr->data.type, "SQ") == 0) {
            int n = mainPtr->data.num;
            bn.nrOfOpr = mainPtr->data.nrOfOpr;
            for (int i = 0; i < bn.nrOfOpr; i++) {
                n = n * n;
            }
            bn.num = n;
            strcpy(bn.type, mainPtr->data.type);
            push(&newPtr, bn);
            mainPtr = mainPtr->nextPtr;
            helperPtr = helperPtr->nextPtr;
        }
        else if (strcmp(mainPtr->data.type, "PR") == 0) {
            bn.num = sqrt(mainPtr->data.num);
            bn.nrOfOpr = mainPtr->data.nrOfOpr;
            strcpy(bn.type, mainPtr->data.type);

            push(&newPtr, bn);
            mainPtr = mainPtr->nextPtr;
            helperPtr = helperPtr->nextPtr;
        }
        else if (strcmp(helperPtr->data.type, "DF") == 0) {
            bn.num = helperPtr->data.num;
            bn.nrOfOpr = helperPtr->data.nrOfOpr;
            strcpy(bn.type, helperPtr->data.type);
            push(&newPtr, bn);
            mainPtr = mainPtr->nextPtr;
            helperPtr = helperPtr->nextPtr;
        }
        else if (strcmp(mainPtr->data.type, "AB") == 0) {
            bn.num = mainPtr->data.num + helperPtr->data.num;
            bn.nrOfOpr = mainPtr->data.nrOfOpr;
            strcpy(bn.type, mainPtr->data.type);
            push(&newPtr, bn);
            mainPtr = mainPtr->nextPtr;
            helperPtr = helperPtr->nextPtr;
        }
        else //if(strcmp(mainPtr->data.type, "PF")==0)
        {
            bn.num = mainPtr->data.num;
            bn.nrOfOpr = mainPtr->data.nrOfOpr;
            strcpy(bn.type, mainPtr->data.type);

            push(&newPtr, bn);
            mainPtr = mainPtr->nextPtr;
            helperPtr = helperPtr->nextPtr;
        }
    }
    return newPtr;
}

//math
int isPrime(int num)
{
    int p = 1;
    if(num==2)
    {
        p = 1;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            p = 0;
            //printf("The number is not prime!");
            break;
        }
    }
    return p;
}

int isAbundantNumber(int num)
{
    int f = 0;
    for(int i=1; i<=num/2; i++)
    {
        if(num%i==0)
        {
            f+=i;
        }
    }
    //printf("The abundance is:");
    //printf(f-num);
    return f-num;
}

int isPerfectSquare(int num)
{
    int i;
    double d = sqrt((double) num);
    i=d;
    if(d==i)
    {
        //printf("perfect square!");
        return 1;
    }
    return 0;
}

