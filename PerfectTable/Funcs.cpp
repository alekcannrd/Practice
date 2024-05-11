#include "Funcs.h"
//void invalidInput(int a, int b)
//{
//	if (std::cin.fail())
//	{
//		std::cin.clear();
//		std::cin.ignore(32767, '\n');
//	};
//	std::cout << std::endl;
//	std::cout << "Неверный ввод. Допустимый ввод: целые числа от " << a << " до " << b << std::endl;
//	std::cout << "Повторите ввод: " << std::endl;
//};

//std::istream& input(std::istream &in, int& inp, int a, int b)
//{
//	bool goodInput{ false };
//	do
//	{
//		in >> inp;
//		in.ignore(32767, '\n');
//		if (in.fail() || inp > b || inp < a)
//		{
//			invalidInput(a, b);
//		}
//		else
//		{
//			goodInput = true;
//		};
//	} while (!goodInput);
//	std::system("cls");
//	return in;
//};

//void lineBreak(QString &line, int border) {
//	int a(line.size());
//    QString outLine{line.QSubstr(0,border)};
//	line.erase(0, border);
//	/*for (int i{}; i < a; ++i) {
//		if (i < border) {
//			outLine[i] = line[i];
//		}
//		if (i + border < a) line[i] = line[i + border];
//		else line[i] = '\0';
//	}*/
//	std::cout << outLine;
//};

//void printStolb()
//{
//	std::cout << '|' << std::setw(UNIT_LEN);
//}
//void printLine()
//{
//	std::cout << '+';
//	for (int i{ 0 }; i <= 126; ++i)
//		std::cout << '-';
//	std::cout << '+' << std::endl;
//};




