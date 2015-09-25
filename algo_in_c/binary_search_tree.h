// https://en.wikipedia.org/wiki/Binary_search_tree
// Copyright (c) 2015 Aaron Zhang
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <stdlib.h>
#include <stdint.h>
#include <exception>
#include <iostream>

namespace ds{
    template<typename KeyT, typename ValueT>
    class BinarySearchTree{
    private:
        struct TreeNode{
            KeyT key;
            ValueT value;
			TreeNode* parent;
			TreeNode* left;
            TreeNode* right;

            TreeNode(const KeyT key, const ValueT value,
                TreeNode * parent, TreeNode * left, TreeNode * right){
                this->key = key;
                this->value = value;
                this->parent = parent;
                this->left = left;
                this->right = right;
            }
        };

    private:
        TreeNode* root;
    private:
		BinarySearchTree(const BinarySearchTree&);
		BinarySearchTree& operator=(const BinarySearchTree&);
    public:
		BinarySearchTree() :root(NULL){};
		~BinarySearchTree(){
            Release(root);
        }

        TreeNode* Find(const KeyT& key){
            TreeNode * n = root;
            while (n != NULL && key != n->key){
                if (key < n->key)
                    n = n->left;
                else
                    n = n->right;
            }
            return n;
        }

        void Insert(const KeyT& key, const ValueT& value){
            TreeNode* n = root;
            TreeNode* y = NULL;
            while (n != NULL){
                y = n;
                if (key < n->key)
                    n = n->left;
                else
                    n = n->right;
            }

            TreeNode* z = new TreeNode(key, value, y, NULL, NULL);
            if (y == NULL)
                root = z;
            else if (key < y->key)
                y->left = z;
            else
                y->right = z;
        }

        bool Delete(const KeyT& key){
            TreeNode* z = Find(key);
            if (z == NULL) return false;
            if (z->left == NULL){
                Replace(z, z->right);
            }
            else if (z->right == NULL){
				Replace(z, z->left);
            }
            else{
                TreeNode* y = Min(z->right);
				Replace(y, y->right);
				Replace(z, y);
            }
            delete z;
            return true;
        }

        void Traverse(TreeNode* n, int indent){
            if (n == NULL) return;
			Traverse(n->left, indent + 1);
            for (int i = 0; i < indent; i++)
                printf("    ");
            std::cout << "[" << n->key << "," << n->value << "]" << std::endl;
			Traverse(n->right, indent + 1);
        }

        void Traverse(){
			Traverse(root, 0);
        }

    private:
        void Release(TreeNode* n){
            if (n == NULL) return;
            Release(n->left);
            Release(n->right);
            delete n;
        }

        void Replace(TreeNode* u, TreeNode* v){
            if (u->parent == NULL){
                root = v;
            }
            else if (u == u->parent->left){
                u->parent->left = v;
            }
            else {
                u->parent->right = v;
            }

            if (v != NULL){
                v->parent = u->parent;
            }

            // make sure v is not u's direct child to avoid
            // circular reference.
			if (u->left != NULL && u->left != v){
				v->left = u->left;
				v->left->parent = v;
			}
			if (u->right != NULL && u->right != v){
				v->right = u->right;
				v->right->parent = v;
			}
        }

        TreeNode* Min(TreeNode* x){
            while (x->left != NULL)
                x = x->left;
            return x;
        }
    };
}

#endif