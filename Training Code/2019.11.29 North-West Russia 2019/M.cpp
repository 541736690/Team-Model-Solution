#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef long long ll;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        ll res = 0;
        for(int i = n - 1; i >= 0; i--) {
            int k = i + 1;
            for(int j = i - 1; j >= 0; j--) {
                while(k < n && a[k] < a[i] * 2 - a[j]) k++;
                int nxt_k = k;
                while(nxt_k < n && a[nxt_k] == a[i] * 2 - a[j]) nxt_k++;
                cout << i << ", " << j << " " << k << ", " << nxt_k << endl;
                res += (nxt_k - k);
                k = nxt_k;
            }
        }
        cout << res << '\n';

    }
}