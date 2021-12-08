#include <iostream>
#include <cstring>

void reverse(char str[], unsigned start, unsigned end)
{
	unsigned l = (end - start + 1) / 2;
	for (unsigned i = 0; i < l; ++i)
	{
		char tmp=str[start+i];
		str[start + i] = str[end - i];
		str[end - i] = tmp;
	}
}

void reverse_words(char sentence[])
{
	unsigned wStart = 0, wEnd = 0, l = strlen(sentence);
	while (wEnd < l - 1)
	{
		while (sentence[wEnd + 1] != ' ' && sentence[wEnd + 1] != 0)
			++wEnd;
		reverse(sentence, wStart, wEnd);
		wStart = wEnd = wEnd + 2;
	}
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

void run_length_decode(char str[], char code[])
{
	unsigned i = 0, l = strlen(code);
	unsigned strL = 0;
	while (i < l)
	{
		unsigned num = 0;
		while (isDigit(code[i]))
		{
			num *= 10;
			num += code[i++] - '0';
		}
		str[strL++] = code[i];
		if(num>1)
			for (unsigned j = 0; j < num - 1; ++j)
				str[strL++] = code[i];
		++i;
	}
	str[strL] = 0;
}

int main()
{
	const unsigned MAX = 100;
	char str[MAX + 1];
	char code[] = "a10b3c";
	std::cin.getline(str, MAX + 1);
	reverse_words(str);
	std::cout << str << '\n';
	run_length_decode(str, code);
	std::cout << str << '\n';
	return 0;
}