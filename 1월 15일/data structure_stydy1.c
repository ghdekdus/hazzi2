#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX     10
#define EDGEMAX 20
#define UNDEF   -1
#define INF     9999

struct edge {
	int s;
	int d;
	int w;
}e[EDGEMAX];

int d[MAX];
int pre[MAX];

int bellmanford(int, int, int);
void relax(struct edge);

int main(void)
{
	int t, tc;
	int i;
	int from, to;
	int vc, ec, s;

	freopen("input.txt", "r", stdin);

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		// input the number of vertices
		// and the position of starting point.
		scanf("%d%d", &vc, &s);

		// input the number of edges.
		scanf("%d", &ec);

		for (i = 0; i < ec; i++)
		{
			// input each vertices that you want to input the weight.
			// input the weight between S.P and D.
			scanf("%d%d", &from, &to);

			e[i].s = from - 1;
			e[i].d = to - 1;

			scanf("%d", &e[i].w);
		}

		// if have detected error.
		if (bellmanford(s - 1, vc, ec))
		{
			printf("Error occured. Negative edge weight cycles detected\n");
		}

		for (i = 0; i < vc; i++)
		{
			printf("Vertex %d. %d\n", i + 1, d[i]);
		}
	}


	return 0;
}

/*
Bellmanford algorithm
It is similar to Dijkstra.
there is some differences.
- this algorithm can find negative.
but it is slower than Dijkstra.
*/
int bellmanford(int s, int vc, int ec)
{
	int i, j;

	// initialize the distances and previous routes.
	for (i = 0; i < vc; i++)
	{
		d[i] = INF;
		pre[i] = UNDEF;
	}

	// set the distance of starting point.
	d[s] = 0;

	// repeat as much as the number of vertices.
	for (i = 0; i < vc - 1; i++)
	{
		// examine all edges.
		for (j = 0; j < ec; j++)
		{
			relax(e[j]);
		}
	}

	// to detect negative cycles,
	// examine all edges again.
	for (i = 0; i < ec; i++)
	{
		// if error occur.
		if (d[e[i].d] > d[e[i].s] + e[i].w)
		{
			return -1;
		}
	}

	return 0;
}

/*
relax( int, int)
this function updates distances between U and V.
*/
void relax(struct edge v)
{
	// if current distance is bigger than new distance.
	if (d[v.d] > d[v.s] + v.w)
	{
		d[v.d] = d[v.s] + v.w;

		pre[v.d] = v.s;
	}
}