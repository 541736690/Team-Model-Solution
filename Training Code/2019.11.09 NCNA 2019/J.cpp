//
// Created by EHPC010 on 11/9/2019.
//
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 30;
int n;
char a[maxn+1][maxn+1];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    memset(a,' ',sizeof(a));
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];

    for (int i=1; i<=n; i++)
    {
        int cntB = 0;
        int cntW = 0;
        for (int j=1; j<=n; j++)
            if (a[i][j]=='B')
                cntB++;
            else
                cntW++;



        if (cntB!=cntW)
        {
            cout << 0;
            return 0;
        }
    }

    for (int j=1; j<=n; j++)
    {
        int cntB = 0;
        int cntW = 0;
        for (int i=1; i<=n; i++)
            if (a[i][j]=='B')
                cntB++;
            else
                cntW++;


        if (cntB!=cntW)
        {
            cout << 0;
            return 0;
        }
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) {
            if (a[i][j] == a[i + 1][j] and a[i + 1][j] == a[i + 2][j]) {
                cout << 0;
                return 0;
            }

            if (a[i][j] == a[i][j + 1] and a[i][j + 1] == a[i][j + 2])
            {
                cout << 0;
                return 0;
            }
        }

    cout << 1;
    return 0;
}
