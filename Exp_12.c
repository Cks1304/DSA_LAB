#include <stdio.h>
#include <stdlib.h>

#define M 4  // Define the order of the B-tree

typedef struct BTreeNode {
    int keys[M - 1];
    struct BTreeNode* children[M];
    int is_leaf;
    int num_keys;
} BTreeNode;

BTreeNode* createNode() {
    BTreeNode* new_node = (BTreeNode*)malloc(sizeof(BTreeNode));
    if (!new_node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    new_node->is_leaf = 1;
    new_node->num_keys = 0;
    for (int i = 0; i < M; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

BTreeNode* insert(BTreeNode* root, int key) {
    if (root == NULL) {
        BTreeNode* new_node = createNode();
        new_node->keys[0] = key;
        new_node->num_keys = 1;
        return new_node;
    }

    if (root->num_keys < M - 1) {
        int i = root->num_keys - 1;
        while (i >= 0 && key < root->keys[i]) {
            root->keys[i + 1] = root->keys[i];
            i--;
        }
        root->keys[i + 1] = key;
        root->num_keys++;
        return root;
    }

    int i = 0;
    while (i < M - 1 && key > root->keys[i]) {
        i++;
    }
    root->children[i] = insert(root->children[i], key);

    return root;
}

void printBTree(BTreeNode* root, int depth) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->num_keys; i++) {
            printBTree(root->children[i], depth + 1);
            for (int j = 0; j < depth; j++) {
                printf("\t");
            }
            printf("%d\n", root->keys[i]);
        }
        printBTree(root->children[i], depth + 1);
    }
}

int main() {
    BTreeNode* root = NULL;

    int keys[] = {3, 7, 1, 5, 10, 9, 8, 2, 6, 4};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < num_keys; i++) {
        root = insert(root, keys[i]);
    }

    printf("B-tree:\n");
    printBTree(root, 0);

    return 0;
}
