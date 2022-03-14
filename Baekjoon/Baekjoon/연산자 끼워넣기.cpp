#include<iostream>
using namespace std;

int MAX = -1000000000; 
int MIN = 1000000000; 

int Operator[4]; 
int num[11]; 
int N;

void dfs(int result, int count) {
	if (count == N - 1) {
		if (MIN > result) {
			MIN = result;
		}
		if (MAX < result) {
			MAX = result;
		}
		return; 
	}

	for (int i = 0; i < 4; i++) {
		if (Operator[i] != 0) {
			Operator[i]--; 
			if (i == 0) {
				dfs(result + num[count + 1], count + 1);
			}
			else if (i == 1) {
				dfs(result - num[count + 1], count + 1);
			}
			else if (i == 2) {
				dfs(result * num[count + 1], count + 1);
			}
			else if (i == 3) {
				dfs(result / num[count + 1], count + 1);
			}
			Operator[i]++; 
		}
	}
}

int main(){
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++){
		cin >> Operator[i];
	}

	dfs(num[0], 0); 

	cout << MAX << "\n" << MIN<<'\n';
	return 0; 
}