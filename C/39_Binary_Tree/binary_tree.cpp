/*----------------------------------------------------------------------------
 * FILE: binary_tree.cpp
 *
 * DESCRIPTION:
 *    Implements a 'Binary_Tree' class.  Items are insterted in sorted
 *    order ... with complexity analysis of ... I believe N ln(N) order.
 *
 *    However, the 'insert' method performs automatic re-balance if the
 *    tree is unbalanced.  So that could throw off the 'insert' timing.
 *    But since that timing is based on the assumption that the tree
 *    is always balanced, there has to be some give-n-take somewhere.
 *
 *    And it implements a 'find' method to search for a particular node.
 *    This should be fast ... N ln(N) ... I think.
 *
 * COPYRIGHT:
 *    Copyright (c) 2024
 *        Tim MacAndrew (six_eight_squash@yahoo.com)
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *--------------------------------------------------------------------------*/

#include <iostream>
#include <binary_tree.h>


/*----------------------------------------------
 * METHOD: Binary_Tree
 *
 * DESCRIPTION:
 *    Class constructor.
 *---------------------------------------------*/
Binary_Tree::Binary_Tree (void)
{
   std::cout << "---> Binary_Tree constructor" << std::endl;
}


/*----------------------------------------------
 * METHOD: ~Binary_Tree
 *
 * DESCRIPTION:
 *    Class destructor.
 *---------------------------------------------*/
Binary_Tree::~Binary_Tree (void)
{
   std::cout << "---> Binary_Tree destructor" << std::endl;

   if ( root == NULL )
   {
       std::cout << "---> Binary_Tree is empty" << std::endl;

       return;
   }

   Delete_Node (root);
}


/*----------------------------------------------
 * METHOD: Add 
 *
 * DESCRIPTION:
 *    Adds the given 'i' to the binary_tree in
 *    sorted order.
 *
 *    Duplicate 'i' values are silently dropped.
 *---------------------------------------------*/
void Binary_Tree::Add (const int i)
{
   Node_Type *new_node = new Node_Type;

   new_node->value  = i;
   new_node->opaque = 0;
   new_node->left   = NULL;
   new_node->right  = NULL;

   if ( root == NULL )
   {
       root = new_node;
   }
   else
   {
       Insert_Node (root, new_node);

       Rebalance();
   }
}


/*----------------------------------------------
 * METHOD: Find
 *
 * DESCRIPTION:
 *    Traverses the tree and determines if the
 *    value 'i' is in the tree.
 *---------------------------------------------*/
bool Binary_Tree::Find (const int i)
{
   if ( root == NULL )
   {
       std::cout << "---> Tree is empty" << std::endl;

       return false;
   }

   bool answer;

   answer = Find_Value (root, i);

   return answer;
}


/*----------------------------------------------
 * METHOD: Num_Nodes
 *
 * DESCRIPTION:
 *    Returns the number of items in the
 *    binary tree.
 *---------------------------------------------*/
unsigned int Binary_Tree::Num_Nodes (void)
{
   if ( root == NULL )
   {
       return 0;
   }

   unsigned int count = 0;

   count = Count_Nodes (root);

   return count;
}


/*----------------------------------------------
 * METHOD: Print
 *
 * DESCRIPTION:
 *    Prints the contents of the binary tree
 *    as a linear, sorted list to <stdout>.
 *---------------------------------------------*/
void Binary_Tree::Print (void)

{
   Print_Node (root);

   std::cout << std::endl;
}


/*----------------------------------------------
 * METHOD: Print_As_Treee
 *
 * DESCRIPTION:
 *    Prints the contents of the tree to
 *    <stdout> ... upside down.
 *---------------------------------------------*/
void Binary_Tree::Print_As_Treee(void)
{
   max_depth = 0;

   Color_Node (root, 1);

   for (unsigned int i = max_depth; i > 0; i--)
   { 
       Print_Tree_Node (root, i);

       std::cout << std::endl;
   }
}


/*----------------------------------------------
 * METHOD: Find_Value
 *
 * DESCRIPTION:
 *    Recursively traverses the sub-tree
 *    starting at 'top' and attempts to
 *    locate the node with the value 'i'.
 *    Returns 'true' if found, 'false'
 *    otherwise.
 *---------------------------------------------*/
