#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//1904A
        int a,b,xk,yk,xq,yq;
        cin>>a>>b;
        cin>>xk>>yk>>xq>>yq;
        vector<pair<int,int>>kingsq;
        vector<pair<int,int>>queensq;
        vector<int>dirx = {+a,+a,+b,+b,-a,-a,-b,-b};
        vector<int>diry = {+b,-b,+a,-a,+b,-b,+a,-a};
        map<pair<int,int>,bool>seen;
        for(int i=0;i<8;i++){
            if(a == b){
                if(seen.count(make_pair(dirx[i],diry[i])) > 0){
                    continue;
                }
            }
            kingsq.push_back(make_pair(xk+dirx[i],yk+diry[i]));
            queensq.push_back(make_pair(xq+dirx[i],yq+diry[i]));
            seen[make_pair(dirx[i],diry[i])] = true;
        }
        map<pair<int,int>,int>freq;
        for(pair<int,int>sq : kingsq){freq[sq]++;}
        for(pair<int,int>sq : queensq){freq[sq]++;}
        int forks = 0;
        for(auto x:freq){
            pair<int,int>sq = x.first;
            int count = x.second;
            // cout << "(" << sq.first << ", " << sq.second << ") - Count: " << count << endl;
            if(count > 1){
                forks++;
            }
        }
        cout<<forks;N();
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