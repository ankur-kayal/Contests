#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

void solve() {
    ll a,b;
    cin >> a >> b;
    ll q = ceil((double) a / b);
    ll answer = q * b - a;
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}