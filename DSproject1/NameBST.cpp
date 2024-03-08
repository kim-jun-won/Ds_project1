#include "NameBST.h"
#include "Manager.h"
#include <iostream>
using namespace std;

NameBST::NameBST() : root(nullptr)
{

}
NameBST::~NameBST()
{

}

NameBSTNode* NameBST::getRoot()
{
	return root;
}

// insert
void NameBST::insert(NameBSTNode* newNode)
{
	string m_name = newNode->get_name();
	if (root == nullptr)
	{
		root = newNode;
		return;
	}
	NameBSTNode* cur = getRoot();
	NameBSTNode* pcur = nullptr;

	while (cur != nullptr)
	{
		pcur = cur;
		string a = cur->get_name();
		int result = a.compare(m_name);

		if (result > 0)
			cur = cur->getLeft();
		else if (result < 0)
			cur = cur->getRight();
	}

	string b = pcur->get_name();
	int result = b.compare(m_name);
	if (result > 0)
	{
		pcur->setLeft(newNode);
		newNode->setParent(pcur);
	}
	else if (result < 0)
	{
		pcur->setRight(newNode);
		newNode->setParent(pcur);
	}


	return;
}

// search
void NameBST::search(NameBSTNode* root, string name, ofstream& a)
{
	if (root == nullptr) return;

	if (root->get_name() == name)
	{
		a << root->get_name() << "/" << root->get_age() << "/" << root->get_collec_date() << "/" << root->get_end_date() << '\n';
	}
	search(root->getLeft(), name, a);
	search(root->getRight(), name, a);

}
// print
void NameBST::inorderprint(NameBSTNode* node, ofstream& a)
{
	if (node == nullptr)
		return;

	inorderprint(node->getLeft(), a);
	a << node->get_name() << "/" << node->get_age() << "/" << node->get_collec_date() << "/" << node->get_end_date() << '\n';
	inorderprint(node->getRight(), a);

}
//find
NameBSTNode* NameBST::find(NameBSTNode* cur, string name)
{
	if (cur == nullptr)
		return nullptr; // if cannot fine node then return nullptr

	if (cur->get_name() == name)
		return cur; // if find node, then return that node pointer

	// recursive find in left subtree node
	NameBSTNode* leftResult = find(cur->getLeft(), name);
	if (leftResult != nullptr)
		return leftResult; // if find return leftResult

	NameBSTNode* rightResult = find(cur->getRight(), name);
	if (rightResult != nullptr)
		return rightResult; // if find return rightResult

	// if cannot find node then return nullptr
	return nullptr;
}

// delete
void NameBST::delete1(NameBSTNode* node, string end_date)
{
	if (node == nullptr)
		return;
	// process that deletes nodes that have end-date less than end_date
	// postorder
	delete1(node->getLeft(), end_date);
	delete1(node->getRight(), end_date);
	//
	if (node->get_end_date() < end_date)
	{
		// if node is leaf node
		if (node->getLeft() == nullptr && node->getRight() == nullptr)
		{
			if (node->getParent() == nullptr) this->root = nullptr;
			else if (node->getParent()->getLeft() == node) node->getParent()->setLeft(nullptr);
			else if (node->getParent()->getRight() == node) node->getParent()->setRight(nullptr);

			node->setParent(nullptr);
		}
		// if node has only left child
		else if (node->getRight() == nullptr)
		{
			if (node->getParent() == nullptr)  root = node->getLeft();
			else if (node->getParent()->getLeft() == node) node->getParent()->setLeft(node->getLeft());
			else node->getParent()->setRight(node->getLeft());

			node->getLeft()->setParent(node->getParent());
			node->setParent(nullptr);
		}
		// if node has only right child
		else if (node->getLeft() == nullptr)
		{
			if (node->getParent() == nullptr)  root = node->getRight();
			else if (node->getParent()->getLeft() == node) node->getParent()->setLeft(node->getRight());
			else if (node->getParent()->getRight() == node) node->getParent()->setRight(node->getRight());

			node->getRight()->setParent(node->getParent());
			node->setParent(nullptr);
		}
		// if node has two childern
		else
		{
			NameBSTNode* cur = node->getRight();

			while (cur->getLeft() != nullptr)
			{
				cur = cur->getLeft();
			}
			// if delNode is root Node
			if (node == root)
			{

				if (cur->getParent() == node)
				{
					node->setRight(nullptr);
					cur->setParent(nullptr);
				}
				else
				{

					if (cur->getRight() == nullptr)
					{
						cur->getParent()->setLeft(nullptr);
						cur->setParent(nullptr);
					}
					else
					{
						cur->getParent()->setLeft(cur->getRight());
						cur->setParent(nullptr);
					}
				}
				cur->m_swap(node, cur);

			}
			else
			{

				if (cur->getRight() != nullptr)
				{
					cur->getParent()->setLeft(cur->getRight());
					cur->setParent(nullptr);
				}
				else
				{
					cur->getParent()->setLeft(nullptr);
					cur->setParent(nullptr);
				}
				cur->m_swap(node, cur);
			}
		}
	}

}

void NameBST::delete2(string name)
{
	NameBSTNode* delNode = find(root, name);
	// cout << delNode->get_name() << '\n';
	if (delNode == nullptr) return;

	// if node is leaf node
	if (delNode->getLeft() == nullptr && delNode->getRight() == nullptr)
	{
		if (delNode == root) root = nullptr;
		else if (delNode->getParent()->getLeft() == delNode) delNode->getParent()->setLeft(nullptr);
		else if (delNode->getParent()->getRight() == delNode) delNode->getParent()->setRight(nullptr);

		delNode->setParent(nullptr);
	}
	// if node has only left child
	else if (delNode->getRight() == nullptr)
	{
		if (delNode->getParent() == nullptr)  root = delNode->getLeft();
		else if (delNode->getParent()->getLeft() == delNode) delNode->getParent()->setLeft(delNode->getLeft());
		else delNode->getParent()->setRight(delNode->getLeft());

		delNode->getLeft()->setParent(delNode->getParent());
		delNode->setParent(nullptr);
	}
	// if node has only right child
	else if (delNode->getLeft() == nullptr)
	{
		if (delNode->getParent() == nullptr)  root = delNode->getRight();
		else if (delNode->getParent()->getLeft() == delNode) delNode->getParent()->setLeft(delNode->getRight());
		else delNode->getParent()->setRight(delNode->getRight());

		delNode->getRight()->setParent(delNode->getParent());
		delNode->setParent(nullptr);
	}
	// if node has two childern
	else
	{
		NameBSTNode* cur = delNode->getRight();

		while (cur->getLeft() != nullptr)
		{
			cur = cur->getLeft();
		}
		// is deletenode is root node
		if (delNode == root)
		{

			if (cur->getParent() == delNode)
			{
				delNode->setRight(nullptr);
				cur->setParent(nullptr);
			}
			else
			{

				if (cur->getRight() == nullptr)
				{
					cur->getParent()->setLeft(nullptr);
					cur->setParent(nullptr);
				}
				else
				{
					cur->getParent()->setLeft(cur->getRight());
					cur->setParent(nullptr);
				}
			}
			cur->m_swap(delNode, cur);

		}
		else
		{

			if (cur->getRight() != nullptr)
			{
				cur->getParent()->setLeft(cur->getRight());
				cur->setParent(nullptr);
			}
			else
			{
				cur->getParent()->setRight(nullptr);
				cur->setParent(nullptr);
			}
			cur->m_swap(delNode, cur);
		}
	}
}


