// Abdalla Fadl Shehata
// 20190305
// G 16
#include <iostream>
using namespace std;
///////////////////////////////////////
///////////////////////////////////////
class Node
{
private:
	int key;
	Node *left;
	Node *right;
	int height;
public:
    Node( )
	{
		left = 0;
		right = 0;
	}
	Node(int k,Node* l = 0 , Node*r = 0)
	{
		key = k;
		left = l;
		right = r;
		height = 1;
	}
	Node* getLeft()
	{
		return left;
	}
	Node* getRight()
	{
		return right;
	}
	int getKey()
	{
		return key;
	}
	int getHeight()
	{
		return height;
	}
	void setLeft(Node *l)
	{
		left = l;
	}
	void setRight(Node *r)
	{
		right = r;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void setKey(int k)
	{
		key = k;
	}
};
///////////////////////////////////////
///////////////////////////////////////
class AVL
{
private:
	Node *root;
public :
AVL()
{
	root = 0;
}
void print(int choice)
{
	if (choice == 1){
		inOrder(root);
	}
	else if (choice==2){
      preOrder(root);
	}
	else {
       postOrder(root);
	}
}
void inOrder(Node *node)
{
	if (node != 0){
	inOrder( node->getLeft() );
	cout << node->getKey() <<" " ;
	inOrder( node->getRight() );
	}
}
////////////
void preOrder(Node * node)
{
	if (node != 0){
	cout << node->getKey() << " ";
	preOrder(node->getLeft());
	preOrder(node->getRight());
	}
}
//////////
void postOrder(Node *node)
{
	if (node != 0){
	postOrder(node->getLeft());
	postOrder(node->getRight());
	cout << node->getKey() <<" ";
	}
}
Node* maxNode(Node* node)
{
	if (node->getRight() == 0)
	{
		return node;
	}
	return maxNode( node->getRight() );
}
int height(Node *node)
{
	if (node == 0){
		return 0;
	}
	return node->getHeight();
}
int getBalance(Node *node)
{
	if (node==0){
		return 0;
	}
	return height(node->getLeft()) - height(node->getRight());
}
Node* rightRotate(Node *y)
{
	Node *x = y->getLeft();
	Node *T2 = x->getRight();

	x->setRight(y);
	y->setLeft(T2);

	y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);
	x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);

	return x;
}
Node* leftRotate(Node *x)
{
	Node *y = x->getRight();
	Node *T2 = y->getLeft();

	y->setLeft(x);
	x->setRight(T2);

	x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);
	y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);

	return y;
}
void deleteNode(int key)
{
	deleteNode(root, key);
}

Node* deleteNode(Node * root, int key)
{
	if (root == 0)
	{
		return root;
	}

	if (key < root->getKey())
	{
		root->setLeft(deleteNode(root->getLeft(), key));
	}
	else if (key > root->getKey())
	{
		root->setRight(deleteNode(root->getRight(), key));
	}
	else
	{
		if (!root->getLeft())
		{
			Node* tmp = root->getRight();
			delete root;
			return tmp;
		}
		else if (!root->getRight())
		{
			Node* tmp = root->getLeft();
			delete root;
			return tmp;
		}
		else
		{
			Node* temp = maxNode(root->getLeft());
			root->setKey(temp->getKey());
			root->setLeft(deleteNode(temp, temp->getKey()));
		}
	}

	if (root == 0)
		return root;

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->getLeft()) >= 0)
	{
		return rightRotate(root);
	}
	else if (balance > 1 && getBalance(root->getLeft()) < 0)
	{
		root->setLeft(leftRotate(root->getLeft()));
		return rightRotate(root);
	}
	else if (balance < -1 && getBalance(root->getRight()) <= 0)
	{
		return leftRotate(root);
	}
	else if (balance < -1 && getBalance(root->getRight()) > 0)
	{
		root->setRight(rightRotate(root->getRight()));
		return leftRotate(root);
	}

	return root;
}
void insert(int key)
{
	root = insert(root, key);
}
Node* insert(Node* node, int key)
{
	if (node == 0)
		return new Node(key);

	if (key < node->getKey())
		node->setLeft(insert(node->getLeft(), key));
	else
		node->setRight(insert(node->getRight(), key));


	node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);


	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->getLeft()->getKey())
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->getRight()->getKey())
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->getLeft()->getKey())
	{
		node->setLeft(leftRotate(node->getLeft()));
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->getRight()->getKey())
	{
		node->setRight(rightRotate(node->getRight()));
		return leftRotate(node);
	}
	return node;
}
};
///////////////////////////////////////
///////////////////////////////////////
int main()
{
    AVL tree;
	tree.insert(15);
    tree.insert(20);
	tree.insert(24);
	tree.insert(10);
	tree.insert(13);
	tree.insert(7);
	tree.insert(30);
	tree.insert(36);
	tree.insert(25);
   ////////////////////////
   cout<< "InOrder"<<endl;
	tree.print(1);
	cout << endl;
    cout<< "PreOrder"<<endl;
	tree.print(2);
	cout << endl;
    cout<< "PostOrder"<<endl;
	tree.print(3);
	cout << endl;
	//////////////////////////
	cout<<endl;
	tree.deleteNode(24);
	cout<<endl;
	/////////////////////////
	cout<<"After Delete (24) "<<endl;
	cout<<endl;
	cout<< "InOrder"<<endl;
	tree.print(1);
	cout << endl;
    cout<< "PreOrder"<<endl;
	tree.print(2);
	cout << endl;
    cout<< "PostOrder"<<endl;
	tree.print(3);
	cout << endl;
    return 0;
}
