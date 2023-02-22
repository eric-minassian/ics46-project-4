#include "LevelBalancedTree.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <string>
#include <vector>

namespace {

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.

// None of the "required" tests require you to have
// Level-Balanced functionality.
// Implementing your tree as a plain binary search
// tree is more than enough to pass these tests.

// Of course, you are expected to implement that functionality
// for the full project.

// BE SURE TO FULLY TEST YOUR CODE.
// This means making sure your templating is not hard-coding for
// a specific type, that every function is called somewhere in
// your test cases, etc.

TEST(Required, FindTheRoot) {
  LevelBalancedTree<int, std::string> tree;
  tree.insert(5, "foo");

  EXPECT_TRUE(tree.contains(5));
}

TEST(Required, FindOneHop) {
  LevelBalancedTree<int, std::string> tree;
  tree.insert(5, "foo");
  tree.insert(10, "bar");

  EXPECT_TRUE(tree.contains(10));
}

TEST(Required, FindTwoHops) {
  LevelBalancedTree<int, std::string> tree;
  tree.insert(5, "foo");
  tree.insert(3, "sna");
  tree.insert(10, "bar");
  tree.insert(12, "twelve");

  EXPECT_TRUE(tree.contains(12));
}

TEST(Required, CanAddAFew) {
  LevelBalancedTree<int, std::string> tree;
  tree.insert(5, "foo");
  tree.insert(3, "sna");
  tree.insert(10, "bar");
  tree.insert(12, "twelve");
  tree.insert(15, "fifteen");

  EXPECT_EQ(tree.size(), 5);
}

TEST(Required, DoAPreOrder) {
  LevelBalancedTree<int, std::string> tree;
  tree.insert(5, "foo");
  tree.insert(3, "sna");
  tree.insert(10, "bar");
  auto trav = tree.postOrder();
  std::vector<int> expected = {3, 10, 5};
  EXPECT_EQ(trav, expected);
}

TEST(Required, RemoveDoesARemove) {
  LevelBalancedTree<int, std::string> tree;
  tree.insert(5, "foo");
  tree.insert(3, "sna");
  EXPECT_TRUE(tree.contains(3));
  tree.remove(3);
  EXPECT_FALSE(tree.contains(3));
  EXPECT_TRUE(tree.contains(5));
}

TEST(PostCheckPoint, InOrderTraversal) {
  LevelBalancedTree<int, std::string> tree;
  tree.insert(5, "foo");
  tree.insert(3, "sna");
  tree.insert(10, "bar");
  tree.insert(12, "twelve");
  tree.insert(15, "fifteen");

  std::vector<int> trav = tree.inOrder();
  std::vector<int> expected = {3, 5, 10, 12, 15};
  EXPECT_EQ(trav, expected);
}

// Additional Tests

TEST(Additional, ClassExample1) {
  LevelBalancedTree<int, int> tree;
  tree.insert(20, 20);
  tree.insert(19, 19);
  tree.insert(18, 18);

  std::vector<int> inOrderTrav1 = tree.inOrder();
  std::vector<int> expectedInOrder1 = {18, 19, 20};
  EXPECT_EQ(inOrderTrav1, expectedInOrder1);

  std::vector<int> postOrderTrav1 = tree.postOrder();
  std::vector<int> expectedPostOrder1 = {18, 20, 19};
  EXPECT_EQ(postOrderTrav1, expectedPostOrder1);

  tree.insert(12, 12);
  tree.insert(9, 9);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {9, 12, 18, 19, 20};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {9, 18, 12, 20, 19};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);

  tree.insert(17, 17);

  std::vector<int> inOrderTrav3 = tree.inOrder();
  std::vector<int> expectedInOrder3 = {9, 12, 17, 18, 19, 20};
  EXPECT_EQ(inOrderTrav3, expectedInOrder3);

  std::vector<int> postOrderTrav3 = tree.postOrder();
  std::vector<int> expectedPostOrder3 = {9, 17, 12, 20, 19, 18};
  EXPECT_EQ(postOrderTrav3, expectedPostOrder3);

  tree.insert(7, 7);

