
#include <bits/stdc++.h>
#define ld long double
using namespace std;
const int START = 2147469564;
const int maxx = 2e9;
const int maxn = 5e4;
const ld pi = 4.0*atan(1.0);
const int DELTA = /*floor(16551*2*pi)*/ -710;
int n;

int main() {

    /*ld mini = -8e4;
    for (int i=-8e4/(2.0*pi); i*2.0*pi<=8e4; i++)
    {
        if (abs(sin(floor(i*2.0*pi)))<abs(sin(mini)) and i!=0)
            mini = floor(i*2.0*pi);
    }*/

    //cout << mini << ' ' << sin(mini) << '\n';

    /*int maxi = 0;
    for (int i=INT_MAX-8e4; i<=INT_MAX-1; i++)
    {
        if (sin(i)>sin(maxi))
        {
            maxi = i;
        }
    }*/

    //cout << maxi << '\n';
    //return 0;

    cin >> n;

    for (int i=1; i<=n; i++)
    {
        cout << START+(DELTA)*(i-1) << '\n';
    }
        //cout << START+(DELTA)*(i-1) << ' ' << sin(START+(DELTA)*(i-1)) << '\n';

    return 0;
}