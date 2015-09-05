/*
 * visitor.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: tatsu
 */
#include <string>
using namespace std ;
#include "visitor.h"

string Node::getName() { return name ; }

Node::Node(int id, string name) {}
File::File(int id , string name) : Node(id,name) {}
void File::add(Node* pNode) {}
void File::accept(Visitor* pVisitor) { pVisitor->visit(this) ; }

Directory::Directory(int id, string name ) : Node(id,name) {}
void Directory::add(Node* pNode) { children.push_back(pNode) ; }
void Directory::accept(Visitor* pVisitor) {
	pVisitor->visit(this) ;
	list<Node*>::iterator it = children.begin() ;
	while(it != children.end()) {
		(*it)->accept(pVisitor) ;
		it ++ ;
	}
}

FindVisitor::FindVisitor() { pResult = new list<Node*> ; }
FindVisitor::~FindVisitor() { delete pResult ; }
list<Node*> FindVisitor::find(Node* pNode,string name) {
	this->name = name ;
	pNode->accept(this) ;
	return (*pResult) ;
}

void FindVisitor::visit(Directory* pDirectory) {
	if(pDirectory->getName().compare(name) == 0)
		pResult->push_back(pDirectory) ;
}
void FindVisitor::visit(File* pFile) {
	if(pFile->getName().compare(name) == 0)
		pResult->push_back(pFile) ;
}


