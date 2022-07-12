#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int stu; 
int arr[101]; 
vector<pair<int,int>> student;

void boySolve(int num){
    int k=1; 
    for(int i=num; i<=n ; i=num*(++k)){
        for(int j=1; j<=n ;j++){
            if(j == i){
                arr[j]= abs(arr[j]-1); 
            }
        }
    }
}

void girlSolve(int num){
    int left=num, right=num; 
    
    while(1){
        left-=1;  
        right+=1; 
        if(left<=0 || right > n || arr[left] != arr[right]){
            left+=1; 
            right-=1;
            break; 
        }
    }

    for(int i= left; i<= right ; i++){
           arr[i]= abs(arr[i]-1); 
    }
}

void switchs(){
    for(int i=0; i< stu; i++){
        if(student[i].first ==1 ){ //남학생
            boySolve(student[i].second); 
        }
        else{ //여학생
            girlSolve(student[i].second); 
        }
    } 
}

int main(){
    cin>>n; 
    for(int i=1 ; i<=n ; i++){
        cin>>arr[i]; 
    }

    cin>>stu; 
    for(int i=0; i<stu ; i++){
        int a, b;
        cin>>a>>b;
        student.push_back({a,b}); 
    }

    switchs(); 

    int j=0; 
    for(int i=1; i<=n ; i++){
        cout<< arr[i]<<' ';
        j++; 
        if(j==20){
            cout<<'\n';
            j=0; 
        }
    }
    return 0; 
}
