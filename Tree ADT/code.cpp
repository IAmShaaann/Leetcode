#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = this->right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = push(root, value);
    }

    void display(string type)
    {
        if (type == "inorder")
            inorder(root);
        else if (type == "postorder")
            postorder(root);
        else if (type == "preorder")
            preorder(root);
        else if (type == "levelorder")
            levelorder(root);

        cout << endl;
    }

    void search(int value)
    {
        bool isValueAvailable = BinarySearch(root, value);
        cout << "is value " << value << " avaiable? " << isValueAvailable << endl;
    }

    Node *remove(int value)
    {
        return deleteNode(root, value);
    }

private:
    bool isnull(Node *root) { return root == nullptr; }

    Node *push(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->value)
        {
            node->left = push(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = push(node->right, value);
        }
        return node;
    }

    void inorder(Node *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == nullptr)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }

    void levelorder(Node *root)
    {
        if (isnull(root))
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *front = q.front();
            cout << front->value << " ";
            q.pop();

            if (!isnull(front->left))
                q.push(front->left);
            if (!isnull(front->right))
                q.push(front->right);
        }
    }

    bool BinarySearch(Node *root, int value)
    {
        if (isnull(root))
            return false;
        if (root->value == value)
            return true;
        else if (root->value < value)
            return BinarySearch(root->right, value);
        else if (root->value > value)
            return BinarySearch(root->left, value);

        return false;
    }

    Node *deleteNode(Node *root, int value)
    {
        if (isnull(root))
            return root;

        if (root->value == value)
            return helper(root);

        Node *currentRoot = root;

        while (!isnull(root))
        {
            if (root->value > value)
            {
                if (!isnull(root->left) and root->left->value == value)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else if (root->value < value)
            {
                if (!isnull(root->right) and root->right->value == value)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return currentRoot;
    }

    Node *helper(Node *root)
    {
        if (isnull(root->left))
            return root->right;
        else if (isnull(root->right))
            return root->left;

        Node *rootRight = root->right;
        Node *lastRightChild = lastRightChildNode(root->left);
        lastRightChild->right = rootRight;
        return root->left;
    }

    Node *lastRightChildNode(Node *root)
    {
        if (isnull(root->right))
            return root;
        return lastRightChildNode(root->right);
    }
};
int main()
{
    BinaryTree tree = BinaryTree();
    tree.insert(20);
    tree.insert(10);
    tree.insert(50);
    tree.insert(30);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);

    tree.display("inorder");
    tree.display("postorder");
    tree.display("preorder");
    tree.display("levelorder");

    tree.search(34);
    tree.search(30);

    tree.remove(70);
    tree.remove(40);

    tree.display("levelorder");

    return 0;
}

/*
    If the root of the a binary tree is x values on the left will always be lesser than left,
    values on the right will be greater than root.

    Inorder - Left Root Right -  10 20 30 40 50 60 70
    Preorder - Root Left Right - 20 10 50 30 40 70 60
    Postorder - Left Right Root - 10 40 30 60 70 50 20
    level order - 20 10 50 30 70 40 60

                    20
        10                      30
    5                       25      35
                17      22              40

*/
