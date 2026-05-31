#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1690D
        int n,k;cin>>n>>k;
        string s;cin>>s;
        vector<int>w(n+1,0);
        for(int i=1;i<=n;i++){
            w[i] = w[i-1] + int((s[i-1] == 'W')? 1 : 0);
        }
        // PRINT(w);
        int paint = INT_MAX;
        for(int r=k;r<=n;r++){
            int l = r-k;
            paint = min(paint,w[r]-w[l]);
        }
        cout<<paint;N();
        //Try all segments of length k (as we want only consecutive segs)
    }
    // void solve(){//1690D
    //     int n,k;cin>>n>>k;
    //     string s;cin>>s;
    //     int maxi = 0 , seg = 1;
    //     for(int i=1;i<n;i++){
    //         if(s[i-1] == s[i] && s[i-1] == 'B'){
    //             seg++;
    //             maxi = max(maxi,seg);
    //         }else{
    //             seg = 1;
    //         }
    //     }  
    //     maxi = max(maxi,seg);
    //     if(maxi >= k){
    //         cout<<0;N();return;  
    //     } 
    //     int Black = count(s.begin(),s.end(),'B');
    //     int White = n - Black;
    //     if(n == k){
    //         cout<<White;N();return;  
    //     }
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
