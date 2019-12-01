#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef long long ll;

unordered_map<int, int> mp;
int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
//    T = 10;
    while(T--) {
        cin >> n;
//        n = 2000;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
//            a[i] = 1000;
        }
        mp.clear();
        mp.reserve(32768);
        mp.max_load_factor(0.25);
        ll res = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < i; j++) res += mp[2 * a[i] - a[j]];
            mp[a[i]]++;
        }
        cout << res << '\n';
    }
}