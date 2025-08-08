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

};
