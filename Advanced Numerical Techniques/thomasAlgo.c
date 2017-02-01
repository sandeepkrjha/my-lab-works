/* Thomas algorithm is used solve system of eqations
   involving a tri-diagonal matrix
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	solve function takes arrays main_diagonal, upper_diagonal, lower_diagonal
	along with n, the number of unknowns as arguments.
	main_diagonal contains diagonal elements of the tri-diagonal matrix
	upper_diagonal contains elements of diagonal above main_diagonal 
	lower_diagonal contains elements of diagonal below main_diagonal
*/
void solve(float main_diagonal[],float upper_diagonal[],float lower_diagonal[],float b[], int n)

{
	upper_diagonal[0]= upper_diagonal[0]/main_diagonal[0];
	b[0]= b[0]/main_diagonal[0];

	int i;
	for(i=1; i <n-1; i++)
	{
		upper_diagonal[i] /= (main_diagonal[i] - upper_diagonal[i-1]* lower_diagonal[i-1]);
		b[i] = (b[i] - b[i-1]* lower_diagonal[i-1])/(main_diagonal[i]-upper_diagonal[i-1]*lower_diagonal[i-1]);
	}

	b[n-1]=(b[n-1]- b[n-2]*lower_diagonal[n-2])/(main_diagonal[n-1] - upper_diagonal[n-2]* lower_diagonal[n-2]);

	for(i= n-2; i>=0; i--)
	{
		b[i] = b[i] - upper_diagonal[i]* b[i+1];
	}



}


int main()
{
	int n=4;
	float a[4]= {-1,-1,-1,0};
	float b[4]={4,4,4,4};
	float c[4] = { -1, -1, -1, 0};
	float d[4] = { 5, 5, 10, 23};
	solve(b,c,a,d,n);

	int i;
	for(i=0; i< 4; ++i)
	{
		printf("%f  ",d[i] );
	}
	printf("\n");
	return 0;
}
