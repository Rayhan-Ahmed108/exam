#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int>v(9);
    for(int i = 0; i < 9; i++) {
        cin >> v[i];
    }
    vector<int>hash(9, -1);
    for(int i = 0; i < 9; i++) {
        int ans = v[i]%10;
        if(hash[ans] == -1) {
            hash[ans] = v[i];
        }
        else {
            while(hash[ans] != -1) {
                ans = (ans + 1)%11;
            }
            hash[ans] = v[i];
        }
    }
    for(auto it : hash) {
        cout << it << ' ';
    }
}