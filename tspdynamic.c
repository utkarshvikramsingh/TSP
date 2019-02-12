//This Program will calculate minimum weight hamiltonian cycle using Dynnamic programming approach when matrix is symmetric

#include<stdio.h>
#include<time.h>

int node_table[10][10];
int traversed[10];
int n,cost=0;

void get_table();      // entering the cost matrix
int mindist(int c);    // finding out shortest path
float mincost(int c);   // compute the minimum cost
void display_result();   // displays the result

void get_table(){
	int i,j;
	printf("Enter No. of Cities: ");
	scanf("%d",&n);
	
	printf("\nEnter the distance(cost) between nodes\n");
	
	for(i=0;i < n;i++){
		printf("\nEnter Elements of Row # : %d\n",i+1);
		for( j=0;j < n;j++)
			scanf("%d",&node_table[i][j]);
		traversed[i]=0;
	}
	
	printf("\n\nThe cost list is:\n\n");
	for( i=0;i < n;i++){
		printf("\n\n");
		for(j=0;j < n;j++)
			printf("\t%d",node_table[i][j]);
	}
}

int mindist(int c){
	int i,nextcity=1000;
	int min=1000,costmin;
	
	for(i=0; i<n; i++){
		if((node_table[c][i]!=0)&&(traversed[i]==0))
			if(node_table[i][c] + node_table[c][i] < min){
				min = node_table[i][0]+node_table[c][i];
				costmin = node_table[c][i];
				nextcity=i;
			}
	}
	
	if(min!=1000)
		cost+=costmin;
	return nextcity;
}

float mincost(int city){
	
		double time_spent = 0.0;
	clock_t begin = clock();
	
	int i,ncity;
	traversed[city]=1;	
	
	printf("%d -->",city+1);
	
	ncity=mindist(city);
	if(ncity==1000){
		ncity=0;
		printf("%d",ncity+1);
		cost+=node_table[city][ncity];
		return;
	}
	mincost(ncity);

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}


void display_result(){
	printf("\n\nMinimum cost:");
	printf("%d",cost);
}

int main(){
	float time_spent;
	get_table();
	printf("\n\nThe Path is:\n\n");
	time_spent=mincost(0);
	display_result();
     
    printf("total time spent is %f", time_spent);
	return 0;
}
