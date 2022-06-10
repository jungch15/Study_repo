#include "ArrayStack.h"
#include <cstring>


double calcPostfix(FILE * fp = stdin){
	doubleStack stack;
	char ch;
	while((ch = fgetc(fp)) != '\n'){ // i<strlen(str)이렇게 하면 unsigned int라고 strlen 반환값이 부로가 정해지지 않은 정수라 오류가 생긴다.
		if(ch >='0' && ch <= '9'){
			stack.push(ch-'0');
			stack.display();
		}
		else if(ch =='+'|| ch == '-'|| ch == '/' || ch == '*'){
			double second = stack.pop();
			double first = stack.pop();
			if(ch == '+')
				stack.push(first + second);
			else if(ch == '-')
				stack.push(first - second);
			else if(ch == '*')
				stack.push(first * second);
			else if(ch == '/')
				stack.push(first / second);
		}
	}
	return stack.pop();

}
int priority(char ch){
	if(ch =='*' || ch == '/')
		return 2;
	else if(ch == '+' || ch == '-')
		return 1;
	return -1;
}
void infixTopost(FILE *fp = stdin){
	doubleStack stack;
	char ch, as;
	char arr[MAX_SIZE];
	int n=0;
	while((ch = fgetc(fp))!='\n'){
		if(ch >='0' && ch <='9')
			arr[n++] = ch;
		else if(ch =='+'|| ch == '-'|| ch == '/' || ch == '*' || ch =='(' || ch == ')'){
			if(stack.isEmpty() || stack.peek() == '(' || ch == '(')
				stack.push(ch);
			else if(ch == ')')
				while((as =stack.pop()) != '(')
					arr[n++] = as;
			else{
				while(!stack.isEmpty()){
					if(priority(ch) <= priority(stack.peek()))
						arr[n++] = stack.pop();
					else break;
				}
				stack.push(ch);
			}
		}
	}
	while(!stack.isEmpty())
		arr[n++] = stack.pop();
	arr[n] =0;
	printf("%s",arr);
}

void searchExit(int (*map)[5]){
	twoArrayStack stack;
	Point position;
	int i=0, j=0, a=0, b=0;
	printf("출발");
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(map[i][j] == 'e'){
				position = Point(i,j);  //입구를 현재 위치로
				a=i, b=j;
				break;
			}
	while(map[a][b] != 'x'){
		map[a][b] = 'g';
		if(map[a-1][b] != '1' && map[a-1][b] != 'g'){
			if(!(a-1<0))
				stack.push(a-1,b);
		}
		if(map[a][b-1] != '1' && map[a][b-1] != 'g'){
			if(!(b-1<0))
				stack.push(a,b-1);
		}
		if(map[a+1][b] != '1' && map[a+1][b] != 'g'){
			if(!(a+1>4))
				stack.push(a+1,b);
		}
		if(map[a][b+1] != '1' && map[a][b+1] != 'g'){
			if(!(b+1>4))
				stack.push(a,b+1);
		}
		stack.display();
		position = stack.pop();
		a = position.getx();
		b = position.gety();
	}
	printf("출구는: %d %d",a,b);
}
int main(){
	int map[5][5] = {
			{'0','e','0','0','0'},
			{'1','0','1','0','1'},
			{ '1','1','1','0','x'},
			{ '1','1','1','0','1'},
			{ '1','1','1','1','1'},
	};

	searchExit(map);

	return 0;
}
