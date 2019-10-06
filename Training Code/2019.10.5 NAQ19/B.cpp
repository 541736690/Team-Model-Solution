#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;

int main() {
    cin >> a >> b;
    cout << __gcd(2 * a, 2 * b) - __gcd(a, b * 2) - __gcd(a * 2, b) + __gcd(a, b) << endl;
}