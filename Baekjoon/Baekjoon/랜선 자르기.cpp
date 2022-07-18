#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k; 
long long sum,ans, result; 
vector<long long> vk; 

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        long long x;
        cin>>x;
        vk.push_back(x); 
    }
    
    long long start= 1;
    long long end = *max_element(vk.begin(), vk.end()); 

    while(start <= end){
        long long mid= (start + end)/2; 
        sum = 0; 

        for(int i=0 ; i<vk.size(); i++){
            sum+= vk[i]/mid; 
        }

        if(sum >= k){
           start = mid+1; 
            if(ans<mid){
             ans= mid; 
            }
        }
        else if(sum < k){
            end= mid-1; 
        }
    }

    cout<<ans<<'\n'; 
    return 0; 
}
