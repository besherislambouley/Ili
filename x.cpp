/*
 * turn all the nodes to 1 except the nodes which we know they are 0 and all their children
 * now every 1 value node try to make it 0 and make its children 0 also 
 * build the values and check if we know a value that doesnt equel to the tested value if yes then this node should be 1 , ? ontherwise
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int N , M ;
string Ans ;
vi V [20009] ;
int Val ( string X ) {
	int Crnt = 0 ;
	for ( int i = 1 ; i < X .size() ; i ++ ) {
		Crnt *= 10 ;
		Crnt += X [i] - '0' ;
	}
	Crnt += ( X [0] == 'c' ? N : 0 ) ;
	return Crnt - 1 ; 
}
int Done [20009] , Ret [20009] , Init [20009] ;
void Dfs ( int Node ) { 
	if ( Done [Node] ) return ; 
	Done [Node] = 1 ;
	for ( auto  U : V [Node] ) Dfs ( U ) ; 
}
void Build () {
	for ( int i = 0 ; i < N ; i ++ ) Ret [i] = 1 - Done [i] ;
	for ( int i = N ; i < M + N ; i ++ ) {
		Ret [i] = 0 ;
		for ( auto U : V [i] ) Ret [i] |= Ret [U] ; 
	}
}
int main () {
	cin >> N >> M >> Ans ;
	for ( int i = N ; i < N + M ; i ++ ) {
		string A , B ;
		cin >> A >> B ; 
		V [i] .pb ( Val ( A ) ) ;
		V [i] .pb ( Val ( B ) ) ; 
	}
	for ( int i = 0 ; i < M ; i ++ ) {
		if ( Ans [i] == '0' && !Done [i+N] ) {
			Dfs ( i + N ) ; 
		}
	}
	Build () ;
	for ( int i = 0 ; i < N + M ; i ++ ) {
		Init [i] = 1 - Ret [i] ; 
	}
	for ( int i = N ; i < N + M ; i ++ ) {
		if ( Ret [i] == 0 ) {
			Ans [i-N] = '0' ; 
		}
	}
	for ( int i = 0 ; i < M ; i ++ ) {
		if ( Ans [i] != '?' ) C ;
		for ( int j = 0 ; j < N + M ; j ++ ) Done [j] = Init [j] ; 
		Dfs ( i + N ) ;	
		Build () ;
		for ( int j = 0 ; j < M ; j ++ ) {
			if ( Ans [j] == '1' && Ret [j+N] != 1 ) {
				Ans [i] = '1' ;
				break ; 
			}
		}
	}
	cout << Ans << endl ; 
}
