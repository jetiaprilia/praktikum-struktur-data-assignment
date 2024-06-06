#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

// Struktur data untuk node tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Fungsi untuk memasukkan data ke dalam tree secara level-order
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return new TreeNode(data);
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new TreeNode(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new TreeNode(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Fungsi untuk traversal preorder
void preorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Fungsi untuk traversal inorder
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Fungsi untuk traversal postorder
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Fungsi untuk menampilkan menu
void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Masukkan data ke dalam tree\n";
    cout << "2. Tampilkan tree dalam Preorder\n";
    cout << "3. Tampilkan tree dalam Inorder\n";
    cout << "4. Tampilkan tree dalam Postorder\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi: ";
}

int main() {
    TreeNode* root = NULL;
    int choice, data;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data (angka): ";
                cin >> data;
                root = insertNode(root, data);
                break;
            case 2:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
