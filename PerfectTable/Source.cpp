
//#include "Header.h"
////void printList(List& w)
////{
////	w.print();
////}

//void menuFuncAdd(List& w)
//{
//	//std::system("cls");
//    QString h[static_cast<int>(TITLES::TITLE_SIZE)]{};
//	for (int i{}; i < static_cast<int>(TITLES::TITLE_SIZE); ++i)
//	{
//		std::cout << "Input " << List::m_strTitleNames[i] << ": ";
//		std::cin >> h[i];
//	};
//	w.add(Item(std::stoi((h[0]).c_str()), h[1], std::stod((h[2]).c_str()), std::stod((h[3]).c_str()), h[4], std::stoi((h[5]).c_str()), std::stoi((h[6]).c_str()), std::stoi((h[7]).c_str())));
//}
//bool isStandard()
//{
//	std::cout << "Standard file? 1/0" << std::endl;
//	bool a{};
//	std::cin >> a;
//	std::cin.ignore(32767, '\n');
//	return a;
//}

//void menuFuncAddFromTxtFile(List& w)
//{
//	//std::system("cls");
//    QString fileName{};
//	Item temp{};
//	//reset(dataBase, currentSize);
//	if (!isStandard())
//	{
//		//std::cin.ignore(32767, '\n');
//		std::cout << "Input full path to file: " << std::endl;
//		std::getline(std::cin, fileName);
//	}
//	else
//	{
//		fileName = "D:/666.txt";
//	};
//	std::ifstream fileRead(fileName);
//	if (fileRead.is_open())
//	{
//		w.clear();
//		while (!fileRead.eof())
//		{
//			std::cout << temp;
//			fileRead >> temp;
//			w.add(temp);
//		};
//	}
//	else
//	{
//		//fileOpenError();
//	};
//	//currentId = dataBase[i - 1].id;
//	if (fileRead.is_open())
//		fileRead.close();

//}
////void printToBin(Student* dataBase, int currentSize)
////{
////	char fileName[255]{};
////	std::cout << "??????? ?????? ???? ? ????????? ????? ???????? (??????? ?????????? .bin): " << std::endl;
////	std::cin.getline(fileName, 255, '\n');
////	std::ofstream fileWrite(fileName, std::ios::binary);
////	if (fileWrite.is_open())
////	{
////		for (int i{ 0 }; i < currentSize; ++i)
////		{
////			fileWrite.write(reinterpret_cast<char*>(dataBase + i), sizeof(Student));
////			std::cout << i << ' ';
////		};
////		fileWrite.close();
////	}
////	else
////		fileOpenError();
////
////
////};


//void MenuFuncOutTxtFile(List &w)
//{
//    QString fileName{};

//	std::cin.ignore(32767, '\n');
//	std::cout << "Input full path to file:" << std::endl;
//	std::getline(std::cin, fileName);
//	std::ofstream fileWrite(fileName);
//	if (fileWrite.is_open())
//	{
//		for (int i{ 0 }; i < w.getSize(); ++i)
//		{
//			fileWrite << w.m_vItemList[i];
//		};
//		fileWrite.close();
//	}
//	//else fileOpenError();


//}
////void inputBin(Student*& dataBase, int& currentSize, int& maxSize, int& currentId)
////{
////	char name[255]{};
////	reset(dataBase, currentSize);
////	std::cout << "??????? ?????? ???? ? ?????: " << std::endl;
////	std::cin.getline(name, 255, '\n');
////	std::ifstream fileRead(name, std::ios::binary);
////	int& i = currentSize;
////	Student temp{};
////	if (fileRead.is_open())
////	{
////		while (fileRead.read(reinterpret_cast<char*>(&temp), sizeof(Student)))
////		{
////			if (i >= maxSize - 2)
////				dataBase = increaseSize(dataBase, maxSize, currentSize);
////			dataBase[i] = temp;
////			++i;
////
////		}
////		fileRead.close();
////	}
////	else fileOpenError();
////	currentId = dataBase[i - 1].id;
////}
////void inputTxt(Student*& dataBase, int& currentSize, int& maxSize, int& currentId, bool isStandard = false)
////{
////	char name[255]{};
////	reset(dataBase, currentSize);
////	if (!isStandard)
////	{
////		std::cout << "??????? ?????? ???? ? ?????: " << std::endl;
////		std::cin.getline(name, 255);
////	}
////	else
////	{
////		strcpy_s(name, "D:/example666.txt");
////	};
////	std::ifstream fileRead(name);
////	int& i = currentSize;
////	if (fileRead.is_open())
////	{
////		while (!fileRead.eof())
////		{
////			if (i >= maxSize - 1)
////				dataBase = increaseSize(dataBase, maxSize, currentSize);
////			fileRead >> dataBase[i].id >> dataBase[i].surname >> dataBase[i].firstname >> dataBase[i].fathername >> dataBase[i].age >> dataBase[i].course >> dataBase[i].year_of_admission >> dataBase[i].math >> dataBase[i].eng >> dataBase[i].physics >> dataBase[i].graphics >> dataBase[i].linearAlgebra;
////			++i;
////		};
////	}
////	else
////	{
////		fileOpenError();
////	};
////	currentId = dataBase[i - 1].id;
////	if (fileRead.is_open())
////		fileRead.close();
////};

//void menuFuncDelete(List& w)
//{
//	//std::system("cls");
//	std::cout << "Input article of deleted element: ";
//    QString article{};
//	std::cin >> article;
//	w.del(*w.findByArticle(std::stoi(article.c_str())));
//}
//void menuFuncChange(List&);
//void menuFuncSort(List&);
//void menuFuncFind(List&);
//void menuFuncGraphic(List&);


