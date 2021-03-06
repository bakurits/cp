#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> a, b;
LL suma, sumb;

int aLarger() {
	int i;
	FORS(i, min((int) a.size(), (int) b.size())) {
		if(a[i] > b[i]) return 1;
		if(a[i] < b[i]) return 0;
	}
	if(a.size() == b.size()) return -1;
	if(a.size() > b.size()) return 1;
	return 0;
}

int main(void)
{
	int n;
	sf("%d", &n);
	int last = -1;
	while(n--) {
		int num;
		sf("%d", &num);
		if(num < 0) b.push_back(-num), sumb += -num, last = 1;
		else a.push_back(num), suma += num, last = 0;
	}
	if(suma > sumb) puts("first");
	else if(suma < sumb) puts("second");
	else {
		if(aLarger() == 1) puts("first");
		else if(aLarger() == 0) puts("second");
		else {
			if(last) puts("second");
			else puts("first");
		}
	}
	
	return 0;
}
