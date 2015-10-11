#include <stdio.h>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map <int, vector<int> > possibleNextMove;

void GenerateGraph(); //Generates all possible moves of a knight from all possible locations on a chessboard
void PrintGraph(); //Prints the Graph Generated in GenerateGraph
int  BFS(int start, int end); //Finds the shortes possible moves between the start and end position for a knight
int  convertToLocation(char a, int b);

int main()
{
	GenerateGraph();
	//PrintGraph();

	//Now take input
	int NumOfTests;
	char temp;
	scanf("%d\n",&NumOfTests);
	//printf("Number of Tests are %d\n",NumOfTests);
	while(NumOfTests>0)
	{
		int  startRow, endRow;
		char startCol, endCol;
		scanf("%c%d %c%d",&startCol,&startRow,&endCol,&endRow);
		scanf("%c",&temp);
		//printf("%c%d %c%d\n",startCol,startRow,endCol,endRow);
		printf("%d\n",BFS(convertToLocation(startCol,startRow), convertToLocation(endCol,endRow)));
		NumOfTests--;
	}
	return 0;
}

void GenerateGraph()
{
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			int loc = i*8+j;
			//printf("%d => ",loc);
			for(int dir=0;dir<8;dir++) //At each point the knight could travel a maximum of 8 directions
			{
				int newi = i; //New value of i when the knight moves
				int newj = j; //New value of j when the knight moves
				int skip = 0; //Skip if knight cannot move in that direction
				switch (dir)
				{
					case 0: newi=newi+1;
						newj=newj+2;
						break; 
					case 1: newi=newi-1;
						newj=newj+2;
						break; 
					case 2: newi=newi+1;
						newj=newj-2;
						break; 
					case 3: newi=newi-1;
						newj=newj-2;
						break; 
					case 4: newi=newi+2;
						newj=newj+1;
						break; 
					case 5: newi=newi+2;
						newj=newj-1;
						break; 
					case 6: newi=newi-2;
						newj=newj+1;
						break; 
					case 7: newi=newi-2;
						newj=newj-1;
						break; 

				}
				if (newi <0 || newi >7)
					continue;
				if (newj <0 || newj >7)
					continue;
				//printf("%d ",newi*8+newj);
				possibleNextMove[loc].push_back(newi*8+newj);
			}
			//printf("\n");
		}
	}
}

void PrintGraph()
{
	for( map<int,vector<int> >::iterator it=possibleNextMove.begin();it!=possibleNextMove.end();it++)
	{
		printf("%d => ",it->first);
		for(vector<int>::iterator it_inner=(it->second).begin();it_inner!=(it->second).end();it_inner++)
		{
			printf("%d ",*it_inner);
		}
		printf("\n");
	}
}

int  convertToLocation(char a, int b)
{
	int row = b-1;
	int col = 0;
	switch((int)a)
	{
		case 97: col=0;
			 break;
		case 98: col=1;
			 break;
		case 99: col=2;
			 break;
		case 100: col=3;
			 break;
		case 101: col=4;
			 break;
		case 102: col=5;
			 break;
		case 103: col=6;
			 break;
		case 104: col=7;
			 break;
	}
	//printf("%d %d %d\n",row,col,(int)a);
	return row*8+col;
}

int  BFS(int start, int end)
{
	//printf("BFS between %d %d\n",start,end);
	int Color[64]; //0 - Unvisited, 1 - InProgress, 2 - Complete
	int NodeSteps[64]; //Number of Steps Required to reach the node from start
	for (int i=0;i<64;i++)
	{
		Color[i] = 0;
	}
	queue<int> nodes;
	nodes.push(start);
	NodeSteps[start] = 0;
	while (!nodes.empty())
	{
		int currNode = nodes.front();
		nodes.pop();  
		if (Color[currNode] == 2)
			continue;
		for(vector<int>::iterator it_inner=possibleNextMove[currNode].begin();it_inner!=possibleNextMove[currNode].end();it_inner++)
		{
			if (Color[*it_inner] == 2)
				continue;
			nodes.push(*it_inner);
			Color[*it_inner] = 1;
			NodeSteps[*it_inner] = NodeSteps[currNode]+1;
		}
		Color[currNode] = 2;
		if(Color[end] > 0)
		{
			break;
		}
	}
	return NodeSteps[end];
}
