#include"task1.h"
#include"task4.h"
BSTNode *newNode(float floatData, char *charData) 
{
    //functie pentru creare nod nou in BST
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    if(node == NULL)
    {
        printf("AlLoCaTiOn ErRoR!\n");
        exit(1);
    }
    node->points = floatData ;
    node->name = (char *)malloc(strlen(charData)*sizeof(char));
    charAllocationTest(node->name);
    strcpy(node->name, charData);
    node->left = node->right = NULL ;
    return node ;
}
BSTNode *insertBSTNode(BSTNode *node , float floatData, char *charData) 
{
    //functia de inserare nod in BST
    if(node == NULL) 
        return newNode(floatData, charData);
    if(floatData < node->points)
        node->left = insertBSTNode(node->left , floatData, charData );
    else 
        if(floatData > node->points)
            node->right = insertBSTNode(node->right , floatData, charData );
        else
        {
            if(strcmp(charData, node->name) < 0)
                node->left = insertBSTNode(node->left , floatData, charData);
            else 
                node->right = insertBSTNode(node->right , floatData, charData );
        }
    return node ;
}
void inorder(FILE *display_file, BSTNode * root ) 
{
    //functia de afisare in inordine
    if(root ){
        inorder (display_file, root->right );
        fprintf(display_file, "%-34s-  %.2f\n",root->name, root->points );
        inorder (display_file, root->left );
        
    }
}
BSTNode *leaderBoard(FILE *display_file, teamNode *winnerStack)
{
    //functia de baza a acestui task
    BSTNode *root = NULL ;
    //se creeazaBST-ul
    while(winnerStack != NULL)
    {
        root = insertBSTNode(root ,winnerStack->val.teamPoints, winnerStack->val.teamName);
        winnerStack = winnerStack->next;
    }
    return root;
}
void freeNodeBST(BSTNode **root)
{
    //functie de eliberare memorie pentru un nod din BST
    free((*root)->name);
    free(*root);
}
void deleteBST(BSTNode **root)
{
    //functia de stergere a BST-ului
    if(*root)
    {
        deleteBST(&(*root)->left);
        deleteBST(&(*root)->right);
        freeNodeBST(&*root);
    }
    root = NULL;
}