#include <bits/stdc++.h>
using namespace std;
int isBinary(int n)
{
	while (n)
	{
		int x = n % 10;
		if (x * x != x)
			return 0;
		n /= 10;
	}
	return 1;
}
float afterPointHexToDec(string afterPoint)
{
	int lend = afterPoint.size();
	float dec_val = 0;
	for (int i = 0; i <= lend - 1; i++)
	{
		if (afterPoint[i] >= '0' && afterPoint[i] <= '9')
		{
			dec_val += (int(afterPoint[i]) - 48) * pow(16, -(i + 1));
		}
		else if (afterPoint[i] >= 'A' && afterPoint[i] <= 'F')
		{
			dec_val += (int(afterPoint[i]) - 55) * pow(16, -(i + 1));
		}
	}
	return dec_val;
}
string fracConversion(float f, int base)
{
	string str1 = "";
	while (f != 0.00)
	{
		f = f * base;
		int temp = f;
		f -= temp;
		str1 += to_string(temp);
	}
	return str1;
}
string fracToHexConversion(float f)
{
	string str1 = "";
	while (f != 0.00)
	{
		f = f * 16;
		int temp = f;
		f -= temp;
		if (temp == 10)
		{
			str1 += 'A';
		}
		else if (temp == 11)
		{
			str1 += 'B';
		}
		else if (temp == 12)
		{
			str1 += 'C';
		}
		else if (temp == 13)
		{
			str1 += 'D';
		}
		else if (temp == 14)
		{
			str1 += 'E';
		}
		else if (temp == 15)
		{
			str1 += 'F';
		}
		else
		{
			str1 += to_string(temp);
		}
	}
	return str1;
}
float fracToDecConversion(float x, int base)
{
	stringstream ss;
	ss << abs(x - (int)x);
	string s;
	ss >> s;
	int slen = s.length() - 2;
	for (int i = 0; i < slen; i++)
	{
		x = x * 10;
	}
	int tempNum = x;
	int m = slen;
	float place_Value = 0;
	while (tempNum)
	{
		int last_digit = tempNum % 10;
		tempNum = tempNum / 10;
		place_Value += (last_digit * pow(base, -m));
		m--;
	}
	return place_Value;
}
void decToBinary(int n, float f)
{
	int binaryNum[32];
	int i = 0;
	while (n > 0)
	{

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	string decBin = "";
	for (int j = i - 1; j >= 0; j--)
	{

		decBin += to_string(binaryNum[j]);
	}
	decBin = decBin + "." + fracConversion(f, 2);
	cout << decBin;
}
float binToDec(int n, float f)
{
	int num = n;
	int dec_value = 0;
	int base = 1;

	int temp = num;
	while (temp)
	{
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value + fracToDecConversion(f, 2);
}
void decToOct(int n, float f)
{
	int octNum[32];
	int i = 0;
	while (n > 0)
	{

		octNum[i] = n % 8;
		n = n / 8;
		i++;
	}
	string decOct = "";
	for (int j = i - 1; j >= 0; j--)
		decOct += to_string(octNum[j]);

	decOct = decOct + "." + fracConversion(f, 8);
	cout << decOct;
}
float octToDec(int n, float f)
{
	int num = n;
	int dec_value = 0;
	int base = 1;

	int temp = num;
	while (temp)
	{
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 8;
	}

	return dec_value + fracToDecConversion(f, 8);
}
float hexadecimalToDecimal(string hexVal, string afterPoint)
{
	int len = hexVal.size();
	int base = 1;

	float dec_val = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (hexVal[i] >= '0' && hexVal[i] <= '9')
		{
			dec_val += (int(hexVal[i]) - 48) * base;
			base = base * 16;
		}
		else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
		{
			dec_val += (int(hexVal[i]) - 55) * base;
			base = base * 16;
		}
	}
	return dec_val + afterPointHexToDec(afterPoint);
}
void decToHexa(int n, float f)
{
	int hexNum[32];
	int i = 0;
	while (n > 0)
	{

		hexNum[i] = n % 16;
		n = n / 16;
		i++;
	}
	string decHex = "";
	for (int j = i - 1; j >= 0; j--)
	{
		if (hexNum[j] == 10)
		{
			decHex += 'A';
		}
		else if (hexNum[j] == 11)
		{
			decHex += 'B';
		}
		else if (hexNum[j] == 12)
		{
			decHex += 'C';
		}
		else if (hexNum[j] == 13)
		{
			decHex += 'D';
		}
		else if (hexNum[j] == 14)
		{
			decHex += 'E';
		}
		else if (hexNum[j] == 15)
		{
			decHex += 'F';
		}
		else
		{
			decHex += to_string(hexNum[j]);
		}
	}
	decHex = decHex + "." + fracToHexConversion(f);
	cout << decHex;
}
int main()
{
	int t;
	do
	{
		cout << "***********************************************" << endl;
		cout << "          * 1. for decimal        *" << endl;
		cout << "          * 2. for binary         *" << endl;
		cout << "          * 3. for octal          *" << endl;
		cout << "          * 4. for hexadecimal    *" << endl;
		cout << "          * 5. for exit           *" << endl;
		cout << "***********************************************" << endl;
		cin >> t;
		float num;
		int n;
		if (t == 1)
		{
			cout << "enter decimal value : ";
			cin >> num;
			n = num;
			num -= n;
			cout << "decimal to binary is : ";
			decToBinary(n, num);
			cout << endl;
			cout << "decimal to octal is : ";
			decToOct(n, num);
			cout << endl;
			cout << "decimal to hexadecimal is : ";
			decToHexa(n, num);
			cout << endl;
		}
		else if (t == 2)
		{
			cout << "enter binary value : ";
			cin >> num;
			n = num;
			num -= n;
			cout << "binary to decimal is : " << binToDec(n, num) << endl;
			float z = binToDec(n, num);
			int l = z;
			z -= l;
			cout << z << "  " << l << endl;
			cout << "binary to octal is : ";
			decToOct(l, z);
			cout << endl;
			cout << "binary to hexadecimal is : ";
			decToHexa(l, z);
			cout << endl;
		}
		else if (t == 3)
		{
			cout << "enter octal value : ";
			cin >> num;
			n = num;
			num -= n;
			cout << "octal to decimal is : " << octToDec(n, num) << endl;
			float z = octToDec(n, num);
			int l = z;
			z -= l;
			cout << "octal to binary is : ";
			decToBinary(l, z);
			cout << endl;
			cout << "octal to hexadecimal is : ";
			decToHexa(l, z);
			cout << endl;
		}
		else if (t == 4)
		{
			cout << "enter hexadecimal value : ";
			string hex;
			cin >> hex;
			int m = hex.length();
			string hexValue = hex.substr(0, hex.find('.'));
			string afterPoint = hex.substr(hex.find('.') + 1, m);
			cout << "hexadecimal to decimal is : " << hexadecimalToDecimal(hexValue, afterPoint) << endl;
			float z = hexadecimalToDecimal(hexValue, afterPoint);
			int l = z;
			z -= l;
			cout << "Hexadecimal to binary is : ";
			decToBinary(l, z);
			cout << endl;
			cout << "Hexadecimal to octal is : ";
			decToOct(l, z);
			cout << endl;
		}
		else if (t == 5)
			cout << ".........exiting.........";
		else
		{
			cout << "enter a valid choice please" << endl;
		}
	} while (t != 5);
	cout << "\n\nNAME AND ID :: DHRUV DIGVIJAYSINH PUVAR AND 20CE117\n\n";
	return 0;
}
