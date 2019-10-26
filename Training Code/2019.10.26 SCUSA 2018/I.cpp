#include <bits/stdc++.h>
using namespace std;

int permu[4][6] = {{1, 2, 3, 4, 5, 6},
                   {1, 2, 4, 3, 6, 5},
                   {2, 1, 3, 4, 6, 5},
                   {2, 1, 4, 3, 5, 6}};

int n;
int a[6], b[6];
map<string, int> mp;

string make_string(int b[]) {
    string str;
    for(int i = 1; i <= 6; i++) str.push_back((char)(b[i] + '0'));
    return str;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 6; j++) {
            cin >> a[j];
        }
        int per[3] = {1, 2, 3};
        string ms = "";
        do {
            for(int p = 0; p < 4; p++) {
                for(int k = 0; k < 3; k++) {
                    b[k * 2 + 1] = permu[p][per[k] * 2 - 1];
                    b[k * 2 + 2] = permu[p][per[k] * 2];
                }
                string ns = make_string(b);
                if(ms == "" || ns < ms) ms = ns;
            }
        } while(next_permutation(per, per + 3));
        mp[ms]++;
    }
    int mx = 0;
    for(auto &p : mp) {
        cout << p.first << " " << p.second << endl;
        mx = max(mx, p.second);
    }
    cout << mx << endl;

}