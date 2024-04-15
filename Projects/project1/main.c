#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "helper.h"

void push(StackNodePtr *topPtr, BizarreNumber_t info);
BizarreNumber_t pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void printStackDetailed(StackNodePtr currentPtr);
StackNodePtr reverseStack(StackNodePtr currentPtr);
void insertAtBottom(StackNodePtr p, BizarreNumber_t bn);

int isAbundantNumber(int num); //returns abundance (if 0 perfect, if > 0 abundant,if < 0 deficient)
int isPrime(int num);
int isPerfectSquare(int num);

StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack);

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

//stackNode* top = NULL;

int main()
{
    //struct stack *topPtr = newStack();
    StackNodePtr stackPtr = NULL;
    StackNodePtr helperPtr = NULL;
    int value;
    printf("Enter an integer number to push:\n");
    scanf("%d", &value);
    BizarreNumber_t bn;
    BizarreNumber_t bn2;

    do
    {
        /*
        bn.num = -1;
        bn2.num = -1;
        int flop = 0;
        bn.nrOfOpr= 0;
        bn2.nrOfOpr= 0;
        strcpy(bn.type,"");
        strcpy(bn2.type,"");*/

        //perfect square
        if(isPerfectSquare(value)==1)
        {
            //nrOfOpr
            int k = 0;
            strcpy(bn.type, "SQ");

            if( value==1 || value ==0 )
            {
                k=1;
                break;
            }
            do
            {
                int temp = sqrt(value);
                k++;
                value = temp;
                bn.num = temp;
                bn.nrOfOpr = k;
                //printf("%d", value);
            } while(isPerfectSquare(value)==1);
            bn2.num = -1;
            bn2.nrOfOpr= 0;
            strcpy(bn2.type,"");
            push(&stackPtr, bn);
            push(&helperPtr, bn2);

            bn.num = -1;
            bn.nrOfOpr= 0;
            strcpy(bn.type,"");

        }
        //prime
        else if(isPrime(value)==1)
        {
            //printf("%d", value);
            int temp = value*value;
            bn.num = temp;
            bn.nrOfOpr = 0;
            strcpy(bn.type, "PR");
            bn2.num= -1;
            bn2.nrOfOpr =0;
            strcpy(bn2.type, "");
            push(&stackPtr, bn);
            push(&helperPtr, bn2);
        }
        //perfect
        else if(isAbundantNumber(value)==0)
        {
            strcpy(bn.type, "PF");
            strcpy(bn2.type, "");
            int temp = value;
            bn.num = temp;
            push(&stackPtr, bn);
            bn2.num = -1;
            bn.nrOfOpr = 0;
            bn2.nrOfOpr = 0;
            push(&helperPtr, bn2);
        }
        //abundance
        else if(isAbundantNumber(value)>0)
        {
            strcpy(bn.type, "AB");
            int temp = value-isAbundantNumber(value);
            bn.num = temp;
            bn.nrOfOpr = 0;
            push(&stackPtr, bn);
            //helper stack
            strcpy(bn2.type, "AB");
            int temp2 = isAbundantNumber(value);
            bn2.num = temp2;
            bn2.nrOfOpr = 0;
            push(&helperPtr, bn2);
        }
        //deficient
        else//(isAbundantNumber(value)<0)
        {
            strcpy(bn.type, "");
            strcpy(bn2.type, "DF");
            //int temp = isAbundantNumber(value);
            //bn.num = temp;
            bn.num = -1;
            bn.nrOfOpr = 0;
            push(&stackPtr, bn);
            bn2.num = value;
            bn2.nrOfOpr=0;
            push(&helperPtr, bn2);
        }

        //push(&stackPtr, value);
        //printStack(stackPtr);
        //printStack(helperPtr);
        //StackNodePtr reStack = recoverCipher(stackPtr, helperPtr);
        //printStackDetailed(reStack);
        //printStack(reStack);

        //printStackDetailed(recoverCipher(stackPtr, helperPtr));
        printf("Enter an integer number to push:\n");

        scanf("%d", &value);

        bn.num = -1;
        bn2.num = -1;
        int flop = 0;
        bn.nrOfOpr= 0;
        bn2.nrOfOpr= 0;
        strcpy(bn.type,"");
        strcpy(bn2.type,"");

        //printStackDetailed(stackPtr);
        //printStackDetailed(helperPtr);
        //printStackDetailed(recoverCipher(stackPtr, helperPtr));
    }
    while(value != EOF);
    printStack(stackPtr);
    printStack(helperPtr);
    StackNodePtr reStack = recoverCipher(stackPtr, helperPtr);
    printStackDetailed(reStack);
    //printStackDetailed(recoverCipher(stackPtr, helperPtr));
    return 0;
}

