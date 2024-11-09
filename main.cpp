#include <iostream>
#include <string>
#include <limits> 
#include "library.h"

Library library;

// Function prototypes
void addBook();
void findAuthor();
void findTitle();
void deleteBook();
void displayMenu();
void loadDatabase();
void saveDatabase(const std::string& filename);  

int main() {
    int choice;
    std::string filename;

    // Ask for the filename to load the database
    std::cout << "Enter the filename to load the library database (or press Enter to skip): ";
    std::getline(std::cin, filename);

    if (!filename.empty()) {
        library.load_from_file(filename);  // Use the load_from_file method to load the database
        std::cout << "Library database loaded from " << filename << std::endl;
    } else {
        std::cout << "No database file provided, starting with an empty library." << std::endl;
    }

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear newline

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                findAuthor();
                break;
            case 3:
                findTitle();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                // Ask for filename to save the database
                std::cout << "Enter the filename to save the library database: ";
                std::getline(std::cin, filename);
                saveDatabase(filename);  // Pass filename as argument
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}

// Display the menu options
void displayMenu() {
    std::cout << "\nLibrary Menu:\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Find Books by Author\n";
    std::cout << "3. Find Book by Title\n";
    std::cout << "4. Delete Book\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void addBook() {
    std::string title, author, isbn;
    int pages, year;
    float price;

    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);

    std::cout << "Enter number of pages: ";
    std::cin >> pages;

    std::cout << "Enter cover price: ";
    std::cin >> price;

    std::cout << "Enter publication year: ";
    std::cin >> year;
    std::cin.ignore();  

    Book book(title, author, pages, isbn, price, year);
    library.insert_sorted(book);  // Use insert_sorted instead of add_book

    std::cout << "Book added successfully.\n";
}

// Function to find books by author and display full details
void findAuthor() {
    std::string author;
    std::cout << "Enter author name: ";
    std::getline(std::cin, author);

    for (const auto& book : library.getBooks()) {
        if (book.getAuthor() == author) {
            std::cout << "Found book: "
                      << book.getTitle() << " by " << book.getAuthor() << "\n"
                      << "ISBN: " << book.getISBN() << "\n"
                      << "Pages: " << book.getPages() << "\n"
                      << "Price: $" << book.getCoverPrice() << "\n"
                      << "Year: " << book.getYear() << "\n"
                      << std::endl;
        }
    }
}

// Function to find a book by title and display full details
void findTitle() {
    std::string title;
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);

    for (const auto& book : library.getBooks()) {
        if (book.getTitle() == title) {
            std::cout << "Found book: "
                      << book.getTitle() << " by " << book.getAuthor() << "\n"
                      << "ISBN: " << book.getISBN() << "\n"
                      << "Pages: " << book.getPages() << "\n"
                      << "Price: $" << book.getCoverPrice() << "\n"
                      << "Year: " << book.getYear() << "\n"
                      << std::endl;
        }
    }
}

// Function to delete a book
void deleteBook() {
    std::string title, author;
    std::cout << "Enter author name: ";
    std::getline(std::cin, author);
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    library.delete_book(author, title);  
}

// Function to load the database of books from a file
void loadDatabase() {
    std::string filename;
    std::cout << "Enter the filename to load the library database: ";
    std::getline(std::cin, filename);

    if (!filename.empty()) {
        library.load_from_file(filename);  // Load the file into the library
        std::cout << "Library database loaded from " << filename << std::endl;
    } else {
        std::cout << "No file specified, continuing with the empty library.\n";
    }
}

// Function to save the database of books to a file
void saveDatabase(const std::string& filename) {
    library.save_to_file(filename);  // Save the current state of the library
    std::cout << "Library database saved to " << filename << std::endl;
}
