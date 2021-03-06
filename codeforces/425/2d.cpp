#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;

/**
 * Lowest Common Ancestor. Call lca(x, y) to get the lca of them.
 * Header Requirement: vector, cassert
 * Verified by: AtCoder ABC014-D (http://abc014.contest.atcoder.jp/submissions/759125)
 */
class LowestCommonAncestor {
private:
  int n, bn;
  std::vector<int> parent; // 0 is root, parent[0] = 0
  std::vector<int> dep;
  
  // Lowest Common Ancestor
  
  std::vector<std::vector<int> > lca_tbl;
  
  void dfs(const std::vector<std::vector<int> > &edges, int v, int par, int d) {
    parent[v] = par;
    dep[v] = d;
    
    for (int i = 0; i < edges[v].size(); ++i) {
      int u = edges[v][i];
      if (u != par) {
	dfs(edges, u, v, d + 1);
      }
    }
  }
  
  void lca_init(void) {
    for (int v = 0; v < n; ++v) {
      lca_tbl[v] = std::vector<int>(bn + 1, 0);
      lca_tbl[v][0] = parent[v];
    }
    for (int i = 1; i <= bn; ++i) {
      for (int v = 0; v < n; ++v) {
	lca_tbl[v][i] = lca_tbl[lca_tbl[v][i - 1]][i - 1];
      }
    }
  }
public:
  int lca(int x, int y) const {
    int dx = dep[x];
    int dy = dep[y];
    if (dx > dy) {
      return lca(y, x);
    }
    // Go up from y to the depth of x
    for (int l = bn; l >= 0; --l) {
      if (dy - dx >= 1 << l) {
	y = lca_tbl[y][l];
	dy -= 1 << l;
      }
    }

    assert (dx == dy);

    if (x == y) {
      return x;
    }
  
    for (int l = bn; l >= 0; --l) {
      if (lca_tbl[x][l] != lca_tbl[y][l]) {
	x = lca_tbl[x][l];
	y = lca_tbl[y][l];
      }
    }
    return lca_tbl[x][0];
  }
  int depth(int a) const {
    return dep[a];
  }
  LowestCommonAncestor(int n, const std::vector<std::vector<int> > &edges)
    : n(n), parent(n), dep(n), lca_tbl(n) {
    bn = 0;
    while (n > 1 << bn) {
      bn++;
    }
    dfs(edges, 0, 0, 0);
    lca_init();
  }
};


int calc(const LowestCommonAncestor &lca, int f, int s, int t) {
  bool s_up = lca.depth(lca.lca(f, s)) < lca.depth(f);
  bool t_up = lca.depth(lca.lca(f, t)) < lca.depth(f);
  if (s_up != t_up) {
    return 1;
  }
  if (not s_up) {
    int l = lca.lca(s, t);
    return lca.depth(l) - lca.depth(f) + 1;
  }
  int fs = lca.lca(f, s);
  int ft = lca.lca(f, t);
  if (fs != ft) {
    return lca.depth(f) - max(lca.depth(fs), lca.depth(ft)) + 1;
  }
  int lfs = lca.depth(fs);
  return lca.depth(f) - lfs + lca.depth(lca.lca(s, t)) - lfs + 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<VI> edges(n);
  REP(i, 1, n) {
    int p;
    cin >> p;
    p--;
    edges[p].push_back(i);
    edges[i].push_back(p);
  }
  LowestCommonAncestor lca(n, edges);
  REP(i, 0, q) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;
    int ma = 0;
    ma = max(ma, calc(lca, a, b, c));
    ma = max(ma, calc(lca, b, a, c));
    ma = max(ma, calc(lca, c, b, a));
    cout << ma << "\n";
  }
}