//void filterByNumOfParty(List& w) {
//	int numOfParty{};
//	std::cout << "input NUM OF PARTY:\n";
//	std::cin >> numOfParty;
//	List filteredList = w.filterByNumOfParty(numOfParty);
//	filteredList.print();
//	//system("pause");
//}
//void filterByName(List& w) {
//    QString name{};
//	std::cout << "input NAME:\n";
//	std::cin >> name;
//	List filteredList = w.filterByName(name);
//	filteredList.print();
//	//system("pause");
//}
//void filterByArticle(List& w) {
//	int article{};
//	std::cout << "input ARTICLE:\n";
//	std::cin >> article;
//	Item* foundedItem= w.findByArticle(article);
//	foundedItem->print();
//	//system("pause");
//}
//void filterByRemain(List& w) {
//	int remain{};
//	std::cout << "input REMAIN:\n";
//	std::cin >> remain;
//	List filteredList = w.filterByRemain(remain);
//	filteredList.print();
//	//system("pause");
//}
//void filtersMenu(List& w) {
//	const int menuSize{ 4 };
//	MenuItem a[menuSize]{ {"by NUM OF PARTY", filterByNumOfParty,&w},{"by NAME",filterByName,&w},{"by ARTICLE",filterByArticle,&w},{"by REMAIN",filterByRemain,&w} };
//	Menu q{ "Filter Menu",a,menuSize };
//	int filterDepth{};
//	while (q.runCommand());

//}

//void sortByName(List& w) {
//	w.sortByName();
//	w.print();
//	//system("pause");
//};
//void sortByRemain(List& w) {
//	w.sortByRemain();
//	w.print();
//	//system("pause");
//};
//void sortByDefinition(List& w) {
//	w.sortByDefinition();
//	w.print();
//	//system("pause");
//};
//void sortByTime(List& w) {
//	w.sortByTime();
//	w.print();
//	//system("pause");
//};
//void sortsMenu(List &w) {
//	const int menuSize{ 4 };
//	MenuItem a[menuSize]{ {"by NAME", sortByName,&w},{"by REMAIN",sortByRemain,&w},{"by DEFINITION",sortByDefinition,&w},{"by TIME",sortByTime,&w}};
//	Menu q{ "Sort Menu",a,menuSize };
//	while (q.runCommand());

//}

////int main()
////{
////	//setlocale(LC_ALL, "Russian");
////	std::vector<Item> TEST{ {1,"QEHTIOQHEGIQHEIPG",12,12,"12",12,12,12},{2,"?SADSDFQWEQWEAAF",12,12,"14",12,12,12},{3,"LSFHLFSDJLHLKSFJHG",12,12,"42",12,12,12},{4,"CAAA",12,12,"2",12,12,12} };
////	List w{TEST};
	
////	const int menuSize{ 7 };
////	MenuItem a[menuSize]{ {"Print", printList,&w},{"Add",menuFuncAdd,&w},{"Delete",menuFuncDelete,&w},{"Sort",sortsMenu,&w},{"Filter",filtersMenu,&w} ,{"Input txt file",menuFuncAddFromTxtFile,& w},{"Output txt file",MenuFuncOutTxtFile,&w}};
////		Menu q{ "my menu",a,menuSize };
////		while (q.runCommand());
////	return 0;
////}
///*enum Colour {
//	black,
//	dark_blue,
//	hacker_green,
//	light_blue,
//	red,
//	purple,
//	yellow,
//	white,
//	grey,
//	blue,
//	green,
//	cyan,
//	pink,
//	light_purple,
//	sand,
//	bright_white,
//	NUM_OF_COLOURS,
//};
//struct User
//{
//	char login[255]{};
//	char password[255]{};
//	bool isAdmin{ false };
//};
//struct Student
//{
//	int id{ 0 };
//	short age{ 0 };
//	short math{ 0 };
//	short eng{ 0 };
//	short physics{ 0 };
//	short graphics{ 0 };
//	short linearAlgebra{ 0 };
//	char firstname[255]{ "" };
//	char surname[255]{ "" };
//	char fathername[255]{ "" };
//	short course{ 0 };
//	short year_of_admission{ 1980 };


//};

////????? ???????
//int current_col{ white };
//void setcol(int x) {
//	HANDLE console_colour;
//	console_colour = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(console_colour, x);
//	current_col = x;
//};

////??????????
//void input(int&, int, int);
//void printFullLine(Student st);
//void printHeader();
//void printLine();

////???????????: ?????? ? ???-?? ?????? ????????????
//bool doubt(Student st)
//{
//	int choice{};
//	printHeader();
//	printFullLine(st);
//	printLine();
//	std::cout << "?? ??????? ? ????? ????????" << std::endl << "1. ??" << std::endl << "2. ???" << std::endl;
//	input(choice, 1, 2);
//	return (choice == 1);
//}
//void accessError()
//{
//	setcol(red);
//	std::cout << "Error: impossible access id";
//	exit(-1);
//};
//void fileOpenError()
//{
//	int temp = current_col;
//	setcol(red);
//	std::cout << "ERROR: Unable to open file" << std::endl;
//	std::system("pause");
//	setcol(temp);
//};
//void choiceError()
//{
//	setcol(red);
//	std::cout << "Error: impossible choice id";
//	exit(-2);
//};
//void invalidInput(int a, int b)
//{


//	if (std::cin.fail())
//	{
//		std::cin.clear();
//		std::cin.ignore(32767, '\n');
//	};
//	std::cout << std::endl;
//	int last_col{ current_col };
//	setcol(red);
//	std::cout << "???????? ????. ?????????? ????: ????? ????? ?? " << a << " ?? " << b << std::endl;
//	std::cout << "????????? ????: " << std::endl;
//	setcol(last_col);
//};
//short currentYear() {

//	short year{};
//	SYSTEMTIME sysTime;
//	GetSystemTime(&sysTime);
//	year = sysTime.wYear;
//	return year;
//}
//void reset(Student dataBase[], int& currentSize)
//{
//	Student null{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		dataBase[i] = null;
//	};
//	currentSize = 0;
//};



