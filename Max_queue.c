/* Develop a C program to perform the following operations using Max Priority Queue using Linked list
1.Enqueue 
2. Dequeue
3. Display the elements from priority queue
Note: The values/ elements should be Integer values
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};
struct node *front = NULL,*rear = NULL,*temp,*n;

void enqueue();
void dequeue();
void display();

int main(){
    int ch;
    printf("1.enqueue 2.dequeue 3.display 0.exit\n");
    do{
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : enqueue(); break;
            case 2 : dequeue(); break;
            case 3 : display(); break;
        }
    }while(ch!=0);

    return 0;
}

void enqueue(){
    n = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&n->data);
    printf("Enter the priority : ");
    scanf("%d",&n->priority);
    n->next = NULL;
    if( front == NULL || n->priority > front->priority ){
        n->next = front;
        front = n;
    }else{
        temp = front;
        while(temp->next != NULL && temp->next->priority > n->priority){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
    }else{
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
    }else{
        temp = front;
        while(temp != NULL){
            printf("Data : %d\tPriority : %d\n",temp->data,temp->priority);
            temp = temp->next;
        }
    }
}
