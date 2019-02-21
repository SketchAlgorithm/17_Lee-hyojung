//�̻��� �ݸ�
#include <iostream>
using namespace std;
int T;
int n, m, k;//�� ����~100, �ݸ� �ð�~1000, ���� ����~1000

//���� ��ġ
class Point {
private:
	int x, y;
public:
	Point() { x = 0; y = 0; }
	Point(int x, int y) { this->x = x; this->y = y; }
	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }
	int get_x() { return this->x; }
	int get_y() { return this->y; }
};

//���� ����(��ġ, ��ü��, ����)
class Micro {
private:
	Point loc;//���� ��ġ
	int micnum, dir;
public:
	Micro() {
		this->loc.set_x(0);
		this->loc.set_y(0);
		this->micnum = 0;
		this->dir = 0;
	}
	Micro(int x, int y) {
		this->loc.set_x(x);
		this->loc.set_y(y);
		this->micnum = 0;
		this->dir = 0;
	}
	void set_loc(int x, int y) { this->loc.set_x(x); this->loc.set_y(y); }
	void set_micnum(int micnum) { this->micnum = micnum; }
	void set_dir(int dir) { this->dir = dir; }
	int get_locx() { return this->loc.get_x(); }
	int get_locy() { return this->loc.get_y(); }
	int get_micnum() { return this->micnum; }
	int get_dir() { return this->dir; }

	void clear_mic() {
		this->loc.set_x(0);
		this->loc.set_y(0);
		this->micnum = 0;
		this->dir = 0;
	}
};

Micro map[100][100];//�� ��
void init();
void move(int i, int j);
void move2(Micro &now, Micro &next);

void init() {
	//(0,0)���� �ʱ�ȭ
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = Micro();

	//map �׵θ� ����(dir=-1)
	for (int i = 0; i < n; i++) {
		map[0][i].set_dir(-1);
		map[i][0].set_dir(-1);
		map[n - 1][i].set_dir(-1);
		map[i][n - 1].set_dir(-1);
	}

	//k(���� ���� ��ŭ) ���� �Է�
	int x, y, micnum_, dir_;
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> micnum_ >> dir_;
		map[x][y].set_loc(x, y);
		map[x][y].set_micnum(micnum_);
		map[x][y].set_dir(dir_);
	}
}

void move(int i, int j) {
	//��ǰ�� ������ ���(��ü�� ����, ���� ��ȯ)
	if (map[i - 1][j].get_dir() == -1 ||
		map[i + 1][j].get_dir() == -1 ||
		map[i][j - 1].get_dir() == -1 ||
		map[i][j + 1].get_dir() == -1)
	{
		int now_dir = map[i][j].get_dir();

		//��ü�� ���� ����
		int half = map[i][j].get_micnum() / 2;
		map[i][j].set_micnum(half);

		//���� ��ȯ
		switch (now_dir) {
		case 1:
			map[i][j].set_dir(2);
			break;
		case 2:
			map[i][j].set_dir(1);
			break;
		case 3:
			map[i][j].set_dir(4);
			break;
		case 4:
			map[i][j].set_dir(3);
			break;
		}
	}

	//��ǰ�� �������� ���� ��� ������ �� ĭ ����
	switch (map[i][j].get_dir()) {
	case 1://��
		move2(map[i][j], map[i - 1][j]);
		break;
	case 2://��
		move2(map[i][j], map[i + 1][j]);
		break;
	case 3://��
		move2(map[i][j], map[i][j - 1]);
		break;
	case 4://��
		move2(map[i][j], map[i][j + 1]);
		break;
	}
	map[i][j].clear_mic();
}

void move2(Micro &now,Micro &next) {
	//�̵� �� ���� ĭ�� �� ���� �Է�
	//�� ū ������ �������� ��ȯ(����)
	if (now.get_micnum() < next.get_micnum()) {
		now.set_dir(next.get_dir());
	}
	//��ü�� ��(��ü��)
	now.set_micnum(now.get_micnum() + next.get_micnum());
	//��ġ(��ġ)
	now.set_loc(next.get_locx(), next.get_locy());
}

int getsum() {
	int sum = 0;
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			sum += map[i][j].get_micnum();
	return sum;
}

int main() {
	cin >> T;
	int testcase = 1;
	while (testcase <= T) {
		cin >> n >> m >> k;
		init();//map �ʱ� ����

		//m�� ��ŭ ���� �̵�
		while (m-- > 0) {
			for (int i = 1; i < n - 1; i++) {
				for (int j = 1; j < n - 1; j++) {
					move(i, j);
				}
			}
		}
		
		cout << "#" << testcase << " "<< getsum()<<endl;
		testcase++;
	}
	return 0;
}