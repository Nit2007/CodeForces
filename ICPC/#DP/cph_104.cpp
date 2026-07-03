#include <bits/stdc++.h> /*$url$*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n,limit;cin>>n>>limit;
        vector<int>weight ;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            weight.push_back(x);
        }
        ll ans = INT_MAX;
        pair<int,int>best [1<<n]; //Rides : filled weight in current ride
        best[0] = {1,0}; //Empty Ride : No weight
        for(int combo=1;combo<(1<<n);combo++){
            best[combo] = {n+1,0} ;
            for(int bit=0;bit<n;bit++){
                if(combo & (1<<bit)){
                    // 1011 comes from {1010,1001,0011} + new Person
                    auto option = best[combo^(1<<bit)];
                    if(option.second + weight[bit] <= limit){
                        option.second += weight[bit];
                    }else {
                        option.first++; //Book a new Ride
                        option.second = weight[bit];
                    }
                    best[combo] = min(best[combo],option);
                }
            }
        }
        ans = best[(1<<n)-1].first;
        cout<<ans;N();
    }
    /*
    10 15
    2 5 4 7 1 3 8 6 9 10
    */


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z=1;
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