////?????? ?? ?????
//void lineBreak(char* line, int border) {
//	int a(strlen(line));
//	char outLine[255]{};
//	for (int i{}; i < a; ++i) {
//		if (i < border) {
//			outLine[i] = line[i];
//		}
//		if (i + border < a) line[i] = line[i + border];
//		else line[i] = '\0';
//	}
//	std::cout << outLine;
//};
//void printLine()
//{
//	std::cout << '+';
//	for (int i{ 0 }; i <= 170; ++i)
//		std::cout << '-';
//	std::cout << '+' << std::endl;
//};
//void printFullLine(Student st)
//{
//	std::cout << '+';
//	for (int i{ 0 }; i <= 170; ++i)
//		std::cout << '-';
//	std::cout << '+' << std::endl;
//	bool first{ true };
//	do
//	{
//		if (first)
//			std::cout << '|' << std::setw(5) << st.id;
//		else
//			std::cout << '|' << std::setw(5) << ' ';
//		std::cout << '|' << std::setw(15);
//		lineBreak(st.surname, 15);
//		std::cout << '|' << std::setw(15);
//		lineBreak(st.firstname, 15);
//		std::cout << '|' << std::setw(15);
//		lineBreak(st.fathername, 15);
//		if (first)
//			std::cout << '|' << std::setw(10) << st.age << '|' << std::setw(20) << st.course << '|' << std::setw(20) << st.year_of_admission << '|' << std::setw(10) << st.math << '|' << std::setw(10) << st.eng << '|' << std::setw(10) << st.physics << '|' << std::setw(10) << st.graphics << '|' << std::setw(20) << st.linearAlgebra << '|' << std::endl;
//		else
//			std::cout << '|' << std::setw(10) << ' ' << '|' << std::setw(20) << ' ' << '|' << std::setw(20) << ' ' << '|' << std::setw(10) << ' ' << '|' << std::setw(10) << ' ' << '|' << std::setw(10) << ' ' << '|' << std::setw(10) << ' ' << '|' << std::setw(20) << ' ' << '|' << std::endl;
//		first = false;

//	} while ((st.firstname[0] != '\0') || (st.surname[0] != '\0') || (st.fathername[0] != '\0'));
//};
//void printHeader()
//{
//	printLine();
//	std::cout << '|' << std::setw(5) << "id" << '|' << std::setw(15) << "???????" << '|' << std::setw(15) << "???" << '|' << std::setw(15) << "????????" << '|' << std::setw(10) << "???????" << '|' << std::setw(20) << "???? ????????" << '|' << std::setw(20) << "??? ???????????" << '|';
//	std::cout << std::setw(10) << "?????????" << '|' << std::setw(10) << "??????????" << '|' << std::setw(10) << "??????" << '|' << std::setw(10) << "???????" << '|' << std::setw(20) << "???????? ???????" << '|' << std::endl;
//};
//void printToScr(Student* dataBase, int currentSize)
//{
//	std::system("cls");
//	printHeader();
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		printFullLine(dataBase[i]);
//	};
//	printLine();
//	std::system("pause");
//};


////input-? ??????????
//void input(int& inp, int a, int b)
//{

//	bool goodInput{ false };
//	do
//	{
//		std::cin >> inp;
//		std::cin.ignore(32767, '\n');
//		if (std::cin.fail() || inp > b || inp < a)
//		{
//			invalidInput(a, b);
//		}
//		else
//		{
//			goodInput = true;
//		};
//	} while (!goodInput);
//	std::system("cls");
//};
//void input(short& inp, int a, int b)
//{

//	bool goodInput{ false };
//	do
//	{
//		std::cin >> inp;
//		std::cin.ignore(32767, '\n');
//		if (std::cin.fail() || inp > b || inp < a)
//		{
//			invalidInput(a, b);
//		}
//		else
//		{
//			goodInput = true;
//		};
//	} while (!goodInput);
//	std::system("cls");
//};
//void input(char* inp)
//{

//	bool goodInput{ false };
//	do
//	{
//		std::cin.getline(inp, 255, '\n');
//		if (std::cin.fail())
//		{
//			std::cin.ignore(32767, '\n');
//			std::cin.clear();
//			std::system("cls");
//			std::cout << "???????? ????? ????????. ????????? ?? ????? 254 ???????? (1 ?????? ????????? ????????? ?? 2 ???????)" << std::endl;
//			std::cout << "????????? ????:" << std::endl;
//		}
//		else
//		{
//			goodInput = true;
//		}
//	} while (!goodInput);
//	std::system("cls");

//};




