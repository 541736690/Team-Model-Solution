#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int a[N], b[N];

bool check(int x) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= x && x <= b[i]) res++;
    }
    return res == x;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int res = -1;
    for(int i = 0; i <= n; i++) {
        if(check(i)) res = i;
    }
    cout << res << endl;
}