#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};


struct node * EnterNode(struct node * root, int val)
{
    if (root == NULL) {
        struct node *root = (struct node*)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->val = val;
        return root;
    }

    if (val < root->val) {
        root->left = EnterNode(root->left, val);
    } else if (val > root->val) {
        root->right = EnterNode(root->right, val);
    } else {
        printf("Error! Value already present in BST [%d]", val);
    }
    return root;
}


/* Root -> Left Subtree-> Right Sub-tree */
void preOrderTraverse(struct node *root)
{
    if (root == NULL)
        return;
    printf(" [%d] ", root->val);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

/* Left Subtree -> Right Sub-tree -> Root */
void postOrderTraverse(struct node *root)
{
    if (root == NULL)
        return;
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    printf(" [%d] ", root->val);

}

/* Left Subtree -> Root -> Right Sub-tree */
void inOrderTraverse(struct node *root)
{
    if (root == NULL)
        return;
    inOrderTraverse(root->left);
    printf(" [%d] ", root->val);
    inOrderTraverse(root->right);

}

int FindMinRightSubTree(struct node* root)
{

    while(root->left != NULL) {
        root = root->left;
    }

    return root->val;
}

struct node* DeleteNodeInBST(struct node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->val == val) {
        printf("Node To be deleted is Found [%d]\n ", root->val);

        if (root->left == NULL && root->right == NULL) {
            /* Node is leaf node with no children */
            free(root);
            return NULL;

        } else if (root->left == NULL){
            /* Node is leaf node with right subtree present */
            printf("Right subtree is present start node val [%d]", root->right->val);
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            /* Node is leaf node with left subtree present */
            printf("Left subtree is present start node val [%d]", root->left->val);
            struct node *temp = root->left;
            free(root);
            return temp;
        } else  {
            /* Node is NOT leaf node, contains both left and right subtree */
            root->val = FindMinRightSubTree(root->right);
            root->right = DeleteNodeInBST(root->right, root->val);
            
        }
    }
    root->left = DeleteNodeInBST(root->left, val);
    root->right = DeleteNodeInBST(root->right, val);
    return root;
}


void FindNodeInBST(struct node *root, int val)
{
    if (root == NULL)
        return;
    if (root->val == val)
        printf(" Node Found [%d] ", root->val);
    FindNodeInBST(root->left, val);
    FindNodeInBST(root->right, val);
}

int main()
{
    int nodes;
    printf("Your first BST...\n");
    printf("Enter number of nodes..");
    scanf("%d", &nodes);

    int num = 0;
    int val;

    /* Initialize tree root node */
    struct node *root = NULL;

    /* TCreation of BST */
    for (; num <nodes; num++) {
        int val;
        scanf("%d", &val);
        root = EnterNode(root, val); 
    }

    /* Traversal */
    printf("\nNow print PreOrder Traversal..");
    preOrderTraverse(root);
    printf("\nNow print PostOrder Traversal..");
    postOrderTraverse(root);
    printf("\nNow print InOrder Traversal..");
    inOrderTraverse(root);

    /* First Deletion of a node */
    printf("\n Now we want to delete a node in BST..\n");
    printf("Enter value of node to be deleted...\n");
    scanf("%d", &val);
    if (root != NULL) {
        root = DeleteNodeInBST(root, val);
        printf("\nNow print PreOrder Traversal..After deletion of the node");
        preOrderTraverse(root);
    }


    /* Second Deletion of a node */
    printf("\n Now we want to delete a node in BST..\n");
    printf("Enter value of node to be deleted...\n");
    scanf("%d", &val);
    if (root != NULL) {
        root = DeleteNodeInBST(root, val);
        printf("\nNow print PreOrder Traversal..After deletion of the node");
        preOrderTraverse(root);
    }

    /* Third Deletion of a node */
    printf("\n Now we want to delete a node in BST..\n");
    printf("Enter value of node to be deleted...\n");
    scanf("%d", &val);
    if (root != NULL) {
        root = DeleteNodeInBST(root, val);
        printf("\nNow print PreOrder Traversal..After deletion of the node");
        preOrderTraverse(root);
    }

    /* Finding a node */
    printf("\n Now we want to Find a node in BST..\n");
    printf("Enter value of nodes to be found...\n");
    scanf("%d", &val);
    FindNodeInBST(root, val);

}
