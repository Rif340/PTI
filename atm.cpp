
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

struct data
{
	string nama;
	int umur;
	int pin;
	int noRek;
	int saldo;
	int statuspin = 0;
} nasabah[100];

void header()
{
	cout << "\n=================================================\n";
	cout << "|              ===ATM BERASAMA===               |\n";
	cout << "=================================================\n";
}
void pinBlok()
{
	cout << " Anda Telah 3x Salah Memasukan PIN" << endl;
	cout << " Akun Anda Telah di Blokir" << endl;
	sleep(2);
}
void bDaftar()
{
	system("cls");
	header();
	cout << " Nomor Nomor Rekening anda belum terdaftar" << endl;
	sleep(2);
}

int main()
{
	int Norek, penarikan, setor, pilihganti, z, pin1, pinBaru, menu, x = 0;
	char kembali;
	srand(time(NULL));

	do
	{
	awal:
		system("cls");
		header();
		cout << " 1. Daftar Nasabah\n";
		cout << " 2. Aktivasi\n";
		cout << " 3. Cek Data Nasabh\n";
		cout << " 4. Setor Tunai\n";
		cout << " 5. Cek Saldo\n";
		cout << " 6. Tarik Tunai\n";
		cout << " 7. Keluar\n";
		cout << "=================================================\n";
		cout << " Masukan Plihan : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			header();
			cout << "                Daftar Nasabah                   \n";
			cout << "=================================================\n";
			cout << " Masukan Nama Anda  : ";
			cin >> nasabah[x].nama;
			cout << " Masukan Umur Anda  : ";
			cin >> nasabah[x].umur;
			if (nasabah[x].umur < 17)
			{
				cout << " Maaf Umur Anda Belum Cukup\n";
			}
			else
			{
				cout << " Masukan PIN anda   : ";
				cin >> nasabah[x].pin;
				cout << " Masukan Saldo Awal : ";
				cin >> nasabah[x].saldo;
				sleep(2);
				system("cls");
				header();
				cout << "|           Pendaftaran Berhasail               |\n";
				cout << "=================================================\n";
				nasabah[x].noRek = rand();
				cout << " No Rekening Anda : " << nasabah[x].noRek << endl;
				cout << " Nama  : " << nasabah[x].nama << endl;
				cout << " Umur  : " << nasabah[x].umur << endl;
				cout << " PIN   : " << nasabah[x].pin << endl;
				cout << " Saldo : " << nasabah[x].saldo << endl;
				sleep(1);
			}
			x++;
			break;
		case 2:
			system("cls");
			header();
			cout << " Masukan No Rekening : ";
			cin >> Norek;
			cout << "=================================================\n";
			for (int i = 0; i < 100; i++)
			{
				if (Norek == nasabah[i].noRek)
				{
					z += 1;
					cout << " PIN Baru : ";
					cin >> pin1;
					nasabah[i].pin = pin1;
					cout << " Konfirmasi PIN Baru : ";
					cin >> pinBaru;
					if (pinBaru == nasabah[i].pin)
					{
						sleep(2);
						cout << " PIN berhasil di peerbarui\n";
						nasabah[i].statuspin = 0;
					}
				}
			}
			if (z == 0)
			{
				bDaftar();
			}
			z = 0;
			break;
		case 3:
			system("cls");
			header();
			cout << " Masukan No Rekening : ";
			cin >> Norek;
			for (int j = 0; j < 100; j++)
			{
				if (Norek == nasabah[j].noRek)
				{
					if (nasabah[j].statuspin == 3)
					{
						z += 1;
						cout << " Rekening Anda Telah di Blokir\n";
						break;
					}
					z += 1;
					do
					{
						if (nasabah[j].statuspin > 0)
						{
							cout << "=================================================\n";
							cout << " Anda telah salah " << nasabah[j].statuspin << "x memasukan PIN!" << endl;
						}
						cout << "=================================================\n";
						cout << " Masukan PIN : ";
						cin >> pin1;
						if (pin1 == nasabah[j].pin)
						{
							cout << " Nama : " << nasabah[j].nama << endl;
							cout << " Umur : " << nasabah[j].umur << endl;
							cout << " PIN  : " << nasabah[j].pin << endl;
							sleep(2);
							break;
						}
						else
						{
							system("cls");
							header();
							nasabah[j].statuspin++;
						}
					} while (nasabah[j].statuspin < 3);
					if (nasabah[j].statuspin == 3)
					{
						pinBlok();
						goto awal;
					}
				}
			}
			if (z == 0)
			{
				bDaftar();
			}
			z = 0;
			break;
		case 4:
			system("cls");
			header();
			cout << " Masukan No Rekening : ";
			cin >> Norek;
			for (int k = 0; k < 100; k++)
			{
				if (Norek == nasabah[k].noRek)
				{
					if (nasabah[k].statuspin == 3)
					{
						z += 1;
						cout << " Rekening Anda Telah di Blokir\n";
						break;
					}
					z += 1;
					do
					{
						if (nasabah[k].statuspin > 0)
						{
							cout << "=================================================\n";
							cout << "Anda telah salah " << nasabah[k].statuspin << "x memasukan PIN!" << endl;
						}
						cout << "=================================================\n";
						cout << " Masukan PIN : ";
						cin >> pin1;
						if (pin1 == nasabah[k].pin)
						{

							system("cls");
							header();
							cout << " Saldo awal            : " << nasabah[k].saldo << endl;
							cout << " Masukan Nominal Setor : ";
							cin >> setor;
							if (setor % 50000 == 0)
							{
								nasabah[k].saldo += setor;
								cout << " Setor Tunai Berhasil\n";
								sleep(1);
								system("cls");
								header();
								cout << " Total Saldo : " << nasabah[k].saldo << endl;
							}
							else
							{
								cout << "\n Setor Tunai Gagal\n";
								cout << " ATM hanya menerima uang Rp.50000 dan Rp.100000\n";
							}
							break;
						}
						else
						{
							system("cls");
							header();
							nasabah[k].statuspin++;
						}
					} while (nasabah[k].statuspin < 3);
					if (nasabah[k].statuspin == 3)
					{
						pinBlok();
						goto awal;
					}
				}
			}
			if (z == 0)
			{
				bDaftar();
			}
			z = 0;
			break;
		case 5:
			system("cls");
			header();
			cout << " Masukan No Rekening : ";
			cin >> Norek;
			for (int l = 0; l < 100; l++)
			{
				if (nasabah[l].statuspin == 3)
				{
					z += 1;
					cout << " Rekening Anda Telah di Blokir\n";
					break;
				}
				z += 1;
				if (Norek == nasabah[l].noRek)
				{
					do
					{
						if (nasabah[l].statuspin > 0)
						{
							cout << " Anda telah salah " << nasabah[l].statuspin << "x memasukan PIN!" << endl;
						}
						cout << "=================================================\n";
						cout << " Masukan PIN : ";
						cin >> pin1;
						if (pin1 == nasabah[l].pin)
						{
							cout << " Saldo Anda : " << nasabah[l].saldo << endl;
							break;
						}
						else
						{
							system("cls");
							header();
							nasabah[l].statuspin++;
						}
					} while (nasabah[l].statuspin < 3);
					if (nasabah[l].statuspin == 3)
					{
						pinBlok();
						goto awal;
					}
				}
				break;
			}
			if (z == 0)
			{
				bDaftar();
			}
			z = 0;
			break;
		case 6:
			system("cls");
			header();
			cout << " Masukan No Rekening : ";
			cin >> Norek;
			for (int m = 0; m < 100; m++)
			{
				if (Norek == nasabah[m].noRek)
				{
					if (nasabah[m].statuspin == 3)
					{
						z += 1;
						cout << " Rekening Anda Telah di Blokir\n";
						break;
					}
					z += 1;
					do
					{
						if (nasabah[m].statuspin > 0)
						{
							cout << "=================================================\n";
							cout << " Anda telah salah " << nasabah[m].statuspin << "x memasukan PIN!" << endl;
						}
						cout << "=================================================\n";
						cout << " Masukan PIN : ";
						cin >> pin1;
						if (pin1 == nasabah[m].pin)
						{
							system("cls");
							header();
							cout << " Masukan Nominal Penarikan : ";
							cin >> penarikan;
							if (penarikan % 50000 != 0)
							{
								system("cls");
								cout << " Transaksi Gagal\n";
								cout << " Anda Hanya Bisa Melakukan Penarikan Rp.50000\n";
							}
							else
							{
								if (penarikan >= nasabah[m].saldo)
								{
									system("cls");
									header();
									cout << " Transaksi Gagal!" << endl;
									cout << " Karena Saldo Anda kurang!" << endl;
									cout << " Sisa Saldo Anda: Rp." << nasabah[m].saldo << endl;
								}
								else if (penarikan <= 0)
								{
									cout << " mana ada orang tarik tunai nominal " << penarikan << endl;
								}
								else
								{
									system("cls");
									header();
									nasabah[m].saldo -= penarikan;
									cout << " Transaksi Berhasil\n";
									cout << " Sisa Saldo Anda: Rp." << nasabah[m].saldo << endl;
								}
							}
							break;
						}
						else
						{
							system("cls");
							header();
							nasabah[m].statuspin++;
						}
					} while (nasabah[m].statuspin < 3);
					if (nasabah[m].statuspin == 3)
					{
						pinBlok();
						goto awal;
					}
				}
			}
			if (z == 0)
			{
				bDaftar();
			}
			z = 0;
			break;
		case 7:
			system("cls");
			header();
			cout << "      Terimakasih Sudah Menggunakan ATM ini\n";
			cout << "=================================================\n";
			exit(0);
		}
		cout << "=================================================\n";
		cout << " Kembali ke Menu?[y/t] ";
		cin >> kembali;
	} while (kembali == 'y' || kembali == 'Y');
}