#include <bits/stdc++.h>

using namespace std;

int r, c, k; 
vector<int> row[205]; 
vector<int> col[205]; 
int rlen, clen; 

void del() {
	// 100이상인 경우 버리기 
	for (int i = 0; i < rlen; i++) {
		if (row[i].size() > 100) {
			row[i].resize(100);
		}
	}

	// 100이상인 경우 버리기 
	for (int i = 0; i < clen; i++) {
		if(col[i].size() > 100){
			col[i].resize(100);
		}
	}
}

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) {
		return true; 
	}
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return false; 
	}
	
}

void sort_first(char ch , int idx, vector<int>& arr, int& len1, int& len2 ) {
	map<int, int> mp; // 숫자, 등장횟수 
	vector<int> v = arr; // 정렬해야 할 벡터 

	for (int i = 0; i < v.size(); i++) {
		if (v[i]) {
			mp[v[i]]++;
		}
	}

	//정렬 
	vector<pair<int, int>> temp(mp.begin(), mp.end()); 
	sort(temp.begin(), temp.end(), comp); 

	// 정렬 후 배열에 값 넣기 
	arr.clear();
	for (int i = 0; i < temp.size(); i++) {
		int num = temp[i].first; 
		int cnt = temp[i].second;
		arr.push_back(num);
		arr.push_back(cnt);
	}

	// 배열의 길이가 달라졌다면 나머지 0 추가
	len1 = max((int)arr.size(),len1);

	if (ch == 'R') {
		for (int i = 0; i < len2; i++) {
			int up = len1 - row[i].size(); 
			while((up--) > 0){
				row[i].push_back(0);
			}
		}
	}
	else {
		for (int i = 0; i < len2; i++) {
			int up = len1 - col[i].size();
			while ((up--) > 0) {
				col[i].push_back(0);
			}
		}
	}
}

void reCol() {
	for (int i = 0; i < rlen; i++) {
		for (int j = 0; j < clen; j++) {
			col[j].push_back(row[i][j]); 
		}
	}
}

void reRow() {
	for (int i = 0; i < clen; i++) {
		for (int j = 0; j < rlen; j++) {
			row[j].push_back(col[i][j]);
		}
	}
}

void solve() {
	//R연산
	if (rlen >= clen) {
		memset(col, 0, sizeof(col));
		for (int i = 0; i < rlen; i++) {
			sort_first('R', i, row[i], clen, rlen);
		}
		reCol();
		del();
	}
	else {//C연산
		memset(row, 0, sizeof(row));
		for (int i = 0; i < clen; i++) {
			sort_first('C', i, col[i], rlen, clen);
		}
		reRow();
		del();
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	rlen = 3, clen = 3; 
	cin >> r >> c >> k; 
	r--, c--; 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x;
			cin >> x; 
			row[i].push_back(x); 
			col[j].push_back(x); 
		}
	}

	int ans = 0; 
	while( (row[r].size() <= c )|| (row[r].size() > c && row[r][c] != k)) {
		ans++; 
		solve(); 
		if (ans > 100) {
			cout << "-1" << '\n';
			return 0; 
		}
	}
	
	cout << ans << '\n'; 
	return 0; 
}
