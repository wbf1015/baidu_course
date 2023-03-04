#include<bits/stdc++.h>

using namespace std;
typedef long long ll;// ll将表示long long这个数据类型
typedef pair<ll, ll> pii;
map<pii,unsigned long long>m;
ll height[41];

void initHeight(){
    height[0]=1;
    for(int i=1;i<=40;i++){
        height[i]=2+2*height[i-1]+i;
    }
}

unsigned long long getAB(ll a,ll b){
    ll initA=a;
    ll initB=b;
    ll ans=0;
    if(m.count({a,b})){
        return m[{a,b}];
    }
    if(initA==0){
        m[{a,b}]=1;
        return 1;
    }
    initB--;
    if(initB>0){
        ll para=min(height[initA-1],initB);
        initB-=para;
        ans+= getAB(a-1,para);
    }
    if(initB>0){
        ll gold=min(initA,initB);
        initB-=gold;
        ans+=gold;
    }
    if(initB>0){
        ll para=min(height[initA-1],initB);
        initB-=para;
        ans+= getAB(a-1,para);
    }
    initB--;
    m[{a,b}]=ans;
    return ans;
}


int main4( )
{
    initHeight();
    ll a,b;
    cin>>a>>b;
    if(b==0){
        cout<<0<<endl;
        return 0;
    }
    cout<<getAB(a,b)<<endl;
    return 0;
}