  std::vector<int> inOrderTrav4 = tree.inOrder();
  std::vector<int> expectedInOrder4 = {7, 9, 12, 17, 18, 19, 20};
  EXPECT_EQ(inOrderTrav4, expectedInOrder4);

  std::vector<int> postOrderTrav4 = tree.postOrder();
  std::vector<int> expectedPostOrder4 = {7, 9, 17, 12, 20, 19, 18};
  EXPECT_EQ(postOrderTrav4, expectedPostOrder4);

  tree.insert(5, 5);

  std::vector<int> inOrderTrav5 = tree.inOrder();
  std::vector<int> expectedInOrder5 = {5, 7, 9, 12, 17, 18, 19, 20};
  EXPECT_EQ(inOrderTrav5, expectedInOrder5);

  std::vector<int> postOrderTrav5 = tree.postOrder();
  std::vector<int> expectedPostOrder5 = {5, 9, 7, 17, 12, 20, 19, 18};
  EXPECT_EQ(postOrderTrav5, expectedPostOrder5);

  tree.insert(13, 13);

  std::vector<int> inOrderTrav6 = tree.inOrder();
  std::vector<int> expectedInOrder6 = {5, 7, 9, 12, 13, 17, 18, 19, 20};
  EXPECT_EQ(inOrderTrav6, expectedInOrder6);

  std::vector<int> postOrderTrav6 = tree.postOrder();
  std::vector<int> expectedPostOrder6 = {5, 9, 7, 13, 17, 12, 20, 19, 18};
  EXPECT_EQ(postOrderTrav6, expectedPostOrder6);

  tree.insert(15, 15);

  std::vector<int> inOrderTrav7 = tree.inOrder();
  std::vector<int> expectedInOrder7 = {5, 7, 9, 12, 13, 15, 17, 18, 19, 20};
  EXPECT_EQ(inOrderTrav7, expectedInOrder7);

  std::vector<int> postOrderTrav7 = tree.postOrder();
  std::vector<int> expectedPostOrder7 = {5, 9, 7, 13, 17, 15, 12, 20, 19, 18};
  EXPECT_EQ(postOrderTrav7, expectedPostOrder7);

  tree.insert(6, 6);

  std::vector<int> inOrderTrav8 = tree.inOrder();
  std::vector<int> expectedInOrder8 = {5, 6, 7, 9, 12, 13, 15, 17, 18, 19, 20};
  EXPECT_EQ(inOrderTrav8, expectedInOrder8);

  std::vector<int> postOrderTrav8 = tree.postOrder();
  std::vector<int> expectedPostOrder8 = {6,  5,  9,  7,  13, 17,
                                         15, 20, 19, 18, 12};
  EXPECT_EQ(postOrderTrav8, expectedPostOrder8);

  tree.insert(16, 16);

  std::vector<int> inOrderTrav9 = tree.inOrder();
  std::vector<int> expectedInOrder9 = {5,  6,  7,  9,  12, 13,
                                       15, 16, 17, 18, 19, 20};
  EXPECT_EQ(inOrderTrav9, expectedInOrder9);

  std::vector<int> postOrderTrav9 = tree.postOrder();
  std::vector<int> expectedPostOrder9 = {6,  5,  9,  7,  13, 16,
                                         17, 15, 20, 19, 18, 12};
  EXPECT_EQ(postOrderTrav9, expectedPostOrder9);

  tree.insert(14, 14);

  std::vector<int> inOrderTrav = tree.inOrder();
  std::vector<int> expectedInOrder = {5,  6,  7,  9,  12, 13, 14,
                                      15, 16, 17, 18, 19, 20};

  EXPECT_EQ(inOrderTrav, expectedInOrder);

  std::vector<int> postOrderTrav = tree.postOrder();
  std::vector<int> expectedPostOrder = {6,  5,  9,  7,  14, 13, 16,
                                        17, 15, 20, 19, 18, 12};

  EXPECT_EQ(postOrderTrav, expectedPostOrder);

  std::vector<int> preOrderTrav = tree.preOrder();
  std::vector<int> expectedPreOrder = {12, 7,  5,  6,  9,  18, 15,
                                       13, 14, 17, 16, 19, 20};

  EXPECT_EQ(preOrderTrav, expectedPreOrder);

