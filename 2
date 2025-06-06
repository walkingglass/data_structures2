#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root = nullptr;

    void insert(int key) {
        root = insert(root, key);
    }

    int height() {
        return height(root);
    }

    ~BST() {
        destroy(root);
    }

private:
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);
        return node;
    }

    int height(Node* node) {
        if (!node) return -1; // Edge count
        return 1 + std::max(height(node->left), height(node->right));
    }

    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1000000000); // Large range to avoid duplicates

    std::vector<int> sizes = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    std::vector<double> n_values, ratios;
    const int trials = 10; // Average over 10 runs

    for (int n : sizes) {
        double avg_height = 0.0;
        for (int t = 0; t < trials; ++t) {
            BST tree;
            for (int i = 0; i < n; ++i) {
                tree.insert(dist(gen));
            }
            avg_height += tree.height();
        }
        avg_height /= trials;
        double ratio = avg_height / std::log2(n);
        n_values.push_back(n);
        ratios.push_back(ratio);
        std::cout << "n = " << n << ", avg height = " << avg_height << ", ratio = " << ratio << std::endl;
    }
    return 0;
}
