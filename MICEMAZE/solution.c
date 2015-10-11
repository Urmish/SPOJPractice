#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <climits>

std::map<int, std::map<int,int> >  adjacencyList;

void createGraph(int startNode, int endNode, int weight);
void printGraph();
void createPriorityQueue();
int shortestPath(int startVertex, int endVertex, int totalNodes);

class CompareDist
{
public:
    bool operator()(std::pair<int,int> n1,std::pair<int,int> n2) 
    {
        return n1.second>n2.second;
    }
};

int main()
{
    int NcellsInMaze;
    int exitCell;
    int numConnections;
    int timer;
    scanf("%d",&NcellsInMaze);
    scanf("%d",&exitCell);
    scanf("%d",&timer);
    scanf("%d",&numConnections);
    int numExits;
    int totalMice = 0;
    while (numConnections > 0)
    {
          int startNode, endNode, weight;
          scanf("%d %d %d",&startNode,&endNode,&weight);
          createGraph(startNode,endNode,weight);
          numConnections--;
    //      printf("%d -> (%d,%d) added \n",startNode,endNode,weight);
    }
    //printGraph();
    //for (std::map<int, std::map<int,int> >::iterator startVertex = adjacencyList.begin();startVertex != adjacencyList.end(); startVertex++)
    for (int i=1; i<=NcellsInMaze; i++)
    {
		///if (exitCell == startVertex->first)
		if (exitCell == i)
		{
			totalMice++;
			continue;
		}
		//int valuePath = shortestPath(startVertex->first,exitCell);
		int valuePath = shortestPath(i,exitCell,NcellsInMaze);
		//printf("%d-%d\n",i,valuePath);
		if (valuePath <= timer)
		{
			totalMice++;
		} 
    }
    printf("%d\n",totalMice);
}


void createGraph(int startNode, int endNode, int weight)
{
    adjacencyList[startNode][endNode] = weight;
}

void printGraph()
{
    printf("********************************************\n");
    printf("************ADJACENCY LIST******************\n");
    printf("********************************************\n");
    printf("\n");
    for(std::map<int, std::map<int,int> >::iterator iteratorOuter = adjacencyList.begin(); iteratorOuter != adjacencyList.end(); ++iteratorOuter)
    {
        printf("%d: ",iteratorOuter->first);
        for(std::map<int,int>::iterator iteratorInner = adjacencyList[iteratorOuter->first].begin(); iteratorInner != adjacencyList[iteratorOuter->first].end(); ++iteratorInner)
        {
          printf("(%d,%d) ",iteratorInner->first,iteratorInner->second);
        }	
        printf("\n");
    }
}

int shortestPath(int startVertex, int endVertex, int totalNodes)
{
    typedef std::pair<int,int> edgePair;
    std::priority_queue< edgePair, std::vector< edgePair >, CompareDist > PQ; 
    std::map<int,int> distFromStart;
    std::map<int,int> inS;
    //for(std::map< int, std::map <int,int> >::iterator iteratorOuter = adjacencyList.begin(); iteratorOuter != adjacencyList.end(); ++iteratorOuter)
	for (int i=1;i<=totalNodes;i++)
    {
    	//distFromStart[iteratorOuter->first] = INT_MAX;
    	distFromStart[i] = INT_MAX;
    }	
    //for(std::map< int, std::map <int,int> >::iterator iteratorOuter = adjacencyList.begin(); iteratorOuter != adjacencyList.end(); ++iteratorOuter)
	for (int i=1;i<=totalNodes;i++)
    {
    	//inS[iteratorOuter->first] = 0;
    	inS[i] = 0;
    }

	distFromStart[startVertex] = 0;

    PQ.push(edgePair(startVertex,0));
    while (!PQ.empty())
    {
		edgePair top = PQ.top();
		PQ.pop();
		int vertex = top.first, dist = top.second;
		//printf("Looking at %d\n",vertex);
		if (inS[vertex] == 1)
		{	
			continue;
		}
		if (vertex == endVertex)
		{
			return dist;
		}
		
		for(std::map <int,int>::iterator iteratorOuter = adjacencyList[vertex].begin(); iteratorOuter != adjacencyList[vertex].end(); ++iteratorOuter)
		{
			int vertex2 = iteratorOuter->first, cost = iteratorOuter-> second;
			//printf("%d and new - %d+%d, old - %d\n",vertex2,dist,cost,distFromStart[vertex2]);
			if (distFromStart[vertex2] > dist + cost)
			{
				distFromStart[vertex2] = dist + cost;
				//printf("Pushing %d - %d\n",vertex2,distFromStart[vertex2]);
				PQ.push(edgePair(vertex2,distFromStart[vertex2]));
			}
		}
		inS[vertex] = 1;
    }
	return INT_MAX;
}
