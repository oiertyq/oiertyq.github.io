#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
namespace mcmf {
	const int N=1002; const int M=500*502*2+1; const int inf=0x3f3f3f3f;
    int tot = 1, head[N], Next[M * 2], ver[M * 2], edge[M * 2], cost[M * 2];
    int dis[N], h[N], lst[N], pre[N], C, n;
	#define pi pair<int,int>
    inline void _add(int u, int v, int c, int w) {
        Next[++tot] = head[u], head[u] = tot, ver[tot] = v, edge[tot] = c, cost[tot] = w;
    }
    inline void add(int u, int v, int c, int w) {
        _add(u, v, c, w), _add(v, u, 0, -w);
    }
    void Dijkstra(int s) {
    	priority_queue<pi, vector<pi>, greater<pi> > q;
        for(; !q.empty(); q.pop());
        fill(dis, dis + 1 + n, -1);
        dis[s] = 0, q.push(pi(0, s));
        while(!q.empty()) {
            pi now = q.top(); q.pop();
            int u = now.second;
            if(dis[u] < now.first) continue;
            for(int i = head[u]; i; i = Next[i]) {
                static int v; v = ver[i];
                if(!edge[i]) continue;
                if(dis[v] < 0 || dis[v] > dis[u] + cost[i] + h[u] - h[v]) {
                    dis[v] = dis[u] + cost[i] + h[u] - h[v];
                    pre[v] = u, lst[v] = i;
                    q.push(pi(dis[v], v));
                }
            }
        }
    }
    int solve(int s, int t) {
        memset(h,0,sizeof(h)); int d=inf;
        while(1){
            Dijkstra(s); if(dis[t] < 0) break;
            for(register int i = 1; i <= n; ++i) h[i] += (dis[i] != -1) ? dis[i] : 0; d=inf;
            for(int u = t; u != s; u = pre[u]) edge[lst[u]]<d && (d=edge[lst[u]]); C += h[t] * d;
            for(int u = t; u != s; u = pre[u]) edge[lst[u]] -= d, edge[lst[u] ^ 1] += d;
        } 
		return C;
    }
}
const int _=501,__=101;
int n,m,k,a,b;
int un[__][__],dis[__][__];
struct pos{
	int x,y;
}st[_], ed[_];
queue<pos> Q;
int dx[8]={1,1,-1,-1,1,1,-1,-1}, dy[8]={1,-1,1,-1,1,-1,1,-1};
#define in(a) (a.x>=1 && a.x<=n && a.y>=0 && a.y<=m && !un[a.x][a.y])
void getdis(int s){
	Q.push(st[s]); dis[st[s].x][st[s].y]=0; pos x; int d;
	while(!Q.empty()){
		x=Q.front(); d=dis[x.x][x.y]; Q.pop();
		for(int i=0;i<8;++i){
			x.x+=dx[i]; x.y+=dy[i];
			(dis[x.x][x.y]==-1) && in(x) && (Q.push(x),dis[x.x][x.y]=d+1);
			x.x-=dx[i]; x.y-=dy[i];
		}
	}
}
char get(){char c=getchar(); while(c!='*' && c!='.') c=getchar(); return c;}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&k,&a,&b); 
	for(register int i=1;i<=n;++i) for(int j=1;j<=m;++j) {
		char ch=get(); un[i][j]=(ch=='*');
	}
	for(register int i=0;i<4;++i) dx[i]*=a,dy[i]*=b;
	for(register int i=4;i<8;++i) dx[i]*=b,dy[i]*=a;
	for(register int i=1;i<=k;++i) scanf("%d%d",&st[i].x,&st[i].y);
	for(register int i=1;i<=k;++i) scanf("%d%d",&ed[i].x,&ed[i].y);
	for(register int i=1;i<=k;++i) {
		memset(dis,-1,sizeof(dis)); getdis(i);
		for(int j=1;j<=k;++j) if(dis[ed[j].x][ed[j].y]!=-1) mcmf::add(i+1,j+k+1,1,dis[ed[j].x][ed[j].y]);
	}
	for(int i=1;i<=k;++i) mcmf::add(1,i+1,1,0),mcmf::add(i+k+1,2*k+2,1,0);
	mcmf::n=2*k+2; printf("%d\n",mcmf::solve(1,2*k+2));
}
