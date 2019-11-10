//
// Created by EHPC010 on 11/9/2019.
//
#include <iostream>
#include <cstdio>

#define int long long
using namespace std;
const int maxx = 20000;
int n;
int cnt[maxx+1];
int f[maxx+1];

main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    f[0] = 0;
    for (int i=0; i<=maxx; i++)
        f[i]=f[i-1]+cnt[i]*i;


    for (int i=0; i<=maxx; i++)
    {
        int left,right;
        if (i==0)
            left = 0;
        else
            left = f[i-1];


        right = f[maxx]-f[i];

        if (left==right)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}

