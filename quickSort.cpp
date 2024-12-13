#include <iostream>
using namespace std;

int part(int a[],int s,int e){
     int i=s;
     int pivot = a[e];
     for(int j=s;j<=e-1;j++){
        if(a[j] < pivot){
            swap(a[i],a[j]);
            i++;
        }
     }
     swap(a[i],a[e]);
     return i;
}

void quicksort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int p = part(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}


int main() {
    int a[] = {12,7,10,345,456, 45, 76, 909,1,1024, 3, 76, -12, -10};
    int length = sizeof(a)/sizeof(a[0]);
    int start = 0;
    int end = 13;
    cout<< "\n";
    quicksort(a, start, end);
    for(int ind = 0; ind < length; ind ++){
        cout<< a[ind]<<" ";
    }
    return 0;
}
