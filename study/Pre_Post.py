import sys

class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.head = None
    def findNode(self, data):
        parent = None
        point = self.head
        while point is not None:
            if point.data < data:
                parent = point
                point = point.right
            elif point.data > data:
                parent = point
                point = point.left
            else:
                break
        return point, parent
    
    def insert(self, data):
        node, p = self.findNode(data)
        if node is not None and data == node.data:
            return None
        new = Node(data)
        if p is None:
            self.head = new
        elif data < p.data:
            p.left = new
        else:
            p.right = new
        return node

    def postorder(self, node):
        if node is not None:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node.data)
        
sys.setrecursionlimit(10**8)  
bt=BinaryTree()        

for i in range(10000):
    try:
        n = int(sys.stdin.readline().rstrip())
        bt.insert(n)
    except:
        break

bt.postorder(bt.head)
