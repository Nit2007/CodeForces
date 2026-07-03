#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//2230B
        string s;
        cin>>s;
        int n = s.length();
        ll four = count(s.begin(),s.end(),'4');
        ll  two = 0 , one = 0 ,three = 0;
        ll  prev = 0 ;
        for(int i=0;i<n;++i){
            char c = s[i];
            if(c == '4')continue;
            else if(c == '1'){
                one++;
            }        
            else if(c == '3'){
                three++;
            }  
            else if(c == '2'){
                two++;
                prev = min(prev+1 , one+three);
            }        
        }        
        cout<<four + prev ;N();     
    }
    // void solve(){//2230B
    //     string s;
    //     cin>>s;
    //     int n = s.length();
    //     ll four = count(s.begin(),s.end(),'4');
    //     ll two = 0 , one = 0 ,three = 0;
    //     ll invalid_2 = 0 , invalid_13 = 0;
    //     for(int i=0;i<n;++i){
    //         char c = s[i];
    //         if(c == '4')continue;
    //         else if(c == '1'){
    //             one++;
    //         }        
    //         else if(c == '3'){
    //             three++;
    //         }  
    //         else if(c == '2'){
    //             two++;
    //             if(max(one,three) > 0){
    //                 invalid_2++;
    //             }
    //         }        
    //     }        
    //     two = 0 , one = 0 ,three = 0;
    //     for(int i=n-1;i>=0;--i){
    //         char c = s[i];
    //         if(c == '4')continue;
    //         else if(c == '1'){
    //             one++;
    //             if(two > 0){
    //                 invalid_13++;
    //                 two--;
    //             }
    //         }        
    //         else if(c == '3'){
    //             three++;
    //             if(two > 0){
    //                 invalid_13++;
    //                 two--;
    //             }
    //         }  
    //         else if(c == '2'){
    //             two++;
    //         }        
    //     }   
    //     // P(invalid_13,invalid_2);
    //     cout<<four + min(invalid_13,invalid_2);N();     
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
