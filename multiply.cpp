//program to multiply two very very large numbers 
//takes input form a file :"input.txt"
//produces output on terminal
//for multiplying larger numbers, increase MAX

//NAME - ATUL MISHRA
//ROLL - 17CS8017

#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
void add(char *p,char *q)
{
	
//performs addition and updates the result of multiply function

	int sum=0,carry=0,short_length,flag=0,i,long_length;                    

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
	
	for(i=0;i<short_length;i++)
	{
		
		sum=(*(p+i)-'0')+(*(q+i)-'0')+carry;
		*(q+i)=char ((sum%10)+'0');
		carry=int(sum/10);	
	}

	for(i=short_length;i<long_length;i++)
	{
		
		if(flag==1) *(q+i)=char (carry+int(*(q+i)-'0')+'0');
		else        *(q+i)=char (carry+int(*(p+i)-'0')+'0');
		carry=carry/10;
		
	}
	
	if(carry==1) *(q+i)='1';
	
}
void multiply(char *a,char *b)
{
	//performs multiplication 
	
	char result[MAX]={'0'},temp[MAX]={'0'};                                     //intializes res and temp to '0'
	int len_a=strlen(a),len_b=strlen(b),i,j,k,l;                             //res will store result and will get updated every time
	int carry=0,product=0;                                                   //temp stores the current multiplication result
	
	for(i=0;i<len_a;i++)
	{
		carry=0;
		l=0 ;
		for(k=0;k<i;k++)
		{
			temp[l]='0';
			
			l++;
		}
		
		for(j=0;j<len_b;j++)
		{
			product=(*(a+len_a-i-1)-'0')*(*(b+len_b-j-1)-'0') + carry;                  //multiplying the digits one by one and storing them
			temp[l]=char (product%10+'0');
			carry=product/10;
			l++;
		}
		while(carry!=0)
		{
			temp[l]=char (carry%10+'0');
			carry=carry/10;
			l++;
		}
		
		add(temp,result);                                                                //calling add to add the result and current product(temp)
		
	}
	cout<<"product is : "<<endl;
	for(i=strlen(result)-1;i>=0;i--) cout<<result[i];
	
}
int main()
{
//driver function
	char num1[MAX],num2[MAX];
	FILE *f;
	int i;
	f=fopen("input.txt","r");                          //takes input from file
	while(!feof(f))
	{
		fscanf(f,"%s%s",num1,num2);
	}
	fclose(f);
	std::cout<<"num1="<<num1<<endl;                   //displays number 1
	std::cout<<"num2="<<num2<<endl;                   //displays number 2
	multiply(num1,num2);                                   //calls multiply function
}
