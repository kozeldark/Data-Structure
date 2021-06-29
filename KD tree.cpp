#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_DIM 3
struct kd_node_t {
	double x[MAX_DIM];
	struct kd_node_t *left, *right;
};

inline double
dist(struct kd_node_t *a, struct kd_node_t *b, int dim)
{
	double t, d = 0;
	while (dim--) {
		t = a->x[dim] - b->x[dim];
		d += t * t;
	}
	return d;
}
inline void swap(struct kd_node_t *x, struct kd_node_t *y) {
	double tmp[MAX_DIM];
	memcpy(tmp, x->x, sizeof(tmp));
	memcpy(x->x, y->x, sizeof(tmp));
	memcpy(y->x, tmp, sizeof(tmp));
}


/* see quickselect method */
struct kd_node_t*
	find_median(struct kd_node_t *start, struct kd_node_t *end, int idx)
{
	if (end <= start) return NULL;
	if (end == start + 1)
		return start;

	struct kd_node_t *p, *store, *md = start + (end - start) / 2;
	double pivot;
	while (1) {
		pivot = md->x[idx];

		swap(md, end - 1);
		for (store = p = start; p < end; p++) {
			if (p->x[idx] < pivot) {
				if (p != store)
					swap(p, store);
				store++;
			}
		}
		swap(store, end - 1);

		/* median has duplicate values */
		if (store->x[idx] == md->x[idx])
			return md;

		if (store > md) end = store;
		else        start = store;
	}
}

struct kd_node_t*
	make_tree(struct kd_node_t *t, int len, int i, int dim)
{
	struct kd_node_t *n;

	if (!len) return 0;

	if ((n = find_median(t, t + len, i))) {
		i = (i + 1) % dim;
		n->left = make_tree(t, n - t, i, dim);
		n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
	}
	return n;
}

/* global variable, so sue me */
int visited;

void nearest(struct kd_node_t *root, struct kd_node_t *nd, int i, int dim, struct kd_node_t **best, double *best_dist)
//본인을 제외한 가장 가까운 포인트를 찾아줄 nearest 함수
{
	double d, dx, dx2;

	if (!root) return;
	d = dist(root, nd, dim);
	dx = root->x[i] - nd->x[i];
	dx2 = dx * dx;

	visited++;

	if (!*best && d != 0)
	{
		*best_dist = d;
		*best = root;
	}

	if (++i >= dim) i = 0;

	nearest(dx > 0 ? root->left : root->left, nd, i, dim, best, best_dist);
	if (dx2 >= *best_dist) return;
	nearest(dx > 0 ? root->right : root->right, nd, i, dim, best, best_dist);
}


void range_search(struct kd_node_t *min, struct kd_node_t *max, struct kd_node_t *root, int Level)//범위 검색을 할 range_search 함수
{
	if (root != NULL)//만약 root가 NULL이 아니면
	{
		if (min->x[0] <= root->x[0] && root->x[0] <= max->x[0] && min->x[1] <= root->x[1] && root->x[1] <= max->x[1])
			//만약 root의 좌표가 min과 max 사이에 있으면
			printf("(%g,%g)\n", root->x[0], root->x[1]);//root의 좌표를 출력한다

		if (min->x[Level] <= root->x[Level])//만약 min의 좌표가 root의 좌표 이하이면
			range_search(min, max, root->left, !Level);//root->left로 이동하여 range_search 함수를 실행한다
		if (max->x[Level] >= root->x[Level])//만약 포인트의 좌표가 root의 좌표 이상이면
			range_search(min, max, root->right, !Level);//root->right로 이동하여 range_search 함수를 실행한다
	}
}

void point_search(struct kd_node_t *point, struct kd_node_t *root, int Level)//원하는 포인트의 여부를 검색할 point_search 함수
{
	if (root != NULL)//만약 root가 NULL이 아니면
	{
		if (point->x[0] == root->x[0] && point->x[1] == root->x[1])//만약 포인트의 좌표가 root의 좌표와 같으면
		{
			int a = root->x[0];
			int b = root->x[1];
			printf("Find (%d,%d)\n", a, b);//root의 좌표를 출력한다
		}

		if (point->x[Level] <= root->x[Level])//만약 포인트의 좌표가 root의 좌표 이하이면
			point_search(point, root->left, !Level);//root->left로 이동하여 point_search 함수를 실행한다
		if (point->x[Level] >= root->x[Level])//만약 포인트의 좌표가 root의 좌표 이상이면
			point_search(point, root->right, !Level);//root->right로 이동하여 point_search 함수를 실행한다
	}

}

