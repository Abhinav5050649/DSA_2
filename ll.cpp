#include "bits/stdc++.h"
using namespace std;

typedef struct node
{
	int num;
	node* next = NULL;

	node()
	{
		num = 0;
	}

	node(int numb)
	{
		num = numb;
	}
}
node;

typedef struct ll{
	node *head;
	int cnt = 0;
	ll()
	{
		head = NULL;
	}

	ll(node* n)
	{
		head = n;
		++cnt;
	}

	void insert_node_at_end(node* n)
	{
		if (head == NULL)
		{
			head = n;
		}
		else
		{
			node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
			++cnt;
		}
	}

	void prepend_node(node *n)
	{
		if (head == NULL)
		{
			head = n;
		}
		else if (head -> next = NULL)
		{
			n->next = head;
			head = n;
		}
	}

	void print_list()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << "Number == " << temp->num << endl;
			temp = temp->next; 
		}
	}

	int no_of_nodes()
	{
		return cnt;
	}

	//Reverse linked list
	void reverse_ll()
	{
		Node* arr[cnt];
		Node *temp = head;
		int i = 0;
		while (temp != NULL)
		{
			arr[i] = temp;
			temp = temp->next;
			++i;
		}

		Node *nh = arr[cnt - 1];
	}

}
ll;

int main()
{
	node *n = new node;
	n->num = 1;
	ll list(n);

	int s = 5;
	while (s--)
	{
		int x; cout << "Enter x: "; cin >> x;
		node* ne = new node(x);
		list.insert_node_at_end(ne);	
	}
	cout << "Nodes in linked list: " << list.no_of_nodes() << endl;
	list.print_list();
	return 0;
}