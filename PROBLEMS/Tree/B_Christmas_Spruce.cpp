#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//913B
        int n;cin>>n;
        vector<vector<int>>graph(n+1,vector<int>(0));
        for(int i=2;i<=n;i++){
            int parent;
            cin>>parent;
            graph[parent].push_back(i);
        }
        // for(auto x:graph)PRINT(x);
        bool valid = true;
        for(vector<int>vertex : graph){
            if(vertex.size() == 0)continue;//Pick Non_Leaf
            int leaf = 0;
            for(int neighbours : vertex){
                if(graph[neighbours].size() == 0)leaf++;
            }
            if(leaf < 3 ){
                valid = false;
                break;
            }
        }
        string ans = (valid)? "YES" : "NO";
        cout<<ans;N();
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