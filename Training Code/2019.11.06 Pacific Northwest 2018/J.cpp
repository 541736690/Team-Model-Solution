//
// Created by 54173 on 11/6/2019.
//
#include <iostream>
#include <cstdio>


using namespace std;
const int maxn = 100;
int n,s;
int t[maxn+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    int res = 0;
    for (int i=1; i<=n; i++)
    {
        cin >> t[i];
        res = max(res,t[i]);
    }

    res*=s;
    if (res%1000==0)
        cout << res/1000;
    else
        cout << res/1000+1;

    return 0;
}