//heapsort

#include<stdio.h>

void heapsort(int a[],int n);
void heapify(int a[],int n,int i);

int main(){
    int a[100],i,n;

    printf("Enter size : ");
    scanf("%d",&n);
    printf("Enter %d elements : ",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    heapsort(a,n);
    printf("Sorted Array : ");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);

    return  0;
    
}

void heapsort(int a[],int n){
    int i;
    for( i = (n/2)-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(i = (n-1);i>=0;i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a,i,0);
    }
}

void heapify(int a[],int n,int i){
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left < n && a[left] > a[largest]){
        largest = left;
    }else if(right < n && a[right] > a[largest]){
        largest = right;
    }

    if(largest!=i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a,n,largest);
    }
}
