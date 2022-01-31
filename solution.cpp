#include "solution.h"
#include <string>
#include <vector>
#include <functional>
using namespace sol1430;
using namespace std;

/* takeaways
   - you can think of this as a two-pointers problem
     - p1 (first pointer) is traversing through the tree
       top-down
     - p2 (second pointer) is traversing through the
       sequence left-to-right
     - both pointers will advance to next if their
       values are the same
     - to produce a valid sequence p1 must point at
       a leaf node, and p2 point at the last element
       of the sequence when the traversal is done.
       Also the value of the leaf node needs to be
       the same as the last element of the sequence

   - the code below tree is the p1 and index is the p2

*/

bool Solution::validSeq(Node *tree, vector<int> &seq)
{
    /*
      - index points to the element we are
        visiting in the seq
    */
    /* C++ notes
       - "visit" function must be in the
         capture by reference list or you
         won't be able to call it recursively
         as you don't have access to it
         inside the visit function body
    */
    function<bool(Node *, vector<int> &, int)> visit =
        [&visit](Node *node, vector<int> &seq, int index)
    {
        if (node == nullptr)
            return false;
        /*
          - running ouf of the seq and we
            are still not arriving at a
            leaf yet
        */
        if (index >= seq.size())
            return false;
        /*
          - the node we are visiting has different
            value than the seq element we are
            visiting
        */
        if (node->val != seq[index])
        {
            return false;
        }
        /*
          - we arrive at a leaf
          - check if we are also at
            the last element of the sequence
        */
        if (node->left == nullptr && node->right == nullptr)
        {
            return index == seq.size() - 1;
        }

        /*
           - left or right first doesn't matter
           - just continue with the one that
             can return true or simply stop
             if neither is true
        */
        return visit(node->left, seq, index + 1) || visit(node->right, seq, index + 1);
    };

    return visit(tree, seq, 0);
}