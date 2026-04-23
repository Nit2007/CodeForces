#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1832C
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);

        vector<int>u(1,nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i-1] == nums[i])continue;
            u.push_back(nums[i]);
        }
#define U ((int)u.size())
        if(U == 1){
            cout<<1;N();return;
        }

        
        int need=0;
        for(int i=0;i<U;i++){
            if(i == 0 || i == U-1 || (u[i-1] > u[i]) == (u[i] < u[i+1]) ){//If flucations ,then that is neeeded
                need++;
            }
        }
        cout<<need;N();
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
    vector<T> makeuque(vector<T>& v){
        unordered_set<T>seen;
        vector<T>uque;
        for(auto &x:v){
            if(seen.insert(x).second)uque.push_back(x);
        }return uque;
    }
};

int main(){
    Main OBJ;
    return OBJ.run();
}
