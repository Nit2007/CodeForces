#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1904B
        int n;cin>>n;
        vector<ll>nums = readVector<ll>(n);

        vector<pair<ll,int>>vi(0);
        for(int i=0;i<n;i++){
            pair<ll,int>x = make_pair(nums[i],i);
            vi.push_back(x);
        }
        sort(vi.begin(),vi.end());
        vector<ll>prefixSum(n+1,0);
        prefixSum[0] = vi[0].first;
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + vi[i].first ;
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){//Find the Largest element in nums ,such that it is smaller than pS[i] 
            int j = i;
            int elements = i;
            while(j<n){
                pair<ll,int>x = make_pair(prefixSum[j]+1,INT_MIN);
                auto it = lower_bound(vi.begin(),vi.end(),x);
                int idx = it - vi.begin();
                idx--;
                if(idx == j)break;
                elements = idx;
                j = idx;
            }
            ans[vi[i].second] = elements;
        }
        PRINT(ans);
    }
    int BinSearch(int l,int r,vector<ll>&prefixSum,int value){
        int m = 0;
        int best = 0;
        while(l<=r){
            m = (l+r)/2;
            if(prefixSum[m] >= value){
                r = m-1;
                best = m;
            }
            else{
                l = m+1;
            }
        }
        return best;
    }

    //     val = 20
    //     ind = 4 
    //     1 2 4 5 20 
    //   0 1 3 7 12 32





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

int main(){
    Main OBJ;
    return OBJ.run();
}
