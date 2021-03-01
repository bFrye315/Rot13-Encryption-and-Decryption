#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//variables setup
	string InputFileName, OutputFileName, LineData;
	char answer;
	char letter;
	const char ENCRYPTION = 'E';
	const char DECRYPTION = 'D';
	const char QUIT = 'Q';
	const int ROT13 = 13;


	cout << "Please select a function:" << endl;
	cout << "E for Encryption \nD for Decrytion \nQ for Quit" << endl;
	cout << endl;

	cin >> answer;
	cout << endl;

	//getting file names
	do
	{
		ifstream inFile;
		ofstream outFile;

		if (answer == ENCRYPTION)
		{
			cout << "Input File Name (case sensitive, include extension): ";
			cin >> InputFileName;
			cout << "Output File Name (case sensitive, include extension): ";
			cin >> OutputFileName;

			inFile.open(InputFileName);
			outFile.open(OutputFileName);
			while (getline(inFile, LineData))
			{
				for (int i = 0; i < LineData.length(); i++)
				{
					letter = LineData[i];
					if (letter >= 97 && letter <= 122)
					{
						if (letter >= 110)
						{
							letter = letter - ROT13;
							outFile << letter;
						}
						else
						{
							letter = letter + ROT13;
							outFile << letter;
						}
					}
					else if (letter >= 65 && letter <= 90)
					{
						if (letter >= 78)
						{
							letter = letter - ROT13;
							outFile << letter;
						}
						else
						{
							letter = letter + ROT13;
							outFile << letter;
						}
					}
					else
					{
						outFile << letter;
					}

				}
				outFile << endl;
			}
			cout << endl;
			cout << "Encryption complete." << endl;
			cout << "Please select a function:" << endl;
			cout << "E for Encryption \nD for Decrytion \nQ for Quit" << endl;
			cout << endl;

			cin >> answer;
			cout << endl;
		}
		else if (answer == DECRYPTION)
		{
			cout << "Input File Name (case sensitive, include extension): ";
			cin >> InputFileName;
			cout << "Output File Name (case sensitive, include extension): ";
			cin >> OutputFileName;

			inFile.open(InputFileName);
			outFile.open(OutputFileName);
			while (getline(inFile, LineData))
			{
				for (int i = 0; i < LineData.length(); i++)
				{
					letter = LineData[i];
					if (letter >= 'a' && letter <= 'z')
					{
						if (letter >= 'n')
						{
							letter = letter - ROT13;
							outFile << letter;
						}
						else
						{
							letter = letter + ROT13;
							outFile << letter;
						}
					}
					else if (letter >= 'A' && letter <= 'Z')
					{
						if (letter >= 'N')
						{
							letter = letter - ROT13;
							outFile << letter;
						}
						else
						{
							letter = letter + ROT13;
							outFile << letter;
						}
					}
					else
					{
						outFile << letter;
					}

				}
				outFile << endl;
			}
			cout << endl;
			cout << "Decryption complete." << endl;
			cout << "Please select a function:" << endl;
			cout << "E for Encryption \nD for Decrytion \nQ for Quit" << endl;
			cout << endl;

			cin >> answer;
			cout << endl;
		}
		else if (answer == QUIT)
		{
			break;
		}
		else
		{
			cout << "An invalid answer was entered, please try again." << endl;
			cout << "Please select a function:" << endl;
			cout << "E for Encryption \nD for Decrytion \nQ for Quit" << endl;
			cout << endl;

			cin >> answer;
			cout << endl;
		}
		inFile.close();
		outFile.close();
	} while (answer != QUIT);
	return 0;
}