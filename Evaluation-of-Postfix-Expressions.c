/*
https://www.includehelp.com/c/evaluation-of-postfix-expressions-using-stack-with-c-program.aspx
*/

#include<stdio.h>
#include<stdarg.h>
#include<string.h>

int top=-1;
int s[1000]={0};

int push(int val)
{
	top++;
	s[top]=val;
}

int pop()
{
	int val;
	val=s[top];
	top--;
	return val;
}

int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int main()
{
	char exp[]="456*+";
	char ch;
	int i,op1,op2,sum=0;

	for(i=0;i<strlen(exp);i++) {

		ch=exp[i];
		if(ch>='0' && ch <='9')
			push(ch-0x30);

		else {
			if(isempty()==0) op1=pop();
			if(isempty()==0) op2=pop();
			
			switch(ch) {
				case '+' : sum = op2 + op1; break;
				case '-' : sum = op2 - op1; break;
				case '*' : sum = op2 * op1; break;
				case '/' : sum = op2 / op1; break;
			}
			push(sum);

		}
	}
	printf("output=%d\n",sum);
	return 0;
}
