#include <iostream>
#include <fstream>//use for string
#include <sstream> //use for reopen file file handling convert
using namespace std;
struct Node
{
	string name;
	int Book_price;
	Node *next;
	Node *prev;
};
class Bookstore
{
public:
	Node *head;
	Node *mid; // for find a mid value in binery search using globally
	string Book_name;
	int price;

	Bookstore()
	{
		head = NULL;
	}
	void CreateNode() // insert a node
	{
		if (head == NULL)
		{
			Node *new_node = new Node;
			cout << "  Name of BOOK: ";
			cin.ignore();
			getline(cin, Book_name); //use for space in string
			new_node->name = Book_name;

			cout << "  BOOK PRICE: ";
			cin >> price;
			new_node->Book_price = price;

			new_node->next = NULL;
			new_node->prev == NULL;
			head = new_node;

			cout << "  Book Added" << endl;
		}
		else
		{

			Node *new_node = new Node;
			cout << "  Name of Book: ";
			cin.ignore();
			getline(cin, Book_name);
			new_node->name = Book_name;

			cout << "  BOOk PRICE: ";
			cin >> price;
			new_node->Book_price = price;

			new_node->next = NULL;

			Node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
			cout << "  Book Added" << endl;
		}
	}
	void Display()
	{
		Node *temp = head;
		int count = 0;

		if (temp == NULL)
		{
			cout << "  No Books... Please Add Some Books" << endl;
			cout << "  Thanks" << endl;
		}
		else
		{
			BubbleSort();

			cout << "\n Book Name "
				 << "    Book Price \n"
				 << endl;
			while (temp != NULL)
			{
				count++;
				cout << "  " << temp->name << ":";
				cout << "  " << temp->Book_price << endl;
				temp = temp->next;
			}
			cout << "\n\n  Total Books: " << count << endl;
		}
	}

	// binay search
	bool Bsearch()
	{

		cout << "Enter Book Name" << endl;
		cin.ignore();
		getline(cin, Book_name);

		// find a mid node
		Node *temp = head;
		Node *left = head;
		Node *right = head;
		while (right->next != NULL && right->next->next != NULL)
		{
			left = left->next;
			right = right->next->next;
		}
		mid = left; // mid node

		while (mid != NULL)
		{
			if (mid->name == Book_name)
			{
				cout << "Book is Found" << endl;
				cout << "Book Name : " << mid->name << endl;
				cout << "Book price : " << mid->Book_price << endl;

				return true;
			}

			else if (mid->name > Book_name)
			{
				mid = temp;

				while (mid != left) // head node to mid node
				{
					if (mid->name == Book_name)
					{
						cout << "\nBook is Found\n"
							 << endl;
						cout << "\nBook Name : " << mid->name << endl;
						cout << "\nBook price : " << mid->Book_price << endl;
						return true;
					}

					mid = mid->next;
				}
				cout << "\nBook Not Found" << endl;
				return false;
			}
			else
			{
				mid = mid->next;
			}
		}
		cout << "\nBook Not Found" << endl;
		return false;
	}

