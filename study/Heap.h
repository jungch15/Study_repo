

#ifndef HEAP_H_
#define HEAP_H_

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


//정렬되지 않은 배열을 이용한 우선순위 큐
class MaxPriorityQueue{
private:
	int elem[MAX_DEGREE];
	int size;
public:
	MaxPriorityQueue(int s=0): size(s){}
	void insert(int elem){this->elem[++size] = elem;}
	int remove(){
		//최대값 찾고 출력
		int max=elem[1];
		int position = find();
		for(int i=position;i<=size;i++)
			elem[i] = elem[i+1];
		size--;
		return max;
	}
	int find(){
		int max=elem[1];
		int position = 1;
		for(int i=2;i<=size;i++)
			if(max<elem[i])
				position = i;
		return position;
	}
	void display(){
		for(int i=1;i<=size;i++)
			printf("%d ",elem[i]);
		printf("\n");
	}


	bool isHeapRecur(int a[], int size){
			//부모의 키값 > 자식의 키 값
			if(a[size] > a[size/2])
				return false;
			if(size == 0)
				return true;
			return isHeapRecur(a,size/2);
		}
		bool isHeapIter(int a[], int size){
			int i=size;
			for(i=size;i>0;i--){
				if(i == 1)
					continue;
				if(a[i] >= a[i/2])
					break;
			}
			if(i == 0)
				return true;
			else
				return false;
		}
};

//정렬된 연결리스트를 이용한 우선순위 큐

class Node{
private:
	int key;
	Node* link;
public:
	Node(int k):key(k),link(NULL){}
	int getKey(){return key;}
	Node* getLink(){return link;}
	void insert(Node* n){  //다음 항에 값을 추가
		n->link = link;
		link = n;
	}
	Node* remove(){// 다음 항값 삭제
		if(link == NULL) return NULL;
		Node* removed = link;
		link = removed->link;
		return removed;

	}
	void display(){printf("%d ",key);}

};

class MinPriorityQueue{
private:
	Node* min;
	int size;
public:
	MinPriorityQueue(int s=0):min(NULL),size(s){}
	bool isEmpty(){return size ==0;}
	void insertNode(Node* n){
		if(isEmpty()){
			min = n;
			size++;
			return;
		}
		if(min->getKey()>n->getKey()){
			Node* c = min;
			min = n;
			min->insert(c);
			size++;
			return;
		}
		Node* i;
		for(i = min;i->getLink()!=NULL;i=i->getLink()){
			if(i->getLink()->getKey() > n->getKey()){
				i->insert(n);
				size++;
				return;
			}
		}
		i->insert(n);
		size++;
	}
	Node* find(){return min->getLink();}
	Node* removeNode(){
		size--;
		return min = min->getLink();
	}
	void display(){
		for(Node* i = min;i!=NULL;i = i->getLink())
			i->display();
		printf("\n");
	}
};



//힙정렬
void heapSort(int a[],int n){
	MaxHeap heap;
	for(int i=0;i<n;i++)
		heap.insert(a[i]);
	for(int i = n-1;i >=0;i--)
		a[i] = heap.remove().getKey();
}

void heapSortDec(int a[],int n){
	priority_queue<int> maxHeap;
	for(int i=0;i<n;i++)
		maxHeap.push(a[i]);
	for(int i = 0;i<n;i--){
		a[i] = maxHeap.top();
		maxHeap.pop();
	}
}

void heapSortInc(int a[],int n){
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i=0;i<n;i++)
		minHeap.push(a[i]);
	for(int i = 0;i<n;i--){
		a[i] = minHeap.top();
		minHeap.pop();
	}
}

#endif /* HEAP_H_ */
