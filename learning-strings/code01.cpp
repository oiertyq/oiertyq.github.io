#include<bits/stdc++.h>
using namespace std;
#define f(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define d(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ri register int
#define ll long long
#define il inline
int max(int x, int y) {return x>y?x:y;} int min(int x, int y) {return x<y?x:y;}
struct SA{
  #define _ 1000005
  const char chr='a';
  char str[_];
  int n, m, rk[_], sa[_], tax[_], tp[_], ht[_];
  void sort() { f(i,0,m) tax[i]=0; f(i,1,n) ++tax[rk[i]]; f(i,1,m) tax[i]+=tax[i-1]; d(i,n,1) sa[tax[rk[tp[i]]]--]=tp[i]; }
  void getSA() {
    m=256; f(i,1,n) rk[i]=str[i]-chr+1, tp[i]=i;
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
  #undef _
} sa ;
long long ans;
int main(){
  scanf("%d", &sa.n); scanf("%s", sa.str+1); sa.getSA(); sa.getHeight(); ans=1LL*sa.n*(sa.n+1)/2;
  f(i,1,sa.n) ans-=sa.ht[i]; printf("%lld\n", ans);
  return 0;
}
// sto wyxkk orz
