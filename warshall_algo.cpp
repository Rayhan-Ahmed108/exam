#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    
    vector<vector<int> >v(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            in >> v[i][j];
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                v[i][j] |= (v[i][k] & v[k][j]); 
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            out << v[i][j] << ' ';
        }
        out << endl;
    }
    in.close();
    out.close();

}
