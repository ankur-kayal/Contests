#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

//HEADER FILES AND NAMESPACES
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

void update(vector<ll> &a, ll index, ll val, ll &ans) {
	int n = a.size();
	ans -= max(0LL, a[index] - a[index - 1]);
	if(index + 1 < n) {
		ans -= max(0LL, a[index + 1] - a[index]);
	}
	a[index] = val;
	ans += max(0LL, a[index] - a[index - 1]);
	if(index + 1 < n) {
		ans += max(0LL, a[index + 1] - a[index]);
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifdef DEBUG
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
    // for writing external error logs to output.txt
    freopen("output.txt", "a+", stderr);
#endif  

#ifdef DEBUG
    clock_t start, end; 
    start = clock();
#endif 

	// start your program here

	int t;
	cin >> t;
	while(t--) {
		ll n,q;
		cin >> n >> q;
		vector<ll> a(n+1,0);
		ll ans = 0;
		for(int i=1;i<=n;i++) {
			int tmp;
			cin >> tmp;
			update(a,i,tmp, ans);
		}

		cout << ans << '\n';
		while(q--) {
			ll l,r;
			cin >> l >> r;
			ll tmp = a[l];
			update(a,l,a[r],ans);
			update(a,r,tmp,ans);
			cout << ans << '\n';
		}

	}


#ifdef DEBUG
    end = clock();  
    ld time_taken = ld(end - start) / ld(CLOCKS_PER_SEC); 
    cerr << "\nTime taken by program is : " << fixed << time_taken << setprecision(5); 
    cerr << " sec " << '\n'; 
#endif 
	   
}
 
// read the question correctly (ll vs int)
// template by bqi343