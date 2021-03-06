#include <cstdio>
long long f[50][50][50][50];
int p[50][50],x[50][50];
int main() {
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++)
      scanf("%1d",&x[i][j]);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      p[i][j] = 0;
      for(int k = j; k >= 1 && x[i][k]==0; k--) p[i][j]++;
    }
  }
  for(int a = 1; a <= n; a++) {
    for(int b = 1; b <= m; b++) {
      for(int c = a; c <= n; c++) {
        for(int d = b; d <= m; d++) {
          f[a][b][c][d] = f[a][b][c][d-1] + f[a][b][c-1][d]-
            f[a][b][c-1][d-1];
          long long w = d - b + 1;
          for(int i = c; i >= a; i--) {
            if(p[i][d] < w) w = p[i][d];
            f[a][b][c][d] += w;
          }
        }
      }
    }
  }
  while(q--) {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%I64d\n",f[a][b][c][d]);
  }
  return 0;
}

