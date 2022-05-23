#include <iostream>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

//가구수 파악
//일단 2차원 배열에 입력해주고 큐 혹은 스택을 사용하여탐색을 하자 
//이미 간 곳을 표시해주기 위하 같은 크기의 2차원 배열을 선언하고 지날 때마다 표시를 해준다

class Point{
private:
    int x;
    int y;
public:
    Point(int x,int y):x(x),y(y){}
		int getx(){return x;}
		int gety(){return y;}
};
class HousingEstate{
private:
    int **arr;
    int n;
public:
    HousingEstate(int num){
        n=num;
        arr = new int*[n];
        for(int i=0;i<n;i++)
            arr[i] = new int[n];
        for(int i=0;i<n;i++){//여기서 setArr함수를 사용하여 원하는 값으로 초기화한다.
            char str[n+1];
            cin>>str;
            setArr(i,str);
        }
    }
    void setArr(int num,char *str){//private로 선언된 arr에 값을 넣어주는 함수이다. 단, 한 줄만 넣어준다 하여 n번 반복해야 다 넣어줄 수 있다.
      
			for(int i=0;i<n;i++)
            arr[num][i] = str[i]-'0';
    }
    bool isConnect(int i, int j){
        if(i>=n || i<0|| j>=n || j<0 || arr[i][j] == 0)
            return false;
        return true;
    }
    
    void search(){//search, and disunite
				int count =0;
				list<int> list;
				int houseNum=1;
       	bool visited[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                visited[i][j] = false;//visited를 0으로 초기화해준다.
        queue<Point> que;
        for(int i=0;i<n;i++)
					for(int j=0;j<n;j++){
						if(visited[i][j]==false && arr[i][j] == 1){
							houseNum =1;
							count++;
							que.push(Point(i,j));
							visited[i][j] = true;
						}
						bool isrun = false;
						while(!que.empty()){//if the elements were connect, insert same data into arr
							Point position = que.front(); que.pop(); //remove front element in que
							int x = position.getx(), y = position.gety();
							arr[x][y] = count;
							if(isConnect(x-1,y) && visited[x-1][y] == 0){//left
								que.push(Point(x-1,y));
								visited[x-1][y] =1;
								houseNum++;
								isrun = true;
							}
							if(isConnect(x+1,y) && visited[x+1][y] == 0){//right
								que.push(Point(x+1,y));
								visited[x+1][y] =1;
								houseNum++;
								isrun = true;
							}
							if(isConnect(x,y-1) && visited[x][y-1] == 0){//down
								que.push(Point(x,y-1));
								visited[x][y-1] =1;
								houseNum++;
								isrun = true;
							}
							if(isConnect(x,y+1) && visited[x][y+1] == 0){//up
								que.push(Point(x,y+1));
								visited[x][y+1] =1;
								houseNum++;
								isrun = true;
							} //I think it was so difficult. it was more simple in past
						}
						if(isrun == true)
							list.push_back(houseNum);
					}
        
			cout<<count<<endl;
			for(int i=0;i<count;i++){
				cout<<list.front()<<endl;
				list.pop_front();
			}
    }
	void printArr(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<arr[i][j]<<" ";
		cout<<endl;
		}
	}
};


int main()
{
	int num;
	cin >> num;
	HousingEstate estate(num);
	estate.search();
	return 0;
}
//순환은 하지 않고 반복만을 이용하여 구현하였다. 이거 할때 순환으로 하겠다고 생각도 안났다. 생각하는게 좋을 듯하다.
