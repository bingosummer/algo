#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Edge {
  pair<int, int> node1;
  pair<int, int> node2;
  int x;
  int y;
};

int inner_product(Edge e1, Edge e2)
{
  return e1.x * e2.x + e1.y * e2.y;
}

int is_same_node(Edge e1, Edge e2)
{
  return e1.node1 == e2.node1 || e1.node1 == e2.node2 || e1.node2 == e2.node1 || e1.node2 == e2.node2;
}

int main()
{
  int N;
  cin >> N;
  while (N--) {
    set<pair<int, int> > s;
    Edge edge[4];
    int x1, y1, x2, y2;
    for (int i = 0; i < 4; i++) {
      cin >> x1 >> y1 >> x2 >> y2;
      s.insert(make_pair(x1, y1));
      s.insert(make_pair(x2, y2));
      edge[i].node1 = make_pair(x1, y1);
      edge[i].node2 = make_pair(x2, y2);
      edge[i].x = x2 - x1;
      edge[i].y = y2 - y1;
    }
    if (s.size() != 4) { cout << "NO" << endl; continue;}
    int flag = 1;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        if (is_same_node(edge[i], edge[j])) {
	    if (inner_product(edge[i], edge[j]) !=0 ) { flag = 0;}
        }
      }
    }
    if (flag == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
  return 0;
}
