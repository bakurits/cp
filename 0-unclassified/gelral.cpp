#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<int, long long> mp[N];
vector<int> edge[N];
int c[N];
long long ans[N];

tuple<int, int, long long> dfs(int now, int bef) {
  int at = now, cnt = 1;
  long long sum = c[now];
  mp[at][c[now]]++;
  for(auto it : edge[now]) {
    if(it == bef) continue;
    int atr, cntr;
    long long sumr;
    tie(atr, cntr, sumr) = dfs(it, now);
    if(mp[atr].size() < mp[at].size()) {
      for(auto it : mp[atr]) {
        mp[at][it.first] += it.second;
        if(mp[at][it.first] > cnt) {
          cnt = mp[at][it.first];
          sum = it.first;
        } else if(mp[at][it.first] == cnt) {
          sum += it.first;
        }
      }
    } else {
      cnt = cntr;
      sum = sumr;
      for(auto it : mp[at]) {
        mp[atr][it.first] += it.second;
        if(mp[atr][it.first] > cnt) {
          cnt = mp[atr][it.first];
          sum = it.first;
        } else if(mp[atr][it.first] == cnt) {
          sum += it.first;
        }
      }
      at = atr;
    }
  }
  ans[now] = sum;
  return make_tuple(at, cnt, sum);
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", c + i);
  }
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; i++) {
    printf("%I64d ", ans[i]);
  }
  return 0;
}
