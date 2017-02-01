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
	float main[1000], lower[1000],upper[1000];
	float b[1000],X[1000];
	float X0=0,Xn=1,h,Y0,Yn;
	printf("Enter the value of h (h<=0.1)\n");
	scanf("%f",&h);

	int n,i;
	printf("\nEnter the number of unknowns\n");
	scanf("%d",&n);

	for(i=0;i<n;++i)
	{
		X[i]=X0 + (i+1)*h;
	}
	for(i=0;i<n;++i)
	{
		if(i==n-1)
		{
			main[i]=  ((-2)-(2/(h*h))) - 4*(1-h*X[i])/((4*h-3)*h*h);
			upper[i]=0;
			lower[i]=0;
		}
		if(i==0)
		{
			main[i]= ((-2)-(2/(h*h))) + 4*(1+X[i]*h)/((3+2*h)*h*h);
			upper[i]=(1-h*X[i])/(h*h) - (1+X[i]*h)/((3+2*h)*h*h);
		}
		if(i==n-2)
		{
			lower[i]= (1+h*X[i+1])/(h*h) + (1-h*X[i+1])/((4*h-3)/(h*h));
		}
		main[i]= ((-2)-(2/(h*h)));
		lower[i]= (1+X[i+1]*h)/(h*h);
		upper[i]=(1-X[i]*h)/(h*h);
	}
	for(i=0;i<n;++i)
	{
		if(i==n-1)
			b[i]= (-4)*X[i]- ((1-h*X[i])*(2*h))/((4*h-3)*h*h);
		else
			b[i]= (-4)*X[i];
	}

	thomasAlgo(main,upper, lower, b, n);
	Y0= (4*b[0]-b[1])/(3+2*h);
	Yn= (2*h + b[n-2]-4*b[n-1])/(4*h-3);
	printf("*****printing solutions******\n");
	printf("\ny(0.000000) is %f\n",Y0);

	for(i = 0; i < n; ++i)
	{
		printf("y(%f) is %f \n",X[i],b[i]);
	}
	printf("y(1.000000) is %f\n",Yn);
	

	return 0;
}