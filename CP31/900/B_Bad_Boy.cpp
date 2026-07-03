#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1537/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n,m,i,j;cin>>n>>m>>i>>j;
        vector<pair<int,int>> corners = {{1,1},{n,1},{1,m},{n,m}} ;
        vector<pair<int,int>> indexDist(4);

        for(int c=0;c<corners.size();c++){
            indexDist[c] = {dist(i,j,corners[c].first,corners[c].second),c};
        }
        map<int,int>opp = {{0,3},{3,0},{1,2},{2,1}};
        sort(indexDist.begin(),indexDist.end());
        cout<<corners[indexDist[3].second].first << " "<<corners[indexDist[3].second].second<<" ";
        cout<<corners[indexDist[opp[3]].second].first << " "<<corners[indexDist[opp[3]].second].second;N();
    }
    int dist(int i,int j,int x,int y){
        return abs(i-x) + abs(j-y);
    }


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
