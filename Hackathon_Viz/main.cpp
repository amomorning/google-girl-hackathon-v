#include <bits/stdc++.h>

#include "calcBFS.h"
typedef unsigned long long ULL;

int main() {
	std::vector<std::vector<std::pair<int, int> > > path;
	ULL ans = 0;
	std::cout << getPath("./data/in_1.txt", ans, path) << std::endl;
	printf("%llu\n", ans);
	for (auto tmp : path) {
		std::reverse(tmp.begin(), tmp.end());
		for (auto p : tmp) {
			printf("%d %d\n", p.first, p.second);
		}
	}
	system("pause");
}