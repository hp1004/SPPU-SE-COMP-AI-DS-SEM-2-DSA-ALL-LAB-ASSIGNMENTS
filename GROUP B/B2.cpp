/*
🔘PROBLEM STATEMET:-
Construct an expression tree from the given prefix expression eg. +-- a*bc/def and
traverse it using postorder traversal(nonrecursive) and then delete the entire tree.
*/ 

/*
#️⃣ QUICK REVISION NOTES:-

1. Expression trees are binary trees used to represent expressions.
2. The internal nodes of the expression tree hold operators like +, -, *, /, ^, etc.
3. The leaf nodes of the expression tree contain the operands on which operations are performed.
4. The operands can be of any data type, such as characters, integers, doubles, etc.
5. Expression trees can represent different types of expressions, including infix, postfix, and prefix.
6. The hierarchical structure of the expression tree reflects the precedence and associativity of the operators.
7. Evaluation of an expression is done by recursively traversing the expression tree and performing operations based on the operators at each node.
8. Expression trees provide a structured and efficient way to evaluate and manipulate mathematical expressions.
*/ 

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* constructExpressionTree(string prefixExpression) {
    stack<TreeNode*> stk;
    
    // Traverse the prefix expression in reverse order
    for (int i = prefixExpression.length() - 1; i >= 0; i--) {
        char ch = prefixExpression[i];
        
        // Create a new node for each character in the expression
        TreeNode* newNode = new TreeNode;
        newNode->data = ch;
        newNode->left = newNode->right = NULL;
        
        // If the character is an operand, push it onto the stack
        if (isalnum(ch)) {
            stk.push(newNode);
        }
        // If the character is an operator, pop two operands from the stack
        // and assign them as the left and right children of the operator node
        else {
            newNode->left = stk.top();
            stk.pop();
            newNode->right = stk.top();
            stk.pop();
            stk.push(newNode);
        }
    }
    
    // The top of the stack will be the root of the expression tree
    return stk.top();
}

void postOrderTraversal(TreeNode* root) {
    if (root == NULL)
        return;
    
    stack<TreeNode*> stk;
    TreeNode* current = root;
    TreeNode* lastVisited = NULL;
    
    while (!stk.empty() || current != NULL) {
        if (current != NULL) {
            stk.push(current);
            current = current->left;
        }
        else {
            TreeNode* topNode = stk.top();
            
            // If the right child exists and has not been visited yet
            if (topNode->right != NULL && topNode->right != lastVisited) {
                current = topNode->right;
            }
            else {
                // Process the node
                cout << topNode->data << " ";
                stk.pop();
                lastVisited = topNode;
            }
        }
    }
}

void deleteTree(TreeNode* root) {
    if (root == NULL)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string prefixExpression = "+--a*bc/def";
    TreeNode* root = constructExpressionTree(prefixExpression);

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    deleteTree(root);

    return 0;
}
