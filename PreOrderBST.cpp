#include <iostream>
using namespace std;
#include <stack>

class Node
{
public:
    Node *lchild;
    Node *rchild;
    int data;
};

class BST
{
public:
    Node *root = NULL;
    void createFromPreorder(int pre[], int n);
    void createFromPostorder(int post[], int);
    void inorder(Node *p);
};

void BST ::inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << endl;
        inorder(p->rchild);
    }
}

void BST::createFromPreorder(int pre[], int n)
{
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = NULL;
    root->rchild = NULL;

    Node *t;
    Node *p = root;
    stack<Node *> stk;

    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < (stk.empty() ? 32767 : stk.top()->data))
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = NULL;
                t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

void BST::createFromPostorder(int post[], int n)
{
    stack<Node *> stk;
    int i = n - 1;
    struct Node *p, *q, *t;
    root = new Node;
    root->data = post[i--];
    root->lchild = root->rchild = NULL;
    p = root;

    while (i > -1)
    {
        if (post[i] > p->data)
        {
            t = new Node;
            t->data = post[i--];
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if (post[i] < p->data && post[i] > stk.top()->data)
            {
                t = new Node;
                t->data = post[i--];
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
                if (stk.empty())
                {
                    q = new Node;
                    q->data = -10;
                    q->lchild = q->rchild = NULL;
                    stk.push(q);
                }
            }
        }
    }
}

int main()
{
    BST b;

    cout << "BST from Preorder: " << endl;
    int post[] = {1, 3, 2, 5, 7, 6, 4};
    int n = sizeof(post) / sizeof(post[0]);

    b.createFromPostorder(post,n);
    b.inorder(b.root);
    cout << endl;

    return 0;
}