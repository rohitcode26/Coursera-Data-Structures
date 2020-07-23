#include<bits/stdc++.h>
using namespace std ;
int main() {
	int n ;
	cin >> n ;
	vector<int> v(n+1) ;
	for (int i = 1 ; i <= n ; ++i) {
		cin >> v[i] ;
	}
	int m ;
	cin >> m ;
	multiset< pair <int , int> > st ;
	for (int i = 1 ; i <= m ; ++i) {
		st.emplace(v[i] , i) ;
	}
	auto ptr = prev(st.end()) ;
	cout << ptr->first << ' ' ;
	for (int i = m+1 ; i <= n ; ++i) {
		auto itr = st.find(make_pair(v[i-m] , i-m)) ;
		st.erase(itr) ;
		st.emplace(v[i] , i) ;
		auto ptr = prev(st.end()) ;
		cout << ptr->first << ' ' ;
	}
	return 0 ;
}
