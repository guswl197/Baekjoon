#include <bits/stdc++.h>

using namespace std;

int n,x;
int ans; 
bool check[2000005]; 
int a[1000001]; 

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin>>n; 
    for(int i=0; i<n; i++){
      cin>>a[i]; 
    }

    cin>>x; 

    for(int i=0 ; i< n ; i++){
        if(x-a[i] >0 && check[x-a[i]]){
            ans++;
        }
        check[a[i]]= true;
    }
    
    cout<<ans<<'\n'; 
    return 0; 
}
