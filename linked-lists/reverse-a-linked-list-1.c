#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

//Easier version, Iterative method.
struct Node* Reverse(struct Node* head) {
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

//Code that was before in other files
struct Node* Insert(struct Node* head, int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;
    if(head == NULL) head = temp;
    else{
        struct Node* temp1 = head;
        while(temp1->link != NULL) temp1 = temp1->link;
        temp1->link = temp;
    }
    return head;
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
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5); // List: 2, 4, 6, 5.
    Print(head);

    head = Reverse(head); // List: 5, 6, 4, 2.
    Print(head);
    return 0;
}
