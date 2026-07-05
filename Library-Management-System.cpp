#include <iostream>
#include <string>

using namespace std;

struct Book
{
    int id;
    string title;
    bool issued;
};

Book books[50];
int countBook = 0;

int searchBook(int id, int index)
{
    if(index >= countBook)
        return -1;

    if(books[index].id == id)
        return index;

    return searchBook(id, index + 1);
}

int main()
{
    int choice;

    while(true)
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "\nEnter Book ID: ";
                cin >> books[countBook].id;

                cout << "Enter Book Title: ";
                cin >> books[countBook].title;

                books[countBook].issued = false;

                countBook++;

                cout << "\nBook Added Successfully!\n";
                break;
            }

            case 2:
            {
                if(countBook == 0)
                {
                    cout << "\nNo Books Available!\n";
                }
                else
                {
                    cout << "\n========== BOOK LIST ==========\n";

                    for(int i = 0; i < countBook; i++)
                    {
                        cout << "\nBook " << i + 1 << endl;
                        cout << "ID     : " << books[i].id << endl;
                        cout << "Title  : " << books[i].title << endl;

                        cout << "Status : ";

                        if(books[i].issued)
                            cout << "Issued";
                        else    
                            cout << "Available";

                        cout << endl;
                    }
                }
                break;
            }

            case 3:
            {
                int id;

                cout << "\nEnter Book ID to Search: ";
                cin >> id;

                int pos = searchBook(id, 0);

                if(pos == -1)
                {
                    cout << "\nBook Not Found!\n";
                }
                else
                {
                    cout << "\nBook Found!\n";
                    cout << "ID     : " << books[pos].id << endl;
                    cout << "Title  : " << books[pos].title << endl;

                    cout << "Status : ";

                    if(books[pos].issued)
                        cout << "Issued";
                    else
                        cout << "Available";

                    cout << endl;
                }

                break;
            }

            case 4:
            {
                int id;

                cout << "\nEnter Book ID to Issue: ";
                cin >> id;

                int pos = searchBook(id, 0);

                if(pos == -1)
                {
                    cout << "\nBook Not Found!\n";
                }
                else if(books[pos].issued)
                {
                    cout << "\nBook Already Issued!\n";
                }
                else
                {
                    books[pos].issued = true;
                    cout << "\nBook Issued Successfully!\n";
                }

                break;
            }

            case 5:
            {
                int id;

                cout << "\nEnter Book ID to Return: ";
                cin >> id;

                int pos = searchBook(id, 0);

                if(pos == -1)
                {
                    cout << "\nBook Not Found!\n";
                }
                else if(!books[pos].issued)
                {
                    cout << "\nThis Book Was Not Issued!\n";
                }
                else
                {
                    books[pos].issued = false;
                    cout << "\nBook Returned Successfully!\n";
                }

                break;
            }

            case 6:
            {
                int id;

                cout << "\nEnter Book ID to Delete: ";
                cin >> id;

                int pos = searchBook(id, 0);

                if(pos == -1)
                {
                    cout << "\nBook Not Found!\n";
                }
                else
                {
                    for(int i = pos; i < countBook - 1; i++)
                    {
                        books[i] = books[i + 1];
                    }

                    countBook--;

                    cout << "\nBook Deleted Successfully!\n";
                }

                break;
            }

            case 7:
            {
                cout << "\nThank You For Using Library Management System!\n";
                return 0;
            }

            default:
            {
                cout << "\nInvalid Choice! Please Try Again.\n";
            }
        }
    }

    return 0;
}