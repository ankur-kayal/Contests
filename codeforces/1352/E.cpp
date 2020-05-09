#include <bits/stdc++.h>
#define ll  int
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(auto &it:a)
            cin>>it;
        ll count=0;
        ll sum1=0;
        ll sum2;
        vector<bool> v(n+1,false);
        for(ll i=0;i<n;i++)
        {
            sum2=sum1+a[i];
            for(ll j=i+1;j<n&&sum2-sum1<=n;j++)
            {
                sum2+=a[j];
                ll x=sum2-sum1;
                if(sum2-sum1<=n)
                    v[sum2-sum1]=true;
            }
            sum1+=a[i];
        }
        for(ll i=0;i<n;i++)
            if(v[a[i]])
                count++;
        cout<<count;
        cout<<"\n";
    }
	return 0;
}