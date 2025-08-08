#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, int> map_sort(unordered_map<char, int> m){
    vector<pair<char, int>> v = {};
    for (auto p: m){
        v.push_back(p);
    };
    sort(v.begin(), v.end(), [=](pair<char, int> a, pair<char, int> b){
        return (a.second < b.second);
    });
    m = {};
    for (auto p: v){
        m[p.first] =  p.second;
    };
    return m;
};

int main() {
	int t, n, c, to_sub, cost, a;
	string people;
	unordered_map<char, int> counts = {{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}};
	vector<int> sols;
	cin >> t;
	
	for (int i = 0; i < t; i++){
	    cin >> n >> c;
	    cin >> people;
	    to_sub = n;
	    counts = {{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}};
	    for (auto elem: people){
	        counts[elem] += 1;
	    };
	    cost = (int) n*(n+1)/2;
	    counts = map_sort(counts);
	    for (auto p: counts){
	        a = p.second;
	        if (to_sub * a - a*(a-1)/2 > c){
	            cost = (int) cost + c - (to_sub * a - a*(a-1)/2);
	            to_sub -= a;
	        }
	        else{
	            break;
	        }
	    };
	    sols.push_back(cost);
	};
	
	for (auto x: sols){
	    cout << x << "\n";
	}

Very nice question, the solution i found uses an unordered hashmap

It is important to note that a simple greedy algorithm wouldn't work for this, as the strategy has to account for cost savings in the future which come from incurring a big loss in the present.
Edge case to support the above: AAAABC, where C = 11

Solution
Observe
* Everytime chef learns a language instead of translating, total cost reduces by a value 'x', while increasing by c (for first such person).
  Initially, x = n, but each time chef encounters a person whose language he knows, this x reduces by 1.
  This x updates the same way IRREGARDLESS of when chef meets the person. 
* The best time to learn a language (if needed) is at the very first person of that language chef meets. This follows from the previous point.
* From the above two, it is evident that the maximum savings can be achieved by learning the languages spoken by most people, in descending order of popularity.

This can be implemented by an unordered map

Start with a base cost = n*(n+1)/2, from translating every time.
First store the number of people who know each language, sort the umap in descending order, then iterate through each pair in it.
For each, check whether the savings of the language outweigh the cost of learning. If savings > cost, then update the total cost, and continue with the next language
If at any point savings < cost, we can stop iterating. Since the map is in descending order, any further languages will only have worse savings
	return 0;
};
