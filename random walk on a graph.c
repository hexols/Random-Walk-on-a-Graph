#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s
{
	char name;
	NODE link[10];
}NODE_t[1];

#define indexA 0
#define indexB 1
#define indexC 2
#define indexD 3
#define indexE 4
#define indexF 5

int main()
{
	NODE_t node[6];
	node[indexA]->name = 'A';
	node[indexB]->name = 'B';
	node[indexC]->name = 'C';
	node[indexD]->name = 'D';
	node[indexE]->name = 'E';
	node[indexF]->name = 'F';
	
	int i,j;
	int lilnode;
	int choice;
	int randlink;
	for(i=0;i<10;i++)
	{
		node[indexA]->link[i]=NULL;
		node[indexB]->link[i]=NULL;
		node[indexC]->link[i]=NULL;
		node[indexD]->link[i]=NULL;
		node[indexE]->link[i]=NULL;
		node[indexF]->link[i]=NULL;
	}

	// A -> C,D,E,F
	
	node[indexA]->link[0]=node[indexC];
	node[indexA]->link[1]=node[indexD];
	node[indexA]->link[2]=node[indexE];
	node[indexA]->link[3]=node[indexF];
	
	// B -> C,F
	
	node[indexB]->link[0]=node[indexC];
	node[indexB]->link[1]=node[indexF];
	
	// C -> A,B,E
	
	node[indexC]->link[0]=node[indexA];
	node[indexC]->link[1]=node[indexB];
	node[indexC]->link[2]=node[indexE];
	
	// D -> A,E,F
	
	node[indexD]->link[0]=node[indexA];
	node[indexD]->link[1]=node[indexE];
	node[indexD]->link[2]=node[indexF];
	
	// E -> A,C,D
	
	node[indexE]->link[0]=node[indexA];
	node[indexE]->link[1]=node[indexC];
	node[indexE]->link[2]=node[indexD];
	
	// F -> A,B,D
	
	node[indexF]->link[0]=node[indexA];
	node[indexF]->link[1]=node[indexB];
	node[indexF]->link[2]=node[indexD];
	
	choice = rand()%8+1;
	srand(time(NULL));
	
	
	for(i=0;i<choice;i++)
	{
		lilnode=rand()%6;
		printf("%c ->",node[lilnode]->name);
		randlink=rand()%10;
		
		while(node[lilnode]->link[randlink]==NULL)
		{
			randlink=rand()%10;
		}
		printf("%c ->",node[lilnode]->link[randlink]->name);
		node[lilnode]->link[randlink]=node[lilnode];
		
		for(j=0;j<6;j++)
		{
			if(node[j]->name==node[lilnode]->link[randlink]->name)
			{
			    lilnode=j;
				break;
			}
	 	}
	}
	
}
