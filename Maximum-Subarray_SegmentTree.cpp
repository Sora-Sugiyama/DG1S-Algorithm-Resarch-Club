#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct MSASEG{
    struct Data{
        ll sum,pref,suff,ans;
        Data(){}
        Data(ll sum,ll pref,ll suff,ll ans):sum(sum),pref(pref),suff(suff),ans(ans){}
    }seg[400003];
    ll st=131072;
    Data g(Data a,Data b){
        Data ret;
        ret.pref=max(a.pref,a.sum+b.pref);
        ret.suff=max(a.suff+b.sum,b.suff);
        ret.sum=a.sum+b.sum;
        ret.ans=max({a.suff+b.pref,a.ans,b.ans});
        return ret;
    }
    void upd(ll w,ll pos){
        pos=pos+st-1;
        seg[pos]=Data(w,w,w,w);
        while(pos>>=1)seg[pos]=g(seg[pos*2],seg[pos*2+1]);
    }
    Data ST(int S,int E,int s,int e,int pos){
        if(S>e||s>E)return Data(0,-1e18,-1e18,-1e18);
        if(S<=s&&e<=E)return seg[pos];
        return g(ST(S,E,s,(s+e)/2,pos*2),ST(S,E,(s+e)/2+1,e,pos*2+1));
    }
    ll MSA(int S,int E){
        return ST(S,E,1,st,1).ans;
    }
}SEG;
