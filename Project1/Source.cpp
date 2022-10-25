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
	cout << " " << " 1 2 3 4 5 6 7 8\n";
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1<<" ";
		for (int j = 0; j < 8; j++)
		{
			cout  << mas[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << '\n' << count << '\n';
	cout << '\n' << x +1<<"\t"<<y + 1 << '\n';
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
	{-2, 1 },
	{-1, -2},
	{-1, 2},
	{1, -2},
	{1, 2},
	{2, -1},
	{2, 1 }
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
			&& desk[_x + mask[i][0]][_y + mask[i][1]] != 1)
		
			return true;



	}
	return false;
}
void clear_temp(int temp[]) 
{
	for (int i = 0; i < 8; i++) 
	{
		temp[i] = 0;
	}
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
		static int iter = 0;
		if (
			_x + mask[i][0] <= 7
			&& _x + mask[i][0] >= 0
			&& _y + mask[i][1] <= 7
			&& _y + mask[i][1] >= 0
			&& desk[_x + mask[i][0]][_y + mask[i][1]] == 0
			)
		{
	
				_x += mask[i][0];
				_y += mask[i][1];
				desk[_x][_y] = 1;
				count++;

				display(desk, count, _x, _y);
		
		}



		
	}
	cout << count << '\n';

	//system("pause");
	



		return count;


}
void draw(int _x, int _y, int desk[][8])
{
	int count = 0;
	while (count<40)
	{
		init_desk(desk);
		desk[_x][_y] = 1;
		count = push_point(_x, _y, desk);
		
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
