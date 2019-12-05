#include "list.h"
#include <conio.h>

using namespace std;

int main()
{
	list* begin = input();

	bool flag = true;
	int n;
	while (flag)
	{
		cout << endl << endl;
		cout << "Menu: " << endl;
		cout << "1. Check for emptiness" << endl;
		cout << "2. Add to start" << endl;
		cout << "3. Add to the end" << endl;
		cout << "4. Count average" << endl;
		cout << "5. Replace one existing item with another" << endl;
		cout << "6. Swap the first and last element" << endl;
		cout << "7. Write to file" << endl;
		cout << "8. Show on screen" << endl;
		cout << "9. Exit" << endl;
		cin >> n;
		switch (n)
		{
		case(1): 
		{
			if (empty(begin))
				cout << "List is empty" << endl;
			else
				cout << "list is not empty" << endl;
		}break;
		case(2):begin=addToStart(begin);break;
		case(3):addToEnd(begin); break;
		case(4):cout << "average is " << average(begin) << endl; break;
		case(5):change(&begin); break;
		case(6):Swap(&begin); break;
		case(7):ofstr(begin); break;
		case(8):print(begin); break;
		case(9):flag = false; break;
		default:
			cout << "Bad input!";
			break;
		}
	}
	deleteList(begin);

	_getch();
	return 0;
}
