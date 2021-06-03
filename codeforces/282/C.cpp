#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string a, b;
    cin >> a >> b;
    if(a.length() != b.length()) {
        cout << "NO";
        return;
    }

    if(a == b) {
        cout << "YES";
        return;
    }

    int a1 = count(a.begin(), a.end(), '1');
    int b1 = count(b.begin(), b.end(), '1');

    if(a1 > 0 and b1 > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}