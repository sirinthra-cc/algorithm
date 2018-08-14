int get_height(Node* root, bool &is_balance){
    if(root == NULL) return 0;
    int left_height = get_height(root -> left);
    int right_height = get_height(root -> right);
    if(abs(left_height - right_height) > 1)
        is_balance = false;
    return max(left_height, right_height) + 1;
}


bool is_balanced(Node *root){
    bool is_balanced = true;
    get_height(root, is_balanced);
    return is_balanced;
}
