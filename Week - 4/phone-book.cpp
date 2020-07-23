#include<bits/stdc++.h>
using namespace std ;
int main () {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int n ;
    cin >> n ;
    map<string , string> m ;
    while (n--) {
        string s ;
        cin >> s ;
        if (s == "add") {
            string num , name ;
            cin >> num >> name ;
            if (m.find(num) != m.end()) m[num] = name ;
            else m.insert({num , name}) ;
        } else if (s == "del") {
            string num ;
            cin >> num ;
            m.erase(num) ;
        } else {
            string num ;
            cin >> num ;
            auto it = m.find(num) ;
            if (m.find(num) == m.end()) cout << "not found\n" ;
            else cout << m[num] << "\n" ;
        }
    }
    return 0 ;
}