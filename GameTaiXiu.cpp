#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<cmath>
#include<ctime>
#include<iomanip>

#define print_format(n) cout<<fixed<<setprecision(n)

using namespace std;

//tai khoan nguoi dung
string inGame = "";
string taiKhoan = "";
string matKhau = "";

//dang ky
string tk = "";
string mk = "";
string ingame = "";
long long tt;

//du lieu game
const int MAX_ACCOUNTS = 5;
const int MAX_PASSWORDS = 5;
const int MAX_INGAME = 5;
const int MAX_MONEY = 5;
const int xiNgau = 6;//tong so mat xi ngau
const int MAX_SIZE = 1000;

int dem_so_luong_tai_khoan_tao = 0;
int t = 0, m = 0, n = 0, e = 0;
int dem_ket_qua = 0;
int s1, s2, s3;
int id;
string rs;
long long tien = 0;

//DATA
int KET_QUA_DAT_CUOC[MAX_SIZE];
string KET_QUA_TAI_XIU[MAX_SIZE];
string DATABASE_ACCOUNTS[MAX_ACCOUNTS];
string DATABASE_PASSWORDS[MAX_PASSWORDS];
string DATABASE_INGAME[MAX_INGAME + 1];
long long DATABASE_MONEYGAME[MAX_MONEY];


//chuong trinh
void TaiKhoan(string dtk[MAX_ACCOUNTS], string dmk[MAX_PASSWORDS], string dig[MAX_INGAME], long long dmn[MAX_MONEY], int& dem_so_luong_tai_khoan_tao);
int KiemTraTaiKhoan(string& tk, string& mk);
void DangKyTaiKhoan();
void DangNhap();
string QuenMatKhau(string taikhoan);
void DatCuoc(int& id);
void NapTien(int& id);
void RutTien();
void TaiXiu(string& rs, long long& tien, int& id);
void Display();

int main()
{
	Display();
}

void TaiKhoan(string dtk[MAX_ACCOUNTS], string dmk[MAX_PASSWORDS], string dig[MAX_INGAME], long long dmn[MAX_MONEY], int& dem_so_luong_tai_khoan_tao)
{

	if (dem_so_luong_tai_khoan_tao < 1) {
		cout << "\n\t\t\t\tChua co tai khoan nao.Vui long dang ky!!!" << endl;
	}
	else {
		cout << "\n\t\t\t\tDANH SACH TAI KHOAN GAME\n";
		for (int i = 0; i < dem_so_luong_tai_khoan_tao; i++) {
			cout << "\n\t\t\t\t\TAI KHOAN THU " << i + 1
				<< "\n\t\t\t\tTEN TAI KHOAN : " << DATABASE_ACCOUNTS[i]
				<< "\n\t\t\t\tMAT KHAU : " << DATABASE_PASSWORDS[i]
				<< "\n\t\t\t\tINGAME : " << DATABASE_INGAME[i]
				<< "\n\t\t\t\tSO TIEN TAI KHOAN : " << DATABASE_MONEYGAME[i] << endl;
		}
	}

}

void DangKyTaiKhoan()
{
	//them tai khoan
	cin.ignore();
	cout << "\n\t\t\t\tDANG KY TAI KHOAN GAME" << endl;
	cout << "\t\t\t\tNhap tai khoan moi:";
	getline(cin, tk);
	cout << "\t\t\t\tNhap mat khau moi:";
	getline(cin, mk);
	cout << "\t\t\t\tNhap ten trong game:";
	getline(cin, ingame);
	cout << "\t\t\t\tNhap so tien can nap:";
	cin >> tt;
	if (dem_so_luong_tai_khoan_tao < MAX_ACCOUNTS + 1) {
		//them vao database
		DATABASE_ACCOUNTS[t] = tk;
		DATABASE_PASSWORDS[m] = mk;
		DATABASE_INGAME[n] = ingame;
		DATABASE_MONEYGAME[e] = tt;
		cout << "\t\t\t\tTHEM THANH CONG" << endl;
		dem_so_luong_tai_khoan_tao++;
		t++;
		m++;
		n++;
		e++;
	}
	else {
		cout << "\t\t\t\tTHEM KHONG THANH CONG" << endl;
	}
	Display();

}

