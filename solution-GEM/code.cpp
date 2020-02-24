#include<bits/stdc++.h>
using namespace std;
#define f(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define d(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ri register int
#define ll long long
#define il inline
#define _ 19260817
namespace intio{char ch; int read(){ ri x=0,f=1; while(!isdigit((ch=getchar()))) f=ch=='-'?-1:1; while(isdigit(ch)) x=x*10+ch-'0', ch=getchar(); return x*f; } void read(int& x) {x = read();}}; using namespace intio;
int max(int x, int y) {return x>y?x:y;} int min(int x, int y) {return x<y?x:y;}
typedef struct wyxkkak{
	int mn, mp, ms;
	void upd(int x, int v){
		if(v<mn) ms=mn, mp=x, mn=v;
		else if(v<ms) ms=v;
	}
} dat ;
dat dp[_];
int ver[_], head[_], Next[_], tot;
int C[_], vis[_];
void add(int u, int v){
	ver[++tot]=v, Next[tot]=head[u], head[u]=tot;
}
void dfs(int n, int f){
	int S=0, k=1; dat& ans=dp[n]; ans.mn=ans.ms=0x3f3f3f3f;
	for(int i=head[n]; i; i=Next[i]) if(ver[i]!=f) dfs(ver[i], n);
	for(int i=head[n]; i; i=Next[i]){
		if(ver[i]==f) continue;
		dat t=dp[ver[i]]; S+=t.mn; C[t.mp]+=t.ms-t.mn; vis[t.mp]=1;
	}
	while(vis[k]) ++k; ans.upd(k, S+k); ++k;
	while(vis[k]) ++k; ans.upd(k, S+k);
	for(int i=head[n]; i; i=Next[i]){
		if(ver[i]==f) continue;
		dat t=dp[ver[i]]; if(!vis[t.mp]) continue;
		ans.upd(t.mp, S+C[t.mp]+t.mp); vis[t.mp]=C[t.mp]=0;
	}
}
int n;
int main(){
	scanf("%d", &n);
	for(int i=1;i<n;++i){
		int x, y; scanf("%d%d", &x, &y); add(x, y); add(y, x);
	} 
	dfs(1, 0);
	printf("%d\n", dp[1].mn);
	return 0;
}
