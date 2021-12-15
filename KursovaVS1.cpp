#include <iostream>
#include <string>
#include <fstream>// підключаєм всі необхідні бібліотеки
#include <vector>
#include <cstdlib>
#include<iomanip>
#include "GetNumException.h"// підключаю свої бібліотеки
#include "GetStringWithoutNum.h"

using namespace std;

class Database
{
protected:
	int size2,size3; //робимо глобальні змінні які будем використовувати в подальших ф-ціях

	struct Data
	{
		string FirstName = " ";// ініціалізовую та обнуляю значення змінних
		string SecondName = " ";
		string SurName = " ";
		string City = " ";
		int Year = 0;
		int Month = 0;
		int PastTime = 0;
		int Expancious = 0;
		int TopOfCity = 0;
	};
	
	vector<Data> dabase = DB();// створюю вектор типу структури

public:

	void GetLineNum2()  // Функція в якій я отримую к-сть рядків в файлі
	{
		ifstream file("DataBase.txt");
		char num[256];
		size2 = 0;

		while (file.getline(num, 256))
		{
			size2++;
		}
		file.close();
	}

	void ReserveBase() // функція яка перевіряє наявність файлу та створює резервний якщо його немає
	{
		ifstream fin;
		fin.open("DataBase.txt");
		if (!fin.is_open())
		{
			ofstream fout;
			fout.open("DataBase.txt");
			DB();
			fout.close();
		}
		fin.close();
	}

	vector<Data> DB() //Ф-ція типу вектора, яка записує інформаццію з файла
	{
		ReserveBase();
		ifstream fin;
		fin.open("DataBase.txt");
		GetLineNum2();
		vector<Data> Dab(size2);
		for (int i = 0; i < Dab.size(); i++)
		{
			fin >> Dab[i].FirstName >> Dab[i].SecondName >> Dab[i].SurName  >> Dab[i].Year >> Dab[i].Month >> Dab[i].PastTime >> Dab[i].City >> Dab[i].Expancious;
		}
		return Dab;
	}

	void EditWorker() // ф-ція редагування працівника
	{
		int k = 0;
		int k2 = 0;
		int chs1, chs2, vallue = 0;
		string Fname1 = " ";
		string Sname1 = " ";
		string Suname1 = " ";
		string Cty1 = " ";
		int yr1 = 0;
		int Mnth1 = 0;
		int Ptime1 = 0;
		int Exps1 = 0;

		DisplayDB();

		cout << "Whitch Worker you want to Edit?" << endl;
		Get_Num_Without_Ex(chs1, "Enter number of Worker: ");

		while (vallue == 0)
		{
			if (chs1 > 1 && chs1 <= dabase.size())
			{
				vallue++;
			}
			else
			{
				cout << "Invalide Input!!! Try again!!!";
				cout << "Whitch Worker you want to Edit?" << endl;
				Get_Num_Without_Ex(chs1, "Enter number of Worker: ");
			}
		}

		chs1--;
		cout << endl;

		for (int i = 0; i < dabase.size(); i++)
		{
			if (chs1 == i)
			{
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << setw(3) << chs1+1 << "|" << setw(10) << dabase[chs1].FirstName << "|" << setw(11) << dabase[chs1].SecondName << "|" << setw(10) << dabase[chs1].SurName << "|" << setw(6) << dabase[chs1].Year << "|" << setw(5) << dabase[chs1].Month << "|" << setw(7) << dabase[chs1].PastTime << "|" << setw(7) << dabase[chs1].City << "|" << setw(10) << dabase[chs1].Expancious << "|" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << endl;
				cout << "What you want to edit: " << endl;
				cout << "(1) Firstname / (2) Secondname / (3) Surname / (4) City" << endl;
				cout << "(5) Year / (6) Month / (7) Passtime / (8) Expansions" << endl;

				Get_Num_Without_Ex(chs2, "Your choise is: ");
			
				switch (chs2)
				{
				case 1:
					Get_String_Whithout_Num(Fname1, "Enter new Firstname: ");
					cout << endl;
					break;
				case 2:
					Get_String_Whithout_Num(Sname1, "Enter new Secondname: ");
					cout << endl;
					break;
				case 3:
					Get_String_Whithout_Num(Suname1, "Enter new Surname: ");
					cout << endl;
					break;
				case 4:
					Get_String_Whithout_Num(Cty1, "Enter new City: ");
					cout << endl;
					break;
				case 5:
					Get_Num_Without_Ex(yr1, "Enter new Year: ");
					break;
				case 6:
					Get_Num_Without_Ex(Mnth1, "Enter new Month: ");
					break;
				case 7:
					Get_Num_Without_Ex(Ptime1, "Enter new Passtime: ");
					break;
				case 8:
					Get_Num_Without_Ex(Exps1, "Enter new Expancions: ");
					break;
				default:
					cout << "Wrong input!!! Try Again!!!" << endl;
				}
				
				while (k == 0)
				{
					cout << "Apply Changes? previos data will be lost!" << endl;
					Get_Num_Without_Ex(k2, "YES (1) \ NO (2): ");

					if (k2 == 1 || k2 == 2)
					{
						if (k2 == 1)
						{
							k++;
							switch (chs2)
							{
							case 1:
								dabase[i].FirstName = Fname1;
								break;
							case 2:
								dabase[i].SecondName = Sname1;
								break;
							case 3:
								dabase[i].SurName = Suname1;
								break;
							case 4:
								dabase[i].City = Cty1;
								break;
							case 5:
								dabase[i].Year = yr1;
								break;
							case 6:
								dabase[i].Month = Mnth1;
								break;
							case 7:
								dabase[i].PastTime = Ptime1;
								break;
							case 8:
								dabase[i].Expancious = Exps1;
								break;
							}
							LogToFile();
						}
						else
						{
							k++;
							continue;
						}
					}
					else
					{
						cout << "ERROR: Invalid Input!!! Enter only (1) or (2)!!!" << endl;
						cout << "Try Again" << endl;
					}
				}

			}
		}

	}

