#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

//Reverse linked list using recursion.
struct Node* Reverse(struct Node* node)
{
    struct Node* head;
   if(node->link == NULL) { // there's no elements after this one
       head = node; //this element is head
       // 2->4->6->5->NULL
       //          ^
       return head; // Reverse is completed, exit to line 24
   }
   head = Reverse(node->link);
   //since we just returned, we're going backwards through the stack
   //so on our first exit node is this: 2->4->6->5->NULL
   //                                         ^
   struct Node* q = node->link; //copy the one from where we just exited
   //on first exit it's 5
   q->link = node; //one after it is, instead of going forward, goes backwards
   // on first exit, instead of going NULL it's going to 6
   node->link = NULL; //current node is pointing backwards as well, becoming null
   //now our list is 5->6->NULL
   //repeat
   return head;
}

//Code that was in other files
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
}

void Print(struct Node* head)
{
    struct Node* temp = head;
    printf("List is:");
    while(temp != NULL)
    {
        printf(" %d",temp->data);
        temp= temp->link;
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    struct Node* head = NULL; //empty list
    head = Insert(head, 2);
    Insert(head, 4);
    Insert(head, 6);
    Insert(head, 5); // List: 2, 4, 6, 5.
    Print(head);

    head = Reverse(head); // List: 5, 6, 4, 2.
    Print(head);
    // Print();
    return 0;
}
