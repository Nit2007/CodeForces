#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//1807D
        int n,q;cin>>n>>q;
        vector<int>nums = readVector<int>(n);
        int l,r,k;
        vector<int>countOfOdds(n+1,0);
        for(int i=0;i<n;i++){
            if(nums[i] %2 == 1){
                countOfOdds[i+1] = countOfOdds[i] + 1;
            }else{
                countOfOdds[i+1] = countOfOdds[i] ;
            }
        }
        // PRINT(countOfOdds);
        while(q--){
            cin>>l>>r>>k;
            int leftOdds = countOfOdds[l-1];
            int rightOdds = countOfOdds[r];
            int windowOdds = rightOdds - leftOdds;

            int totalOdds = countOfOdds[n];
            int outsideWindow = totalOdds - windowOdds;
            int windowSize = r-l+1;

            int kcontribution = (k%2);
            int currentOdds = outsideWindow + (windowSize) * (kcontribution);
            if(currentOdds%2 == 1){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
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