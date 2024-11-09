#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(const std::string& title = "", const std::string& author = "", int pages = 0,
         const std::string& isbn = "", float cover_price = 0.0f, int year = 0);

    std::string getTitle() const;
    std::string getAuthor() const;
    int getPages() const;
    std::string getISBN() const;
    float getCoverPrice() const;
    int getYear() const;

    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setPages(int pages);
    void setISBN(const std::string& isbn);
    void setCoverPrice(float price);
    void setYear(int year);

private:
    std::string title;
    std::string author;
    int pages;
    std::string isbn;
    float cover_price;
    int year;
};

#endif
