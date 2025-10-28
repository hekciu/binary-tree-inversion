#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


static uint8_t nodes_index = 0;


struct node {
    struct node* left;
    struct node* right;
    uint8_t value;
    uint8_t index;
};


struct node* create_node(uint8_t value) {
    struct node* output = malloc(sizeof(struct node));

    output->value = value;
    output->left = NULL;
    output->right = NULL;
    output->index = nodes_index;

    nodes_index++;

    return output;
}


struct node* create_tree() {
    struct node* root = create_node(1);

    root->left = create_node(3);
    root->right = create_node(2);

    root->right->left = create_node(5);
    root->right->right = create_node(4);

    root->left->left = create_node(6);
    root->left->right = create_node(4);

    return root;
}


void free_tree(struct node* node) {
    if (node->left != NULL) free_tree(node->left);

    if (node->right != NULL) free_tree(node->right);

    free(node);
}


void _print_nodes(struct node* node) {
    printf("index: %d ", node->index);
    printf("value: %d ", node->value);

    if (node->left != NULL) printf("left: %d ", node->left->value);

    if (node->right != NULL) printf("right: %d ", node->right->value);

    printf("\n");

    if (node->left != NULL) _print_nodes(node->left);

    if (node->right != NULL) _print_nodes(node->right);
}


void print_tree(struct node* root) {
    _print_nodes(root);
}


void inverse_tree(struct node* node) {
    struct node* tmp = node->left;

    node->left = node->right;

    node->right = tmp;

    if (node->right != NULL) inverse_tree(node->right);

    if (node->left != NULL) inverse_tree(node->left);
}


int main(void) {
    struct node* root = create_tree();

    printf("original:\n");
    print_tree(root);
    printf("\n\n");

    inverse_tree(root);

    printf("inverted:\n");
    print_tree(root);

    free_tree(root);

    return 0;
}
