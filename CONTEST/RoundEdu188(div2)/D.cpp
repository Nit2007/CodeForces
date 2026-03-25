#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//2204D
        int n,m;cin>>n>>m;
        vector<vector<int>>graph(n+1,vector<int>(0));
        for(int i=0;i<m;i++){
            int v1,v2;
            cin>>v1>>v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }//Its an undirected graph , try dfs over all unvisited nodes to look for the alternating vertices
        vector<int>color(n+1,-1);
        int dir = 0;
        ll beautiful = 0;
        for(int i=1;i<=n;i++){
            bool valid = true;
            vector<int>cnt = {0,0};
            if(color[i] == -1){//Unvisited Node => new component found => DFS to 2-color it => IF(valid) bipartite => add larger{either IN | OUT} part to answer
                dfs(i,graph,dir,color,valid,cnt);
                if(valid){
                    beautiful += max(cnt[0],cnt[1]);
                }
            }
        }
        cout<<beautiful;N();
    }
    void dfs(int current,vector<vector<int>>&graph,int dir,vector<int>&color,bool&valid,vector<int>&cnt){
        if(color[current] != -1 )return;//!valid - condition gives WA because we want to explore all neighburs of a particular chord
        color[current] = dir;       //Color the Node , with alternating colors at each depth
        cnt[dir]++;                 //Increment at appropriate Biparitite

        for(int neighbour:graph[current]){
            if(color[neighbour] == color[current]){ //Ugly Node => Invalid
                valid = false;
            }
            if(color[neighbour] == -1){  //Not visited , Flip the dir => recurse deeper to evauate the correctness of the whole subGraph 
                dfs(neighbour,graph,dir^1,color,valid,cnt);
            }
        }
    }

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

int main(){//upsolved
    Main OBJ;
    return OBJ.run();
}