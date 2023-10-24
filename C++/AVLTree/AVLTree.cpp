#ifndef __PROGTEST__
#include <cassert>
#include <iostream>
#include <memory>
#include <limits>
#include <optional>
#include <algorithm>
#include <bitset>
#include <list>
#include <array>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <random>

#endif

// TODO implement
template <typename Product>
struct Bestsellers
{
  class Node
  {
  public:
    size_t amount;
    Node *left;
    Node *right;
    Product p;
    size_t height;     // for rotations
    size_t allNodesBelow; // for rank calculation
    size_t higherAmounts;
    size_t lowerAmounts;

    Node(size_t amount, const Product &p)
    {
      this->amount = amount;
      this->left = NULL;
      this->right = NULL;
      this->height = 1;
      this->p = p;
      this->allNodesBelow = 0;
      this->higherAmounts = 0;
      this->lowerAmounts = 0;
    }
  };

  class AVLTree
  {
  public:
    Node *root = NULL;

    void ClearTree(Node *node)
    {
      if (node != NULL)
      {
        ClearTree(node->left);
        ClearTree(node->right);
        delete node;
      }
    }
    
    ~AVLTree()
    {
      ClearTree(root);
    }

    size_t height(Node *node) const// returns nodes height
    {
      if (node == NULL) // nodes parent is a leaf
      {
        return 0;
      }
      return node->height;
    }

    int nodeBalance(Node *node) const
    {
      if (node == NULL)
      {
        return 0;
      }
      return height(node->left) - height(node->right);
    }

    void heightCalc(Node *node)
    {
      if (node == NULL)
      {
        return;
      }
      
      if (height(node->left) > height(node->right))
      {
        node->height = height(node->left) + 1;
      }
      else
      {
        node->height = height(node->right) + 1;
      }
    }

    Node *rotateRight(Node *parent)
    {
      Node *newParent = parent->left;
      Node *tmp = newParent->right;
      newParent->right = parent;
      parent->left = tmp;
      heightCalc(parent);
      heightCalc(newParent);

      if(tmp != NULL)
      {
        parent->allNodesBelow += (tmp->allNodesBelow + 1) - (newParent->allNodesBelow + 1);
        newParent->allNodesBelow += (parent->allNodesBelow + 1) - (tmp->allNodesBelow + 1);

        if(parent->right != NULL)
        {
          parent->higherAmounts = parent->right->amount + parent->right->higherAmounts + parent->right->lowerAmounts;
        }
        else
        {
          parent->higherAmounts = 0;
        }
        if(parent->left != NULL)
        {
          parent->lowerAmounts = parent->left->amount + parent->left->higherAmounts + parent->left->lowerAmounts;
        }
        else
        {
          parent->lowerAmounts = 0;
        }
        if(newParent->right != NULL)
        {
          newParent->higherAmounts = newParent->right->amount + newParent->right->higherAmounts + newParent->right->lowerAmounts;
        }
        else
        {
          newParent->higherAmounts = 0;
        }
        if(newParent->left != NULL)
        {
          newParent->lowerAmounts = newParent->left->amount + newParent->left->higherAmounts + newParent->left->lowerAmounts;
        }
        else
        {
          newParent->lowerAmounts = 0;
        }
        if(tmp->right != NULL)
        {
          tmp->higherAmounts = tmp->right->amount + tmp->right->higherAmounts + tmp->right->lowerAmounts;
        }
        else
        {
          tmp->higherAmounts = 0;
        }
        if(tmp->left != NULL)
        {
          tmp->lowerAmounts = tmp->left->amount + tmp->left->higherAmounts + tmp->left->lowerAmounts;
        }
        else
        {
          tmp->lowerAmounts = 0;
        }
      }
      else
      {
        parent->allNodesBelow -= (newParent->allNodesBelow + 1);
        newParent->allNodesBelow += (parent->allNodesBelow + 1); 

        if(parent->right != NULL)
        {
          parent->higherAmounts = parent->right->amount + parent->right->higherAmounts + parent->right->lowerAmounts;
        }
        else
        {
          parent->higherAmounts = 0;
        }
        if(parent->left != NULL)
        {
          parent->lowerAmounts = parent->left->amount + parent->left->higherAmounts + parent->left->lowerAmounts;
        }
        else
        {
          parent->lowerAmounts = 0;
        }
        if(newParent->right != NULL)
        {
          newParent->higherAmounts = newParent->right->amount + newParent->right->higherAmounts + newParent->right->lowerAmounts;
        }
        else
        {
          newParent->higherAmounts = 0;
        }
        if(newParent->left != NULL)
        {
          newParent->lowerAmounts = newParent->left->amount + newParent->left->higherAmounts + newParent->left->lowerAmounts;
        }
        else
        {
          newParent->lowerAmounts = 0;
        }
        
      }
      return newParent;
    }

