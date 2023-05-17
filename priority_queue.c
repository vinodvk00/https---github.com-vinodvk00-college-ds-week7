// priority queue
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *n, *temp, *p;

void enqueue();
void dequeue();
void display();

int main(){
    int ch;
    printf("1.enqueue priority 2.dequeue 3. display \n");

    do{
        printf("choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    }while(ch!=0);

    return 0;
}

void enqueue(){
    n = (struct node*)malloc(sizeof(struct node));

    printf("Enter Data : ");
    scanf("%d",&n->data);
    n->next = NULL;
    if(front == NULL){
        front = n;
        rear = n;
    }else if(front == rear){
        if(front->data < n->data){
            rear->next = n;
            rear = n;
        }else{
            n->next = front;
            front = n;
        }
    }else{
        temp = front;
        while(temp!=NULL){
            if(n->data <= front->data){
                n->next = front;
                front = n;
                break;
            }else if(n->data >= rear->data){
                rear->next = n;
                rear = n;
                break;
            }else if(n->data < temp->data){
                p->next = n;
                n->next = temp;
                break;
            }
            p = temp;
            temp = temp->next;
        }
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
    }else{
        temp = front;
        front = front->next;
        printf("%d deleted\n",temp->data);
        free(temp);
    }
}

void display(){
    temp = front;
    if(front == NULL){
        printf("Empty\n");
    }else{
        while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
        }
    }

}
