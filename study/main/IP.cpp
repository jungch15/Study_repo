//가능한 ip를 모두 출력하는 문제

#include <iostream>
#include <cstring>
using namespace std;

//함수를 두 개로 나눈다. 첫번째는 숫자를 주고 그걸로 가능한 값을 출력하는 함수 두 번째는 얼마만큼의 숫자를 줄건지 결정하는 함수
int pactorial(int a){
	if(a == 0)
		return 1;
	return a*pactorial(a-1);
}
void movePosition(int &x, int &y,int &z,int b){//점들을 이동하게 하는 함수
    if(z!=b-1)
	        z++;
	else{
	    if(y!=z-1){
	        y++;
	        z=y+1;
	        
	    }
	    else if(x!=y-1){
	        x++;
	        y=x+1;
	        z=y+1;
	    }
	}
}
void printIp(int * arr, int a, int b){
	int length = b-a+1;
	int x=a, y=x+1, z=y+1;//점이 박힐 자리를 나타낸다. 두점의 차이는 두 점사이의 정수의 자릴수를 나타낸다.점다음 정수는 x+1부터 시작
	int num = pactorial(length-1)/pactorial(length-4)/pactorial(3); //이 개수만큼 4개 정수 쌍이 나온다.
	for(int i=0;i<num;i++){
		if((x-a > 0 && arr[a] == 0 )|| x-a > 2){
			movePosition(x,y,z,b);
			continue;
		}
		if(x-a == 2)
			if(arr[a]*100 + arr[a+1]*10 + arr[a+2] >255){//첫번째 정수와 나머지 정수의 조건이 조금 다르다. 처음에는 자기자신이 알아서 들어가 있는 반면 그 다음 정수에서부턴 내가 직접 넣어야한다 해서 -1을 더 해주었다.
			    movePosition(x,y,z,b);                   //두번째 부턴 점에 의해 표시가 되기 때문에 +1을 해주고 첫번째는 점에 의해 표시되는게 아니라 그냥 하면 된다.
			    continue;
			}//여기까지가 첫번째 정수의 조건이다.
		if((y-x>1 && arr[x+1] == 0)|| y-x > 3){
		    movePosition(x,y,z,b);
			continue;
		}
		if(y-x-1 == 2)
			if(arr[x+1]*100 + arr[x+2]*10 + arr[x+3] >255){
			    movePosition(x,y,z,b);
			    continue; 
			}//여기까지가 두번째 정수의 조건이다.
		if((z-y>1 && arr[y+1] == 0) || z-y > 3){
			movePosition(x,y,z,b);
			continue;
		}
		if(z-y-1 == 2)
			if(arr[y+1]*100 + arr[y+2]*10 + arr[y+3] >255){
				movePosition(x,y,z,b);
			    continue;
	        } //여기까지가 세번째 정수의 조건이다.
		if((b-z>1 && arr[z+1] == 0) || b-z > 3){
			movePosition(x,y,z,b);
			continue;
	    }
		if(b-z-1 == 2)
			if(arr[z+1]*100 + arr[z+2]*10 + arr[z+3] >255){
				movePosition(x,y,z,b);
			    continue;
			}//여기까지가 네번째 정수의 조건이다.
		//아래는 출력하는 것이다.
		for(int i=0;i<=x;i++)
			std::cout<<arr[i];
		std::cout<<".";
		for(int i=x+1;i<=y;i++)
			std::cout<<arr[i];
		std::cout<<".";
		for(int i= y+1;i<=z;i++)
			std::cout<<arr[i];
		std::cout<<".";
		for(int i= z+1;i<=b;i++)
			std::cout<<arr[i];
		cout<<endl;
	   movePosition(x,y,z,b);
        
	}
}
//배열을 잘라서 넘겨줄 때, 처음부터 최소 길이부터 최대 길이까지 잘라서 넘겨주고 문자열의 끝까지 닿도록 반복해준다.
void ipValue(char * str){
    int * arr = new int[strlen(str)];//동적할당으로 배열 생성 -> 입력할때 char형으로 받아서 숫자의 개수만큼 길이를 정해준다.
    for(int i=0;i<strlen(str);i++)
        arr[i] = str[i]-'0';//문자이기 때문에 0을 빼줘서 올바른 숫자가 저장될 수 있도록 한다.
    //최소 길이: 4 /최대 길이: 12
    int start=0, finish=0;
    int i=3;
    while(str[start+3] != 0){ //문자열에서 0은 \0 즉 문자열의 끝을 나타낸다. 최소 길이가 4이기 때문에 4를 더해주었다.
        for(i=3;i<12;i++){
            finish = start+i;//3부터 11까지 start에 더해준 값을 finish라고 한다. 
            printIp(arr,start,finish);
            if(strlen(str)-1 == start+i)
                break;
        }
        if(strlen(str)-1 == start+i)
            break;
        start++;
    }
}

int main(){
    char str[3000];
    cin>>str;
    int * arr = new int[strlen(str)];//동적할당으로 배열 생성 -> 입력할때 char형으로 받아서 숫자의 개수만큼 길이를 정해준다.
    for(int i=0;i<strlen(str);i++)
        arr[i] = str[i]-'0';//문자이기 때문에 0을 빼줘서 올바른 숫자가 저장될 수 있도록 한다.
    //ipValue(str);//문제 의도와 다르다
    printIp(arr,0,strlen(str)-1);
    return 0;
}

