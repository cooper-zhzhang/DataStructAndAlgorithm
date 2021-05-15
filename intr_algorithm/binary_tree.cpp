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

    bool CheckBinary()
    {
        return CheckBinary(pRoot);
    }

    Node* Successor(Node *pNode)
    {// 后继
        if (pNode == nullptr)
        {
            return nullptr;
        }
        
        if (pNode->right)
        {// 1如果有右节点
            return Minimum(pNode->right);
        }

        // 2 没有右节点的情况
        Node *par = pNode->par;
        while (par != nullptr && pNode == par->right)
        {
            pNode = par;
            par = pNode->par;
        }

        return par;

        // while (pNode && pNode->par && pNode->par->right == pNode)
        // {
        //     pNode = pNode->par;
        // }

        // if (pNode)
        // {
        //     pNode = pNode->par;
        // }
        
        // return pNode;
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
            pDeleteNode = Successor(pNode);
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

    bool CheckBinary(Node *pNode)
    {
        if (pNode)
        {
            if (pNode->left && pNode->left->key > pNode->key)
            {
                return false;
            }
            
            if (pNode->right && pNode->right->key < pNode->key)
            {
                return false;
            }

            return (CheckBinary(pNode->right) && CheckBinary(pNode->left));
        }

        return true;
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

    std::cout << "--------------------------------" << std::endl;

    for (auto &it : sourceData)
    {
        Node *pNode = binaryTree.Search(it);
        if (pNode)
        {
            Node *pSuccessorNode =
            binaryTree.Successor(pNode);
            std::cout << pNode->key << " --> " << (pSuccessorNode ? pSuccessorNode->key : -1) << std::endl;
        }
    }

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

    std::cout << "is binary tree ? " 
        <<  (binaryTree.CheckBinary() ? "yes" : "no")
        << std::endl;

    return 0;
}
