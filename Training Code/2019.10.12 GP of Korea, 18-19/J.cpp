#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, INF = (int)1e9;
typedef pair<int, int> P;
typedef pair<ll, int> Pli;

int n;
int h[N];
int L[N], R[N];
ll lb, rb;

ll count_len(ll len, int i) {
    return max(0LL, R[i] - L[i] + 1 - len + 1)
       - max(0LL, i - L[i] - len + 1)
       - max(0LL, R[i] - i - len + 1);
}

ll count(ll mxlen, ll len) {
    len = min(mxlen, len);
    return (2 * mxlen - len + 1) * len / 2;
}

ll count_small(ll sum) {
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        res += count(R[i] - L[i] + 1, sum / h[i])
                - count(i - L[i], sum / h[i])
                - count(R[i] - i, sum / h[i]);
    }
    return res;
}

vector<ll> fres;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    cin >> lb >> rb;
    stack<P> S;
    S.push({-INF, 0});
    for(int i = 1; i <= n; i++) {
        while(S.top().first >= h[i]) S.pop();
        L[i] = S.top().second + 1;
        S.push({h[i], i});
    }
    while(!S.empty()) S.pop();
    S.push({-INF, n + 1});
    for(int i = n; i >= 1; i--) {
        while(S.top().first > h[i]) S.pop();
        R[i] = S.top().second - 1;
        S.push({h[i], i});
    }

    ll l = 0, r = (ll)3e15 + 50, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(count_small(mid) >= lb) r = mid;
        else l = mid;
    }
    ll tot = count_small(r);

    for(ll i = 0; i < min(tot, (ll)rb) - lb + 1; i++) fres.push_back(r);
    priority_queue<Pli, vector<Pli>, greater<Pli> > pque;
    while(!pque.empty()) pque.pop();
    for(int i = 1; i <= n; i++) {
        if(count_len(r / h[i] + 1, i) > 0) {
            pque.push(Pli((r / h[i] + 1) * h[i], i));
        }
    }
    while(!pque.empty() && fres.size() < rb - lb + 1) {
        P p = pque.top(); pque.pop();
        int i = p.second;
        ll sum = p.first;
        ll c = count_len(sum / h[i], i);
        while(c > 0 && fres.size() < rb - lb + 1) {
            c--;
            fres.push_back(sum);
        }
        if(count_len(sum / h[i] + 1, i) > 0) {
            pque.push(Pli((sum / h[i] + 1) * h[i], i));
        }
    }
    for(ll x : fres) cout << x << " ";
    cout << "\n";

}