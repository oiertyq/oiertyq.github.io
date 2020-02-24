#include<bits/stdc++.h>
using namespace std; /*Copyright [tyqtyq](http://oiertyq.github.io). All rights served.*/
#define f(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define d(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ri register int
#define ll long long
#define il inline
namespace intio{char ch; int read(){ ri x=0,f=1; while(!isdigit((ch=getchar()))) f=ch=='- '?-1:1; while(isdigit(ch)) x=x*10+ch-'0', ch=getchar(); return x*f; } void read(int& x) {x = read();}}; using namespace intio;
int max(int x, int y) {return x>y?x:y;} int min(int x, int y) {return x<y?x:y;}
#define _ 100005
int c[_], n, k;
typedef struct wyxkkakioi {
  int a[5], b, num;
} ani;
ani x[_];
int Mx[(1<<4)], S[_][(1<<4)], f[(1<<4)];
int a, b, ans=-0x3f3f3f3f, up;
int cmp(ani x, ani y){ return x.b<y.b; }
int main(){
  scanf("%d%d", &n, &k); up=(1<<4)-1;
  f(i,1,k) scanf("%d", &c[i]);
  f(i,1,n) {
    f(j,1,k-1) scanf("%d", &x[i].a[j]), x[i].a[j]*=c[j];
    scanf("%d", &x[i].b), x[i].b*=c[k];
    x[i].num=i;
  }
  sort(x+1, x+n+1, cmp);
  f(i,1,n) f(U,0,up) f(l,0,3) S[i][U]+=(U&(1<<l))?x[i].a[l+1]:-x[i].a[l+1];
  f(U,0,up) Mx[U]=S[1][U]+x[1].b, f[U]=x[1].num;
  f(i,2,n) {
    f(U,0,up) {
      int newans=Mx[U^up]+S[i][U]-x[i].b;
      if(newans > ans) ans=newans, a=f[U^up], b=x[i].num;
    }
    f(U,0,up) if(Mx[U]<S[i][U]+x[i].b) Mx[U]=S[i][U]+x[i].b, f[U]=x[i].num;
  }
  printf("%d %d\n%d\n", a, b, ans);
  return 0;
}
// sto wyxkk orz
