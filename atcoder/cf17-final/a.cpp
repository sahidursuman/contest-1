#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
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
  string s;
  cin >> s;
  string t = "AKIHABARA";
  int p=0;
  REP(i, 0, t.length()){
    //cerr << p << " "<< i << endl;
    if (p < s.length() && s[p] == t[i]){
      p++;
      continue;
    }
    if (t[i]=='A'){
      continue;
    }
    p = 1000;
    break;
  }
  cout << (p == s.length() ? "YES" : "NO") << "\n";
}
