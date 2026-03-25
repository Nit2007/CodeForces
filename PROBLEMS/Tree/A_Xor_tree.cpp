#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//429A
        int n;cin>>n;
        vector<vector<int>>graph(n+1,vector<int>(0));
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>init = readVector<int>(n);
        vector<int>goal = readVector<int>(n);

        vector<int>ans(0);
        dfs(1,-1,0,graph,ans,init,goal,0,0);

        cout<<ans.size();
        for(int i:ans){N();cout<<i;}
    }
    void dfs(int current,int parent,int depth,vector<vector<int>>&graph
        ,vector<int>&ans,vector<int>&init,vector<int>&goal,int flip_even,int flip_odd){
            
        int intial = init[current-1];
        //Apply flips from the ancestors
        if(depth%2 == 0)intial ^= flip_even;
        else intial ^= flip_odd;
        //If misMatch , add it to the answer ,update the flips
        if(intial != goal[current-1]){
            ans.push_back(current);
            if(depth%2 == 0)flip_even ^= 1;
            else flip_odd  ^= 1;            
        }//Go deeper of the childrens and explore more
        for(int neighbour : graph[current]){
            if(neighbour == parent)continue;
            dfs(neighbour,current,depth+1,graph,ans,init,goal,flip_even,flip_odd);
        }
    }

    int run() {
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