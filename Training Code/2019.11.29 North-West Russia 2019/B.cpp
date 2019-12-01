#include <bits/stdc++.h>
#define ld long double
using namespace std;
const int START = -2147482699;
const int maxx = 2e9;
const int maxn = 5e4;
const ld pi = 4.0*atan(1.0);
const int DELTA = 79853;
int n;

int main() {

    ios_base::sync_with_stdio(0);

    ld mini = -100;
    int vtmin = 1;
    for (int i=1; i <= 8e4; i++)
    {
        ld accuracy = i - floor((double)i / (2 * pi)) * 2 * pi;
        if (accuracy > mini)
        {
            mini = accuracy;
            vtmin = i;
        }
    }

    cout << vtmin << endl;
    cout << sin(vtmin) << '\n';


    int mxi = INT_MIN;
    for(int i = INT_MIN; i < INT_MIN + 1000; i++) {
        if(sin(i) > sin(mxi)) mxi = i;
    }
    cout << mxi << " " << fixed << setprecision(10) << sin(mxi) << endl;

    cin >> n;


    for (int i=1; i<=n; i++) {
        //cout << START+(DELTA)*(i-1) << '\n';
        if (i > 1) {
            if (sin(START + (DELTA) * (i - 1)) > sin(START + DELTA * (i - 2))) {
                cout << i << ' ' << "What!";
                return 0;
            }
        }

//        if (20650<=i and i<=20654)
//            cout << START+DELTA*(i-1) << "\n";
//            cout << sin(START+DELTA*(i-1)) << '\n';
    }
    return 0;
}