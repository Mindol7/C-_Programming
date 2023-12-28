#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, m;
    int i, j, k;
    cin>>n>>m;
    int baguni[n];
    memset(baguni, 0, n);
    for(int a = 0; a < m; a++){
        cin>>i>>j>>k;
        for(i; i<=j; i++){
            baguni[i] = k;
        }
    }
    for(int i = 0; i<n; i++){
        cout<<baguni[i]<<" ";
    }
    cout<<endl;
    return 0;
}