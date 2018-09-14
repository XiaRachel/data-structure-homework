#include<iostream>
using namespace std;
void sort(int *array, int len)
{
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
		{
			if(array[i]>array[j])
			{
				int temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
}
int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a, 3);
	cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	return 0;
}
