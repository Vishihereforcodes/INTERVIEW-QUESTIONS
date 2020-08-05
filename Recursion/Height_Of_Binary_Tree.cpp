// Question:- To find height of a given binary tree.

/*Approach:- 
1. Height of binary tree is the height of root node plus maximum of height of left subtree and right subtree.
2. So, we will calculate height of left and right subtree through recursion and add the maximum one into height of root node(1).
*/

int heightOfBinaryTree(node* root)
{
    if(root == NULL)
        return 0;
        
   return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
}