bool Binary_Tree::Find_Value
                    (Binary_Tree::Node_Type *top,
                     const int              i)
{
   if ( top == NULL )
   {
       std::cout << "***> ERROR - Find_Value\n"
                 << "***>       - top node is NULL"
                 << std::endl;

       return false;
   }

   if (top->value == i)
   {
       return true;
   }

   bool found = false;

   if (top->left != NULL)
   {
       found = Find_Value (top->left, i);
   }

   if ( ( ! found ) && (top->right != NULL) )
   {
       found = Find_Value (top->right, i);
   }

   return found;
}


/*----------------------------------------------
 * METHOD: Insert_Node
 *
 * DESCRIPTION:
 *    Recursively traverses the sub-tree
 *    starting at 'top' and adds the given
 *    item 'new_node' as a leaf to the
 *    sub-tree.
 *
 *    Duplicates are silently dropped.
 *---------------------------------------------*/
void Binary_Tree::Insert_Node
                     (Node_Type *top,
                      Node_Type *new_node)
{
   if ( top->value == new_node->value )
   {
       /*
	* Skip duplicates
	*/
       delete new_node;

       return;
   }

   if ( top->value < new_node->value )
   {
       if ( top->right == NULL )
       {
           top->right = new_node;
       }
       else
       {
           Insert_Node (top->right, new_node);
       }
   }
   else
   {
       if ( top->left == NULL )
       {
           top->left = new_node;
       }
       else
       {
           Insert_Node (top->left, new_node);
       }
   }
}


/*----------------------------------------------
 * METHOD: Delete_Node
 *
 * DESCRIPTION:
 *    Deletes the specified node and all of
 *    its children nodes ... left and right.
 *
 *    Implementation is to recursively pluck
 *    (delete) left and right nodes until the
 *    specified node itself can be deleted.
 *---------------------------------------------*/
void Binary_Tree::Delete_Node (Node_Type *node)
{
   if ( node == NULL )
   {
       std::cout << "***> ERROR - Delete_Node"
                 << "***>       - specified node to"
                 << "***>       - delete is NULL"
                 << std::endl;

       return;
   }

   if ( node->left != NULL )
   {
       Delete_Node ( node->left );
   }

   if ( node->right != NULL )
   {
       Delete_Node ( node->right );
   }

   delete node;

   node = NULL;
}


/*----------------------------------------------
 * METHOD: Count_Nodes
 *
 * DESCRIPTION:
 *    Recursively counts the number of nodes
 *    starting at 'node' and all of its
 *    child nodes (left and right).
 *---------------------------------------------*/
unsigned int Binary_Tree::Count_Nodes (Node_Type *node)

{
   unsigned int count = 0;

   if ( node->left != NULL )
   {
       count = Count_Nodes (node->left);
   }

   if ( node->right != NULL )
   {
       count = count + Count_Nodes (node->right);
   }

   count++;

   return count;
}


/*----------------------------------------------
 * METHOD: Color_Node
 *
 * DESCRIPTION:
 *    Recursively assigns a 'depth' value to
 *    the 'opaque' attribute of each node in
 *    the tree.  The 'root' node has a depth
 *    of 1, the left and right nodes a depth
 *    of 2, and each of their child nodes a
 *    depth of 3, and so on.
 *
 *    This is done in preparation of printing
 *    the node values (to <stdout> via the
 *    'Print_Tree_Node' method).  All nodes at
 *    the same depth are printed on the same
 *    line of the console/output.
 *---------------------------------------------*/
void Binary_Tree::Color_Node
                 (Binary_Tree::Node_Type *node,
                  unsigned int           depth)
{
   if ( node == NULL )
   {
       std::cout << "***> ERROR - Color_Node\n"
                 << "***>       - node is NULL\n"
                 << std::endl;

       return;
   }

   node->opaque = depth;

   if (max_depth < depth)
   {
       max_depth = depth;
   }

   depth++;

   if (node->left != NULL)
   {
       Color_Node (node->left, depth);
   }

   if (node->right != NULL)
   {
       Color_Node (node->right, depth);
   }

   //std::cout << "Max depth = " + std::to_string(max_depth) << std::endl;
}


