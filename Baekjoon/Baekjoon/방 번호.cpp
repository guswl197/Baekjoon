#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>

using namespace std;

int n, Max, idx; 
vector<int> v;
vector<int> number(10); 

int main(){ 
    cin>>n;
    while(n!=0){
        int num = n%10;
        n/=10;   
        if(num==6 || num==9){
            if(number[6] < number[9]){
                number[6]++; 
            }
            else{
                number[9]++;
            }
        }
        else{
            number[num]++; 
        }
    }

    cout<<*max_element(number.begin(), number.end())<<'\n';

    return 0; 
}
