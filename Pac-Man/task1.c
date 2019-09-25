#include <stdio.h>

int main (){

int N, i, j;
char C;
scanf("%d\n", &N);
scanf("%c", &C);

for (i=0; i<N; i++)
{	for(j=0; j<N; j++)
		if(i>j)	
			printf("  ");	
		else
			if(j!=N-1)
				printf("%c ",C);
			else
				printf("%c",C);
		
	printf("\n");
}
return 0;	
}