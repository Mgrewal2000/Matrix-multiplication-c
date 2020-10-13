#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
FILE* f =fopen(argv[1],"r");
if(f == NULL){
	printf("Could not open test.txt\n");
	return 1;
};
int row1, row2, col1, col2;
int i,x,k;
int result=0;

fscanf(f,"%d\t%d",&row1, &col1);
int **M1 = (int **)malloc(sizeof(int*) * row1);
int z = 0;
for(; z<row1;z++)
{
	M1[z]= (int*)malloc(sizeof(int)*col1);
}
	for (i=0; i < row1;i++)
	{ for(x=0; x <col1; x++)
	{	
		fscanf(f,"%d",&M1[i][x]);
	}
	}
// here we're done with matrix 1
// moving onto matrix 2

fscanf(f,"%d\t%d",&row2, &col2);
int **M2 = (int **)malloc(row2*sizeof(int*));
z = 0;
for(; z<row2;z++)
{
        M2[z]= (int *)malloc(sizeof(int)*col2);
}
        for (i=0; i < row2;i++)
        { for(x=0; x <col2; x++)

        { 
	      fscanf(f,"%d",&M2[i][x]);
        }
        }
if(col1==row2){
	int **resultant=(int**)malloc(row1*sizeof(int*));
	z=0;
	for(;z<row1;z++){
	resultant[z]=(int *)malloc(sizeof(int)*col2);
	}
	for(i=0;i<row1;i++){
		for(x=0;x<col2;x++){
			for(k=0;k<row2;k++){
				result +=(M1[i][k])*(M2[k][x]);	
				}	
			resultant[i][x]=result;
			result = 0;
		}
	}
		for(i=0;i<row1;i++){
			for(x=0;x<col2;x++)
				printf("%d\t",resultant[i][x]);
				
				printf("\n");
			}
		}
	else
	{
		printf("bad-matrices");
		printf("\n");
	}
	return 0;
}
