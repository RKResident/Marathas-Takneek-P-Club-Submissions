#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, x, y, z, a, b, c, n;
	vector<int> sols = {};
	cin >> t;
	for (int i = 0; i < t; i++){
	    cin >> x >> y >> z >> a >> b >> c;
	    if (z > c){
	        n = c;
	        y += z- c;
	    }
	    else {
	        n = z;
	    };
	    
	    if (y > b){
	        n += b;
	        x += y - b;
	    }
	    else{
	        n += y;
	    };
	    
	    if (x > a){
	        n += a;
	    }
	    else{
	        n += x;
	    };
	    
	    sols.push_back(n);
	};
	
	for (auto elem: sols){
	    cout << elem << "\n";
	}

}

The basic idea is to descend the shirt sizes, starting from XL

Each size category has a base number of people who are happy from the starting conditions. The only way to increase this number is by 
'bringing down' shirts from above. Hence, we start from the largest size, subtract the shirts used to make people of that size happy, and add the remaining to
the next smaller size.
