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
        std::cout << "- ������ ������� ������ �������� 8 �������\n";
        return false;
    }

    for (char c : password) {
        if (std::isupper(c)) hasUpper = true;
        else if (std::islower(c)) hasLower = true;
        else if (std::isdigit(c)) hasDigit = true;
        else if (std::ispunct(c)) hasSpecial = true;
    }

     if (!hasUpper) std::cout << "- ������ �� ������ ���� � ���� ������ �����\n";
    if (!hasLower) std::cout << "- ������ �� ������ ���� � ���� ���� �����\n";
    if (!hasDigit) std::cout << "- ������ �� ������ ���� � ���� �����\n";
    if (!hasSpecial) std::cout << "- ������ �� ������ ���� � ���� ����������� ������\n";

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

    std::cout << "�����! ������� ��������� ��� ������.\n";
    std::cout << "���� �����, ������ ��� ������: ";
    std::getline(std::cin, userPassword);

    if (!checkPassword(userPassword)) {
        std::cout << "�� ����, ��� ������ ���������. ��� �����, ������������ ������:\n";
        std::string newPassword = generateStrongPassword();
        std::cout << "������������ ������: " << newPassword << std::endl;
    }
    else {
        std::cout << "��� ������ �������! ��������!\n";
    }

    return 0;
}
