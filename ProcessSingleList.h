#pragma once

#include<string>
#include<iostream>
#include "Process.h"
class ProcessSingleList
{
private:
	Process * head;
public:
	ProcessSingleList(void);
	~ProcessSingleList(void);
	bool isEmpty();
	void insertAtLast(const Process &newProcess);
	void deleteAtStart();
	void print();
	void sort();
	Process * gethead();
	void delete1(Process * newp);
};

