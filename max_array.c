//max queue using array

#include<stdio.h>
#define size 10

struct node{
    int data;
    int priority;
};

struct node *a[size];

int front = -1, rear = -1,temp,i;

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
    struct node n;
    printf("Enter data : ");
    scanf("%d",&n.data);
    printf("Enter priority : ");
    scanf("%d",&n.priority);

    if( rear == size-1 ){
        printf("Queue Overflow\n");
    }else if(front == -1 && rear ==-1 ){
        front = rear = 0;
        pq[rear] = n;
    }else{
        int i;
        for( i = rear; i>= front; i--){
            if(n.priority > pq[i].priority){
                pq[i+1] = pq[i];
            }else[
                break;
            ]
        }
        
        pq[i+1] = n;
        rear++;
    }
}

void dequeue(){
    if(front==-1 || front > rear){
        printf("Queue Underflow\n");
    }else{
        front++;
    }
}

void display(){
    if(front == - 1 && rear == -1){
        printf("Queue is empty\n");
    }else{
        temp = front;
        for(i=0;i<size-1;i++){
            printf("DATA\t PRIORITY\t");
            printf("%d\t %d\t");
        }
    }
}