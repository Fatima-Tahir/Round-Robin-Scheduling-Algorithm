#include "ProcessQueue.h"


ProcessQueue::ProcessQueue(void)
{
	head=NULL;
}

Process* ProcessQueue:: getHead()
{
	return head;
}

ProcessQueue::~ProcessQueue(void)
{
	if(head)
	{
		Process * cur=head;
		while(cur->next != head)
		{
			Process * t=cur;
			cur=cur->next;
			delete t;
		}
		delete cur;
		head=NULL;
	}
}

void ProcessQueue:: insert(const Process &newProcess)
{
	Process * node=new Process(newProcess);
	if(head==NULL)
	{
		head=node;
		head->next=head;
	}
	else
	{
		Process * cur=head;
		while(cur->next!=head)
		{
			cur=cur->next;
		}
		cur->next=node;
		node->next=head;
	}
}

void ProcessQueue:: insertAfter(Process * prev,const Process &newProcess)
{
	if(prev==NULL)
	{
		cout<<"Prev Node null\n";
		return;
	}

	Process * newNode=new Process (newProcess);

	Process * traverse=head;
	while(traverse->next != prev)
	{
		traverse=traverse->next;
	}
	traverse->next=newNode;
	newNode->next=prev;
}
void ProcessQueue:: remove(const Process * obj)
{
	if(head==NULL)
		cout<<"Can't Removed in empty list\n";
	else
	{
		Process * cur=head;
		Process * prev=NULL;
		while(cur->next != head && (cur)!= obj)
		{
			prev=cur;
			cur=cur->next;
		}
		if(prev==NULL)
		{
			Process * temp=head;
			Process * start=head;
			head=head->next;
			while(start->next != temp)
			{
				start=start->next;
			}
			start->next=head;
		}
		else
		{
			prev->next=cur->next;
		}

		if(obj->next == obj)
		{
			head = NULL;
		}
		if(cur!=NULL)
			delete cur;
	}
}
void ProcessQueue:: showList()
{
	if(head==NULL)
	{
		cout<<"Empty list\n";
	}
	else
	{
		Process * cur=head;
		do
		{
			cur->showDetails();
			cur=cur->next;
			cout<<endl;
		}
		while(cur!=head);
	}
}

bool ProcessQueue:: isEmpty()
{
	return (head==NULL);
}