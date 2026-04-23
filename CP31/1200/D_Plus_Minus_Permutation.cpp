#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    ll SUM(ll start, ll end){
        return (end - start + 1) * (start + end) / 2;
    }
    void solve(){//1872D
        ll n,x,y;cin>>n>>x>>y;
        
        ll common = lcm(x,y);
        ll xRep = (n/x) - (n/common);
        ll yRep = (n/y) - (n/common);
        ll xContribution = SUM(n-xRep+1,n); 
        // cout<<xContribution;ND();
        ll yContribution = SUM(1LL,yRep) ; 
        // cout<<yContribution;ND();
        ll ans = xContribution - yContribution ;
        cout<<ans<<endl;
    }
    //Potential TLE
    // ll maxi = n;
    // ll mini = 1;
    // ll ans = 0;
    // for(ll i=1;i<=n;i++){
    //     if(i%x == 0 && i%y == 0){
    //         continue;
    //     }
    //     if(i%x == 0){
    //         ans += (maxi--);
    //     }
    //     if(i%y == 0){
    //         ans -= (mini++);
    //     }
    // }
    // cout<<ans;N();

    //Assuming nonIndependent x and y on array 
    // int common = lcm(x,y);
    // int xRep = n/x;
    // int yRep = n/y;
    // ll xContribution = (n* (n+1))/2 - ((n-xRep)* (n-xRep+1))/2;
    // // cout<<xContribution;ND();
    // ll yContribution = (n* (n+1))/2 - ((n-yRep)* (n-yRep+1))/2;
    // // cout<<yContribution;ND();
    // ll ans = xContribution - yContribution ;
    // cout<<ans<<endl;





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
