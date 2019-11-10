#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 30;

string str;
int n;
int num[N];
ll pw[N];
ll cur_res = 0;

bool check(int l, int r, int b) {
    for(int k = l; k <= r; k++) {
        int sum = 0;
        for(int i = max(0, k - b); i <= min(b, k); i++) {
            sum += num[i] * num[k-i];
        }
        if(sum % 10 != (str[k] - '0')) {
            return false;
        }
    }
    return true;
}

void solve(int b) {
    if(b == n) {
        cout << cur_res << endl;
        exit(0);
    }
    for(int i = 0; i < 10; i++) {
        cur_res += i * pw[n - 1 - b];
        num[b] = i;
        if((b < n - 1 && check(b, b, b)) || (b == n - 1 && check(b, b * 2, b))) {
            solve(b + 1);
        }
        cur_res -= i * pw[n - 1 - b];
    }
}

int main() {
    pw[0] = 1;
    for(int i = 1; i < 18; i++) pw[i] = pw[i-1] * 10;
//
//
//    for(int i = 0; i < 10; i++) {
//        for(int j = 0; j < 10; j++) {
//            G[i][(i * j) % 10].push_back(j);
//        }
//    }
    cin >> str;
    if(str.length() % 2 == 0) {
        cout << "-1" << endl;
        return 0;
    }

    n = ((int)str.length() + 1) / 2;
    solve(0);
    cout << "-1" << endl;


}