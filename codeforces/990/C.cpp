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
const int maxN = 3e5+100;
void run_cases() {
    int n;
    cin >> n;
    int64_t ans = 0;
    int64_t regular = 0;
    vector<int64_t> open(maxN + 1, 0), closed(maxN + 1, 0);
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        // int j=0;
        // int cnt1 = 0, cnt2 = 0;
        // for(;j<s.length();j++) {
        //     if(s[j] == ')') {
        //         cnt1++;
        //     }
        //     else {
        //         break;
        //     }
        // }
        // for(;j<s.length();j++) {
        //     if(s[j] == '(') {
        //         cnt2++;
        //     }
        //     else {
        //         cnt2--;
        //     }
        // }
        // if(s[0] == ')') {
        //     if(cnt2 <= 0) {
        //         closed[abs(-cnt1 + cnt2)]++;
        //     }
        // }
        // else {
        //     if(-cnt1 + cnt2 > 0) {
        //         open[cnt1 + cnt2]++;
        //     }
        //     else if(-cnt1 + cnt2 < 0) {
        //         closed[abs(-cnt1 + cnt2)]++;
        //     }
        //     else {
        //         regular++;
        //         ans++;
        //     }
        // }
        // debug() << imie(i) imie(s) imie(cnt2) imie(cnt1);
        // debug() << imie(regular) << '\n' << imie(open) << '\n' << imie(closed);
        int64_t cnt = 0;
        int64_t mn = 0;
        for(auto u: s) {
            if(u == ')') {
                cnt--;
            }
            else {
                cnt++;
            }
            mn = min(cnt, mn);
        }
        if(mn == 0) {
            if(cnt == 0) {
                regular++;
                ans++;
            }
            else {
                open[cnt]++;
            }
        }
        else {
            if(cnt <= mn) {
                closed[abs(cnt)]++;
            }
        }
        debug() << imie(s) imie(mn) imie(cnt);
    }

    // debug() << imie(regular) << '\n' << imie(open) << '\n' << imie(closed);

    ans += (regular * (regular - 1));
    for(int i=1;i<maxN;i++) {
        ans += open[i] * closed[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}