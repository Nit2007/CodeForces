#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//2220C -- 100TH problem
        ll p,q;cin>>p>>q;
        
        int N = 2*p + 4*q + 1;
        for(int i=1;i*i<=N;i+=2){
            if(N%i != 0)continue;

            int n = (i-1)/2;
            int m = (N/i-1)/2;
            int hLines = m*(n+1);// (row+1) sized , m lines 
            int vLines = n*(m+1);// (col+1) sized , n lines 
            //q contributes 1 vertical + 1 horizontal
            //If q is more than the grid dimension ,we got too many,cannot form a valid rectangle
            if(q <= hLines && q <= vLines){
                cout<<n<<" "<<m<<endl;
                return;
            }
        }
        cout<<-1<<endl;
    }
    // p + 2q = Vertical_lines + horizontal_lines
    // p + 2q = m(n+1) + n(m+1)
    // p + 2q = 2nm + m + n
    // x = 2nm + m + n
    // 2x + 1 = 4nm + 2m + 2n + 1 = (2n+1)(2m+1)
    // Hence the no of edges factor to two Odd Numbers





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


