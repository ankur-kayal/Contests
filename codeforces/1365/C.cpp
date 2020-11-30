#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &u: a) cin >> u;
    for(auto &u: b) cin >> u;

    vector<int> pos(n + 1);
    for(int i=0;i<n;i++) {
        pos[a[i]] = i;
    }
    gp_hash_table<int, int> left;
    for(int i=0;i<n;i++) {
        int initial = pos[b[i]];
        if(initial > i) {
            left[n-(initial - i)]++;
        }
        else {
            left[i - initial]++;
        }
    }
    gp_hash_table<int, int> right;
    for(int i=0;i<n;i++) {
        int initial = pos[b[i]];
        if(initial > i) {
            right[initial - i]++;
        } 
        else {
            right[n + initial - i]++;
        }
    }

    int ans = -1;
    for(auto u: left) {
        ans = max(ans, u.second);
    }
    for(auto u: right) {
        ans = max(ans, u.second);
    }
    cout << ans << '\n';

}