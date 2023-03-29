#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("rosalind_ini.txt","r",stdin);
    freopen("rosalind_out.txt","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;cin>>s;
    int A=0,G=0,T=0,C=0;
    for(char x:s){
        if(x=='A')A++;
        if(x=='G')G++;
        if(x=='T')T++;
        if(x=='C')C++;
    }
    cout<<A<<" "<<C<<" "<<G<<" "<<T;
    return 0;
}
