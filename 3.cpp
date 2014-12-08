#include <iostream>
#include <stdio.h>
#include <string.h>
int n;
int Cint(char mychar)
{
	return (mychar-48);
}

int IsChar(char i)
{
	if(i=='+'||i=='-'||i=='*'||i=='/'||i=='#'||i=='^'||isdigit(i)||i=='x')
		return 1;
	else
		return 0;
}

void Process(int s[],char x)
{
	static int flag=0,tempnum = 0;
	if(isdigit(x))
	{
		if(flag==2)
		{
			if(Cint(x)==1)
			{
				n= n-4;
				flag =4;
				tempnum =0;
			}
			else 
			{
				s[n-5]=s[n-5]*Cint(x);
				s[n++]= Cint(x)-1;
				flag = 4;
				tempnum = 0;
			}
		}
		else
		{
			tempnum= tempnum*10+Cint(x);
			flag = 0;
		}
	}
	else if(x=='x')
	{
		if(tempnum!=0)
			s[n++]=tempnum;
		else 
			s[n++] = 1;
		s[n++]= -1;
		s[n++] = (int )x;
		tempnum =0;
		flag =1;
	}
	else if(x=='^')
	{
		s[n++]=-1;
		s[n++]=(int)x;
		flag = 2;
	}
	else if(x=='+'||x=='-'||x=='*'||x=='/')
	{
		if(flag==4)
		{
			s[n++]=-1;
			s[n++]= (int)x;
		}
		else if(flag==1)
		{
			n-=2;
			s[n++]=-1;
			s[n++]= (int)x;
		}
		tempnum = 0;
		flag =3;
	}
	else if(x=='#')
	{
		if(flag!=4)
		{
			n=n-1;
			s[n++]=-1;
			s[n]=(int)x;
		}
		else if(flag==1)
		{
		n=n-2;
		s[n++]=-2;
		}
		else 
			s[n++]=-2;
	}
}
int main()
{
	int s[40],i;
	char ch[40];
	printf("\n\t\t输入含x的表达式:4x^3+6#,一定要用'#'结尾,然后按Enter键!\n");
	scanf("%s",ch);
	for(i=0;i<strlen(ch);i++)
	{
	if(!IsChar(ch[i]))
	{
		printf("\n Input Error!");
		exit(0);
	}
	}
	for(i=0;i<strlen(ch);i++)
	{
		Process(s,ch[i]);
	}
	printf("求导结果为:");
	for(i=0;i<n;i++)
	{
		if(s[i]==-2)
		{
			i=n;
		}
		else if(s[i]==-1)
		{
			printf("%c",s[++i]);
		}
		else 
			printf("%d",s[i]);
	}
	printf("\n");
	getchar();
	getchar();
 	return 0;
}