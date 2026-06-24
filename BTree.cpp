#include <bits/stdc++.h>

class BTreeNode {
private:
    int* keys;
    int minDegree;
    BTreeNode** children;
    int numKeys;
    bool isLeaf;

public:
    BTreeNode(int minDegree, bool isLeaf);

    void traverse() const;
    BTreeNode* search(int key);
    void insertNonFull(int key);
    void splitChild(int childIndex, BTreeNode* fullChild);

    friend class BTree;
};

class BTree {
private:
    BTreeNode* root;
    int minDegree;

public:
    explicit BTree(int minDegree) : root(nullptr), minDegree(minDegree) {}

    void traverse() const {
        if (root != nullptr) {
            root->traverse();
        }
    }

    BTreeNode* search(int key) {
        return (root == nullptr) ? nullptr : root->search(key);
    }

    void insert(int key);
};

BTreeNode::BTreeNode(int minDegree, bool isLeaf) 
    : minDegree(minDegree), isLeaf(isLeaf), numKeys(0) {
    keys = new int[2 * minDegree - 1];
    children = new BTreeNode*[2 * minDegree];
}

void BTreeNode::traverse() const {
    int i;
    for (i = 0; i < numKeys; i++) {
        if (!isLeaf) {
            children[i]->traverse();
        }
        std::cout << keys[i] << " ";
    }
    
    if (!isLeaf) {
        children[i]->traverse();
    }
}

BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < numKeys && key > keys[i]) {
        i++;
    }

    if (i < numKeys && keys[i] == key) {
        return this;
    }

    if (isLeaf) {
        return nullptr;
    }

    return children[i]->search(key);
}

void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode(minDegree, true);
        root->keys[0] = key;
        root->numKeys = 1;
        return;
    }

    if (root->numKeys == 2 * minDegree - 1) {
        BTreeNode* newRoot = new BTreeNode(minDegree, false);
        newRoot->children[0] = root;
        newRoot->splitChild(0, root);

        int i = (newRoot->keys[0] < key) ? 1 : 0;
        newRoot->children[i]->insertNonFull(key);

        root = newRoot;
    } else {
        root->insertNonFull(key);
    }
}

void BTreeNode::insertNonFull(int key) {
    int i = numKeys - 1;

    if (isLeaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        numKeys++;
    } else {
        while (i >= 0 && keys[i] > key) {
            i--;
        }

        if (children[i + 1]->numKeys == 2 * minDegree - 1) {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < key) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int childIndex, BTreeNode* fullChild) {
    BTreeNode* newNode = new BTreeNode(fullChild->minDegree, fullChild->isLeaf);
    newNode->numKeys = minDegree - 1;

    for (int j = 0; j < minDegree - 1; j++) {
        newNode->keys[j] = fullChild->keys[j + minDegree];
    }

    if (!fullChild->isLeaf) {
        for (int j = 0; j < minDegree; j++) {
            newNode->children[j] = fullChild->children[j + minDegree];
        }
    }

    fullChild->numKeys = minDegree - 1;

    for (int j = numKeys; j >= childIndex + 1; j--) {
        children[j + 1] = children[j];
    }
    children[childIndex + 1] = newNode;

    for (int j = numKeys - 1; j >= childIndex; j--) {
        keys[j + 1] = keys[j];
    }
    
    keys[childIndex] = fullChild->keys[minDegree - 1];
    numKeys++;
}

int main(void) {
    BTree tree(2); 

    int valuesToInsert[] = {10, 20, 30, 40, 50, 60, 70, 80};
    for (int value : valuesToInsert) {
        tree.insert(value);
    }

    std::cout << "B-Tree Traversal: ";
    tree.traverse();
    std::cout << "\n";

    int searchKey = 50;
    std::cout << "Searching for " << searchKey << "...\n";
    
    if (tree.search(searchKey) != nullptr) {
        std::cout << "Key " << searchKey << " found in the B-Tree.\n";
    } else {
        std::cout << "Key " << searchKey << " NOT found.\n";
    }

    return 0;
}