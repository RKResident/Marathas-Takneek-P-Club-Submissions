#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t, n, m, m2;
	vector<vector<ll>> sols;
	vector<ll> seq;
	
	cin >> t;
	for (ll i = 0; i < t; i++){
	    cin >> n >> m;
	    m2 = m;
	    ll bits = 0;
	    while (m2 > 0){
	        m2 >>= 1;
	        bits++;
	    };
	    bits -= 1;
	    ll comp = 1ll << bits;
	    seq = {n};
	    while (comp > 0){
	        if ((comp & n) == 0){
	            if ((n + comp) <= m){
	                seq.push_back(n+comp);
	            };
	        };
	        comp >>= 1;
	    };
	    sols.push_back(seq);
	};
	
	for (auto sol: sols){
	    if (sol.size() > 1){
	        cout << sol.size() << "\n";
	        for (auto num: sol){
	            cout << num << " ";
	        };
	        cout << "\n";
	    }
	    else{
	        cout << -1 << "\n";
	    };
	};
	return 0;
}
