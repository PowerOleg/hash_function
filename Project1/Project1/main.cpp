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

int real_string_hash(std::string text, int p, int modul)
{
	int hash = 0;
	for (size_t i = 0; i < text.length(); i++)
	{
		char ch = text[i];
		int ch_int = static_cast<int>(ch);
		int po = pow(p, i);
		hash += ch_int * (po);
		std::cout << "string hash: " << ch_int * (po) << std::endl;
	}
	hash = hash % modul;
	return hash;
}

int symbol_hash(char symbol)
{
	return static_cast<int>(symbol);
}


int find_substring_light_rabin_karp(std::string text, std::string search)
{
	int hash = simple_string_hash(search);
	int s = text.length();
	int k = search.length();
	int h = 0;
	bool is_equal = true;
	std::string substring = "";
	for (size_t i = 0; i < s; i++)
	{
		if (i == 0)
		{
			substring = text.substr(0, k);
			h = simple_string_hash(substring);
		}
		else
		{
			char symbol = text[i - 1];
			int substruct_first = symbol_hash(symbol);
			h -= substruct_first;
			int new_symbol_index = i - 1 + k;
			if (new_symbol_index >= s)
			{
				return -1;
			}
			char new_symbol = text[new_symbol_index];
			int substruct_end = symbol_hash(new_symbol);
			h += substruct_end;
		}
			
		if (hash != h)
		{
			is_equal = false;
		}
		else
		{
			for (size_t j = 0, l = i; j < k; j++, l++)
			{
				if (search[j] != text[l])
				{
					is_equal = false;
					break;
				}
				is_equal = true;
			}

			if (is_equal)
			{
				return i;
			}
		}
	}
	return -1;
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	std::string text = "";
	printf("Введите строку, в которой будет осуществляться поиск: ");
	std::cin >> text;
	while (true)
	{
		std::string search = "";
		printf("Введите подстроку, которую нужно найти: ");
		std::cin >> search;
		if (search == "exit")
		{
			break;
		}
		int index = find_substring_light_rabin_karp(text, search);
		if (index == -1)
		{
			printf("Подстрока %s не найдена\n", search.c_str());
		}
		else
		{
			printf("Подстрока %s найдена по индексу %d\n", search.c_str(), index);
		}
		
	}
	return 0;
}