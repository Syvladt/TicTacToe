// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
char cell(std::string inStr_1, std::string inStr_2, std::string inStr_3, int x, int y) {
    if (y == 0)
        return inStr_3[x];
    else if (y == 1)
        return inStr_2[x];
    else return inStr_1[x];
}

bool validate_input(std::string inStr) {
    if (inStr.length() != 3)
        return false;
    else {
        for (int i = 0; i < 3; i++) {
            if (inStr[i] != 'X' && inStr[i] != 'O' && inStr[i] != '.')
                return false;
        }
        return true;
    }
}

std::string string_search(std::string inStr) {
    if (inStr[0] == 'X' && inStr[1] == 'X' && inStr[2] == 'X')
        return "Petya won!\n";
    else if (inStr[0] == 'O' && inStr[1] == 'O' && inStr[2] == 'O') {
        return "Vanya won!\n";
    }
}



int main()
{
    std::string inStr_1, inStr_2, inStr_3;
    std::cout << "\nProgram for validate result games tic-tac-toe\n\n";
    std::cout << "Input games result:\n";
    std::cin >> inStr_1;
    std::cin >> inStr_2;
    std::cin >> inStr_3;
    if (validate_input(inStr_1) && validate_input(inStr_2) && validate_input(inStr_3))
        std::cout << "valid\n";
    else
        std::cout << "invalid\n";
    std::cout << cell(inStr_1, inStr_2, inStr_3, 2, 2);

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
