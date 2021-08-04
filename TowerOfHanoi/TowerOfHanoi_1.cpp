#include <iostream>

int InputFromUser();
void Hanoi(int disk, char from, char temp, char to);
void Move(int disk, char from, char to);

int main()
{
	// 원반의 개수 입력
	int count = InputFromUser();

	// 하노이 풀이
	Hanoi(count, 'A', 'B', 'C');
}

int InputFromUser()
{
	int n{};

	std::cout << "< 하노이의 탑 >" << std::endl;
	std::cout << "1. 한 번에 하나의 원판만 옮길 수 있다." << std::endl;
	std::cout << "2. 큰 원판이 작은 원판 위에 있을 수 없다." << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "원판의 개수를 입력하세요. : ";
	std::cin >> n;

	return n;
}

// 
void Move(int disk, char from, char to)
{
	static int moveCount{ 0 };
	moveCount++;
	std::cout << moveCount << " : " << from << "에서 " << to << "로 원판" << disk << "을 옮깁니다." << std::endl;
}


void Hanoi(int disk, char from, char temp, char to)
{
	if (disk == 1)
	{
		Move(disk, from, to);
	}
	else
	{
		Hanoi(disk - 1, from, to, temp);
		Move(disk, from, to);
		Hanoi(disk - 1, temp, from, to);
	}
}