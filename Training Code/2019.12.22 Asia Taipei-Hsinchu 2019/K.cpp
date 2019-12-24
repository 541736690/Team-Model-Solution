#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e3 + 50;

typedef long long ll;

int n;
priority_queue<int, vector<int>, greater<int> > pque;

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;

        ll res = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            pque.push(x);
        }
        for(int it = 0; it < n - 1; it++) {
            int a = pque.top(); pque.pop();
            int b = pque.top(); pque.pop();
            res += a + b;
            pque.push(a + b);
        }
        cout << res << '\n';
        pque.pop();
    }
}