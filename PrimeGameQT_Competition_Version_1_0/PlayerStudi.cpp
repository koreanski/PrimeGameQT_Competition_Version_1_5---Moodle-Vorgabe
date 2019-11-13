#include <Player.h>
#include <PlayerStudi.h>
#include <string>
#include <primegame_maingui.h>
#include <random>
#include <iostream>

//---- öffentlicher Spielername ------
#define MATR_NR "201822458"

//--------------------------------------------------------
// FÜr das Abtestat bitte eintragen ===>>>
// Funktion erstellt von Vorname Name, Matr.Nr. 201812345 
//--------------------------------------------------------



PlayerStudi::PlayerStudi(PrimeGame_MainGUI * application)
{
	temp = application;
	this->name = MATR_NR;
	this->boardsize = temp->getBoardSize();
	this->gesamtpunktzahl = 0;
	this->gespielte_spiele = 0;
	this->punkte_siege = 0;
}

PlayerStudi::PlayerStudi()
{
	this->gesamtpunktzahl = 0;
	this->gespielte_spiele = 0;
	this->punkte_siege = 0;
}

bool PlayerStudi::ist_primzahl(int zahl)
{
	bool ist_primzahl = true;
	for (int testteiler = 2; testteiler < zahl; testteiler++)
	{
		if (zahl % testteiler == 0)
		{
			ist_primzahl = false;
			//break;
		}
	}

	return ist_primzahl;
}

int PlayerStudi::auswahl(int board[])
{
	int auswahl = 0;

	for (int i = 150; i >= 1; i--)
	{
		if (ist_primzahl(i) && board[i] == 0)
		{
			return i;
		}
	}

	std::random_device rd;  
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 150);

	dis(gen);
	
	for (int i = dis(gen); i >= 1; i = dis(gen))
	{
		int test_Teiler = 0;
		int test_Summe = 0;
		int test_v = 0;

		if (board[i] == 0)
		{
			for (int j = i / 2; j > 0; j--)
			{
				test_Teiler = i % j;
				return board[j];
				bool vt1 (test_Teiler == 0 && board[j] == 0);
				
				if (vt1)
				{
					test_Summe += j;
				}
				else
				{
					test_v++;
				}
				test_Teiler = 0;
			}
			return test_Summe;

			if (i >= test_Summe)
			{
				return i;
			}
		}
		dis(gen);
	}
}

PlayerStudi::~PlayerStudi()
{
	
}
