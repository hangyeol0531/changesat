#include <iostream>
#include <stdlib.h>
#include<string>
#include <fstream>
#include <time.h>
#include<windows.h>
#include <mmsystem.h>
#include <vector>
#include <iomanip>
#include <conio.h>
using namespace std;

class seat {
	string stna[50]; // �л����̸�
	int stgn[50]; //�л��� ����
	string inputstring;

public:
	seat();
	static int num;
	static int numbern;// �л���z
	static int zonumber;
	static int studentline;
	static int genderline;
	int reserved[10] = { 0, }; // �ٲٴ� ��� ��ȣ
	int zizungflag = 0;
	int ren[10] = { 0, }; // �¼� ��ȣ
	int recount = 0; //���� Ƚ��
	int jijung;
	int jicount = 0;
	int studentnum = 0; // �������� �����
	void inputinformation(void);
	void mainchang(void);
	void setseat(void);	
	void zolottery(void);
	void danglottery(void);
	void checkrecord(void);
	void setmember(void);
	void waitingchang(void);
	void setseatmain(void);
	void reservedseat(void);
	void Shuffle_Data(int *student_array, int routine_time=20);
};
