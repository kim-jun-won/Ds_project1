#pragma once
#include "../../DS_Project1/DS_Project1/NameBSTNode.h"


class NameBST
{
private:
	NameBSTNode* root;

public:
	NameBST();
	~NameBST();

	NameBSTNode* getRoot();

	// insert
	void insert(NameBSTNode* newNode);
	// search
	void search(NameBSTNode* root, string name, ofstream& a);
	// print
	void inorderprint(NameBSTNode* node, ofstream& a);
	// delete
	void delete1(NameBSTNode* node, string end_date);
	void delete2(string name);
	// find
	NameBSTNode* find(NameBSTNode* cur, string name);

};