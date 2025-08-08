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
