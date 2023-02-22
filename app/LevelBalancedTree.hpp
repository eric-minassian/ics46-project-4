#ifndef __PROJ_FOUR_LEVEL_BALANCED_TREE_HPP
#define __PROJ_FOUR_LEVEL_BALANCED_TREE_HPP

#include "runtimeexcept.hpp"
#include <cstddef>
#include <string>
#include <vector>

class ElementNotFoundException : public RuntimeException {
public:
  ElementNotFoundException(const std::string &err) : RuntimeException(err) {}
};

template <typename Key, typename Value> struct LBTreeNode {

  Key key;
  Value value;
  LBTreeNode *left;
  LBTreeNode *right;
  LBTreeNode *parent;
  unsigned level;

  LBTreeNode(const Key &k, const Value &v)
      : key(k), value(v), left(nullptr), right(nullptr), parent(nullptr),
        level(1) {}
};

template <typename Key, typename Value> class LevelBalancedTree {
private:
  // fill in private member data here
  // If you need to declare private functions, do so here too.
  LBTreeNode<Key, Value> *root;
  size_t treeSize;

  // Extra Methods
  void updateLevel(LBTreeNode<Key, Value> *node);
  void setChild(LBTreeNode<Key, Value> *parent, char whichChild,
                LBTreeNode<Key, Value> *child);
  void replaceChild(LBTreeNode<Key, Value> *parent,
                    LBTreeNode<Key, Value> *currentChild,
                    LBTreeNode<Key, Value> *child);
  unsigned getLevel(LBTreeNode<Key, Value> *node);
  void rotateLeft(LBTreeNode<Key, Value> *node);
  void rotateRight(LBTreeNode<Key, Value> *node);
  void rebalance(LBTreeNode<Key, Value> *node);

  void removeHelper(LBTreeNode<Key, Value> *node);

  void postOrderHelper(LBTreeNode<Key, Value> *node,
                       std::vector<Key> &result) const;
  void inOrderHelper(LBTreeNode<Key, Value> *node,
                     std::vector<Key> &result) const;
  void preOrderHelper(LBTreeNode<Key, Value> *node,
                      std::vector<Key> &result) const;

  void destructorHelper(LBTreeNode<Key, Value> *node);

public:
  LevelBalancedTree();

  // In general, a copy constructor and assignment operator
  // are good things to have.
  // For this quarter, I am not requiring these.
  //	LevelBalancedTree(const LevelBalancedTree & st);
  //	LevelBalancedTree & operator=(const LevelBalancedTree & st);

  // The destructor is required.
  ~LevelBalancedTree();

  // size() returns the number of distinct keys in the tree.
  size_t size() const noexcept;

  // isEmpty() returns true if and only if the tree has no values in it.
  bool isEmpty() const noexcept;

  // contains() returns true if and only if there
  //  is a (key, value) pair in the tree
  //	that has the given key as its key.
  bool contains(const Key &k) const noexcept;

  // find returns the value associated with the given key
  // If !contains(k), this will throw an ElementNotFoundException
  // There needs to be a version for const and non-const LevelBalancedTrees.
  Value &find(const Key &k);
  const Value &find(const Key &k) const;

  // Inserts the given key-value pair into
  // the tree and performs the balancing operation(s) if needed
  // operation, as described in lecture.
  // If the key already exists in the tree,
  // you may do as you please (no test cases in
  // the grading script will deal with this situation)
  void insert(const Key &k, const Value &v);

  // Deletes the given key from the tree
  // and performs the balancing operation(s) if needed.
  // If the key does not exist in the tree,
  // do not modify the tree.
  void remove(const Key &k);

  // The following three functions all return
  // the set of keys in the tree as a standard vector.
  // Each returns them in a different order.
  std::vector<Key> inOrder() const;
  std::vector<Key> preOrder() const;
  std::vector<Key> postOrder() const;
};

template <typename Key, typename Value>
LevelBalancedTree<Key, Value>::LevelBalancedTree()
    : root(nullptr), treeSize(0) {}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::destructorHelper(
    LBTreeNode<Key, Value> *node) {
  if (node == nullptr) {
    return;
  }
  destructorHelper(node->left);
  destructorHelper(node->right);
  delete node;
}

