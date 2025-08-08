#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  int t, n, m, m2;
	vector<vector<int>> sols;
	vector<int> seq;
	
	cin >> t;
	for (int i = 0; i < t; i++){
	    cin >> n >> m;
	    m2 = m;
	    int bits = 0;
	    while (m2 > 0){
	        m2 >>= 1;
	        bits++;
	    };
	    bits -= 1;
	    ll comp = 1 << bits;
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
