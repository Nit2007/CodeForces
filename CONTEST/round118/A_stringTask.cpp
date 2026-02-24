#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long;

void solve(){//118A
    string s;
    cin>>s;
    vector<char>str(s.begin(),s.end());
    set<char>vowels = {'a','e','i','o','u','y'};

    for(char &c:str){
        if(vowels.count(tolower(c)))continue;
        if(isupper(c)){
            c = tolower(c);
        }
        if(!vowels.count(tolower(c))){
            cout<<"."<<(c);
        }
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    { solve();}
}
