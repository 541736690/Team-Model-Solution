#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d",&n);
    if(n % 2 == 1) {
        cout << "Either" << endl;
    }
    else {
        if(n % 4 == 0) cout << "Even" << endl;
        else cout << "Odd" << endl;
    }
}