#include "graph.h"

Graph::Graph(int V)
{
    this->V=V;
    subset=new Subset[V];
    for(int i=0;i<V;i++)
    {
        subset[i].parent=i;
        subset[i].rank=0;
    }
}
 

Graph::~Graph()
{
	cout<<"\nDeleting the graph from the memory.\n";
}


bool edgecmp(Edge i,Edge j)
{
    return i.weight<j.weight;
}


void Graph::addEdge(int v,int w,int wt)
{
    Edge temp;
    temp.src=v;
    temp.dest=w;
    temp.weight=wt;
    edge.push_back(temp);
}
 

int Graph::find(int i)
{
    if(subset[i].parent!=i)
        subset[i].parent=find(subset[i].parent);
    return subset[i].parent;
}
 

void Graph::Union(int x,int y)
{
    int xroot=find(x);
    int yroot=find(y);
    if(subset[xroot].rank<subset[yroot].rank)
        subset[xroot].parent=yroot;
    else if(subset[yroot].rank<subset[xroot].rank)
        subset[yroot].parent=xroot;
    else
    {
        subset[yroot].parent=xroot;
        subset[xroot].rank++;
    }
}

list<int>* createAdjList(vector<Edge> edge, int V)
{
	list<int> *adj = new list<int>[V];
	vector<Edge>::iterator i;

	for(i=edge.begin(); i!=edge.end(); i++)
		adj[i->src].push_back(i->dest);

	return adj;
}

void Graph::BFS()
{
	list<int> *adj = createAdjList(edge, V);
	queue<int> vertex_queue;
	bool *visited = new bool[V];
	list<int>::iterator j;
	int s=0;

	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}

	visited[s]=true;
	vertex_queue.push(s);

	while(!vertex_queue.empty())
	{
		s=vertex_queue.front();
		cout<< s <<" ";
		vertex_queue.pop();

		for(j=adj[s].begin(); j!=adj[s].end(); j++)
		{
			if(!visited[*j]){
				visited[*j]=true;
				vertex_queue.push(*j);
			}
		}
	}
}


void Graph::DFS()
{
	bool *visited = new bool[V];
	list<int> *adj = createAdjList(edge,V);
	for(int i=0;i<V;i++)
		visited[i]=false;

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
			DFSUtil(i, visited, adj);
	}
}


void Graph::DFSUtil(int v, bool visited[], list<int> *adj)
{
	visited[v]=true;
	cout<<v<<" ";

	list<int>::iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); i++)
	{
		if(!visited[*i])
			DFSUtil(*i, visited, adj);
	}

}

void Graph::kruskalMST()
{
	int e=0;
    Edge *result=new Edge[V-1];
    sort(edge.begin(),edge.end(),edgecmp);
    vector<Edge>::iterator i;
    for(i=edge.begin();i!=edge.end() && e!=V-1;i++)
    {
        int x=find(i->src);
        int y=find(i->dest);
        if(x!=y)
        {
            result[e++]=*i;
            Union(x,y);
        }
    }
    for(int i=0;i<e;i++)
        cout<<result[i].src<<" - "<<result[i].dest<<"     "<<result[i].weight<<endl;
}