////??????????
//void sortArrayBySurname(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			for (int k{ 0 }; k < min(strlen(dataBase[i].surname), strlen(dataBase[j].surname)); ++k)
//			{
//				if ((!reverse) ? (dataBase[i].surname[k] > dataBase[j].surname[k]) : (dataBase[i].surname[k] < dataBase[j].surname[k]))
//				{
//					temp = dataBase[i];
//					dataBase[i] = dataBase[j];
//					dataBase[j] = temp;
//					break;
//				}
//				else if ((!reverse) ? (dataBase[i].surname[k] < dataBase[j].surname[k]) : (dataBase[i].surname[k] > dataBase[j].surname[k]))
//					break;
//			};
//		};
//	};
//};
//void sortArrayByFatherName(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			for (int k{ 0 }; k < min(strlen(dataBase[i].fathername), strlen(dataBase[j].fathername)); ++k)
//			{
//				if ((!reverse) ? (dataBase[i].fathername[k] > dataBase[j].fathername[k]) : (dataBase[i].fathername[k] < dataBase[j].fathername[k]))
//				{
//					temp = dataBase[i];
//					dataBase[i] = dataBase[j];
//					dataBase[j] = temp;
//					break;
//				}
//				else if ((!reverse) ? (dataBase[i].fathername[k] < dataBase[j].fathername[k]) : (dataBase[i].fathername[k] > dataBase[j].fathername[k]))
//					break;
//			};
//		};
//	};
//};
//void sortArrayByFirstName(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			for (int k{ 0 }; k < min(strlen(dataBase[i].firstname), strlen(dataBase[j].firstname)); ++k)
//			{
//				if ((!reverse) ? (dataBase[i].firstname[k] > dataBase[j].firstname[k]) : (dataBase[i].firstname[k] < dataBase[j].firstname[k]))
//				{
//					temp = dataBase[i];
//					dataBase[i] = dataBase[j];
//					dataBase[j] = temp;
//					break;
//				}
//				else if ((!reverse) ? (dataBase[i].firstname[k] < dataBase[j].firstname[k]) : (dataBase[i].firstname[k] > dataBase[j].firstname[k]))
//					break;
//			};
//		};
//	};
//};
//void sortArrayById(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].id > dataBase[j].id) : (dataBase[i].id < dataBase[j].id))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortArrayByMath(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].math > dataBase[j].math) : (dataBase[i].math < dataBase[j].math))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortArrayByEng(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].eng > dataBase[j].eng) : (dataBase[i].eng < dataBase[j].eng))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortArrayByPhysics(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].physics > dataBase[j].physics) : (dataBase[i].physics < dataBase[j].physics))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortArrayByGraphics(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].graphics > dataBase[j].graphics) : (dataBase[i].graphics < dataBase[j].graphics))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortArrayByLinearAlgebra(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].linearAlgebra > dataBase[j].linearAlgebra) : (dataBase[i].linearAlgebra < dataBase[j].linearAlgebra))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortArrayByCourse(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].course > dataBase[j].course) : (dataBase[i].course < dataBase[j].course))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortArrayByAge(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].age > dataBase[j].age) : (dataBase[i].age < dataBase[j].age))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortArrayByYear(Student* dataBase, int currentSize, int reverse)
//{
//	Student temp{};
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		for (int j{ i }; j < currentSize; ++j)
//		{
//			if ((!reverse) ? (dataBase[i].year_of_admission > dataBase[j].year_of_admission) : (dataBase[i].year_of_admission < dataBase[j].year_of_admission))
//			{
//				temp = dataBase[i];
//				dataBase[i] = dataBase[j];
//				dataBase[j] = temp;
//			};
//		};
//	};
//};
//void sortBy(Student* dataBase, int currentSize)
//{
//	int choice{}, choice2{};
//	std::cout << "???????? ????, ?? ???????? ?????????? ?????????? (??????? ?????):" << std::endl;
//	std::cout << "1. Id" << std::endl << "2. ???????" << std::endl << "3. ???" << std::endl << "4. ????????" << std::endl << "5. ???? ????????" << std::endl << "6. ???????" << std::endl;
//	std::cout << "7. ??? ???????????" << std::endl << "8. ?????????????? ??????" << std::endl << "9. ?????????? ????" << std::endl;
//	std::cout << "10. ??????" << std::endl << "11. ?????????? ???????" << std::endl << "12. ???????? ???????" << std::endl;
//	input(choice, 1, 12);
//	std::cout << "? ??????? ??????????? ??? ?????????" << std::endl << "1. ???????????" << std::endl << "2. ????????" << std::endl;
//	input(choice2, 1, 2);
//	--choice2;
//	switch (choice)
//	{
//	case (1): sortArrayById(dataBase, currentSize, choice2); break;
//	case (2): sortArrayBySurname(dataBase, currentSize, choice2); break;
//	case (3): sortArrayByFirstName(dataBase, currentSize, choice2); break;
//	case (4): sortArrayByFatherName(dataBase, currentSize, choice2); break;
//	case (5): sortArrayByCourse(dataBase, currentSize, choice2); break;
//	case (6): sortArrayByAge(dataBase, currentSize, choice2); break;
//	case (7): sortArrayByYear(dataBase, currentSize, choice2); break;
//	case (8): sortArrayByMath(dataBase, currentSize, choice2); break;
//	case (9): sortArrayByEng(dataBase, currentSize, choice2); break;
//	case (10): sortArrayByPhysics(dataBase, currentSize, choice2); break;
//	case (11): sortArrayByGraphics(dataBase, currentSize, choice2); break;
//	case (12): sortArrayByLinearAlgebra(dataBase, currentSize, choice2); break;
//	default: exit(-1);
//	};
//	printToScr(dataBase, currentSize);
//	sortArrayById(dataBase, currentSize, 0);

//};

////??????????? ???????????? ????????
//Student* increaseSize(Student*& old, int& maxSize, int currentSize)
//{
//	Student* newArray = new Student[maxSize + 20]{};

//	for (int i{}; i < currentSize; ++i)
//	{
//		newArray[i] = old[i];
//	};
//	maxSize += 20;
//	delete[] old;
//	return newArray;
//}
//User* increaseUserSize(User*& old, int& maxUsers)
//{
//	User* newArray = new User[maxUsers + 10]{};
//	for (int i{ 0 }; i < maxUsers; ++i)
//	{
//		newArray[i] = old[i];
//	};
//	maxUsers += 20;
//	delete[] old;
//	return newArray;
//};

////??????????????
//void change(Student dataBase[], int currentSize, int currentId)
//{
//	std::system("cls");
//	int continueInput{ 0 }, id{}, reallyId{ -1 };
//	bool exist{ false };
//	do
//	{
//		std::cout << "??????? id ??????????? ????????:" << std::endl;
//		input(id, 1, currentId);
//		exist = false;
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (dataBase[i].id == id)
//			{
//				reallyId = i;
//				exist = true;
//			};
//		};
//		if (exist)

