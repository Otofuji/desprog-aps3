#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t) {
  if (fscanf(file, "%d", p) != 1) {
    fprintf(stderr, "erro ao ler string do teste %d\n", t);
  }

  char c;
  do {
    c = getc(file);
  } while (c != '\n');

  fgets(s, *p + 1, file);
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {

  int c, d;

  if (n == 0 || m == 0) {
    length[n][m] = 0;
    
    }

  else if (a[n-1] == b[m-1]) {

    if (length[n-1][m-1] == -1) {
      length[n][m] = mlcs_w(a, n-1, b, m-1, length) + 1;
    }

    else {
      length[n][m] = length[n-1][m-1] + 1;
    }
  
  }

  else {
    if (length[n-1][m] == -1) {c = mlcs_w(a, n-1, b, m, length);}
    else {c = length[n-1][m];}
    if (length[n][m-1] == -1) {d = mlcs_w(a, n, b, m-1, length);}
    else {d = length[n][m-1];}

    if (c >= d) {length[n][m] = c;}
    else        {length[n][m] = d;}
  }
  return length[n][m];
}

int mlcs(char a[], int n, char b[], int m) {
  int ni, mi, length[MAX_SIZE+1][MAX_SIZE+1];
  for (ni = 0; ni <= n; ni++){
    for (mi = 0; mi <= m; mi++){
      length[ni][mi] = -1;
    }
  }
  return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m) {

  return 2;
}
