#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1831B
        int n;cin>>n;
        vector<int>a = readVector<int>(n);
        vector<int>b = readVector<int>(n);

        map<int,int>long_subarray_a = compute(a);
        map<int,int>long_subarray_b = compute(b);

        int maxOfBoth = 1;
        for(auto m:long_subarray_a){
            maxOfBoth = max(maxOfBoth , m.second + long_subarray_b[m.first]);
        }
        for(auto m:long_subarray_b){
            maxOfBoth = max(maxOfBoth , m.second + long_subarray_a[m.first]);
        }
        cout<<maxOfBoth;N();
        // for(auto m:long_subarray_a){cout<<m.first<<" "<<m.second;N();}
    }
// 3 3 2 2 2 2 1 1 
// 3 2 1 1 1 2 8 8 
    map<int,int> compute(vector<int>&a){
        int n = a.size();
        map<int,int>long_subarray_a;
        int temp = 1;
        long_subarray_a[a[0]] = temp;
        for(int i=1;i<n;i++){
            if(a[i-1] == a[i]){
                temp ++;
            }else temp = 1;
            long_subarray_a[a[i]] = max(temp,long_subarray_a[a[i]]);
        }
        return long_subarray_a;
    }



    int run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ /*cout<<z;ND();*/  solve();}
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
