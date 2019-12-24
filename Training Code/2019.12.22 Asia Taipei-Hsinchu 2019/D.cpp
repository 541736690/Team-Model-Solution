#include <bits/stdc++.h>
using namespace std;

vector<string> res;

bool is_bad(string str) {
    return str == "bubble" || str == "tapioka";
}

int main() {
    for(int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        if(!is_bad(str)) res.push_back(str);
    }
    if(res.empty()) cout << "nothing" << endl;
    else {
        for(string s : res) cout << s << " ";
    }
}