/*----------------------------------------------
 * METHOD: Print_Node
 *
 * DESCRIPTION:
 *    This is a recursive method that traverses
 *    the binary tree and prints the contents
 *    of each node so the result is a linear,
 *    sorted array of 'values'.
 *
 *    First, any nodes on the 'left' are
 *    recursively printed ... then the value
 *    of 'node' is printed ... then all the
 *    nodes to the right are printed.
 *---------------------------------------------*/
void Binary_Tree::Print_Node
                 (Binary_Tree::Node_Type *node)
{
   if ( node == NULL )
   {
       std::cout << "***> ERROR - Print_Node"
                 << "***>       - Given node is NULL"
                 << std::endl;
   }

   if ( node->left != NULL )
   {
       Print_Node (node->left);
   }

   std::cout << " " + std::to_string(node->value) + " ";

   if ( node->right != NULL )
   {
       Print_Node (node->right);
   }
}


/*----------------------------------------------
 * METHOD: Print_Tree_Node
 *
 * DESCRIPTION:
 *    Recursively prints any node starting at
 *    'node' that has the specified 'depth'
 *    value (in the 'opaque' attribute).
 *    If 'node' or any child nodes have an
 *    'opaque' value of 'depth', the node's
 *    'value' will be printed to <stdout>.
 *    Once the 'value' is printed, the
 *    'opaque' value is cleard (0) so it
 *    won't be repeated.  If 'node' or any
 *    child nodes do not have the same
 *    'depth' value, it is not printed
 *    (under the assumption that it will be
 *    printed when the 'depth' value matches
 *    on a later iteration).
 *---------------------------------------------*/
void Binary_Tree::Print_Tree_Node 
                 (Binary_Tree::Node_Type *node, 
                  const unsigned int     depth)
{
   if ( node == NULL )
   {
       std::cout << "***> ERROR - Print_Tree_Node"
                 << "***>       - Given node is NULL"
		 << std::endl;
   }

   //std::cout << "Node (value = " + std::to_string(node->value) +
   //             ", opaque = " + std::to_string(node->opaque) + ")"
   //          << " depth = " + std::to_string(depth) << std::endl;

   if (node->opaque == depth)
   {
       std::cout << " " + std::to_string(node->value) + " ";

       node->opaque = 0;
   }

   if ( node->left )
   {
       Print_Tree_Node (node->left, depth);
   }

   if ( node->right )
   {
       Print_Tree_Node (node->right, depth);
   }
}


/*----------------------------------------------
 * METHOD: Sum_Values
 *
 * DESCRIPTION:
 *    Sums up the 'value' from the given 'node'
 *    and each sub-node.
 *---------------------------------------------*/
int Binary_Tree::Sum_Values (Node_Type *node)
{
   if ( node == NULL )
   {
       return 0;
   }

   int sum = node->value;

   if ( node->left )
   { 
       sum += Sum_Values (node->left);
   }

   if ( node->right )
   {
       sum += Sum_Values (node->right);
   }

   return sum;
}


/*----------------------------------------------
 * METHOD: Find_Median_Node
 *
 * DESCRIPTION:
 *    Finds the 'median' node in the
 *    tree starting at the given 'top_node'.
 *    This is a recursive depth-search that
 *    is invoked during a 'rebalance' operation.
 *---------------------------------------------*/