  EXPECT_TRUE(tree.contains(5));
  EXPECT_TRUE(tree.contains(6));
  EXPECT_TRUE(tree.contains(7));
  EXPECT_TRUE(tree.contains(9));
  EXPECT_TRUE(tree.contains(12));
  EXPECT_TRUE(tree.contains(13));
  EXPECT_TRUE(tree.contains(14));
  EXPECT_TRUE(tree.contains(15));
  EXPECT_TRUE(tree.contains(16));
  EXPECT_TRUE(tree.contains(17));
  EXPECT_TRUE(tree.contains(18));
  EXPECT_TRUE(tree.contains(19));
  EXPECT_TRUE(tree.contains(20));

  EXPECT_FALSE(tree.contains(1));
  EXPECT_FALSE(tree.contains(2));
  EXPECT_FALSE(tree.contains(3));

  EXPECT_EQ(tree.size(), 13);
}

TEST(Additional, ClassExample2) {
  LevelBalancedTree<int, int> tree;
  tree.insert(10, 10);
  tree.insert(5, 5);
  tree.insert(15, 15);
  tree.insert(20, 20);
  tree.insert(2, 2);
  tree.insert(12, 12);
  tree.insert(11, 11);
  tree.insert(13, 13);

  std::vector<int> inOrderTrav = tree.inOrder();
  std::vector<int> expectedInOrder = {2, 5, 10, 11, 12, 13, 15, 20};
  EXPECT_EQ(inOrderTrav, expectedInOrder);

  std::vector<int> postOrderTrav = tree.postOrder();
  std::vector<int> expectedPostOrder = {2, 5, 11, 13, 12, 20, 15, 10};
  EXPECT_EQ(postOrderTrav, expectedPostOrder);

  std::vector<int> preOrderTrav = tree.preOrder();
  std::vector<int> expectedPreOrder = {10, 5, 2, 15, 12, 11, 13, 20};
  EXPECT_EQ(preOrderTrav, expectedPreOrder);

  EXPECT_TRUE(tree.contains(2));
  EXPECT_TRUE(tree.contains(5));
  EXPECT_TRUE(tree.contains(10));
  EXPECT_TRUE(tree.contains(11));

  EXPECT_FALSE(tree.contains(1));
  EXPECT_FALSE(tree.contains(3));

  EXPECT_EQ(tree.size(), 8);

  tree.remove(2);
  EXPECT_FALSE(tree.contains(2));

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {5, 10, 11, 12, 13, 15, 20};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {5, 11, 10, 13, 20, 15, 12};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);

  std::vector<int> preOrderTrav2 = tree.preOrder();
  std::vector<int> expectedPreOrder2 = {12, 10, 5, 11, 15, 13, 20};
  EXPECT_EQ(preOrderTrav2, expectedPreOrder2);

  EXPECT_EQ(tree.size(), 7);

  tree.remove(10);
  EXPECT_FALSE(tree.contains(10));

  std::vector<int> inOrderTrav3 = tree.inOrder();
  std::vector<int> expectedInOrder3 = {5, 11, 12, 13, 15, 20};
  EXPECT_EQ(inOrderTrav3, expectedInOrder3);

  std::vector<int> postOrderTrav3 = tree.postOrder();
  std::vector<int> expectedPostOrder3 = {5, 11, 13, 20, 15, 12};
  EXPECT_EQ(postOrderTrav3, expectedPostOrder3);

  std::vector<int> preOrderTrav3 = tree.preOrder();
  std::vector<int> expectedPreOrder3 = {12, 11, 5, 15, 13, 20};
  EXPECT_EQ(preOrderTrav3, expectedPreOrder3);

  tree.remove(11);
  EXPECT_FALSE(tree.contains(11));

  std::vector<int> inOrderTrav4 = tree.inOrder();
  std::vector<int> expectedInOrder4 = {5, 12, 13, 15, 20};
  EXPECT_EQ(inOrderTrav4, expectedInOrder4);

  std::vector<int> postOrderTrav4 = tree.postOrder();
  std::vector<int> expectedPostOrder4 = {5, 13, 20, 15, 12};
  EXPECT_EQ(postOrderTrav4, expectedPostOrder4);

  std::vector<int> preOrderTrav4 = tree.preOrder();
  std::vector<int> expectedPreOrder4 = {12, 5, 15, 13, 20};
  EXPECT_EQ(preOrderTrav4, expectedPreOrder4);

  EXPECT_EQ(tree.size(), 5);

  tree.remove(5);
  EXPECT_FALSE(tree.contains(5));

  std::vector<int> inOrderTrav5 = tree.inOrder();
  std::vector<int> expectedInOrder5 = {12, 13, 15, 20};
  EXPECT_EQ(inOrderTrav5, expectedInOrder5);

  std::vector<int> postOrderTrav5 = tree.postOrder();
  std::vector<int> expectedPostOrder5 = {13, 12, 20, 15};
  EXPECT_EQ(postOrderTrav5, expectedPostOrder5);
}

