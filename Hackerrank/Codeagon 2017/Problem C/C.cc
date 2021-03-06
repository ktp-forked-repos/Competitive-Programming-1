#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

const ll MOD = 1e9 + 7;

const int N = 2100;

ll dp[N][N];
ll sum[N];
ll csum[N][N];
ll b[N];

void solve(){
	int n, e;
	cin >> n >> e;
	
	for(int i = 1; i <= e; i++){
		cin >> b[i];
	}
	
	dp[0][0] = 1;
	sum[0] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= e; j++){
			int k = max(i - b[j] - 1, -1ll);
			dp[i][j] = (sum[i-1] - ((k == -1)? 0 : sum[k]) + MOD) - (csum[i-1][j] - ((k == -1)? 0 : csum[k][j]) + MOD) + MOD;
			dp[i][j] %= MOD;
			
			csum[i][j] = (csum[i-1][j] + dp[i][j]) % MOD;
		}
		
		sum[i] = sum[i-1];
		for(int j = 1; j <= e; j++){
			sum[i] = (sum[i] + dp[i][j]) % MOD;
		}
	}
	
	cout << (sum[n] - sum[n-1] + MOD) % MOD << endl;
	
}

int main(){ _
	int s;
	cin >> s;
	while(s--) solve();	
	return 0;
}
