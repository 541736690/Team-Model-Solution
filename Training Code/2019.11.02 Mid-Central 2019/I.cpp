#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

int n, m;
char a[maxn], b[maxn], c[maxn];

void checkb(int l, int r) {
    for(int x=0;x<m;x++) {
        if(a[l+x] != b[1+x]) return ;
    }
    printf("Yes");
    exit(0);
}

void checkc(int l, int r) {
    for(int x=0;x<m;x++) {
        if(a[l+x] != c[1+x]) return ;
    }
    printf("Yes");
    exit(0);
}

int main() {
    scanf(" %s %s",a+1,b+1);
    n = strlen(a+1); m = strlen(b+1);

    for(int i=1;i<=m;i++) {
        if('a' <= b[i] && b[i] <= 'z') c[i] = 'A' + b[i] - 'a';
        else if('A' <= b[i] && b[i] <= 'Z') c[i] = 'a' + b[i] - 'A';
        else c[i] = b[i];
    }

    if(n == m+1) {
        if('0' <= a[n] && a[n] <= '9') checkb(1,n-1);
        if('0' <= a[1] && a[1] <= '9') checkb(2,n+1);
    }

    else if(n == m) {
        checkb(1,n);
        checkc(1,n);
    }

    printf("No");
}