//
// Created by 54173 on 10/12/2019.
//
#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 5005;
int sg[maxn+1];
typedef bitset<maxn*2 + 1> bs;

int calsg(int x)
{
    if (sg[x] != -1) return sg[x];

    if(x == 0 || x == 1) return 0;

//    memset(tmp, 0, sizeof(tmp));
    bs tmp;
    tmp.reset();
    for(int i = 1; i <= x - 1; i++) {
        tmp[calsg(i - 1) ^ calsg(x - i - 1)] = true;
    }
    int cur = 0;
    while(true) {
        if(!tmp[cur]) return sg[x] = cur;
        cur++;
    }
}

void solve()
{
    cin >> n;
    if (calsg(n) == 0)
        cout << "Second";
    else
        cout << "First";
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    memset(sg,-1,sizeof(sg));
    for (int i=1; i<=t; i++)
        solve();

//    for(int i = 0; i < 10; i++) cout << i << ": " << calsg(i) << endl;



    return 0;
}