	void AddWorker() // ф-ція додавання нового працівника
	{
		int k = 1;
		int k2 = 0;
		int proof,r;
		string Fname = " ";
		string Sname;
		string Suname;
		string Cty;
		int yr = 0;
		int Mnth = 0;
		int Ptime = 0;
		int Exps = 0;

		
		while (k != 2)
		{
			cout << "Enter queuently: Firstname, Secondname, Surname, Year, Month, PastTime, City, Expansions" << endl;
			
			Get_String_Whithout_Num(Fname, "Enter Firstname: ");
			cout << endl;
			Get_String_Whithout_Num(Sname, "Enter Secondname: ");
			cout << endl;
			Get_String_Whithout_Num(Suname, "Enter Surname: ");
			cout << endl;
			while (k2 == 0)
			{
				Get_Num_Without_Ex(yr, "Enter Year: ");
				if (yr >= 1900)
				{
					k2++;
				}
				else
				{
					cout << "Invalide Entering!!! Year is to low!!!" << endl;
					cout << "Please try again: " << endl;
				}
			}
			k2 = 0;

			while (k2 == 0)
			{
				Get_Num_Without_Ex(Mnth, "Enter Month: ");
				if (Mnth > 0 && Mnth < 13)
				{
					k2++;
				}
				else
				{
					cout << "Invalide Entering!!! Enter numbers of month from 1 to 12 !!!" << endl;
					cout << "Please try again: " << endl;
				}
			}
			k2 = 0;

			while (k2 == 0)
			{
				Get_Num_Without_Ex(Ptime, "Enter PTime: ");
				if (Ptime >= 0)
				{
					k2++;
				}
				else
				{
					cout << "Invalide Entering!!! Enter only positive numbers!!!" << endl;
					cout << "Please try again: " << endl;
				}
			}
			k2 = 0;
			Get_String_Whithout_Num(Cty, "Enter City: ");
			cout << endl;

			while (k2 == 0)
			{
				Get_Num_Without_Ex(Exps, "Enter Expancions: ");
				if (Exps >= 0)
				{
					k2++;
				}
				else
				{
					cout << "Invalide Entering!!! Enter only positive numbers!!!" << endl;
					cout << "Please try again: " << endl;
				}
			}
			k2 = 0;

			
			cout << "Are you sure that you want to add this worker?      YES(1)     NO(2)" << endl;
			Get_Num_Without_Ex(proof, "Your choice is: ");
			switch (proof)
			{
			case 1:
				r = size2;
				dabase.resize(size2 + 1);
				size2 += 1;
				dabase[r].FirstName = Fname;
				dabase[r].SecondName = Sname;
				dabase[r].SurName = Suname;
				dabase[r].Year = yr;
				dabase[r].Month = Mnth;
				dabase[r].PastTime = Ptime;
				dabase[r].City = Cty;
				dabase[r].Expancious = Exps;
				LogToFile();
				k = 2;
				break;
			case 2:
				k = 2;
				continue;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
				cout << "Do you want again enter workers?   YES(1)     NO(2)" << endl;
				break;
			}
		}
	}

	void DeleteWorker() // ф-ція видалення працівника
	{
		int k = 0;
		int k2 = 0;
		int DU = 0;
		DisplayDB();
		cout << "Enter number of Worker you want to DELETE (range from 1 to " << size2 << " )\n" << endl;

		Get_Num_Without_Ex(DU, "You choose: ");

		cout << endl << endl;
		if (DU <= 0 || DU > size2) {
			cout << "!!!  Invalide Input  !!!   TRy Again: " << endl << endl;
			DeleteWorker();
		}
		else
		{
			while (k2 == 0)
			{
				cout << "Are you sure that you want to DELETE this WORKER???" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << setw(3) << DU << "|" << setw(10) << dabase[DU-1].FirstName << "|" << setw(11) << dabase[DU-1].SecondName << "|" << setw(10) << dabase[DU-1].SurName << "|" << setw(6) << dabase[DU-1].Year << "|" << setw(5) << dabase[DU-1].Month << "|" << setw(7) << dabase[DU-1].PastTime << "|" << setw(7) << dabase[DU-1].City << "|" << setw(10) << dabase[DU-1].Expancious << "|" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				Get_Num_Without_Ex(k, "YES (1) / NO (2): ");
				if (k == 1 || k == 2)
				{
					if (k == 1)
					{
						cout << endl << "DELETE SUCCESFULL \n" << endl;
						k2++;
						ofstream fout;
						fout.open("DataBase.txt");

						for (int i = 0; i < size2; i++)
						{
							if (i == (DU - 1))
							{
								continue;
							}
							else
							{
								fout << dabase[i].FirstName << " " << dabase[i].SecondName << " " << dabase[i].SurName << " " << dabase[i].Year << " " << dabase[i].Month << " " << dabase[i].PastTime << " " << dabase[i].City << " " << dabase[i].Expancious << endl;
							}
						}
						fout.close();

						vector<Data> copydabase = DB();

						dabase = copydabase;
						LogToFile();
					}
					else
					{
						k2++;
					}
				}
				else
				{
					cout << "Invalide Input!!! Try again and Enter only (1) or (2)!!!" << endl;
				}
			}
		}
	}

	vector<Data> TOC() //Ф-ція типу вектора, яка записує інформаццію з файла
	{
		ifstream fin;
		fin.open("TOC.txt");
		NumOfCityF();
		vector<Data> topc(size3);
		for (int i = 0; i < topc.size(); i++)
		{
			fin >> topc[i].City >> topc[i].Month >> topc[i].TopOfCity;
		}
		return topc;
	}

