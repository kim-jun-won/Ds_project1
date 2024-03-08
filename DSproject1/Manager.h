
#include "../../DS_Project1/DS_Project1/MemberQueue.h"
#include "../../DS_Project1/DS_Project1/TermsList.h"
#include "../../DS_Project1/DS_Project1/TermsBST.h"
#include "NameBST.h"
#include <fstream>
using namespace std;
class Manager
{
private:

	ifstream	fcmd;
	ofstream	flog;

public:
	Manager();
	~Manager();

	void run(const char* command);

	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);
	//LOAD
	void LOAD(MemberQueue* q);
	// ADD
	// QPOP
	void QPop(MemberQueue* q, TermsLIST* list, NameBST* namebst);
	// SEARCH
	void Search(NameBST* namebst, string name);
	// PRINT
	void Print_Termslist(TermsLIST* list, string type);
	void Print_NameBST(NameBST* namebst);
	// DELETE NAME_BST
	void namebst_Delete1(NameBST* bst, string end_date);
	void namebst_Delete2(NameBST* bst, string name);
	// DELETE TERMS_BST
	void termsbst_Delete1(TermsLIST* bst, string end_date);
	void termsbst_Delete2(TermsLIST* bst, string name);
	// DELETE TERMS_LIST
	void Exit(MemberQueue* q, TermsLIST* newlist, NameBST* new_namebst);
};
