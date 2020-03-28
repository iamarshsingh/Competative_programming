#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int LIM = 400;
const int mod = 1e9 + 7;

ll modpow(ll b, ll e)
{
  ll curr = b % mod, sol = 1;
  while (e) {
    if (e % 2)
      sol = (sol * curr) % mod;
    curr = (curr * curr) % mod;
    e /= 2;
  }
  return sol;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout); 
  #endif
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N), fac(N + 1, 1);
  for (int i = 1; i <= N; i++)
    fac[i] = ((ll)fac[i - 1] * i) % mod;
  map<int, int> ma;
  vector<vector<int>> pos;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (ma.find(a[i]) == ma.end()) {
      ma[a[i]] = pos.size();
      pos.push_back({});
    }
    a[i] = ma[a[i]];
    pos[a[i]].push_back(i);
  }
  vector<vector<int>> prec;
  for (int i = 0; i * LIM < N; i++) {
    prec.push_back(vector<int>(N - i * LIM));
    vector<int> co(pos.size());
    prec[i][0] = 1;
    co[a[i * LIM]]++;
    for (int j = i * LIM + 1; j < N; j++) {
      co[a[j]]++;
      prec[i][j - i * LIM] = ((ll)prec[i][j - i * LIM - 1] * co[a[j]]) % mod;
    }
  }
  int sol = 0;
  for (int i = 0; i < Q; i++) {
    int L1, L2, R1, R2;
    cin >> L1 >> L2 >> R1 >> R2;
    int L = (L1 * (ll)sol + L2) % N,
      R = (R1 * (ll)sol + R2) % N;
    if (L > R) swap(L, R);
    sol = 1;
    int end = R;
    if (L / LIM != R / LIM) {
      sol = prec[L / LIM + 1][R - (L / LIM + 1) * LIM];
      end = (L / LIM + 1) * LIM;
    }
    for (int i = L; i < end; i++) {
      int occ = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), R)
        - lower_bound(pos[a[i]].begin(), pos[a[i]].end(), i);
      sol = ((ll)sol * occ) % mod;
    }
    sol = (fac[R - L + 1] * modpow(sol, mod - 2)) % mod;
    cout << sol << endl;
  }
  return 0;
}
