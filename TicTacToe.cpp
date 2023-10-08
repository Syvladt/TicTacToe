// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
char cell(std::string inStr, int x, int y) {
    return inStr[y * 3 + x];
}

bool validate_input(std::string inStr_1, std::string inStr_2, std::string inStr_3) {
    std::string temp;
    temp = inStr_1 + inStr_2 + inStr_3;
    if (temp.length() != 9 || inStr_1.length() != 3 || inStr_2.length() != 3 || inStr_2.length() != 3)
        return false;
    else {
        for (int i = 0; i < 9; i++) {
            if (temp[i] != 'X' && temp[i] != 'O' && temp[i] != '.')
                return false;
        }
        return true;
    }
}

int validate_field(std::string inStr, char sign) {
    std::string temp;
    int num = 0;
    for (int i = 0; i < 9; i++) {
        if (inStr[i] == sign)
            num++;
    }
    return num;
}

char find_winner(std::string inStr, char sign) {
    int counter_l = 0, counter_r = 0;
    for (int i = 0; i < 3; i++) {
        if (cell(inStr, 0, i) == sign && cell(inStr, 1, i) == sign && cell(inStr, 2, i) == sign)
            return sign;
        if (cell(inStr, i, 0) == sign && cell(inStr, i, 1) == sign && cell(inStr, i, 2) == sign)
            return sign;
        if (cell(inStr, i, 2 - i) == sign)
            counter_r++;
        if (cell(inStr, i, i) == sign)
            counter_l++;
    }
    if (counter_l == 3 || counter_r == 3)
        return sign;
    else
        return '.';
}

int main()
{
    std::string inStr, inStr_1, inStr_2, inStr_3;
    char temp;
    int x_counter, o_counter, dot_counter;
    std::cout << "\nProgram for validate result games tic-tac-toe\n\n";
    std::cout << "Input games result:\n";
    std::cin >> inStr_1;
    std::cin >> inStr_2;
    std::cin >> inStr_3;
    inStr = inStr_1 + inStr_2 + inStr_3;
    if (validate_input(inStr_1, inStr_2, inStr_3)) {
        x_counter = validate_field(inStr, 'X');
        o_counter = validate_field(inStr, 'O');
        dot_counter = validate_field(inStr, '.');
        if (find_winner(inStr, 'O') == 'O' && find_winner(inStr, 'X') == 'X')
            std::cout << "Incorrect\n";
            else if (find_winner(inStr, 'O') == 'O' && x_counter == o_counter)
                std::cout << "Vanya won!\n";
            else if (find_winner(inStr, 'X') == 'X' && x_counter - o_counter == 1)
                std::cout << "Petya won!\n";
             else if (find_winner(inStr, 'X') == '.' && find_winner(inStr, 'O') == '.' && ((x_counter - o_counter) == 0 || (x_counter - o_counter) == 1))
                std::cout << "Nobody\n";
             else
                std::cout << "Incorrect\n";
    }
    else
        std::cout << "Incorrect\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
