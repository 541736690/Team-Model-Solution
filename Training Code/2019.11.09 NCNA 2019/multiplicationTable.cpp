//
// Created by EHPC010 on 11/9/2019.
//
#include <iostream>
#include <cstdio>


using namespace std;

int cnt[10][10];
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("output.txt","w",stdout);


    for (int i=1; i<=2; i++)
        for (int j=0; j<=9; j++)
            for (int z=0; z<=9; z++) {
                cout << i << ' ' << j << ' ' << z << ' ' << (i * j * z) % 10 << '\n';
                cnt[i][(i * j * z) % 10]++;
            }

    for (int i=0; i<=2; i++)
        cout <<

}
