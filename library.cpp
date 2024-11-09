// library.cpp
#include "library.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>

void Library::insert_sorted(const Book& book) {
    // Insert the book into the list while maintaining the sorted order by author
    auto it = books.begin();
    for (; it != books.end(); ++it) {
        if (it->getAuthor() > book.getAuthor()) {
            break;  
        }
    }
    books.insert(it, book);  // Insert the book at the appropriate position
}

void Library::find_author(const std::string& author) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            std::cout << "Found book: " << book.getTitle() << " by " << book.getAuthor() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found by author: " << author << std::endl;
    }
}

void Library::find_title(const std::string& title) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            std::cout << "Found book: " << book.getTitle() << " by " << book.getAuthor() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found with title: " << title << std::endl;
    }
}

void Library::delete_book(const std::string& author, const std::string& title) {
    auto it = std::remove_if(books.begin(), books.end(), [&](const Book& book) {
        return book.getAuthor() == author && book.getTitle() == title;
    });
    if (it != books.end()) {
        books.erase(it, books.end());
        std::cout << "Book: " << title << " by " << author << " has been removed." << std::endl;
    } else {
        std::cout << "Book not found for removal: " << title << " by " << author << std::endl;
    }
}

void Library::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string title, author, isbn;
        int pages, year;
        float price;

        // Read the file in a simple format
        while (file >> title >> author >> isbn >> pages >> price >> year) {
            Book book(title, author, pages, isbn, price, year);
            insert_sorted(book);  // Insert books while maintaining sorted order
        }
        file.close();
        std::cout << "Books loaded from file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}

void Library::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& book : books) {
            file << book.getTitle() << " "
                 << book.getAuthor() << " "
                 << book.getISBN() << " "
                 << book.getPages() << " "
                 << book.getCoverPrice() << " "
                 << book.getYear() << "\n";  // Save all attributes in one line
        }
        file.close();
        std::cout << "Books saved to file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

void Library::display_all() const {
    if (books.empty()) {
        std::cout << "No books available in the library." << std::endl;
        return;
    }
    for (const auto& book : books) {
        std::cout << book.getTitle() << " by " << book.getAuthor() << std::endl;
    }
}

const std::list<Book>& Library::getBooks() const {
    return books;  // Return the list of books
}
