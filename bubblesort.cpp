#include <iostream>
using namespace std;

int bubsort(int arr[], int len){
    int i, ind, j;
    for (int i = 0; i< len; i++)
    {
        for(int j = len; j >= i+1; j--)
        {
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    for(int ind = 0; ind<len; ind ++){
        cout<< arr[ind]<<" ";
    }
    return 0;
}


int main() {
    int a[] = {12,43,23,345,567, 45, 76, 32};
    int length = sizeof(a)/sizeof(a[0]);
    cout<< "\n";
    bubsort(a, length);
    return 0;
}
