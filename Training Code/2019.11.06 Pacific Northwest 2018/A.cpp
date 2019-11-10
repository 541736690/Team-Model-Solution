//
// Created by 54173 on 11/6/2019.
//

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;

int n, k;
char a[maxn], b[maxn];

int main() {
    scanf("%d %s %s",&k,a,b);
    n = strlen(a);
    int x = 0, y = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == b[i]) x++;
        else y++;
    }
    int ans = 0;
    ans += min(x, k);
    k -= min(x, k);
    ans += y - k;
    printf("%d",ans);
}