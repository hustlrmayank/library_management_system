#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Book
{
public:
  string title, author;
  int id;

  Book(int id, string title, string author)
  {
    this->id = id;
    this->title = title;
    this->author = author;
  }

  void display()
  {
    cout << "Book ID:" << id << " | Title:" << title << " | Author:" << author << endl;
  }
};

class Library
{
private:
  vector<Book> Books;

public:

Library(){
  loadfile();
}
  void addBook(int id, string title, string author)
  {
    Books.push_back(Book(id, title, author));
    cout << "Book added successfully!";
  }

  void displayBooks()
  {
    if (Books.empty())
    {
      cout << "No Books available!";
      return;
    }
    cout << "List of Books:" << endl;
    for (auto &Book : Books)
    {
       Book.display();
    }
  }

  void searchbook(int id)
  {
    for (auto &Book : Books)
      if (Book.id == id)
      {
        cout << "Book is found" << endl;
        Book.display();
        
      }
    cout << "Book not found." << endl;
  }

  void removebook(int id)
  {
    for (auto it = Books.begin(); it != Books.end(); ++it)
    {
      if (it->id == id)
      {
        Books.erase(it);
        cout << "Book removed successfully." << endl;
        //return;
      }
    }
    cout << "Book not found." << endl;
  }
void savefile(){
  ofstream in("libfile.txt");
  for(auto &Book : Books){
    in<<Book.id<<"\n"<<Book.title<<"\n"<<Book.author<<endl;
  }
  in.close();
}

void loadfile(){
  ifstream out("libfile.txt");
if(!out)return;
Books.clear();
int id;
string title,author;
if(out>>id){
  out.ignore();
 getline(out,title);
 getline(out,author);
 Books.push_back(Book(id, title, author));
}
out.close();
}
  
};
int main()
{
  Library Library;
  int choice, id;
  string title, author;
  cout << "\n Library Management system \n";
  bool running=true;
  while (running)
  {
    cout << "select options:" << endl;
    cout << "1. Add Book. \n 2. display Books. \n 3. Search Book. \n 4. Remove Book.\n";
    cout << "enter your choice:" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter Book id:" << endl;
      cin >> id;
      cin.ignore();
      cout << "Enter Book name:" << endl;
      getline(cin, title);
      cout << "Enter author name:" << endl;
      getline(cin, author);
      Library.addBook(id, title, author);
      break;

    case 2:
      cout << "Books are:" << endl;
      Library.displayBooks();
      break;

    case 3:
      cout << "Enter the book ID:";
      cin >> id;
      Library.searchbook(id);
      break;

    case 4:
      cout << "Enter the book ID:";
      cin >> id;
      Library.removebook(id);
      break;

    case 5:
      cout << ".....Exiting" << endl;
      running = false;
      break;

    default:
      cout << "Invalid option." << endl;
  
    }
  }
}
