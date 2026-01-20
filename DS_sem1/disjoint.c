#include <stdio.h>
struct DisjSet {
int parent[10];
int rank[10];
int n;
} dis;
void makeSet() {
int i;
for (i = 0; i < dis.n; i++) {
dis.parent[i] = i;
dis.rank[i] = 0;
}
}
int find(int x) {
if (dis.parent[x] != x)
dis.parent[x] = find(dis.parent[x]);
return dis.parent[x];
}
void Union(int x, int y) {
int xset, yset;
xset = find(x);
yset = find(y);
if (xset == yset)
return;
if (dis.rank[xset] < dis.rank[yset]) {
dis.parent[xset] = yset;
dis.rank[xset] = -1;
}
else if (dis.rank[xset] > dis.rank[yset]) {
dis.parent[yset] = xset;
dis.rank[yset] = -1;
}
else {
dis.parent[yset] = xset;
dis.rank[xset]++;
dis.rank[yset] = -1;
}
}
void displaySet() {
int i;
printf("\nParent Array: ");
for (i = 0; i < dis.n; i++)
printf("%d ", dis.parent[i]);
printf("\nRank Array: ");
for (i = 0; i < dis.n; i++)
printf("%d ", dis.rank[i]);
printf("\n");
}
int main() {
int ch, x, y, wish;
printf("How many elements? ");
scanf("%d", &dis.n);
makeSet();
do {
printf("\n1.Union\n2.Find\n3.Display\n");
printf("Enter choice: ");
scanf("%d", &ch);if (ch == 1) {
printf("Enter elements: ");
scanf("%d %d", &x, &y);
Union(x, y);
}
else if (ch == 2) {
printf("Enter elements: ");
scanf("%d %d", &x, &y);
if (find(x) == find(y))
printf("Connected components\n");
else
printf("Not connected components\n");
}
else if (ch == 3)
displaySet();
printf("Continue? (1/0): ");
scanf("%d", &wish);
} while (wish == 1);
return 0;
}