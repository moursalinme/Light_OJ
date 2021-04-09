#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 100, sz = 5761500;

unsigned int pref[sz];
int prime[sz];
int ok[N >> 5];

bool check (int n, int pos) {
  return n & (1 << pos); 
}

void On (int& n, int pos) {
  n |= (1 << pos);
}

int main () {
  for (int i = 3; i <= (int) 1e4; i += 2) {
    if (!check(ok[i >> 5], (i & 31))) {
      for (int j = i * i; j < N; j += (i << 1)) {
        On (ok[j >> 5], (j & 31));
      }
    }
  }

  prime[0] = pref[0] = 2;

  for (int i = 3, j = 1; i < N; i += 2) {
    if(!check(ok[i >> 5], (i & 31))) {
      prime[j] = i;
      pref[j] = i * pref[j - 1];
      ++j;
    }
  }

  int test_c;
  scanf ("%d", &test_c);

  for (int tc = 1; tc <= test_c; ++tc) {
    int n; 
    scanf ("%d", &n);
    unsigned int answer = 1;
    int lim = sqrt (n);

    for (int i = 0; i < sz && prime[i] <= lim; ++i) {
      long long now = prime[i] * prime[i];
      
      while (now <= n) {
        answer *= prime[i];
        now *= prime[i] * 1LL;
      }
    }

    int lb = lower_bound (prime, prime + sz, n) - prime;
    
    if (prime[lb] > n) {
      --lb;
    }
    
    printf ("Case %d: %u\n", tc, answer * pref[lb]);
  }
  return 0;
}