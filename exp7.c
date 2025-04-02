#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;}Node;
    Node* head = NULL;
    Node* CreateNode(int ele){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data=ele;
        newNode->next=NULL;
        return newNode;
    }
    void insertAtBeg(int ele){
        Node* newNode = CreateNode(ele);
        newNode->next=head;
        head=newNode;
        printf("Node added !!!\n");
    }
    void insertAtEnd(int ele){
        Node* newNode = CreateNode(ele);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            
        }

        printf("Node added !!!\n");

    }
    void insertAtpos(int ele,int pos){
        if(head==NULL){
            printf("List is empty\n");
        }
        else if(pos==1){
            insertAtBeg(ele);
        }
        else{
        Node* newNode = CreateNode(ele);
        Node *temp=head;
        int i =1;
        while(i<pos-1 && temp!=NULL){
            temp=temp->next;
            i++;
        }
        if(temp->next!=NULL && i>1){
            newNode->next=temp->next;
            temp->next=newNode;
            printf("Node added !!!\n");
            
        }else{
            printf("Position not found\n");
        }
       
        }
        
    }
    void deleteFrombeg(){
        if(head==NULL)
        printf("List is empty\n");
        else{
            Node *temp = head;
            head=head->next;
            printf("Node deleted !!!\n");
            free(temp);
        }
    }
    void deleteFromEnd(){
        if(head==NULL)
        printf("List is empty!!! \n");
        else{
            Node* t;
            if(head->next==NULL){   //if only one node is present
             t=head;
             head=NULL;
             
            }
            else{
            Node *temp = head;      //if more than one node is present
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            t =temp->next;
            temp->next=NULL;
            printf("Node deleted !!!\n");
        }
        free(t);
        }
    }

    void deleteAtanypos(int pos){
        if(head==NULL)
        printf("List is Empty !!!\n");
        else if (pos==1)
        deleteFrombeg();
        else{
            int i = 1;
            Node* temp=head;
            while(i<pos-1 && temp->next!=NULL){
                i++;
                temp = temp->next;
            }
            if(temp->next!=NULL && pos>0 ){
                Node* t = temp->next;
                temp->next=temp->next->next;
                free(t);
                printf("Node deleted!!!\n");
            }
            else
                printf("Invalid Position !!!\n");
        }
    }
    void search(int ele){
        for(int i = 0; i<ele;i++){
            if(head->data == ele){
                printf("Element found at position %d\n",i+1);
                return;
            }
        }
    }

    void display(){
        if (head==NULL){
            printf("List is empty\n");
            return;
        }
        else{
            printf("Elements in the list are: ");
        
        Node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }}

    }
    void sort(){
        Node *temp=head;
        
    }
    


int main(){
system("cls");
int value, pos;
    while(1){
        printf("---------Singly Linked List---------\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Searching in List\n8. Sort Elements\n9. Display\n10. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            printf("Enter value to insert: ");
            scanf("%d",&value);
            insertAtBeg(value);
            break;
            case 2:
            printf("Enter value to insert: ");
            scanf("%d",&value);
            insertAtEnd(value);
            break;
            case 3:
            printf("Enter value to insert: ");
            scanf("%d",&value);
            printf("Enter position to insert: ");
            scanf("%d",&pos);
            insertAtpos(value,pos);
            break;
            case 4:
            deleteFrombeg();
            break;
            case 5:
            deleteFromEnd();
            break;
            case 6:
            printf("Enter position to insert: ");
            scanf("%d",&pos);
            deleteAtanypos(pos);
            break;
            case 7:
            printf("Enter value to search: ");
            scanf("%d",&value);
            search(value);
            break;
            case 8:
            break;
            case 9:
            display();
            break;
            case 10:
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n");
    }
    return 0;
}