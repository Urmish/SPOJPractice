#include <stdio.h>
#include <stdlib.h>

int mergeSortInversionCountWrapper(int *A, int TotalElements);
int mergeSort(int* Arr, int l, int r);
int merge(int* Arr, int l, int m, int r);

int main()
{
	int a;
	int Number_Of_Test = 0;
	scanf("%d",&Number_Of_Test);
	while (Number_Of_Test > 0)
	{
		int Number_Of_Elements;
		scanf("%d",&Number_Of_Elements);
		int *ArrayA = (int *)malloc(Number_Of_Elements*sizeof(int));
		printf("Need to read %d Elements\n",Number_Of_Elements);
		for (int i=0;i<Number_Of_Elements;i++)
		{
			int temp;
			scanf("%d",&temp);
			ArrayA[i] = temp;
			printf("Read %d\n",temp);
		}
		for (int i=0;i<Number_Of_Elements;i++)
		{
			printf(" %d",ArrayA[i]);
		}
		printf("\n");
		printf("Total Inversions %d\n",mergeSortInversionCountWrapper(ArrayA,Number_Of_Elements));	
 		for (int i=0;i<Number_Of_Elements;i++)
		{
			printf(" %d",ArrayA[i]);
		}

		printf("\n");
		free(ArrayA);
		Number_Of_Test--;
	}
	return 0;
}


int mergeSortInversionCountWrapper(int *A, int TotalElements)
{
	return mergeSort(A,0,TotalElements-1);
}

int mergeSort(int* Arr, int l, int r)
{
	if (l < r)
	{
		int m = (l+r)/2;
		printf("Mid Point is %d\n",m);
		int total = 0;
		total += mergeSort(Arr,l,m);
		total += mergeSort(Arr,m+1,r);l=0, m=0, r=1
		total += merge(Arr,l,m,r);
		return total;
	}
	else
	{
		printf("Returning \n");
		return 0;
	}
}

int merge(int* Arr, int l, int m, int r)
{
	printf("Merging with intputs l=%d, m=%d, r=%d\n",l,m,r);
	int inversions = 0;
	int nl = m -l + 1;
	int nr = r - m;
	printf("nl=%d, nr=%d\n",nl,nr);
	int L[nl], R[nr];
	printf("Reading For L\n");
	for (int i=0;i < nl;i++)
	{
		L[i] = Arr[l+i];
		printf("%d ",L[i]);
	}
	printf("\nReading For R\n");
	for (int i=0;i < nr;i++)
	{
		R[i] = Arr[m+1+i];
		printf("%d ",R[i]);
	}
	int i=0;
	int j=0;
	int k=l;
	printf("\n");
	printf("Reading for Merge \n");
	while (i < nl && j<nr)
	{
		if(L[i] <= R[j])
		{
			Arr[k] = L[i];
			printf("%d ",Arr[k]);
			i++; k++;
		}
		else
		{
			Arr[k] = R[j];
			printf("%d ",Arr[k]);
			j++; k++;
			inversions = inversions + (nl-i);
		}
	}		
	while (i < nl)
	{
		Arr[k] = L[i];
		printf("%d ",Arr[k]);
		i++; k++;
	}
	while (j < nr)
	{
		Arr[k] = R[j];
		printf("%d ",Arr[k]);
		j++; k++;
	}
	printf("\nInversions in this Merge - %d\n",inversions);
	return inversions;
}

