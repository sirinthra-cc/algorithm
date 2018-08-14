struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* create_bst(vector<int> &sorted_arr, int first, int last){
    Node* current_node = NULL;
    if(first <= last){
        int mid = (first+last)/2;
        current_node = new Node(sorted_arr[mid]);
        current_node -> left = create_bst(sorted_arr, first, mid-1);
        current_node -> right = create_bst(sorted_arr, mid+1, last);
    }
    return current_node
}