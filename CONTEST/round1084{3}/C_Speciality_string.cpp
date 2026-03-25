#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int;
#define PRINT(v) for(int i1=0;i1<(int)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define N cout<<endl; 

void simplify(string s){
    int n = s.length();
    if(n==0){cout<<"YES";N;return;}
    if(n==1){cout<<"NO";N;return;}

    bool tried = false;
    for(int i=1;i<n;i++){
        if(s[i-1] == s[i]){
            s[i-1] = '*';
            s[i]   = '*';
            tried = true;
        }
    }
    if(!tried){cout<<"NO";N;return;}

    string Rem="";
    for(int i=0;i<n;i++){
        if(s[i] == '*')continue;
        Rem.push_back(s[i]);
    }
    simplify(Rem);
}
void solve(){//2200C
    int n;cin>>n;
    string s;cin>>s;
    simplify(s);
}

    // char left='#',right='#';//# - Empty
    // for(int i=0;i<n;i++){
    //     if(s[i] != '*' && left == '#'){
    //         left = s[i];
    //     }
    //     else if(s[i] != '*' && left != '#'){
    //         right = s[i];
    //     }
    //     if(left != '#' && right != '#' && left == right){
    //         left = '#';
    //         right = '#';
    //     }else if(left != '#' && right != '#' && left != right){
    //         cout<<"NO";N
    //         return;
    //     }
    // }
    // if(n<=1){cout<<"NO";N;return;}
    // cout<<"YES";N

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
