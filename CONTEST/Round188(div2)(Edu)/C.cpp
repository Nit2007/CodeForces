#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    static void solve(){//2204C
        ll a,b,c;cin>>a>>b>>c;
        ll m;cin>>m;
        ll two = lcm(lcm(a,b),c);
        ll ab = lcm(a,b);
        ll bc = lcm(b,c);
        ll ca = lcm(c,a);

        ll A=0,B=0,C=0;
        A += 6*(m/a);
        B += 6*(m/b);
        C += 6*(m/c);

        A -= 3*(m/ab);
        A -= 3*(m/ca);
        A += 2*(m/two);

        B -= 3*(m/ab);
        B -= 3*(m/bc);
        B += 2*(m/two);

        C -= 3*(m/bc);
        C -= 3*(m/ca);
        C += 2*(m/two);


        cout<<A<<" "<<B<<" "<<C;N();
    }
    // static void solve(){//2204C
    //     int a,b,c;cin>>a>>b>>c;
    //     ll m;cin>>m;
    //     ll two = lcm(lcm(a,b),c);
    //     ll ab = lcm(a,b);
    //     ll bc = lcm(b,c);
    //     ll ca = lcm(c,a);

    //     ll A=0,B=0,C=0;
    //     A += 2*(m%two);
    //     B += 2*(m%two);
    //     C += 2*(m%two);

    //     A += 3*(m%ab);
    //     B += 3*(m%bc);
    //     C += 3*(m%ca);

    //     A += 3*(m%ca);
    //     B += 3*(m%ab);
    //     C += 3*(m%bc);

    //     ll total = A + B + C ; 
    //     ll rem = (m*6) - total;

    //     A+=rem;
    //     B+=rem;
    //     C+=rem;

    //     cout<<A<<" "<<B<<" "<<C;N();
    // }

    static int run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
        return 0;
    }
    


    template<typename T>
    static void PRINT(const vector<T>& v){
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }

    template<typename T>
    static void PRINTS(const string& s,const vector<T>& v){
        cout<<s<<" : ";
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }
    static void N(){cout<<endl;}
};

int main(){
    return Main::run();
}