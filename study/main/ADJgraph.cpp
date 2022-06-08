class AdjMatGraph{
protected:
	int size;
	char *vertices;
	int **adj;
public:
	AdjMatGraph(int s=0):size(s){
		vertices = new char[MAX_SIZE];
		adj = new int*[MAX_SIZE];
		for(int i=0;i<MAX_SIZE;i++)
			adj[i] = new int[MAX_SIZE];
		reset();
	}
	~AdjMatGraph(){
		delete[] vertices;
		for(int i=0;i<MAX_SIZE;i++)
			delete[] adj[i];
		delete[] adj;
	}
	char getVertex(int i){return vertices[i];}
	int getEdge(int i,int j){return adj[i][j];}
	void setEdge(int i, int j, int val){adj[i][j] = val;}
	int getSize(){return size;}
	bool isEmpty(){return size==0;}
	bool isFull(){return size >=MAX_SIZE;}

	void reset(){
		for(int i=0;i<MAX_SIZE;i++)
			for(int j=0;j<MAX_SIZE;j++)
				setEdge(i,j,0);
		size =0;
	}

	void insertVertex(char v){
		if(!isFull()) vertices[size++] = v;
		else printf("초과");
	}
	//무방향그래프의 경우이다. 값이 없다는걸 0으로 표현함
	void deleteVertex(int v){
		for(int i=0;i<size;i++){
			adj[v][i] = 0;
			adj[i][v] = 0;
		}
		vertices[v] = 0;
		size--;             //이게 줄어들면 특정 값에 접근 못할 수도 있다 나중에 수정해보자
	}
	//무방향 그래프의 경우이다.
	void insertEdge(int u, int v){
		setEdge(u,v,1);
		setEdge(v,u,1);
	}
	void deleteEdge(int u, int v){}
	//int* adjacent(int v){}  뭐하는 애냐
	void display(FILE* fp = stdout){
		fprintf(fp,"%d\n",size);
		for(int i=0;i<size;i++){
			fprintf(fp,"%c ", getVertex(i));
			for(int j=0;j<size;j++)
				fprintf(fp," %3d",getEdge(i,j));
			fprintf(fp,"\n");
		}
	}

	void load(char* filename){
		FILE* fp = fopen(filename,"r");
		if(fp != NULL){
			int n=0;
			fscanf(fp,"%d",&n);
			for(int i=0;i<n;i++){
				char str[80];
				fscanf(fp,"%s",str);
				insertVertex(str[0]);
				for(int j=0;j<n;j++){
					int val;
					fscanf(fp,"%d",&val);
					if(val !=0)
						insertEdge(i,j);
				}
			}
			fclose(fp);
		}
	}
	void store(char* filename){
		FILE* fp = fopen(filename,"w");
		if(fp!= NULL){
			display(fp);
			fclose(fp);
		}
	}
};
