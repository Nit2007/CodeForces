#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//270A
        int angle;cin>>angle;
        bool valid = true;

        if(angle < 0 || angle >= 180)valid = false;

        int sides = 360 / (180 - angle);
        int possible = 360 % (180 - angle);
        if(sides < 3 || possible != 0)valid = false;

        cout<<((valid)? "YES" : "NO");N();
    }
    // Sum(intangle) = (sides - 2) * 180;
    // angle * sides = (sides - 2) * 180; {Regular_Polygon}
    // angle * sides = 180 sides - 360; 
    // angle * sides + 360 = 180 sides
    // 360 = 180 sides - (angle * sides )
    // 360 = sides (180 - angle)
    // sides = 360 / (180 - angle)
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