	void DisplayDB() // ф-ція вивіду таблички працівників
	{
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << setw(4) << "|"  << setw(10) <<" Firstname"  << "|" << setw(11)<< "Secondname" << "|" << setw(10) << "Surname" << "|" << setw(6) << "Year" << "|" << setw(5) << "Month" << "|" << setw(7) << "PTime" << "|" <<setw(7) << "City" << "|" << setw(10) <<"Expancions" << "|"<< endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		if (dabase.size() == 0)
		{
			cout << endl;
			cout << "ATTENTION:  NO RECORDS!!! ADD NEW RECORD OR WAIT WHEN ADMIN ADD THE NEW ONE" << endl;
		}
		else
		{
			for (int i = 0; i < dabase.size(); i++)
			{
				cout << setw(3) << i + 1 << "|" << setw(10) << dabase[i].FirstName << "|" << setw(11) << dabase[i].SecondName << "|" << setw(10) << dabase[i].SurName << "|" << setw(6) << dabase[i].Year << "|" << setw(5) << dabase[i].Month << "|" << setw(7) << dabase[i].PastTime << "|" << setw(7) << dabase[i].City << "|" << setw(10) << dabase[i].Expancious << "|" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
			}
		}
		cout << endl;
	}

	void LogToFile() // функція запису в файл
	{
		ofstream fout;
		fout.open("DataBase.txt");
		for (int i = 0; i < size2; i++)
		{
			fout << dabase[i].FirstName << " " << dabase[i].SecondName << " " << dabase[i].SurName << " " << dabase[i].Year << " " << dabase[i].Month << " " << dabase[i].PastTime << " " << dabase[i].City << " " << dabase[i].Expancious << endl;
		}
		fout.close();
	}

	void NumOfCityF() // Функція в якій я отримую к-сть рядків в файлі
	{
		ifstream file("TOC.txt");
		char bud[256];
		size3 = 0;

		while (file.getline(bud, 256))
		{
			size3++;
		}
		file.close();
	}

	void Top_Of_Cities() // ф-ція підрахунку найбільш відвідуваних міст за вказаний проміжок місяців
	{
		string copy1;
		string copy2 = "";
		int k = 0;
		int x = 0;
		int a = 0;
		int b = 0;

		cout << "Enter First and Second Month number (from 1 to 12)" << endl;

		Get_Num_Without_Ex(a, "First Month: ");
		Get_Num_Without_Ex(b, "Second Month: ");

		if (a > 0 && a < 13 && b > 0 && b < 13)
		{
		ofstream fout;

		fout.open("TOC.txt");

			for (int i = 0; i < dabase.size(); i++)
			{
				if (a < b && dabase[i].Month >= a && dabase[i].Month <= b)
				{
					fout << dabase[i].City << " " << dabase[i].Month << " " << dabase[i].TopOfCity << endl;
				}
				if (a > b && dabase[i].Month >= a)
				{
					fout << dabase[i].City << " " << dabase[i].Month << " " << dabase[i].TopOfCity << endl;
					x = 1;
				}
			}

			fout.close();

			if (x == 1)
			{
				fout.open("TOC.txt", ofstream::app);
				for (int v = 0; v < dabase.size(); v++)
				{
					if (a > b)
					{
						if (dabase[v].Month >= 1 && dabase[v].Month <= b)
						{
							fout << dabase[v].City << " " << dabase[v].Month << " " << dabase[v].TopOfCity << endl;
						}
					}
				}
				fout.close();
			}

			vector<Data> topV = TOC();

			x = 0;

			while (x < topV.size())
			{
				copy1 = topV[x].City;

				for (int d = 0; d < topV.size(); d++)
				{
					if (topV[d].City == copy1)
					{
						topV[x].TopOfCity++;
					}
				}
				x++;
			}

			for (int i = 1; i < topV.size(); i++)
			{
				for (int j = 0; j < topV.size() - i; j++)
				{
					if (topV.at(j).City > topV.at(j + 1).City)
					{
						Data temp = topV.at(j);
						topV.at(j) = topV.at(j + 1);
						topV.at(j + 1) = temp;
					}
				}
			}

			fout.open("TOC.txt");

			x = 0;
			int y = 0;
			while(y < topV.size())
			{
				int z = 0;
				for (int q = 0; q < topV.size(); q++)
				{
					if (x < topV.size())
					{
						z = 1;
						copy2 = topV[x].City;
						if (topV[q].City == copy2)
						{
							k = q;
						}
					}
					else
					{
						z = 0;
						y = topV.size();
						break;
					}
				}
				if (z == 1)
				{
					fout << topV[k].City << " " << topV[k].Month << " " << topV[k].TopOfCity << endl;
					x = (k + 1);
					y++;
				}
			}
			fout.close();

			topV = TOC();

			for (int w = 1; w < topV.size(); w++)
			{
				for (int e = 0; e < topV.size() - w; e++)
				{
					if (topV.at(e).TopOfCity < topV.at(e + 1).TopOfCity)
					{
						Data temp = topV.at(e);
						topV.at(e) = topV.at(e + 1);
						topV.at(e + 1) = temp;
					}
				}
			}

			remove("TOC.txt");

			cout << "Tops of Cities: " << endl;

			for (int h = 0; h < topV.size(); h++)
			{
				if (h < 5)
				{
					cout << setw(3) << h + 1 << "." << setw(10) << topV[h].City << endl;
				}
			}
		}
		else
		{
			cout << "Incorrect Input!!! Try Again!!! \n" << endl;
			Top_Of_Cities();
		}
	}

