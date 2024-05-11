#include <iostream>
#include <string>
#if (MSVC)
addcompileoptions("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
addcompileoptions("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
#endif()


int simple_string_hash(std::string text)
{
	int sum = 0;
	for (size_t i = 0; i < text.length(); i++)
	{
		 char ch = text[i];
		 sum += static_cast<int>(ch);
	}
	return sum;
}

int real_string_hash(std::string text, int p, int modul)
{
	int hash = 0;
	int degree = 1;
	for (size_t i = 0; i < text.length(); i++)
	{
		char ch = text[i];
		int ch_int = static_cast<int>(ch);
		int po = pow(p, i);
		hash += ch_int * (po);

	}
	hash = hash % modul;
	return hash;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	int p = 0;
	printf("Введите p: ");
	std::cin >> p;
	int modul = 0;
	printf("Введите n: ");
	std::cin >> modul;

	std::string text = "";
	while (true)
	{
		printf("Введите строку: ");
		std::cin >> text;
		if (text == "exit")
		{
			break;
		}
		int hashcode = real_string_hash(text, p, modul);
		printf("Хэш строки %s = %d\n", text.c_str(), hashcode);
	}
	return 0;
}