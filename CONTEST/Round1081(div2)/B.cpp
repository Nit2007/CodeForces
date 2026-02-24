#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int;

void solve(){//2192B
    int n;cin>>n;
    string s;
    cin>>s;

    int c0 = count(s.begin(),s.end(),'0');
    int c1 = n - c0;
    //Flipping a bit : Even{No Change} , Odd {Change}
    // c0 even(ODD) c1 odd       => -1
    // c0 even      c1 even(ODD) => print 1s
    // c0 odd(EVEN) c1 even(ODD) => print 0s1s{either works}
    // c0 odd(EVEN) c1 odd       => print 0s

    if( (c0 % 2) ){
        cout<<c0<<endl;
        for(int i=0;i<n;i++){
            if(s[i] == '0')cout<<i+1<<" ";
        }cout<<endl;
    }
    else if((c1%2) == 0){
        cout<<c1<<endl;
        if(c1 != 0){
            for(int  i=0;i<n;i++){
                if(s[i] == '1')cout<<i+1<<" ";
            }cout<<endl;
        }
    }else{
        cout<<-1<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}


// (1)010
//  11(0)1
//  0000

// 100
// 011 000

//  1000
//  0011

//  10(1)01
//  0111(0)
//  1000(0)

// #include <bits/stdc++.h>
// using namespace std;//AUTHOR : NITHISH JAISARUN
// using ll = long long;

// void solve(){//2192B
//     int n;cin>>n;
//     string s;
//     cin>>s;

//     int ones = count(s.begin(),s.end(),'1');
//     if(ones%2 != 0){//Odd
//         cout<<-1<<endl;
//         return ;
//     }
    
//     int zeros = n-ones;
//     if(zeros == 1){
//         cout<<1<<endl<<s.find('0')+1<<endl;
//         return ;
//     }
//     cout<<ones<<endl;
//     for(int i=0;i<s.length();i++){
//         if(s[i] == '1'){
//             cout<<i+1<<" ";
//         }
//     }
//     if(ones != 0)cout<<endl;
// }
// int main() {
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);
//     int z;cin>>z;
//     while(z--){ solve();}
// }


// // (1)010
// //  11(0)1
// //  0000

// // 100
// // 011 000

// //  1000
// //  0011

// //  10(1)01
// //  0111(0)
// //  1000(0)

