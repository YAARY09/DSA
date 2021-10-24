 #include <stdio.h>
 #include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;

};

struct node * createnode(int data)
{
    struct node * p;
    p = (struct node *) malloc (sizeof( struct node));
    p -> data = data;
    p ->left = NULL;
    p ->right = NULL;
    return p;
};

struct node * delitnode()
{
    struct node * p;
    p = (struct node *) malloc (sizeof( struct node));
    p -> data = data;
    p ->left = NULL;
    p ->right = NULL;
    return p;
};

void link(struct node * parent , struct node * left , struct node * right )
{
    parent->left = left;
    parent->right = right;
}

void PreOrder(struct node *root)
{
    if (root!= NULL){
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct node *root)
{
    if (root!= NULL){
        
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}

void InOrder(struct node *root)
{
    if (root!= NULL){
        
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

void main()
{
    struct node * root = createnode(1);
    struct node * second = createnode(2);
    struct node * third = createnode(3);
    struct node * fourth = createnode(4);
    struct node * fifth = createnode(5);

    link(root,second,third);
    link(second,fourth,NULL);
    link(third,NULL,fifth);
    PreOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
    InOrder(root);

}