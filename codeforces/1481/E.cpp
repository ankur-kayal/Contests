#include <bits/stdc++.h>
using namespace std;

//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'

//----------------------------------- END DEFINES -------------------------------- 

void run_cases() {
    int n;
    cin >> n;
    vector<int> a(n);
    trav(u, a) cin >> u;
    vector<int> first_occurance(n + 1, n + 2), last_occurance(n + 1), count_occurance(n + 1), suffix_max(n + 1);
    for(int i=0;i<n;i++) {
        first_occurance[a[i]] = min(first_occurance[a[i]], i);
        last_occurance[a[i]] = max(last_occurance[a[i]], i);
    }

    for(int i=n-1;i>=0;i--) {
        count_occurance[a[i]]++;
        suffix_max[i] = max(suffix_max[i + 1], count_occurance[a[i]]);
    }

    vector<int> dp(n);
    int answer = -1;
    for(int i=0;i<n;i++) {
        int j = first_occurance[a[i]];
        if(i == last_occurance[a[i]]) {
            dp[i] = (j - 1 >= 0 ? dp[j-1] : 0) + count_occurance[a[i]];
        }

        if(i != 0) {
            dp[i] = max(dp[i-1], dp[i]);
        }
        answer = max(answer, dp[i] + suffix_max[i + 1]);
    }


    cout << n - answer << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}