Binary_Tree::Node_Type *Binary_Tree::Find_Median_Node
                            (Binary_Tree::Node_Type *top_node,
                             const int              avg)
{
   Node_Type *med_node = NULL;
   Node_Type *tmp_node = NULL;
   int       dev       = 0;
   int       tmp_dev   = 0;

   if (top_node == NULL)
   {
       std::cout << "***> ERROR - Find_Median_Node\n"
                 << "***>       - node is NULL"
                 << std::endl;

       return NULL;
   }

   dev = std::abs(top_node->value - avg);

   med_node = top_node;

   //std::cout << "---> Node = " + std::to_string(top_node->value)     +
   //             ", Avg = " + std::to_string(avg)                     +
   //             ", diff = " + std::to_string(dev) << std::endl;

   if ( top_node->left != NULL )
   {
       tmp_node = Find_Median_Node (top_node->left, avg);

       if (tmp_node != NULL)
       {
          tmp_dev = std::abs(tmp_node->value - avg);

          if ( tmp_dev < dev ) 
          {
              dev = tmp_dev;

              // std::cout << "---> Switch root to LEFT node " +
              //           std::to_string(tmp_node->value)
              //           << std::endl;

              med_node = tmp_node;
          }
       }
   }

   if ( top_node->right != NULL )
   {
       tmp_node = Find_Median_Node (top_node->right, avg);
  
       if ( tmp_node != NULL )
       { 
           tmp_dev = std::abs(tmp_node->value - avg);

           if ( tmp_dev < dev )
           {
               dev = tmp_dev;

               // std::cout << "---> Switch root to RIGHT node " +
               //           std::to_string(tmp_node->value)
               //           << std::endl;

               med_node = tmp_node;
           }
       }
   }

   return med_node;
}


/*----------------------------------------------
 * METHOD: Rebalance
 *
 * DESCRIPTION:
 *    As items are added to the tree, if the
 *    tree is 'unbalanced' then this method
 *    will reorganize the tree so it is more
 *    appropriately balanced.
 *---------------------------------------------*/
void Binary_Tree::Rebalance (void)
{
   unsigned int num_left_nodes  = 0;

   if ( root->left != NULL )
   {
      num_left_nodes = Count_Nodes (root->left);
   }
   
   unsigned int num_right_nodes = 0;

   if ( root->right != NULL )
   {
       num_right_nodes = Count_Nodes (root->right);
   }
   
   unsigned int total_num_nodes = num_left_nodes + num_right_nodes + 1;
   float        left_node_weight;

   left_node_weight = (float) num_left_nodes / (float) total_num_nodes;

   if ( (left_node_weight > 0.70f) ||
        (left_node_weight < 0.30f) )
   {
       int sum;

       sum = Sum_Values (root);

       int num_nodes;

       num_nodes = Count_Nodes(root);

       float avg = (float) sum / (float) num_nodes;

       //std::cout << "---> sum....: " + std::to_string(sum) << std::endl;
       //std::cout << "---> count..: " + std::to_string(num_nodes) << std::endl;
       //std::cout << "---> Average: " + std::to_string(avg) << std::endl;

       Node_Type *median;

       median = Find_Median_Node ( root, (int) avg );

       // std::cout << "---> Rebalance: median = " +
       //           std::to_string(median->value)
       //           << std::endl;

       if ( median == root )
       {
           /*
            * The 'root' is already the median
            */
           return;
       }

       Binary_Tree::Node_Type *parent   = NULL;
       Binary_Tree::Node_Type *out_node = NULL;

       Remove_Node_From_Tree
             (median->value,
	      &parent,
	      &median);

       while (root)
       {
           Remove_Node_From_Tree
                 (root->value,
                  &parent,
                  &out_node);

	   Insert_Node (median, out_node);
       }

       root = median;
   }
}


/*----------------------------------------------
 * METHOD: Remove_Node_From_Tree
 *
 * DESCRIPTION:
 *    Searches the tree for the node with 'value'
 *    and removes it from the tree.  Note, the
 *    node is NOT deleted from the tree, it
 *    is only removed.
 *
 *    If the node is found, then the pointer
 *    'out_node' is set to point to the node.
 *    Also, if there is a parent, then the
 *    pointer 'parent' is set to point to it.
 *
 *    The 'left' and 'right' pointers of the
 *    'out_node' are set to NULL, which would
 *    be the case if it was a 'leaf' node
 *    anyway.
 *
 *    It is the responsibility of the caller
 *    to 'manage' the removed node (via
 *    the 'out_node' pointer).
 *
 *    If the tree is empty, the 'out' pointers
 *    are set to NULL.
 *
 *    If there's only one node in the tree, then
 *    'out_node' is set to that node, the
 *    'parent' pointer is set to NULL, and
 *    the 'root' pointer is set to NULL, which
 *    means the tree is now empty.
 *---------------------------------------------*/