    Node *rotateLeft(Node *parent)
    {
      Node *newParent = parent->right;
      Node *tmp = newParent->left;
      newParent->left = parent;
      parent->right = tmp;
      heightCalc(parent);
      heightCalc(newParent);

      if(tmp != NULL)
      {
        parent->allNodesBelow += (tmp->allNodesBelow + 1) - (newParent->allNodesBelow + 1);
        newParent->allNodesBelow += (parent->allNodesBelow + 1) - (tmp->allNodesBelow + 1);

        if(parent->right != NULL)
        {
          parent->higherAmounts = parent->right->amount + parent->right->higherAmounts + parent->right->lowerAmounts;
        }
        else
        {
          parent->higherAmounts = 0;
        }
        if(parent->left != NULL)
        {
          parent->lowerAmounts = parent->left->amount + parent->left->higherAmounts + parent->left->lowerAmounts;
        }
        else
        {
          parent->lowerAmounts = 0;
        }
        if(newParent->right != NULL)
        {
          newParent->higherAmounts = newParent->right->amount + newParent->right->higherAmounts + newParent->right->lowerAmounts;
        }
        else
        {
          newParent->higherAmounts = 0;
        }
        if(newParent->left != NULL)
        {
          newParent->lowerAmounts = newParent->left->amount + newParent->left->higherAmounts + newParent->left->lowerAmounts;
        }
        else
        {
          newParent->lowerAmounts = 0;
        }
                if(tmp->right != NULL)
        {
          tmp->higherAmounts = tmp->right->amount + tmp->right->higherAmounts + tmp->right->lowerAmounts;
        }
        else
        {
          tmp->higherAmounts = 0;
        }
        if(tmp->left != NULL)
        {
          tmp->lowerAmounts = tmp->left->amount + tmp->left->higherAmounts + tmp->left->lowerAmounts;
        }
        else
        {
          tmp->lowerAmounts = 0;
        }
      }
      else
      {
        parent->allNodesBelow -= (newParent->allNodesBelow + 1);
        newParent->allNodesBelow += (parent->allNodesBelow + 1);

        if(parent->right != NULL)
        {
          parent->higherAmounts = parent->right->amount + parent->right->higherAmounts + parent->right->lowerAmounts;
        }
        else
        {
          parent->higherAmounts = 0;
        }
        if(parent->left != NULL)
        {
          parent->lowerAmounts = parent->left->amount + parent->left->higherAmounts + parent->left->lowerAmounts;
        }
        else
        {
          parent->lowerAmounts = 0;
        }
        if(newParent->right != NULL)
        {
          newParent->higherAmounts = newParent->right->amount + newParent->right->higherAmounts + newParent->right->lowerAmounts;
        }
        else
        {
          newParent->higherAmounts = 0;
        }
        if(newParent->left != NULL)
        {
          newParent->lowerAmounts = newParent->left->amount + newParent->left->higherAmounts + newParent->left->lowerAmounts;
        }
        else
        {
          newParent->lowerAmounts = 0;
        }
      }
      return newParent;
    }

