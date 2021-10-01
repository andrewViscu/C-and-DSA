#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* link;
};

//struct Node* head; 

//without "head" parameter if it's global,
//single pointer if we return and write it to a var.
//double pointer to change the original value. 
void Insert(struct Node** pointerToHead, int x) { 
    
    //if we dont change the original value, we can leave it as "head"
    // since it a copy of original and not the orig.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; 
    temp->link = NULL;
    if(*pointerToHead != NULL) temp->link = *pointerToHead;
    *pointerToHead = temp;
    //return head;  //one of the methods, if head is a copy.
    //we should then also change the function return type to
    //struct Node*

}

void Print(struct Node* head) {
    while(head != NULL) {
        printf(" %d", head->data);
        head = head->link;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    //values we want: 2, 4, 6.
     struct Node* head;
     // empty list
    head = NULL;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(&head, x);
        //we can do head = Insert(head, x)
        Print(head);
    }
    
    
    // temp->data = 2; //same as (*temp).data = 2;
    // temp->link = NULL;
    // A = temp;
    // temp = (struct Node*)malloc(sizeof(struct Node));
    // temp->data = 4;
    // temp->link = NULL;
    
    // //traverse the linked list
    // struct Node* temp1 = A; // A is never modified, to not lose the address of the head node.
    // while(temp1->link != NULL) {
    //     temp1 = temp1->link;
    //     printf("%d", temp->data);
    // }
    // temp1->link = temp;
    //insert a node in the link list
    return 0;
}
