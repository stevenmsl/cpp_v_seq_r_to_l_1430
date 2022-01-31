#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;
using namespace sol1430;

/*
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation:
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure).
Other valid sequences are:
0 -> 1 -> 1 -> 0
0 -> 0 -> 0
*/

pair<Node *, vector<int>> testFixture1()
{
  auto *tree = new Node(0);
  /* left */
  tree->left = new Node(1);
  tree->left->left = new Node(0);
  tree->left->left->right = new Node(1);
  tree->left->right = new Node(1);
  tree->left->right->left = new Node(0);
  tree->left->right->right = new Node(0);

  /* right */
  tree->right = new Node(0);
  tree->right->left = new Node(0);

  vector<int> seq = {0, 1, 0, 1};

  return make_pair(tree, seq);
}

/*
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false
Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.
*/

pair<Node *, vector<int>> testFixture2()
{
  auto *tree = new Node(0);
  /* left */
  tree->left = new Node(1);
  tree->left->left = new Node(0);
  tree->left->left->right = new Node(1);
  tree->left->right = new Node(1);
  tree->left->right->left = new Node(0);
  tree->left->right->right = new Node(0);

  /* right */
  tree->right = new Node(0);
  tree->right->left = new Node(0);

  vector<int> seq = {0, 0, 1};

  return make_pair(tree, seq);
}
/*
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false
Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.
*/
pair<Node *, vector<int>> testFixture3()
{
  auto *tree = new Node(0);
  /* left */
  tree->left = new Node(1);
  tree->left->left = new Node(0);
  tree->left->left->right = new Node(1);
  tree->left->right = new Node(1);
  tree->left->right->left = new Node(0);
  tree->left->right->right = new Node(0);

  /* right */
  tree->right = new Node(0);
  tree->right->left = new Node(0);

  vector<int> seq = {0, 1, 1};

  return make_pair(tree, seq);
}

void test1()
{
  Solution sol;
  auto fixture = testFixture1();
  cout << "Test 1 - expect to see 1" << endl;
  cout << "result: " << sol.validSeq(fixture.first, fixture.second) << endl;
}

void test2()
{
  Solution sol;
  auto fixture = testFixture2();
  cout << "Test 2 - expect to see 0" << endl;
  cout << "result: " << sol.validSeq(fixture.first, fixture.second) << endl;
}

void test3()
{
  Solution sol;
  auto fixture = testFixture3();
  cout << "Test 3 - expect to see 0" << endl;
  cout << "result: " << sol.validSeq(fixture.first, fixture.second) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}