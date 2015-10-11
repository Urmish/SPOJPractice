#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <map>
#include <queue>

std::map<int, std::map<int,int> >  adjacencyList;

void createGraph(int startNode, int endNode, int weight);
void printGraph();
void createPriorityQueue();
int shortestPath(int startVertex, int endVertex);

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
    printGraph();
    for (std::map<int, std::map<int,int> >::iterator startVertex = adjacencyList.begin();startVertex != adjacencyList.end(); startVertex++)
    {
	int valuePath = shortestPath(startVertex->first,exitCell);
	if (valuePath <= timer)
	{
	    totalMice++;
	} 
    }
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

int shortestPath(int startVertex, int endVertex)
{
    typedef std::pair<int,int> edgePair;
    std::priority_queue< edgePair, std::vector< edgePair >, CompareDist > PQ; 
    PQ.push(edgePair(startVertex,0));
    int found;
    while (!PQ.empty())
    {
	edgePair top = PQ.top();
	PQ.pop();
	int vertex = top.first, dist = top.second;
    }
}
