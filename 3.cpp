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
