#include <stdio.h>
#include <stdlib.h>

struct edge_t {
	int src;
	int dest;
};

int main(int argc, char **argv)
{
	int i, j;
	int n = atoi(argv[1]);
	int *perms = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		*(perms + i) = i;
	}
	for (i = 0; i < n; i++) {
		int j = rand() % n;	
		int t = perms[i];
		perms[i] = perms[j];
		perms[j] = t;
	}
	int num_edges = n * (n-1) / 2;
	struct edge_t *edges = malloc(sizeof(struct edge_t) * num_edges);
	unsigned long long k = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i < j) {
				/* *(edges + k) = struct edge { */
				/* 	.src  = perms[i], */
				/* 	.dest = perms[j] */
				/* }; */

				struct edge_t *e = edges + k;
				e->src  = perms[i];
				e->dest = perms[j];
				k++;
			}
		}
	}
	unsigned long long l;
	for (l = 0; l < k; l++) {
		struct edge_t *e = edges + l;
		printf("%d %d\n", e->src, e->dest);
	}

	return 0;
}
