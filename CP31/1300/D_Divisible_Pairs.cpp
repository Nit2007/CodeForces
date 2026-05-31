#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1931D
        ll n,x,y;cin>>n>>x>>y;
        vector<ll>nums = readVector<ll>(n);
        //Pairs => (xx,yy) & ((xx-x)%x,yy)
        ll beauty = 0;
        map<pair<ll,ll>,ll>cnt;
        for(int e:nums){
            int xx = e%x , yy = e%y;
            auto TARGET = make_pair((x-xx)%x,yy);
            beauty += (cnt.count(TARGET)) ? cnt[TARGET] : 0;
            cnt[{xx,yy}]++;
        }
        cout<<beauty;N();
    }
    // void solve(){//1931D
    //     ll n,x,y;cin>>n>>x>>y;
    //     vector<ll>nums = readVector<ll>(n);

    //     sort(nums.begin(),nums.end());
    //     map<ll,int>freq;
    //     for(int i:nums){
    //         freq[i]++;
    //     }
    //     vector<ll>uni = makeUnique(nums);
    //     int beauty = 0;
    //     // PRINT(uni);
    //     for(int i:nums){
    //         for(int j:nums){
    //             // if(i == j)continue;
    //             if((i+j)%x == 0 && (i-j)%y == 0){
    //                 // cout<<i<<" "<<j;ND();
    //                 // beauty += freq[i]  * freq[j];
    //                 beauty ++;
    //             }
    //         }
    //     }
    //     cout<<beauty/2;N();
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
