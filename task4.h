struct BSTNode
{
    float points;
    char *name;
    struct BSTNode *left;
    struct BSTNode *right;
};
typedef struct BSTNode BSTNode;

BSTNode * newNode ( float floatData, char *charData ) ;
BSTNode * insertBSTNode ( BSTNode * node , float floatData, char *charData) ;
void inorder (FILE *display_file, BSTNode * root ) ;
BSTNode *leaderBoard(FILE *display_file, teamNode *winnerStack, int numberOfTeams);
