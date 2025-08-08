#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<char, char> pc;

int main() {
	int t, n;
	string v1, v2;
	vi sols;
	pc one_one = {'1', '1'};
	pc one_zero = {'1', '0'};
	pc zero_one = {'0', '1'};
	pc zero_zero = {'0', '0'};
	map<pair<char, char>, int> counts = {
	    {one_one, 0}, 
	    {one_zero, 0}, 
	    {zero_zero, 0}
	};
	
	cin >> t;
	for (int i = 0; i < t; i++){
	    cin >> n;
	    
	    v1 = {}; v2 = {};
	    counts = {
    	    {one_one, 0}, 
    	    {one_zero, 0}, 
    	    {zero_zero, 0}
    	};
    	
	    cin >> v1;
	    cin >> v2;
	    
	    // odd is -1, even is 0
	    for (int j = 0; j < n; j++){
	       // cout << v1[j] << v2[j] << "\n";
	        if ((v1[j] == v2[j]) && (v1[j]=='1')){
	            counts[one_one] = ~counts[one_one];
	           // cout << "h1" << "\n";
	        }
	        else if (((v1[j] == '1') && (v2[j] == '0')) || ((v1[j] == '0' && v2[j] =='1'))){
	            counts[one_zero] = ~counts[one_zero];
	           // cout << "h2" << "\n";
	        }
	        else{
	            counts[zero_zero] = ~counts[zero_zero];
	           // cout << "h3" << "\n";
	        };
	    };
	    
	    int s = counts[one_one] + counts[one_zero] + counts[zero_zero];
	    
	    if (n & 1){
	        if ((s == -1) | (s == 0)){
	            sols.push_back(1); 
	        }
	        else{
	            sols.push_back(0);
	        };
	    }
	    else{
	        if (s == 0){
	            sols.push_back(1);
	        }
	        else{
	            sols.push_back(0);
	        };
	    };
	    
	};
	
	for (auto sol: sols){
	    if (sol){
	        cout << "YES" << "\n";
	    }
	    else {
	        cout << "NO" << "\n";
	    };
	};
	return 0;
};

Observe
* a pair of bits A_i and B_i will always remain together at the same index, even if this index change. The only thing that can change is their order, if A_i and B_i are different (1,0 vs 0,1)
* As a result of this, we can simplify our process of forming palindromes by first converting all (0,1) pairs to (1,0). A_i = 1, B_i = 0
* From here on, we can look at these 'pairs' instead of the individual strings. We'll consider the two strings together to form a palindromic 'block' (idk the right word to use here)
* Thus, we find 3 types of pairs. 1-0, 0-0, and 1-1 (0-1 need not be considered as we converted them to 1-0)
* if n is odd, there are two possibilities
*   *   Theres an even number of all three pairs
    *   One pair has an odd number, other two are even
* if n is even, only one possibility
*   *   all three pairs have even numbers
* Hereon, simple matter of iteration and calculation. Small speedups can be achieved by using bitwise operations to track the parity of the pairs
