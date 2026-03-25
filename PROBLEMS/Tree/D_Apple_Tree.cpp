#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//1843D
        int n;cin>>n;
        vector<vector<int>>graph(n+1,vector<int>(0));
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>leafCount(n+1,0);
        dfs_leafCount(1,-1,graph,leafCount);
        
        int q;cin>>q;
        for(int i=0;i<q;i++){
            int x,y;cin>>x>>y;
            ll leaf_x = leafCount[x];
            ll leaf_y = leafCount[y];
            cout<<(leaf_x * leaf_y) ;N();
        }
    }
    void dfs_leafCount(int current,int parent,vector<vector<int>>&graph,vector<int>&leafCount){
        ll ans = 0;
        for(int neighbour : graph[current]){
            if(neighbour == parent)continue;
            dfs_leafCount(neighbour,current,graph,leafCount);
            ans += leafCount[neighbour];
        }
        if(ans == 0){leafCount[current] =  1;return;}//No child => Leaf
        leafCount[current] =  ans;
    }
    //Without Memo
    // int dfs_leafCount(int current,int parent,vector<vector<int>>&graph){
    //     ll ans = 0;
    //     for(int neighbour : graph[current]){
    //         if(neighbour == parent)continue;
    //         ans += dfs_leafCount(neighbour,current,graph);
    //     }
    //     if(ans == 0)return 1;//No child => Leaf
    //     return ans;
    // }

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
        vector<T> v(n);
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