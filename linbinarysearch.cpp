    #include <iostream>
    
    using namespace std;
    
    void linsearch(int arr[], int n, int val) {
        int check = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == val) {
              cout <<"Element found at : "<< i<<"\n";
              check = 1;
            }
        }
        if (check == 0){
            cout<<"Element not found";
        }
    }
    
    int binsearch(int arr[], int start, int end, int val) {
      if (start > end) {
        return -1;
      }
      int mid = (start + end) / 2;
      if (arr[mid] == val) {
        return mid; // found
      } else if (arr[mid] < val) {
        return binsearch(arr, mid + 1, end, val);
      } else {
        return binsearch(arr, start, mid - 1, val);
      }
    }
        
    int main() {
        int a[] = {0, 12, 92};
        linsearch(a, 3, 12);
        int b[] = {1, 2, 3, 4, 5, 6, 7, 102};
        int ans = binsearch(b, 0, 8, 7);
        if (ans != -1){
            cout << "Element found at : " << ans;
        }
        else{
            cout<<"Element not found.";
        }
        return 0;
    }
