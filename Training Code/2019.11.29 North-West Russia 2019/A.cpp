#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b,n; scanf("%d%d%d",&a,&b,&n);
    int x = (int)ceil((double)(n-b)/(b-a));
    printf("%d",x*2 + 1);
}
