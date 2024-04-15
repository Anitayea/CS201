//
// Created by anita on 2022/9/29.
//

#ifndef PROJECT1_HELPER_H
#define PROJECT1_HELPER_H

typedef struct {
    char type[3];
    int nrOfOpr;
    int num;
} BizarreNumber_t;

struct stackNode {
    BizarreNumber_t data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;


#endif //PROJECT1_HELPER_H
