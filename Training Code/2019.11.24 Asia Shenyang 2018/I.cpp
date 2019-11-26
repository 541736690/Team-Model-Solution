#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 2048;

struct FWT {
//    int N = 2048;

    void FWTxor(vector<ll> &a, int opt) {
        for(int mid = 1; mid < N; mid <<= 1) {
            for(int R = mid << 1, j = 0; j < N; j += R) {
                for(int k = 0; k < mid; k++) {
                    ll x = a[j + k], y = a[j + k + mid];
                    if(opt == 1) a[j + k] = x + y, a[j + k + mid] = x - y;
                    else {
                        a[j + k] = (x + y) / 2, a[j + k + mid] = (x - y) / 2;
                    }
                }
            }
        }
    }
} fwt;

vector<vector<int> > I, A, G;
vector<vector<int> > PI, PA, PG;
vector<vector<ll> > PIc, PAc, PGc;
vector<vector<ll>> d;

void read_and_prefix(int r1, int r2, vector<vector<int> > &arr, vector<vector<int> > &psum,
        vector<vector<ll> > &psum_c) {
    for(int i = 0; i <= r1; i++) {
        for(int j = 0; j <= r2; j++) {
            arr[abs(i - j)][i ^ j]++;
        }
    }

    for(int j = 0; j < N; j++) psum[0][j] = arr[0][j];
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < N; j++) psum[i][j] = psum[i-1][j] + arr[i][j];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            psum_c[i][j] = psum[i][j];
        }
        fwt.FWTxor(psum_c[i], 1);
    }
}

ll solve(int sign, vector<vector<ll> > &A1, vector<vector<ll> > &A2, vector<vector<ll> > &A3) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            d[i][j] += sign * A1[i][j] * A2[i][j] * A3[i][j];
            if(i > 0) d[i][j] -= sign * A1[i-1][j] * A2[i-1][j] * A3[i-1][j];
        }
    }
    return 0;
}

void solve(int tcase) {
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) d[i][j] = 0;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) A[i][j] = I[i][j] = G[i][j] = 0;
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    read_and_prefix(a1, a2, I, PI, PIc);
    read_and_prefix(b1, b2, A, PA, PAc);
    read_and_prefix(c1, c2, G, PG, PGc);
    ull res = solve(1, PIc, PAc, PGc);
    for(int i = 0; i < N; i++) {
        fwt.FWTxor(d[i], -1);
        for(int j = 0; j < N; j++) {
            res += d[i][j] * (j ^ i);
        }
    }
    cout << "Case #" << tcase << ": " << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    A.resize(N, vector<int>(N, 0));
    I.resize(N, vector<int>(N, 0));
    G.resize(N, vector<int>(N, 0));
    PA.resize(N, vector<int>(N, 0));
    PAc.resize(N, vector<ll>(N, 0));
    PI.resize(N, vector<int>(N, 0));
    PIc.resize(N, vector<ll>(N, 0));
    PG.resize(N, vector<int>(N, 0));
    PGc.resize(N, vector<ll>(N, 0));
    d.resize(N, vector<ll>(N, 0));
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        solve(t);
    }

}