void Binary_Tree::Remove_Node_From_Tree
                     (const int              value,
                      Binary_Tree::Node_Type **parent,
                      Binary_Tree::Node_Type **out_node)
{
   *parent   = NULL;
   *out_node = NULL;

   /*
    * Case 0:
    *    Tree is empty
    */
   if (root == NULL)
   {
       std::cout << "***> ERROR - Remove_Node_From_Tree\n"
                 << "***>       - tree is NULL"
                 << std::endl;

       return;
   }

   /*
    * Case 1:
    *    root is match ...
    */
   if ( root->value == value )
   {
       /*
        * Sub-case 1.1:
        *    ... and it's the only node
        */
       if ( (root->left == NULL) &&
            (root->right == NULL) )
       {
           //std::cout << "---> Remove node from tree - case 1.1" << std::endl;

           *out_node = root;

           root = NULL;

           return;
       }

       /*
        * Sub-case 1.2:
        *    ... and only has a LEFT
	*    sub-tree ... no RIGHT sub-tree.
        */
       if ( (root->left != NULL) &&
            (root->right == NULL) )
       {
           //std::cout << "---> Remove node from tree - case 1.2" << std::endl;

           *out_node = root;

           root = root->left;

	   (*out_node)->left = NULL;

           return;
       }

       /*
        * Sub-case 1.3:
        *    ... and only has a RIGHT
	*    sub-tree ... no LEFT sub-tree.
        */
       if ( (root->left == NULL) && 
            (root->right != NULL) )
       {
           //std::cout << "---> Remove node from tree - case 1.3" << std::endl;

           *out_node = root;

           root = root->right;

           (*out_node)->right= NULL;

           return;
       }

       if ( (root->left != NULL) &&
            (root->right != NULL) )
       {
           //std::cout << "---> Remove node from tree - case 1.4" << std::endl;

           Binary_Tree::Node_Type *left_child;

           left_child = Find_Left_Leaf_Node ( root->right );

           left_child->left = root->left;

           *out_node = root;

           root = root->right;

           (*out_node)->left  = NULL;
           (*out_node)->right = NULL;

           return;
       }
   }

   Find_Node (value, root, parent, out_node);

   if ( ( *out_node != NULL ) && ( *parent == NULL) )
   {
       /*
        * Means root node was returned, but this
        * should've been handled above.
        */
       std::cout << "***> ERROR - Remove_Node_From_Tree\n"
	         << "***>    Invalid find operation.\n"
                 << "***>    returned node is root.\n"
                 << "***>    Not expected here.\n"
		 << "***>    search value..: " +
                    std::to_string((*out_node)->value) + "\n"
		 << "***>    node value....: " +
                    std::to_string((*out_node)->value) + "\n"
		 << "***>    root value....: " +
                    std::to_string(root->value)
                 << std::endl;

       *parent   = NULL;

       *out_node = NULL;

       return;
   }

   if ( ( *out_node != NULL ) && ( *parent != NULL ) )
   {
       if ( ( (*out_node)->left  == NULL ) &&
            ( (*out_node)->right == NULL ) )
       {
           /*
            * Case 2
            *    Node has parent, but no leaf nodes
            */
           if ( (*parent)->left == *out_node )
           {
               (*parent)->left = NULL;
           }
	   else if ( (*parent)->right == *out_node )
           {
               (*parent)->right = NULL;
           }
       }
       else if ( ( (*out_node)->left  != NULL ) &&
                 ( (*out_node)->right == NULL ) )
       {
           /*
            * Case 3
            *    Node has parent.
	    *    Node has LEFT child node/tree only
            */
           if ( (*parent)->left == *out_node )
           {
               (*parent)->left = (*out_node)->left;

	       (*out_node)->left = NULL;
           }
           else if ( (*parent)->right == *out_node )
           {
               (*parent)->right = (*out_node)->left;

	       (*out_node)->left = NULL;
           }
       }
       else if ( ( (*out_node)->left  == NULL ) &&
                 ( (*out_node)->right != NULL) )
       {
           /*
            * Case 4
            *    Node has parent.
            *    Node has RIGHT child node/tree only
            */
           if ( (*parent)->left == *out_node )
           {
               (*parent)->left = (*out_node)->right;

               (*out_node)->right = NULL;
           }
           else if ( (*parent)->right == *out_node )
           {
               (*parent)->right = (*out_node)->right;

               (*out_node)->right = NULL;
           }
       }
       else if ( ( (*out_node)->left  != NULL ) &&
                 ( (*out_node)->right != NULL) )
       {
           /*
            * Case 5
            *    Node has parent.
            *    Node has both RIGHT and LEFT child node/tree
            */
           if ( (*parent)->left == *out_node )
           {
               (*parent)->left = (*out_node)->right;

	       Binary_Tree::Node_Type *left_child;

               left_child = Find_Left_Leaf_Node ( (*out_node)->right );

               left_child->left = (*out_node)->left;

               (*out_node)->left  = NULL;
               (*out_node)->right = NULL;
           }
           else if ( (*parent)->right == *out_node )
           {
               (*parent)->right = (*out_node)->right;

	       Binary_Tree::Node_Type *left_child;

               left_child = Find_Left_Leaf_Node ( (*out_node)->right );

               left_child->left = (*out_node)->left;

               (*out_node)->left  = NULL;
               (*out_node)->right = NULL;
           }
       }
   }
}


