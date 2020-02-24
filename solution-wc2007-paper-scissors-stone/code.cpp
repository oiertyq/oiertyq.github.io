#include<bits/stdc++.h>
using namespace std; /*Copyright [tyqtyq](http://oiertyq.github.io). All rights served.*/
#define f(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define d(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ri register int
#define ll long long
#define il inline
namespace intio{char ch; int read(){ ri x=0,f=1; while(!isdigit((ch=getchar()))) f=ch=='- '?-1:1; while(isdigit(ch)) x=x*10+ch-'0', ch=getchar(); return x*f; } void read(int& x) {x = read();}}; using namespace intio;
int max(int x, int y) {return x>y?x:y;} int min(int x, int y) {return x<y?x:y;}
namespace mcmf {
	const int _ = 20005;
	int head[_],ver[_*4],edge[_*4],Next[_*4],cost[_*4],tot=-1,s,t ;
	int flow[_],lst[_],dis[_],pre[_],vis[_];
	int n,m,mf,mc ;
	void init(){
		tot = -1 , memset(head,-1,sizeof(head)),memset(Next,-1,sizeof(Next)) ;
	}
	void _add(int u,int v,int w,int f){
		ver[++tot]=v,
		edge[tot]=w,
		cost[tot]=f,
		Next[tot]=head[u],
		head[u]=tot ;
	}
	void add(int u,int v,int w,int f){
		//printf("ADD : (%d, %d, %d, %d)\n", u,v,w,f);
		_add(u,v,w,f),
		_add(v,u,0,-f) ;
	}
	int spfa(int s,int t){
		queue<int> Q;
		memset(dis,0x3f,sizeof(dis));
		memset(flow,0x3f,sizeof(flow));
		memset(vis,0,sizeof(vis));
		Q.push(s); vis[s]=1; dis[s]=0; pre[t]=-1;
		while(!Q.empty()){
			int d=Q.front(); Q.pop(); vis[d]=0;
			for(int i=head[d]; i!=-1; i=Next[i]){
				if(edge[i]>0 && dis[ver[i]]>dis[d]+cost[i]){
					dis[ver[i]]=dis[d]+cost[i]; pre[ver[i]]=d; lst[ver[i]]=i; flow[ver[i]]=min(flow[d],edge[i]);
					!vis[ver[i]] && (Q.push(ver[i]), vis[ver[i]]=1);
				}
			}
		}
		return pre[t]!=-1;
	}
	int mcmf(){
		while(spfa(s,t)){
			int now=t; mf+=flow[t]; mc+=flow[t]*dis[t];
			while(now!=s){
				edge[lst[now]]-=flow[t];
				edge[lst[now]^1]+=flow[t];
				now=pre[now];
			}
		}
    return mc;
	}
}
namespace sol {
  #define _ 192
  int mat[_][_], n, num[_][_], tot;
	pair<int, int> denum[_*_];
  void solve() {
		mcmf::init();
    scanf("%d", &n);
    f(i,1,n) f(j,1,n) {
      scanf("%d", &mat[i][j]);
      if(mat[i][j]==1 || (mat[i][j]==2 && i<j)) num[i][j]=++tot, denum[tot]=make_pair(i, j);
    }
    mcmf::s=10001; mcmf::t=10002;
    f(i,1,n) f(j,1,n) {
      if(mat[i][j]==1) mcmf::add(mcmf::s, num[i][j], 1, 0), mcmf::add(num[i][j], j+tot, 1, 0);
      if(mat[i][j]==2 && i<j) mcmf::add(mcmf::s, num[i][j], 1, 0), mcmf::add(num[i][j], i+tot, 1, 0), mcmf::add(num[i][j], j+tot, 1, 0);
    }
    f(i,1,n) f(j,0,n) mcmf::add(i+tot, mcmf::t, 1, j);
    printf("%d\n", n*(n-1)/2*(n-2)/3-mcmf::mcmf()); memset(mat, 0, sizeof(mat));
    f(u,1,n) {
      for(int i=mcmf::head[u+tot]; i!=-1; i=mcmf::Next[i]) {
				//printf("EDGE : (%d, %d)\n", u+tot, mcmf::ver[i]);
        if(mcmf::ver[i]<=tot&&mcmf::edge[i]) mat[u][(u!=denum[mcmf::ver[i]].second)?denum[mcmf::ver[i]].second:denum[mcmf::ver[i]].first]=1;
      }
    }
    f(i,1,n) f(j,1,n) printf("%d%c", mat[i][j], " \n"[j==n]);
  }
} ;
int main(){
  sol::solve();
  return 0;
}
// sto wyxkk orz
