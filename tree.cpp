#include <iostream>
#include <list>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insert(int value, char pos) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            insertRec(root, value, pos);
        }
    }

    void breadthFirstTraversal() const {
        if (!root) return;

        list<Node*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            Node* current = queue.front();
            cout << current->val << " ";
            queue.pop_front();

            if (current->left) queue.push_back(current->left);
            if (current->right) queue.push_back(current->right);
        }
    }

    void preorderTraversal(Node* node) const {
        if (node) {
            cout << node->val << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void inorderTraversal(Node* node) const {
        if (node) {
            inorderTraversal(node->left);
            cout << node->val << " ";
            inorderTraversal(node->right);
        }
    }

    void postorderTraversal(Node* node) const {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->val << " ";
        }
    }

private:
    void insertRec(Node* current, int value, char pos) {
        if (pos == 'l') {
            if (current->left == nullptr) {
                current->left = new Node(value);
            } else {
                cout << "Left child already exists. Choose another position.\n";
            }
        } else if (pos == 'r') {
            if (current->right == nullptr) {
                current->right = new Node(value);
            } else {
                cout << "Right child already exists. Choose another position.\n";
            }
        } else {
            cout << "Invalid position. Use 'l' for left or 'r' for right.\n";
        }
    }
};

int main() {
    BinaryTree tree;
    int choice, value;
    char pos;

    cout << "Enter the value of root node: ";
    cin >> value;
    tree.insert(value, 'r'); // Insert root

    do {
        cout << "\n1. Insert\n2. Breadth First Traversal\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            cout << "Left or Right of Root (l/r): ";
            cin >> pos;
            tree.insert(value, pos);
            break;
        case 2:
            tree.breadthFirstTraversal();
            break;
        case 3:
            tree.preorderTraversal(tree.root);
            break;
        case 4:
            tree.inorderTraversal(tree.root);
            break;
        case 5:
            tree.postorderTraversal(tree.root);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
