#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//2244E
        int n,e;cin>>n>>e;
        vector<vector<int>>graph(n+1,vector<int>(n+1,0));
        for(int i=0;i<e;i++){
            int u,v,w;
            cin>>u>>v>>w;
            // v--;u--;
            graph[u][v] = w;
            graph[v][u] = w;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distance(n+1,INT_MAX);
        distance[0] = 0;

        pq.emplace(0,1);
        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(int i=0;i<n;i++){
                if(graph[u][i] == 0)continue;
                if(distance[u] + graph[u][i] < distance[i]){
                    distance[i] = distance[u] + graph[u][i];
                    pq.emplace(distance[i],i);
                }
            }

        }
        for(int i=2;i<distance.size();i++){
            cout<<distance[i];N();
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
