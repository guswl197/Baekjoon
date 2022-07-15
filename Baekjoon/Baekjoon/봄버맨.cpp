#include <iostream>

using namespace std;

int r,c,n; 
int time;
int arr[201][201]; 
int dx[]={1,-1 ,0, 0}; 
int dy[]= {0,0,1,-1 }; 

void bomb(){
    for(int i=0 ; i<r; i++){
        for(int j=0; j<c ; j++){
            if(arr[i][j] ==0){
                for(int k=0; k< 4; k++){
                    int nx = i + dx[k]; 
                    int ny= j + dy[k]; 
                    if(nx< 0 || nx>=r || ny<0 || ny>=c){
                        continue; 
                    }
                    if(arr[nx][ny]!=0){
                        arr[nx][ny]=-1; 
                    }
                }
            }
        }
    }
}

void timeSub(){
    for(int i=0 ; i<r ; i++){
        for(int j=0; j<c ; j++){
            if(arr[i][j]>0){
                arr[i][j]--; 
            }
        }
    }
}

void timePlus(){
     for(int i=0 ; i<r ; i++){
        for(int j=0; j<c ; j++){
            if(arr[i][j]==0){
                arr[i][j]=3; 
            }
        }
    }
}

bool check(){
     if(time == n){
        return true; 
    }
    return false;
}

void zero(){
    for(int i=0 ; i<r ; i++){
        for(int j=0; j<c ; j++){
            if(arr[i][j]==-1){
                arr[i][j]=0; 
            }
        }
    }
}
void sol(){

    time++;
    timeSub(); 
        
    if(check()){
        return; 
    }

    while(1){
    
        //full
        timeSub(); 
        timePlus(); 
        time++;  

        if(check()){
            return; 
        }

        timeSub(); 
        bomb(); 
        zero(); 
        time++; 

        if(check()){
            return; 
        }
    }
}

int main(){
    cin>>r>>c>>n;
    for(int i=0 ;i<r ; i++){
        for(int j=0 ; j<c ; j++){
            char c; 
            cin >>c; 
            if(c =='O'){
                arr[i][j]= 3; 
            }
        }
    } 

    sol(); 

    for(int i=0; i<r ; i++){
        for(int j=0; j< c; j++){
            if(arr[i][j]>0){
                cout<<'O';
            }
            else{
                 cout<<'.';
            }               
        }
        cout<<'\n';
    }
 
    return 0; 
}
