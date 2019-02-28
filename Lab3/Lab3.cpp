/* Новоселов Георгий, студент группы БИВ164. Лабораторная работа №3.
Вариант студента: 17
Варианты заданий: 3, 2.
Задание 1: Вариант 3. (1^n 0^m | n>m≥0);
Задание 2: Вариант 2. 1^n0^m1^n0^m  в  1^m0^(m+n), n>0, m>0 (разрешается использование нескольких стеков);
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>

class MPAuto {
protected:
	std::vector<std::string> letters;
	std::vector<std::string> magsymb;
	std::stack<char> stack;
	std::string line;
	std::string output;
	short accept = 0;

	virtual int CheckLine(std::string *str);

public:
	MPAuto();
	~MPAuto() {}
	void Accept();                        // Принять
	void Cancel();                        // Отвергнуть
	void GoFwd();                         // Сдвиг
	void Wait();                          // Удержать
	void Pop();                           // Вытолкнуть
	void Push(char ch);		              // Втолкнуть()
	void Exchange(std::string str);       // Заменить()
	int GetLine();
	void PushLetters(std::vector<std::string> str);
	void PushMagSymbols(std::vector<std::string> str);
	virtual int Work() = 0;
};

MPAuto::MPAuto() {
	stack.push('^');
	magsymb.push_back("^");
}

void MPAuto::Accept() {
	accept = 1;
}


void MPAuto::Cancel() {
	accept = -1;
}

void MPAuto::GoFwd() {
	line.erase(0, 1);
}

void MPAuto::Wait() {
	return;
}

void MPAuto::Pop() {
	stack.pop();
}

void MPAuto::Push(char ch) {
	stack.push(ch);
}

void MPAuto::Exchange(std::string str) {
	Pop();
	for (unsigned i = 0; i < str.length(); ++i)
		Push(str[i]);
}



int MPAuto::CheckLine(std::string *str) {
	for (unsigned i = 0; i < str->length(); ++i)
		if ((*str)[i] != '1' || (*str)[i] != '0')
			return 0;
	return 1;
}

int MPAuto::GetLine() {
	std::string str;
	std::getline(std::cin, str);
	if (CheckLine(&str)) {
		line = str;
		return 1;
	}
	else return 0;
}

void MPAuto::PushLetters(std::vector<std::string> str) {
	for (unsigned i = 0; i < str.size(); ++i)
		letters.push_back(str[i]);
}


void MPAuto::PushMagSymbols(std::vector<std::string> str) {
	for (unsigned i = 0; i < str.size(); ++i)
		magsymb.push_back(str[i]);

}


class MPAuto1 : virtual public MPAuto {
private:



public:
	MPAuto1() {}
	~MPAuto1() {}

	int Work();
};

MPAuto1::MPAuto1() {
	std::vector<std::string> str;
	str.push_back("0");
	str.push_back("1");
	PushLetters(str);
	str.clear();
	str.push_back("Z");
	str.push_back("A");
	PushMagSymbols(str);
}

int MPAuto1::Work() {


	return 1;
}




class MPAuto2 : virtual public MPAuto {
private:
	void ToPrint(char ch);  // Выдать() 
	int CheckLine(std::string *str);
public:
	MPAuto2();
	~MPAuto2() {}

	int GetLine();
	int Work();
};


MPAuto2::MPAuto2() {
	std::vector<std::string> str;
	str.push_back("0");
	str.push_back("1");
	PushLetters(str);
	str.clear();
	str.push_back("Z");
	str.push_back("A");
	str.push_back("B");
	PushMagSymbols(str);
}

int MPAuto2::CheckLine(std::string *str) {
	for (unsigned i = 0; i < str->length(); ++i)
		if ((*str)[i] != '1' || (*str)[i] != '0')
			return 0;



	return 1;
}

int MPAuto2::GetLine() {
	std::string str;
	std::getline(std::cin, str);
	if (CheckLine(&str)) {
		line = str;
		return 1;
	}
	else return 0;
}


void MPAuto2::ToPrint(char ch) {
	output.push_back(ch);
}


int MPAuto2::Work() {


	return 1;
}


int main()
{
	int again = 1;
	MPAuto* Auto;
	do {
		char mode = 0;
		std::cout << "What task do you want to check? (1/2)" << std::endl;
		std::cin >> mode;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (mode == '2') {
			std::cout << "Ok, task #2." << std::endl;
			Auto = new MPAuto2();
		}
		else {
			if (mode != '1')
				std::cout << "You gave me incorrect symbol! So ok, it will be task #1." << std::endl;
			else
				std::cout << "Ok, task #1." << std::endl;
			Auto = new MPAuto1();
		}

		std::cout << "Give me the expression. Use only 0 and 1." << std::endl;

		while (!Auto->GetLine())
			std::cout << "Incorrect line for this task!\nGive me the expression. Use only 0 and 1." << std::endl;

		int result = Auto->Work();
		if (!result)
			std::cout << "Your line doesn't fit our task." << std::endl;
		else {

			std::cout << "Your line is good! Congrats!" << std::endl;
		}


		std::cout << "Again? (1/0)" << std::endl;
		std::cin >> again;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
	} while (again);

	std::cout << "Okay, Good Bye!" << std::endl;
	system("Pause");
	return 0;
}

