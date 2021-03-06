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
const ll mod = 1e9 + 7;



int main(void){
  int n;
  string s;
  cin >> n >> s;
  vector<int> d(n);
  REP(i, 0, n) {
    cin >> d[i];
  }
  VI p(n);
  REP(i, 0, n) {
    int v = i + (s[i] == '>' ? d[i] : -d[i]);
    if (v < 0 || v >= n) {
      p[i] = -1;
    } else {
      p[i] = v;
    }
  }
  set<int> vis;
  int c = 0;
  bool outside = false;
  while (1) {
    if (vis.count(c)) {
      break;
    }
    vis.insert(c);
    int nxt = p[c];
    if (nxt == -1) {
      outside = true;
      break;
    }
    c = nxt;
  }
  cout << (outside ? "FINITE" : "INFINITE") << endl;
}
