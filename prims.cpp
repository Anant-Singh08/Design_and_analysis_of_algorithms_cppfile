#include <cstring>
#include <iostream>
using namespace std;

#define INF 100000
#define V 5


void prims(int G[V][V]){
    int no_edge;  
  int selected[V];
  memset(selected, false, sizeof(selected));
  no_edge = 0;

  selected[0] = true;

  int x;  
  int y;  
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edge < V - 1) {

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }
}
int main() {
    int G[V][V] = {
    {0, 10, 175, 0, 90},
    {9, 0, 5, 108, 41},
    {55, 78, 0, 51, 18},
    {0, 20, 56, 0, 91},
    {0, 4, 82, 91, 10}
    
    };
  prims(G);

  return 0;
}
