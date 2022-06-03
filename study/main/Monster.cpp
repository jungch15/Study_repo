#include <iostream>

using namespace std;


class Monster{
private:
	bool islive;
	int x;
	int y;
	int direct;
public:
	Monster(int x=0, int y=0, char dir='E'):islive(true), x(x), y(y){
		switch(dir){
			case 'E':
				direct = 0;
				break;
			case 'W':
				direct = 1;
				break;
			case 'S':
				direct = 2;
				break;
			case 'N':
				direct = 3;
				break;
		}
	}
	int getx(){return x;}
	int gety(){return y;}
	bool live(){return islive;}
	void dead(){islive = false;}
	void print(){cout<<x<<" "<<y<<" "<<direct<<endl;}
	void move(int num){// this function move one time by direction
		switch(direct)
		{
			case 0:
			x+=num;
			break;
			case 1:
			x-=num;
			break;
			case 2:
			y-=num;
			break;
			case 3:
			y+=num;
			break;
		}
	}
	void changeDirection(char LR){ //this function change direction
		if(LR == 'R')
			direct = (direct+1)%4;
		else{
			if(direct == 'E')
				direct = 'N';
			else
				direct -=1;
		}
		cout<<"change Direction"<<endl;
	}


};
void order(int **arr,int w, int h, Monster * swarm,int i, char LRF,int num){
	if(swarm[i].live() == false){
		cout<<"M "<<i<<" is none"<<endl;
		return;
	}
	switch(LRF){
		case 'L':
			swarm[i].changeDirection('L');
			break;
		case 'R':
			swarm[i].changeDirection('R');
			break;
		case 'F':
		    arr[h-swarm[i].gety()][swarm[i].getx()-1] =0;//original value
			swarm[i].move(num); //move
			if(swarm[i].getx() <= -1 || swarm[i].gety() <= -1 ||
				swarm[i].getx() >= w || swarm[i].gety() >= h){
				cout<<"M "<<i<<" touched the wall"<<endl;
				swarm[i].dead();
				break;
			}
			int a = arr[h-swarm[i].gety()][swarm[i].getx()-1]; //position moved by using (move) function
			cout<<a<<endl;
			if(a != 0){
				swarm[a].dead();// this monster is dead;
				cout << "M "<<i<<" eats M "<<a<<endl;
			}
			if(swarm[i].live())
				arr[h-swarm[i].gety()][swarm[i].getx()-1] = i;
			break;

	}
}
int main()
{
	int width, height,n,m;
	cin>>width>>height;
	cin>>n>>m;
//	cout<<width<<height<<n<<m<<endl;
	int **arr = new int*[height];
	for(int i=0;i<height;i++)
		arr[i] = new int[width];
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
			arr[i][j] = 0;
	int x, y,a;
	a=0;
	char direct;
	Monster *swarm = new Monster[width*height];
	for(int i=0;i<n;i++){
		cin>>x>>y>>direct;
		swarm[i+1] = Monster(x,y,direct);
		arr[height-y][x-1] = ++a;
	}
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++)
			cout<<arr[i][j];
		cout<<endl;
	}
	int name,num;
	char orderin;
	for(int i=0;i<m;i++){
		cin>>name>>orderin>>num;//repeat as much as num
		order(arr,width,height,swarm,name,orderin,num);
	}
	for(int i=1;i<=a;i++){
		if(swarm[i].live())
			cout<<"M "<<i<<" survived"<<endl;
		if(i == a && swarm[i].live() == false)
			cout<<"Monster does not exist"<<endl;
	}
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++)
			cout<<arr[i][j];
		cout<<endl;
	}
	return 0;
}
