#pragma once

#include <iostream>
#include <fstream>

using namespace std;

typedef double TE;

struct list
{
	TE data;
	list* next;
};

list* input();
list* addToStart(list*);
bool empty(list*);
void print(list*);
void addToEnd(list*);
void deleteList(list*);
double average(list*);
void change(list**);
void Swap(list**);
void ofstr(list*);
