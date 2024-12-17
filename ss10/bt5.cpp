#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void preOrder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

struct TreeNode* search(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Thêm ph?n t? vào cây\n");
    printf("2. Duy?t cây theo PreOrder\n");
    printf("3. Duy?t cây theo InOrder\n");
    printf("4. Duy?t cây theo PostOrder\n");
    printf("5. T?m ki?m ph?n t?\n");
    printf("6. Thoát\n");
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Duyet PreOrder: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Duyet InOrder: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Duyet PostOrder: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &data);
                struct TreeNode* result = search(root, data);
                if (result != NULL) {
                    printf("Phan tu %d da duoc tim thay.\n", data);
                } else {
                    printf("Phan tu %d khong ton tai trong cay.\n", data);
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

