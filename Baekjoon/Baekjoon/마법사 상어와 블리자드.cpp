#include <iostream>
#include <vector>
#include <cstring>

#define MAX 55
using namespace std;

struct COORD
{
	int x;
	int y;
};

int n, m, marble[4];
int board[MAX][MAX];
int number[MAX][MAX];
bool Delete[MAX * MAX];
COORD Shark;
COORD Coord[MAX * MAX];
vector<pair<int, int>> ds;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
// »ó ÇÏ ÁÂ ¿ì

int Change_Dir(int dir)
{
	if (dir == 1) return 3;
	if (dir == 2) return 4;
	if (dir == 3) return 2;
	if (dir == 4) return 1;
}

void makeMap(){
	int x = n / 2;
	int y = n / 2;
	int cnt = 1;
	int num = 0;
	int dir = 3;

	Shark = { x , y };
	number[x][y] = num;
	Coord[num++] = { x , y };
	while (1)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < cnt; j++)
			{
				x += dx[dir];
				y += dy[dir];
				number[x][y] = num;
				Coord[num++] = { x , y };
			}
			dir = Change_Dir(dir);
		}
		cnt++;

		if (cnt == n)
		{
			for (int j = 0; j < cnt; j++)
			{
				x += dx[dir];
				y += dy[dir];
				number[x][y] = num;
				Coord[num++] = { x , y };
			}
			break;
		}
	}
}

void IceRemove(int Idx)
{
	memset(Delete, false, sizeof(Delete));
	int dir = ds[Idx].first;
	int k = ds[Idx].second;

	int x = Shark.x;
	int y = Shark.y;
	for (int i = 0; i < k; i++)
	{
		x += dx[dir];
		y += dy[dir];
		Delete[number[x][y]] = true;
	}
}

void moveMarble()
{
	bool flag = false;
	int cnt = 0;
	for (int i = 1; i < n * n; i++)
	{
		if (Delete[i] == true)
		{
			flag = true;
			cnt++;
		}
		else
		{
			if (board[Coord[i].x][Coord[i].y] == 0)
			{
				for (int j = 1; j <= cnt; j++) board[Coord[i - j].x][Coord[i - j].y] = 0;
				flag = false;
				break;
			}
			else board[Coord[i - cnt].x][Coord[i - cnt].y] = board[Coord[i].x][Coord[i].y];
		}
	}

	if (flag == true)
	{
		int i = (n * n) - 1;
		for (int j = 0; j < cnt; j++, i--) board[Coord[i].x][Coord[i].y] = 0;
	}
}

bool destroyMarble()
{
	memset(Delete, false, sizeof(Delete));

	bool flag = false;
	int cur = board[Coord[1].x][Coord[1].y];
	int cnt = 1;
	int start = 1;
	int num;
	for (num = 2; num < n * n; num++)
	{
		int next = board[Coord[num].x][Coord[num].y];
		if (next == 0) break;

		if (cur == next) cnt++;
		else
		{
			if (cnt >= 4)
			{
				flag = true;
				for (int i = start; i < num; i++) Delete[i] = true;
				marble[cur] += cnt;
			}

			cur = next;
			cnt = 1;
			start = num;
		}
	}

	if (cnt >= 4)
	{
		flag = true;
		for (int i = start; i < num; i++) Delete[i] = true;
		marble[cur] += cnt;
	}
	return flag;
}

void remakeMap()
{
	int newMap[MAX][MAX] = { 0, };
	int cur = board[Coord[1].x][Coord[1].y];
	int cnt = 1;
	int pos = 1;
	bool flag = true;
	for (int num = 2; num < n *n; num++)
	{
		if (pos >= n * n)
		{
			flag = false;
			break;
		}

		int next = board[Coord[num].x][Coord[num].y];
		if (next == 0) break;
		if (cur == next) cnt++;
		else
		{
			newMap[Coord[pos].x][Coord[pos].y] = cnt;
			newMap[Coord[pos + 1].x][Coord[pos + 1].y] = cur;
			cur = next;
			cnt = 1;
			pos += 2;
		}
	}
	if (flag == true) //¸ÊÀÌ ²Ë Â÷ÀÖ´Â °æ¿ì
	{
		if (pos != 1)
		{
			newMap[Coord[pos].x][Coord[pos].y] = cnt;
			newMap[Coord[pos + 1].x][Coord[pos + 1].y] = cur;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = newMap[i][j];
		}
	}
}

int main(void)
{
	cin >> n >>m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		ds.push_back(make_pair(a, b));
	}
	
	//sol
	makeMap();
	for (int i = 0; i < m; i++)
	{
		IceRemove(i);
		moveMarble();

		while (1)
		{
			if (destroyMarble() == false) break;
			moveMarble();
		}
		remakeMap();
	}

	cout << marble[1] + (2 * marble[2]) + (3 * marble[3]) << endl;

	return 0;
}