TEST(Additional, ClassExample3) {
  LevelBalancedTree<int, int> tree;
  tree.insert(44, 44);
  tree.insert(17, 17);
  tree.insert(78, 78);
  tree.insert(32, 32);
  tree.insert(50, 50);
  tree.insert(87, 87);
  tree.insert(48, 48);
  tree.insert(62, 62);

  tree.remove(87);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {17, 32, 44, 48, 50, 62, 78};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {32, 17, 48, 62, 78, 50, 44};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);
}

TEST(Additional, ClassExample4) {
  LevelBalancedTree<int, int> tree;
  tree.insert(44, 44);
  tree.insert(17, 17);
  tree.insert(78, 78);
  tree.insert(32, 32);
  tree.insert(50, 50);
  tree.insert(87, 87);
  tree.insert(48, 48);
  tree.insert(62, 62);

  tree.remove(50);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {17, 32, 44, 48, 62, 78, 87};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {32, 17, 48, 62, 87, 78, 44};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);
}

TEST(Additional, ClassExample5) {
  LevelBalancedTree<int, int> tree;
  tree.insert(44, 44);
  tree.insert(17, 17);
  tree.insert(78, 78);
  tree.insert(32, 32);
  tree.insert(50, 50);
  tree.insert(87, 87);
  tree.insert(48, 48);
  tree.insert(62, 62);

  tree.remove(62);
  tree.remove(87);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {17, 32, 44, 48, 50, 78};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {32, 17, 48, 78, 50, 44};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);
}

TEST(Additional, ClassExample6) {
  LevelBalancedTree<int, int> tree;
  tree.insert(44, 44);
  tree.insert(17, 17);
  tree.insert(78, 78);
  tree.insert(32, 32);
  tree.insert(50, 50);
  tree.insert(87, 87);
  tree.insert(48, 48);
  tree.insert(62, 62);

  tree.remove(48);
  tree.remove(87);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {17, 32, 44, 50, 62, 78};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {32, 17, 50, 78, 62, 44};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);
}

TEST(Additional, ClassExample7) {
  LevelBalancedTree<int, int> tree;
  tree.insert(44, 44);
  tree.insert(17, 17);
  tree.insert(78, 78);
  tree.insert(32, 32);
  tree.insert(50, 50);
  tree.insert(87, 87);
  tree.insert(48, 48);
  tree.insert(62, 62);

  tree.remove(48);
  tree.remove(62);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {17, 32, 44, 50, 78, 87};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {32, 17, 50, 87, 78, 44};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);

  tree.remove(87);

  std::vector<int> inOrderTrav3 = tree.inOrder();
  std::vector<int> expectedInOrder3 = {17, 32, 44, 50, 78};
  EXPECT_EQ(inOrderTrav3, expectedInOrder3);

  std::vector<int> postOrderTrav3 = tree.postOrder();
  std::vector<int> expectedPostOrder3 = {32, 17, 50, 78, 44};
  EXPECT_EQ(postOrderTrav3, expectedPostOrder3);

  tree.remove(50);

  std::vector<int> inOrderTrav4 = tree.inOrder();
  std::vector<int> expectedInOrder4 = {17, 32, 44, 78};
  EXPECT_EQ(inOrderTrav4, expectedInOrder4);

  std::vector<int> postOrderTrav4 = tree.postOrder();
  std::vector<int> expectedPostOrder4 = {32, 17, 78, 44};
  EXPECT_EQ(postOrderTrav4, expectedPostOrder4);

  tree.remove(44);

  std::vector<int> inOrderTrav5 = tree.inOrder();
  std::vector<int> expectedInOrder5 = {17, 32, 78};
  EXPECT_EQ(inOrderTrav5, expectedInOrder5);

  std::vector<int> postOrderTrav5 = tree.postOrder();
  std::vector<int> expectedPostOrder5 = {17, 78, 32};
  EXPECT_EQ(postOrderTrav5, expectedPostOrder5);
}

