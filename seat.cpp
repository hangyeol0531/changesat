#include "seat.h"

using namespace std; 


void seat::reservedseat() {
reservedseatagain:
	system("cls");
	ifstream i1File("student.txt");
	while (1) {
		zizungflag = 1;
		int n = 1;
		int input = 1;

		while (!i1File.eof()) {
			i1File >> stna[n] ;
			cout << n << ". " << stna[n] << endl;
			n++;
		}

		cout << "���° ����� �����Ͻðڽ��ϱ�?: ";
		cin >> reserved[recount];
		cout << "���° �¼����� �����Ͻðڽ��ϱ�?: ";
		cin >> ren[recount];
		cout << "��� �Ͻ÷��� �ƹ�Ű�� �Է����ּ���(���� ȭ�� -1) : ";
		cin >> input;
		++recount;
		if (input == -1) break;
		else goto reservedseatagain;
	}
}

void seat::setseat() {
setseatagain:
	vector<int> over(numbern, 0);
	int fgfg = 0;
	jicount = 0;
	system("cls");
	seat seat;
	cout << "�� �ٴ� ���� �л� ���� �Է����ּ��� : ";
	cin >> num;
	int i, j, bFound, exit_flag = 0;
	int exit_flag1 = 0;
	srand(time(NULL));
	for (i = 0; i < numbern; ++i)
	{
		//������~~~~~~~~~~~~~~~~~~~~~~~~~~

		//���� Ƚ�� ���ϱ� 
		if (i == 0 && zizungflag == 1) {
			jijung = 0;
			for (int k = 0; k < numbern; k++) {
				jijung++;
				if (reserved[k] == 0) {
					jijung -= 1;
					break;
				}
			}
		}
		//������~~~~~~~~~~~~~~~~~~~~~~~~~~
		while (1)
		{	
			//������~~~~~~~~~~~~~~~~~~~~~~~~~~
			if (i == 0 && zizungflag == 1) {
				for (int q = 0; q < jijung; q++) {
					//over[reserved[q]] = ren[q];
					over[ren[q] - 1] = reserved[q];//over[�¼� ��ȣ] = �����ȣ
				}
			}

			fgfg = 0;

			if (jicount < jijung) {
				if (reserved[jicount] == over[i]) {
					jicount++;
					fgfg = 1;
				}
			}
			if (fgfg) break;
			//������~~~~~~~~~~~~~~~~~~~~~~~~~~

			over[i] = rand() % numbern + 1; // �������ϳ�����
			// �̹��ִ°�����Ȯ���ϱ������÷��׼���
			bFound = 0;
			// ���������ִ���Ȯ���Ѵ�
			for (j = 0; j < i; ++j)
			{
				// ��������������
				if (over[j] == over[i])
				{
					// ���������̹�����
					bFound = 1;
					break;
				}
			}
			// �������̾�����while��Ż��
			if (!bFound)
				break;
		}
	}
	/*��� �� �ֱ�*/
	ofstream i1File("setrecord.txt");

	int n = 0;
	//�л�, ���� �̸��ֱ�
	for (int i = 0; i < numbern; i++) {
		if (i == 0) {
			i1File << num << endl;
			i1File << numbern << endl;
		}
		i1File << over[i] << endl;
		system("cls");
	}
	i1File.close();
	////////////////////////////z
	system("cls");

	seat::waitingchang();
	int a = 0;
	cout.fill('0');
	system("cls");
	PlaySound("��.wav", NULL, SND_ASYNC | SND_LOOP);
	cout << "���������������������������������������������������������������������� ��÷ ��� ��������������������������������������������������������������������" << endl;
	for (int q = 0; q < numbern; ++q) {
		if (a % num == 0)
		{
			cout << endl << "��            ";
		}
		cout.width(2);
		cout << stna[over[q] - 1] << "   ";
		if (a != a / num && a % num == 5)
		{
			cout << "            ��" << endl;
		}
		a++;
	}
	cout << endl;
	cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
	Sleep(2000);
	PlaySound(0, 0, 0);
	Sleep(3000);
	if (MessageBox(NULL, "����÷ �Ͻðڽ��ϱ�?", "����", MB_YESNO) == IDYES) {
		system("cls");
		goto setseatagain;
	}
	else {
		seat.mainchang();
	}
	cout << endl;
};


class student {
public:

	int gender; // 0���� 1����

	int seatnumber; //���� ��ȣ // ������ 0
};
