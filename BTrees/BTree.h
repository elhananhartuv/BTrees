#pragma once
#include"BNode.h"

template <typename T>
class BTree
	//BTree with max degree M
{
	BNode<T>* root;
	void printSubTree(BNode<T>* t);
	void deleteSubTree(BNode<T>* t);
	void printBetween_(T x, T y, BNode<T>* node);//private dunction
	T* search_(BNode<T>* p, T x);
	void printByName_(BNode<T>* p, string name);
public:
	BTree() { root = NULL; } //build an empty tree
	~BTree() { deleteTree(); }
	void insert(T x);      //add a value to the tree
	void deleteVal(T x);
	void deleteTree() { deleteSubTree(root); }
	void printTree() { printSubTree(root); }
	void printBetween(T x, T y) { printBetween_(x, y, root); }//public funk that call to private function
	T* search(T x) { return search_(root, x); }
	void printByName(string name) { printByName_(root, name); }//function that prints all lendings of a name. The bonus
};

#include "BTree.h"

template <typename T>
T* BTree<T>::search_(BNode<T>* p, T x)
{
	for (int i = 0; i < p->nkeys; i++)
	{
		if (p->Key[i] == x)
			return p;
		if (p->key[i] > x)
		{
			return search_(p->son[i], x);
			break;
		}
	}
	if (p->key[p->nkeys - 1] < x)
		return search_(p->son[p->nkeys], x);
	return NULL;

	/*
		for (int i = 0; i < p->nkeys; i++)
		{
			if (p->Key[i] == x)
				return p;
			else
				for (int i = 0; i < p->nsons; i++)
					return search(p->Son[i], x);
		}
		return NULL;
		*/
}

template<typename T>
void BTree<T>::printByName_(BNode<T>* node, string name)
{
	if (node == NULL)
		return;
	for (int i = 0; i < node->nsons; ++i)
		if (node->Son[i])
			printByName_(node->Son[i], name);

	for (int i = 0; i < node->nkeys; i++)
	{
		if (node->Key[i].getName() == name)
			cout << node->Key[i] << " ";
	}
}

template <typename T>
void BTree<T>::deleteSubTree(BNode<T>* t)
{
	if (t == NULL)
		return;
	for (int i = 0; i < t->nsons; i++)
		deleteSubTree(t->Son[i]);

	delete t;
}


template <typename T>
void BTree<T>::printSubTree(BNode<T>* t)
{
	if (t == NULL)
		return;
	for (int i = 0; i < t->nsons; ++i) {
		if (t->Son[i])
			printSubTree(t->Son[i]);
	}

	for (int i = 0; i < t->nkeys; i++)
		cout << t->Key[i] << " ";
}

template<typename T>
inline void BTree<T>::printBetween_(T x, T y, BNode<T>* node)
{
	if (!node)
		return;
	for (int i = 0; i < node->nkeys; ++i)
	{
		if (node->Key[i] < x)
			continue;
		if (node->Key[i] > y)
		{
			printBetween_(x, y, node->Son[i]);
			break;
		}
		else
		{
			printBetween_(x, y, node->Son[i + 1]);
			cout << node->Key[i];
		}
	}

	/*	for (int i = 0; i < node->nsons; ++i)
			if (node->Son[i])
				printBetween_(x,y,node->Son[i]);

		for (int i = 0; i < node->nkeys; i++)
		{
			if (node->Key[i] >= x && node->Key[i] <= y)
				cout << node->Key[i] << " ";
		}
	*/
}


template <typename T>
void BTree<T>::insert(T x) //add a value to the tree
{
	BNode<T>* tmp = NULL;
	T tx;
	if (root == NULL)
		root = new BNode<T>(x);
	else
	{
		root->insert(x, tx, tmp);
		if (tmp) //a split was done;
		{
			BNode<T>* newRoot = new BNode<T>(tx);
			newRoot->Son[0] = root;
			newRoot->Son[1] = tmp;
			root = newRoot;
		}
	}
}

template <typename T>
void BTree<T>::deleteVal(T x)
{
	T tmp;
	bool holeSent;
	if (root == NULL) return;
	root->deleteVal(x, false, tmp, holeSent); //and if a hole was return, the depth of all leaves reduces in one.
	if (holeSent == true)
		if (root->nsons == 1) //the son will be the root
		{
			BNode<T>* tmp = root;
			root = root->Son[0];
			delete tmp;
		}
	//otherwise, the root is allowed to have less than M/2 nodes.
}
