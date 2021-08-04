#include <iostream>

int InputFromUser();
void Hanoi(int disk, char from, char temp, char to);
void Move(int disk, char from, char to);

int main()
{
	// ������ ���� �Է�
	int count = InputFromUser();

	// �ϳ��� Ǯ��
	Hanoi(count, 'A', 'B', 'C');
}

int InputFromUser()
{
	int n{};

	std::cout << "< �ϳ����� ž >" << std::endl;
	std::cout << "1. �� ���� �ϳ��� ���Ǹ� �ű� �� �ִ�." << std::endl;
	std::cout << "2. ū ������ ���� ���� ���� ���� �� ����." << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "������ ������ �Է��ϼ���. : ";
	std::cin >> n;

	return n;
}

// 
void Move(int disk, char from, char to)
{
	static int moveCount{ 0 };
	moveCount++;
	std::cout << moveCount << " : " << from << "���� " << to << "�� ����" << disk << "�� �ű�ϴ�." << std::endl;
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