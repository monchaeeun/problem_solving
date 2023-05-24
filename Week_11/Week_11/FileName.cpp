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
        std::cout << "������ �� �� �����ϴ�." << std::endl;
        return 1;
    }

    if (separatedSentences.size() < 2) 
    {
        std::cout << "���Ͽ� ������ ������ �����ϴ�." << std::endl;
        return 1;
    }
    //��������
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

    //���Ϳ� �� �ֱ�
    while (sso >> word) 
    {
        differentWordsF.push_back(word);
    }

    while (sst >> word)
    {
            differentWordsS.push_back(word);   
    }
    //���� ������ Ȯ��(�� ��)
    for (const auto& word : differentWordsS) {
        cout << word << endl;
    }
    for (const auto& word : differentWordsF) {
        cout << word << endl;
    }
    //���ۺ��� ���ܾ���� ����
    for (auto it = 0; it < differentWordsS.size(); it++)
    {
              //���� ��ġ�� �ܾ �ٸ� ��
            if (differentWordsF[i] != differentWordsS[i + x]) 
            {   //���� �ܾ� ��ȯ
                string firstWord = differentWordsF[i];
                string SecondWord = differentWordsF[i + x];
                //�ܾ��� �� �ޱ��� ��ȯ
                char minusFirst = differentWordsS[i].back();
                char minusSecond = differentWordsF[i].back();
                //�ܾ��� ù ���� ��ȯ
                char firWord = differentWordsF[i].front();
                char SecWord = differentWordsS[i].front();
                
                    //����
                        //�ޱ��ڰ� �ٸ��ٸ�
                        if (differentWordsF[i].back() != differentWordsS[i].back())
                        {
                            j = i + 1;
                            //���� ����

                            std::string combinedWord = differentWordsS[i] + differentWordsS[j];
                            std::string minusFir = differentWordsF[i];
                            std::string minusSec = differentWordsS[i] + differentWordsS[j];
                          



                            while (differentWordsF[i].back() == minusSec.back()) {
                                //���ۺ��� ���ܾ���� ����
                                
                                    //���� �ǵڰ� �ٸ� ���
                                    if (minusFir.back() != minusSec.back())
                                    {
                                        
                                    }
                                    //���� �ǵڰ� ���� ���
                                    else
                                    {
                                        //�����
                                        differentWordsS[i].erase(differentWordsS[i].end() - 1);
                                        minusSec.erase(minusSec.end() - 1);
                                    }                                    
                            }
                                //�ٸ� �ܾ� ����
                                difWord.push_back(minusSec);
                                x++;
                                i++;
                        }
                        //�ޱ��ڰ� ���ٸ�
                        else if (minusFirst == minusSecond)
                        {
                            do {
                                // �� ���� �����
                                differentWordsS[i].erase(differentWordsS[i].end() - 1);
                                differentWordsF[i].erase(differentWordsF[i].end() - 1);
                                //�ܾ��� �� �ޱ��� ��ȯ
                                 minusFirst = differentWordsS[i].back();
                                 minusSecond = differentWordsF[i].back();
                                
                                //�ٸ� �ܾ� ����
                                difWord.push_back(differentWordsS[i]);

                            } while (differentWordsF[i].back() == differentWordsS[i].back());

                            //�ٸ� �ܾ� ����
                            difWord.push_back(differentWordsS[i]);
                            i++;
                        }
                
                
            }
            else
            {
                continue;
            }
    }

    cout << "�ٸ� ����: " << endl;
    for (int v = 0; v < difWord.size(); v++)
        cout << difWord[v] << " ";

    cout << "\n\n";
    cout << "%s ����: " << count_s << endl;
    cout << "%d ����: " << count_d << endl;
    cout << "%c ����: " << count_c << endl;

   
    
    return 0;
}

