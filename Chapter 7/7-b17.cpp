/*1651574 1�� �����*/
/*¬���� ������ ¬���� ������ ¬���� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>

using namespace std;

void StoreMem(ofstream &fout, char *mem)
{
	unsigned int tmp = 0;
	static bool flag = true;
	if (mem[0] <= 'Z' && mem[0] >= 'A')
		tmp += 16 * (mem[0] - 'A' + 10);
	else if (mem[0] <= 'z' && mem[0] >= 'a')
		tmp += 16 * (mem[0] - 'a' + 10);
	else
		tmp += 16 * (mem[0] - '0');

	if (mem[1] <= 'Z' && mem[1] >= 'A')
		tmp += mem[1] - 'A' + 10;
	else if (mem[1] <= 'z' && mem[1] >= 'a')
		tmp += mem[1] - 'a' + 10;
	else
		tmp += mem[1] - '0';

	char out = char(tmp & 0x00FF);

	/*		write Ҳ�ɣ� >>Ҳ��		*/	
	//char *c1 = new char;
	//char *c2 = new char;
	//*c1 = '\r'; *c2 = '\n';
	//if (!flag) {
	//	if (out == 0x0d) {
	//		//lfout.write(c1, 1);
	//		//fout.write((char*)'\r', 1);
	//		fout << char(0x0d);
	//	}
	//	else {
	//		if (out == 0x0a) {
	//			//fout.write(c2, 1);
	//			fout << char(0x0a);
	//		}
	//		else {
	//			//fout.write(c1,1);
	//			//fout.write(&out, 1);
	//			fout << char(0x0d) << out;
	//		}
	//		flag = true;
	//	}
	//}
	//else {
	//	if (out == 0x0d)
	//		flag = false;
	//	else
	//		fout << out;
	//}
	fout << out;
}

int main(int argc, char**argv)
//int main()
{
	ifstream fin;
	ofstream fout;
	char finName[20], foutName[20], tmp_mem[38];
	if (argc < 3) {
		cout << "��ֱ������ת�����ļ���������ļ�����\n";
		cin >> finName >> foutName;//no parameter
	}
	else {
		strcpy(finName, argv[1]);
		strcpy(foutName, argv[2]);
	}
	//char finName[20] = "1.txt", foutName[20] = "out.docx", tmp_mem[38];
	fin.open(finName, ios::binary);	//ios::binary
	fout.open(foutName, ios::binary);	//ios::binary important!!
	if (!fin.is_open()) {
		cout << "��" << finName << "ʧ�ܣ�\n";
		return 0;
	}
	if (!fout.is_open()) {
		cout << "��" << foutName << "ʧ�ܣ�\n";
		return 0;
	}
	int n = 0;
	//if (fin.peek() != EOF)
	//	fin >> tmp_mem;		//��ȡxxx.docx��һ��
	while (fin.peek() != EOF) {
		fin >> tmp_mem;		//��ȡǰ���00000001���
		for (int i = 0; i < 8 ; i++) {	//��8��
			//fin.clear();
			fin >> tmp_mem;
			if (strlen(tmp_mem) != 2 || fin.peek() == EOF)
				break;
			StoreMem(fout, tmp_mem);
		}
		//fin.clear();
		if (strlen(tmp_mem) != 2 || fin.peek() == EOF)
			break;
		fin>>tmp_mem;
		for (int i = 0; i < 8 && (fin.peek() != EOF); i++) {
			fin >> tmp_mem;
			if (strlen(tmp_mem) != 2 || fin.peek() == EOF)
				break;
			StoreMem(fout, tmp_mem);
			//fin.clear();
		}
		//fin.clear();
		if (strlen(tmp_mem) != 2 || fin.peek() == EOF)
			break;
		fin >> tmp_mem;
	}

	fin.close();
	fout.close();
	return 0;
}