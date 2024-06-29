
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int k) : value(k), left(nullptr), right(nullptr), height(1) {}
};

//mohasebe height
int height(Node* node) {
    return node ? node->height : 0;
}

//moghayese 2 meghdar
int max(int a, int b) {
    return (a > b) ? a : b;
}

//charkhesh be rast
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

//charkhesh be chap
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

//chack kardan height 2 taraf
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

//add new node
Node* insert(Node* node, int value) {
    if (!node)
        return new Node(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


Node* minValueNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int value) {
    
    //node root null ast ya na
	if (!root)
        return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {                                                 //replace node with its chldren
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {                                   //node farzandi nadare
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {                                          //kochektarin farzand rast be jaye node hazf shode
            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

int search(Node* root, int x) {
    for (Node* ptr = root; ptr != nullptr; ptr = ptr->left) {
        if (ptr->value == x)
            return 1;
    }

    for (Node* ptr = root; ptr != nullptr; ptr = ptr->right) {
        if (ptr->value == x)
            return 1;
    }
    return -1;
}

int main() {
    Node* root = nullptr;
    char answer;
    int n, num, delValue;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; ++i) {
        int item;
        cin >> item;
        root = insert(root, item);
    }

    cout << "For adding a new node, enter 'y': ";
    cin >> answer;
    if (answer == 'y') {
        cout << "Enter a number: ";
        cin >> num;
        root = insert(root, num);
        n++;
    }

    cout << "AVL Tree: ";
    inOrder(root);
    cout << endl;

    int result = search(root, 8);
    if (result == 1)
        cout << "Number 8 is in the tree." << endl;
    else
        cout << "There isn't an 8 in the tree." << endl;

    cout << "Enter a number to delete: ";
    cin >> delValue;
    root = deleteNode(root, delValue);

    cout << "AVL Tree after deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}
