#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void concatenate(int arr1[],int n1,int arr2[],int n2,int arr[],int n)
{
	for(int i=0;i<n1;i++)
	{
		arr[i]=arr1[i];
	}
	for(i=0;i<n2;i++)
	{
		arr[n1+i]=arr2[i];
	}
	if (n1+n2<=n)
		return 1;
	else
	 	return 0;
}

void main()
{
	clrscr();
	int arr,arr1={1,2,3,4,5,6,7,8},arr2={8,9,10,11,12,13}
	if(concatenate(arr1,sizeof(arr1),arr2,sizeof(arr2),arr,sizeof(arr))
	{	for(int i=0;i<15;i++)
		cout<<str[i]<<endl;
	}
	else
		cout<<"No";
}