#include <bits/stdc++.h>
using namespace std;

const int N = 27;

int n;
int c[N];
string str;
int pt = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        c[i] = (ch == 'T');
    }
    getchar();
    getline(cin, str);
    stack<int> S;
    for(int i = 0; i < str.length(); i += 2) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            S.push(c[str[i] - 'A']);
        }
        else if(str[i] == '-') {
            S.top() = !S.top();
        }
        else if(str[i] == '+') {
            int a=  S.top(); S.pop();
            S.top() |= a;
        }
        else {
            int a=  S.top(); S.pop();
            S.top() &= a;
        }
    }
//    cout << S.size() << endl;
    cout << (S.top() ? 'T' : 'F') << endl;

}