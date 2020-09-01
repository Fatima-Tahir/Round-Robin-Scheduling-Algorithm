#include "ProcessSingleList.h"


ProcessSingleList::ProcessSingleList(void)
{
	head =NULL;
}


ProcessSingleList::~ProcessSingleList(void)
{
	
	Process *cur=head ,*temp=NULL;
	while(cur!=NULL)
	{
		temp=cur;
		cur=cur->next;
		delete temp;
	}
}

bool ProcessSingleList:: isEmpty()
{
	return (head==NULL);
}
void ProcessSingleList:: insertAtLast(const Process &newProcess)
{
	Process * node=new Process(newProcess);
	if(head==NULL)
	{
		head=node;
	}
	else
	{
		Process* cur=head;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=node;
	}
}
void ProcessSingleList::deleteAtStart()
{
	Process * cur=head;
	head=head->next;
	delete cur;
}
void ProcessSingleList ::delete1(Process * obj)
{
	if(head==NULL)
		cout<<"Can't Removed in empty list\n";
	else
	{
		Process obj1(*obj);
		Process * cur=head;
		Process * prev=NULL;
		while(cur!=NULL && (cur)!= obj)
		{
			prev=cur;
			cur=cur->next;
		}
		if(prev==NULL)
		{
			head=head->next;
			//deleteAtStart();
		}
		else
		{
			prev->next=cur->next;
		}
		if(cur!=NULL)
			delete cur;
	}
}
void ProcessSingleList::print()
{
	Process * cur=head;
	if(head==NULL)
		cout<<"Empty list\n";
	while(cur!=NULL)
	{
		cur->showDetails();
		cout<<endl;
		cur=cur->next;
	}
}

void ProcessSingleList :: sort()
{
	Process* current = head;
	Process* index = NULL;
//Current will point to head  

	int Arr_t=0,Ser_t=0;
	string name;

	if(head == NULL)
	{  
		cout<<("List is empty");  
	}  
	else 
	{  
		do
		{  
			//Index will point to node next to current  
			index = current->next;  
			while(index != NULL) 
			{  
		//If current node is greater than index data, swaps the data  
				if(current->arrival_time >= index->arrival_time)
				{  
					if(current->arrival_time == index->arrival_time)
					{
						if(current->service_time > index->service_time)
						{
							name =current->name;  
							current->name= index->name;  
							index->name = name;  

							Arr_t =current->arrival_time;  
							current->arrival_time= index->arrival_time;  
							index->arrival_time = Arr_t; 

							Ser_t =current->service_time;  
							current->service_time= index->service_time;  
							index->service_time = Ser_t; 
						}
					}
					else
					{
						name =current->name;  
						current->name= index->name;  
						index->name = name;  

						Arr_t =current->arrival_time;  
						current->arrival_time= index->arrival_time;  
						index->arrival_time = Arr_t; 

						Ser_t =current->service_time;  
						current->service_time= index->service_time;  
						index->service_time = Ser_t; 
					}
				}  
			index= index->next;  
			}  
		current =current->next;  
		}
		while(current != NULL);   
	}  
}  

Process * ProcessSingleList ::gethead()
{
	return head;
}