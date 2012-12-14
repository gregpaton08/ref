

struct node *mirrorbt(struct node *head) {

    if (head == nullptr)
        return head;
    else {
        struct node *new_node = (struct node)malloc(sizeof(struct node));
        new_node->value = head->value;
        new_node->left = mirrorbt(head->right);
        new_node->right = mirrorbt(head->left);
        return new_node;
    }
}
