#include "seat.h"
void seat::danglottery() {
	string inputString;
	string stuString;

	system("cls");
	int Dinput = 1; // �� ��� ��
	int i; //for�� ���� ����
	int boy = 1, girl = 1; // ���� ��, �� ���� �ο� ��
	int input; // ������� ��ȣ ����
	int r = 0;//���� �� ����
	int cnt = 0;
	int bFound;
	int c = 1;
	vector<int> boyArr; //���ڰ� �����ִ� �� ���� ����Ǿ��ִ� �迭 ��� �����̳�
	vector<int> girlArr;
	vector<int>over(studentline, 0);

	//  /*���ڿ� ���ڰ� �����ִ� �� �� ����
	ifstream gd("gender.txt");
	while (!gd.eof()) {
		for (i = 0; i < genderline; i++) {
			getline(gd, inputString);
			if (inputString.compare(0, 1, "0") == 0) {
				boyArr.push_back(i + 1);
			}
			else if (inputString.compare(0, 1, "1") == 0) {
				girlArr.push_back(i + 1);
			}
			else
				break;
		}
	}

	ifstream student("student.txt");
	ifstream gender("gender.txt");

	int *student_array = new int[studentline];
	for (i = 0; i < studentline; i++)
		student_array[i] = i + 1;
	Shuffle_Data(student_array);

	vector <string> stu;
	vector <string> gen;

	while (!student.eof()) {
		getline(student, stuString);
		stu.push_back(stuString);
		getline(gender, inputString);
		gen.push_back(inputString);
	}

	while (true) {
		cout << "���������������������������������������������� ��� �̱� ȭ�� ��������������������������������������������������" << endl;
		cout << "��                                                              ��" << endl;
		cout << "��                                                              ��" << endl;
		cout << "��                        1.��ü���� �̱�                       ��" << endl;
		cout << "��                                                              ��" << endl;
		cout << "��                        2.��,�� ���� �̱�                     ��" << endl;
		cout << "��                                                              ��" << endl;
		cout << "��                        3.���� Ȩ                             ��" << endl;
		cout << "��                                                              ��" << endl;
		cout << "��������������������������������������������������������������������������������������������������������������������������������" << endl;
		cin >> input;

		//      /*��÷�� ��� �ο� �� �� ���� ����
		if (input == 1) {
			againdang1:
			//�ο�  �� ����
			while (true) {
				cout << "���� �ο� ���� �������ּ��� : ";
				cin >> Dinput;
				if (Dinput > studentline) {
					MessageBoxA(NULL, "���� �ο� ���� �����ϴ�", "Error", MB_ICONWARNING);
					_getch();
					continue;
				}
				break;
			}

			//���
			seat::waitingchang();

			/*��� �� �ֱ�*/
			ofstream i1File("dangrecord.txt");

			int n = 0;
			//�л�, ���� �̸��ֱ�
			for (int i = 0; i < numbern; i++) {
				if (i == 0) {
					i1File << numbern << endl;
					i1File << Dinput << endl;
				}
				system("cls");
			}
			////////////////////////////
			cout << "��������������������������������� ��÷ ���������������������������������" << endl;
			c = 1;
			Shuffle_Data(student_array);
			for (int i = 0; i < Dinput; i++) {
				cout << c << ". " << stu[student_array[i]] << endl;
				c++;
				i1File << student_array[i] << endl; // ���
			}
			i1File.close();
			cout << "����������������������������������������������������������������������������������������" << endl;
			Sleep(3000);
			if (MessageBox(NULL, "����÷ �Ͻðڽ��ϱ�?", "����", MB_YESNO) == IDYES) {
				system("cls");
				goto againdang1;
			}
			else goto EXIT;
			system("cls");
		}
		else if (input == 2) {
			//���� �ο� �� ����
			while (true) {
			againdang2:
				cout << "���� �ο� ���� �������ּ��� : ";
				cin >> Dinput;
				if (Dinput > studentline) {
					MessageBoxA(NULL, "���� �ο� ���� �����ϴ�", "Error", MB_ICONWARNING);
					_getch();
					continue;
				}
				system("cls");
				cout << "���� (��), (��) �ο����� �������ּ��� (�� ��� �� :" << Dinput << ") " << endl;
				cout << "�� : ";
				cin >> boy;
				cout << "�� : ";
				cin >> girl;

				if (boy + girl != Dinput) {
					MessageBoxA(NULL, "��,�� ���� �߸������Ͽ����ϴ�.", "ERROR", MB_ICONWARNING);
					_getch();
					continue;
				}

				if (girl > girlArr.size() || boy > boyArr.size()) {
					MessageBoxA(NULL, "���� �Ǵ� ������ ���� ����ġ�� �����ϴ�.", "ERROR", MB_ICONWARNING);
					_getch();
					continue;
				}
				break;
			}
			seat::waitingchang();
			/*��� �� �ֱ�*/
			ofstream i1File("dangrecord.txt");

			int n = 0;
			//�л�, ���� �̸��ֱ�
			for (int i = 0; i < numbern; i++) {
				if (i == 0) {
					i1File << numbern << endl;
					i1File << Dinput << endl;
				}
				system("cls");
			}
			////////////////////////////
			c = 1; // ��� ��ȣ 
			//���� ���
			cout << "��������������������������������� ��÷ ���������������������������������" << endl;
			int draw_amount = 0;
			for (int i = 0; i < studentline; i++) {
				if (draw_amount == boy) {
					break;
				}
				if (gen[student_array[i]] == "0") {
					cout << c << ". "<< stu[student_array[i]] << endl;
					c++;
					i1File << student_array[i] << endl;
					draw_amount++;
				}
			}
			//���� ���
			draw_amount = 0;
			for (int i = 0; i < studentline; i++) {
				if (draw_amount == girl) {
					break;
				}
				if (gen[student_array[i]] == "1") {
					cout << c << ". " << stu[student_array[i]] << endl;
					c++;
					i1File << student_array[i] << endl;
					draw_amount++;
				}
			}
			cout << "����������������������������������������������������������������������������������������" << endl;
			i1File.close();
			Sleep(3000);
			if (MessageBox(NULL, "����÷ �Ͻðڽ��ϱ�?", "����", MB_YESNO) == IDYES) {
				system("cls");
				goto againdang2;
			}
			break;
		}
		else if (input == 3) {
			EXIT:
			seat::mainchang();
			break;
		}

		else {
			MessageBoxA(NULL, "�������� �� �� �����ϼ̽��ϴ�.", "Error", MB_ICONWARNING);
		}
	}
	student.close();
	gender.close();
};

void seat::Shuffle_Data(int *student_array, int routine_time) {
	for (int i = 0; i < routine_time; i++) {
		int data1_dir = rand() % studentline;
		int data2_dir = rand() % studentline;
		int temp = student_array[data2_dir];
		student_array[data2_dir] = student_array[data1_dir];
		student_array[data1_dir] = temp;
	}
};
