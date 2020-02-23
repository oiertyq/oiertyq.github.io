#include<bits/stdc++.h>
using namespace std;
#define f(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define d(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ri register int
#define ll long long
#define il inline
int max(int x, int y) {return x>y?x:y;} int min(int x, int y) {return x<y?x:y;}
#define _ 1000005
struct SA{
  const char chr='0';
  char str[_];
  int n, m, rk[_], sa[_], tax[_], tp[_], ht[_];
  void sort() { f(i,0,m) tax[i]=0; f(i,1,n) ++tax[rk[i]]; f(i,1,m) tax[i]+=tax[i-1]; d(i,n,1) sa[tax[rk[tp[i]]]--]=tp[i]; }
  void getSA() {
    m=75; f(i,1,n) rk[i]=str[i]-chr+1, tp[i]=i;
    for(int w=1, p=(sort(), 0); p<n; m=p, w<<=1) {
      p=0; f(i,1,w) tp[++p]=n-w+i;
      f(i,1,n) if(sa[i]>w) tp[++p]=sa[i]-w; sort(); swap(tp, rk);
      rk[sa[1]]=p=1; f(i,2,n) rk[sa[i]] = (p += 1-(tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+w]==tp[sa[i]+w]));
    }
  }
  void getHeight() {
    f(i,1,n) rk[sa[i]]=i; for(int i=1, k=0, j=sa[rk[i]-1]; i<=n; ++i, j=sa[rk[i]-1]) {
      if(rk[i]==1) continue; k-=k>0; while(j+k<=n&&i+k<=n&&str[i+k]==str[j+k]) ++k; ht[rk[i]]=k;
    }
  }
} sa ;
int fa[_], siz[_], id[_], n, r;
long long ans1[_], ans2[_], ans[_], Mn[_], Mx[_], a[_];
int cmp(int x, int y) {return sa.ht[x]>sa.ht[y];}
int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void merge(int x, int y, int z) {
  int fx=getfa(x), fy=getfa(y); ans1[z]+=(long long)siz[fx]*siz[fy];
  ans[x]=max(max(Mx[fx]*Mx[fy], Mn[fx]*Mn[fy]), ans[x]);
  ans[x]=max(max(Mn[fx]*Mx[fy], Mx[fx]*Mn[fy]), ans[x]);
  ans[x]=max(ans[x], ans[y]); ans2[z]=max(ans2[z], ans[x]);
  Mn[fx]=min(Mn[fx], Mn[fy]); Mx[fx]=max(Mx[fx], Mx[fy]); siz[fx]+=siz[fy]; fa[fy]=fx;
}
void solve() {
  f(i,1,n) fa[i]=i, siz[i]=1, Mx[i]=Mn[i]=a[i];
  f(i,0,_-1) ans[i]=ans2[i]=(-1000000000000000000LL);
  f(i,2,n) merge(sa.sa[id[i]], sa.sa[id[i]-1],sa.ht[id[i]]);
}
int main(){
  scanf("%d", &n); scanf("%s", sa.str+1); sa.n=strlen(sa.str+1); sa.getSA(); sa.getHeight();
  f(i,1,n) scanf("%lld", &a[i]), id[i]=i; sort(id+2, id+n+1, cmp); solve();
  d(i,n,0) ans1[i]+=ans1[i+1], ans2[i]=max(ans2[i], ans2[i+1]);
  f(i,0,n-1) printf("%lld %lld\n", ans1[i], !ans1[i]?0:ans2[i]);
}
// sto wyxkk orz
