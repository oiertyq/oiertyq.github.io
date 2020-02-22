#include<bits/stdc++.h>
using namespace std;
#define f(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define d(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ri register int
#define ll long long
#define il inline
#define _ 400005
long long ans;
int max(int x, int y) {return x>y?x:y;} int min(int x, int y) {return x<y?x:y;}
struct SA{
  const char chr='a';
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
  void init(char* str) {
    this->n = strlen(str+1); for(int i=1; i<=this->n; ++i) this->str[i]=str[i]; memset(rk, 0, sizeof(rk)); memset(sa, 0, sizeof(sa)); memset(tax, 0, sizeof(tax)); memset(tp, 0, sizeof(tp)); memset(ht, 0, sizeof(ht)); this->getSA(); this->getHeight();
  }
} ;
namespace solve {
  int f[_]; SA sa;
  void sol(char* str, int flg) {
    sa.init(str); memset(f, 0, sizeof(f)); stack<int> S; long long sum=0;
    f(i,2,sa.n) {
      while(!S.empty() && sa.ht[S.top()]>=sa.ht[i]) S.pop();
      if(S.empty()) f[i] = sa.ht[i]*(i-1); else f[i] = f[S.top()]+sa.ht[i]*(i-S.top());
      S.push(i); sum+=f[i];
    }
    ans += flg*sum;
  }
} ;
char str1[_], str2[_], str3[_];
int main(){
  scanf("%s", str1+1); scanf("%s", str2+1);
  for(int i=1, len=strlen(str1+1); i<=len;++i) str3[i]=str1[i]; str3[strlen(str1+1)+1] = 'z'+1;
  for(int i=strlen(str1+1)+2, len=i+strlen(str2+1); i<=len; ++i) str3[i]=str2[i-strlen(str1+1)-1];
  solve::sol(str3, 1); solve::sol(str1, -1); solve::sol(str2, -1);
  printf("%lld\n", ans);
  return 0;
}
// sto wyxkk orz
