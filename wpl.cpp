#include<iostream>
using namespace std;
bool JudgeArry(int *array,int n);
void quickSort(int *array, int left, int right);
int main(){
	int n,k=0,is=0;
	cin>>n;
	int* a = new int[n];
	int* sum = new int[n];
	int *ary,total=0;
	for(int i=0;i<n;i++)sum[i]=0;
	for(int i=0;i<n;i++)cin>>a[i];
	ary=a;
	while(JudgeArry(ary,n)){
		quickSort(ary,k,n);
		while(a[k]==0)k++;
		a[k+1]=a[k]+a[k+1];
		a[k]=0;
		sum[is]=a[k+1];
		is++;
	}
	for(int i=0;i<n;i++)total+=sum[i];
	cout<<"WPL="<<total<<endl;
	return 0;
}
void quickSort(int *array, int left, int right)
{
	if(left < right)
	{
		int pivot = array[left];
		int low = left, high = right;
		while(low < high)
		{
			while(array[high] >= pivot && low < high)
				high--;
			array[low] = array[high];
			
			while(array[low] <= pivot && low < high)
				low++;
			array[high] = array[low];
		}
		array[low] = pivot;
		quickSort(array, left, low - 1);
		quickSort(array, low + 1, right);
	}
}
bool JudgeArry(int *array,int n){
	int flag=0;
	for(int i=0;i<n;i++)if(array[i]!=0)flag++;
	if(flag)return 1;
	else return 0;
}
