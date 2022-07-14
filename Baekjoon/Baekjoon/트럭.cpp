#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[1001]; 
int n, w, l; 
int total, time; 
queue<int> q; 

int main(){
    cin>>n>>w>>l; 
    for(int i=0; i< n ; i++){
        cin>>arr[i]; 
    }

    for(int i=0; i<n ; i++){
        while(1){
            if(q.size() == w){
                total-= q.front();
                q.pop();  
            }
            else{
                if(total + arr[i] <=l){
                    q.push(arr[i]); 
                    total+= arr[i]; 
                    time++; 
                    break; 
                }
                else{
                    q.push(0); 
                    time++; 
                }
            }
        }
    }

    cout<<time + w<<'\n';
    return 0; 
}
