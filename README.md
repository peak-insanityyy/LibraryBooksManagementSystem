# LibraryBooksManagementSystem
📚 Library Management System (C++)

A simple, menu-driven Library Management System built using C++. This project allows users to explore books, view book information, borrow available copies, and track borrowed books using student IDs.

✨ Features

- 📖 View Books: Display the list of books available in the library.
- 🔍 Book Information: View a book's author, total copies, and available copies.
- 📕 Borrow Books: Borrow books while checking their availability.
- 👨‍🎓 Student Tracking: Associate borrowed books with student IDs.
- 📋 Borrowing Records: Display the student IDs and titles of borrowed books.
- 🔄 Availability Management: Update the available copy count when a book is borrowed.

🛠️ Concepts Used

This project helped me practice fundamental C++ programming and object-oriented programming concepts:

- Classes and Objects — Represent books and library borrowing operations.
- Encapsulation — Organize book information and borrowing data within classes.
- Constructors — Initialize book details and borrowing records.
- Vectors — Store books and borrowing records dynamically.
- Static Members — Track the total number of book copies and borrowed books.
- Friend Functions and Classes — Access private class members where required.
- Member Functions — Implement book information, borrowing, and display operations.
- Control Flow — Use loops and switch statements to handle menu options.

💻 Technologies Used

- Language: C++
- Standard Library: "<iostream>", "<string>", "<vector>"

🚀 How to Run

1. Clone the repository:
   
   git clone https://github.com/peak-insanityyy/LibraryBooksManagementSystem.git

2. Navigate to the project directory:
   
   cd LibraryBooksManagementSystem

3. Compile the source file using a C++ compiler:
   
   g++ main.cpp -o library
   
   Replace "main.cpp" with the actual name of your C++ source file if it differs.

4. Run the program:
   
   ./library

📚 Sample Books

The library starts with the following books:

- Dune — Frank Herbert
- Sapiens — Yuval Noah Harari
- Think Like a Monk — Jay Shetty
- The Silent Patient — Alex Michaelides
- Atomic Habits — James Clear
- The Alchemist — Paulo Coelho

🎯 Project Goal

The goal of this project was to strengthen my understanding of C++ fundamentals, object-oriented programming, classes, vectors, and basic library management operations through hands-on implementation.

🔮 Future Improvements

- Implement book-return functionality.
- Add input validation and error handling.
- Prevent invalid book selections and improve menu navigation.
- Store borrowing records persistently using file handling.
- Track individual borrowing and returning transactions more reliably.

---

Built with C++ while learning and practicing object-oriented programming. 🚀
