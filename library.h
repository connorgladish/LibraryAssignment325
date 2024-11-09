#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>
#include "book.h"

class Library {
public:
    // Add book in sorted order by author
    void insert_sorted(const Book& book);

    // Find all books by an author
    void find_author(const std::string& author) const;

    // Find book by title
    void find_title(const std::string& title) const;

    // Delete a book by author and title
    void delete_book(const std::string& author, const std::string& title);

    // Load and save library data
    void load_from_file(const std::string& filename);
    void save_to_file(const std::string& filename) const;

    // Display all books
    void display_all() const;

    // Getter function to access books list
    const std::list<Book>& getBooks() const;

private:
    std::list<Book> books;
};

#endif
