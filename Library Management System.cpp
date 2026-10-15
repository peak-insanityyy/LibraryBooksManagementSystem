#include <iostream>
#include <string>
#include <vector>

class Book {
    std::string title;
    std::string author;
    static int totalBooks;
    int totalCopies;
    int availableCopies;
public:
    Book(std::string cTitle = "???", std::string cAuthor = "???", int copies = 0) : title(cTitle), author(cAuthor), totalCopies(copies), availableCopies(copies) {
        totalBooks += copies;
    }
    void infoBook();
    void showTitle(int iterator);
    friend void showTitleAll(std::vector<Book>& , int bookCount);
    friend void getInfoBook(std::vector<Book>&, int bookCount);
    friend class BookManage;
};

class BookManage {
    std::string mTitle;
    int studentId;
public:
    static int borrowedBooks;
    BookManage(std::string cTitle = "???", int cStudentID= 0) : mTitle(cTitle),  studentId(cStudentID) {}
    void borrowBook(std::vector<Book>&, int);
    void returnBook();
    friend void showAllBorrowedBooks(std::vector<BookManage>&);
};

// Book class member function start
void Book::infoBook() {
    std::cout << "The title of the book: " << title
    << "\nThe author of the book: " << author
    << "\nThe total copies of the book: "
    << totalCopies
    << "\nThe available copies of the book: " <<
    availableCopies << "\n";
}

void Book::showTitle(int iterator) {
    std::cout << iterator+1 << ". " << "Title: " << title << "\n\n";
}

void showTitleAll(std::vector<Book>& library, int bookCount) {
     std::cout << std::string(67, '=') << "\n\n";
     for (int i = 0; i < bookCount; i++) {
        library[i].showTitle(i);
     }
     std::cout << std::string(67, '=');
     std::cout << "\n\n";
}

void getInfoBook(std::vector<Book>& library, int bookCount) {
    std::cout << "\nEnter the option number of the book you want to check: ";
    
    while (true) {
        int choice {};
        std::cin >> choice;
        if (choice > 0 and choice <= bookCount) {
            std::cout << "\n";
    
            library[--choice].infoBook();
            std::cout << "\n";
            break;
        }
        else {
            std::cout << "\nPlease enter number between 1-" << bookCount << ": ";
        }
    }
}
    
int Book::totalBooks = 0;
// Book class member function end

// BookManage class member start
void BookManage::borrowBook(std::vector<Book>& library, int choice) {
    if (library[choice-1].availableCopies <= 0) {
        std::cout << "\nNo available copies\n";
    }
    else {
        mTitle = library[--choice].title;
        std::cout << "\nEnter the student ID to borrow '" << mTitle << "' book: ";
        std::cin >> studentId;
        borrowedBooks++;
        library[choice].availableCopies--;
        std::cout << "\n";
    }
}

void showAllBorrowedBooks(std::vector<BookManage>& borrowLibrary) {
    if (BookManage::borrowedBooks == 0) {
        std::cout << "\nNo borrowed books yet.\n";
    }
    else {
        for (int i = 0; i < BookManage::borrowedBooks; i++) {
            std::cout << "The student ID: " << borrowLibrary[i].studentId << " took the book: " << borrowLibrary[i].mTitle << "\n\n"; 
        }
    }
}

int BookManage::borrowedBooks = 0;

int main() {
    std::vector<Book> library{};
    int bookCount;
    
    library.push_back(Book("Dune", "Frank Herbet", 3));
    library.push_back(Book("Sapiens", "Yuval Noah Harari", 10));
    library.push_back(Book("Think Like A Monk", "Jay Shetty", 5));
    library.push_back(Book("The Silent Patient", "Alex Michaelides", 5));
    library.push_back(Book("Atomic Habits", "James Clear", 10));
    library.push_back(Book("The Alchemist", "Paulo Coelho", 10));
    
    bookCount = library.size();
    
    std::vector<BookManage> borrowLibrary {};
    borrowLibrary.push_back(BookManage());
    
    showTitleAll(library, bookCount);
    
    while (true) {
        std::cout << std::string(67, '=');
        std::cout << "\n\n1. Get Info of a book\n\n2. Borrow a book\n\n3. Show all borrowed books\n\n4. Exit:";
        int option;
        std::cin >> option;
        switch (option) {
            case 1:
                getInfoBook(library, bookCount);
                break;
            case 2:
               std::cout << "\nwhich book do you want to borrow?: ";
               int choice;
               std::cin >> choice; borrowLibrary[BookManage::borrowedBooks].borrowBook(library, choice);
                borrowLibrary.push_back(BookManage());
                break;
            case 3:
                showAllBorrowedBooks(borrowLibrary);
                break;
            case 4:
                std::cout << "\nThanks for coming to the library.\n";
                exit(0);
        }
    }
    
    return 0;
}
