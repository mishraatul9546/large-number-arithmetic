//calculates sum and difference of numbers having upto 10^5 digits 
//for calculating sum or difference with more than 10^5 digits, increase MAX

//NAME - ATUL MISHRA
//ROLL - 17CS8017

#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
void add(char *p,char *q)
{
	
//performs addition

	int sum=0,carry=0,short_length,flag=0,i,long_length;                    
	char x[MAX],y[MAX];
	
	if(strlen(p)<strlen(q))
	{
		short_length=strlen(p);
		long_length=strlen(q);
		flag=1;
	}                                                                         //short_length= number of digits in shorter number
	else                                                                      //long_length= number of digits in longer number
	{
		short_length=strlen(q);
		long_length=strlen(p);
	}
	
	for(i=short_length-1;i>=0;i--)
	{
		if(flag==1)    sum=(*(p+i)-'0')+(*(q+i+long_length-short_length)-'0')+carry;
		else           sum=(*(p+i+long_length-short_length)-'0')+(*(q+i)-'0')+carry;            //find sum from last digit upto shorter number's first digit
																				 	
		x[i]=char((sum%10)+'0');
		carry=int(sum/10);
	}
	
	for(i=long_length-short_length-1;i>=0;i--)
	{
		if(flag==1)    sum=(*(q+i)-'0')+carry;
		else           sum=(*(p+i)-'0')+carry;                                             //puts the remaining numbers of longer number in array
		
		y[i+1]=char((sum%10)+'0');
		carry=int(sum/10);
	}

	if(carry!=0) y[0]=char(carry+'0');                                                  //checks for final carry and puts in array if present
	std::cout<<"sum= "<<y<<x<<endl;                                                           //displays result
	
	
}
void diff(char *p,char *q,int sign)
{   
	//performs subtraction
	
	int short_length,long_length,i,d,flag=0;
	char x[MAX];
	if(strlen(p)<strlen(q))
	{
		short_length=strlen(p);
		long_length=strlen(q);
		flag=1;
	}                                                                         //short_length= number of digits in shorter number
	else                                                                      //long_length= number of digits in longer number
	{
		short_length=strlen(q);
		long_length=strlen(p);
	}
	for(i=short_length-1;i>=0;i--)
	{
		if(flag==1)  d=(*(p+i)-'0')-(*(q+i+long_length-short_length)-'0');
		else         d=(*(p+i+long_length-short_length)-'0')-(*(q+i)-'0'); 
		
		if(d<0)	
		{
			d=d+10;
			if(flag==1) *(p+i-1)=char(((*(p+i-1)-'0')-1)+'0');
			else        *(p+i+long_length-short_length-1)=char(((*(p+i+long_length-short_length-1)-'0')-1)+'0');
		}
		x[i]=char(d+'0');	
	}
	
	cout<<"diff=";
	if(sign==0) cout<<"-";
	for(i=0;i<=long_length-short_length-1;i++) cout<<*(p+i);
	std::cout<<x<<endl;
}
int main()
{
//driver function
	char num1[MAX][MAX],num2[MAX]={'0'};
	FILE *f;
	int i=0;
	f=fopen("inputt.txt","r");                          //takes input from file
	while(!feof(f))
	{
		fscanf(f,"%s",num1[i]);
		i=i+1;
	}
	for(i=0;i<100;i++)
	{
		num2=add(num1[i],num2);
	}
	std::cout<<num2;
	//std::cout<<"num1="<<num1<<endl;                   //displays number 1
	//std::cout<<"num2="<<num2<<endl;                   //displays number 2
//	add(num1,num2);                                   //calls addition function
	//if(strlen(num1)>strlen(num2)) diff(num1,num2,1);
	//else if(strlen(num1)<strlen(num2)) diff(num2,num1,0);
	//else
	//{
		//for(i=0;i<strlen(num1);i++) 
		//if (num1[i]>num2[i])
		//{
			//diff(num1,num2,1);
			//break;
	//	}
		//else if(num2[i]>num1[i])
	//	{
	//		diff(num2,num1,0);
	//		break;
	//	}
	//} 
}

