#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n;
string str[N];
int mat[N][N], res[N][N];
int row[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> str[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) mat[i][j] = str[i][j] - '0';
    }
    for(int i = n - 2; i >= 0; i--) {
        mat[i+1][i+1] = 1;
        for(int j = 0; j < n; j++) row[j] = mat[i][j];
        for(int j = i + 1; j < n; j++) {
            if(row[j] == 0) continue;
            res[i][j] = 1;
            for(int k = j; k < n; k++) {
                row[k] -= mat[j][k];
                if(row[k] < 0) row[k] += 10;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << res[i][j];
        cout << '\n';
    }

}