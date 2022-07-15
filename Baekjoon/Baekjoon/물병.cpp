#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k; 
int result;

int getNum(int num){
    int cnt=0; 

    while( num> 0){
        if(num %2 ==1){
            cnt++; 
        }
        num/=2;
    }

    return cnt; 
}

int main(){
    cin >> n >> k; 
    int ans=n; 

    while(1){
        if(getNum(ans)<= k){
            break; 
        } 
        else{
            ans+=1; 
        }
    }

    cout<<ans- n<<endl;
    return 0; 
}
