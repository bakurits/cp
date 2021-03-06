#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

struct segtree {
public:
  segtree(int n) : n(n) {
    num.resize(n << 2);
    cnt.resize(n << 2);
  }
  void insert(int at, int val) {
    insert(1, 0, n - 1, at, val);
  }
  int find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
private:
  void insert(int p, int l, int r, int at, int val) {
    if(l == r) {
      num[p] += val;
      if(num[p] > 0) cnt[p] = 1;
      else cnt[p] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      insert(p + p, l, mid, at, val);
    } else {
      insert(p + p + 1, mid + 1, r, at, val);
    }
    cnt[p] = cnt[p + p] + cnt[p + p + 1];
  }
  int find(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) return cnt[p];
    if(r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, ll, rr) + find(p + p + 1, mid + 1, r, ll, rr);
  }
  int n;
  vector<int> num, cnt;
};

vector<int> pa, pb;
vector<int> ins[N], del[N];
vector<pair<int, int>> ran[N];
int la[N], lb[N], ra[N], rb[N];

int ida(int a) {
  return lower_bound(pa.begin(), pa.end(), a) - pa.begin();
}

int idb(int b) {
  return lower_bound(pb.begin(), pb.end(), b) - pb.begin();
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d %d", la + i, lb + i, ra + i, rb + i);
    pa.push_back(la[i]);
    pa.push_back(ra[i]);
    pa.push_back(la[i] + 1);
    pa.push_back(ra[i] + 1);
    pb.push_back(lb[i]);
    pb.push_back(rb[i]);
  }
  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());
  pa.resize(distance(pa.begin(), unique(pa.begin(), pa.end())));
  pb.resize(distance(pb.begin(), unique(pb.begin(), pb.end())));
  
  for(int i = 0; i < n; i++) {
    if(lb[i] == rb[i]) {
      int b = min(la[i], ra[i]);
      int e = max(la[i], ra[i]);
      ins[ida(b)].push_back(idb(lb[i]));
      del[ida(e + 1)].push_back(idb(lb[i]));
    } else {
      int l = min(lb[i], rb[i]);
      int r = max(lb[i], rb[i]);
      ran[ida(la[i])].emplace_back(idb(l), idb(r));
    }
  }
  int range = pb.size();
  segtree seg(range);
  
  long long ans = 0;
  for(int i = 0; i + 1 < pa.size(); i++) {
    for(auto it : ins[i]) {
      seg.insert(it, 1);
    }
    for(auto it : del[i]) {
      seg.insert(it, -1);
    }
    //printf("%d ada %d\n", pa[i], seg.find(0, range - 1));
    set<pair<int, int>> mel;
    for(auto it : ran[i]) {
      vector<pair<int, int>> bad;
      int l = pb[it.first];
      int r = pb[it.second];
      auto iter = mel.lower_bound(make_pair(l, -1));
      
      if(iter != mel.begin()) iter--;
      while(iter != mel.end() && iter->second < l) iter++;
      while(iter != mel.end()) {
        if(r < iter->first) break;
        bad.push_back(*iter);
        l = min(l, iter->first);
        r = max(r, iter->second);
        iter++;
      }
      for(auto iu : bad) mel.erase(iu);
      mel.insert(make_pair(l, r));
    }
    for(auto it : mel) {
      int l = it.first;
      int r = it.second;
      ans += r - l + 1 - seg.find(idb(l), idb(r));
    }
    ans += 1LL * seg.find(0, range - 1) * (pa[i + 1] - pa[i]);
  }
  cout << ans << endl;
  return 0;
}
