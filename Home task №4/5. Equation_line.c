#include <stdio.h>

int main(int argc, char **argv)
{	
	int x1,y1,x2,y2,dx,dy;
	float k,b;
	printf("Enter x1 y1 x2 y2 numbers\n");
	scanf("%d %d %d %d",&x1, &y1, &x2, &y2);		
	dx = x1-x2;	
	dy = y1-y2;
	k = (float)dy/dx;	
	b = y2-(k*x2);
	printf("Result: %.2f %.2f \n",k,b); 	
	return 0;
}

