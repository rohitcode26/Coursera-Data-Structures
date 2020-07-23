#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 1 ;
vector<int> g[N] , dis(N , -1) ;
int main() {
	int n , root ;
	cin >> n ;
	for (int i = 0 ; i < n ; ++i) {
		int a ;
		cin >> a ;
		if (a == -1) {
			root = i ;
			continue ;
		}
		g[a].push_back(i) ;
		g[i].push_back(a) ;
	}
	queue<int> q ;
	q.push(root) ;
	dis[root] = 1 ;
	while (q.size()) {
		int node = q.front() ;
		q.pop() ;
		for (int &i : g[node]) {
			if (dis[i] != -1) {
				continue ;
			}
			dis[i] = dis[node] + 1 ;
			q.push(i) ;
		}
	}
	int ans = -1 ;
	for (auto &i : dis) {
		ans = max(ans , i) ;
	}
	cout << ans << '\n' ;
	return 0 ;
}
