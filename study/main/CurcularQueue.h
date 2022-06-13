/*
 * CircularQueue.h
 *
 */

#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_

#include <cstdio>

#define MAX_SIZE 100

inline void error(const char * str){
	printf("%s",str);
}

class CircularQueue{
protected:
	int front;
	int rear;
	int data[MAX_SIZE];
public:
	CircularQueue(){front = rear = 0;}
	bool isEmpty(){
		return front == rear;  //MAX_SIZE로 나누는 것은 밑에서 해주기 때문에 따로 나머지 연산을 할 필요는 없다.
	}
	bool isFull(){
		return (rear+1)%MAX_SIZE == front; // rear은 MAX_SIZE-1까지 값을 가진다(그 때 front는 0)하여 +1할 경우 MAX_SIZE가 되므로 나머지 연산을 해주어야 0값을 가질 수 가 있다.
	}
	void enqueue(int a){
		if(isFull())
			error("overflow");
		rear = (rear+1)%MAX_SIZE;
		data[rear] = a;
	}
	int dequeue(){
		if(isEmpty())
			error("underflow");
		front = (front +1)%MAX_SIZE;
		return data[front];
	}
	int peek(){
		if(isEmpty())
			error("underflow");
		return data[(front+1)%MAX_SIZE];
	}
	void display(){
		int max = front<rear? rear: rear+MAX_SIZE;  //front<rear인 것은 자명하다 만약 아니라면, rear가 MAX_SIZE값을 넘어선거기 때문에 MAX_SIZE를 더해준다.
		for(int i=front+1;i<=max;i++)
			printf("%d ",data[i%MAX_SIZE]); //rear의 값이 front보다 작을 경우 0부터 다시 출력해야하므로 MAX_SIZE로 나머지 연산을 해주었다.
		printf("\n");
	}
};

#endif /* CIRCULARQUEUE_H_ */
