#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, h;
vector<int> a[N], b[N];
string str;

struct P{
    int x, y, z;

    void print() {
        cout << x << " " << y << " " << z << "\n";
    }
};

vector<P> best, worst;

int main() {
    cin >> n >> m >> h;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            if(str[j] == '1') a[i].push_back(j);
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < h; j++) {
            if(str[j] == '1') b[i].push_back(j);
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i].empty() ^ b[i].empty()) {
            cout << "-1" << endl;
            return 0;
        }
        if(a[i].empty()) continue;
        for(int y : a[i]) {
            for(int z : b[i]) worst.push_back({i, y, z});
        }
        reverse(a[i].begin(), a[i].end());
        reverse(b[i].begin(), b[i].end());
        while(a[i].size() != b[i].size()) {
            best.push_back({i, a[i].back(), b[i].back()});
            if(a[i].size() > b[i].size()) a[i].pop_back();
            else b[i].pop_back();
        }
        while(!a[i].empty()) {
            best.push_back({i, a[i].back(), b[i].back()});
            a[i].pop_back();
            b[i].pop_back();
        }
    }
    cout << worst.size() << "\n";
    for(P p : worst) p.print();
    cout << best.size() << "\n";
    for(P p : best) p.print();
}