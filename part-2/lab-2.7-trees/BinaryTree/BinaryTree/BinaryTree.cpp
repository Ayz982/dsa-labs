#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BinaryTree {
private:
    struct TreeNode {
        T key;
        TreeNode* left;
        TreeNode* right;

        bool isMin;
        bool isMax;

        TreeNode(T val)
            : key(val), left(nullptr), right(nullptr), isMin(false), isMax(false) {}
    };

    TreeNode* root = nullptr;

    TreeNode* firstMaxPtr = nullptr;
    TreeNode* lastMinPtr = nullptr;

    void deleteTree(TreeNode* node);
    TreeNode* buildTreeRec(const vector<T>& arr, int start, int end);
    void printInOrder(TreeNode* node) const;
    void findExtremes(TreeNode* node, T& minVal, T& maxVal);
    void markNodesRec(TreeNode* node, const T& minVal, const T& maxVal);
    TreeNode* findFirstMaxInOrder() const;

public:
    BinaryTree();
    ~BinaryTree();

    void markMinMax();

    void buildBalanced(const vector<T>& arr);
    void buildPerfectBST(const vector<T>& arr);
    void print() const;
};

int main()
{
    vector<int> arr = { 10, 30, 10, 40, 70, 70, 50 };
    vector<int> sortedArr = { 10, 10, 30, 40, 50, 70, 70 };

    BinaryTree<int> tree1;
    tree1.buildBalanced(arr);
    tree1.print();

    BinaryTree<int> tree2;
    tree2.buildPerfectBST(sortedArr);
    tree2.print();

    return 0;
}

template<typename T>
void BinaryTree<T>::deleteTree(TreeNode* node)
{
    if (!node) return;;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

template<typename T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::buildTreeRec(const vector<T>& arr, int start, int end)
{
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(arr[mid]);

    node->left = buildTreeRec(arr, start, mid - 1);
    node->right = buildTreeRec(arr, mid + 1, end);

    return node;
}

template<typename T>
void BinaryTree<T>::printInOrder(TreeNode* node) const
{
    if (!node) return;

    printInOrder(node->left);

    cout << node->key;
    if (node == firstMaxPtr) cout << "(FIRST_MAX)";
    else if (node->isMax) cout << "(max)";

    if (node == lastMinPtr) cout << "(LAST_MIN)";
    else if (node->isMin) cout << "(min)";

    cout << " ";

    printInOrder(node->right);
}

template<typename T>
void BinaryTree<T>::findExtremes(TreeNode* node, T& minVal, T& maxVal)
{
    if (!node) return;
    if (node->key < minVal) minVal = node->key;
    if (node->key > maxVal) maxVal = node->key;
    findExtremes(node->left, minVal, maxVal);
    findExtremes(node->right, minVal, maxVal);
}

template<typename T>
void BinaryTree<T>::markNodesRec(TreeNode* node, const T& minVal, const T& maxVal)
{
    if (!node) return;

    markNodesRec(node->left, minVal, maxVal);

    if (node->key == minVal) node->isMin = true;
    if (node->key == maxVal) node->isMax = true;

    if (node->key == maxVal && firstMaxPtr == nullptr) {
        firstMaxPtr = node;
    }

    if (node->key == minVal) {
        lastMinPtr = node;
    }

    markNodesRec(node->right, minVal, maxVal);
}

template<typename T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::findFirstMaxInOrder() const
{
    if (!root) return;

    firstMaxPtr = nullptr;
    lastMinPtr = nullptr;

    T minVal = root->key;
    T maxVal = root->key;

    findExtremes(root, minVal, maxVal);

    markNodesRec(root, minVal, maxVal);
}

template<typename T>
BinaryTree<T>::BinaryTree()
    : root(nullptr) {}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    deleteTree(root);
}

template<typename T>
void BinaryTree<T>::markMinMax()
{
    if (!root) return;

    T minVal = root->key;
    T maxVal = root->key;

    findExtremes(root, minVal, maxVal);
    markNodesRec(root, minVal, maxVal);
}

template<typename T>
void BinaryTree<T>::buildBalanced(const vector<T>& arr)
{
    if (arr.empty()) return;

    root = buildTreeRec(arr, 0, arr.size() - 1);
    markMinMax();
}

template<typename T>
void BinaryTree<T>::buildPerfectBST(const vector<T>& sortedArr)
{
    if (sortedArr.empty()) return;

    root = buildTreeRec(sortedArr, 0, sortedArr.size() - 1);
    markMinMax();
}

template<typename T>
void BinaryTree<T>::print() const
{
    if (!root) {
        cout << "Tree is empty." << "\n";
        return;
    }
    cout << "In-Order traversal: ";
    printInOrder(root);
    cout << "\n";
}

