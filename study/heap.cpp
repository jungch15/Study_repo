#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

#define MAX_DEGREE 200

class HeapNode{
private:
	int key;
public:
	HeapNode(int key =0): key(key){}
	void setKey(int k){key = k;}
	int getKey(){return key;}
	void display(){ printf("%d ",key);}
};

class MaxHeap{
private:
	HeapNode node[MAX_DEGREE];
	int size;
public:
	MaxHeap(): size(0){}
	bool isEmpty(){return size == 0;}
	bool isFull(){return size == MAX_DEGREE-1;}
	HeapNode& getParent(int i){return node[i/2];}
	HeapNode& getLeft(int i){return node[i*2];}
	HeapNode& getRight(int i){return node[i*2+1];}
	void insert(int key){
		if(isFull()) return;
		size++;
		int i=0;
		for(i= size;i!=1;i/=2){
			if(key > getParent(i).getKey())
				node[i] = getParent(i);
			else
				break;
		}
		node[i].setKey(key);

	}
	HeapNode remove(){ //두고두고 보도록 하자 내가 한게 아니다.
		if(isEmpty()) return NULL;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while(child <= size){
			if(child< size && getRight(parent).getKey() > getLeft(parent).getKey())
				child++;
			if(last.getKey() > node[child].getKey())
				break;
			node[parent] = node[child];
			parent = child;
			child*=2;
		}
		node[parent] = last;
		return item;
	}
	HeapNode find(){ return node[1];}
	void display(){
		for(int i=1, level =1;i<=size;i++){
			if(i == level){
				printf("\n");
				level*=2;
			}
			node[i].display();
		}
		printf("\n");
	}

};

class MinHeap{
private:
	HeapNode node[MAX_DEGREE];
	int size;
public:
	MinHeap(): size(0){}
	bool isEmpty(){return size == 0;}
	bool isFull(){return size == MAX_DEGREE-1;}
	HeapNode& getParent(int i){return node[i/2];}
	HeapNode& getLeft(int i){return node[i*2];}
	HeapNode& getRight(int i){return node[i*2+1];}
	void insert(int key){
		if(isFull()) return;
		size++;
		int i=0;
		for(i= size;i!=1;i/=2){
			if(key < getParent(i).getKey())
				node[i] = getParent(i);
			else
				break;
		}
		node[i].setKey(key);

	}
	HeapNode remove(){ //두고두고 보도록 하자 내가 한게 아니다.
		if(isEmpty()) return NULL;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while(child <= size){
			if(child< size && getRight(parent).getKey() < getLeft(parent).getKey())
				child++;
			if(last.getKey() <= node[child].getKey())
				break;
			node[parent] = node[child];
			parent = child;
			child*=2;
		}
		node[parent] = last;
		return item;
	}
	HeapNode find(){ return node[1];}
	void display(){
		for(int i=1, level =1;i<=size;i++){
			if(i == level){
				printf("\n");
				level*=2;
			}
			node[i].display();
		}
		printf("\n");
	}

};