TEST(Additional, ClassExample8) {
  LevelBalancedTree<int, int> tree;
  tree.insert(5, 5);
  tree.insert(10, 10);
  tree.insert(15, 15);
  tree.insert(12, 12);
  tree.insert(18, 18);
  tree.insert(2, 2);
  tree.insert(20, 20);

  std::vector<int> inOrderTrav1 = tree.inOrder();
  std::vector<int> expectedInOrder1 = {2, 5, 10, 12, 15, 18, 20};
  EXPECT_EQ(inOrderTrav1, expectedInOrder1);

  std::vector<int> postOrderTrav1 = tree.postOrder();
  std::vector<int> expectedPostOrder1 = {2, 5, 12, 20, 18, 15, 10};
  EXPECT_EQ(postOrderTrav1, expectedPostOrder1);

  tree.remove(2);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {5, 10, 12, 15, 18, 20};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {5, 12, 10, 20, 18, 15};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);
}

TEST(Additional, ClassExample9) {
  LevelBalancedTree<int, int> tree;
  // 10, 2, 5, 15, 20, 11, 13, 12
  tree.insert(10, 10);
  tree.insert(2, 2);
  tree.insert(5, 5);
  tree.insert(15, 15);
  tree.insert(20, 20);
  tree.insert(11, 11);
  tree.insert(13, 13);
  tree.insert(12, 12);

  std::vector<int> inOrderTrav1 = tree.inOrder();
  std::vector<int> expectedInOrder1 = {2, 5, 10, 11, 12, 13, 15, 20};
  EXPECT_EQ(inOrderTrav1, expectedInOrder1);

  std::vector<int> postOrderTrav1 = tree.postOrder();
  std::vector<int> expectedPostOrder1 = {2, 5, 11, 13, 12, 20, 15, 10};
  EXPECT_EQ(postOrderTrav1, expectedPostOrder1);

  tree.remove(2);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {5, 10, 11, 12, 13, 15, 20};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {5, 11, 10, 13, 20, 15, 12};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);
}

TEST(Additional, ClassExample10) {
  LevelBalancedTree<int, int> tree;

  tree.insert(10, 10);
  tree.insert(5, 5);
  tree.insert(15, 15);
  tree.insert(2, 2);
  tree.insert(11, 11);
  tree.insert(20, 20);

  std::vector<int> inOrderTrav1 = tree.inOrder();
  std::vector<int> expectedInOrder1 = {2, 5, 10, 11, 15, 20};
  EXPECT_EQ(inOrderTrav1, expectedInOrder1);

  std::vector<int> postOrderTrav1 = tree.postOrder();
  std::vector<int> expectedPostOrder1 = {2, 5, 11, 20, 15, 10};
  EXPECT_EQ(postOrderTrav1, expectedPostOrder1);

  tree.remove(2);

  std::vector<int> inOrderTrav2 = tree.inOrder();
  std::vector<int> expectedInOrder2 = {5, 10, 11, 15, 20};
  EXPECT_EQ(inOrderTrav2, expectedInOrder2);

  std::vector<int> postOrderTrav2 = tree.postOrder();
  std::vector<int> expectedPostOrder2 = {5, 11, 20, 15, 10};
  EXPECT_EQ(postOrderTrav2, expectedPostOrder2);
}

