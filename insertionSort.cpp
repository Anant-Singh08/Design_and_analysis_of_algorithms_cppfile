#include <iostream>
using namespace std;

void insertsort(int a[], int len) {
    for (int i = 1; i < len; i++) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
     for(int ind = 0; ind<len; ind ++){
        cout<< a[ind]<<" ";
    }
}



int main() {
    int a[] = {12,7,10,345,456, 45, 76, 909,1,1024};
    int length = sizeof(a)/sizeof(a[0]);
    cout<< "\n";
    insertsort(a, length);
    return 0;
}
