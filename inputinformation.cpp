#include "seat.h"

void seat::setmember(void) {
	system("cls");
	int input;
	cout << "������������������������������������������������ ü ���� ȭ�� ��������������������������������������������������" << endl;
	cout << "��                                                             ��" << endl;
	cout << "��                                                             ��" << endl;
	cout << "��                        1.�̸� ����                          ��" << endl;
	cout << "��                                                             ��" << endl;
	cout << "��                        2.���� ����                          ��" << endl;
	cout << "��                                                             ��" << endl;
	cout << "��                                                             ��" << endl;
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << "���Ͻô� �������� �������ּ���. ";
	cin >> input;
	system("cls");
	if (input == 1) {
		string name;
		system("cls");
		cout << "�л����� �Է����ּ���.";
		cin >> numbern;
		ofstream outFile("student.txt");
		system("cls");
		for (int i = 0; i < numbern; i++) {
			cout << i + 1 << "��° ����� ������ �Է����ּ���" << endl;
			cout << "�̸�: ";
			cin >> name;
			outFile << name << endl;
			system("cls");
		}
		outFile.close();
	}
	else if (input == 2) {
		int gender;
		system("cls");
		ofstream outFile("gender.txt");
		ifstream inFile("student.txt");
		system("cls");

		string a[30];
		for (int i = 0; i < numbern; i++) {
			//inFile.getline(inputString, 100);
			inFile >> a[i];

			cout << a[i] << "���� ������ �Է����ּ���.(���� = 0 ���� = 1)" << endl;
			cout << "����: ";
			cin >> gender;
			outFile << gender << endl;
			system("cls");
		}
		inFile.close();
		outFile.close();
		inputinformation();
	}
}

void seat::inputinformation(void) {
	ifstream i1File("student.txt");
	ifstream i2File("gender.txt");

	int n = 0;
	//�л�, ���� �̸��ֱ�
	while (!i1File.eof() && !i2File.eof()) {
		getline(i1File, inputstring);
		stna[n] = inputstring;
		i2File >> stgn[n];
		n++;
	}
	
	i1File.close();
	i2File.close();

	genderline = n - 1;
	studentline = n - 1;
	system("cls");

	//stna[100][100]; // �л����̸�
	//stgn[100][1]; //�л��� ����
}
