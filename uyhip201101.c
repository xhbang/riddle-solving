#include <stdio.h>
#define N 200
#define MAX 100

int map[2][MAX];	
int flag;

int pos(int n){
	flag=0;
	int i;
	for(i=0;i<MAX;i++){
		if(n==map[0][i])	
			break;
	}
	//if not find,find the first pos whose val==0
	if(i==MAX){
		for(i=0;map[1][i]!=0&&i<MAX;i++)
			;
	}
	if(i==MAX)
		flag=1;
	//time to reduce everyone
	return i;
}

void reduce(){
	int i;
	for(i=0;i<MAX;i++)
		if(!map[1][i])
			map[1][i]-=1;
}

int main(){
	int i,j,m,n;
	//initial
	int vote[N];
	for(i=0;i<200;i++){
		map[0][i]=0;
		map[1][i]=0;
		if(i<50)
			vote[i]=1;
		else if(i<199)
			vote[i]=2;
		else
			vote[i]=200;
	}
	//first time
	for(i=0;i<200;i++){
		m=pos(vote[i]);
		if(flag){
			reduce();
			m=pos(vote[i]);
		}
		map[0][m]=vote[i];
		map[1][m]+=1;
	}
	//second time
	for(i=0;i<MAX;i++){
		map[1][i]=0;
	}
	for(i=0;i<200;i++){
		m=pos(vote[i]);
		map[1][m]+=1;
	}
	//additional time to print
	for(i=0;i<MAX;i++){
		if(map[1][i]!=0)
			printf("%d has %d votes\n",i,map[1][i]);
	}
}
