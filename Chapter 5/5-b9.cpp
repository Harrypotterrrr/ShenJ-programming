/*1�� ����� 1651574*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
bool Judge(int p[][10]) {
	bool flag_row[10] = { false };
	bool flag_arr[10] = { false };
	bool flag_blk[10] = { false };
	int row, col;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!flag_row[p[i][j]])
				flag_row[p[i][j]] = true;
			else
				return false;
			if (!flag_arr[p[j][i]])
				flag_arr[p[j][i]] = true;
			else
				return false;
			col = j % 3 + i % 3 * 3;	//��
			row = j / 3 + i / 3 * 3;	//��
			if (!flag_blk[p[row][col]])
				flag_blk[p[row][col]] = true;
			else
				return false;
			
		}
		memset(flag_row, false, sizeof(flag_row));
		memset(flag_arr, false, sizeof(flag_arr));
		memset(flag_blk, false, sizeof(flag_blk));
		//����������ѧϰ�����ݣ���ʵ�������޷Ǿ���ʡ������for..���������ܿ��ҷ�~
	}
	return true;
}
int main()
{
	int p[10][10],tmp;
	for (int i = 0; i < 9;i++)
		for (int j = 0; j < 9; j++) {
			while (true) {
				cin >> tmp;
				if (!cin.good() || tmp <=0 || tmp >9) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "�����������"<<i+1<<"��"<<j+1
						<<"��(���о���1��ʼ����)��ֵ\n";
					continue;
				}
				p[i][j] = tmp;
				break;
			}
		}
	if (Judge(p))
		cout << "�������Ľ�\n";
	else
		cout << "���������Ľ�\n";
	return 0;
}