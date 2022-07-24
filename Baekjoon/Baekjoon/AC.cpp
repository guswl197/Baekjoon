#include <bits/stdc++.h>

using namespace std;

int t;
string command; 
string arr; 
int n; 
bool flag = true; 
bool front = true; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t; 
	while (t--) {
		deque<int> dq;
		int num;

		front = true; 
		flag = true; 
		cin >> command;
		cin >> n; 
		cin >> arr; 

		for (int i = 0; i < arr.size(); i++) {
			if ('0' > arr[i] || arr[i] > '9') {
				arr[i] = ' ';
			}
		}

		stringstream stream;
		stream.str(arr); 
		while (stream >> num) {
			dq.push_back(num); 
		}

		for (int i = 0; i<command.size(); i++) {
			if (command[i] == 'R') {
				if (front == true) {
					front = false;
				}
				else {
					front = true;
				}
			}
			else { //D
				if (!dq.empty()) {
					if (front == true) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					} 
				}
				else {
					cout << "error" << '\n'; 
					flag = false; 
					break; 
				}
			}
		}

		if (flag == true) {
			cout << '[';
			if (!dq.empty()){
				if (front == true) {
					for (int i = 0; i < dq.size() - 1; i++) {
						cout << dq[i] << ",";
					}
					cout << dq[dq.size() - 1];
				}
				else {
					for (int i = dq.size() - 1; i>0; i--) {
						cout << dq[i] << ",";
					}
					cout << dq[0];
				}
			}
			cout<<']' << '\n';
		}
	}
	return 0; 
}

