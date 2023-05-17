struct AVLNode {
    int height ; 
    float points;
    char *name;
    struct AVLNode *left ;
    struct AVLNode *right ; 
};
typedef struct AVLNode AVLNode;

int nodeHeight ( AVLNode *root );
AVLNode *rightRotation ( AVLNode *z) ;
AVLNode *leftRotation ( AVLNode *z) ;
AVLNode *LRRotation ( AVLNode *Z) ;
AVLNode *RLRotation ( AVLNode *Z) ;
AVLNode *insertAVLNode ( AVLNode *node , float floatData, char *charData) ;
void createTree ( BSTNode * BSTroot , AVLNode **AVLroot) ;
AVLNode *tree(FILE *display_file, teamNode *winnerStack, int numberOfTeams);
void printLevel (FILE *display_file,  AVLNode *root , int level );
void inorder1 ( AVLNode * root ) ;
