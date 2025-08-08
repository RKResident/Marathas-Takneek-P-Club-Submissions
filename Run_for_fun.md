#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
	if (y%x == 0){
	    cout << y/x - 1;
	}
	else{
	    cout << (int) y/x;
	};
    return 0;
}

Very simple problem, only edge case to check if is x is a factor of y
