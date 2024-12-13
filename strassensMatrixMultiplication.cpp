# include <iostream>
using namespace std;
void mul(int m1[2][2],int m2[2][2]){
    int ans[2][2];
    int p=(m1[0][0]+m1[1][1])*(m2[0][0]+m2[1][1]);
    int q=(m1[1][0]+m1[1][1])*m2[0][0];
    int r=m1[0][0]*(m2[0][1]-m2[1][1]);
    int s=m1[1][1]*(m2[1][0]-m2[0][0]);
    int t=(m1[0][0]+m1[0][1])*m2[1][1];
    int u=(m1[1][0]-m1[0][0])*(m2[0][0]+m2[0][1]);
    int v=(m1[0][1]-m1[1][1])*(m2[1][0]+m2[1][1]);
    ans[0][0] = p+s-t+v;
    ans[0][1] = r+t;
    ans[1][0] = q+s;
    ans[1][1] = p+r-q+u;
    for (int i = 0;i<2;i++){
        for (int j = 0; j<2;j++){
            cout << ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int a[2][2];
    int b[2][2];
    cout << "Matrix:1"<<endl;
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << "a["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
    }
    cout << "Matrix:2"<<endl;
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << "b["<<i<<"]["<<j<<"]: ";
            cin>>b[i][j];
        }
    }
    mul(a,b);
    return 0;
}
