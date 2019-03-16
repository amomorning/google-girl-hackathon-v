#pragma once
#include <bits/stdc++.h>
typedef unsigned long long ULL;
typedef std::pair<ULL, std::pair<int, int> > P;

const int N = 3e3 + 10;

struct Node {
	int g, r, t, f;
}map[N][N];

int n, m, k;
int sx, sy;
ULL d[N][N];

std::pair<int, int> pre[N][N];
std::pair<int, int> tmpk[66];

template<class Vector>
bool printPath(const int x, const int y, Vector &path) {
	std::vector<std::pair<int, int> > subPath;
	int tx = x, ty = y;
	while (tx != sx || ty != sy) {
		std::pair<int, int> tmp = pre[tx][ty];
		tx = tmp.first;
		ty = tmp.second;
		subPath.emplace_back(tmp);
	}
	path.emplace_back(subPath);
}

template<class Vector>
bool calcBFS(ULL &s, Vector &path)
{
	std::priority_queue<P, std::vector<P>, std::greater<P> > q;
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j) d[i][j] = 1e15;
	d[sx][sy] = s;
	q.push({ s, {sx, sy} });

	while (!q.empty()) {
		P u = q.top(); q.pop();
		int cx = u.second.first;
		int cy = u.second.second;

		if (map[cx][cy].f) {
			map[cx][cy].f = 0;
			s = d[cx][cy];
			printf("%d %d total = %llu\n", cx, cy, s);
			printPath(cx, cy, path);
			sx = cx, sy = cy;
			return true;
		}

		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) if (dx*dy == 0 && dx != dy) {
				int nx = cx + dx;
				int ny = cy + dy;
				if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
				Node v = map[nx][ny];
				
				ULL tmp = (d[cx][cy] + 30) % (v.g + v.r);
				tmp = v.g - tmp;
				if (tmp >= v.t) tmp = v.t;
				else tmp += v.r + v.t;

				if (d[nx][ny] <= d[cx][cy] + tmp + 30) continue;

				pre[nx][ny] = { cx, cy };
				d[nx][ny] = d[cx][cy] + tmp + 30;
				q.push({ d[nx][ny], {nx, ny} });
			}
		}
	}
	return false;
}


template<class T>
inline void getInt(T &x) {
	char c; bool sign = false;
	for (c = getchar(); c < '0' || c > '9'; c = getchar()) if (c == '-') sign = true;
	for (x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
	sign && (x = -x);
}

void readData(const char * filename) {
	
	freopen(filename, "r", stdin);
	freopen("./data/out_0.txt", "w", stdout);
	getInt(n); getInt(m);
	getInt(sx); getInt(sy);
	getInt(k);
	
	printf("%d %d\n", n, m);
	for (int i = 0; i < k; ++i) {
		int u, v;
		getInt(u); getInt(v);
		tmpk[i] = { u, v };
	}

	for (int i = 0; i < n*m; ++i) {
		int u, v, g, r, t;
		getInt(u); getInt(v);
		getInt(g); getInt(r); getInt(t);
		map[u][v] = { g, r, t, 0 };
	}

	for (int i = 0; i < k; ++i) {
		int u = tmpk[i].first;
		int v = tmpk[i].second;
		map[u][v].f = 1;
	}
	
}

template<class T, class Vector>
bool getPath(const char * filename, T &total, Vector & path)
{
	clock_t t = clock();
	readData(filename);
	int tx = sx, ty = sy;
	
	for (int i = 0; i < k; ++i) {
		calcBFS(total, path);
	}
	puts("ok");
	map[tx][ty].f = 1;
	calcBFS(total, path);
	
	tx = pre[sx][sy].first;
	ty = pre[sx][sy].second;
	total = d[tx][ty] + 30;

	std::vector<std::pair<int, int> > last;
	last.push_back({ sx, sy });
	path.emplace_back(last);

	std::cout << "total time used: ";
	std::cout << (double)(clock() - t) / CLOCKS_PER_SEC << " seconds." << std::endl;
	return true;
}



