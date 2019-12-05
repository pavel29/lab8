#include "list.h"

bool empty(list *begin)
{
	if (begin == NULL)
		return true;
	else
		return false;
}

list* input()
{
	int n;
	cout << "enter size for array: ";
	cin >> n;
	double* arr = new double[n];

	for (int i(0); i < n; i++)
	{
		cin >> arr[i];
	}

	list* begin = new list;
	begin->data = arr[0];
	begin->next = NULL;
	list *end = begin;
	for (int i(1); i <n; i++)
	{
		end->next = new list;
		end = end->next;
		end->data = arr[i];
		end->next = NULL;
	}
	delete[] arr;

	return begin;
}

list* addToStart(list* begin)
{
	cout << "Enter number to add in structure: ";
	double n;
	cin >> n;
	
	list* current = new list;
	current->data = n;
	current->next = begin;
	begin = current;
	return begin;
}

void print(list* begin)
{
	list* current = begin;
	
	while (true)
	{
		cout << current->data << "->";
		if (current->next == NULL)
			break;
		current = current->next;
	}
	cout << "NULL" << endl;
}

void addToEnd(list* begin)
{
	int a;
	cout << "Enter item: " << endl;
	cin >> a;

	list* last;
	list* current = begin;
	while (true)
	{
		if (current->next == NULL)
		{
			last = current;
			break;
		}
		else
		{
			current = current->next;
		}
	}
	last->next = new list;
	last = last->next;
	last->next = NULL;
	last->data = a;
}

double average(list *begin)
{
	if (empty(begin))
		return 0;
	double counter = 0;
	double sum = 0;
	while (begin)
	{
		counter++;
		sum += begin->data;
		begin = begin->next;
	}
	return sum / counter;
}

void change(list **begin)
{
	int b;
	int a;
	list* change = *begin;
	
		cout << "Which item do you want to change ? "<<endl;
		cin >> a;
		cout << "Which item do you want to receive?"<<endl;
		cin >> b;
		while (change)
		{

			if (change->data == a)
				change->data = b;
			change = change->next;
		}
}

void Swap(list **begin)
{
	if (empty(*begin) || empty((*begin)->next))
	{
		cout << "Error" << endl;
		return;
	}
	list* last = *begin;
	list* prev_last = NULL;
	while (last->next != NULL)
	{
		prev_last = last;
		last = last->next;
	}

	list* temp;

	temp = *begin;
	*begin = last;
	last = temp;
	prev_last->next = last;

	temp = (*begin)->next;
	(*begin)->next = last->next;
	last->next = temp;
}

void ofstr(list *begin)
{
	list* current = begin;
	ofstream output("text.txt");
	while (true)
	{
		output << current->data << "-> ";
		if (current->next == NULL)
			break;
		current = current->next;
	}
	output << "NULL" << endl;
	output.flush();
	output.close();
}

void deleteList(list* begin)
{
	if (begin)
	{
		deleteList(begin->next);
		delete(begin);
	}
}

