#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL; // null pointer

void insertNodeInbeg(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    newNode->next = head;
    head = newNode;
    printf("Node Inserted !!!\n");
}

void insertNodeAtEnd(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node Inserted !!!\n");
}

void insertNodeAtanyPos(int ele, int pos)
{
    if (head == NULL && pos != 1)
    {
        printf("List is empty !!!\n");
    }
    else if (pos == 1)
    {
        insertNodeInbeg(ele);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = ele;
        newNode->next = NULL;
        Node *temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next != NULL && i > 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node Inserted !!!\n");
        }
        else
        {
            printf("Invalid Position!!!\n");
        }
    }
}

void deleteNodefromBeg()
{
    if (head == NULL)
    {
        printf("List is Empty!!!\n");
    }
    else
    {
        Node *t = head;
        head = head->next;
        free(t);
        printf("Node Deleted !!!\n");
    }
}

void deleteNodefromEnd()
{
    if (head == NULL)
        printf("List is empty !!!\n");
    else
    {
        Node *t;
        if (head->next == NULL)
        { // list contains single node
            t = head;
            head = NULL;
        }
        else
        { // list contain more than one node
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            t = temp->next;
            temp->next = NULL;
        }
        free(t);

        printf("Node Deleted !!!\n");
    }
}
void deleteNodeFromAnyPos(int pos)
{
    if (head == NULL)
        printf("List is empty !!!\n");
    else if (pos == 1)
    {
        deleteNodefromBeg();
    }
    else
    {
        int i = 1;
        Node *temp = head;
        while (i < pos - 1 && temp->next != NULL)
        {
            i++;
            temp = temp->next;
        }
        if (temp->next != NULL && pos > 0)
        {
            Node *t = temp->next;
            temp->next = temp->next->next;
            free(t);
            printf("Node Deleted !!1\n");
        }
        else
            printf("Invalid Position");
    }
}
void search(int target)
{
    if (head == NULL)
        printf("List is empty !!!\n");
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
            {
                printf("Found !!!\n");
                return;
            }
            temp = temp->next;
        }
        printf("Not Found!!!!\n");
    }
}

void sort(){
    Node* last = NULL;
    Node* j=head;
    for(Node* i = head ; i->next != NULL ; i=i->next){
        for(j=head ; j->next!= last ; j=j->next ){
            if(j->data > j->next->data){
                int temp=j->data;
                j->data=j->next->data;
                j->next->data=temp;
            }
        }
        last=j;
    }
    printf("List element sorted Successfully!!!\n");
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty !!!\n");
    }
    else
    {
        printf("Elements are : \n");
        Node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n\n");
}

int main()
{
    while (1)
    {
        printf("----- Singly Linked List -----\n");
        printf("1. Insert Node at beginning\n2. Insert Node at end\n3. Insert Node at any position\n4. Delete Node from beginning\n5. Delete Node from end\n6. Delete Node from any position\n7. Search elements\n8. Sort elements\n9. Display List\n10. Exit\n\n");
        int choice, ele, pos,target;
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element : ");
            scanf("%d", &ele);
            insertNodeInbeg(ele);
            break;
        case 2:
            printf("Enter the element : ");
            scanf("%d", &ele);
            insertNodeAtEnd(ele);
            break;
        case 3:
            printf("Enter the element : ");
            scanf("%d", &ele);
            printf("Enter the poitioin : ");
            scanf("%d", &pos);
            insertNodeAtanyPos(ele, pos);
            break;
        case 4:
            deleteNodefromBeg();
            break;
        case 5:
            deleteNodefromEnd();
            break;
        case 6:
            printf("Enter position : ");
            scanf("%d", &pos);
            deleteNodeFromAnyPos(pos);
            break;
        case 7:
            printf("Enter element : ");
            scanf("%d", &target
            );
            search(target);
            break;
        case 8:
            sort();
            break;
        case 9:
            display();
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid Choice !!!\n");
        }
    }
}
