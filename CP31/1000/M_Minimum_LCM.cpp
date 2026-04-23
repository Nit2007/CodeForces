#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1765M
        ll n;cin>>n;
        
        ll A = 1 , B = n-1 ;
        for(ll a = 2;a*a<=n;a++){
            if(n%a == 0){
                A = n/a ; //This yields max_A
                break;
            }
        }
        if(A != 1){
            B = n - A;
        }
        cout<<A<<" "<<B;N();
        // b%a != 0 :
        //     a,b  -> lcm(a,b) = a * b
        //     min value of a is 2 (as 1 divides b)
        //     hence we can say that lcm(a,b) >= 2b = ab ...a[2.....n]
        // b%a == 0 : 
        //     a,b  -> lcm(a,b)
        //     a,af -> lcm(a,af) = af = b
        // n%a : 
        //     (a+b)%a
        //     ( (a%a) + (b%a) + (a) ) % a
        //     if(b%a == 0)
        //         then we can say that if a divides b ,then a also divides n
        // By looking at these observations ,we can infer that divisors are going to be the least lcm
        // when thinking of , divisors is going to yield b , Hence we want a min B -> max A which is divisor of n

        
    }
    //TLE at TestCase 3
    // void solve(){//1765M
    //     int n;cin>>n;
        
    //     int mini = lcm(1,n-1);
    //     int A=1,B=n-1;
    //     for(int a=1;a<=n/2 ;a++){
    //         int b = n-a;
    //         if(mini > lcm(a,b)){
    //             A = a;
    //             B = b;
    //             mini = lcm(a,b);
    //         }
    //     }
    //     cout<<A<<" "<<B;N();
    // }





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
