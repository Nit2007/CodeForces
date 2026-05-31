#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    set<char>V = {'a','e'};
    set<char>C = {'b','c','d'};
    void solve(){//1915D
        int n;cin>>n;
        string s;
        cin>>s;
        int i = n -1;
        string Result="";
        while(i>=0){
            int x;
            if(V.count(s[i])){  x = 2;  }
            if(C.count(s[i])){  x = 3;  }
            while(x--){
                Result += s[i];
                --i;
            }
            Result += ".";
        }
        reverse(Result.begin(),Result.end());
        for(int i=1;i<(int)Result.size();++i){
            cout<<Result[i];
        }N();
    }
    
    // void solve(){//1915D
    //     int n;cin>>n;
    //     string s;
    //     cin>>s;
    //     string build = "",Result = "";
    //     R(s,0,build,Result);
    //     cout<<Result;N();
    // }
    // bool R(string s,int i,string build,string&Result){
    //     if(i == s.length()){
    //         Result = build;
    //         return true;
    //     }
    //     build += s[i];
    //     int b = build.length();
    //     if(build.size() <= 1 || build[b-2] == '.'){
    //         if(R(s,i+1,build,Result))return true;
    //     }else{
    //         bool branched = false;
    //         if(b > 2){  
    //             if(C.count(build[b-3]) && V.count(build[b-2])  && C.count(build[b-1])){
    //                 string temp = build;
    //                 build += ".";
    //                 if(R(s,i+1,build,Result))return true;
    //                 build = temp;
    //                 branched = true;
    //             }
    //             if(C.count(build[b-2])  && V.count(build[b-1])){
    //                 string temp = build;
    //                 build += ".";
    //                 if(R(s,i+1,build,Result))return true;
    //                 build = temp;
    //                 branched = true;
    //             }
    //         }
    //         if(!branched){
    //             if(R(s,i+1,build,Result))return true;
    //         }
    //     }
    //     return false;
    // }

    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
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
