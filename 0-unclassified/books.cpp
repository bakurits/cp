#include <iostream>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)

const int N = 1000010;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

int n, t, sum, ans, a[100005], i, j, sumi;

int main()
{
	cin >> n >> t;
	FORS(i,100005) a[i] = 0;
	FORS(i,n) sf("%d", &a[i]);
	j = 0; ans = 0;
	FORS(i,n){
		if(i >= j) { j = i; sum = 0; sumi = 0; }
		else if(i < j) { sum -= a[i-1]; sumi--; }
		do {
			sum += a[j];
			sumi++;
			// pf("%d %d %d %d\n",i,j,sum,sumi);
			j++;
		} while (sum < t && j < n);
		if(j == n) j = n-1;
		if(t < sum) { sum -= a[j-1]; j--; sumi--; }
		// cout << sum << ' ' << sumi << "\n";
		if(sum <= t) ans = max(ans, sumi);
	}
	
	cout << ans << endl;
	return 0;
}