#include <bits/stdc++.h>
#define ld long double
using namespace std;
const int START = -2147482697;
const int maxx = INT_MAX;
const int maxn = 5e4;
const ld pi = acos(-1.0);
const int DELTA = floor(16551*2*pi);
int n;
int a[100005];

int main() {

    cin >> n;

    for (int i=1; i<=n; i++) a[i] = START+(DELTA)*(i-1);
    //for (int i=1; i<=n; i++) a[i+n] = -START+(DELTA)*(i-1);

    sort(&a[1],&a[n+1],[](int x, int y) {return sin(x) > sin(y);});

    int cnt = 0;

    int l = -INT_MIN, r = maxx, last = maxx;
    for(int i=1;i<=n*2;i++) {
        if(a[i]<l || r<a[i]) {
            printf("BAD! %d [%d %d] <- %d\n",i,l,r,a[i]);
            break;
        }
        if(a[i]<=last) r = last;
        else l = last;
        // printf("%d: %.10lf\n",a[i],sin(a[i]));
        last = a[i];
        cnt++;
        if(cnt%10000==0) printf("%d\n",cnt);
    }
    printf("%d",cnt);

    return 0;
}