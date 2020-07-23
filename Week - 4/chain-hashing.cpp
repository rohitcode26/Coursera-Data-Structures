#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define mod 1000000007
#define x 263
int h(string s , ll bucket) {
    ll ans = 0 ;
    for (int i = s.length()-1 ; i >= 0 ; --i) {
        ans = (ans*x + s[i]) % mod ;
    }
    return ans % bucket ;
}
int main () {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    ll b , q ;
    cin >> b >> q ;
    vector< vector<string> > table(b) ;
    while (q--) {
        string s ;
        cin >> s ;
        if (s == "add") {
            string t ;
            cin >> t ;
            int index = h(t , b) ;
            bool flag = 0 ;
            for (int i = 0 ; i < table[index].size(); ++i) {
                if (table[index][i] == t) flag = 1 ;
            }
            if (!flag) table[index].push_back(t) ;
        } else if (s == "del") {
            string t ;
            cin >> t ;
            int index = h(t , b) ;
            vector<string>::iterator i ; 
	        for (i = table[index].begin() ; i != table[index].end() ; ++i) 
    	        if (*i == t) break ;
	        if (i != table[index].end()) table[index].erase(i) ;
        } else if (s == "find") {
            string t ;
            cin >> t ;
            int index = h(t , b) ;
            vector<string>::iterator i ;
            for (i = table[index].begin() ; i != table[index].end() ; ++i) 
    	        if (*i == t) break ;
	        if (i != table[index].end()) cout << "yes\n" ;
            else cout << "no\n" ;
        } else {
            int num ;
            cin >> num ;
            for (int i = table[num].size()-1 ; i >= 0 ; --i) {
                cout << table[num][i] << " " ;
            }
            cout << "\n" ;
        }
    }
    return 0 ;
}