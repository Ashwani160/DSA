#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* create_node(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    temp->data=data;
    temp->prev=temp;
    temp->next=temp;
    return temp;
}
struct node* create_CLL(int n){
    struct node* head=create_node();
    struct node*temp=head;
    struct node* newnode;
    for(int i=1;i<n;i++){
        newnode=create_node();
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
    head->prev=newnode;
    return head;
}
void traverse(struct node* head){
    struct node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}
struct node* insert(struct node* head, int index){
    struct node* temp=create_node();
    struct node* ptr=head;
    for(int i=1;i<index;i++){
        ptr=ptr->next;
    }
    if(ptr==head){
    temp->next=ptr;
    temp->prev=ptr->prev;
    ptr->prev->next=temp;
    ptr->prev=temp; 
    return temp;
    }
    temp->next=ptr;
    temp->prev=ptr->prev;
    ptr->prev->next=temp;
    ptr->prev=temp;
}
int main(){
    int n;
    printf("Enter the size of list: ");
    scanf("%d",&n);
    struct node* head=create_CLL(n);
    traverse(head);
    int index;
    printf("Enter the index: ");
    scanf("%d",&index);
    head=insert(head,index);
    traverse(head);
}