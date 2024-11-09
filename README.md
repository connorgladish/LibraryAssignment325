# LibraryAssignment325

A basic C++ library management system to manage books. The program allows users to:

- Add books to the library
- Find books by author or title
- Delete books from the library
- Save/load the library data from/to a file

There is also a database in the project files that already has a template database of books. The file name is `templateLibrary.txt`.

## Features

- **Add a Book**: Enter book details (title, author, ISBN, pages, price, and year).
- **Find by Author**: Search for books written by a specific author.
- **Find by Title**: Search for a book by its title.
- **Delete a Book**: Remove a book from the library by specifying its author and title.
- **Save/Load Data**: Save the library to a file and load it from a file.

## Setup & Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/connorgladish/LibraryAssignment325
    ```

2. Navigate to the project directory:

    ```bash
    cd LibraryAssignment325s
    ```

3. Compile the program:

    ```bash
    make
    ```

4. Run the program:

    ```bash
    ./library
    ```

## Usage

Upon running the program, you'll be presented with a menu to choose from:

1. Add a book to the library.
2. Find books by a specific author.
3. Find a book by its title.
4. Delete a book from the library.
5. Exit the program.

You'll also be prompted to load the library from a file or save your changes to a file when you exit.

## Files

- **`main.cpp`**: The main program logic with menu options and user input.
- **`library.cpp`**: Functions for managing the library's books (adding, deleting, saving, and loading).
- **`book.cpp`**: Defines the `Book` class with attributes like title, author, and ISBN.
- **`library.h`**: Header file with the `Library` class definition.
- **`book.h`**: Header file with the `Book` class definition.

## This project was completed on Nov 8, by CJ Gladish and Reece Cosbey. ##
