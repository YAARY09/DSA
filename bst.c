#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;                     
    p->right = NULL;
    return p;
};

void link(struct node *parent, struct node *left, struct node *right)
{
    parent->left = left;
    parent->right = right;
}

void PreOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct node *root)
{
    if (root != NULL)
    {

        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

void InOrder(struct node *root)
{
    if (root != NULL)
    {

        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

bool isBST(struct node *root)
{
    if (root != NULL)
    {
        static struct node *prev = NULL;
        if (!isBST(root->left))
        {
            return false;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return false;
        }
        prev = root;

        return isBST(root->right);
    }
    else
    {
        return true;
    }
}

void main()
{
    struct node *root = createnode(5);
    struct node *second = createnode(3);
    struct node *third = createnode(6);
    struct node *fourth = createnode(1);
    struct node *fifth = createnode(4);

    link(root, second, third);
    link(second, fourth, fifth);
    link(third, NULL, NULL);
    bool x = isBST(root);
    InOrder(root);
    printf("%s ", x ? "true" : "false");
}