#include<bits/stdc++.h>
using namespace std; 
int T; long long n, d;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>d; puts(((ceil(sqrt(d)*2)<=n+1)?("YES"):("NO")));
    }
}