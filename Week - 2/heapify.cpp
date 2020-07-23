#include<bits/stdc++.h>
using namespace std ;
vector<int> v ;
vector< pair<int , int> > ans ;

void Heapify(vector<int> &a , int n , int i) 
{ 
	int smallest = i ; 
	int l = 2 * i + 1 ; 
	int r = 2 * i + 2 ; 
	if (l < n && a[l] < a[smallest]) {
        smallest = l ;
    } 
	if (r < n && a[r] < a[smallest]) {
        smallest = r ;
    } 
	if (smallest != i) { 
		swap(a[i], a[smallest]) ;
        ans.push_back(make_pair(i , smallest)) ;
		Heapify(a , n , smallest) ;
	} 
} 

void MakeHeap(vector<int> &a , int n) {
	int indx = (n / 2) - 1 ;
	for (int i = indx ; i >= 0 ; --i) { 
		Heapify(a , n , i) ;
	} 
} 

int main() {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int n ;
    cin >> n ;
    v.assign(n , 0) ;
    for (auto &i : v) {
        cin >> i ;
    }
    MakeHeap(v , n) ;
    cout << (int)ans.size() << "\n" ;
    for (auto &i : ans) {
        cout << i.first << " " << i.second << "\n" ;
    }
	return 0 ; 
} 
