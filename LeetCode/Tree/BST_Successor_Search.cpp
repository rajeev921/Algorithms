#include <iostream>

using namespace std;

struct Node
{
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your 
// findInOrderSuccessor function on
Node *getNodeByKey( Node *root, int key )
{
   Node *currentNode = root;

   while( currentNode )
   {
      if( key == currentNode->key )
         return currentNode;

      if( key < currentNode->key )
         currentNode = currentNode->left;
      else
         currentNode = currentNode->right;
   }

   return nullptr;
}

function findInOrderSuccessor(inputNode):
    if (inputNode.right != null):
        # return the node with minimum key in the right subtree
        return findMinKeyWithinTree(inputNode.right)

    ancestor = inputNode.parent
    child = inputNode

    # travel up using the parent pointer until you see
    # a node which is the left child of its parent. The parent
    # of such a node is successorNode.
    while (ancestor != null AND child == ancestor.right):
        child = ancestor
        ancestor = child.parent

    return ancestor

function findMinKeyWithinTree(inputNode):
    while (inputNode.left != null):
        inputNode = inputNode.left

    return inputNode

int main() {
  return 0;
}
/*
First, make sure your peer understands the question.
If you or your peer have a hard time understanding how to go about solving this problem,
or could use a reminder of how BSTs work, take this interactive BST application for a spin.

If your peer is still stuck, ask them to look again at the examples provided above 
(in the diagram caption and “For example”) and see if based on these examples they can discern
the two different cases in which a node is an Inorder Successor of a given input node.

Your peer may suggest another approach and that is to start searching from the root and 
traversing the tree in a binary search manner. While correct, ask them to come up with a 
solution that doesn’t require the root.
*/