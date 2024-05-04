#include <iostream>
#include <string>

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

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	std::string text = "";
	while (true)
	{
		printf("Введите строку: ");
		std::cin >> text;
		if (text == "exit")
		{
			break;
		}
		int hashcode = simple_string_hash(text);

		printf("Наивный хэш строки %s = %d\n", text.c_str(), /*std::to_string(*/ hashcode/*).c_str()*/);
	}
	return 0;
}