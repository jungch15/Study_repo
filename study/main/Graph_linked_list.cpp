삭제연산 관련해서는 아직 구현 x

class Node{
private:
	int id;
	Node* link;
public:
	Node(int id=0, Node* n=NULL):id(id),link(n){}
	~Node(){if(link != NULL) delete link;}
	int getId(){return id;}
	Node* getLink(){return link;}
	void setLink(Node* n){link =n;}
	void display(){printf("%3d ",id);}
};

class AdjListGraph{
protected:
	int size;
	char vertices[MAX_SIZE];
	Node* adj[MAX_SIZE];
public:
	AdjListGraph():size(0){}
	~AdjListGraph(){reset();}
	bool isEmpty(){return size == 0;}
	bool isFull(){return size >= MAX_SIZE;}
	char getVertex(int i){return vertices[i];}
	int getSize(){return size;}
	void reset(){
		for(int i=0;i<size;i++){
			if(adj[i] != NULL) delete adj[i];
		}
		size =0;
	}

	void insertVertex(char v){
		if(!isFull()){
			vertices[size] = v;
			adj[size++] = NULL;
		}
		else printf("초과다");
	}
	void deleteVertex(int v){}
	void insertEdge(int u, int v){
		adj[u] = new Node(v,adj[u]);
		adj[v] = new Node(u,adj[v]);
	}
	void deleteEdge(int u,int v){}
	Node* adjacent(int v){return adj[v];}
	void display(){
		printf("%d\n",size);
		for(int i=0;i<size;i++){
			printf("%c ", getVertex(i));
			for(Node* n = adj[i];n!=NULL;n=n->getLink())
				printf("%c ",getVertex(n->getId()));
			printf("\n");
		}
	}
};