	void SortExpancions() // ф-ція сортування витрат
	{
		for (int i = 1; i < dabase.size(); i++)
		{
			for (int j = 0; j < dabase.size() - i; j++)
			{
				if (dabase.at(j).Expancious < dabase.at(j + 1).Expancious)
				{
					Data temp = dabase.at(j);
					dabase.at(j) = dabase.at(j + 1);
					dabase.at(j + 1) = temp;
				}
			}
		}
		DisplayDB();
		LogToFile();
	}

	void SortCity() // ф-ція сортування міст
	{
		for (int i = 1; i < dabase.size(); i++)
		{
			for (int j = 0; j < dabase.size() - i; j++)
			{
				if (dabase.at(j).City > dabase.at(j + 1).City)
				{
					Data temp = dabase.at(j);
					dabase.at(j) = dabase.at(j + 1);
					dabase.at(j + 1) = temp;
				}
			}
		}
		LogToFile();
	}

	void SortPastTime() // ф-ція сортування по часу
	{
		for (int i = 1; i < dabase.size(); i++)
		{
			for (int j = 0; j < dabase.size() - i; j++)
			{
				if (dabase.at(j).PastTime < dabase.at(j + 1).PastTime)
				{
					Data temp = dabase.at(j);
					dabase.at(j) = dabase.at(j + 1);
					dabase.at(j + 1) = temp;
				}
			}
		}
		DisplayDB();
		LogToFile();
	}

	void SortFirstname() // ф-ція сортування по імені
	{
		for (int i = 1; i < dabase.size(); i++)
		{
			for (int j = 0; j < dabase.size() - i; j++)
			{
				if (dabase.at(j).FirstName > dabase.at(j + 1).FirstName)
				{
					Data temp = dabase.at(j);
					dabase.at(j) = dabase.at(j + 1);
					dabase.at(j + 1) = temp;
				}
			}
		}
		DisplayDB();
		LogToFile();
	}

	void SortSecondName() // ф-ція сортування по призвіщу
	{
		for (int i = 1; i < dabase.size(); i++)
		{
			for (int j = 0; j < dabase.size() - i; j++)
			{
				if (dabase.at(j).SecondName > dabase.at(j + 1).SecondName)
				{
					Data temp = dabase.at(j);
					dabase.at(j) = dabase.at(j + 1);
					dabase.at(j + 1) = temp;
				}
			}
		}
		DisplayDB();
		LogToFile();
	}

	void SortSurname() // ф-ція сортування по батькові
	{
		for (int i = 1; i < dabase.size(); i++)
		{
			for (int j = 0; j < dabase.size() - i; j++)
			{
				if (dabase.at(j).SurName > dabase.at(j + 1).SurName)
				{
					Data temp = dabase.at(j);
					dabase.at(j) = dabase.at(j + 1);
					dabase.at(j + 1) = temp;
				}
			}
		}
		DisplayDB();
		LogToFile();
	}

	void SortYear() // ф-ція сортування по року
	{
		for (int i = 1; i < dabase.size(); i++)
		{
			for (int j = 0; j < dabase.size() - i; j++)
			{
				if (dabase.at(j).Year > dabase.at(j + 1).Year)
				{
					Data temp = dabase.at(j);
					dabase.at(j) = dabase.at(j + 1);
					dabase.at(j + 1) = temp;
				}
			}
		}
		DisplayDB();
		LogToFile();
	}

	void SortMonth() // ф-ція сортування по місяцях
	{
		for (int i = 1; i < dabase.size(); i++)
		{
			for (int j = 0; j < dabase.size() - i; j++)
			{
				if (dabase.at(j).Month > dabase.at(j + 1).Month)
				{
					Data temp = dabase.at(j);
					dabase.at(j) = dabase.at(j + 1);
					dabase.at(j + 1) = temp;
				}
			}
		}
		LogToFile();
	}

	void Mounth_Expansions_Count() // ф-ція сортування виплат за місяць
	{
		int k = 0;
		int num2 = 0;
		int count = 0;

		Get_Num_Without_Ex(num2, "Enter Month: ");

		
		if (num2 < 13 && num2 > 0)
		{
			cout << "People " << num2 << " month: " << endl;
			for (int i = 0; i < size2; i++)
			{
				if (dabase[i].Month == num2)
				{
					k = 1;
					count += dabase[i].Expancious;
					cout << setw(3) << i + 1 << "|" << setw(7) << dabase[i].FirstName << setw(10) << dabase[i].SecondName << setw(10) << dabase[i].SurName << setw(8) << dabase[i].Year << setw(6) << dabase[i].Month << setw(8) << dabase[i].PastTime << setw(10) << dabase[i].City << setw(8) << dabase[i].Expancious << endl;
				}
			}
			if (k == 0)
			{
				cout << "NO RECORDS!" << endl;
			}
			cout << endl;
			cout << "General Expansions of workers " << num2 << " month: " << count << endl;
			cout << endl;
		}
		else
		{
			cout << "Invalide Input!!! Try Again!!! Enter month numbers from 1 to 12 !!!" << endl;
			Mounth_Expansions_Count();
		}
	}

