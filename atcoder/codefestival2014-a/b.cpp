#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

using namespace std;
typedef long long int ll;
const double EPS=1e-9;



int main(void){
	string a;
	int b;
	cin>>a>>b;
	int n = a.length();
	int i = (b-1) % n;
	cout << a[i] << endl;
}
