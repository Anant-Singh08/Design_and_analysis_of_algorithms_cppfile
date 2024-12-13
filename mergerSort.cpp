#include <iostream>
using namespace std;

void merge(int *a,int s,int e){
    int mid = (s+e)/2;
    
    int i = s;
    int j = mid+1;
    int k = s;
    
    int temp[100];
    
    while(i<=mid && j<=e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++]  = a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }
    
    
}

void mergesort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    merge(a,s,e);


}

int main() {
    int a[] = {12,7,10,345,456, 45, 76, 909,1,1024, 3, 76};
    int length = sizeof(a)/sizeof(a[0]);
    int start = 0;
    int end = 11;
    cout<< "\n";
    mergesort(a, start, end);
    for(int ind = 0; ind < length; ind ++){
        cout<< a[ind]<<" ";
    }
    return 0;
}
