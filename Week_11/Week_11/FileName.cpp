#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::ifstream file("memo.txt");  // 메모장 파일 열기

    if (file.is_open()) {  // 파일이 성공적으로 열렸는지 확인
        std::string line;
        while (std::getline(file, line)) {
            std::string::size_type pos = line.find("%d");
            if (pos != std::string::npos) {
                int number;  // 숫자 입력값
                std::cout << "숫자를 입력하세요: ";
                std::cin >> number;
                line.replace(pos, 2, std::to_string(number));  // %d를 숫자로 대체
            }

            pos = line.find("%c");
            if (pos != std::string::npos) {
                char character;  // 문자 입력값
                std::cout << "문자를 입력하세요: ";
                std::cin >> character;
                line.replace(pos, 2, 1, character);  // %c를 문자로 대체
            }

            std::cout << line << std::endl;  // 수정된 내용 출력
        }
        file.close();  // 파일 닫기
    }
    else {
        std::cout << "메모장을 읽을 수 없습니다." << std::endl;
    }

    return 0;
}
