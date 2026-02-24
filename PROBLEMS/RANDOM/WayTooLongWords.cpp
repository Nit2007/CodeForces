#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//71A
    string word;
    cin>>word;
    int n=word.length();
    if(n > 10){
        n -= 2;
        string w="";
        w+=word[0];
        w += to_string(n);
        w += word[n+1];
        cout<<w<<endl;
    }else{
        cout<<word<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