	void FindByYear() // ф-ція знаходження за роком
	{
		int k = 0;
		int num1 = 0;

		
		Get_Num_Without_Ex(num1, "Enter Year you want to find: ");

		cout << "Result is: " << endl;

		for (int i = 0; i < size2; i++)
		{
			if (dabase[i].Year == num1)
			{
				cout << setw(3) << i + 1 << "|" << setw(7) << dabase[i].FirstName << setw(10) << dabase[i].SecondName << setw(10) << dabase[i].SurName << setw(8) << dabase[i].Year << setw(6) << dabase[i].Month << setw(8) << dabase[i].PastTime << setw(10) << dabase[i].City << setw(8) << dabase[i].Expancious << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "NO MATCH!" << endl;
		}
	}

	void FindByFirstName() // ф-ція знаходження за іменем
	{
		int k = 0;
		string name;

		cout << "Enter FirstName of person you want to find: ";
		cin >> name;
		cout << endl;
		cout << "Result is: " << endl;

		for (int i = 0; i < size2; i++)
		{
			if (dabase[i].FirstName == name)
			{
				cout << setw(3) << i + 1 << "|" << setw(7) << dabase[i].FirstName << setw(10) << dabase[i].SecondName << setw(10) << dabase[i].SurName << setw(8) << dabase[i].Year << setw(6) << dabase[i].Month << setw(8) << dabase[i].PastTime << setw(10) << dabase[i].City << setw(8) << dabase[i].Expancious << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "NO MATCH!" << endl;
		}
	}

	void FindBySecondName() // ф-ція знаходження за призвіщем
	{
		int k = 0;
		string name;
		cout << "Enter SecondName of person you want to find: ";
		cin >> name;
		cout << endl;
		cout << "Result is: " << endl;

		for (int i = 0; i < size2; i++)
		{
			if (dabase[i].SecondName == name)
			{
				cout << setw(3) << i + 1 << "|" << setw(7) << dabase[i].FirstName << setw(10) << dabase[i].SecondName << setw(10) << dabase[i].SurName << setw(8) << dabase[i].Year << setw(6) << dabase[i].Month << setw(8) << dabase[i].PastTime << setw(10) << dabase[i].City << setw(8) << dabase[i].Expancious << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "NO MATCH!" << endl;
		}
	}

	void FindBySurName() // ф-ція знаходження по батькові
	{
		int k = 0;
		string name;

		cout << "Enter SurName of person you want to find: ";
		cin >> name;
		cout << endl;
		cout << "Result is: " << endl;

		for (int i = 0; i < size2; i++)
		{
			if (dabase[i].SurName == name)
			{
				cout << setw(3) << i + 1 << "|" << setw(7) << dabase[i].FirstName << setw(10) << dabase[i].SecondName << setw(10) << dabase[i].SurName << setw(8) << dabase[i].Year << setw(6) << dabase[i].Month << setw(8) << dabase[i].PastTime << setw(10) << dabase[i].City << setw(8) << dabase[i].Expancious << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "NO MATCH!" << endl;
		}
	}
};

class Login : public Database
{
private:

	string lg, ps;
	int size = 0;
	int chs1 = 0;
	int chs2 = 0;
	//int TF = 1;

	struct LG
	{
		string Log, Pass, Role;
	};

	vector<LG> lgps = LG1();

public:
	int MainChoice = 1;
	int Exit = 2;

	void EditUser() // ф-ція редагування логінів
	{
		int k = 0;
		int k2 = 0;
		int chos;
		int lg = 0;
		int ps = 0;
		int rl = 0;
		int chos1 = 1, vallue = 0;
		string logn, pssw, roll;

		DisplayLG();

		Get_Num_Without_Ex(chos, "What you want to Edit? (1)LOgin/(2)Password/(3)Roll: ");

		switch (chos)
		{
		case 1:
			cout << "Enter num of login you want to edit (from 1 to " << lgps.size() << " )" << endl;

			Get_Num_Without_Ex(lg, "Your choise is: ");

			while (vallue == 0)
			{
				if (lg > 1 && lg <= lgps.size())
				{
					vallue++;
				}
				else
				{
					cout << "Invalide Input!!! Try again!!!";
					cout << "Enter num of login you want to edit (from 1 to " << lgps.size() << " )" << endl;
					Get_Num_Without_Ex(lg, "Your choise is: ");
				}
			}
			vallue = 0;
			cout << "Enter New Login: ";
			cin >> logn;
			cout << endl;
			break;
		case 2:
			cout << "Enter num of password you want to edit (from 1 to " << lgps.size() << " )" << endl;
			Get_Num_Without_Ex(ps, "Your choise is: ");

			while (vallue == 0)
			{
				if (ps > 1 && ps <= lgps.size())
				{
					vallue++;
				}
				else
				{
					cout << "Invalide Input!!! Try again!!!";
					cout << "Enter num of password you want to edit (from 1 to " << lgps.size() << " )" << endl;
					Get_Num_Without_Ex(ps, "Your choise is: ");
				}
			}
			vallue = 0;

			cout << "Enter New Password: ";
			cin >> pssw;
			cout << endl;
			break;
		case 3:
			cout << "Enter num of role you want to edit (from 1 to " << lgps.size() << " )" << endl;
			Get_Num_Without_Ex(rl, "Your choise is: ");

			while (vallue == 0)
			{
				if (rl > 1 && rl <= lgps.size())
				{
					vallue++;
				}
				else
				{
					cout << "Invalide Input!!! Try again!!!";
					cout << "Enter num of role you want to edit (from 1 to " << lgps.size() << " )" << endl;
					Get_Num_Without_Ex(rl, "Your choise is: ");
				}
			}
			vallue = 0;

			cout << "Enter New Roll: ";
			cin >> roll;
			cout << endl;
			break;
		default:
			cout << "INVALIDE INPUT!!! TRY AGAIN!!!" << endl;
			EditUser();
		}

		while (k == 0)
		{
			cout << "Apply Changes? previos data will be lost!" << endl;
			Get_Num_Without_Ex(k2, "YES (1) \ NO (2): ");

			if (k2 == 1 || k2 == 2)
			{
				if (k2 == 1)
				{
					k++;
					switch (chos)
					{
					case 1:
						lgps[lg - 1].Log = logn;
						break;
					case 2:
						lgps[ps - 1].Pass = pssw;
						break;
					case 3:
						lgps[rl - 1].Role = roll;
						break;
					}
					LogLGToFile();
				}
				else
				{
					k++;
					continue;
				}
			}
			else
			{
				cout << "ERROR: Invalid Input!!! Enter only (1) or (2)!!!" << endl;
				cout << "Try Again" << endl;
			}
		}
	}

	void DeleteUser() // ф-ція видалення логіну
	{
		int k = 0;
		int k2 = 0;
		int DU = 0;
		DisplayLG();
		cout << "Enter number of User you want to DELETE (range from 1 to " << size <<" )"<< endl;
		Get_Num_Without_Ex(DU, "You choose: ");
		cout << endl << endl;
		if (DU <= 0 || DU > size) {
			cout << "!!!  Invalide Input  !!!   TRy Again: " << endl << endl;
			DeleteUser();
		}
		else
		{
			while (k2 == 0) 
			{
				cout << "Are you sure that you want to DELETE this user???" << endl;
				cout << "------------------------------" << endl;
				cout << setw(3) << DU << "|" << setw(10) << lgps[DU-1].Log << "|" << setw(10) << lgps[DU-1].Pass << "|" << setw(3) << lgps[DU-1].Role << "|"<< endl;
				cout << "------------------------------" << endl;
				Get_Num_Without_Ex(k, "YES (1) / NO (2): ");
				if (k == 1 || k == 2)
				{
					if (k == 1)
					{
						cout << endl << "DELETE SUCCESFULL \n" << endl;
						k2++;
						ofstream fout;
						fout.open("LoginAndPass.txt");
						for (int i = 0; i < size; i++)
						{
							if (i == (DU - 1))
							{
								continue;
							}
							else
							{
								fout << lgps[i].Log << " " << lgps[i].Pass << " " << lgps[i].Role << endl;
							}
						}
						fout.close();

						vector<LG> copylgps = LG1();

						lgps = copylgps;
						LogLGToFile();
					}
					else
					{
						k2++;
					}
				}
				else
				{
					cout << "Invalide Input!!! Try again and Enter only (1) or (2)!!!" << endl;
				}
			}
		}
	}

	void LogLGToFile() // функція запису логіну в файл
	{
		ofstream fout;
		fout.open("LoginAndPass.txt");
		for (int i = 0; i < size; i++)
		{
			fout << lgps[i].Log << " " << lgps[i].Pass << " " << lgps[i].Role << endl;
		}
		fout.close();
	}

	void AddUser() // ф-ція що додає новий логін
	{
		int k = 1;
		int k1 = 0;
		int k2 = 1;
		int k3 = 0;
		int proof, r;
		string logn, pssw, roll;

		while (k != 2)
		{
			cout << "Enter queuently: Login, Password, Role( Admin(1) / User(0)" << endl;
			cout << "Enter Login: ";
			cin >> logn;
			cout << endl;
			for (int i = 0; i < size; i++)
			{
				if (lgps[i].Log == logn)
				{
					k2 = 2;
				}
			}

			if (k2 == 2)
			{
				cout << "This login already use!!!" << endl;
				cout << "Try Again: ";
				AddUser();
				break;
			}
			else
			{
				cout << "Enter Password: ";
				cin >> pssw;
				cout << endl;
				while (k3 != 1)
				{
					Get_Num_Without_Ex(k1, "Enter Role ( Admin(1) / User(0) ): ");

					switch (k1)
					{
					case 0:
						roll = "0";
						k3 = 1;
						break;
					case 1:
						roll = "1";
						k3 = 1;
						break;
					default:
						cout << "Incorrect Input!!! Try again!!! \n" << endl;
						break;
					}
				}
				cout << endl;
			}
			
			cout << "Are you sure that you want to add this User?      YES(1)     NO(2)" << endl;
			Get_Num_Without_Ex(proof, "Your choice is: ");
			cout << "\n" << endl;

			switch (proof)
			{
			case 1:
				r = size;
				lgps.resize(size + 1);
				size += 1;

				lgps[r].Log = logn;
				lgps[r].Pass = pssw;
				lgps[r].Role = roll;

				LogLGToFile();
				k = 2;
				break;
			case 2:
				k = 2;
				continue;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
				cout << "Do you want again enter Users?   YES(1)     NO(2)" << endl;
				break;
			}
		}
	}

	void Exit_The_Program() // ф-ція яка запитує про вихід із програми
	{
		cout << endl;
		cout << "Are you sure that you want to EXIT?" << endl;

		Get_Num_Without_Ex(Exit, "<<YES - 1>> OR <<NO - 2>> : ");

		if (MainChoice != 1 && MainChoice != 2)
		{
			cout << endl;
			cout << "WARNING!!! Invalid Entering!!! Try Again: " << endl;
			Exit_The_Program();
		}
		cout << endl;
	}

	void General_Admin_Menu() // ф-ція викликання меню для адміна
	{
		cout << "  -_ ADMIN MENU _-" << endl;
		cout << "Display    (1) " << endl;
		cout << "Sort       (2) " << endl;
		cout << "Search     (3) " << endl;
		cout << "Edit       (4) " << endl;
		cout << "Delete     (5) " << endl;
		cout << "Add        (6) " << endl;
		cout << "Individial (7) " << endl;
		cout << "Exit       (8) " << endl;
	}

	void General_User_Menu() // ф-ція викликання меню користувача
	{
		cout << "  << USER MENU >>" << endl;
		cout << "Display    (1) " << endl;
		cout << "Sort       (2) " << endl;
		cout << "Search     (3) " << endl;
		cout << "Individual (4)" << endl;
		cout << "Exit       (5) " << endl;
	}

	void All_Add_Funktions() // ф-ція виклику меню всіх функцій додавання і їх реалізація
	{
		int k = 0;

		while (k == 0)
		{
			int n1 = 0;
			cout << "Add User    (1)" << endl;
			cout << "Add Worker  (2)" << endl;
			cout << "Exit        (3)" << endl;

			Get_Num_Without_Ex(n1, "You choose: ");

			switch (n1)
			{
			case 1:
				AddUser();
				break;
			case 2:
				AddWorker();
				break;
			case 3:
				k++;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
			}
		}
	}

	void Delete_Files() // ф-ція видалення файлів
	{
		int chs = 0;
		int chs2 = 0;
		int k = 0;
		int k2 = 0;
		while (k2 == 0)
		{
			cout << "Wich file you want to delete?" << endl;
			cout << "Database file (1)" << endl;
			cout << "Logins file   (2)" << endl;
			Get_Num_Without_Ex(chs, "Your choose is: ");
			if (chs == 1 || chs == 2)
			{
				k2++;
				while (k == 0)
				{
					cout << "Are you sure that you want to delete this file?" << endl;
					Get_Num_Without_Ex(chs2, "YES (1) / NO (2): ");
					if (chs2 == 1 || chs2 == 2)
					{
						if (chs2 == 1)
						{
							if (chs == 1)
							{
								ofstream fout;
								fout.open("DataBase.txt", ios::trunc);
								fout.close();
								vector<Data> copydab = DB();
								dabase = copydab;
								remove("DataBase.txt");
								cout << "DELETE SUCCESFULL!" << endl;
							}
							if (chs == 2)
							{
								ofstream fout;
								fout.open("LoginAndPass.txt", ios::trunc);
								fout.close();
								vector<LG> copylg = LG1();
								lgps = copylg;
								remove("LoginAndPass.txt");
								cout << "DELETE SUCCESFULL!" << endl;
							}
							k++;
						}
						else
						{
							k++;
						}
					}
					else
					{
						cout << "Invalide Input!!! Try again!!!" << endl;
					}
				}
			}
			else
			{
				cout << "Invalide Input!!! Try again!!!" << endl;
			}
		}
	}

	void All_Delete_Funktions() // ф-ція виклику меню всіх функцій видалення і їх реалізація
	{
		int k = 0;
		while (k == 0)
		{
			int n1 = 0;

			cout << "Delete User    (1)" << endl;
			cout << "Delete Worker  (2)" << endl;
			cout << "Delete FILES   (3)" << endl;
			cout << "Exit           (4)" << endl;

			Get_Num_Without_Ex(n1, "You choose: ");

			switch (n1)
			{
			case 1:
				DeleteUser();
				break;
			case 2:
				DeleteWorker();
				break;
			case 3:
				Delete_Files();
				break;
			case 4:
				k++;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
				break;
			}
		}
	}

	void All_Edit_Funktions() // ф-ція виклику меню всіх функцій редагування і їх реалізація
	{
		int k = 0;
		while (k == 0)
		{
			int n1 = 0;

			cout << "Edit User    (1)" << endl;
			cout << "Edit Worker  (2)" << endl;
			cout << "Exit         (3)" << endl;
			Get_Num_Without_Ex(n1, "You choose: ");

			switch (n1)
			{
			case 1:
				EditUser();
				break;
			case 2:
				EditWorker();
				break;
			case 3:
				k++;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
			}
		}
	}

	void All_Search_Funktions() // ф-ція виклику меню всіх функцій пошуку і їх реалізація
	{
		int k = 0;
		while (k == 0)
		{
			int n1 = 0;
			cout << "Search by Firstname   (1)" << endl;
			cout << "Search by SecondName  (2)" << endl;
			cout << "Search by SurName     (3)" << endl;
			cout << "Search by Year        (4)" << endl;
			cout << "Exit                  (5)" << endl;
			Get_Num_Without_Ex(n1, "You choose: ");
			switch (n1)
			{
			case 1:
				FindByFirstName();
				break;
			case 2:
				FindBySecondName();
				break;
			case 3:
				FindBySurName();
				break;
			case 4:
				FindByYear();
				break;
			case 5:
				k++;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
			}
		}
	}

	void User_Display_Funktions() // ф-ція виклику меню всіх функцій виводу і їх реалізація
	{
		int k = 0;
		while (k == 0)
		{
			int n1 = 0;
			cout << "Display Database      (1)" << endl;
			cout << "Display Top Of Cities (2)" << endl;
			cout << "Exit                  (3)" << endl;
			Get_Num_Without_Ex(n1, "You choose: ");
			switch (n1)
			{
			case 1:
				DisplayDB();
				break;
			case 2:
				Top_Of_Cities();
				break;
			case 3:
				k++;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
			}
		}
	}

	void Admin_Display_Funktions() // ф-ція виклику меню виводу адміна і ф-цій їх реалізаці
	{
		int k = 0;
		while (k == 0)
		{
			int n1 = 0;
			cout << "Display Database      (1)" << endl;
			cout << "Display Logins        (2)" << endl;
			cout << "Exit                  (3)" << endl;
			Get_Num_Without_Ex(n1, "You choose: ");
			switch (n1)
			{
			case 1:
				DisplayDB();
				break;
			case 2:
				DisplayLG();
				break;
			case 3:
				k++;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
				break;
			}
		}
	}

	void All_Sort_Funktions() // ф-ція виклику меню всіх функцій сортування і їх реалізація
	{
		int k = 0;
		while (k == 0)
		{
			int n1 = 0;
			cout << "Sort by FirstName  (1)" << endl;
			cout << "Sort by SecondName (2)" << endl;
			cout << "Sort by SurName    (3)" << endl;
			cout << "Sort by Year       (4)" << endl;
			cout << "Sort by Month      (5)" << endl;
			cout << "Sort by PastTime   (6)" << endl;
			cout << "Sort by City       (7)" << endl;
			cout << "Sort by Expancions (8)" << endl;
			cout << "Exit               (9)" << endl;

			Get_Num_Without_Ex(n1, "You choose: ");
			switch (n1)
			{
			case 1:
				SortFirstname();
				break;
			case 2:
				SortSecondName();
				break;
			case 3:
				SortSurname();
				break;
			case 4:
				SortYear();
				break;
			case 5:
				SortMonth();
				DisplayDB();
				break;
			case 6:
				SortPastTime();
				break;
			case 7:
				SortCity();
				DisplayDB();
				break;
			case 8:
				SortExpancions();
				break;
			case 9:
				k++;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
			}
		}
	}

	void Individual_Task() // ф-ція виклику меню всіх індивідуальних функцій і їх реалізація
	{
		int k = 0;
		while (k == 0)
		{
			int n1 = 0;
			cout << "Top Of Cities       (1)" << endl;
			cout << "Expansions of Month (2)" << endl;
			cout << "Exit                (3)" << endl;
			Get_Num_Without_Ex(n1, "You choose: ");
			switch (n1)
			{
			case 1:
				Top_Of_Cities();
				break;
			case 2:
				Mounth_Expansions_Count();
				break;
			case 3:
				k++;
				break;
			default:
				cout << "Invalide Input!!! Try Again!!!" << endl;
				break;
			}
		}
	}

	void Admin() // ф-ція виклику меню адміна і всіх функцій та їх реалізація
	{
		while (Exit == 2)
		{
			General_Admin_Menu();
			Get_Num_Without_Ex(chs1, "Your Choise: ");
			switch (chs1)
			{
			case 1:
				Admin_Display_Funktions();
				break;
			case 2:
				All_Sort_Funktions();
				break;
			case 3:
				All_Search_Funktions();
				break;
			case 4:
				All_Edit_Funktions();
				break;
			case 5:
				All_Delete_Funktions();
				break;
			case 6:
				All_Add_Funktions();
				break;
			case 7:
				Individual_Task();
				break;
			case 8:
				Exit_The_Program();
				break;
			default:
				cout << "\n";
				cout << "!!!!!-----INVALIDE ENTERING-----!!!!!\n" << endl;
				cout << "              Try Again!\n" << endl;
				cout << "\n";
				Admin();
				break;
			}
		}	
	}

	void User() // ф-ція виклику меню функцій користувача та їх реалізація
	{
		while (Exit == 2)
		{
			General_User_Menu();
			Get_Num_Without_Ex(chs2, "Your Choise is: ");
			switch (chs2)
			{
			case 1:
				User_Display_Funktions();
				break;
			case 2:
				All_Sort_Funktions();
				break;
			case 3:
				All_Search_Funktions();
				break;
			case 4:
				Individual_Task();
				break;
			case 5:
				Exit_The_Program();
				break;
			default:
				cout << "\n";
				cout << "!!!!!-----INVALIDE ENTERING-----!!!!!\n" << endl;
				cout << "              Try Again!\n" << endl;
				cout << "\n";
				User();
				break;
			}
		}
	}

	void LoginValue() // ф-ція вводу даних логіна і паролю
	{
		cout << "Enter Login and Password \n" << endl;
		cout << "Login: ";
		cin >> lg;
		cout << endl;
		cout << "Pass: ";
		cin >> ps;
		cout << endl;
		CompareLG();
	}

	void GetLineNum1() // ф-ція підрахунку рядків у файлі
	{
		ifstream file("LoginAndPass.txt");
		char num1[256];
		size = 0;
		while (file.getline(num1, 256))
		{
			size++;
		}
		if (size == 0)
		{
			cout << "Reserve data was enabled!!!" << endl;
			ReserveData();
			GetLineNum1();
		}
		file.close();
	}

	vector<LG> LG1() // ф-ція запису з файлу в вектор
	{
		ReserveLogin();
		ifstream fin;
		fin.open("LoginAndPass.txt");
		GetLineNum1();
		vector<LG> log(size);
		for (int i = 0; i < log.size(); i++)
		{
			fin >> log[i].Log >> log[i].Pass >> log[i].Role;
		}
		return log;
	}

	void ReserveData() // ф-ція запису резервних логінів
	{
		ofstream fout;
		fout.open("LoginAndPass.txt");
		fout << "RA 12345 1" << endl;
		fout << "RU 1234 0" << endl;
		fout.close();
	}

	void ReserveLogin() // ф-ція створення нового файлу логіну якщо його не було найдено
	{
		ifstream fin;
		fin.open("LoginAndPass.txt");
		if (!fin.is_open())
		{
			cout << "Error: File with Logins dont finded" << endl;
			cout << "Please use reserve login" << endl;
			ReserveData();
			LG1();
		}
		fin.close();
	}

	void DisplayLG() // ф-ція виводу логінів
	{
		cout << "------------------------------" << endl;
		cout << setw(3) << "num" << "|" << setw(10) << "LOGIN " << "|" << setw(10) << "Password " << "|" << setw(3) << "ROL" << "|" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < lgps.size(); i++)
		{
			cout << setw(3) << i + 1 << "|" << setw(10) << lgps[i].Log << "|" << setw(10) << lgps[i].Pass << "|" << setw(3) << lgps[i].Role << "|" << endl;
			cout << "------------------------------" << endl;
		}
		cout << endl;
	}

	void CompareLG() // ф-ція перевірки логіна і паролю
	{
		int k = 0;
		for (int i = 0; i < lgps.size(); i++)
		{
			if (lgps[i].Log == lg && lgps[i].Pass == ps)
			{
				k++;
				if (lgps[i].Role == "1")
				{
					Admin();
				}
				if (lgps[i].Role == "0")
				{
					User();
				}
			}
		}
		if (k == 0)
		{
			cout << "*** Invalid login or password! ***\n" << endl;
			cout << "Invalide Login or Password!!!" << endl;
			cout << "Try Again: ";
			LoginValue();
			CompareLG();
		}
	}
};

int main()
{
	Login DB;
	DB.LoginValue();
return 0;
}


