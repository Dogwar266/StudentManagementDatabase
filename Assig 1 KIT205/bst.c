#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


BSTNodePtr find_bst_node(BSTNodePtr self, int n)
{
	if (self == NULL || (n == self->data)) {
		return self;
	}
	else if (n < self->data) {
		return find_bst_node(self->left, n);
	}
	else {
		return find_bst_node(self->right, n);
	}
}

BSTNodePtr find_bst(BST *self, int n) {
	return find_bst_node(self->root, n);
}

BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
	if (self == NULL) {
		self = malloc(sizeof *self);
		self->data = n;
		self->left = self->right = NULL;
		self->courses = new_list();
	}
	else if (n < self->data) {
		self->left = insert_bst_node(self->left, n);
	}
	else if (n > self->data) {
		self->right = insert_bst_node(self->right, n);
	}
	return self;
}

void insert_bst(BST *self, int n)
{
	self->root = insert_bst_node(self->root, n);
}


BSTNodePtr min_node(BSTNodePtr self)
{
	BSTNodePtr current = self;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

BSTNodePtr max_node(BSTNodePtr self) {
	BSTNodePtr current = self; 
	while (current->right != NULL) {
		current = current->right;
	}
	return current;
}

BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
	if (self != NULL) {
		if (n == self->data) {
			if (self->left != NULL && self->right != NULL) {
				BSTNodePtr successor = min_node(self->right);
				self->data = successor->data;
				self->right = delete_bst_node(self->right, self->data);
			}
			else {
				BSTNodePtr to_free = self;
				if (self->left) {
					self = self->left;
				}
				else {
					self = self->right;
				}
				free(to_free);
			}

		}
		else if (n < self->data) {
			self->left = delete_bst_node(self->left, n);
		}
		else {
			self->right = delete_bst_node(self->right, n);
		}
	}
	return self;
}

void delete_bst(BST *self, int n) {
	self->root = delete_bst_node(self->root, n);
}

BST new_bst() {
	BST temp;
	temp.root = NULL;
	return temp;
}