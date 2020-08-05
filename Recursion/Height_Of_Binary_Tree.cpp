int heightOfBinaryTree(node* root)
{
    if(root == NULL)
        return 0;
        
   return 1 + max(heightOfBinaryTree(roo->left), heightOfBinaryTree(root->right));
}