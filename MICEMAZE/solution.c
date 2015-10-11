#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <map>

std::map<int, std::map<int,int> >  adjacencyList;

void createGraph(int startNode, int endNode, int weight);
void printGraph();
void createPriorityQueue();

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
	while (numConnections > 0)
	{
	      int startNode, endNode, weight;
	      scanf("%d %d %d",&startNode,&endNode,&weight);
	      createGraph(startNode,endNode,weight);
	      numConnections--;
	//      printf("%d -> (%d,%d) added \n",startNode,endNode,weight);
	}
	printGraph();
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

void createPriorityQueue()
{
}
