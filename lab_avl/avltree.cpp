/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* y = t->right;
    t->right = y ->left;
    y->left = t;
    updateHeight(t);
    t = y;
    updateHeight(t);
    updateHeight(t->right);
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
    
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node* y = t->left;
    t->left = y->right;
    y->right = t;
    updateHeight(t);
    t = y;
    updateHeight(t);
    updateHeight(t->left);
    
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (subtree == NULL) {
        return;
    }
    if (std::abs(getBalance(subtree)) <= 1) {
        return;
    }
    if (getBalance(subtree) > 1) {
        if (getBalance(subtree->right) == 1) {
            rotateLeft(subtree);
        } else if (getBalance(subtree->right) == -1) {
            rotateRightLeft(subtree);
        }
    } else if (getBalance(subtree) < -1) {
        if (getBalance(subtree->left) == -1) {
            rotateRight(subtree);
        } else if (getBalance(subtree->left) == 1) {
            rotateLeftRight(subtree);
        }
    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
if (subtree == NULL) {
        subtree = new Node(key, value);
    } else if (subtree->key == key) {
        subtree->value = value;
    } else if (subtree->key > key) {
        insert(subtree -> left, key, value);
    } else if (subtree->key < key) {
        insert(subtree -> right, key, value);
    }
    rebalance(subtree);
    updateHeight(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;
    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* i = subtree->left;
            while (i->right != NULL) {
                i = i->right;
            }
            swap(i, subtree);
            remove(subtree->left, key);
        } else {
            /* one-child remove */
            // your code here
            if (subtree->left == NULL) {
                Node* temp = subtree->right;
                delete subtree;
                subtree = temp;
            } else {
                Node* temp = subtree->left;
                delete subtree;
                subtree = temp;
            }
        }
        // your code here
    }
    updateHeight(subtree);
    rebalance(subtree);
}

/**
*get height function
*/
template <class K, class V>
void AVLTree<K, V>::updateHeight(Node*& node) {
    if (node == NULL) {
        return;
    } else if (node->left == NULL && node->right == NULL) {
        node->height = 0;
    } else {
        node->height =  std::max(heightOrNeg1(node->left), heightOrNeg1(node->right)) + 1;
    }
}

template <class K, class V>
int AVLTree<K, V>::getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return heightOrNeg1(node->right) - heightOrNeg1(node->left);
}
