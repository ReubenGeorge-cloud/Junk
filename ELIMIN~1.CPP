#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void eliminate_duplicates(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if((arr[i]==arr[j])&&(i!=j))
			{
				n--;
				for(int k=j;k<n;k++)
				{
					arr[k]=arr[k+1];
				}
			}
		}
	}
}
void main()
{
	clrscr();
	int str[15]={1,2,2,3,3,4,5,6,7,88,9,77,77,8,77};
	eliminate_duplicates(str,15);
	for(int i=0;i<15;i++)
		cout<<str[i]<<endl;
	getch();
}