//		{
//			std::cout << "??????? ???????:" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].surname << std::endl;
//			input(dataBase[id].surname);
//			std::cout << "??????? ???:" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].firstname << std::endl;
//			input(dataBase[id].firstname);
//			std::cout << "??????? ????????:" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].fathername << std::endl;
//			input(dataBase[id].fathername);
//			std::cout << "??????? ??????? (0-100):" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].age << std::endl;
//			input(dataBase[id].age, 0, 100);
//			std::cout << "??????? ???? ???????? (1-6):" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].course << std::endl;
//			input(dataBase[id].course, 1, 6);
//			std::cout << "??????? ??? ??????????? (1900-" << currentYear() << "):" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].year_of_admission << std::endl;
//			input(dataBase[id].year_of_admission, 1900, currentYear());
//			std::cout << "??????? ?????????? ?? ??????????????? ??????? (0-100):" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].math << std::endl;
//			input(dataBase[id].math, 0, 100);
//			std::cout << "??????? ?????????? ?? ??????????? ????? (0-100):" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].eng << std::endl;
//			input(dataBase[id].eng, 0, 100);
//			std::cout << "??????? ?????????? ?? ?????? (0-100):" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].physics << std::endl;
//			input(dataBase[id].physics, 0, 100);
//			std::cout << "??????? ?????????? ?? ?????????? ??????? (0-100):" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].graphics << std::endl;
//			input(dataBase[id].graphics, 0, 100);
//			std::cout << "??????? ?????????? ?? ???????? ??????? (0-100):" << std::endl;
//			std::cout << "???????? ? ?????? ??????: " << dataBase[id].linearAlgebra << std::endl;
//			input(dataBase[id].linearAlgebra, 0, 100);
//		}
//		else
//		{
//			int temp = current_col;
//			setcol(red);
//			std::cout << "??????? ? ????? id ?? ?????????" << std::endl;
//			std::system("pause");
//			setcol(temp);
//		};
//		std::cout << "?????????? ????? (1 - ??????????/0 - ????????? ? ????????? ? ????)" << std::endl;
//		input(continueInput, 0, 1);

//	} while (continueInput);
//};
//void deleteStudent(Student* dataBase, int& currentSize, int currentId)
//{
//	std::system("cls");
//	int continueInput{ 0 }, id{}, reallyId{ -1 };
//	bool exist{ false };
//	do
//	{
//		std::cout << "??????? id ?????????? ????????:" << std::endl;
//		input(id, 1, currentId);
//		exist = false;

//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (dataBase[i].id == id)
//			{
//				reallyId = i;
//				exist = true;
//			};
//		};
//		if (exist)
//		{
//			if (doubt(dataBase[reallyId]))
//			{
//				for (int i{ reallyId }; i < currentSize; ++i)
//					dataBase[i] = dataBase[i + 1];
//				--currentSize;
//			}

//		}
//		else
//		{
//			int temp = current_col;
//			setcol(red);
//			std::cout << "??????? ? ????? id ?? ?????????" << std::endl;
//			std::system("pause");
//			setcol(temp);
//		};

//		std::cout << "?????????? ????????? (1/0)" << std::endl;
//		input(continueInput, 0, 1);

//	} while (continueInput);
//}
//void inputKeyboard(Student*& dataBase, int& currentSize, int& maxSize, int& currentId)
//{
//	std::system("cls");
//	int continueInput{ 0 };
//	do
//	{
//		if (currentSize >= maxSize - 1)
//			dataBase = increaseSize(dataBase, maxSize, currentSize);
//		dataBase[currentSize].id = currentId + 1;
//		std::cout << "??????? ???????:" << std::endl;
//		input(dataBase[currentSize].surname);
//		std::cout << "??????? ???:" << std::endl;
//		input(dataBase[currentSize].firstname);
//		std::cout << "??????? ????????:" << std::endl;
//		input(dataBase[currentSize].fathername);
//		std::cout << "??????? ??????? (0-100):" << std::endl;
//		input(dataBase[currentSize].age, 0, 100);
//		std::cout << "??????? ???? ???????? (1-6):" << std::endl;
//		input(dataBase[currentSize].course, 1, 6);
//		std::cout << "??????? ??? ??????????? (1900-" << currentYear() << "):" << std::endl;
//		input(dataBase[currentSize].year_of_admission, 1900, currentYear());

//		std::cout << "??????? ?????????? ?? ??????????????? ??????? (0-100):" << std::endl;
//		input(dataBase[currentSize].math, 0, 100);
//		std::cout << "??????? ?????????? ?? ??????????? ????? (0-100):" << std::endl;
//		input(dataBase[currentSize].eng, 0, 100);
//		std::cout << "??????? ?????????? ?? ?????? (0-100):" << std::endl;
//		input(dataBase[currentSize].physics, 0, 100);
//		std::cout << "??????? ?????????? ?? ?????????? ??????? (0-100):" << std::endl;
//		input(dataBase[currentSize].graphics, 0, 100);
//		std::cout << "??????? ?????????? ?? ???????? ??????? (0-100):" << std::endl;
//		input(dataBase[currentSize].linearAlgebra, 0, 100);
//		++currentSize;
//		++currentId;
//		std::cout << "?????????? ????? (1 - ??????????/0 - ????????? ? ????????? ? ????)" << std::endl;
//		input(continueInput, 0, 1);

//	} while (continueInput);
//};

