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



int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  VI a(m);
  vector<PI> b(m);
  REP(i, 0, m) {
    cin >> a[i];
  }
  REP(i, 0, m) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  VI res(m);
  REP(i, 0, m) {
    int idx = b[i].second;
    res[idx] = a[i];
  }
  REP(i, 0, m) {
    cout << res[i] << (i == m - 1 ? "\n" : " ");
  }
}
