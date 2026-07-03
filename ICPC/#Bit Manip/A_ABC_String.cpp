#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1494/A*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        string s;cin>>s;
        vector<bool>opens ;
        vector<bool>ans;
        opens = {1,1,0}; ans.push_back(check(s,opens));
        opens = {1,0,1}; ans.push_back(check(s,opens));
        opens = {0,1,1}; ans.push_back(check(s,opens));

        opens = {0,0,1}; ans.push_back(check(s,opens));
        opens = {0,1,0}; ans.push_back(check(s,opens));
        opens = {1,0,0}; ans.push_back(check(s,opens));
        sort(ans.begin(),ans.end());
        if(*(ans.end()-1)){
            cout<<"YES";
        } 
        else{
            cout<<"NO";
        }
        N();
    }
    bool check(string s,vector<bool>opens){
        map<char,int> charVal = {{'A', 0} , {'B',1} , {'C',2}} ;
        int bal = 0;
        for(char x:s){
            if(opens[charVal[x]]){
                bal++;
            }else{
                bal--;
            }
            if(bal < 0){return false;}
        }
        if(bal != 0){return false;}
        return true;
    }


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve(); }
        return 0;
    }

    


    template<typename T>
    void PRINT(const vector<T>& v){
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }

    template<typename T>
    void PRINTS(const string& s,const vector<T>& v){
        cout<<s<<" : ";
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }
    void N(){cout<<"\n";}
    void ND(){cout<<"---DEBUG___";cout<<"\n";}
    template<typename... Args>
    void debugPrint(const string& raw, Args&&... args){
        vector<string> keys;
        stringstream ss(raw);
        string tok;
        while(getline(ss, tok, ',')){
            while(!tok.empty() && tok.front()==' ') tok.erase(tok.begin());
            while(!tok.empty() && tok.back() ==' ') tok.pop_back();
            keys.push_back(tok);
        }
        int i=0;
        cout << " [DEBUG] ";
        ([&](auto&& arg){ cout << keys[i++] << " : " << arg << "  |  "; }(args), ...);
        cout << "\n";
    }

    template<typename T>
    vector<T> readVector(int n){
        vector<T> v((unsigned int)n);
        for(auto &x : v) cin >> x;
        return v;
    }
    template<typename T>
    vector<T> makeUnique(vector<T>& v){
        unordered_set<T>seen;
        vector<T>unique;
        for(auto &x:v){
            if(seen.insert(x).second)unique.push_back(x);
        }return unique;
    }
};

signed main(){
    Main OBJ;
    return OBJ.run();
}
