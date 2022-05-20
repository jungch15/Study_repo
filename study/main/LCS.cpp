#include <iostream>
#include <cstring>
using namespace std;
int samething(char* str1, char* str2,int left1, int left2){
	int n1 = strlen(str1), n2 = strlen(str2);
	bool same = false;
  int i,j;
	for(i=left1;i<n1;i++){
		for(j=left2;j<n2;j++)
			if(str1[i] == str2[j]){
				cout<<i<<"   "<<j<<endl;
				same = true;
				break;
			}
		if(same)
			break;
	}
	if(!same)
		return 0;
	return 1 + samething(str1,str2,i+1,j+1);
	
}
//
int equalthing(char* str1, char* str2, char* str3, int left1, int left2, int left3){
	int n1 = strlen(str1), n2 = strlen(str2), n3 = strlen(str3);
	bool same = false;
  int i,j,k;
	for(i=left1;i<n1;i++){
		for(j=left2;j<n2;j++){
			for(k=left3;k<n3;k++)
				if(str1[i] == str2[j]){
					same = true;
					break;
				}
			if(same)
				break;
			}
		if(same)
			break;
	}
	if(!same)
		return 0;
	return 1 + equalthing(str1,str2,str3,i+1,j+1,k+1);
	
}
int newLCS(char * str1, char * str2, char * str3){ //it seems to work hard. i think it can be writed simpler.
	int arr[6];//it must have 6 space. because the count of strings is 3, and pactorial(3) is 6. 
	arr[0] = equalthing(str1,str2,str3,0,0,0);
	arr[1] = equalthing(str2,str1,str3,0,0,0);
	arr[2] = equalthing(str1,str3,str2,0,0,0);
	arr[3] = equalthing(str2,str3,str1,0,0,0);
	arr[4] = equalthing(str3,str2,str1,0,0,0);
	arr[5] = equalthing(str3,str1,str2,0,0,0);
	int max=0;
	for(int i=0;i<6;i++)//the max value is comfotable to find. because the values are stored in array.
		if(max<arr[i])
			max = arr[i];
	return max;
}
int LCS(char * str1, char * str2){
	int one = samething(str1,str2,0,0);
	int two = samething(str2,str1,0,0);
	cout<<one<<"   "<<two<<endl;
	return one>two?one:two;
    //start point that has same value is derived.
    //based on this point, execute repeatation.
}
//the way of upper direction is so complex. i present second way
//the second way is that first, compare a and b, second, made LCS of a,b, third compare LCS and c, forth, print max LCS value. 
//samething(char* str1,char* str2,int left1, int left2, char * arr) -> the arr is the array made by the function newly. this way is more efficient.
int main()
{
	char str1[100], str2[100], str3[100];
	cin>>str1;
	cin>>str2;
	cin>>str3;
	int lcs = newLCS(str1,str2,str3);
	cout<<lcs;

    return 0;
}
