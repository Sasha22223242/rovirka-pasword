#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <random>
#include <Windows.h>

bool checkPassword(const std::string& password) {
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    if (password.length() < 8) {
        std::cout << "- Пароль повинен містити принаймні 8 символів\n";
        return false;
    }

    for (char c : password) {
        if (std::isupper(c)) hasUpper = true;
        else if (std::islower(c)) hasLower = true;
        else if (std::isdigit(c)) hasDigit = true;
        else if (std::ispunct(c)) hasSpecial = true;
    }

     if (!hasUpper) std::cout << "- Пароль має містити хоча б одну велику літеру\n";
    if (!hasLower) std::cout << "- Пароль має містити хоча б одну малу літеру\n";
    if (!hasDigit) std::cout << "- Пароль має містити хоча б одну цифру\n";
    if (!hasSpecial) std::cout << "- Пароль має містити хоча б один спеціальний символ\n";

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

std::string generateStrongPassword(int length = 12) {
    const std::string characters =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()_+[]{}|;:,.<>?";

    std::string password;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    for (int i = 0; i < length; ++i) {
        password += characters[distribution(generator)];
    }

    return password;
}

int main() {
    system("chcp 1251>null");
    std::string userPassword;

    std::cout << "Привіт! Давайте перевіримо ваш пароль.\n";
    std::cout << "Будь ласка, введіть свій пароль: ";
    std::getline(std::cin, userPassword);

    if (!checkPassword(userPassword)) {
        std::cout << "На жаль, ваш пароль ненадійний. Ось новий, згенерований пароль:\n";
        std::string newPassword = generateStrongPassword();
        std::cout << "Згенерований пароль: " << newPassword << std::endl;
    }
    else {
        std::cout << "Ваш пароль надійний! Молодець!\n";
    }

    return 0;
}
