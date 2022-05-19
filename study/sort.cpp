#include <iostream>
#include <queue>
/////////////////////////////////////////////////////////////////////////////////////
static void sortGapInsertion(int *a, int first, int last, int gap){
	int i,j,key;
	for(i=first+gap;i<last;i=i+gap){
		key = a[i];
		for(j=i-gap;key<a[j] && j>=first;j=j-gap)//두번째 항부터 시작해서 올바른 자리가 나올 때까지 미뤄준다. 그리고 그 자리에 값을 넣어준다.
			a[j+gap]=a[j];
		a[j+gap] = key;
	}
}
void shellSort(int *a,int n){
	for(int gap = n/2;gap>0;gap/=2){
		if(gap%2 == 0)
			gap++;
		for(int j=0;j<gap;j++)
			sortGapInsertion(a,j,n-1,gap);
	}
}
////////////////////////////////////////////////////////////////////////////////////

void merge(int *arr,int left, int mid, int right){
	int n = right - left;
	int b[n];
	int x=left, y=mid+1;
	for(int i = 0;i<=n;i++){
		if(arr[x] < arr[y] && x<=mid)
			b[i] = arr[x++];
		else if(arr[x] > arr[y] && y<=right)
			b[i] = arr[y++];
	}
	for(int i = left;i<right;i++)
		arr[i] = b[i];
}
void mergeSort(int * arr,int left, int right){//왼쪽 오른쪽 나누어서 정렬 그걸또 두개로 나누어서 정렬하는 방식이다. 작은 범위에서부터 점점 범위가 커진다.
	if(left<right){//순환할때 제한을 걸어둔것이다. 부분 리스트가 한개가 될때 까지 나누어 진후 다시 합쳐진다.
		int mid = (left + right)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////

void radixSort(int *arr, int n){
	queue<int> que[10];
	int factor =1;
	for(int i=0;i<4;i++){
		for(int j=0;j<n;j++)
			que[(arr[i]/factor)%10].push(arr[i]);//일의 자리에 따라 숫자가 들어간다.
		for(int b=j=0;b<10;b++)                    //버킷안에 들어간 애들을 꺼내어 다시 리스트로 만든다. 일의 자리에따라 정렬된 상태임 계속 반복하면 완벽히 정렬됨
			while(!que.empty()){
				arr[j] = que[b].front();
				que[b].pop();
			}
		factor+=10;

	}
}
