#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node
{
    int data;
    node *leftChild;
    node *rightChild;
};

void inorder(node *tree)
{
    if(tree)
    {
        inorder(tree->leftChild);
        cout << tree->data << " ";
        inorder(tree->rightChild);
    }
}

node* swapTree(node *original)
{
    if (original)
    {
        node *temp = new node;
        temp->leftChild = swapTree(original->rightChild);
        temp->rightChild = swapTree(original->leftChild);
        temp->data = original->data;
        return temp;
    }
    return NULL;
}

int getHeight(node *tree)
{
	int hl, hr, h;
	if (tree)
	{
		hl = getHeight(tree->leftChild);
		hr = getHeight(tree->rightChild);
		if (hl > hr)
			h = 1 + hl;
		else
			h = 1 + hr;
		return h;
	}
	return 0;
}
node *insert_bst (node *tree, int key)
{
    if (!tree)
    {
        node *new_tree = new node;
        new_tree->leftChild = NULL;
        new_tree->rightChild = NULL;
        new_tree->data = key;
        return new_tree;
    }
    if(key < tree->data)
        tree->leftChild = insert_bst(tree->leftChild, key);
    else
        tree->rightChild = insert_bst(tree->rightChild, key);
    return tree;
}

int main()
{
	/*Uniform Random Number Generator*/
    node *bst = NULL;
    srand(time(0));
	int numRand, n = 100;
    for (int i = 0; i < n; i++)
	{
        numRand = rand() % 2000 + 1;
        cout << numRand << " ";
        bst = insert_bst(bst, numRand);
    }

	/*Swapped Tree*/
    node *swapped_tree;
    swapped_tree = swapTree(bst);
	cout << "\nSwapTree BST: ";
	inorder(swapped_tree);

	/*Getting Height*/
	cout << "\nHeight of BST: " << getHeight(bst) << endl;

    return 0;
}