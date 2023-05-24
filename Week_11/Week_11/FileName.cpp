#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int count_d = 0;
    int count_s = 0;
    int count_c = 0;

    int i = 0;
    int j = 0;
    int x = 0;
    std::ifstream file("memo.txt");
    std::string line;
    std::vector<std::string> separatedSentences;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string sentence;

            while (std::getline(ss, sentence, '\n')) {
                separatedSentences.push_back(sentence);
            }
        }
        file.close();
    }
    else {
        std::cout << "파일을 열 수 없습니다." << std::endl;
        return 1;
    }

    if (separatedSentences.size() < 2) 
    {
        std::cout << "파일에 적절한 문장이 없습니다." << std::endl;
        return 1;
    }
    //변수선언
    std::string devideFir = separatedSentences[0];
    std::string devideSeco = separatedSentences[1];

    std::stringstream sso(devideFir);
    std::stringstream sst(devideSeco);

    cout << separatedSentences[0] << endl;
    cout << separatedSentences[1] << endl;


    std::string word;
    std::vector<std::string> differentWordsF;
    std::vector<std::string> differentWordsS;
    std::vector<std::string> difWord;

    //벡터에 값 넣기
    while (sso >> word) 
    {
        differentWordsF.push_back(word);
    }

    while (sst >> word)
    {
            differentWordsS.push_back(word);   
    }
    //값이 들어갔는지 확인(잘 들어감)
    for (const auto& word : differentWordsS) {
        cout << word << endl;
    }
    for (const auto& word : differentWordsF) {
        cout << word << endl;
    }
    //시작부터 끝단어까지 진행
    for (auto it = 0; it < differentWordsS.size(); it++)
    {
              //같은 위치의 단어가 다를 때
            if (differentWordsF[i] != differentWordsS[i + x]) 
            {   //비교할 단어 반환
                string firstWord = differentWordsF[i];
                string SecondWord = differentWordsF[i + x];
                //단어의 맨 뒷글자 반환
                char minusFirst = differentWordsS[i].back();
                char minusSecond = differentWordsF[i].back();
                //단어의 첫 글자 반환
                char firWord = differentWordsF[i].front();
                char SecWord = differentWordsS[i].front();
                
                    //실행
                        //뒷글자가 다르다면
                        if (differentWordsF[i].back() != differentWordsS[i].back())
                        {
                            j = i + 1;
                            //문자 결합

                            std::string combinedWord = differentWordsS[i] + differentWordsS[j];
                            std::string minusFir = differentWordsF[i];
                            std::string minusSec = differentWordsS[i] + differentWordsS[j];
                          



                            while (differentWordsF[i].back() == minusSec.back()) {
                                //시작부터 끝단어까지 진행
                                
                                    //만약 맨뒤가 다를 경우
                                    if (minusFir.back() != minusSec.back())
                                    {
                                        
                                    }
                                    //만약 맨뒤가 같을 경우
                                    else
                                    {
                                        //지우기
                                        differentWordsS[i].erase(differentWordsS[i].end() - 1);
                                        minusSec.erase(minusSec.end() - 1);
                                    }                                    
                            }
                                //다른 단어 저장
                                difWord.push_back(minusSec);
                                x++;
                                i++;
                        }
                        //뒷글자가 같다면
                        else if (minusFirst == minusSecond)
                        {
                            do {
                                // 뒷 글자 지우기
                                differentWordsS[i].erase(differentWordsS[i].end() - 1);
                                differentWordsF[i].erase(differentWordsF[i].end() - 1);
                                //단어의 맨 뒷글자 반환
                                 minusFirst = differentWordsS[i].back();
                                 minusSecond = differentWordsF[i].back();
                                
                                //다른 단어 저장
                                difWord.push_back(differentWordsS[i]);

                            } while (differentWordsF[i].back() == differentWordsS[i].back());

                            //다른 단어 저장
                            difWord.push_back(differentWordsS[i]);
                            i++;
                        }
                
                
            }
            else
            {
                continue;
            }
    }

    cout << "다른 문자: " << endl;
    for (int v = 0; v < difWord.size(); v++)
        cout << difWord[v] << " ";

    cout << "\n\n";
    cout << "%s 개수: " << count_s << endl;
    cout << "%d 개수: " << count_d << endl;
    cout << "%c 개수: " << count_c << endl;

   
    
    return 0;
}