void nearest_neighbor_search(struct kd_node_t *root, struct kd_node_t *nd, int i, int dim, struct kd_node_t **best, double *best_dist)
//만약 본인을 제외한 가장 가까운 포인트가 1개보다 많으면 모두를 출력해줄 nearest_neighbor_search 함수 (대칭점의 원리 이용)
{
	struct kd_node_t *original;
	struct kd_node_t *found1;//nearest 함수의 결과값을 받기위해 선언

	found1 = 0;
	double best_d;
	original = nd;


	nearest(root, nd, 0, 2, &found1, &best_d);

	*best = found1;
	*best_dist = best_d;

	double k = (found1->x[0] - original->x[0]) + (found1->x[1] - original->x[1]);

	double a = original->x[0] - (found1->x[0] - original->x[0]) + (found1->x[1] - original->x[1]);
	double b = original->x[1];


	struct kd_node_t point = { { a, b } };

	//대칭점의 원리를 이용하여 최단 거리 이웃이 더 있는지 탐색하여 출력
	if (found1->x[0] > original->x[0] && found1->x[1] > original->x[1])
	{
		a = original->x[0] - (found1->x[0] - original->x[0]);
		b = original->x[1] - (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] + (found1->x[0] - original->x[0]);
		b = original->x[1] - (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] + (found1->x[0] - original->x[0]);
		b = original->x[1] - (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

	}

	else if (found1->x[0] > original->x[0] && found1->x[1] < original->x[1])
	{

		a = original->x[0] - (found1->x[0] - original->x[0]);
		b = original->x[1] - (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] - (found1->x[0] - original->x[0]);
		b = original->x[1] + (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] + (found1->x[0] - original->x[0]);
		b = original->x[1] - (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

	}

	else if (found1->x[0] < original->x[0] && found1->x[1] < original->x[1])
	{

		a = original->x[0] + (found1->x[0] - original->x[0]);
		b = original->x[1] - (found1->x[0] - original->x[0]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] - (found1->x[0] - original->x[0]);
		b = original->x[1] + (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] - (found1->x[0] - original->x[0]);
		b = original->x[1] + (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

	}

	else if (found1->x[0] < original->x[0] && found1->x[1] > original->x[1])
	{
		a = original->x[0] + (found1->x[0] - original->x[0]);
		b = original->x[1] + (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] + (found1->x[0] - original->x[0]);
		b = original->x[1] - (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] + (found1->x[0] - original->x[0]);
		b = original->x[1] + (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

	}

	else if (found1->x[0] == original->x[0] && found1->x[1] < original->x[1])
	{

		a = original->x[0] + (found1->x[1] - original->x[1]);
		b = original->x[1];

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] - (found1->x[1] - original->x[1]);
		b = original->x[1];

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0];
		b = original->x[1] - (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

	}
	else if (found1->x[0] == original->x[0] && found1->x[1] > original->x[1])
	{

		a = original->x[0] - (found1->x[1] - original->x[1]);
		b = original->x[1];

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0] + (found1->x[1] - original->x[1]);
		b = original->x[1];

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0];
		b = original->x[1] - (found1->x[1] - original->x[1]);

		point = { { a, b } };
		(point_search(&point, root, 0));

	}

	else if (found1->x[0] > original->x[0] && found1->x[1] == original->x[1])
	{

		a = original->x[0] - (found1->x[0] - original->x[0]);
		b = original->x[1];

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0];
		b = original->x[1] + (found1->x[0] - original->x[0]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0];
		b = original->x[1] - (found1->x[0] - original->x[0]);

		point = { { a, b } };
		(point_search(&point, root, 0));

	}
	else if (found1->x[0] < original->x[0] && found1->x[1] == original->x[1])
	{

		a = original->x[0] - (found1->x[0] - original->x[0]);
		b = original->x[1];

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0];
		b = original->x[1] - (found1->x[0] - original->x[0]);

		point = { { a, b } };
		(point_search(&point, root, 0));

		a = original->x[0];
		b = original->x[1] + (found1->x[0] - original->x[0]);

		point = { { a, b } };
		(point_search(&point, root, 0));

	}
}
#define N 1000000
#define rand1() (rand() / (double)RAND_MAX)
#define rand_pt(v) { v.x[0] = rand1(); v.x[1] = rand1(); v.x[2] = rand1(); }

int main(void)
{
	int i;
	struct kd_node_t wp[] = {
		{ { 2, 3 } },{ { 5, 4 } },{ { 3, 4 } },{ { 9, 6 } },{ { 4, 7 } },{ { 8, 1 } },{ { 7, 2 } },
	};
	struct kd_node_t testNode = { { 5, 4 } };
	struct kd_node_t testNode2 = { { 4, 7 } };
	struct kd_node_t testNode3 = { { 10, 5 } };
	struct kd_node_t *root, *found, *million;
	double best_dist;

	root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);


	printf("---------Point search---------\n");
	printf("If the results are not printed, the point does not exist in the k-d tree.\n\n");
	printf("Result for search (%g,%g) in K-D tree : ", testNode.x[0], testNode.x[1]);
	(point_search(&testNode, root, 0));

	printf("Result for search (%g,%g) in K-D tree : ", testNode2.x[0], testNode2.x[1]);
	(point_search(&testNode2, root, 0));

	printf("Result for search (%g,%g) in K-D tree : ", testNode3.x[0], testNode3.x[1]);
	(point_search(&testNode3, root, 0));

	printf("\n\n\n");

	struct kd_node_t minNode = { { 6, 3 } };
	struct kd_node_t maxNode = { { 9, 7 } };

	printf("---------Range search---------\n");
	printf("If the results are not printed, the points in the range do not exist in the k-d tree.\n\n");
	printf("Result for range search (%g,%g) ~ (%g,%g) in K-D tree : ", minNode.x[0], minNode.x[1], maxNode.x[0], maxNode.x[1]);
	range_search(&minNode, &maxNode, root, 0);

	printf("\n\n\n");


	printf("---------Nearest neighbor search---------\n");
	visited = 0;
	found = 0;

	nearest_neighbor_search(root, &testNode, 0, 2, &found, &best_dist);

	printf("and found (%g,%g) by searching (%g,%g) for k-d tree.\ndist %g\nseen %d nodes\n\n",
		found->x[0], found->x[1], testNode.x[0], testNode.x[1], sqrt(best_dist), visited);

	nearest_neighbor_search(root, &testNode2, 0, 2, &found, &best_dist);

	printf("and found (%g,%g) by searching (%g,%g) for k-d tree.\ndist %g\nseen %d nodes\n\n",
		found->x[0], found->x[1], testNode2.x[0], testNode2.x[1], sqrt(best_dist), visited);

	printf("\n\n\n");

	system("pause");
	return 0;
}
