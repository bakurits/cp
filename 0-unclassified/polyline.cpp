#include <bits/stdc++.h>

using namespace std;

const double inf = 1e18;
const double eps = 1e-11;

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  double a, b;
  scanf("%lf %lf", &a, &b);
  if(equal(a, b)) {
    printf("%.15f\n", a);
    return 0;
  }
  bool ada = 0;
  double ans = inf;
  if(a - b > -eps) {
    int l = 1, r = 1e9;
    while(l < r) {
      int k = (l + r + 1) >> 1;
      double x = (a - b) / (2 * k);
      if(b - eps < x) {
        l = k;
      } else {
        r = k - 1;
      }
    }
    double x = (a - b) / (2 * l);
    if(b - eps < x) {
      ada = 1;
      ans = min(ans, x);
    }
  }
  int l = 0, r = 1e9;
  while(l < r) {
    int k = (l + r + 1) >> 1;
    double x = (a + b) / (2 * k + 2);
    double c = x - b;
    if(b - eps < x && c - eps < x) {
      l = k;
    } else {
      r = k - 1;
    }
  }
  double x = (a + b) / (2 * l + 2);
  double c = x - b;
  if(b - eps < x && c - eps < x) {
    ada = 1;
    ans = min(ans, x);
  }
  if(!ada) {
    puts("-1");
  } else {
    printf("%.15f\n", ans);
  }
  return 0;
}