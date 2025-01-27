#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    bool availability;

    Book() : title(""), author(""), availability(true) {}
    Book(string t, string a) : title(t), author(a), availability(true) {}
};

class LibraryManagementSystem {
    unordered_map<string, Book> books;

public:
    // Add a new book to the library
    void addBook(string title, string author, string isbn) {
        if (books.find(isbn) != books.end()) {
            cout << "Book with ISBN " << isbn << " already exists.\n";
        } else {
            books[isbn] = Book(title, author);
            cout << "Book '" << title << "' added successfully!\n";
        }
    }

    // Search for books by title or author using partial matching
    void searchBook(string query) {
        bool found = false;
        for (const auto& pair : books) {
            const string& isbn = pair.first;
            const Book& book = pair.second;
            if (book.title.find(query) != string::npos || book.author.find(query) != string::npos) {
                cout << "ISBN: " << isbn << ", Title: " << book.title
                     << ", Author: " << book.author
                     << ", Status: " << (book.availability ? "Available" : "Not Available") << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No matching books found.\n";
        }
    }

    // Borrow a book if it is available
    void borrowBook(string isbn) {
        if (books.find(isbn) == books.end()) {
            cout << "Book with ISBN " << isbn << " does not exist.\n";
        } else if (!books[isbn].availability) {
            cout << "Book with ISBN " << isbn << " is not available.\n";
        } else {
            books[isbn].availability = false;
            cout << "Book with ISBN " << isbn << " borrowed successfully!\n";
        }
    }

    // Return a borrowed book and update its availability status
    void returnBook(string isbn) {
        if (books.find(isbn) == books.end()) {
            cout << "Book with ISBN " << isbn << " does not exist.\n";
        } else if (books[isbn].availability) {
            cout << "Book with ISBN " << isbn << " is already available.\n";
        } else {
            books[isbn].availability = true;
            cout << "Book with ISBN " << isbn << " returned successfully!\n";
        }
    }

    // Display all books currently in the library
    void viewAllBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
        } else {
            cout << "Library Collection:\n";
            for (const auto& pair : books) {
                const string& isbn = pair.first;
                const Book& book = pair.second;
                cout << "ISBN: " << isbn << ", Title: " << book.title
                     << ", Author: " << book.author
                     << ", Status: " << (book.availability ? "Available" : "Not Available") << "\n";
            }
        }
    }
};

int main() {
    LibraryManagementSystem library;
    int choice;
    string title, author, isbn, query;

    while (true) {
        cout << "Library Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. View All Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the newline character left in the input buffer

        switch (choice) {
            case 1: {
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book ISBN: ";
                cin >> isbn;
                library.addBook(title, author, isbn);
                break;
            }
            case 2: {
                cout << "Enter search query: ";
                cin.ignore();
                getline(cin, query);
                library.searchBook(query);
                break;
            }
            case 3: {
                cout << "Enter book ISBN to borrow: ";
                cin >> isbn;
                library.borrowBook(isbn);
                break;
            }
            case 4: {
                cout << "Enter book ISBN to return: ";
                cin >> isbn;
                library.returnBook(isbn);
                break;
            }
            case 5:
                library.viewAllBooks();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}