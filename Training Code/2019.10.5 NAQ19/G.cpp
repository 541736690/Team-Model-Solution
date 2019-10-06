#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
double pr[N];
double dp[N][N];

double solve(int p) {
    for(int i = 0; i < N; i++) fill(dp[i], dp[i] + N, 0);
    dp[0][0] = 1;
    for(int i = 1; i <= p; i++) {
        for(int j = 0; j < N; j++) {
            if(j - 1 >= 0) dp[i][j] += dp[i-1][j-1] * pr[i];
            dp[i][j] += dp[i-1][j] * (1 - pr[i]);
        }
    }
    double res = 0;
    for(int i = 1; i <= p; i++) {
        res += dp[p][i] * pow(i, (double)i / p);
    }
    return res;
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> pr[i];
        pr[i] /= 100;
    }
    sort(pr + 1, pr + n + 1, greater<>());

    double res = 0;
    for(int p = 1; p <= n; p++) {
        res = max(res, solve(p));
    }
    cout << fixed << setprecision(10) << res << endl;

}