TEST(Additional, Insert1) {
  LevelBalancedTree<int, int> tree;
  tree.insert(714, 714);
  tree.insert(874, 874);
  tree.insert(98, 98);
  tree.insert(887, 887);
  tree.insert(188, 188);
  tree.insert(435, 435);
  tree.insert(924, 924);
  tree.insert(452, 452);
  tree.insert(983, 983);
  tree.insert(134, 134);
  tree.insert(440, 440);
  tree.insert(311, 311);
  tree.insert(868, 868);
  tree.insert(657, 657);
  tree.insert(348, 348);
  tree.insert(31, 31);
  tree.insert(736, 736);
  tree.insert(782, 782);
  tree.insert(991, 991);
  tree.insert(801, 801);
  tree.insert(648, 648);
  tree.insert(763, 763);
  tree.insert(941, 941);
  tree.insert(972, 972);
  tree.insert(184, 184);
  tree.insert(448, 448);
  tree.insert(315, 315);
  tree.insert(354, 354);
  tree.insert(510, 510);
  tree.insert(676, 676);
  tree.insert(698, 698);
  tree.insert(580, 580);
}

TEST(Additional, Insert2) {
  LevelBalancedTree<int, std::string> tree;
  for (int i = 0; i < 100; i++) {
    tree.insert(i, std::to_string(i));
  }

  for (int i = 0; i < 100; i++) {
    EXPECT_TRUE(tree.contains(i));
  }

  std::vector<int> postOrderTrav = tree.postOrder();
  std::vector<int> ans = {
      0,  2,  1,  4,  6,  5,  3,  8,  10, 9,  12, 14, 13, 11, 7,  16, 18,
      17, 20, 22, 21, 19, 24, 26, 25, 28, 30, 29, 27, 23, 15, 32, 34, 33,
      36, 38, 37, 35, 40, 42, 41, 44, 46, 45, 43, 39, 48, 50, 49, 52, 54,
      53, 51, 56, 58, 57, 60, 62, 61, 59, 55, 47, 31, 64, 66, 65, 68, 70,
      69, 67, 72, 74, 73, 76, 78, 77, 75, 71, 80, 82, 81, 84, 86, 85, 83,
      88, 90, 89, 92, 94, 93, 91, 96, 99, 98, 97, 95, 87, 79, 63};

  EXPECT_EQ(postOrderTrav, ans);
}

TEST(Additional, Insert3) {
  LevelBalancedTree<int, int> tree;
  for (int i = 0; i < 30; i++) {
    tree.insert(i, i);
  }

  std::vector<int> postOrderTrav = tree.postOrder();
  std::vector<int> ans = {0,  2,  1,  4,  6,  5,  3,  8,  10, 9,
                          12, 14, 13, 11, 7,  16, 18, 17, 20, 22,
                          21, 19, 24, 26, 25, 29, 28, 27, 23, 15};

  EXPECT_EQ(postOrderTrav, ans);
}

TEST(Additional, ConstFind1) {
  LevelBalancedTree<int, int> tree;
  for (int i = 0; i < 30; i++) {
    tree.insert(i, i);
  }

  const LevelBalancedTree<int, int> &constTree = tree;
  for (int i = 0; i < 30; i++) {
    EXPECT_EQ(constTree.find(i), i);
  }
}

TEST(Additional, InsertStressTest) {
  LevelBalancedTree<int, int> tree;
  for (int i = 0; i < 100000; i++) {
    tree.insert(i, i);
  }

  for (int i = 0; i < 100000; i++) {
    EXPECT_TRUE(tree.contains(i));
  }

  for (int i = 0; i < 100000; i++) {
    EXPECT_EQ(tree.find(i), i);
  }

  EXPECT_EQ(tree.size(), 100000);

  for (int i = 0; i < 100000; i++) {
    tree.remove(i);
  }

  EXPECT_EQ(tree.size(), 0);
  EXPECT_TRUE(tree.isEmpty());

  for (int i = 0; i < 100000; i++) {
    EXPECT_FALSE(tree.contains(i));
  }

  for (int i = 0; i < 100000; i++) {
    tree.insert(i, i);
  }

  for (int i = 0; i < 100000; i++) {
    EXPECT_TRUE(tree.contains(i));
  }

  for (int i = 0; i < 100000; i++) {
    tree.remove(i);
  }

  EXPECT_EQ(tree.size(), 0);
  EXPECT_TRUE(tree.isEmpty());

  for (int i = 0; i < 100000; i++) {
    EXPECT_FALSE(tree.contains(i));
  }
}

} // namespace