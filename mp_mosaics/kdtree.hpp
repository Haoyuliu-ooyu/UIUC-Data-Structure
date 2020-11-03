/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if (first[curDim] < second[curDim]) {
      return true;
    } else if (first[curDim] > second[curDim]) {
      return false;
    }
    return (first<second);
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    int currentDis = 0;
    int potentialDis = 0;
    for (int i =0; i < Dim; i++) {
      currentDis += (target[i]-currentBest[i])*(target[i]-currentBest[i]);
      potentialDis += (target[i]-potential[i])*(target[i]-potential[i]);
    }
    if (currentDis < potentialDis) {
      return false;
    } else if (currentDis > potentialDis) {
      return true;
    }
    return potential<currentBest;
}

template <int Dim>
void KDTree<Dim>::quickSelect(vector<Point<Dim>>& list, int start, int end, int p, int dimension) {
    while (start != end) {
      Point<Dim> pivot = list[p];
      list[p] = list[end];
      list[end] = pivot;
      int temp = start;
      for (int i = start; i < end; i++) {
        if (smallerDimVal(list[i], pivot, dimension) || list[i]==pivot) {
          Point<Dim> tempPoint = list[temp];
          list[temp] = list[i];
          list[i] = tempPoint;
          temp++;
        }
      }
      Point<Dim> tempP = list[temp];
      list[temp] = list[end];
      list[end] = tempP;
      if (temp == p) {
        return;
      } else if (p > temp) {
        start = temp+1;
      } else {
        end = temp-1;
      }
    }
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::helper(vector<Point<Dim>>& list, int start, int end, int dimension) {
  if (start > end) {
    return NULL;
  } else if (start == end) {
    return new KDTreeNode(list[start]);
  }
  int p = (start+end)/2;
  int next_dimension = (dimension+1)%Dim;
  quickSelect(list, start, end, p, dimension);
  KDTreeNode* curr = new KDTreeNode(list[p]);
  curr->left = helper(list, start, (p-1), next_dimension);
  curr->right = helper(list, (p+1), end, next_dimension);
  return curr;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
    if (newPoints.size() == 0) {
      root = NULL;
    }
    size = newPoints.size();
    vector<Point<Dim>> points;
    points.assign(newPoints.begin(), newPoints.end());
    root = helper(points, 0, points.size()-1, 0);
}



template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
  size = other->size;
  copy(root, other->root);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if (this != NULL) {
    destroy(root);
    copy(root, rhs->root);
    size = rhs.size;
    return *this;
  }


  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    return findNearestNeighbor(query, root, 0);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query, typename KDTree<Dim>::KDTreeNode* curr, int dimension) const{
  if (curr->left == NULL && curr->right == NULL) {
    return curr->point;
  }
  int next_dimension = (dimension+1)%Dim;
  Point<Dim> currentBest = curr->point;
  Point<Dim> potentialBest = currentBest;
  bool flg = smallerDimVal(query, currentBest, dimension);
  if (flg) {
    if (curr->left == NULL) {
      potentialBest = findNearestNeighbor(query, curr->right, next_dimension);
    } else {
      potentialBest = findNearestNeighbor(query, curr->left, next_dimension);
    }
  } else {
    if (curr->right == NULL) {
      potentialBest = findNearestNeighbor(query, curr->right, next_dimension);
    } else {
      potentialBest = findNearestNeighbor(query, curr->right, next_dimension);
    }
  }
  if (shouldReplace(query, currentBest, potentialBest)) {
    currentBest = potentialBest;
  }
  int best = 0;
  for (int i = 0; i < Dim; i++) {
    best += (query[i]-currentBest[i])*(query[i]-currentBest[i]);
  }
  int radius = (query[dimension]-curr->point[dimension])*(query[dimension]-curr->point[dimension]);
  if (best >= radius) {
    if (!flg && curr->left != NULL) {
      potentialBest = findNearestNeighbor(query, curr->left, next_dimension);
    } else if (flg && curr->right != NULL) {
      potentialBest = findNearestNeighbor(query, curr->right, next_dimension);
    }
    if (shouldReplace(query, currentBest, potentialBest)) {
      currentBest = potentialBest;
    }
  }
  return currentBest;
}

template <int Dim>
void KDTree<Dim>::destroy(KDTreeNode* node) {
  if (node == NULL) {return;}
  if (node->left != NULL) {
    destroy(node->left);
  }
  if (node->right != NULL) {
    destroy(node->right);
  }
  delete node;
  node = NULL;
}

template <int Dim>
void KDTree<Dim>::copy(KDTreeNode* node, KDTreeNode* other) {
  node = new KDTreeNode();
  node->point = other->point;
  copy(node->left, other->left);
  copy(node->right, other->right);
}


