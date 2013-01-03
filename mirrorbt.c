

struct node mirror(struct node *head) {

    struct node temp;
    queue q;
    q.push(head);

    while(false == q.isEmpty()) {
        q.pop(&temp);
        swap_children(temp);
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

void swap_children(struct node *parent) {

    if (parent == nullptr)
        return;

    struct node temp;
    temp = parent->right;
    parent->right = parent->left;
    parent->left = temp;
}