/*----------------------------------------------
 * METHOD: Find_Node
 *
 * DESCRIPTION:
 *    Starting at the node 'top' this method
 *    recursively searches the tree for the
 *    node with 'value'.  If found, the 'node'
 *    is set to point to that node.  If there
 *    is a parent node, then 'parent' is set
 *    to point to it.
 *
 *    If the tree starting at 'top' is empty,
 *    then both the 'node' and 'parent'
 *    pointers are set to NULL.
 *
 *    If the node is found but there's not
 *    a parent node (i.e. the found node is
 *    'top') then the 'node' is set to that
 *    node and the 'parent' node is set
 *    to NULL.
 *
 *    This method is a 'passive' function in
 *    that the tree is left unchanged when
 *    done.
 *---------------------------------------------*/
void Binary_Tree::Find_Node
           (const int              value,
            Binary_Tree::Node_Type *top_node,
            Binary_Tree::Node_Type **parent,
            Binary_Tree::Node_Type **node)
{
   *node   = NULL;
   *parent = NULL;

   /*
    * Case 0:
    *    Tree is empty
    */
   if (top_node == NULL)
   {
       std::cout << "***> ERROR - Find_Node\n"
                 << "***>       - tree from 'top' node is NULL"
                 << std::endl;

       return;
   }

   if ( top_node->value == value )
   {
       *node = top_node;
   }
   else if (top_node->value > value)
   {
       if ( top_node->left != NULL )
       {
           Find_Node (value, top_node->left, parent, node);

	   if ( ( *node != NULL ) &&
                ( top_node->left == *node ) &&
                ( (*node)->value == value ) )
           {
               *parent = top_node;
           }
       }
   }
   else /* top->value < value */
   {
       if ( top_node->right != NULL )
       {
           Find_Node (value, top_node->right, parent, node);

           if ( ( *node != NULL ) &&
                ( top_node->right == *node ) &&
                ( (*node)->value == value ) )
           {
               *parent = top_node;
           }
       }
   }
}


/*----------------------------------------------
 * METHOD: Find_Left_Leaf_Node
 *
 * DESCRIPTION:
 *    Starting at the node 'top' this method
 *    recursively searches the tree for the
 *    left-most node, which is a leaf-node
 *    with the least 'value' on that sub-tree.
 *    The function returns a pointer to the
 *    leaf-node.  If 'top' has no 'left'
 *    child nodes, then 'top' is returned
 *    because it is the leaf-node.
 *---------------------------------------------*/
Binary_Tree::Node_Type *Binary_Tree::Find_Left_Leaf_Node
                           (Binary_Tree::Node_Type *top)
{
   if ( top == NULL )
   {
       std::cout << "***> ERROR - Find_Left_Leaf_Node\n"
                 << "***>       - top node is NULL"
		 << std::endl;

       return NULL;
   }

   if ( top->left == NULL )
   {
       return top;
   }

   Binary_Tree::Node_Type *tmp = top;

   while ( tmp->left != NULL )
   {
       tmp = tmp->left;
   }

   return tmp;
}

/* EOF */

