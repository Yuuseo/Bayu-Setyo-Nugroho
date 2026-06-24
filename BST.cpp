#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    explicit Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        
        return node;
    }

    Node* search(Node* node, int value) const {
        if (node == nullptr || node->value == value) {
            return node;
        }

        if (value < node->value) {
            return search(node->left, value);
        }

        return search(node->right, value);
    }

    Node* findMin(Node* node) const {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }

    void inorder(Node* node) const {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->value << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) const {
        if (node != nullptr) {
            std::cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) const {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->value << " ";
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) const {
        return search(root, value) != nullptr;
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void printInorder() const {
        std::cout << "Inorder   : ";
        inorder(root);
        std::cout << "\n";
    }

    void printPreorder() const {
        std::cout << "Preorder  : ";
        preorder(root);
        std::cout << "\n";
    }

    void printPostorder() const {
        std::cout << "Postorder : ";
        postorder(root);
        std::cout << "\n";
    }
};

int main() {
    BST tree;

    int valuesToInsert[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : valuesToInsert) {
        tree.insert(val);
    }

    tree.printInorder();
    tree.printPreorder();
    tree.printPostorder();

    std::cout << "\n";
    int target = 60;
    if (tree.search(target)) {
        std::cout << "Key " << target << " found in BST.\n";
    } else {
        std::cout << "Key " << target << " NOT found in BST.\n";
    }

    std::cout << "Removing 50...\n";
    tree.remove(50);
    tree.printInorder();

    return 0;
}