#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//2218F
        int x_even,y_odd;
        cin>>x_even>>y_odd;

        int rootSize = (x_even + y_odd);
        if(rootSize%2 == 0 && x_even == 0){
            cout<<"NO\n";return;
        }
        if(rootSize%2 == 1 && y_odd == 0){
            cout<<"NO\n";return;
        }

        if(x_even > y_odd){//Every Even_sized Node is going to contain at least one Odd_sized Node (or more)
            cout<<"NO\n";return;
        }

        cout<<"YES\n";
        int chain = 2 * x_even + (y_odd - x_even)%2;//Fill the Even first , so we have x Evens and x Odds ,
        //still we want (y-x) Odds,attach the remaining nodes to the last Node
        for(int i=2;i<=chain;i++){
            cout<<i-1<<" "<<i;N();
        }
        for(int i=chain+1;i<=rootSize;i++){
            cout<<chain<<" "<<i;N();
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
