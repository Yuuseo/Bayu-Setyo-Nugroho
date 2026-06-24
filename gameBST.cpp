#include <bits/stdc++.h>
using namespace std;

struct Node {
    int score;
    Node* left;
    Node* right;
};

Node* createNode(int score) {
    Node* newNode = new Node();
    newNode->score = score;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int score) {
    if(root == NULL) {
        return createNode(score);
    }

    if(score < root->score) {
        root->left = insert(root->left, score);
    } else if(score > root->score) {
        root->right = insert(root->right, score);
    }

    return root;
}

void descending(Node* root) {
    if(root != NULL) {
        descending(root->right);
        cout << root->score << endl;
        descending(root->left);
    }
}

bool search(Node* root, int score) {
    if(root == NULL) {
        return false;
    }

    if(root->score == score) {
        return true;
    }

    if(score < root->score) {
        return search(root->left, score);
    } else {
        return search(root->right, score);
    }
}

int main(void) {
    Node* root = NULL;

    root = insert(root, 50);

    insert(root, 300);
    insert(root, 700);
    insert(root, 200);
    insert(root, 400);
    insert(root, 600);
    insert(root, 800);

    cout << "Ranking Player: " << endl;
    descending(root);

    int find_score = 600;

    if(search(root, find_score)) {
        cout << "Score " << find_score << " ditemukan" << endl;
    } else {
        cout << "Score " << find_score << " tidak ditemukan" << endl;
    }

    return 0;
}