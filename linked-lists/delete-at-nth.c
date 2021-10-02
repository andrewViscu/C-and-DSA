#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* link;   
};
struct Node* head;

void Insert(int data);
void Print();

//Delete node at nth position 
void Delete(int position){
    struct Node* previousNode = head;
    if(position == 1) {
        head = previousNode->link; //head now points to second node
        free(previousNode);
        return;
    } 
    for(int i = 0; i < position - 2; i++) //if, for example, the value of position is 3,
                                          //it runs one time, from first it goes to second. 
        previousNode = previousNode->link; //now it points to prev node
    struct Node* currentNode = previousNode->link; //points to curr node
    previousNode->link = currentNode->link; //we skip the current node and go to it's link, which is next node
    free(currentNode);
}

//Code that was before in other files
void Insert(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = head;
    head = temp;
}

void Print()
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
    head = NULL; //empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List: 2, 4, 6, 5.
    Print();
    int n;
    printf("Enter a position \n");
    scanf("%d", &n);
    Delete(n);
    Print();
    return 0;
}