template <typename Key, typename Value>
LevelBalancedTree<Key, Value>::~LevelBalancedTree() {
  destructorHelper(root);
}

template <typename Key, typename Value>
size_t LevelBalancedTree<Key, Value>::size() const noexcept {
  return treeSize;
}

template <typename Key, typename Value>
bool LevelBalancedTree<Key, Value>::isEmpty() const noexcept {
  return treeSize == 0;
}

template <typename Key, typename Value>
bool LevelBalancedTree<Key, Value>::contains(const Key &k) const noexcept {
  try {
    find(k);
  } catch (ElementNotFoundException e) {
    return false;
  }
  return true;
}

template <typename Key, typename Value>
Value &LevelBalancedTree<Key, Value>::find(const Key &k) {
  LBTreeNode<Key, Value> *cur = root;
  while (cur != nullptr) {
    if (cur->key == k) {
      return cur->value;
    } else if (cur->key < k) {
      cur = cur->right;
    } else {
      cur = cur->left;
    }
  }
  throw ElementNotFoundException("Key not in tree");
}

template <typename Key, typename Value>
const Value &LevelBalancedTree<Key, Value>::find(const Key &k) const {
  LBTreeNode<Key, Value> *cur = root;
  while (cur != nullptr) {
    if (cur->key == k) {
      return cur->value;
    } else if (cur->key < k) {
      cur = cur->right;
    } else {
      cur = cur->left;
    }
  }
  throw ElementNotFoundException("Key not in tree");
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::updateLevel(LBTreeNode<Key, Value> *node) {
  if (node == nullptr) {
    return;
  }
  unsigned leftLevel = 0;
  unsigned rightLevel = 0;
  if (node->left != nullptr) {
    leftLevel = node->left->level;
  }
  if (node->right != nullptr) {
    rightLevel = node->right->level;
  }
  node->level = 1 + std::max(leftLevel, rightLevel);
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::setChild(LBTreeNode<Key, Value> *parent,
                                             char whichChild,
                                             LBTreeNode<Key, Value> *child) {
  if (whichChild == 'L') {
    parent->left = child;
  } else {
    parent->right = child;
  }
  if (child != nullptr) {
    child->parent = parent;
  }
  LevelBalancedTree<Key, Value>::updateLevel(parent);
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::replaceChild(
    LBTreeNode<Key, Value> *parent, LBTreeNode<Key, Value> *currentChild,
    LBTreeNode<Key, Value> *child) {
  if (parent->left == currentChild) {
    setChild(parent, 'L', child);
  } else {
    setChild(parent, 'R', child);
  }
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::rotateRight(LBTreeNode<Key, Value> *node) {
  LBTreeNode<Key, Value> *leftRightChild = node->left->right;
  if (node->parent != nullptr) {
    replaceChild(node->parent, node, node->left);
  } else {
    root = node->left;
    root->parent = nullptr;
  }
  setChild(node->left, 'R', node);
  setChild(node, 'L', leftRightChild);
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::rotateLeft(LBTreeNode<Key, Value> *node) {
  LBTreeNode<Key, Value> *rightLeftChild = node->right->left;
  if (node->parent != nullptr) {
    replaceChild(node->parent, node, node->right);
  } else {
    root = node->right;
    root->parent = nullptr;
  }
  setChild(node->right, 'L', node);
  setChild(node, 'R', rightLeftChild);
}

template <typename Key, typename Value>
unsigned LevelBalancedTree<Key, Value>::getLevel(LBTreeNode<Key, Value> *node) {
  if (node == nullptr) {
    return 0;
  }
  return node->level;
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::rebalance(LBTreeNode<Key, Value> *node) {
  if (node == nullptr) {
    return;
  }

  updateLevel(node);

  if (getLevel(node) - getLevel(node->left) > 2) {
    // Left Side is empty
    if (node->right && node->right->right &&
        getLevel(node->right) - getLevel(node->right->right) == 1) {
      rotateLeft(node);
    } else {
      rotateRight(node->right);
      rotateLeft(node);
    }
  } else if (getLevel(node) - getLevel(node->right) > 2) {
    // Right Side is empty
    if (node->left && node->left->left &&
        getLevel(node->left) - getLevel(node->left->left) == 1) {
      rotateRight(node);
    } else {
      rotateLeft(node->left);
      rotateRight(node);
    }
  }
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::insert(const Key &k, const Value &v) {
  LBTreeNode<Key, Value> *new_node = new LBTreeNode<Key, Value>(k, v);
  if (root == nullptr) {
    root = new_node;
    treeSize++;
    return;
  }

  LBTreeNode<Key, Value> *cur = root;
  while (cur != nullptr) {
    if (cur->key == k) {
      return;
    } else if (cur->key < k) {
      if (cur->right == nullptr) {
        cur->right = new_node;
        new_node->parent = cur;
        treeSize++;
        cur = nullptr;
      } else {
        cur = cur->right;
      }
    } else {
      if (cur->left == nullptr) {
        cur->left = new_node;
        new_node->parent = cur;
        treeSize++;
        cur = nullptr;
      } else {
        cur = cur->left;
      }
    }
  }

  new_node = new_node->parent;
  while (new_node != nullptr) {
    rebalance(new_node);
    new_node = new_node->parent;
  }
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::removeHelper(LBTreeNode<Key, Value> *node) {
  LBTreeNode<Key, Value> *parent = node->parent;

  if (node->left != nullptr && node->right != nullptr) {
    LBTreeNode<Key, Value> *successor = node->right;
    while (successor->left != nullptr) {
      successor = successor->left;
    }
    node->key = successor->key;
    node->value = successor->value;

    removeHelper(successor);
    return;
  } else if (node == root) {
    if (node->left != nullptr) {
      root = node->left;
      root->parent = nullptr;
    } else if (node->right != nullptr) {
      root = node->right;
      root->parent = nullptr;
    } else {
      root = nullptr;
    }
    delete node;
    treeSize--;
    return;
  } else if (node->left != nullptr) {
    replaceChild(parent, node, node->left);
    delete node;
    treeSize--;
  } else {
    replaceChild(parent, node, node->right);
    delete node;
    treeSize--;
  }

  while (parent != nullptr) {
    rebalance(parent);
    parent = parent->parent;
  }
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::remove(const Key &k) {
  LBTreeNode<Key, Value> *cur = root, *node = nullptr;
  while (cur != nullptr) {
    if (cur->key == k) {
      node = cur;
      cur = nullptr;
    } else if (cur->key < k) {
      cur = cur->right;
    } else {
      cur = cur->left;
    }
  }

  if (node == nullptr) {
    throw ElementNotFoundException("Key not in tree");
  }

  removeHelper(node);
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::inOrderHelper(
    LBTreeNode<Key, Value> *node, std::vector<Key> &result) const {
  if (node == nullptr) {
    return;
  }
  inOrderHelper(node->left, result);
  result.push_back(node->key);
  inOrderHelper(node->right, result);
}

template <typename Key, typename Value>
std::vector<Key> LevelBalancedTree<Key, Value>::inOrder() const {
  std::vector<Key> result;
  inOrderHelper(root, result);
  return result;
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::preOrderHelper(
    LBTreeNode<Key, Value> *node, std::vector<Key> &result) const {
  if (node == nullptr) {
    return;
  }
  result.push_back(node->key);
  preOrderHelper(node->left, result);
  preOrderHelper(node->right, result);
}

template <typename Key, typename Value>
std::vector<Key> LevelBalancedTree<Key, Value>::preOrder() const {
  std::vector<Key> result;
  preOrderHelper(root, result);
  return result;
}

template <typename Key, typename Value>
void LevelBalancedTree<Key, Value>::postOrderHelper(
    LBTreeNode<Key, Value> *node, std::vector<Key> &result) const {
  if (node == nullptr) {
    return;
  }
  postOrderHelper(node->left, result);
  postOrderHelper(node->right, result);
  result.push_back(node->key);
}

template <typename Key, typename Value>
std::vector<Key> LevelBalancedTree<Key, Value>::postOrder() const {
  std::vector<Key> result;
  postOrderHelper(root, result);
  return result;
}

#endif