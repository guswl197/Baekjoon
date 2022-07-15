#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m; 
vector<int> v; 

int main(){
    cin>>n>>m;

    for(int i=0; i<n ; i++){
        int x; 
        cin>>x;
        v.push_back(x); 
    }

    int start,end,mid,result=0; 
    start=0, end= *max_element(v.begin(), v.end()); 

    while(start <= end){
        mid=(start+end)/2; 
        long long total=0; 

        for(int i=0; i<n; i++){
            if(v[i] > mid){
                total+= v[i]- mid; 
            }
        }

        if(total < m){
            end= mid-1; 
        }
        else{
            result= mid; 
            start= mid+1; 
        }
    }

    cout<<result<<endl;
    return 0; 
}
