#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char* token;
    int d_value = 0;
    char c_value = '\0';
    char s_value[100] = "";
    char t_value[100] = "";//탭 입력 수정
    float f_value = 0.0f;

    printf("입력값: ");
    // 입력값 저장
    fgets(input, 100, stdin);

     token = strtok(input, " \t");
    while (token != NULL) 
    {
        // 입력값이 정수형 변수일 때
        if (isdigit(token[0]))
        { 
            int i = 0;
            while (token[i])
            {

                //숫자만 있는지 판단
                if (isdigit(token[i]))
                {
                    d_value = atoi(token);
                }
                //. 이 있을 때
                else if (token[i] == '.')
                {
                    f_value = atof(token);
                }

                i++;
            }

            
        }
        // 입력값이 문자형 변수일 때
        else if (isalpha(token[0])) 
        { 
            c_value = token[0];
        }
        // 입력값이 문자열 변수일 때
        else if (strlen(token) > 0) 
        { 
            if (strlen(s_value) == 0) {
                strcpy(s_value, token);
            }
            //tap 키 입력 수정
            else if (strlen(t_value) == 0) {
                strcpy(t_value, token);
            }
          

        }
        token = strtok(NULL, " ");
    }

    //입력 값 표시
    printf("d_value = %d\n", d_value);
    printf("c_value = %c\n", c_value);
    printf("s_value = %s\n", s_value);
    printf("t_value = %s\n", t_value);
    printf("f_value = %f\n", f_value);
    return 0;
}