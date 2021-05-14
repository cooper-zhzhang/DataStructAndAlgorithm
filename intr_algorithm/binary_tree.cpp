#include <iostream>
#include <vector>

using namespace std;

typedef struct Node
{
    int key;
    Node *par;
    Node *left;
    Node *right;
} Node;

class BinaryTree
{
private:
    Node *pRoot = nullptr;

public:
    BinaryTree() : pRoot(nullptr)
    {
    }

    ~BinaryTree()
    {
        ClearTree();
    }

    void ClearTree()
    {
        DeleteTree(pRoot);
        pRoot = nullptr;
    }

    Node *Minimum(Node *pNode)
    {
        if (pNode == nullptr)
        {
            return nullptr;
        }

        return pNode->left ? Minimum(pNode->left) : pNode;
    }

    Node *Maximum(Node *pNode)
    {
        return (pNode && pNode->right) ? Maximum(pNode->right) : pNode;
    }

    Node *Search(int key)
    {
        return Search(pRoot, key);
    }

    void inorder_tree_walk()
    {
        if (pRoot)
        {
            inorder_tree_walk(pRoot->left);
            std::cout << pRoot->key << " ";
            inorder_tree_walk(pRoot->right);
        }

        std::cout << std::endl;
    }

    Node *insert_tree(Node *pNewNode)
    {
        if (pNewNode == nullptr)
        {
            return pRoot;
        }

        Node *x = pRoot;
        Node *pParNode = nullptr;
        while (x)
        {
            pParNode = x;
            if (pNewNode->key < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        if (pParNode == nullptr)
        {
            pRoot = pNewNode;
        }
        else
        {
            pNewNode->par = pParNode;
            if (pNewNode->key < pParNode->key)
            {
                pParNode->left = pNewNode;
            }
            else
            {
                pParNode->right = pNewNode;
            }
        }

        return pRoot;
    }

    Node *delete_node(Node *pNode)
    {
        if (pNode == nullptr)
        {
            return nullptr;
        }

        Node *pDeleteNode = nullptr;
        Node *pChildNode = nullptr;

        if (pNode->right == nullptr || pNode->left == nullptr)
        { // 至多一个子节点
            pDeleteNode = pNode;
        }
        else
        { // 两个子节点
            pDeleteNode = Minimum(pNode->right);
        }

        pChildNode = pDeleteNode->left ? pDeleteNode->left : pDeleteNode->right;

        if (pChildNode)
        {
            pChildNode->par = pDeleteNode->par;
        }

        if (pDeleteNode->par == nullptr)
        { // 需要删除的是root节点
            pRoot = pChildNode;
        }
        else if (pDeleteNode == pDeleteNode->par->left)
        {
            pDeleteNode->par->left = pChildNode;
        }
        else
        {
            pDeleteNode->par->right = pChildNode;
        }

        if (pDeleteNode != pNode)
        { // 删除的是一个后续节点
            pNode->key = pDeleteNode->key;
        }

        return pDeleteNode;
    }

private:
    void inorder_tree_walk(Node *pNode)
    {
        if (pNode)
        {
            inorder_tree_walk(pNode->left);
            std::cout << pNode->key << " ";
            inorder_tree_walk(pNode->right);
        }
    }

    Node *Search(Node *pNode, int key)
    {
        if (pNode == nullptr || pNode->key == key)
        {
            return pNode;
        }

        if (key > pNode->key)
        {
            return Search(pNode->right, key);
        }
        else
        {
            return Search(pNode->left, key);
        }
    }

    void DeleteTree(Node *pNode)
    {
        if (pNode)
        {
            DeleteTree(pNode->left);
            DeleteTree(pNode->right);
            delete pNode;
        }
    }
};

int main(int argc, char **argv)
{
    BinaryTree binaryTree;

    std::vector<int> sourceData{15, 5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 7};

    for (auto &it : sourceData)
    {
        Node *pNew = new Node;
        pNew->key = it;
        pNew->left = pNew->right = pNew->par = nullptr;

        binaryTree.insert_tree(pNew);
    }

    binaryTree.inorder_tree_walk();

    Node *p = nullptr;

    for (auto &it : {13, 16, 15})
    {
        p = binaryTree.Search(it);
        p = binaryTree.delete_node(p);
        if (p)
        {
            std::cout << "delete key: " << p->key << std::endl;
            delete p;
            p = nullptr;
        }

        binaryTree.inorder_tree_walk();
    }

    return 0;
}