    Node *insertNode(Node *node, size_t amount, const Product &p)
    {
      /*insert to the correct pos*/
      if (node == NULL)
      {
        Node *first = new Node(amount, p);
        return first;
      }
      if (amount < node->amount)
      {
        node->left = insertNode(node->left, amount, p);
        node->lowerAmounts += amount;
      }
      else if (amount > node->amount)
      {
        node->right = insertNode(node->right, amount, p);
        node->higherAmounts += amount;
      }
      else if (amount == node->amount && (p > node->p))
      {
        node->right = insertNode(node->right, amount, p);
        node->higherAmounts += amount;
      }
      else if (amount == node->amount && (p < node->p))
      {
        node->left = insertNode(node->left, amount, p);
        node->lowerAmounts += amount;
      }

      node->allNodesBelow += 1;
      heightCalc(node);

      // rotate if needed
      if (nodeBalance(node) > 1)
      {
        if (amount > node->left->amount)
        {
          node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
      }

      if (nodeBalance(node) < -1)
      {
        if (amount < node->right->amount)
        {
          node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
      }
      return node;
    }

    Node *deleteNode(Node *node, size_t amount, const Product &p) // finds the amount in tree, deletes it and connects subtrees. Rebalances if needed
    {
      if (node == NULL)
      {
        return node;
      }
      if (amount < node->amount)
      {
        node->lowerAmounts -= amount;
        node->left = deleteNode(node->left, amount, p);
        node->allNodesBelow -= 1;
      }
      else if (amount > node->amount)
      {
        node->higherAmounts -= amount;
        node->right = deleteNode(node->right, amount, p);
        node->allNodesBelow -= 1;
      }
      else if (amount == node->amount && (p < node->p))
      {
        node->lowerAmounts -= amount;
        node->left = deleteNode(node->left, amount, p);
        node->allNodesBelow -= 1;
      }
      else if (amount == node->amount && (p > node->p))
      {
        node->higherAmounts -= amount;
        node->right = deleteNode(node->right, amount, p);
        node->allNodesBelow -= 1;
      }
      else // found it, ready to delete
      {
        if (node->left == NULL && node->right == NULL) // no leafs
        {
          Node *tmp = node;
          node = NULL;
          delete tmp;
        }
        else if (node->left == NULL) // has right leaf (right leaf becomes the parent node)
        {
          Node *tmp = node->right;
          *node = *tmp;
          delete tmp;
        }
        else if (node->right == NULL) // has left leaf (left leaf becomes the parent node)
        {
          Node *tmp = node->left;
          *node = *tmp;
          delete tmp;
        }
        else // has 2 leafs
        {
          Node *tmp = node->right;
          while (tmp->left != NULL)
          {
            tmp = tmp->left;
          }

          node->amount = tmp->amount;
          node->p = tmp->p;

          node->higherAmounts -= amount;
          node->right = deleteNode(node->right, tmp->amount, tmp->p);
          node->allNodesBelow -= 1;
        }
      }
      
      if (node == NULL)
      {
        return node;
      }
              if(node->right != NULL)
        {
          node->higherAmounts = node->right->amount + node->right->higherAmounts + node->right->lowerAmounts;
        }
        else
        {
          node->higherAmounts = 0;
        }
        if(node->left != NULL)
        {
          node->lowerAmounts = node->left->amount + node->left->higherAmounts + node->left->lowerAmounts;
        }
        else
        {
          node->lowerAmounts = 0;
        }

      heightCalc(node);

      // rotate if needed
      if (nodeBalance(node) > 1)
      {
        if (nodeBalance(node->left) < 0)
        {
          node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
      }

      if (nodeBalance(node) < -1)
      {
        if (nodeBalance(node->right) > 0)
        {
          node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
      }
      return node;
    }


    size_t getRank(Node *node, size_t amount, const Product &p) const
    {
      size_t res = 1;
      while (node != NULL)
      {
          if(node->right != NULL)
          {
            if (node->amount > amount) 
            {
              res += node->right->allNodesBelow + 2;
              node = node->left;
            } 
            else if (node->amount < amount)
            {
              node = node->right;
            }
            else if (node->amount == amount && node->p > p) 
            {
              res += node->right->allNodesBelow + 2;
              node = node->left;
            } 
            else if (node->amount == amount && node->p < p)
            {
              node = node->right;
            }
            else 
            {
              res += node->right->allNodesBelow + 1;
              break;
            }
          }
          else
          {
            if (node->amount > amount) 
            {
              res +=  1;
              node = node->left;
            } 
            else if (node->amount < amount)
            {
              node = node->right;
            }
            else if (node->amount == amount && node->p > p) 
            {
              res +=  1;
              node = node->left;
            } 
            else if (node->amount == amount && node->p < p)
            {
              node = node->right;
            }
            else 
            {
              break;
            }
          }
      }
      return res;
    }

    Node *nodeAtRank(Node *node, size_t rank) const
    {
      Node *tmp = node;
      Node *res = NULL;
      size_t x = rank;

      while (tmp != NULL)
      {
        size_t val = 0;
        if(tmp->right != NULL)
        {
          val = tmp->right->allNodesBelow;
          
          if(tmp->right == NULL && tmp->left == NULL)
          {
            res = tmp;
            break;
          }
          if(val + 2 == x)
          {
            res = tmp;
            break;
          }
          else if(val + 2 > x)
          {
            if(tmp->right == NULL)
            {
              res = tmp->left;
              break;
            }
            tmp = tmp->right;
          }
          else
          {
            x -= val + 2;

            tmp = tmp->left;
          }
        }
        else
        {
          if(tmp->left == NULL)
          {
            res = tmp;
            break;
          }
          if(val + 1 == x)
          {
            res = tmp;
            break;
          }
          else if(val + 1 > x)
          {
            if(tmp->right == NULL)
            {
              res = tmp->left;
              break;
            }
            tmp = tmp->right;
          }
          else
          {
            x -= val + 1;

            tmp = tmp->left;
          }
        }
      }
      return res;
    }
    size_t sumFrom(Node *node, size_t rank) const
    {
      Node *tmp = node;
      size_t res = 0;
      size_t x = rank;

      while (true)
      {
        size_t val = 0;
        if(tmp->right != NULL)
        {
          val = tmp->right->allNodesBelow;
          
          if(tmp->right == NULL && tmp->left == NULL)
          {
            res += tmp->higherAmounts + tmp->amount;
            break;
          }
          if(val + 2 == x)
          {
            res += tmp->higherAmounts  + tmp->amount;
            break;
          }
          else if(val + 2 > x)
          {
            tmp = tmp->right;
          }
          else
          {
            x -= val + 2;
            res += tmp->higherAmounts + tmp->amount;
            tmp = tmp->left;
          }
        }
        else
        {
          if(tmp->left == NULL)
          {
            res += tmp->higherAmounts + tmp->amount;
            break;
          }
          if(val + 1 == x)
          {
            res += tmp->higherAmounts + tmp->amount;
            break;
          }
          else if(val + 1 > x)
          {
            tmp = tmp->right;
          }
          else
          {
            x -= val + 1;
            res += tmp->higherAmounts  + tmp->amount;
            tmp = tmp->left;
          }
        }
      }
      return res;
    }
  };

  std::unordered_map<Product, size_t> ranks;
  AVLTree tree;

  // The total number of tracked products
  size_t products() const
  {
    return ranks.size();
  }

  void sell(const Product &p, size_t amount)
  {
    if (ranks.find(p) != ranks.end())
    {
      tree.root = tree.deleteNode(tree.root, ranks[p], p);
      ranks[p] += amount;
      tree.root = tree.insertNode(tree.root, ranks[p], p);
    }
    else
    {
      ranks.insert(std::make_pair(p, amount));
      tree.root = tree.insertNode(tree.root, amount, p);
    }
  }

  // The most sold product has rank 1
  size_t rank(const Product &p) const
  {
    if (ranks.find(p) == ranks.end())
    {
      throw std::out_of_range("out of range2");
    }
    else
    {
      return tree.getRank(tree.root, ranks.at(p), p);
    }
  }

  const Product &product(size_t rank) const
  {
    if (products() < rank || rank < 1)
    {
      throw std::out_of_range("out of range3");
    }
    else
    {
      return tree.nodeAtRank(tree.root, rank)->p;
    }
  }

  // How many copies of product with given rank were sold
  size_t sold(size_t rank) const
  {
    if (products() < rank || rank < 1)
    {
      throw std::out_of_range("out of range4");
    }
    else
    {
      return tree.nodeAtRank(tree.root, rank)->amount;
    }
  }

  // The same but sum over interval of products (including from and to)
  // It must hold: sold(x) == sold(x, x)
  size_t sold(size_t from, size_t to) const
  {
    if (products() < from || from < 1 || products() < to || to < 1 || from > to)
    {
      throw std::out_of_range("out of range5");
    }
    else
    {
        return tree.sumFrom(tree.root, to) - tree.sumFrom(tree.root, from) + tree.nodeAtRank(tree.root, from)->amount;
    }
  }

  // Bonus only, ignore if you are not interested in bonus
  // The smallest (resp. largest) rank with sold(rank) == sold(r)
  size_t first_same(size_t r) const { return 0; }
  size_t last_same(size_t r) const { return 0; }
};

#ifndef __PROGTEST__

void test1() {
  Bestsellers<std::string> T;
  T.sell("coke", 32);
  T.sell("bread", 1);
  assert(T.products() == 2);
  T.sell("ham", 2);
  T.sell("mushrooms", 12);

  assert(T.products() == 4);
  assert(T.rank("ham") == 3);
  assert(T.rank("coke") == 1);
  assert(T.sold(1, 3) == 46);
  assert(T.product(2) == "mushrooms");

  T.sell("ham", 11);
  assert(T.products() == 4);
  assert(T.product(2) == "ham");
  assert(T.sold(2) == 13);
  assert(T.sold(2, 2) == 13);
  assert(T.sold(1, 2) == 45);
}

void test2() {
# define CATCH(expr) \
  try { expr; assert(0); } catch (const std::out_of_range&) { assert(1); };

  Bestsellers<std::string> T;
  T.sell("coke", 32);
  T.sell("bread", 1);

  CATCH(T.rank("ham"));
  CATCH(T.product(3));
  CATCH(T.sold(0));
  CATCH(T.sold(9));
  CATCH(T.sold(0, 1));
  CATCH(T.sold(3, 2));
  CATCH(T.sold(1, 9));

#undef CATCH
}

int main() {
  test1();
  test2();
}

#endif


