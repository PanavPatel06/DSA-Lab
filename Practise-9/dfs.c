#include<stdio.h>
#include<stdlib.h>

struct node
{
  int vertex;
  struct node *next;
};

struct node *adj[10];
int edges[20][2],visited[10],n,e;

void addEdge(int u,int v)
{
  struct node *newNode=(struct node *)malloc(sizeof(struct node));
  newNode->vertex=v;
  newNode->next=adj[u];
  adj[u]=newNode;
}

void buildAdjList()
{
  int i,u,v;
  for(i=0;i<e;i++)
  {
    u=edges[i][0];
    v=edges[i][1];
    addEdge(u,v);
    addEdge(v,u);
  }
}

void dfs(int v)
{
  struct node *temp;
  visited[v]=1;
  printf("%d ",v);
  temp=adj[v];
  while(temp!=NULL)
  {
    if(visited[temp->vertex]==0)
      dfs(temp->vertex);
    temp=temp->next;
  }
}

int main()
{
  int i,start;
  printf("Enter number of vertices: ");
  scanf("%d",&n);
  printf("Enter number of edges: ");
  scanf("%d",&e);
  printf("Enter edges (u v):\n");
  for(i=0;i<e;i++)
    scanf("%d%d",&edges[i][0],&edges[i][1]);
  for(i=1;i<=n;i++)
  {
    adj[i]=NULL;
    visited[i]=0;
  }
  buildAdjList();
  printf("Enter starting vertex: ");
  scanf("%d",&start);
  printf("DFS traversal: ");
  dfs(start);
  printf("\n");
  return 0;
}