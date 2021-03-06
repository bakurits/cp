#include <bits/stdc++.h>

using namespace std;

char s[10][10];
int n = 4;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '.') {
        s[i][j] = 'x';
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; l++) {
            bool ok = 1;
            for (int it = 0; it < 3; it++) {
              if (!valid(k, l + it) || s[k][l + it] != 'x') ok = 0;
            }
            if (ok) {
              puts("YES");
              return 0;
            }
            
            ok = 1;
            for (int it = 0; it < 3; it++) {
              if (!valid(k + it, l + it) || s[k + it][l + it] != 'x') ok = 0;
            }
            if (ok) {
              puts("YES");
              return 0;
            }
            
            ok = 1;
            for (int it = 0; it < 3; it++) {
              if (!valid(k + it, l) || s[k + it][l] != 'x') ok = 0;
            }
            if (ok) {
              puts("YES");
              return 0;
            }
            
            ok = 1;
            for (int it = 0; it < 3; it++) {
              if (!valid(k - it, l + it) || s[k - it][l + it] != 'x') ok = 0;
            }
            if (ok) {
              puts("YES");
              return 0;
            }
          }
        }
        s[i][j] = '.';
      }
    }
  }
  puts("NO");
  return 0;
}