////?????? ???????
//void findAverageByYear(Student* dataBase, int currentSize)
//{
//	int year{}, sum{}, count{};
//	std::system("cls");
//	std::cout << "??????? ????????? ???:" << std::endl;
//	input(year, 1900, currentYear());
//	printHeader();
//	for (int i{ 0 }; i < currentSize; ++i)
//	{
//		if (year == dataBase[i].year_of_admission)
//		{
//			printFullLine(dataBase[i]);
//			++count;
//			sum += dataBase[i].math + dataBase[i].eng + dataBase[i].graphics + dataBase[i].linearAlgebra + dataBase[i].physics;
//		};
//	};
//	printLine();
//	std::cout << std::endl << "??????? ???? ???????? ? ???? ???? ?????????????? ?????: " << sum * 0.2 / count << std::endl;
//	std::system("pause");
//}
//void convertToBin()
//{
//	char name[255]{};
//	std::cout << "??????? ?????? ???? ? ?????????? ????? (??????? ?????????? .txt): " << std::endl;
//	std::cin.getline(name, 255);
//	std::ifstream fileRead(name);
//	Student temp{}, null{};
//	if (fileRead.is_open())
//	{
//		std::cout << "??????? ?????? ???? ? ????????? ????? (??????? ?????????? .bin): " << std::endl;
//		std::cin.getline(name, 255);
//		std::ofstream fileWrite(name, std::ios::binary);
//		if (fileWrite.is_open())
//		{
//			while (!fileRead.eof())
//			{
//				fileRead >> temp.id >> temp.surname >> temp.firstname >> temp.fathername >> temp.age >> temp.course >> temp.year_of_admission >> temp.math >> temp.eng >> temp.physics >> temp.graphics >> temp.linearAlgebra;
//				fileWrite.write(reinterpret_cast<char*>(&temp), sizeof(Student));
//			};
//			fileWrite.close();
//		}
//		else
//			fileOpenError();
//		fileRead.close();
//	}
//	else
//		fileOpenError();
//};

////???????
//void filterBy(Student* dataBase, int currentSize, int choice)
//{
//	std::system("cls");
//	char standardChar[255]{};
//	int standardInt{};

//	std::cout << "???????, ???? ?????? ????????? ????: " << std::endl;
//	switch (choice)
//	{
//	case 1:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].id)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 2:
//	{
//		input(standardChar);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (!strcmp(standardChar, dataBase[i].surname))
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 3:
//	{
//		input(standardChar);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (!strcmp(standardChar, dataBase[i].firstname))
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 4:
//	{
//		input(standardChar);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (!strcmp(standardChar, dataBase[i].fathername))
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 5:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].age)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 6:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].course)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 7:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].year_of_admission)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 8:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].math)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 9:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].eng)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 10:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].physics)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 11:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].graphics)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	case 12:
//	{
//		input(standardInt, INT_MIN, INT_MAX);
//		printHeader();
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			if (standardInt == dataBase[i].linearAlgebra)
//				printFullLine(dataBase[i]);
//		};
//		printLine();
//		break;
//	};
//	};
//	std::system("pause");
//};
//void filter(Student* dataBase, int currentSize)
//{
//	std::system("cls");
//	int choice{};
//	std::cout << "??????? ???? ??????? (??????): " << std::endl;
//	std::cout << "1. id" << std::endl << "2. ???????" << std::endl << "3. ???" << std::endl << "4. ????????" << std::endl << "5. ???????" << std::endl << "6. ???? ????????" << std::endl << "7. ??? ???????????" << std::endl;
//	std::cout << "8. ?????????" << std::endl << "9. ?????????? ????" << std::endl << "10. ??????" << std::endl << "11. ?????????? ???????" << std::endl << "12. ???????? ???????" << std::endl;
//	input(choice, 1, 12);
//	filterBy(dataBase, currentSize, choice);
//}

////????? ? ??????
//void inputBin(Student*& dataBase, int& currentSize, int& maxSize, int& currentId)
//{
//	char name[255]{};
//	reset(dataBase, currentSize);
//	std::cout << "??????? ?????? ???? ? ?????: " << std::endl;
//	std::cin.getline(name, 255, '\n');
//	std::ifstream fileRead(name, std::ios::binary);
//	int& i = currentSize;
//	Student temp{};
//	if (fileRead.is_open())
//	{
//		while (fileRead.read(reinterpret_cast<char*>(&temp), sizeof(Student)))
//		{
//			if (i >= maxSize - 2)
//				dataBase = increaseSize(dataBase, maxSize, currentSize);
//			dataBase[i] = temp;
//			++i;

//		}
//		fileRead.close();
//	}
//	else fileOpenError();
//	currentId = dataBase[i - 1].id;
//}
//void inputTxt(Student*& dataBase, int& currentSize, int& maxSize, int& currentId, bool isStandard = false)
//{
//	char name[255]{};
//	reset(dataBase, currentSize);
//	if (!isStandard)
//	{
//		std::cout << "??????? ?????? ???? ? ?????: " << std::endl;
//		std::cin.getline(name, 255);
//	}
//	else
//	{
//		strcpy_s(name, "D:/example666.txt");
//	};
//	std::ifstream fileRead(name);
//	int& i = currentSize;
//	if (fileRead.is_open())
//	{
//		while (!fileRead.eof())
//		{
//			if (i >= maxSize - 1)
//				dataBase = increaseSize(dataBase, maxSize, currentSize);
//			fileRead >> dataBase[i].id >> dataBase[i].surname >> dataBase[i].firstname >> dataBase[i].fathername >> dataBase[i].age >> dataBase[i].course >> dataBase[i].year_of_admission >> dataBase[i].math >> dataBase[i].eng >> dataBase[i].physics >> dataBase[i].graphics >> dataBase[i].linearAlgebra;
//			++i;
//		};
//	}
//	else
//	{
//		fileOpenError();
//	};
//	currentId = dataBase[i - 1].id;
//	if (fileRead.is_open())
//		fileRead.close();
//};
//void inputFile(Student*& dataBase, int& currentSize, int& maxSize, int& currentId)
//{
//	int choice{};
//	std::system("cls");
//	std::cout << "???????? ??? ?????: ????????? ??? ????????? (??????)" << std::endl << "1. ?????????" << std::endl << "2. ????????" << std::endl;
//	input(choice, 1, 2);
//	switch (choice)
//	{
//	case 1:
//		inputTxt(dataBase, currentSize, maxSize, currentId);
//		break;
//	case 2:
//		inputBin(dataBase, currentSize, maxSize, currentId);
//		break;
//	default:
//		choiceError();
//		break;
//	}
//}


