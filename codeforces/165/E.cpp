#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


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

void run_cases() {
    int N;
    cin >> N;
    int max_bits = 22;
    vector<int> A(N);
    vector<int> cnt(1 << max_bits);
    int rev = (1 << max_bits) - 1;
    for(int i=0;i<N;i++) {
        cin >> A[i];
        if(A[i] > rev) exit(0);
        cnt[A[i]]++;
    }

    vector<int> ans(1 << max_bits, -1);

    for(int mask = 0; mask < (1 << max_bits); mask++) {
        if(cnt[mask]) {
            ans[mask] = mask;
        }
    }

    // for(int mask = 0; mask < (1 << max_bits); mask++) {
    //     debug() << imie(mask) imie(ans[mask]);
    // }

    for(int i=0;i<max_bits;i++) {
        for(int mask = 0; mask < (1 << max_bits); mask++) {
            if((mask & (1 << i))) {
                int submask = mask ^ (1 << i);
                // debug() << imie(mask) imie(submask);
                ans[mask] = max(ans[mask], ans[submask]);
            }
        }
    }

    for(auto element : A) {
        cout << ans[element^rev] << " ";
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