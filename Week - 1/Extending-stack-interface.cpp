#include<bits/stdc++.h>
using namespace std ;

stack<int> st ;

int main() {
	int q ;
	cin >> q ;
	while (q--) {
		string s ;
		cin >> s ;
		if (s == "push") {
            int a ;
            cin >> a ; 
            if (st.size() == 0) 
            	st.emplace(a) ;
            else
            	st.emplace(max(st.top() , a)) ;
        } else if (s == "pop") {
			if (st.size())
				st.pop() ;     
        } else {
            cout << st.top() << '\n' ;
        }
	}
	return 0 ;
}
