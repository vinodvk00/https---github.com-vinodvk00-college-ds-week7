#include<stdio.h>
#include<stdlib.h>

struct node{
    int priority;
    int data;
    struct node *next;
};

struct node *front = NULL,*rear = NULL,*n,*temp;

void enqueue();
void dequeue();
void display();

int main(){
    int ch;
    printf("1.enqueue 2.dequeue 3.display\n");
    do{
        printf("enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1 : enqueue(); break;
        case 2 : dequeue(); break;
        case 3 : display(); break;
        }
    }while(ch!=0);

    return 0;
}

void enqueue() {
    n = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &(n->data));
    printf("Enter priority: ");
    scanf("%d", &(n->priority));
    n->next = NULL;

    if (front == NULL || n->priority > front->priority) {
        n->next = front;
        front = n;
    } else {
        temp = front;
        while (temp->next != NULL && temp->next->priority >= n->priority) {
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;
    }
}


void dequeue(){
    if(front == NULL){
        printf("Queue is empty \n");
    }else{
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display(){
    temp = front;
    if(front == NULL){
        printf("Queue is empty \n");
    }else{
        printf("Queue is :\n");
        printf("Priority       Item\n");
        while (temp != NULL)
        {
            printf("%5d        %5d\n", temp->priority, temp->data);
            temp = temp->next;
        }
    }
}