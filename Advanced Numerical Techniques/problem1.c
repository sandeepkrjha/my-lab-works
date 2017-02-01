#include <stdio.h>

void thomasAlgo(float main_diagonal[],float upper_diagonal[],float lower_diagonal[],float b[], int n)
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
	float h, X0, Xn, Y0,Yn; 
	int i,n;
	printf("Enter the number of unknowns\n");
	scanf("%d",&n);
	printf("Enter the value of h, X0, Xn, Y(X0), Y(Xn), respectively\n");
	scanf("%f%f%f%f%f",&h,&X0,&Xn,&Y0,&Yn);
	float main[1000],lower[1000],upper[1000];
	float X[100];
	float b[100];

	for(i=0;i<=n-1;++i)
	{
		X[i]=X0 + (i+1)*h;
	}

	for(i=0;i<n;++i)
	{
		main[i]= ((-2)*X[i]*X[i])/(h*h);
		if(i==n-1)
		{
			upper[i]=0;
			lower[i]=0;
		}
		else
		{
			upper[i]=(X[i]*X[i]/(h*h)) + (X[i]/(2*h));
			lower[i]=(X[i+1]*X[i+1]/(h*h))- (X[i+1]/(2*h));
		}

	}

	for(i=0;i<n;++i)
	{
		if(i==0)
			b[i]= 1- (((X[0]*X[0]/(h*h)) +(X[0]/(2*h)))*Y0);
		else if(i==n-1)
			b[i]= 1- (((X[n-1]*X[n-1]/(h*h)) - (X[n-1]/(2*h)))*Yn);
		else
			b[i]=1;
	}
	thomasAlgo(main,upper,lower,b,n);
	printf("*****printing solutions******\n");
	for(i = 0; i < n; ++i)
	{
		printf("y(%f) is %f \n",X[i],b[i]);
	}
	

	return 0;
}