Node* deleteNode(Node* node, int k) {
        if (!node) return nullptr;
        if (k < node->key) {
            node->left = deleteNode(node->left, k);
        } else if (k > node->key) {
            node->right = deleteNode(node->right, k);
        } else {
            // Case 1: No left child or leaf node
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // Case 2: No right child
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children
            Node* minNode = node->right;
            while (minNode->left) minNode = minNode->left;
            node->key = minNode->key;
            node->right = deleteNode(node->right, minNode->key);
        }
        return node;
    }
