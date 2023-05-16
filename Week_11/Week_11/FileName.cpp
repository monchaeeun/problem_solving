#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::ifstream file("memo.txt");  // �޸��� ���� ����

    if (file.is_open()) {  // ������ ���������� ���ȴ��� Ȯ��
        std::string line;
        while (std::getline(file, line)) {
            std::string::size_type pos = line.find("%d");
            if (pos != std::string::npos) {
                int number;  // ���� �Է°�
                std::cout << "���ڸ� �Է��ϼ���: ";
                std::cin >> number;
                line.replace(pos, 2, std::to_string(number));  // %d�� ���ڷ� ��ü
            }

            pos = line.find("%c");
            if (pos != std::string::npos) {
                char character;  // ���� �Է°�
                std::cout << "���ڸ� �Է��ϼ���: ";
                std::cin >> character;
                line.replace(pos, 2, 1, character);  // %c�� ���ڷ� ��ü
            }

            std::cout << line << std::endl;  // ������ ���� ���
        }
        file.close();  // ���� �ݱ�
    }
    else {
        std::cout << "�޸����� ���� �� �����ϴ�." << std::endl;
    }

    return 0;
}
