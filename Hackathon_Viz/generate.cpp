#include <cstring>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <string>

const int N = 50;
const int M = 10;

int vis[N][N];

int main() {
    for(int i = 1; i <= 1; ++ i) {
        std::string filename = "team5_input_" + std::to_string(i); 
        filename += ".txt";
        freopen(filename.c_str(), "w", stdout);

        srand(time(NULL));
        int n = rand() % N + 1;
        int m = rand() % N + 1;
        //n = 3000, m = 3000;
        printf("%d %d\n", n, m); 

        int sx = rand() % n + 1;
        int sy = rand() % m + 1;
        printf("%d %d\n", sx, sy);

        int k = rand() % M + 1;
        //k = 60;
        printf("%d\n", k);

        for(int i = 0; i < k; ++ i) {
            int u = rand() % n + 1;
            int v = rand() % m + 1;
            if(vis[u][v] == 0) {
                printf("%d %d\n", u, v);
                vis[u][v] = 1;
            }
            else k--;
        }

        for(int i = 1; i <= n; ++ i) {
            for(int j = 1; j <= m; ++ j) {
                int g = rand() % 1000 + 5;
                int r = rand() % 1000 + 5;
                int t = rand() % g + 1;
                printf("%d %d %d %d %d\n", i, j, g, r, t);
            }
        }

    }
}
