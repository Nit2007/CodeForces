#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//1905B
        int n;cin>>n;
        vector<vector<int>>Graph(n+1,vector<int>(0));
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        ll leaf = 0;
        for(vector<int>vertex:Graph){
            if(vertex.size() == 1)leaf++;
        }
        cout<<(leaf+1)/2;N(); // Proof by Induction
        //leaves - operations => [ (leaves+1)/2 ]  --- where [] means round of to smallest INT
        //  1 - 0
        //  2 - 1
        //  3 - 2
        //  4 - 2
        //  5 - 3
        //  6 - 3
    }
//DFS can find leaves in a tree, but only relative to the chosen root ,,,so not suitable , only suitable for Graph
    // ll dfs(int current,int parent,vector<vector<int>>&Graph){
    //     int child = 0;
    //     ll leaf = 0;
    //     for(int neighbour : Graph[current]){
    //         if(neighbour == parent)continue;
    //         child++;
    //         leaf += dfs(neighbour,current,Graph);
    //     }
    //     if(child == 0)return 1;
    //     return leaf;
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