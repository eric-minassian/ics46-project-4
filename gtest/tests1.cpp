#include "gtest/gtest.h"
#include "LevelBalancedTree.hpp"
#include <string>
#include <sstream>
#include <vector>

namespace{


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


TEST(Required, FindTheRoot)
{
	LevelBalancedTree<int, std::string> tree;
	tree.insert(5, "foo");

	EXPECT_TRUE( tree.contains(5) );
}

TEST(Required, FindOneHop)
{
	LevelBalancedTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(10, "bar");

	EXPECT_TRUE( tree.contains(10) );
}

TEST(Required, FindTwoHops)
{
	LevelBalancedTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");

	EXPECT_TRUE( tree.contains(12) );
}



TEST(Required, CanAddAFew)
{
	LevelBalancedTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	EXPECT_EQ( tree.size(), 5 );
}

TEST(Required, DoAPreOrder)
{
	LevelBalancedTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	auto trav = tree.postOrder();
	std::vector<int> expected = {3, 10, 5};
	EXPECT_EQ(trav, expected);

}


TEST(Required, RemoveDoesARemove)
{
	LevelBalancedTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	EXPECT_TRUE( tree.contains( 3 ) );
	tree.remove(3);
	EXPECT_FALSE( tree.contains( 3 ) );
	EXPECT_TRUE( tree.contains( 5 ) );
}


TEST(PostCheckPoint, InOrderTraversal)
{
	LevelBalancedTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	std::vector<int> trav = tree.inOrder();
	std::vector<int> expected = {3, 5, 10, 12, 15};
	EXPECT_EQ( trav, expected );
}


}