#include <iostream>
using namespace std;

void selsort(int a[], int len) {
    int i, j, min;
    for (i=0; i<len-1; i++){
        min=i;
        for (j=i+1; j<len; j++)
            if (a[j]<a[min])
                min=j;
        swap(a[min], a[i]);
    }
    for(int ind = 0; ind<len; ind ++){
        cout<< a[ind]<<" ";
    }
