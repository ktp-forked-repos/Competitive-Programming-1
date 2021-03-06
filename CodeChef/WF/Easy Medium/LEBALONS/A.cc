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

const int N = 50;

ll dp_num[N][N];
ll dp_den[N][N];

ll cnt[N];
ll sum[N];

void solve(){
	int n, m;
	sd2(n, m);
	
	set<int> dis;
	
	memset(cnt, 0, sizeof cnt);
	memset(sum, 0, sizeof sum);
	memset(dp_den, 0, sizeof dp_den);
	memset(dp_num, 0, sizeof dp_num);
	
	for(int i = 0; i < n; i++){
		int c, p;
		sd2(c, p);
		
		dis.insert(c);
		
		cnt[c] += 1, sum[c] += p;
	}
	
	int k = dis.size();

	dp_den[0][0] = 1;
	for(int i = 1; i < N; i++){
		dp_den[i][0] = 1;
		
		if(cnt[i] == 0){
			for(int j = 1; j <= i; j++){
				dp_num[i][j] = dp_num[i-1][j];
				dp_den[i][j] = dp_den[i-1][j];
			}
			continue;
		}
		
		for(int j = 1; j <= i; j++){
			dp_den[i][j] = dp_den[i-1][j] + dp_den[i-1][j-1] * ((1ll << cnt[i]) - 1);
			dp_num[i][j] = dp_num[i-1][j] + dp_num[i-1][j-1] * ((1ll << cnt[i]) - 1) + (1ll << (cnt[i] - 1)) * sum[i] * dp_den[i-1][j-1];
		}
	}
	
	ll tnum = 0;
	ll tden = 0;
	
	for(int i = m; i <= k; i++){
		tnum += dp_num[N-1][i];
		tden += dp_den[N-1][i];
	}

	tr(tnum, dp_num[1][1], sum[1], cnt[1]);	
	
	assert(tnum >= 0 and tden > 0);
	
	printf("%.10lf\n", (double) tnum / (double) tden);

}

int main(){
	int t;
	sd(t);
	while(t--) solve();
	return 0;
}
