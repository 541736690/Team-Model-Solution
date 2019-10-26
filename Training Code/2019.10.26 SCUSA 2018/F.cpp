#include <bits/stdc++.h>
using namespace std;

const int N = 105;
typedef pair<string, int> P;
map<string, int> mp;

int n;
P p[N];

bool cmp(P p1, P p2) {
    return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        mp.clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            string str; int x;
            cin >> str >> x;
            mp[str] += x;
        }
        n = 0;
        for(auto cp : mp) {
            p[n++] = cp;
        }
        sort(p, p + n, cmp);
        cout << n << '\n';
        for(int i = 0; i < n; i++) cout << p[i].first << " " << p[i].second << "\n";
    }

}