#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int ttoi(string time) {
	int t = 0; 
	string h, m; 

	h = time.substr(0, 2); 
	m = time.substr(3, 2); 
	t = (60 * stoi(h)) + stoi(m);
	return t; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int cnt = 0; 
	string	S, E, Q;
	cin >> S >> E >> Q; 

	int st_t, end_t, stream_t; 
	st_t = ttoi(S); 
	end_t = ttoi(E);
	stream_t = ttoi(Q);

	unordered_set<string> st_list;  // 시작 전에 입장한 학회원들
	unordered_set<string> atd_list; // 최종 출석자 리스트 

	while (1) {
		string c_time, name; 
		cin >> c_time >> name;
		if (cin.eof() == true) {
			break;
		}

		if (ttoi(c_time) <= st_t) {
			st_list.insert(name); 
		}
		else if (ttoi(c_time) >= end_t && ttoi(c_time) <= stream_t) {
			if (st_list.find(name) != st_list.end()) {
				atd_list.insert(name); 
			}
		}
	}

	cout << atd_list.size() << '\n';
	return 0; 
}
