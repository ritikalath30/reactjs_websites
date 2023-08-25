#include <stdio.h>
int adj[10][10]={0},visited[10]={0},d[10]={0},c[10]={0},n;
void prims(int node)
{
    int i;
    visited[node]=1;
    for(i=1;i<=n;i++)
    {
        if(adj[node][i]==1 && visited[i]==0)

    }
}
int main()
{
    int e,i,v1,v2,node;
    printf("Enter no.of nodes\n");
    scanf("%d",&n);
    printf("Enter no.of edges\n");
    scanf("%d",&e);
    printf("Enter edge details\n");
    for(i=1;i<=e;i++)
    {
        printf("Enter edge\n");
        scanf("%d %d",&v1,&v2)
    }
}