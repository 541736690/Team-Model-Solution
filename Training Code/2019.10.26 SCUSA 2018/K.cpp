//
// Created by 54173 on 10/26/2019.
//
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 100000;
int n,q;
int a[maxn+1];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=q; i++)
    {
        int o,x,y;
        cin >> o >> x >> y;
        if (o==1)
        {
            a[x] = y;
        }
        else
            cout << abs(a[x]-a[y]) << '\n';
    }

    return 0;
}

