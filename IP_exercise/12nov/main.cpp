#include <iostream>
#include <ctime>

int getTurnInput(bool isAFirst, const int MAX)
{
	int turn;
	std::cout << "It's player " << (isAFirst ? 'A' : 'B') << "'s turn: ";
	do {
		std::cin >> turn;
		if (turn < 1 || turn>MAX)
			std::cout << "Move must be between 1 and " << MAX << " to the right!\n";
	} while (turn < 1 || turn>MAX);
	return turn;
}



void playGame()
{
	const int MAX = 256;
	const int JUMPLIMIT = 3;
	const int MAX_MOVE = 6;
	unsigned N;
	int posA = 0, posB = 0;
	bool isAFirst = true;
	int field[MAX];
	bool arrUndiscovered[MAX];
	std::cout << "Enter size of tunnel: ";
	std::cin >> N;
	for (unsigned i = 0; i < N; ++i) {
		field[i] = (!i ? 0 : rand() % (2 * JUMPLIMIT + 1) - JUMPLIMIT);
		if (!i) std::cout << "-> ";
		else	std::cout << field[i] << ' ';
		arrUndiscovered[i] = true;
	}
	std::cout << "->\n";
	isAFirst = rand() % 2;

	do {
		posA += getTurnInput(isAFirst, MAX_MOVE);
		if (posA < N && arrUndiscovered[posA]) {
			arrUndiscovered[posA] = false;
			posA += field[posA];
			if (posA < 0)posA = 0;
		}
		if (posA < N) {
			posB += getTurnInput(!isAFirst, MAX_MOVE);
			if (posB < N && arrUndiscovered[posB]) {
				arrUndiscovered[posB] = false;
				posB += field[posB];
				if (posB < 0)posB = 0;
			}
		}
	} while (posA < N && posB < N);
	std::cout << "Player " <<
		(posA < N - 1 ? (isAFirst ? 'B' : 'A') : (isAFirst ? 'A' : 'B'))
		<< " wins!\n";
}

void generateGame()
{
	const int MAX = 20;
	const int MIN = 6;
	const int JUMPLIMIT = 3;
	const int MAX_MOVE = 6;
	unsigned int N;
	int pos = 0;
	int field[MAX];
	bool isBlocking[MAX];
	N = rand() % (MAX - MIN + 1) + MIN;
	std::cout << "The tunnel:\n";
	for (int i = 0; i < N; ++i) {
		field[i] = (!i ? 0 : rand() % (2 * JUMPLIMIT + 1) - JUMPLIMIT);
		if (!i)	std::cout << "-> ";
		else	std::cout << field[i] << ' ';
		isBlocking[i] = false;
	}
	isBlocking[0] = true;
	std::cout << "->\n";
	for (int i = 1; i <= MAX_MOVE; ++i)
	{
		for (int j = 1; j < N; ++j)isBlocking[j] = false;
		pos = i;
		while (pos < N && !isBlocking[pos]) {
			isBlocking[pos] = true;
			pos += field[pos];
			if (pos < 0)pos = 0;
		}
		if (pos >= N)
		{
			std::cout << "Possible when starting with " << i << std::endl;
			return;
		}

	}
	std::cout << "It's impossible\n";
}

int main()
{
	srand(time(0));
	int action = 0;
	do {
		std::cout << "Enter 1 to play a game or 2 to simulate a game.\n";
		std::cin >> action;
		if (action == 1)
			playGame();
		else if (action == 2)
			generateGame();
	} while (action == 1 && action == 2);
	return 0;
}