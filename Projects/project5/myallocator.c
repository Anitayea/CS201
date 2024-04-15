#include<stdio.h>
#include<stddef.h>


char mymemory[8000];

struct block{
    size_t size;
    int free;
    struct block *next;
};

typedef struct block block;

block *list=(void*)mymemory;


void initmemory()
{
    //TO DO
    //Initialize the list size, free and next
    list->size = 8000-sizeof(block);
    list->free = 1;
    list->next = NULL;
}

void split( block *slotToBeSplitted,size_t size)
{
    //TO DO
    //Split the slot to be splitted and create a new slot
    //block *newblk = (void*)((void*)slotToBeSplitted + size + sizeof(block));
    block *newblk = ((void*)slotToBeSplitted + size + sizeof(block));
    newblk->size = (slotToBeSplitted->size) - size - sizeof(block);
    newblk->free = 1;
    newblk->next = slotToBeSplitted->next;
    slotToBeSplitted->size = size;
    slotToBeSplitted->free = 0;
    slotToBeSplitted->next = newblk;

}


void *NewMalloc(size_t allocsSize)
{
    block *curr;
    void *result;
    curr=list;

    //TO DO
    //Find a chunk with enough free space


    while((((curr->size)<allocsSize)||(curr->free)==0)&&(curr->next!=NULL))
    {
        curr = curr->next;
    }

    printf("curr size is: %d\n\n", curr->size);

    //TO DO
    //Check cases and allocate with/without splitting
    if(curr->size == allocsSize)//+sizeof(block)?
    {
        curr->free=0;
        result = (void*)(++curr);
        //result = curr;
        return result;
    }
    else if(curr->size > allocsSize+sizeof(block))
    {
        split(curr, allocsSize);
        result = (void*)(++curr);
        //result = curr;
        //printf("%p\n", (void *) &curr);
        printf("Allocate block with splitting for %zu", allocsSize);
        printf(" bytes \n");
        //printf("%p\n", (void *) &curr);
        return result;
    }
    else
    {
        result = NULL;
        printf("No sufficient memory\n");
        return result;
    }

}

void coalesce(){
    struct block *curr;
    curr=list;
    //TO DO
    //Coalesce consequtive free blocks
    while((curr->next)!=NULL)
    {
        if((curr->free)&&(curr->next->free))
        {
            curr->size+=(curr->next->size)+sizeof(block);
            curr->next = curr->next->next;
        }
        else
        {
            curr=curr->next;
        }
    }
}

void NewFree(void* ptr){
    //TO DO
    //Check if the pointer is in a valid range
    //If yes, free the block and call coalesce
    if(((void*)mymemory<=ptr)&&(ptr<=(void*)(mymemory+8000)))
    {
        block* curr = ptr;
        --curr;
        curr->free=1;
        coalesce();
    }
    else
    {
        printf("Error\n");
    }

}

int main(){

    if(!(list->size))
    {
        initmemory();
        printf("\n\n--Memory Initialization Completed--\n");
        printf("Initial size is: %d\n\n", list->size);
    }

    int *p=(int*)NewMalloc(800);
    printf("\n");

    char *q=(char*)NewMalloc(250*sizeof(char));
    printf("\n");

    int *r=(int*)NewMalloc(1000*sizeof(int));
    printf("\n");

    NewFree(p);
    printf("\n");

    char *w=(char*)NewMalloc(1000);
    printf("\n");

    NewFree(r);
    printf("\n");

    int *k=(int*)NewMalloc(1500*sizeof(int));
    printf("\n");

}
