

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;
namespace sol1430
{
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node(int _val)
        {
            val = _val;
            left = nullptr;
            right = nullptr;
        }
    };
    class Solution
    {
    public:
        bool validSeq(Node *tree, vector<int> &seq);
    };
}
#endif