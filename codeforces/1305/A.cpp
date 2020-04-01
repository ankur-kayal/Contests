#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n],b[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	    }
	    sort(a,a+n,greater<int>());
	    sort(b,b+n,greater<int>());
	    for(int i=0;i<n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<'\n';
	    for(int i=0;i<n;i++){
	        cout<<b[i]<<' ';
	    }
	    cout<<'\n';
	}
}