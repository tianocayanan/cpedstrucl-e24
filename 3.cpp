#include <iostream>
#include <deque>
#include <climits>
#include <vector>
using namespace std;

struct Tree
{
	char data;
	Tree *left;
	Tree *right;  
	Tree *parent;  
};

Tree* lookUp(struct Tree *node, char key)
{
	if(node == NULL) return node;

	if(node->data == key) return node;
	else {
	    if(node->data < key)
		return lookUp(node->right, key) ;
	    else
		return lookUp(node->left, key);
	}
}

Tree* leftMost(struct Tree *node)
{
	if(node == NULL) return NULL;
	while(node->left != NULL)
		node = node->left;
	return node;
}

struct Tree *newTreeNode(int data) 
{
	Tree *node = new Tree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

struct Tree* insertTreeNode(struct Tree *node, int data)
{
	static Tree *p;
	Tree *retNode;

	//if(node != NULL) p = node;

	if(node == NULL)  {
	    retNode = newTreeNode(data);
	    retNode->parent = p;
	    return retNode;
	}
	if(data <= node->data ) { 
	    p = node;
	    node->left = insertTreeNode(node->left,data);
	} 
	else {
	    p = node;
	    node->right = insertTreeNode(node->right,data);
	} 
	return node;
}

void isBST(struct Tree *node)
{
	static int lastData = INT_MIN;
	if(node == NULL) return;

	isBST(node->left);

	/* check if the given tree is BST */
	if(lastData < node->data) 
	    lastData = node->data;
	else {
	    cout << "Not a BST" << endl;
	    return;
	}

	isBST(node->right);
	return;
}

int treeSize(struct Tree *node)
{
	if(node == NULL) return 0;
	else
	    return treeSize(node->left) + 1 + treeSize(node->right);
}

int maxDepth(struct Tree *node)
{
	if(node == NULL || (node->left == NULL && node->right == NULL)) 
            return 0;

	int leftDepth = maxDepth(node->left);
	int rightDepth = maxDepth(node->right);

	return leftDepth > rightDepth ? 
				leftDepth + 1 : rightDepth + 1;
}

int minDepth(struct Tree *node)
{
	if(node == NULL || (node->left == NULL && node->right == NULL)) 
            return 0;

	int leftDepth = minDepth(node->left);
	int rightDepth = minDepth(node->right);

	return leftDepth < rightDepth ? 
				leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct Tree *node)
{
	if(maxDepth(node)-minDepth(node) <= 1) 
	    return true;
	else
	    return false;
}

/* Tree Minimum */
Tree* minTree(struct Tree *node)
{
	if(node == NULL) return NULL;
	while(node->left) 
	    node = node -> left;
	return node;
}

/* Tree Maximum */
Tree* maxTree(struct Tree *node)
{
	while(node->right) 
	    node = node -> right;
	return node;
}

/* In Order Successor - a node which has the next higher key */ 
Tree *succesorInOrder(struct Tree *node)
{
	/* if the node has right child, seccessor is Tree-Minimum */
	if(node->right != NULL) return minTree(node->right);

	Tree *y = node->parent;
	while(y != NULL && node == y->right) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

/* In Order Predecessor - a node which has the next lower key */
Tree *predecessorInOrder(struct Tree *node)
{
	/* if the node has left child, predecessor is Tree-Maximum */
	if(node->left != NULL) return maxTree(node->left);

	Tree *y = node->parent;
	/* if it does not have a left child, 
	predecessor is its first left ancestor */
	while(y != NULL && node == y->left) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

void reverseOrderPrint(struct Tree *node)
{
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL) {
		cout << node->data << " ";
		return;
	}
	
	reverseOrderPrint(node->right);
	cout << node->data << " ";
	reverseOrderPrint(node->left);
}
 
Tree *lowestCommonAncestor(Tree *node, Tree *p, Tree *q) 
{
	Tree *left, *right;
	if(node == NULL) return NULL;
	if(node->left == p || node->left == q
		|| node->right == p || node->right == q) return node;
	
	left = lowestCommonAncestor(node->left,p,q);
	right = lowestCommonAncestor(node->right, p,q);
	if(left && right) 
	    return node;
	else 
	    return (left) ? left : right;	
}

void clear(struct Tree *node)
{
	if(node != NULL) {
	    clear(node->left);
	    clear(node->right);
	    delete node;
	}
}
/* print tree in order */
/* 1. Traverse the left subtree. 
   2. Visit the root. 
   3. Traverse the right subtree. 
*/

void printTreeInOrder(struct Tree *node)
{
	if(node == NULL) return;

	printTreeInOrder(node->left);
	cout << node->data << " ";
	printTreeInOrder(node->right);
}

/* print tree in postorder*/
/* 1. Traverse the left subtree. 
   2. Traverse the right subtree. 
   3. Visit the root. 
*/
void printTreePostOrder(struct Tree *node)
{
	if(node == NULL) return;

	printTreePostOrder(node->left);
	printTreePostOrder(node->right);
	cout << node->data << " ";
}

/* In reverse of printTreeInOrder() */
void printTreeReverseOrder(struct Tree *node)
{
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL) {
	    cout << node->data << " ";
	    return;
	}
	
	printTreeReverseOrder(node->right);
	cout << node->data << " ";
	printTreeReverseOrder(node->left);
}
/* recursion routine to find path */
void pathFinder(struct Tree *node, int path[], int level)
{
	if(node == NULL) return;
        // save leaf node
	if(node->left == NULL && node->right == NULL) {
	    path[level] = node->data;
	    for(int i = 0; i <= level; i++) {
		cout << (char)path[i];
	    }
	    cout << endl;
	    return;
	}
        // save parent node
	path[level] = node->data;
	pathFinder(node->left, path, level+1);
	pathFinder(node->right, path, level+1);
}

bool matchTree(Tree *r1, Tree *r2)
{
	/* Nothing left in the subtree */
	if(r1 == NULL && r2 == NULL)
	    return true;
	/* Big tree empty and subtree not found */
	if(r1 == NULL || r2 == NULL)
	    return false;
	/* Not matching */
	if(r1->data != r2->data)
	    return false;
	return (matchTree(r1->left, r2->left) && 
			matchTree(r1->right, r2->right));
}

bool subTree(Tree *r1, Tree *r2)
{
	/*Big tree empty and subtree not found */
	if(r1 == NULL)
	    return false;
	if(r1->data == r2->data)
	    if(matchTree(r1, r2)) return true;
	return 
            (subTree(r1->left, r2) || subTree(r1->right, r2));
}

bool isSubTree(Tree *r1, Tree *r2)
{
	/* Empty tree is subtree */
	if(r2 == NULL) 
	    return true;
	else
	    return subTree(r1, r2);
}

/* change a tree so that the roles of the left 
and right hand pointers are swapped at every node */
void mirror(Tree *r)
{
	if(r == NULL) return;
	
	Tree *tmp;
	mirror(r->left);
	mirror(r->right);

	/* swap pointers */
	tmp = r->right;
	r->right = r->left;
	r->left = tmp;
}

/* create a new tree from a sorted array */
Tree *addToBST(char arr[], int start, int end)
{
	if(end < start) return NULL;
	int mid = (start + end)/2;

	Tree *r = new Tree;
	r->data = arr[mid];
	r->left = addToBST(arr, start, mid-1);
	r->right = addToBST(arr, mid+1, end);
	return r;
}

Tree *createMinimalBST(char arr[], int size)
{
	return addToBST(arr,0,size-1);
}

/* Breadth first traversal using queue */
void BreadthFirstTraversal(Tree *root)
{
	if (root == NULL) return;
	deque <Tree *> queue;
	queue.push_back(root);

	while (!queue.empty()) {
	    Tree *p = queue.front();
	    cout << p->data << " ";
	    queue.pop_front();

	    if (p->left != NULL)
		queue.push_back(p->left);
	    if (p->right != NULL)
		queue.push_back(p->right);
	}
	cout << endl;
} 

/* get the level of a node element: root level = 0 */
int getLevel(struct Tree *node, int elm, int level)
{
	if(node == NULL) return 0;
	if(elm == node->data) 
	    return level;
	else if(elm < node->data) 
	    return getLevel(node->left, elm, level+1);
	else 
	    return getLevel(node->right, elm, level+1);
}

/* This code prints out all nodes at the same depth (level) */
void BreadthFirst_LevelElement_Print
               (struct Tree *root, vector<vector<int> > &v)
{
	if(root == NULL) return;
	deque<Tree *> q;
	q.push_back(root);
	while(!q.empty()) {
	    Tree *p =  q.front();
	    int lev = getLevel(root, p->data, 0);
	    v[lev].push_back(p->data);
	    q.pop_front();
	    if(p->left) q.push_back(p->left);
	    if(p->right)q.push_back(p->right);
	}
	return;
}

/* levelPrint()
prints nodes at the same level
This is simpler than the BreadthFirstTraversal(root) above
It takes 2D vector with the same size of level (= MaxDepth+1)
and fills elements as we traverse (preOrder) */

void levelPrint(struct Tree *node, vector<vector<char> >&elm, int level)
{
	if(node == NULL) return;
	// leaf nodes
	if(node->left == NULL && node->right == NULL) {
	    elm[level].push_back(node->data);
	    return;
	}
	// other nodes
	elm[level++].push_back(node->data);
	levelPrint(node->left, elm, level);
	levelPrint(node->right, elm, level);
}

/* find n-th max node from a tree */
void NthMax(struct Tree* t)
{        
	static int n_th_max = 5;
	static int num = 0;
	if(t == NULL) return;        
	NthMax(t->right);        
	num++;        
	if(num == n_th_max)                
	    cout << n_th_max << "-th maximum data is " 
                 << t->data << endl;        
	NthMax(t->left);
}

/* Converting a BST into an Array */ 
void TreeToArray(struct Tree *node, int a[]){ 
	static int pos = 0; 
  
	if(node){ 
	    TreeToArray(node->left,a); 
	    a[pos++] = node->data; 
	    TreeToArray(node->right,a); 
       } 
} 

/* Separate even/odd level elements */
/* This function is using BFS */
void level_even_odd(struct Tree *node)
{
	vector<char> evenVec, oddVec;
	if (node == NULL) return;
	deque<struct Tree*> que;
	que.push_back(node);

	while(!que.empty()) 
	{
	    struct Tree *p = que.front();
	    int level = getLevel(node, p->data, 0) ;
	    // even level
	    if (level % 2 == 0) 
		evenVec.push_back(p->data);
	    else
		oddVec.push_back(p->data);
	    que.pop_front();
	    if(p->left)  que.push_back(p->left);
	    if(p->right) que.push_back(p->right);
	}
	
	cout << "even level elements : ";
	for(int i = 0; i < evenVec.size(); i++) 
            cout << evenVec[i] << " ";
	cout << endl << "odd level elements : ";
        for(int i = 0; i < oddVec.size(); i++) 
            cout << oddVec[i] << " ";
	cout << endl;
}

int main(int argc, char **argv)
{
	char ch, ch1, ch2;
	Tree *found;
	Tree *succ;
	Tree *pred;
	Tree *ancestor;
	char charArr[9] 
	    = {'A','B','C','D','E','F','G','H','I'};

	Tree *root = newTreeNode('F');
	insertTreeNode(root,'B');
	insertTreeNode(root,'A');
	insertTreeNode(root,'D');
	insertTreeNode(root,'C');  
	insertTreeNode(root,'E');
	insertTreeNode(root,'G');
	insertTreeNode(root,'I');
	insertTreeNode(root,'H');

	/* print tree in order */
	cout << "increasing sort order\n";
	printTreeInOrder(root);
	cout << endl;

	/* print tree in postorder*/
	cout << "post order \n";
	printTreePostOrder(root);
	cout << endl;

	return 0;
}
