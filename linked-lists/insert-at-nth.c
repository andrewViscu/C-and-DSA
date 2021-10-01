#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* link;
};
struct Node* head;

void Insert(int data, int position){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->link = NULL;
    if(position == 1) {
        newNode->link = head;
        head = newNode;
        return; 
    }
    struct Node* previousNode = head;
    //since we're starting from head (0), the previous node will not be just -1
    //it will be -1 from 1 or -2 from 0
    //we can write for(int i = 1; i<position-1;i++)
    for(int i = 0; i<position-2;i++) {
        previousNode = previousNode->link;
    }
    newNode->link = previousNode->link;
    previousNode->link = newNode;
    
}
void Print() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

int main(int argc, char const *argv[])
{
    head = NULL;
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Print();
    return 0;
}
