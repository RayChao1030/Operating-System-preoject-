//E14071025 »¯ªl·ç comment added
// C program for Red-Black Tree insertion
#include<stdio.h>
#include<stdlib.h>
 
//A Red-Black tree node structure
struct node
{
    int data;     // for data part
    char color;  // for color property
 
    //links for left, right children and parent
    struct node *left, *right, *parent;
};
 
 
// Left Rotation
void LeftRotate(struct node **root,struct node *x)
{
    //y stored pointer of right child of x,at last y will become the parent of x
    struct node *y = x->right;
 
    //store y's left subtree's pointer as x's right child to rotate y's left children will become x .
    x->right = y->left;
 
    //update parent pointer of x's right
    if (x->right != NULL)
        x->right->parent = x;
 
    //update y's parent pointer,make y replace x,link y to x's parent first.
    y->parent = x->parent;
 
    // if x's parent is null make y as root of tree,which means that x is root,and y will become the root after rotating.
    if (x->parent == NULL)
        (*root) = y;
 
    // store y at the place of x and make x become y's children
    else if (x == x->parent->left)
        x->parent->left = y;
    else    x->parent->right = y;
 
    // make x as left child of y
    y->left = x;
 
    //update parent pointer of x
    x->parent = y;
}
 
 
// Right Rotation (Similar to LeftRotate)
void rightRotate(struct node **root,struct node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}
 
// Utility function to fixup the Red-Black tree after standard BST insertion
void insertFixUp(struct node **root,struct node *z)
{
    // iterate until z is not the root and z's parent color is red
	//if z is root which means there have no way to shift(finish),
	//if z's color is black so that the problem of continue red node is solved.
    while (z != *root && z->parent->color == 'R')
    {
        struct node *y;
 
        // Find uncle and store uncle in y
        if (z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;
 
        // If uncle is RED, do following
        // (i)  Change color of parent and uncle as BLACK
        // (ii) Change color of grandparent as RED
        // (iii) Move z to grandparent

		//thus it will become the case in else,which means that this operation is to make uncle's colour become at the case in else
        if (y->color == 'R')
        {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        }
 
        // Uncle is BLACK, there are four cases (LL, LR, RL and RR)
        else
        {
            // Left-Left (LL) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Right Rotate Grandparent
            if (z->parent == z->parent->parent->left &&
                z == z->parent->left)
            {
                char ch = z->parent->color ; //solve the problem of continue red node ,it has to change two colour so that the black hight will maintain
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
				//the rotate can make root become black,also matain black height
                rightRotate(root,z->parent->parent);
            }
 
            // Left-Right (LR) case, do following
            // (i)  Swap color of current node  and grandparent
            // (ii) Left Rotate Parent
            // (iii) Right Rotate Grand Parent
            if (z->parent == z->parent->parent->left &&
                z == z->parent->right)
            {
                char ch = z->color ; //solve the problem of continue red nod ,it has to change two colors so as that the black hight is going to maintain.
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
				//this rotation is to change the side of continue red node, and make it become the form as " Left-Left of Right-Right case"
                LeftRotate(root,z->parent);
                rightRotate(root,z->parent->parent);
            }
 
            // Right-Right (RR) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Left Rotate Grandparent
            if (z->parent == z->parent->parent->right &&
                z == z->parent->right)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent->parent);
            }
 
            // Right-Left (RL) case, do following
            // (i)  Swap color of current node  and grandparent
            // (ii) Right Rotate Parent
            // (iii) Left Rotate Grand Parent
            if (z->parent == z->parent->parent->right &&
                z == z->parent->left)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent);
                LeftRotate(root,z->parent->parent);
            }
        }
    }
    (*root)->color = 'B'; //keep root always black
}
 
// Utility function to insert newly node in RedBlack tree
void insert(struct node **root, int data)
{
    // Allocate memory for new node
    struct node *z = (struct node*)malloc(sizeof(struct node));
    z->data = data;
    z->left = z->right = z->parent = NULL;
 
     //if root is null make z as root
    if (*root == NULL)
    {
        z->color = 'B';//the root is black.
        (*root) = z;
    }
    else
    {
        struct node *y = NULL;
        struct node *x = (*root);
 
        // Follow standard BST insert steps to first insert the node
        while (x != NULL)
        {
			//recording the path
            y = x;
			//if x'data is large than current data it have to move leftward ,so that left children are bigger than its parent
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
		//connecting the node to the lastly compared node.
        z->parent = y;
		//if z is bigger than y ,it should be put on right
        if (z->data > y->data)
            y->right = z;
		//In contrast, if z is smaller than y ,it should be put on left
        else
            y->left = z;
        z->color = 'R'; //insert node must be red to maintain the black height.
 
        // call insertFixUp to fix reb-black tree's property if it
        // is voilated due to insertion.
        insertFixUp(root,z);
    }
}
 
// A utility function to traverse Red-Black tree in inorder fashion
//which can output the tree's data from the smallest to the biggest
void inorder(struct node *root)
{
    if (root == NULL)
        return;
	//move to the most left place(and also smaller)
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);//node is larger than left children and right is larger than it's parent
}
 
/* Drier program to test above function*/
int main()
{
    struct node *root = NULL;
    insert(&root,20);
    insert(&root,28);
    insert(&root,72);
    insert(&root,25);
    insert(&root,59);
    insert(&root,39);
    insert(&root,60);
    insert(&root,48);
    printf("inorder Traversal Is : ");
    inorder(root);
 
    return 0;
}
