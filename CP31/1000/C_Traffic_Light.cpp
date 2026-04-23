#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1744C
        int n;cin>>n;
        char current;cin>>current;
        string s; cin>>s;

        s += s; //Solve the problem of Cyclicity
        vector<int>nextGreen(n,-1);
        int last = 1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == 'g'){
                nextGreen[i%n] = 0;
                last = 1;
            }else {
                nextGreen[i%n] = last;
                last++;
            }
        }
        // PRINT(nextGreen);
        int cross = INT_MIN;
        //Track the furthest green , as we want the worst case scenario 
        for(int i=0;i<n;i++){
            if(current == s[i]){
                cross = max(cross,nextGreen[i]);
            }
        }
        cout<<cross;N();
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
