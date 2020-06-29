#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int maxN = 1001;
const int cX[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int cY[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, k;
bool q[maxN][maxN];
bool virus[maxN][maxN];
int result[maxN];
vector<pii> v1, v2;

void danhDau(int u, int v, int x, int y) {
  for (int i = u; i <= x; i++)
    for (int j = v; j <= y; j++)
      q[i][j] = true;
}

void solve(int u, int v) {
  v1.push_back(pii(u, v));
  int t = 0;
  while (!v1.empty()) {
    t++; result[t] = result[t-1];
// cout << '*';
    while (!v1.empty()) {
      int u = v1.front().first, v = v1.front().second; v1.erase(v1.begin());
      if (u < 1 || u > n || v < 1 || v > m) continue;
// cout << u << ' ' << v << endl;
      virus[u][v] = true;
      if (q[u][v]) result[t]++;

      for (int i = 0; i < 8; i++)
        v2.push_back(pii(u + cX[i], v + cY[i]));
    }
    swap(v1, v2);
  }
}

void test() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << q[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  freopen("input", "r", stdin);

  cin >> n >> m >> k;
  int u, v; cin >> u >> v;

  for (int i = 1; i <= k; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    danhDau(a, b, c, d);
  }

  solve(u, v);
  // cout << result[2];

  return 0;
}