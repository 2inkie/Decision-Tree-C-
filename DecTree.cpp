#include <iostream>

using namespace std;

class TreeNode {
  private:
    int data;
    TreeNode *left;
    TreeNode *right;
    bool ifLeaf;

  public:
    // Constructor
    TreeNode(int value, bool leaf = false)
        : data(value), left(nullptr), right(nullptr), ifLeaf(leaf) {}

    // Basic functions
    void setData(int a) { data = a; }
    void setLeft(TreeNode *l) { left = l; }
    void setRight(TreeNode *r) { right = r; }

    int getData() { return data; }
    TreeNode *getLeft() { return left; }
    TreeNode *getRight() { return right; }
    bool getLeaf() { return ifLeaf; }

    void setIfLeaf(bool lf) { ifLeaf = lf; }
};

class DecisionTree {
  public:
    TreeNode *root;

    // Constructor
    DecisionTree() : root(nullptr) {}

    // Destructor
    ~DecisionTree() { deleteTree(root); }

    void deleteTree(TreeNode *node) {
        if (node) {
            deleteTree(node->getLeft());  // Delete left
            deleteTree(node->getRight()); // Delete right
            delete node;
        }
    }

    // Insert new value
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }

        else {
            insertHelper(root, value);
        }
    }

    // Helper function to handle the recursive process
    void insertHelper(TreeNode *node, int value) {
        if (value < node->getData()) {
            if (node->getLeft() == nullptr) {
                node->setLeft(new TreeNode(value));
            }

            else {
                insertHelper(node->getLeft(), value);
            }
        }

        else {
            if (node->getRight() == nullptr) {
                node->setRight(new TreeNode(value));
            }

            else {
                insertHelper(node->getRight(), value);
            }
        }
    }

    void inorderTraversal(TreeNode *node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->getLeft()); // Go left
        cout << node->getData() << " ";    // Print node

        inorderTraversal(node->getRight()); // Go right
    }

    // Print tree
    void printInOrder() {
        inorderTraversal(root);

        cout << endl;
    }
};
