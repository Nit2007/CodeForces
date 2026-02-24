#include <bits/stdc++.h>
using namespace std;

int main() {
    int w; 
    cin >> w;
    if (w > 2 && w % 2 == 0) cout << "YES"; //Can be divided
    else cout << "NO"; //Odd no ,or {0,1,2}
    return 0;
}
