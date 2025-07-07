/*----------------------------------------------------------------------------
 * FILE: binary_tree.h
 *
 * DESCRIPTION:
 *    Declares a 'Binary_Tree' class.  Items are insterted in sorted
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
#ifndef Q14_BINARY_TREE

   #define Q14_BINARY_TREE

   class Binary_Tree {

      public:

         /*----------------------------------------------
          * METHOD: Binary_Tree
          *
          * DESCRIPTION:
          *    Class constructor.
          *---------------------------------------------*/
         Binary_Tree (void);

         /*----------------------------------------------
          * METHOD: ~Binary_Tree
          *
          * DESCRIPTION:
          *    Class destructor.
          *---------------------------------------------*/
         ~Binary_Tree (void);

         /*----------------------------------------------
          * METHOD: Add 
          *
          * DESCRIPTION:
          *    Adds the given 'i' to the binary_tree in
	  *    sorted order.
          *
          *    Duplicate 'i' values are silently dropped.
          *---------------------------------------------*/
         void Add (const int i);

	 /*----------------------------------------------
          * METHOD: Find
          *
          * DESCRIPTION:
          *    Traverses the tree and determines if the
	  *    value 'i' is in the tree.
          *---------------------------------------------*/
         bool Find (const int i);

         /*----------------------------------------------
          * METHOD: Num_Nodes
          *
          * DESCRIPTION:
          *    Returns the number of items in the
          *    binary tree.
          *---------------------------------------------*/
         unsigned int Num_Nodes (void);
 
         /*----------------------------------------------
          * METHOD: Print
          *
          * DESCRIPTION:
          *    Prints the contents of the binary tree
          *    as a linear, sorted list to <stdout>.
          *---------------------------------------------*/
         void Print (void);

	 /*----------------------------------------------
          * METHOD: Print_As_Tree
          *
          * DESCRIPTION:
          *    Prints the contents in the form of an
	  *    upside-down tree to <stdout>.
          *---------------------------------------------*/
         void Print_As_Treee (void);

      private:

         struct Node_Type
         {
             int          value;
	     unsigned int opaque;
             Node_Type    *left;
	     Node_Type    *right;
         };

         Node_Type *root = (Node_Type *) NULL;

	 unsigned int max_depth = 0;


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
         bool Find_Value
                    (Node_Type *top,
                     const int i);

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
         void Insert_Node
                    (Node_Type *top,
                     Node_Type *new_node);

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
         void Delete_Node (Node_Type *node);

	 /*----------------------------------------------
          * METHOD: Count_Nodes 
          *
          * DESCRIPTION:
          *    Recursively counts the number of nodes
	  *    starting at 'node' and all of its
	  *    child nodes (left and right).
          *---------------------------------------------*/
         unsigned int Count_Nodes (Node_Type *node);

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
         void Print_Node (Node_Type *node);

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
	  *    the node values (to stdout via the
	  *    'Print_Tree_Node' method).  All nodes at
	  *    the same depth are printed on the same
	  *    line of the console/output.
          *---------------------------------------------*/
         void Color_Node
                 (Node_Type    *node,
                  unsigned int depth);

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
         void Print_Tree_Node
                 (Node_Type          *node,
                  const unsigned int depth);

         /*----------------------------------------------
          * METHOD: Sum_Values
          *
          * DESCRIPTION:
          *    Sums up the 'value' from the given 'node'
          *    and each sub-node.
          *---------------------------------------------*/
         int Sum_Values (Node_Type *node);

         /*----------------------------------------------
          * METHOD: Find_Median_Node
          *
          * DESCRIPTION:
          *    Finds the 'median' node in the
	  *    tree starting at the given 'top_node'.
	  *    This is a recursive depth-search that
	  *    is invoked during a 'rebalance' operation.
          *---------------------------------------------*/
         Node_Type *Find_Median_Node
                       (Node_Type *top_node,
                        const int avg);

	 /*----------------------------------------------
          * METHOD: Rebalance 
          *
          * DESCRIPTION:
          *    As items are added to the tree, if the
	  *    tree is 'unbalanced' then this method
	  *    will reorganize the tree so it is more
	  *    appropriately balanced.
          *---------------------------------------------*/
	 void Rebalance (void);

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
         void Remove_Node_From_Tree
                 (const int value,
		  Node_Type **parent,
		  Node_Type **out_node);

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
         void Find_Node
                 (const int value,
		  Node_Type *top,
                  Node_Type **parent,
                  Node_Type **node);

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
         Node_Type *Find_Left_Leaf_Node
                       (Node_Type *top);

   };

#endif

/* EOF */

