#ifndef WGRAPHMST_H_
#define WGRAPHMST_H_

#include "WGraph.h"

class VertexSets{
private:
	int parent[MAX_SIZE];
	int nSets;
public:
	VertexSets(int n): nSets(n){
		for(int i=0;i<nSets;i++)
			parent[i] = -1;//모두 루트로 정해준다.
	}
	bool isRoot(int i){return parent[i]<0;}
	int findSet(int i){
		while(!isRoot(i)) i = parent[i];
		return i;
	}
	void unionSets(int s1, int s2){
		parent[s1] = s2;
		nSets--;
	}
};

//힙에 저장할 노드 클래스
class HeapNode{
private:
	int key;
	int v1;
	int v2;
public:
	HeapNode(int k=0, int u=0, int v=0):key(k),v1(u),v2(v){}
	void setKey(int k,int u, int v){key =k; v1 =u; v2=v;}
	int getKey(){return key;}
	int getV1(){return v1;}
	int getv2(){return v2;}
	void display(){
		printf("%d, %d, %d\n",key,v1,v2);
	}
};

class MinHeap{
private:
	HeapNode node[MAX_SIZE];
	int size;
public:
	MinHeap(int s=0): size(s){
		//resetNode();
	}
	void resetNode(){
		//for(int i=0;i<MAX_SIZE;i++)
			//node[i] = HeapNode(0);
		size=0;
	}
	bool isEmpty(){return size == 0;}
	bool isFull(){return size == MAX_SIZE-1;}
	HeapNode& getParent(int i){return node[i/2];}
	HeapNode& getLeft(int i){return node[i*2];}
	HeapNode& getRight(int i){return node[i*2+1];}
	int getSize(){return size;}
	void displayHeap(){
		for(int i=1;i<=size;i++)
			node[i].display();
		printf("\n");
	}
	void insert(int key,int u,int v){//힘에 삽입이 제대로 안되는같은데......  getParent같은 함수들이 적용되지 않는다. 
			if(isFull()) return;
			size++;
			int i=0;
			for(i= size;i!=1;i/=2){
				if(key < node[i/2].getKey())
					node[i] = node[i/2];
				else
					break;
			}
			node[i].setKey(key,u,v);
		}
	HeapNode remove(){ //두고두고 보도록 하자 내가 한게 아니다.
		//if(isEmpty()) return NULL;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while(child <= size){
			if(child< size && node[parent*2+1].getKey() < node[parent*2].getKey())
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
};

//Kruskal의 최소비용 신장 트리
class WGraphMST: public WGraph{//책보고 따라함
public:
	WGraphMST():WGraph(){}
	void Kruskal(){
		MinHeap heap;
		heap.resetNode();

		for(int i=0;i<size-1;i++)
			for(int j=i+1;j<size;j++)
				if(hasEdge(i,j))
					heap.insert(getEdge(i,j),i,j);

		heap.displayHeap();
		VertexSets set(size);
		int edgeAccepted=0;
		//HeapNode e = heap.remove();
		//printf(" %d ",e.getKey());
		//heap.displayHeap();
		//HeapNode d = heap.remove();
		//printf(" %d ",d.getKey());
		while(edgeAccepted < size-1){
			HeapNode e = heap.remove();
			int uset = set.findSet(e.getV1());
			int vset = set.findSet(e.getv2());
			if(uset != vset){
				printf("간선추가: %c - %c (비용: %d)\n",getVertex(e.getV1()),getVertex(e.getv2()),e.getKey());
				set.unionSets(uset,vset);
				edgeAccepted++;
			}
		}

	}
	void prim(int s=0){   //이건 됨 위에 거는 상속에 쫌 꼬여 있어서 오류가 생기는 듯하다 
		bool selected[MAX_SIZE];
		int dist[MAX_SIZE];
		for(int i=0;i<size;i++){
			dist[i] = INF;
			selected[i] = false;
		}
		dist[0]=0;
		for(int i=0;i<size;i++){
			int u = getMinVertex(selected,dist);
			selected[u] = true;
			if(dist[u] == INF) return; //신장트리가 아니다 가장 작은 거리가 INF다 -> 이어져있지 않다.
			printf("%c",getVertex(u));
			for(int j=0;j<size;j++)
				if(getEdge(u,j) != INF)
					if(!selected[j] && getEdge(u,j) < dist[j])
						dist[j] = getEdge(u,j);
		}
		printf("\n");
	}

	int getMinVertex(bool* selected,int* dist){
		int minv=0;
		int mindist=INF;
		for(int i=0;i<size;i++)
			if(!selected[i])
				if(mindist > dist[i]){
					mindist = dist[i];
					minv = i;
				}
		return minv;
	}
};

#endif /* WGRAPHMST_H_ */
