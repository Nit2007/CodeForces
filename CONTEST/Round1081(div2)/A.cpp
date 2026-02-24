#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

int score(string s){
    int Score = 1;
    int i=1;
    while(i<s.length()){
        if(s[i-1] != s[i])Score++;
        i++;
    }
    return Score;
}

void solve(){//2192A
    int n;cin>>n;
    string s;
    cin>>s;
    int i=0;
    while(s.front() != s.back() && i<=s.length()){
        char last = s.back();
        s.pop_back();
        s = last + s;
        i++;
    }
    cout<<score(s)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
