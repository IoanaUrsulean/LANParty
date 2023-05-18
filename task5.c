#include"task1.h"
#include"task4.h"
#include"task5.h"
int nodeHeight(AVLNode *root)
{
    if(root == NULL) 
        return -1;
    else 
        return root->height ;
}
int max(int a,int b) 
{
    return ((a > b) ? a : b);
}

AVLNode *rightRotation(AVLNode *z)
{
    AVLNode *y = z->left;
    AVLNode *T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

AVLNode* leftRotation(AVLNode* z)
{
    AVLNode *y = z->right;
    AVLNode *T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
}

AVLNode* LRRotation(AVLNode *z)
{
    z->left = leftRotation(z->left);
    return rightRotation(z);
}

AVLNode *RLRotation(AVLNode *z)
{
    z->right = rightRotation(z->right);
    return leftRotation(z);
}
AVLNode *insertAVLNode(AVLNode *node , float floatData, char *charData) 
{
    if(node == NULL)
    {
        node = (AVLNode *)malloc(sizeof(AVLNode));
        if(node == NULL)
        {
            printf("AlLoCaTiOn ErRoR!\n");
            exit(1);
        }
        node->points = floatData ;
        node->name = (char *)malloc(strlen(charData)*sizeof(char));
        charAllocationTest(node->name);
        strcpy(node->name, charData);
        node->height = 0; 
        node->left = node->right = NULL ;
        return node ;
    }
    if(floatData < node->points)
        node->left = insertAVLNode(node->left, floatData, charData);
    else 
        if(floatData > node -> points)
            node->right = insertAVLNode(node->right , floatData, charData);
        else
        {
            if(strcmp(charData, node->name) < 0)
                node->left = insertAVLNode(node->left, floatData, charData);
            else 
                node->right = insertAVLNode(node->right , floatData, charData);
        } 
    node->height = 1 + max(nodeHeight(node->left ) ,
    nodeHeight(node->right));
    int k = (nodeHeight(node->left) - nodeHeight(node->right));

    if (k > 1 && (floatData < (node->left)->points || strcmp(charData, (node->left)->name) < 0))
        return rightRotation(node);
    if (k < -1 && (floatData > (node->right)->points || strcmp(charData, (node->right)->name) > 0))
        return leftRotation(node);
    if (k > 1 && (floatData > (node->left)->points|| strcmp(charData, (node->left)->name) > 0))
        return LRRotation(node);
    if (k < -1 && (floatData < (node->right)->points || strcmp(charData, (node->right)->name) < 0))
        return RLRotation(node);
    return node ; 
}
void createTree (BSTNode *BSTroot , AVLNode **AVLroot) 
{
    if(BSTroot ){
        createTree(BSTroot->right , &*AVLroot);
        *AVLroot = insertAVLNode(*AVLroot ,BSTroot->points, BSTroot->name);
        createTree(BSTroot->left, &*AVLroot);
    }
}
AVLNode *tree(FILE *display_file, teamNode *winnerStack, int numberOfTeams)
{
    BSTNode *helpingHand = NULL;
    helpingHand = leaderBoard(display_file, winnerStack);
    AVLNode *root = NULL ;
    createTree(helpingHand, &root);
    deleteBST(&helpingHand);
    return root;
}
void printLevel(FILE *display_file,  AVLNode * root , int level)
{
    if(root == NULL) 
        return ;
    if(level == 1) 
        fprintf(display_file, "%s\n", root ->name );
    else 
        if(level > 1) 
        {
            printLevel(display_file, root->right , level -1);
            printLevel(display_file, root->left , level -1);
        }
}
void freeNodeAVL(AVLNode **root)
{
    free((*root)->name);
    free(*root);
}
void deleteAVL(AVLNode **root)
{
    if(*root)
    {
        deleteAVL(&(*root)->left);
        deleteAVL(&(*root)->right);
        freeNodeAVL(&*root);
    }
    root = NULL;
}