void DangNhap()
{
	cin.ignore();
	cout << "\n\t\t\t\t===========LOGIN=============";
	cout << "\n\t\t\t\tNhap tai khoan :";
	getline(cin, taiKhoan);
	cout << "\t\t\t\tNhap mat khau  :";
	getline(cin, matKhau);
	if (KiemTraTaiKhoan(taiKhoan, matKhau) >= 0)
	{
		id = KiemTraTaiKhoan(taiKhoan, matKhau);
		cout << "\n\t\t\t\tCHAO MUNG BAN " << DATABASE_INGAME[id] << " !XIN HAY DAT CUOC!!!";
		while (true) {
			cout << "\n\t\t\t\tSO TIEN HIEN TAI: " << DATABASE_MONEYGAME[id];
			if (DATABASE_MONEYGAME[id] <= 0) {
				cout << "\n\t\t\t\tSo tien hien tai khong du de choi.Nap them!!!";
				char w = _getch();
				if (w == 13) {
					cout << endl;
					Display();
				}
			}
			else
			{
				DatCuoc(id);
				cin.ignore();
				cout << "\n\t\t\t\tBan chon: 1.TAI\t2.XIU"
					<< "\n\t\t\t\tChon:";
				getline(cin, rs);
				if (rs == "1")
					rs = "TAI";
				else
					rs = "XIU";
				TaiXiu(rs, tien, id);
				cout << "\n\t\t\t\tTiep tuc cuoc choi(ENTER) hay thoat ra man hinh chinh(Any key)???";
				char cc = _getch();
				if (cc != 13)
					Display();

			}
		}

	}
	else
	{
		cout << "\n\t\t\t\t!!!SAI THONG TIN. THU LAI SAU!!!" << endl;
		cout << "\n\t\t\t\tBan co muon tiep tuc choi ?(Y/N) :";
		char lc = _getch();
		if (lc == 'y' || lc == 'Y') {
			cout << endl;
			Display();
		}
		else {
			cout << "\n\t\t\t\tCHAO TAM BIET!!!";
			return;
		}
	}

}
int KiemTraTaiKhoan(string& tk, string& mk) {
	int i = 0;
	while (i < MAX_ACCOUNTS) {
		if (DATABASE_ACCOUNTS[i] == tk && DATABASE_PASSWORDS[i] == mk)
			return i;
		i++;
	}
	return -1;
}

string QuenMatKhau(string taikhoan) {
	int i = 0;
	while (i < dem_so_luong_tai_khoan_tao) {
		if (DATABASE_ACCOUNTS[i].compare(taikhoan) == 0)
			return (string)DATABASE_PASSWORDS[i];
		i++;
	}
	return "";
}

void DatCuoc(int& id)
{
	cout << "\n\t\t\t\t\tMUC TIEN\n"
		<< "\t\t\t\t1.10K\t2.20K\t3.50K\t4.100K\t5.200K"
		<< "\t6.500K\n\t\t\t\t7.1M\t8.3M\t9.5M\t10.10M\t11.50M\t12.100M" << endl;
	long long soTienDatCuoc;
	long long tongMucTien = 0;
	char tt;
	do {
		if (tongMucTien < DATABASE_MONEYGAME[id] && tien < DATABASE_MONEYGAME[id]) {
			cout << "\n\t\t\t\tMoi ban chon muc tien:";
			cin >> soTienDatCuoc;
			switch (soTienDatCuoc)
			{
			case 1:
				tongMucTien += 10000;
				break;
			case 2:
				tongMucTien += 20000;
				break;
			case 3:
				tongMucTien += 50000;
				break;
			case 4:
				tongMucTien += 100000;
				break;
			case 5:
				tongMucTien += 200000;
				break;
			case 6:
				tongMucTien += 500000;
				break;
			case 7:
				tongMucTien += 1000000;
				break;
			case 8:
				tongMucTien += 3000000;
				break;
			case 9:
				tongMucTien += 5000000;
				break;
			case 10:
				tongMucTien += 10000000;
				break;
			case 11:
				tongMucTien += 50000000;
				break;
			case 12:
				tongMucTien += 100000000;
				break;
			default:
				cout << "\t\t\t\tKhong co muc tien nay!!!";
				break;
			}
			tien = tongMucTien;
		}
		else if (tongMucTien >= DATABASE_MONEYGAME[id] && tien >= DATABASE_MONEYGAME[id])
		{
			cout << "\n\t\t\t\tKhong du tien thuc hien!!!" << endl;
		}
		cout << "\n\t\t\t\tTiep tuc dat cuoc ? (Y/N) :";
		cin >> tt;
	} while (tt == 'Y' || tt == 'y');
	cout << "\n\t\t\t\tTong muc dat duoc hien tai la :" << tongMucTien << endl;

}

