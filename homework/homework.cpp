//#include <iostream>
//#include <string>
//#include <cctype>
//#include <Windows.h>
//
//std::string filterAndLowercase(const std::string& str) {
//    std::string result;
//    for (char ch : str) {
//        if (std::isalpha(ch)) {
//            result += std::tolower(ch);
//        }
//    }
//    return result;
//}
//
//int main() {
//    system("chcp 1251>null");
//    std::string str1, str2;
//
//    std::cout << "Введіть перший рядок: ";
//    std::getline(std::cin, str1);
//
//    std::cout << "Введіть другий рядок: ";
//    std::getline(std::cin, str2);
//
//    // Фільтруємо і перетворюємо обидва рядки
//    std::string filteredStr1 = filterAndLowercase(str1);
//    std::string filteredStr2 = filterAndLowercase(str2);
//
//    // Порівняння
//    if (filteredStr1 == filteredStr2) {
//        std::cout << "ІДЕНТИЧНІ" << std::endl;
//    }
//    else {
//        std::cout << "не ІДЕНТИЧНІ" << std::endl;
//    }
//
//    return 0;
//}
//2 завдання
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <windows.h>

bool containsLower(const std::string& password) {
    for (char ch : password) {
        if (std::islower(ch)) return true;
    }
    return false;
}

bool containsUpper(const std::string& password) {
    for (char ch : password) {
        if (std::isupper(ch)) return true;
    }
    return false;
}

bool containsDigit(const std::string& password) {
    for (char ch : password) {
        if (std::isdigit(ch)) return true;
    }
    return false;
}

bool containsSpecial(const std::string& password) {
    for (char ch : password) {
        if (std::ispunct(ch)) return true;
    }
    return false;
}

bool isPasswordStrong(const std::string& password) {
    return password.length() >= 8 &&
        containsLower(password) &&
        containsUpper(password) &&
        containsDigit(password) &&
        containsSpecial(password);
}

std::string generateStrongPassword() {
    const std::string chars = "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()";
    std::string password;
    std::srand(std::time(0)); // Ініціалізація випадкового числа

    for (int i = 0; i < 12; ++i) {
        password += chars[std::rand() % chars.size()];
    }
    return password;
}

int main() { 
    system("chcp 1251>null");
    std::string password;

    std::cout << "Введіть пароль: ";
    std::cin >> password;

    if (isPasswordStrong(password)) {
        std::cout << "Пароль надійний!" << std::endl;
    }
    else {
        std::cout << "Пароль не надійний! Ось чого бракує:" << std::endl;
        if (password.length() < 8) {
            std::cout << "- Довжина менша за 8 символів." << std::endl;
        }
        if (!containsLower(password)) {
            std::cout << "- Немає малих літер." << std::endl;
        }
        if (!containsUpper(password)) {
            std::cout << "- Немає великих літер." << std::endl;
        }
        if (!containsDigit(password)) {
            std::cout << "- Немає цифр." << std::endl;
        }
        if (!containsSpecial(password)) {
            std::cout << "- Немає спеціальних символів." << std::endl;
        }

        // Пропонуємо згенерувати новий пароль
        std::cout << "Згенерований надійний пароль: " << generateStrongPassword() << std::endl;
    }

    return 0;
}

