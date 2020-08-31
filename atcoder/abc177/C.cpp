#include <bits/stdc++.h>
#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)
#define nui 100
#define INF 100000000000
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf int t;cin>>t;for(int w=1;w<=t;w++)



using namespace std;

void dex(int a)
{
    if (a == 1)
    {
        cout << "1\n";
    }
    else if (a == -1)
    {
        cout << "-1\n";
    }
    else if (a == 0)
    {
        cout << "0\n";
    }
    else if (a == 2)
    {
        cout << "YES\n";
    }
    else if (a == 3)
    {
        cout << "NO\n";
    }

}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
       a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}




int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    ll csum = 0;
    F(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
        csum += (a[i] % mod) * (a[i] % mod);
        csum %= mod;
        sum %= mod;
    }
    sum = ((sum % mod) * (sum % mod)) % mod;
    cout << ((mod + sum - csum) * binpow(2,mod-2) ) % mod << "\n";

	//cout << binpow(2,mod-2) << '\n';



    return 0;


    return 0;

}