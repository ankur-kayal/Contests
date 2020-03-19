#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    vector <ll> b(n);
    for(int i=0;i<n;i++) {
    	cin >> b[i];
    }
    vector <ll> a(n,0);
    a[0] = b[0];
    ll maximum = a[0];
    for(int i=1;i<n;i++) {
    	a[i] = maximum + b[i];
    	maximum = max(maximum,a[i]);
    }
    for(int i=0;i<n;i++) {
    	cout << a[i] << " ";
    }
    cout << '\n';
}