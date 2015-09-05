/*
 * visitor.h
 *
 *  Created on: Aug 29, 2015
 *      Author: tatsu
 */

#ifndef VISITOR_H_
#define VISITOR_H_
#include <string>
#include <list>
using namespace std ;

class Visitor;

class Node {
public:
	Node(int id , string name) ;
	int getId() ;
	string getName() ;
	virtual void add(Node* pNode) = 0 ;
	virtual void accept(Visitor* pVisitor) = 0 ;
private:
	int id ;
	string name ;
};

class File : public Node {
public:
	File(int id , string name) ;
	virtual void add(Node* pNode) ;
	virtual void accept(Visitor* pVisitor) ;
};

class Directory : public Node {
public:
	Directory(int id , string name) ;
	virtual void add(Node* pNode) ;
	virtual void accept(Visitor* pVisitor) ;
private:
	list<Node*> children ;
};

class Visitor {
public:
	virtual void visit(Directory* pDirectory) = 0 ;
	virtual void visit(File* pFile) = 0 ;
};

class FindVisitor : public Visitor {
public:
	FindVisitor() ;
	virtual ~FindVisitor() ;
	list<Node*> find(Node *pNode,string name) ;
	virtual void visit(Directory* pDirectory) ;
	virtual void visit(File* pFile) ;
private:
	string name ;
	list<Node*>* pResult ;
};


#endif /* VISITOR_H_ */