	void DeleteAll_Books()
	{
		Node *temp = head;
		Node *temp2;
		if (head == NULL)
		{
			cout << "  Book Store is Empty" << endl;
			cout << "***********" << endl;
		}
		else
		{
			while (temp != NULL)
			{
				temp2 = temp;
				temp = temp->next;
				delete temp2;
			}
			head = NULL;
			cout << "  Successfully Deleted All Books" << endl;
			cout << "***********" << endl;
		}
	}
	// delete specific books
	bool DeleteBooks()
	{
		bool check = false;
		Node *temp;
		cout << "***********" << endl;

		if (Bsearch() == true)
		{
			temp = mid;
			check = true;

			if (check == true)
			{
				int User_input;
				cout << "  Press 1 to Delete A BOOk: ";
				cin >> User_input;
				if (User_input == 1 && temp == head) // first node delete
				{
					Node *temp1;
					temp1 = temp;
					temp = temp->next;
					delete temp1;

					head = temp;
					cout << "  Book Delete Succesfully" << endl;
					return true;
				}
				if (User_input == 1 && temp->next == NULL) // last node delete
				{
					temp->prev->next = NULL;
					delete temp;
					cout << "  Book Delete Successfully" << endl;
					return true;
				}
				if (User_input == 1) // delete specific node
				{
					Node *temp1;
					temp1 = temp;
					temp->prev->next = temp1->next;
					temp->next->prev = temp1->prev;

					delete temp1;

					cout << "  Book Delete Successfully" << endl;
					return true;
				}

				else
				{
					cout << "  Invalid Command" << endl;
				}
			}
		}
	}
	// bubble sort applying
	void BubbleSort()
	{
		Node *temp = head;
		Node *i, *j;
		string n;
		int swap2;
		if (temp == NULL)
		{
			cout << "  Books store is Empty" << endl;
		}
		else
		{
			for (i = temp; i->next != NULL && i != NULL; i = i->next)
			{
				for (j = i->next; j != NULL; j = j->next)
				{

					// swap

					if (i->name > j->name)
					{
						n = i->name;
						i->name = j->name;
						j->name = n;

						swap2 = i->Book_price;
						i->Book_price = j->Book_price;
						j->Book_price = swap2;
					}
				}
			}
		}
	}
	int EditContacts()
	{
		Node *temp;
		cout << "***********" << endl;

		bool flag = false;
		if (Bsearch() == true)
		{
			temp = mid;
			flag = true;

			if (flag == true)
			{

				int User_input;
				cout << "\n\n  Press 1 to Edit the Book: ";
				cin >> User_input;
				if (User_input == 1)
				{
					cout << "  Enter New Book Name: ";
					cin.ignore();
					getline(cin, Book_name);
					cout << "  Enter New Book Price: ";
					cin >> price;

					temp->name = Book_name;
					temp->Book_price = price;

					cout << "  Book Edited Successfully" << endl;
				}
				else
				{
					cout << "  Invalid User_input" << endl;
				}
			}
		}
	}

	void Filesave()
	{
		Node *temp = head;
		ofstream myfile("Book_store.txt");
		if (myfile.is_open())
		{
			while (temp != NULL)
			{
				myfile << temp->name << endl;
				myfile << temp->Book_price << endl;
				temp = temp->next;
			}
			myfile.close();
		}
	}

void reopenCB()
		{
			bool isEmpty;
			ifstream myfile ("Book_store.txt");
            if (myfile.is_open() & myfile.peek() != EOF)
            {
                int i=0;
                while(getline(myfile,Book_name))
                {	
                    if(i % 2 == 0)
					{
						if(head==NULL)
	                    {
    	                  Node *newer= new Node;
                          newer->name=Book_name;
		         
	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      head=newer;
		                }
						else
						{
							Node *newer= new Node;
							
							newer->name=Book_name;
							newer->next=NULL;
							
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=newer;
		                	newer->prev=temp;		
						} 
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->Book_price==0)
                    	{
                    		
                    		 stringstream convert(Book_name);
			       	         convert>>price;
                             temp->Book_price=price;
						}
						else
						{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	
		                	stringstream convert(Book_name);
			       	        convert>>price;
		                	temp->Book_price=price;
							
						}
                       
				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
            	cout<<"  Book store is Empty Cannot open...Sorry"<<endl;
			}
		}
	

	
};

int main()
{
	Bookstore bs;
	bs.reopenCB();
	int user;

	cout << "******************************************" << endl;
	cout << "  "
		 << "  WELCOME TO BOOK STORE MANAGEMENT SYSTEM     " << endl;
	cout << "\n*****************************************" << endl;

	do
	{
		cout << "\n******************" << endl;
		cout << "  1. Add Book" << endl;
		cout << "  2. Edit the Book" << endl;
		cout << "  3. Delete Book" << endl;
		cout << "  4. Search Book" << endl;
		cout << "  5. Display All Books" << endl;
		cout << "  6. Delete All Books" << endl;
		cout << "  0. Close the program" << endl;
		cout << "***********" << endl;
		cout << " Enter the Input  ";
		cin >> user;

		switch (user)
		{
		case 1:
			bs.CreateNode();
			bs.Filesave();

			break;
		case 2:
			bs.EditContacts();
			bs.Filesave();

			break;
		case 3:
			bs.DeleteBooks();

			break;
		case 4:
			bs.Bsearch();

			break;
		case 5:
			bs.Display();
			bs.Filesave();

			break;
		case 6:
			bs.DeleteAll_Books();
			bs.Filesave();

			break;

		default:
			cout << "ERROR: invalid Option" << endl;
		}

	} while (user != 0);

	return 0;
}