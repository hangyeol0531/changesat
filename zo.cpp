#include "seat.h"

void seat::zolottery() {
againzolottery:
	system("cls");
	cout << "�� �� �ο��� ����Դϱ�?" << endl;
	cin >> zonumber;
	seat seat;
	int i, j, bFound;
	vector<int> zonum(numbern);
	srand(time(0));
	for (i = 0; i < numbern; ++i)
	{
		while (1)
		{
			// �������ϳ�����
			zonum[i] = rand() % numbern + 1;
			// �̹��ִ°�����Ȯ���ϱ������÷��׼���
			bFound = 0;
			// ���������ִ���Ȯ���Ѵ�
			for (j = 0; j < i; ++j)
			{
				// ��������������
				if (zonum[j] == zonum[i])
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
	ofstream i1File("zorecord.txt");

	int n = 0;
	//�л�, ���� �̸��ֱ�
	for (int i = 0; i < numbern; i++) {
		if (i == 0) {
			i1File << zonumber << endl;
			i1File << numbern << endl;
		}
		i1File << zonum[i] << endl;
		system("cls");
	}
	i1File.close();
	////////////////////////////

	system("cls");
	seat::waitingchang();
	int a = 0;
	int zocount = 0;
	cout.fill('0');
	PlaySound("��.wav", NULL, SND_ASYNC | SND_LOOP);
	cout << "�������������������������������������������������������������������� ��÷ ��� ������������������������������������������������������������������" << endl;
	for (i = 0; i < numbern; ++i) {

		if (a % zonumber == 0)
		{
			zocount++;
			cout << endl << endl;
			cout << zocount << "�� :  ";
		}
		cout.width(2);
		cout << stna[zonum[i] - 1] << "  ";
		a++;
	}
	cout <<  endl << endl << "������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
	Sleep(2000);
	PlaySound(0, 0, 0);
	Sleep(3000);
	if (MessageBox(NULL, "����÷ �Ͻðڽ��ϱ�?", "����", MB_YESNO) == IDYES) {
		system("cls");
		goto againzolottery;
	}
	else {
		seat.mainchang();
	}
	cout << endl;
};
