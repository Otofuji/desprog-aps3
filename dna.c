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
  int lcs = 0;

  if (n == 0 || m == 0) {
    length[n-1][m-1] = 0;
    return 0;
    }

  if (a[n-2] == b[m-2]) {
    if (length[n-2][m-2] == -1) {
      length[n-2][m-2] = mlcs_w(a, n-1, b, m-1, length) + 1;
      lcs = length[n-2][m-2];
    }
  }

  else {
    if (length[n-2][m-1] >= length[n-1][m-2]) {
      return length[n-2][m-1];
    }
    else {
      return length[n-1][m-2];
    }
  }
  return lcs;
}

int mlcs(char a[], int n, char b[], int m) {
  int ni, mi, length[n][m];
  for (ni = 0; ni < n; ni++){
    for (mi = 0; mi < m; mi++){
      length[ni][mi] = -1;
    }
  }
  return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m) {

  return 2
}