void NapTien(int& id)
{
	cout << "\t\t\t\tNhap so tien can nap :";
	cin >> tien;
	if (tien >= 10000 && tien <= 5000000)
	{
		DATABASE_MONEYGAME[id] += tien;
		cout << "\n\t\t\t\tNAP TIEN THANH CONG!!!" << endl;
	}
	else {
		cout << "\n\t\t\t\tSO TIEN QUA LON!!!" << endl;
	}
	Display();

}

void RutTien()
{
	string tk, mk;
	int soTienRut;
	cin.ignore();
	cout << "\n\t\t\t\tNhap ten tai khoan:";
	getline(cin, tk);
	cout << "\t\t\t\tNhap mat khau:";
	getline(cin, mk);
	int index = KiemTraTaiKhoan(tk, mk);
	if (index >= 0)
	{
		cout << "\t\t\t\tNhap so tien can rut:";
		cin >> soTienRut;
		if (soTienRut <= DATABASE_MONEYGAME[index])
		{
			DATABASE_MONEYGAME[index] = DATABASE_MONEYGAME[index] - soTienRut;
			cout << "\n\t\t\t\tRut thanh cong. So du con lai trong tai khoan la " << DATABASE_MONEYGAME[index] << endl;
			cout << "\n\t\t\t\tBan co muon tiep tuc choi?(Y/N) :";
			char lc = _getch();
			if (lc == 'y' || lc == 'Y') {
				cout << endl;
				Display();
			}
			else {
				cout << "\n\t\t\t\tCHAO TAM BIET!!!";
				return;
			}
		}
		else
		{
			cout << "\t\t\t\tSo tien khong hop le.Vui long nhap lai!!!" << endl;
			cout << "\n\t\t\t\tBan co muon tiep tuc giao dich ?(Y/N) :";
			char lc = _getch();
			if (lc == 'y' || lc == 'Y') {
				cout << endl;
				Display();
			}
			else {
				cout << "\n\t\t\t\tCHAO TAM BIET!!!";
				return;
			}
		}
	}
	else
	{
		cout << "\n\t\t\t\tKhong co tai khoan nay!!!" << endl;
		cout << "\n\t\t\t\tBan co muon tiep tuc choi ?(Y/N) :";
		char lc = _getch();
		if (lc == 'y' || lc == 'Y') {
			cout << endl;
			Display();
		}
		else {
			cout << "\n\t\t\t\tCHAO TAM BIET!!!";
			return;
		}
	}
}

void TaiXiu(string& rs, long long& tien, int& id)
{
	srand(time(NULL));

	s1 = 1 + (rand() % (xiNgau));
	s2 = 1 + (rand() % (xiNgau));
	s3 = 1 + (rand() % (xiNgau));
	cout << "\n\t\t\t\tKET QUA XI NGAU";
	Sleep(1500);//Dung man hinh 1.5s
	cout << "\n\t\t\t\t=====" << "\t" << "=====" << "\t" << "=====" << endl
		<< "\t\t\t\t| " << s1 << " |" << "\t" << "| " << s2 << " |" << "\t" << "| " << s3 << " |" << endl
		<< "\t\t\t\t=====" << "\t" << "=====" << "\t" << "=====";
	int kq = s1 + s2 + s3;
	if (kq >= 3 && kq <= 10)
	{
		KET_QUA_TAI_XIU[dem_ket_qua] = "XIU";
		KET_QUA_DAT_CUOC[dem_ket_qua] = kq;
	}
	else if (kq >= 11 && kq <= 18)
	{
		KET_QUA_TAI_XIU[dem_ket_qua] = "TAI";
		KET_QUA_DAT_CUOC[dem_ket_qua] = kq;
	}
	dem_ket_qua++;


	cout << "\n\t\t\t\t" << "KET QUA:";
	if (KET_QUA_DAT_CUOC[dem_ket_qua - 1] == 3)
	{
		cout << "NO HU 3" << endl;
	}
	else if (KET_QUA_DAT_CUOC[dem_ket_qua - 1] == 18) {
		cout << "NO HU 18" << endl;
	}
	else {
		cout << KET_QUA_DAT_CUOC[dem_ket_qua - 1] << " " << KET_QUA_TAI_XIU[dem_ket_qua - 1] << endl;
	}


	if (rs == KET_QUA_TAI_XIU[dem_ket_qua - 1]) {
		cout << "\n\t\t\t\tBan doan chinh xac!!!" << endl;
		DATABASE_MONEYGAME[id] += tien;
		cout << "\n\t\t\t\tSo du hien tai la " << DATABASE_MONEYGAME[id] << endl;
	}
	else {
		cout << "\n\t\t\t\tBan doan sai roi.Doan lai nao!!!" << endl;
		DATABASE_MONEYGAME[id] -= tien;
		if (DATABASE_MONEYGAME[id] < 0) {
			DATABASE_MONEYGAME[id] = 0;
		}
		cout << "\n\t\t\t\tSo du hien tai la " << DATABASE_MONEYGAME[id] << endl;
	}

}

