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

 Easier than first q, but has a VERY ugly edge case (for cpp amateurs like me at least)

 Observe
 * Two cases to consider for bitwise and
 * When the & results in a 0 at a place in n, it means there can be at most ONE number in the sequence which has a 1 at that place. All others must have a 0 there.
 * When the & results in a 1 at a place in n, it means ALL numbers of the sequence must have a 0 at that place
 * It is evident that the longest possible sequence occurs when we have one number which is an exact copy of n, and the rest of the numbers of the sequence have only one 0 switched to a 1 from n.
 * From here it's just a matter of iterating through the bits of n, and using bit manipulation to make the program more efficient. A naive approach calculating the binary rep as an array using the
   remainder algorithm leads to a very slow solution
*  IMPORTANT: the constraints of the problem require the use of long long ints instead of ints. in line 21, it is critical to write 1ll and not 1, as that leads to an overflow error and causes the solution
   to fail task# 3 (side not: VERY ANNOYING ERROR WHICH TOOK ME A DAY TO CATCH. SAME CODE WORKED IN PYTHON BY NOT CPP)
	return 0;
}
