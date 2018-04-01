#pragma once
struct roman
{
	int key;
	char letter;
	roman(int key, char letter)
	{
		this->key = key;
		this->letter = letter;
	}
	roman() {}
	roman operator()(int key, char letter)
	{
		return roman(key, letter);
	}
};
class convertToRoman
{
private:
	roman arr[7];
public:
	convertToRoman() :arr()
	{
		arr[0] = arr[0](1, 'I');
		arr[1] = arr[1](5, 'V');
		arr[2] = arr[2](10, 'X');
		arr[3] = arr[3](50, 'L');
		arr[4] = arr[4](100, 'C');
		arr[5] = arr[5](500, 'D');
		arr[6] = arr[6](1000, 'M');
	}

	roman find_(int k)
	{
		for (int i = 0; i < 7; ++i)
		{
			if (arr[i].key == k)
			{
				return arr[i];
			}
		}
		return roman(0, '0');
	}
	void foo(int n, int step, char symbol, int base, int f, string& str)
	{
		int i;
		roman temp;
		if (symbol == '*')
		{
			for (i = 0; i < f; ++i)
			{
				temp = find_(base*step);
				str += temp.letter;
			}
		}
		else
		{
			if (symbol == '+')
			{
				temp = find_((n - f)*step);
				str += temp.letter;
				for (i = 0; i < f; ++i)
				{
					temp = find_(step);
					str += temp.letter;
				}
			}
			else
			{
				temp = find_(step);
				str += temp.letter;
				temp = find_(n*step + step);
				str += temp.letter;
			}
		}
	}
	int order(int number)
	{
		int len = 0;
		while (number / 10)
		{
			++len;
			number /= 10;
		}
		return len;
	}
	char get_symbol(int n, int& base, int& f)
	{
		if (n <= 3 || n == 5)
		{
			base = 1;
			f = n;
			if (n == 5)
			{
				base = 5;
				f = 1;
			}
			return '*';
		}
		if (n == 4 || n == 9)
		{
			f = 1;
			return '-';
		}
		f = n - 5;
		return '+';
	}
	string get_number(int number)
	{
		char symbol;
		int f = 0, base = 0;
		int step = 0;
		int n = 0, i = 0, p = order(number);
		string str;
		step = int(pow(10, p));
		n = number / step;
		while (i <= p)
		{
			n = number / step;
			if (n == 0)
			{
				++i;
			}
			symbol = get_symbol(n, base, f);
			foo(n, step, symbol, base, f, str);
			number = number % step;
			step /= 10;
			while (number < step)
			{
				++i;
				step /= 10;
			}
			++i;
		}
		return str;
	}
};