void Display()
{
	system("color 6");
	cout << "\n\t\t\t\t===GAME TAI XIU==="
		<< "\n\t\t\t\t1.CHOI GAME"
		<< "\n\t\t\t\t2.NAP TIEN"
		<< "\n\t\t\t\t3.RUT TIEN"
		<< "\n\t\t\t\t4.THOAT"
		<< "\n\t\t\t\t=================";
	int chon;
	int idx;
	char lc;
	cout << "\n\t\t\t\tMoi ban chon:";
	cin >> chon;
	switch (chon)
	{
	case 1:
		cout << "\n\t\t\t\t\=======LOGIN=======";
		cout << "\n\t\t\t\t1.Dang nhap\n\t\t\t\t2.Dang ky tai khoan moi"
			<< "\n\t\t\t\t3.Quen mat khau\n\t\t\t\t4.Xem thong tin tai khoan"
			<< "\n\t\t\t\tChon:";
		int c;
		cin >> c;
		if (c == 1)
		{
			DangNhap();
		}
		else if (c == 2)
		{
			DangKyTaiKhoan();
		}
		else if (c == 3)
		{
			cin.ignore();
			cout << "\n\t\t\t\tNhap ten tai khoan cua ban:";
			getline(cin, taiKhoan);
			if (QuenMatKhau(taiKhoan) != "")
			{
				cout << "\n\t\t\t\t" << "Mat khau cua ban la :" << QuenMatKhau(taiKhoan) << endl;
			}
			else
			{
				cout << "\n\t\t\t\tKhong co thong tin tai khoan nay!!!" << endl;

			}
			cout << "\n\t\t\t\tBan co muon tiep tuc choi ?(Y/N):";

			cin >> lc;
			if (lc == 'y' || lc == 'Y') {
				cout << endl;
				Display();
			}
			else {
				cout << "\n\t\t\t\tCHAO TAM BIET!!!";
				return;
			}
		}
		else if (c == 4)
		{
			TaiKhoan(DATABASE_ACCOUNTS, DATABASE_PASSWORDS, DATABASE_INGAME, DATABASE_MONEYGAME, dem_so_luong_tai_khoan_tao);
			cout << "\n\t\t\t\tBan co muon tiep tuc choi ?(Y/N) :";
			char lc = _getch();
			if (lc == 'y' || lc == 'Y') {
				cout << endl;
				Display();
			}
			else {
				cout << "\n\t\t\t\tCHAO TAM BIET!!!";
				return;
			}
		}
		else {
			cout << "\n\t\t\t\tKhong co thao tac nay!!!";
			cout << "\n\t\t\t\tBan co muon tiep tuc choi ?(Y/N) :";
			char lc = _getch();
			if (lc == 'y' || lc == 'Y') {
				cout << endl;
				Display();
			}
			else {
				cout << "\n\t\t\t\tCHAO TAM BIET!!!";
				return;
			}
		}
		break;
	case 2:
		cin.ignore();
		cout << "\n\t\t\t\tTHONG TIN NAP TIEN";
		cout << "\n\t\t\t\tNhap tai khoan:";
		getline(cin, tk);
		cout << "\t\t\t\tNhap mat khau:";
		getline(cin, mk);
		idx = KiemTraTaiKhoan(tk, mk);
		if (idx >= 0)
			NapTien(idx);
		else
		{
			cout << "\n\t\t\t\tKhong co tai khoan nay!!!" << endl;
			cout << "\n\t\t\t\tBan co muon tiep tuc choi ?(Y/N) :";
			char lc = _getch();
			if (lc == 'y' || lc == 'Y') {
				cout << endl;
				Display();
			}
			else {
				cout << "\n\t\t\t\tCHAO TAM BIET!!!";
				return;
			}
		}
		break;
	case 3:
		RutTien();
		break;
	case 4:
		cout << "\n\t\t\t\tHEN GAP LAI BAN LAN SAU. BYE!!!" << endl;
		break;
	default:
		cout << "\n\t\t\t\tKhong co thao tac nay!!!" << endl;
		cout << "\n\t\t\t\tBan co muon tiep tuc choi ?(Y/N) :";
		char lc = _getch();
		if (lc == 'y' || lc == 'Y') {
			cout << endl;
			Display();
		}
		else {
			cout << "\n\t\t\t\tCHAO TAM BIET!!!";
			return;
		}
		break;
	}
}


