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
bool printPath(Vector &path) {

}

bool calcBFS(ULL &s) {
	std::priority_queue<P, std::vector<P>, std::greater<P> > q;
	memset(d, 0x3f, sizeof(d));
	d[sx][sy] = s;
	q.push({ s, {sx, sy} });

	while (!q.empty()) {
		P u = q.top(); q.pop();
		int cx = u.second.first;
		int cy = u.second.second;

		if (map[cx][cy].f) {
			map[cx][cy].f = 0;
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

template<class T, class Vector>
bool getPath(const char * filename, T total, Vector & path)
{
	std::ifstream is(filename, std::ios::binary);
	if(is) readData(is);
	else return false;
	int tx = sx, ty = sy;
	
	total = 0;
	for (int i = 0; i < k; ++i) {
		calcBFS(total);
		printPath(path);
	}
	
	map[tx][ty].f = 1;
	if (!calcBFS(total)) return false;
	if (!printPath(path)) return false;

	return true;
}

template<class IS>
void readData(IS &in) {
}

