#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Function to display menu options
void displayMenu() {
    std::cout << "\nSimple Note Taking App\n";
    std::cout << "1. Create a New Note\n";
    std::cout << "2. View All Notes\n";
    std::cout << "3. Delete a Note\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

// Function to create a new note
void createNote() {
    std::string fileName, fileContent;

    std::cout << "Enter note title: ";
    std::cin.ignore();
    std::getline(std::cin, fileName);

    std::ofstream file(fileName + ".txt");
    std::cout << "Enter note content (press Enter then Ctrl+D in a new line to finish):\n";
    while (std::getline(std::cin, fileContent)) {
        file << fileContent << std::endl;
    }
    file.close();

    std::cout << "Note created successfully.\n";
}

// Function to view all notes
void viewNotes() {
    std::vector<std::string> files;
    std::string fileName;
    std::ifstream fileList("filelist.txt");

    while (std::getline(fileList, fileName)) {
        files.push_back(fileName);
    }
    fileList.close();

    std::cout << "\nList of Notes:\n";
    for (const auto& file : files) {
        std::cout << file << std::endl;
    }
}

// Function to delete a note
void deleteNote() {
    std::string fileName;

    std::cout << "Enter note title to delete: ";
    std::cin.ignore();
    std::getline(std::cin, fileName);

    if (std::remove((fileName + ".txt").c_str()) == 0) {
        std::cout << "Note deleted successfully.\n";
    } else {
        std::cout << "Error deleting the note.\n";
    }
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                createNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                deleteNote();
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
