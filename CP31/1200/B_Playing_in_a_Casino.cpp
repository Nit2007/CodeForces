#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1808B
        ll n,m;cin>>n>>m;
        vector<vector<ll>>playerCard(0);
        for(ll v=0;v<n;v++){
            vector<ll>nums = readVector<ll>(m);
            playerCard.push_back(nums);
        }
        vector<vector<ll>>cardPlayer(m,vector<ll>(n,0));
        for(ll v=0;v<n;v++){
            for(ll i=0;i<m;i++){
                cardPlayer[i][v] = playerCard[v][i];
            }//Each col is dependent only on the col elements 
        }
        for(auto &x:cardPlayer){
            sort(x.begin(),x.end());
        }//As the elements are sorted ,consider a row i,the elements are [a0...aj...am] here the
        // jth element has contributed to all of its preceding element j elements  ,Subract the rem diff of small contributors
        ll ans = 0;
        for(ll i=0;i<m;i++){
            ll prefixSum = 0;
            for(ll j=0;j<n;j++){
                ans += abs(cardPlayer[i][j]*j - prefixSum);
                prefixSum += cardPlayer[i][j];
            }
        }
       cout<<ans;N();
    }
    
    // vector<vector<int>>prefixRow(0);
    // for(int i=0;i<=n;i++){
    //     if(i==0){
    //         vector<int> row(m,0);
    //         prefixRow.push_back(row);
    //     }else{
    //         vector<int>prev = prefixRow[i-1];
    //         vector<int>curr = playerCard[i-1];
    //         for(int j=0;j<prev.size();j++){
    //             curr[j] += prev[j];
    //         }
    //         prefixRow.push_back(curr);
    //     }
    // }
    // for(auto v:prefixRow){PRINT(v);}




    int run() {
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

int main(){
    Main OBJ;
    return OBJ.run();
}
