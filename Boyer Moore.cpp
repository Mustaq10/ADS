#include<string.h>
#include<iostream>
using namespace std;
int  find(char pattern[ ], char  ch)
{
	int m, i;  m = strlen(pattern);
	for  (i = m - 2; i >= 0; i--)
	{
		if  (ch == pattern[i])
		{
			return  i;
		}
	}
	return  -1;
} 
int  BoyerMoore(char text[ ], char pattern[ ])
{
	int n, m, i, j, lastch;  
	n = strlen(text);  
	m = strlen(pattern);
	i=m-1; j=m-1;
	while  (i < n) 		//  not end of string S
		if  (pattern[j] == text[i])  
			if  (j == 0) 	// first char of pattern
				return  i;
			else
			{
				j--;  i--;	//  go left
			}
		else		//  no match – find char in pattern
		{
			lastch = find(pattern, text[i]);
			if  (lastch == -1) 	// not found
				i = i + m;		// jump over
			else
				i = i + j-lastch;	// align char
			j = m - 1;	// restart from right
		}
	return  -1;	//  not matched
}


int main()
 {
     char text[] = "This is demo program";
     char pattern[] = "gram";
     int loc = BoyerMoore(text, pattern);
     if(loc==-1)
     	cout<<"Sorry...! No pattern found..!";
     else
     	cout<<"The pattern starts from location "<<loc<<" in main text..!";
     return 0;
 } 
