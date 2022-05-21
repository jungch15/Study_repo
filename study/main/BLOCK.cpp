#include <iostream>

int addBlock(int ** arr,int num){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)
            std::cout<<arr[i][j]<<" ";
        std::cout<<std::endl;
    }
    int colMax=0, rowMax=0, smallMax =0;
    int result = 0;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            for(int k=0;k<num;k++)
                if(rowMax < arr[i][k])
	                rowMax = arr[i][k];//그 행에서의 최대값
            for(int k=0;k<num;k++)
	            if(colMax < arr[k][j])
	                colMax = arr[k][j];//그 열에서의 최대값
	        
	        smallMax = colMax > rowMax? rowMax: colMax; // 계산할 최대값을 구해줬다.
	        result  +=smallMax - arr[i][j];
	        rowMax =0;
	        colMax =0;
        }
    }
   
    return result;	
}

int main(){
    int num;
    std::cin>>num; //nxn배열에서 n에 해당하는 숫자 배정
    getchar();  //getc함수의 경우 엔터도 버퍼에 저장이 된다. 하여 내가 입력하지도 않았는데 저절로 입력되는 상황이 발생한다. 이를 대비하여 하나의 버퍼를 소모시키도록 추가한 문장이다.
    int ** arr = new int*[num];
    for(int i=0;i<num;i++)
        arr[i] = new int[num];    //addBlock함수에 넣어주기 위해 동적할당 함 이렇게 하지 않으면 크기가 정해진 이차원 배열만 함수에 넣어줄 수 있다.
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)
	        arr[i][j] = getc(stdin)-'0';   //블록 쌓기
        getchar();// 위의 경우와 마찬가지로 getc함수는 엔터까지 입력을 받기 때문에 버퍼에서 엔터값을 없애주기 위해 getchar를 사용하였다.
    }
    int count = addBlock(arr,num);
    std::cout<<"추가해도 되는 블록의 최소 개수는 "<<count<<"이다.";
    return 0;
