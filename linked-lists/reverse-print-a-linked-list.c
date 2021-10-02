#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

//Recursion method.
void Print(struct Node* node)
{
    if(node == NULL){printf("\n"); return;}
    printf("%d ", node->data);
    Print(node->link);
}

void ReversePrint(struct Node* node)
{
   if(node == NULL) return;
   ReversePrint(node->link);
   printf("%d ", node->data);
}

//Code that was before in other files
struct Node* Insert(struct Node* head, int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;
    if(head == NULL) head = temp;
    else {
        struct Node* temp1 = head;
        while(temp1->link != NULL) temp1 = temp1->link;
        temp1->link = temp;
    }
    return head;
}





int main(int argc, char const *argv[])
{
    struct Node* head = NULL; //empty list
    head = Insert(head, 2);
    Insert(head, 4);
    Insert(head, 6);
    Insert(head, 5); // List: 2, 4, 6, 5.
    Print(head);

    ReversePrint(head); // List: 5, 6, 4, 2.
    // Print();
    return 0;
}
