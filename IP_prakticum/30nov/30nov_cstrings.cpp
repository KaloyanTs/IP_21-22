#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
const unsigned MAX = 128;

char upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 'A';
	return c;
}

void uppercase(char s[])
{
	unsigned i = 0;
	while (s[i])
	{
		s[i] = upper(s[i]);
		++i;
	}

}

void reverse(char str[])
{
	unsigned len = strlen(str);
	for (unsigned i = len / 2 - 1; i < len /* <=> i >= 0 */; --i)
	{
		char tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
}

bool isPalindrome(const char str[])
{
	unsigned l = strlen(str), i = l / 2 - 1;
	while (i < l && str[i] == str[l - 1 - i])
		--i;
	return i >= l;	// <=> i < 0
}

unsigned Atoi(const char str[])
{
	unsigned res = 0, i = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i++] - '0';
	}
	return res;
}

void capitalWords(char str[])
{
	str[0] = upper(str[0]);
	for (unsigned i = 0; str[i]; ++i)
	{
		if (str[i] == ' ')
			str[i + 1] = upper(str[i + 1]);
	}
}

bool isBreaker(char c)
{
	char breakers[] = ".?! /\\\"\',;:()-[]{}\0"; //поне най-често срещаните
	return strchr(breakers, c) != nullptr;
}

unsigned wordsInSentence(const char str[], char words[][MAX + 1])
{
	unsigned wordsCount = 0, i = 0;
	do{
		unsigned currentWord = '\0';
		while (!isBreaker(str[i]))
			words[wordsCount][currentWord++] = str[i++];
		if(currentWord>0)
			words[wordsCount++][currentWord] = '\0';
	} while (str[i++] != 0);
	return wordsCount;
}

int main()
{
	char str[MAX + 1], strCopy[MAX + 1],wordsInStr[MAX/2][MAX+1];
	std::cin.getline(str, MAX + 1);
	strcpy(strCopy, str);
	uppercase(strCopy);
	std::cout << "Uppercase: " << strCopy << '\n';
	strcpy(strCopy, str);
	reverse(strCopy);
	std::cout << "Reversed: " << strCopy << '\n';
	std::cout << "The string is " 
			  << (isPalindrome(str) ? "" : "NOT ") << "a palindrome.\n";
	std::cout << "The string to integer: " << Atoi(str) << '\n';
	strcpy(strCopy, str);
	capitalWords(strCopy);
	std::cout << "Words starting with capital letter: " << strCopy << '\n';
	unsigned wCount = wordsInSentence(str, wordsInStr);
	for (unsigned i = 0; i < wCount; ++i)
		std::cout << wordsInStr[i] << '\n';
	return 0;
}