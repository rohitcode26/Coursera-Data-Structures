#include<bits/stdc++.h>
using namespace std ;
int main() {
	string s ;
	cin >> s ;
	int n = s.length() ;
	stack< pair <char , int> > st ;
	for (int i = 0 ; i < n ; ++i) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			st.push(make_pair(s[i] , i)) ;
		} else {
			if (s[i] == '}') {
				if (st.size() == 0) {
					cout << i+1 ;
					return 0 ;
				}
				pair<char , int> p = st.top() ;
				if (p.first != '{') {
					cout << i+1 ;
					return 0 ;
				} else {
					st.pop() ;
				}
			} else if (s[i] == ']') {
				if (st.size() == 0) {
					cout << i+1 ;
					return 0 ;
				}
				pair<char , int> p = st.top() ;
				if (p.first != '[') {
					cout << i+1 ;
					return 0 ;
				} else {
					st.pop() ;
				}
			} else if (s[i] == ')') {
				if (st.size() == 0) {
					cout << i+1 ;
					return 0 ;
				}
				pair<char , int> p = st.top() ;
				if (p.first != '(') {
					cout << i+1 ;
					return 0 ;
				} else {
					st.pop() ;
				}
			} else {
				continue ;
			}
		}
	}
	if (st.size()) {
		while (st.size() > 1) {
			st.pop() ;
		}
		pair<char , int> p = st.top() ;
		cout << p.second + 1 ;
	} else {
		cout << "Success" ;
	}
	return 0 ;
}
