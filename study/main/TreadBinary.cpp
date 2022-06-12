include iostream

class ThreadedBinNode{
private:
	int data;
	ThreadedBinNode* left;
	ThreadedBinNode* right;
public:
	bool bThread;
	ThreadedBinNode(int d, ThreadedBinNode* l,ThreadedBinNode* r, bool b): data(d),left(l),right(r),bThread(b){}
	int getData(){return data;}
	ThreadedBinNode* getLeft(){return left;}
	ThreadedBinNode* getRight(){return right;}
	void setData(int d){data =d;}
	void setLeft(ThreadedBinNode* l){left = l;}
	void setRight(ThreadedBinNode* r){right = r;}

};

class ThreadedBinTree{
private:
	ThreadedBinNode* root;
public:
	ThreadedBinTree():root(NULL){}
	void setRoot(ThreadedBinNode* n){root = n;}
	bool isEmpty(){return root == NULL;}

	void inorder(){
		if(isEmpty())
			return;
		ThreadedBinNode* n = root;
		while(n->getLeft() != NULL) n = n->getLeft();
		while(n != NULL){
			printf("%c",n->getData());
			n =findSuccessor(n);
		}
	}
	ThreadedBinNode* findSuccessor(ThreadedBinNode* n){
		ThreadedBinNode* p = n->getRight();
		if(n->bThread || p == NULL)
			return p;
		while(p->getLeft() != NULL)
			p = p->getLeft();
		return p;
	}

};
