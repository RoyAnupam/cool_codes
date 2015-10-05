#include <stdio.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};

typedef struct node node;
node *n1_parent = NULL;
node *n2_parent = NULL;
static int found = 0;


node* CreateBST(node *root, int val)
{
    if (root == NULL) {

        root = (node*)malloc(sizeof(node));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;

    } else if (root->val > val) {
            root->left = CreateBST(root->left, val);
            return root;
    } else {
            root->right = CreateBST(root->right, val);
            return root;
    }
}

void PreOrderTraversal(node *parent, node *root, int n1, int n2)
{
    if (root == NULL)
        return;

    if (root->val == n1) {
        
        //printf("[%d]", root->val);
        n1_parent = parent;
        

    } else if (root->val == n2) {

        //printf("[%d]", root->val);
        n2_parent = parent;
    }

    if (n1_parent != NULL && n2_parent != NULL && found ==0) {
        if (n1_parent == n2_parent) {
            printf("[%d]", n1_parent->val);
        } else if (n1 < n2) {
            printf("[%d]", n1);
        } else if (n2 < n1) {
            printf("[%d]", n2);
        }
        found = 1;
        return;
    }

    PreOrderTraversal(root, root->left, n1, n2);
    PreOrderTraversal(root, root->right, n1, n2);
}

void FindLCA(node *root, int n1, int n2)
{
    node *temp_root = root;

    PreOrderTraversal(root, root, n1, n2);

}

int main()
{

    int num;
    int val;
    int k;
    int n1;
    int n2;

    printf("Welcome to finding Lowest Common Ancestor in BST..\n");

    printf("Enter number of nodes in BST...\n");
    scanf("%d", &num);

    node *root = NULL;
    
    for(k=0; k < num; k++) {
        scanf("%d", &val);
        root = CreateBST(root, val);
    }

    PreOrderTraversal(root, root, n1, n2);

    printf("Now time to find LCA..\n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    FindLCA(root, n1, n2);
}