////?????? ? ????
//void printToBin(Student* dataBase, int currentSize)
//{
//	char fileName[255]{};
//	std::cout << "??????? ?????? ???? ? ????????? ????? ???????? (??????? ?????????? .bin): " << std::endl;
//	std::cin.getline(fileName, 255, '\n');
//	std::ofstream fileWrite(fileName, std::ios::binary);
//	if (fileWrite.is_open())
//	{
//		for (int i{ 0 }; i < currentSize; ++i)
//		{
//			fileWrite.write(reinterpret_cast<char*>(dataBase + i), sizeof(Student));
//			std::cout << i << ' ';
//		};
//		fileWrite.close();
//	}
//	else
//		fileOpenError();


//};
//void printToTxt(Student dataBase[], int currentSize)
//{
//	char fileName[255];
//	std::cout << "??????? ?????? ???? ? ????? ????????:" << std::endl;
//	std::cin.getline(fileName, 255);
//	std::ofstream fileWrite(fileName);
//	if (fileWrite.is_open())
//	{
//		for (int i{ 0 }; i < currentSize - 1; ++i)
//		{
//			fileWrite << std::setw(5) << dataBase[i].id << std::setw(15) << dataBase[i].surname << std::setw(15) << dataBase[i].firstname << std::setw(15) << dataBase[i].fathername << std::setw(10) << dataBase[i].age << std::setw(20) << dataBase[i].course << std::setw(20) << dataBase[i].year_of_admission << std::setw(10) << dataBase[i].math << std::setw(10) << dataBase[i].eng << std::setw(10) << dataBase[i].physics << std::setw(10) << dataBase[i].graphics << std::setw(20) << dataBase[i].linearAlgebra << std::endl;
//		};
//		int i = currentSize - 1;
//		fileWrite << std::setw(5) << dataBase[i].id << std::setw(15) << dataBase[i].surname << std::setw(15) << dataBase[i].firstname << std::setw(15) << dataBase[i].fathername << std::setw(10) << dataBase[i].age << std::setw(20) << dataBase[i].course << std::setw(20) << dataBase[i].year_of_admission << std::setw(10) << dataBase[i].math << std::setw(10) << dataBase[i].eng << std::setw(10) << dataBase[i].physics << std::setw(10) << dataBase[i].graphics << std::setw(20) << dataBase[i].linearAlgebra;

//		fileWrite.close();
//	}
//	else fileOpenError();
//};
//void printToFile(Student* dataBase, int currentSize)
//{
//	int choice{};
//	std::system("cls");
//	std::cout << "???????? ??? ?????: ????????? ??? ????????? (??????)" << std::endl << "1. ?????????" << std::endl << "2. ????????" << std::endl;
//	input(choice, 1, 2);
//	switch (choice)
//	{
//	case 1:
//		printToTxt(dataBase, currentSize);
//		break;
//	case 2:
//		printToBin(dataBase, currentSize);
//		break;
//	default:
//		choiceError();
//		break;
//	}
//}




////???? ???????????
//void registr(User*& userList, int& usersCount, int& usersMax, int& access)
//{
//	std::system("cls");
//	char login[255]{};
//	bool busy{ false };
//	do
//	{
//		busy = false;
//		std::cout << "??????? ???????? ?????: " << std::endl;
//		std::cin.getline(login, 255, '\n');
//		for (int i{ 0 }; i < usersCount; ++i)
//		{
//			if (!strcmp(login, userList[i].login))
//			{
//				busy = true;
//			}
//		}
//		if (!strcmp(login, ""))
//		{
//			busy = false;
//		}
//		else if (!busy)
//		{
//			if (usersCount >= usersMax)
//				userList = increaseUserSize(userList, usersMax);
//			strcpy_s(userList[usersCount].login, login);

//			std::cout << "??????? ???????? ??????: " << std::endl;
//			std::cin.getline(userList[usersCount].password, 255, '\n');
//			++usersCount;
//			access = 1;
//			busy = false;
//		}
//		else
//		{
//			std::system("cls");
//			std::cout << "???? ????? ??? ?????. ?????????? ?????. ????? ?????, ??????? ?????? ???? (??????? enter)" << std::endl;
//			busy = true;
//		};
//	} while (busy);
//}
//int authorize(User*& userList, int usersCount)
//{
//	std::system("cls");
//	char login[255]{};
//	char password[255]{};
//	bool exist{ false }, goodPassword{ false }, goodLogin{ false };
//	int access{ 0 }, ident{};
//	while (!goodLogin)
//	{
//		std::cout << "????? ?????????????? - admin" << std::endl;
//		std::cout << "??????? ????? (????? ?????, ??????? ?????? ????, ?.?. ??????? enter): ";
//		std::cin.getline(login, 255, '\n');
//		for (int i{ 0 }; i < usersCount; ++i)
//		{
//			if (!strcmp(login, userList[i].login))
//			{
//				exist = true;
//				ident = i;
//			}
//		};
//		if (exist)
//		{
//			goodLogin = true;
//			goodPassword = false;
//			while (!goodPassword)
//			{
//				std::cout << "?????? ?????????????? - password" << std::endl;
//				std::cout << "??????? ?????? (????? ?????, ??????? ?????? ????, ?.?. ??????? enter): ";
//				std::cin.getline(password, 255, '\n');
//				if (!strcmp(userList[ident].password, password))
//				{
//					if (userList[ident].isAdmin)
//					{
//						setcol(hacker_green);
//						std::cout << "You are welcome" << std::endl;
//					}
//					else
//						std::cout << "????? ??????????, " << login << std::endl;
//					Sleep(1000);
//					access = (userList[ident].isAdmin) ? (2) : (1);
//					goodPassword = true;
//				}
//				else if (!strcmp("", password))
//				{
//					goodPassword = true;
//					goodLogin = false;
//					std::system("cls");
//				}
//				else
//				{
//					std::system("cls");
//					std::cout << "???????? ??????. ??????????? ?????. " << std::endl;
//				};
//			};
//		}
//		else if (!strcmp(login, ""))
//		{
//			goodLogin = true;
//		}
//		else
//		{
//			std::system("cls");
//			std::cout << "???????????? ? ????? ??????? ?? ??????????. ??????????? ?????. " << std::endl;
//		};
//	};
//	return access;

