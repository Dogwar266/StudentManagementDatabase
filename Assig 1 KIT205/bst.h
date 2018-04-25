#pragma once
#include "stringlist.h"

typedef struct bstNode {
	long data;
	List courses; 
	struct bstNode *left;
	struct bstNode *right;
} *BSTNodePtr;

typedef struct bst {
	BSTNodePtr root;
} BST;

BSTNodePtr find_bst_node(BSTNodePtr self, int n);

BSTNodePtr find_bst(BST *self, int n);

void insert_bst(BST *self, int n);

BSTNodePtr insert_bst_node(BSTNodePtr self, int n);

BSTNodePtr min_node(BSTNodePtr self);

BSTNodePtr max_node(BSTNodePtr self);

BSTNodePtr delete_bst_node(BSTNodePtr self, int n);

void delete_bst(BST *self, int n);

BST new_bst(bstNode);

void print_pre_order_bst_node(BSTNodePtr self);

void print_pre_order_bst(BST *self);