#include"apue.h"
#include"error.h"
#include<stdio.h>
#include<math.h>
int cnt=1;
int main()
{
pid_t pid;
int ch=1;

double a=0,b=0,c=0,d=0,e=0,f=0;
while(ch!=0 && cnt<=10)
{
printf("cnt:%d\n",cnt);				
printf("please enter the values of a,b,c,d\n");
printf("a:");
scanf("%lf",&a);printf("b:");scanf("%lf",&b);printf("c:");scanf("%lf",&c);printf("d:");scanf("%lf",&d);
//printf("The values of a=%lf b=%lf c=%lf d=%lf\n",a,b,c,d);
	if(cnt<=10)
	{	
	if ((pid = fork()) < 0)
	     {
	       err_sys("fork error");
  	     }
	else if (pid == 0) 
	{
	printf("%d",cnt);
	
	e=pow(a,b);
	f=pow(c,d);
	if (e<f)
	printf("a^b: %lf < c^d: %lf\n ||  %lf^%lf is greater.  ||\n",e,f,c,d);
	else
 	printf("a^b: %lf > c^d: %lf\n ||  %lf^%lf is greater.  ||\n",e,f,a,b);
	printf("To exit press 0:\n");
	
	_exit(0);		
	}
	scanf("%d",&ch);
	}
cnt++;		
}
return 0;
}
