#include"task1.h"
#include"task4.h"
BSTNode * newNode ( float floatData, char *charData ) 
{
    BSTNode * node = ( BSTNode *) malloc ( sizeof ( BSTNode ));
    node->points = floatData ;
    node->name = (char *)malloc(strlen(charData)*sizeof(char));
    strcpy(node->name, charData);
    node->left = node->right = NULL ;
    return node ;
}
BSTNode * insertBSTNode ( BSTNode * node , float floatData, char *charData) 
{
    
    if ( node == NULL ) 
        return newNode ( floatData, charData );
    if ( floatData < node->points)
        node->left = insertBSTNode (node->left , floatData, charData );
    else 
        if (floatData > node->points)
            node->right = insertBSTNode (node->right , floatData, charData );
        else
        {
            if ( strcmp(charData, node->name)<0)
                node->left = insertBSTNode (node->left , floatData, charData );
            else 
                node->right = insertBSTNode (node->right , floatData, charData );
        }
    return node ;
}
void inorder (FILE *display_file, BSTNode * root ) 
{
    if ( root ){
        inorder (display_file, root->right );
        fprintf(display_file, "%-34s-  %.2f\n",root->name, root->points );
        inorder (display_file, root->left );
        
    }
}
BSTNode *leaderBoard(FILE *display_file, teamNode *winnerStack, int numberOfTeams)
{
    BSTNode *root = NULL ;
    for(int i=0; i<numberOfTeams; i++)
    {
        root = insertBSTNode (root ,winnerStack->val.teamPoints, winnerStack->val.teamName);
        winnerStack = winnerStack->next;
    }
    return root;
}