//};

////????
//void mainMenuNotAuthorized(Student*& dataBase, User*& userList, int& usersCount, int& usersMax, int& access, bool& end)
//{
//	setcol(white);
//	int choice{};
//	std::system("cls");
//	std::cout << "???????? ???????? (??????):" << std::endl << "1. ??????????????" << std::endl << "2. ??????????????????" << std::endl << "3. ?????" << std::endl;
//	input(choice, 1, 3);
//	switch (choice)
//	{
//	case 1:

//		access = authorize(userList, usersCount);
//		break;

//	case 2:

//		registr(userList, usersCount, usersMax, access);
//		break;

//	case 3:

//		std::system("cls");
//		end = true;
//		break;
//	default:
//		choiceError();
//	};
//};
//void mainMenuAdmin(Student*& dataBase, int& currentSize, int& maxSize, int& access, bool& end, int& currentId)
//{
//	setcol(hacker_green);
//	int choice{};

//	std::system("cls");
//	std::cout << "???????? ???????? (??????):" << std::endl << "1. ??????????? ???????" << std::endl << "2. ????????????? ???? ??????" << std::endl << "3. ???????? ??????" << std::endl;
//	std::cout << "4. ???????? ??????" << std::endl << "5. ??????? ??????" << std::endl << "6. ???? ? ?????" << std::endl << "7. ????? ? ????" << std::endl << "8. ?????????????? ????????? ???? ? ????????" << std::endl << "9. ????????????? ???? ??????" << std::endl;
//	std::cout << "10. ??????? ???? ????????? ? ????" << std::endl << "11. ????? ?? ????????" << std::endl << "12. ????????? ??????" << std::endl;
//	input(choice, 1, 12);
//	std::system("cls");
//	switch (choice)
//	{
//	case 1:
//	{
//		printToScr(dataBase, currentSize);
//		break;
//	};
//	case 2:
//	{
//		sortBy(dataBase, currentSize);
//		break;
//	};
//	case 3:
//	{
//		inputKeyboard(dataBase, currentSize, maxSize, currentId);
//		break;
//	}
//	case 4:
//	{

//		change(dataBase, currentSize, currentId);
//		break;
//	};
//	case 5:
//	{
//		deleteStudent(dataBase, currentSize, currentId);
//		break;
//	};
//	case 6:
//	{
//		inputFile(dataBase, currentSize, maxSize, currentId);
//		break;
//	};
//	case 7:
//	{
//		printToFile(dataBase, currentSize);
//		break;
//	};
//	case 8:
//		convertToBin();
//		break;
//	case 9:
//	{
//		filter(dataBase, currentSize);
//		break;
//	};
//	case 10:
//	{
//		findAverageByYear(dataBase, currentSize);
//		break;
//	}
//	case 11:
//	{
//		access = 0;
//		break;
//	};
//	case 12:
//	{
//		end = true;
//		break;
//	};
//	default: choiceError();
//	};

//};
//void mainMenuUser(Student*& dataBase, int& currentSize, int& maxSize, int& access, bool& end, int& currentId)
//{
//	setcol(sand);
//	bool goodInput{ false };
//	int choice{};
//	std::system("cls");
//	std::cout << "???????? ???????? (??????):" << std::endl << "1. ??????????? ???????" << std::endl << "2. ????????????? ???? ??????" << std::endl << "3. ???? ?????? ?? ?????" << std::endl << "4. ????? ?????? ? ????" << std::endl << "5. ?????????????? ????????? ???? ? ????????" << std::endl << "6. ????????????? ??????" << std::endl << "7. ??????? ???? ???????? ? ????" << std::endl << "8. ????? ?? ????????" << std::endl << "9. ????????? ??????" << std::endl;
//	input(choice, 1, 9);
//	std::system("cls");
//	switch (choice)
//	{
//	case 1:
//	{
//		printToScr(dataBase, currentSize);
//		break;
//	};
//	case 2:
//	{
//		sortBy(dataBase, currentSize);
//		break;
//	};
//	case 3:
//	{
//		inputFile(dataBase, currentSize, maxSize, currentId);
//		break;
//	};
//	case 4:
//	{
//		printToFile(dataBase, currentSize);
//		break;
//	};
//	case 5:
//		convertToBin();
//		break;
//	case 6:
//	{
//		filter(dataBase, currentSize);
//		break;
//	};
//	case 7:
//	{
//		findAverageByYear(dataBase, currentSize);
//		break;
//	}
//	case 8:
//	{
//		access = 0;
//		break;
//	};
//	case 9:
//	{
//		end = true;
//		break;
//	};
//	default: choiceError();
//	};
//};


//int main()
//{
//	setcol(white);
//	std::system("cls");
//	setlocale(LC_ALL, "Russian");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	bool end{ false };
//	int access{ 0 };
//	Student* dataBase = new Student[255]{};
//	User* userList = new User[255]{ {"admin","password",1}, };
//	int currentSize{ 0 }, maxSize{ 255 }, usersCount{ 1 }, usersMax{ 255 }, currentId{ 0 };
//	std::cout << "???????????? ???? ?????? ?? ??????????" << std::endl;
//	std::cout << "1. ??" << std::endl << "0. ???" << std::endl;
//	int choice{};
//	input(choice, 0, 1);
//	if (choice)
//	{
//		inputTxt(dataBase, currentSize, maxSize, currentId, true);
//	};

//	while (!end)
//	{
//		switch (access)
//		{
//		case 0: mainMenuNotAuthorized(dataBase, userList, usersCount, usersMax, access, end); break;
//		case 1: mainMenuUser(dataBase, currentSize, maxSize, access, end, currentId); break;
//		case 2: mainMenuAdmin(dataBase, currentSize, maxSize, access, end, currentId); break;
//		default: accessError(); break;
//		};
//	};

//	return 0;
//};*/
