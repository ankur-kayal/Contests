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
    int k;
    cin >> k;
    string s;
    cin >> s;
    int N = (1 << (k + 1)) - 1;
    vector<int64_t> winners(N);
    map<int,int> map_index;
    map<int,int> rev_map;
    vector<vector<int>> levels(k);
    int lvl = 0;
    int max_num = 1;
    for(int i = 0; i < (1 << k) - 1; i++) {
        levels[lvl].push_back(i);
        if(levels[lvl].size() == max_num) {
            lvl++;
            max_num *= 2;
        }
    }
    debug() << imie(levels);
    lvl--;
    int rev = 0;
    int ind = 0;
    for(int i = lvl; i >= 0; i--) {
        debug() << imie(levels[i]);
        for(auto u: levels[i]) {
            map_index[u] = ind;
            rev_map[ind] = u;
            ind++;
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < N && right < N) {
            if(s[map_index[i]] == '?') {
                winners[i] = winners[left] + winners[right];
            } else if(s[map_index[i]] == '0') {
                winners[i] = winners[left];
            } else {
                winners[i] = winners[right];
            }
        } else {
            winners[i] = 1;
        }
    }

    debug() << imie(map_index);

    int Q;
    cin >> Q;
    while(Q--) {
        int index;
        char ch;
        cin >> index >> ch;
        index--;
        s[index] = ch;
        index = rev_map[index];
        while(true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            if(s[map_index[index]] == '?') {
                winners[index] = winners[left] + winners[right];
            } else if(s[map_index[index]] == '0') {
                winners[index] = winners[left];
            } else {
                winners[index] = winners[right];
            }
            if(index == 0) {
                break;
            }
            index = (index - 1) / 2;
        }

        cout << winners[0] << '\n';
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