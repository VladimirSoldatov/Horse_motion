#include<iostream>
using namespace std;

void func(int (* massive)[]) {

}
struct Khod
{

};
void init_desk(int desk[][8])
{
	for (int i = 0; i < 8; i++)//Инициализировали
	{
		for (int j = 0; j < 8; j++)
		{
			desk[i][j] = 0;
		}
	}
}
void display(int mas[][8], int count, int x, int y)//Рисование доски
{
	system("cls");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout <<mas[i][j]<<"  ";
		}
		cout << "\n";
	}
	
	cout << '\n' << count << '\n';
	cout << '\n' << x<<"\t"<<y << '\n';
}
int random_number(int limit) 
{
	int number;
	srand((unsigned)time(NULL));
	number = rand() % (limit - 1);//number = 0 + rand(8 - 0);
	return number;
}
int mask[8][2]
{
	{-2, -1},
	{-2, 1},
	{-1, -2},
	{-1, 2},
	{1, -2},
	{1, 2},
	{2, -1},
	{2, 1}
};

bool test_free_space(int _x, int _y, int desk[][8])
{
	bool flag = false;
	for (int i = 0; i < 8; i++)
	{
		if (_x + mask[i][0] <= 7
			&& _x + mask[i][0] >= 0
			&& _y + mask[i][1] <= 7 
			&& _y + mask[i][1] >= 0
			&& desk[_x + mask[i][0]][_y + mask[i][1]] == 0)
		{
			flag = true;
			break;
		}


	}
	return flag;
}
int push_point(int& _x, int& _y, int desk[][8])
{
	int old_x = _x;
	int old_y = _y;
	int count = 0;
	int i; 
	while(test_free_space(_x,_y,desk))
	{
		i = random_number(8);
		if (_x + mask[i][0] <= 7
			&& _x + mask[i][0] >= 0
			&& _y + mask[i][1] <= 7
			&& _y + mask[i][1] >= 0
			&& desk[_x + mask[i][0]][_y + mask[i][1]] == 0)
		{
			_x += mask[i][0];
			_y += mask[i][1];
			desk[_x][_y] = 1;
			display(desk, count, _x, _y);
		
			count++;
		}

		
	}
	cout << count << '\n';

	system("pause");
	
	if (count < 60) 
	{
		init_desk(desk);
		push_point(old_x, old_y, desk);
	}


		return count;


}
void draw(int _x, int _y, int desk[][8])
{
	while (1)
	{
		push_point(_x, _y, desk);
		
		//display(desk);
	}
}

int main()
{
	int massive[8][8];//Создали статический массив 8х8
	init_desk(massive);
	int x = random_number(8);
	int y = random_number(8);
	massive[x][y] = 1;
	display(massive,0,0,0);
	draw(x, y, massive);
	

}
