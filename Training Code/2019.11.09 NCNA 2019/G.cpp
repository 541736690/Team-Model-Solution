#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int N = 37000;

int pn;
int cnt[N];
ld fac[N];

ld comb(int n, int k) {
    return fac[n] - fac[k] - fac[n-k];
}

ld multi(int n, int k) {
    return fac[n] - fac[k] * (int)(n / k);
}

int main() {
    fac[0] = 0;
    for(int i = 1; i < N; i++) fac[i] = fac[i-1] + log10(i);

    cin >> pn;
    int sum = 0, days = 365;
    for(int i = 1; i <= pn; i++) {
        int a; cin >> a;
        sum += a;
        cnt[a]++;
    }
    ld res = 0;
    for(int i = 1; i <= 365; i++) {
        res += comb(days, cnt[i]) + comb(sum, cnt[i] * i) + multi(cnt[i] * i, i) - log10(365) * cnt[i] * i;
        sum -= cnt[i] * i;
        days -= cnt[i];
    }
    cout << fixed << setprecision(10) << res << endl;

}