#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/2232/C1*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        ll n,x,s;cin>>n>>x>>s;
        string people;
        cin>>people;
        ll empty = x ;
        ll ans = 0 , buffer = 0 , partial = 0;
        for(ll i=0;i<n;i++){
            auto P = people[i];
            if(P == 'I'){
                if(empty){
                   empty--;
                   partial += s-1;
                   ans++;
                }
            }
            else if(P == 'E'){ 
               if(partial){
                   partial--;
                   ans++;
               }
               else if(buffer && empty && s > 1){
                   empty--;
                   buffer--;
                   partial += s-2;
                   ans += 2;
               }
            }
            else if(P == 'A'){
                buffer++;
            }

            if(buffer > partial && empty){//Ambiverts Overflow, open a new empty Table
                 empty--;
                 buffer--;
                 partial += s-1;
                 ans++;
            }
        }
        ll remSeats = (partial + (1LL * empty * s));
        ans += min(remSeats,buffer);
        cout<<ans;N();
    }
    // void solve(){
    //     int n,x,s;cin>>n>>x>>s;
    //     string people;
    //     cin>>people;
    //     int empty = x ;
    //     int ans = 0;
    //     multiset<int>partial;
    //     for(auto P:people){ //Only empty seats
    //         if(P == 'I'){
    //             if(empty > 0){
    //                 empty--;
    //                 ans++;
    //                 if(s - 1 > 0) partial.insert(s-1);
    //             }
    //         }
    //         else if(P == 'E'){ 
    //             if(partial.size() > 0){ 
    //                 auto last = partial.rbegin();
    //                 int maxi = *last;
    //                 partial.erase(next(last).base());
    //                 ans++;
    //                 if(maxi-1 > 0){
    //                     partial.insert(maxi-1);
    //                 }
    //             }
    //         }
    //         else if(P == 'A'){//Try putting in partial seat Or else use empty seat
    //             if(partial.size() > 0){
    //                 auto last = prev(partial.end());
    //                 int maxi = *last;
    //                 partial.erase(last);
    //                 ans++;
    //                 if(maxi-1 > 0){
    //                     partial.insert(maxi-1);
    //                 }
    //             }
    //             else if(empty > 0){
    //                 empty--;
    //                 ans++;
    //                 if(s - 1 > 0) partial.insert(s-1);
    //             }
    //         }
    //     }
    //     cout<<ans;N();
    // }

    // int R(int i,int empty,int full,string people,multiset<int>&seats){
    //     if(i == people.length()){
    //         return 0;
    //     }
    //     if(empty < 0 || full < 0){
    //         return -1e5;
    //     }
    //     char P = people[i];
    //     if(P == 'I'){
    //         if(empty != 0){
    //             return 1+R(i+1,empty-1,full,people,seats);
    //         }
    //         return R(i+1,empty,full,people,seats);
    //     }else if(P == 'A'){
    //         int use_empty = 1+R(i+1,empty-1,full,people,seats);
    //         int use_full = 1+R(i+1,empty,full-1,people,seats);
    //         int use_ambivert = 0;
    //         if(seats.size() > 0){
    //             int maxi = *seats.rbegin();
    //             auto it = seats.lower_bound(maxi-1);
    //             if(it != seats.end()){
    //                 int curr = *it;
    //                 seats.erase(it);
    //                 seats.insert(curr-1);
    //                 use_ambivert = 1 + R(i + 1, empty, full, people, seats);
    //                 seats.erase(seats.find(curr - 1));
    //                 seats.insert(curr);
    //             }
    //         }
    //         return max({use_ambivert,use_empty,use_full});
    //     }else if(P == 'E'){
    //         if(full != 0){
    //             return 1+R(i+1,empty,full-1,people,seats);
    //         }
    //         return R(i+1,empty,full,people,seats);
    //     }
    //     return  R(i+1,empty,full,people,seats);
    // }

    signed run() {
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

signed main(){
    Main OBJ;
    return OBJ.run();
}
