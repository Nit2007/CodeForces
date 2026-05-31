#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1704C    
        int n,m;cin>>n>>m;
        vector<int>virus = readVector<int>(m);
        sort(virus.begin(),virus.end());
        vector<int>gaps(0);
        gaps.push_back(n - (virus[m-1]) + (virus[0]) -1);
        for(int i=1;i<m;++i){
            gaps.push_back(virus[i]-virus[i-1] -1);
        }
        sort(gaps.begin(),gaps.end(),greater<int>());
        int days = 0;
        int saved = 0;
        for(auto&G:gaps){//Trying to save something would shrink all segements by 2
            int current = G - (2*2*days);//LR contributes each one | save 1 ->shrinks Rest of the gaps
            if(current <= 0)continue;
            if(current == 1)saved++;
            if(current >= 2)saved += current-1 ;
            days+=1;
        }
        int infected = n-saved;
        cout<<infected;N();
    }
    // void solve(){//1704C    
    //     int n,m;cin>>n>>m;
    //     vector<int>virus = readVector<int>(m);
    //     sort(virus.begin(),virus.end());
    //     int infected = m;
    //     vector<int>l(m,0),r(m,0);
    //     l[0] = n - (virus[m-1]) + (virus[0]);
    //     for(int i=1;i<m;++i){
    //         l[i] = virus[i] - virus[i-1];
    //     }
    //     for(int i=0;i<m-1;++i){
    //         r[i] = l[i+1];
    //     }
    //     r[m-1] = l[0];
    //     //Seal the Largest l,r
    //     //Increment the infection
    //     //Sealing could lead to NO_INFECTION & Stopage of infection -> then make the l,r value 0
    //     while(true){

    //     }
    // }


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
        return 0;
    }

// 1 {2} 3 4 {5} 6 


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
