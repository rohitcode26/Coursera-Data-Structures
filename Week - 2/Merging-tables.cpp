#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 10 ;
vector<int> parent(N , -1) , row(N) ;
int mx = -1 ;
int find_par(int a) {
	if (parent[a] < 0) {
		return a ;
	}
	return parent[a] = find_par(parent[a]) ;
}

int join(int u , int v) {
	int p1 = find_par(u) ;
	int p2 = find_par(v) ;
	if (p1 == p2) {
		return mx ;
	}
	if (parent[p1] > parent[p2]) {
		swap(p1 , p2) ;
	}
	parent[p1] += parent[p2] ;
	row[p1] += row[p2] ;
	parent[p2] = p1 ;
	mx = max(mx , row[p1]) ;
	return mx ;
}

int main () {
	int n , m ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; ++i) {
		cin >> row[i] ;
		mx = max(mx , row[i]) ;
	}
	for (int i = 0 ; i < m ; ++i) {
		int u , v ;
		cin >> u >> v ;
		cout << join(u , v) << '\n' ;
	}
	return 0 ;
}
