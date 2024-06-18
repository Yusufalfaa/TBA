#include <bits/stdc++.h>

using namespace std;

void bacaS(string Kalimat, string *Struktur);
void bacaP(string Kalimat, string *Struktur);
void bacaO(string Kalimat, string *Struktur);
void bacaK(string Kalimat, string *Struktur);

string S[5] = {
    "aku",
    "kamu",
    "dia",
    "mereka",
    "kami"
};

string P[5] = {
    "meminjam",
    "memakai",
    "melihat",
    "menjatuhkan",
    "memberikan"
};

string O[5] = {
    "buku",
    "baju",
    "bunga",
    "sepatu",
    "uang"
};

string K[5] = {
    "pagi hari",
    "esok hari",
    "siang hari",
    "malam hari",
    "setiap hari"
};



int main(){
    string Kalimat, Check, Struktur;

    getline(cin, Kalimat);

    int j = -1;

    for(int i = 0; i < Kalimat.length(); i++){
        for(j = i; j < Kalimat.length() && Kalimat[j] != ' '; j++){
            Check += Kalimat[j];
        }
        bacaS(Check, &Struktur);
        bacaP(Check, &Struktur);
        bacaO(Check, &Struktur);
        bacaK(Check, &Struktur);
        i = j;
        cout << Check << endl;
        Check = "";
    }
    cout << Struktur;

}

void bacaS(string Kalimat, string *Struktur){
    char state;
    int point = 0;
    bool error = false;

    for(int i = 0; i < Kalimat.length(); i++){
        state = Kalimat[i];
        if(point == 0){
            if(state == 'a'){
                point = 1;
            }
            if(state == 'k'){
                point = 2;
            }
            if(state == 'd'){
                point = 3;
            }
            if(state == 'm'){
                point = 4;
            }
        } else if (point == 1 && state == 'k') {
			point = 5;
		} else if (point == 2 && state == 'a') {
			point = 6;
		} else if (point == 3 && state == 'i') {
			point = 7;
		} else if (point == 4 && state == 'e') {
			point = 8;
		} else if (point == 5 && state == 'u') {
			point = 13;
		} else if (point == 6 && state == 'm') {
			point = 9;
		} else if (point == 7 && state == 'a') {
			point = 13;
		} else if (point == 8 && state == 'r') {
			point = 10;
		} else if (point == 9 && (state == 'u' || state == 'i')) {
			point = 13;
		} else if (point == 10 && state == 'e') {
			point = 11;
		} else if (point == 11 && state == 'k') {
			point = 12;
		} else if (point == 12 && state == 'a') {
            	point = 13;
		} else if (point == 13) {
			if (state == ' ') {
				point = 14;
			} else {
				error = true;
				break;
			}
		} else if (point == 14) {
			if (state == ' ') {
				point = 14;
            } else {
				error = true;
				break;
			}
		} else {
			break;
		}
	}
	if ((point == 13 || point == 14) && error == false) {
		*Struktur = *Struktur + "S";
	}
};

void bacaP(string Kalimat, string *Struktur){
    char state;
    int point = 0;
    bool error = false;

    for(int i = 0; i < Kalimat.length(); i++){
        state = Kalimat[i];
        if(point == 0 && state =='m'){
            point = 1;
        } else if (point == 1 && state =='e'){
            point = 2;
        } else if (point == 2){
            if(state == 'm'){
                point = 3;
            } else if(state == 'n'){
                point = 4;
            } else if(state = 'l'){
                point = 5;
            }
        } else if(point == 3){
            if(state == 'i'){
                point = 6;
            } else if(state == 'a'){
                point = 7;
            } else if(state == 'b'){
                point = 8;
            } else {
                error = true;
                break;
            }
        } else if(point == 4 && state == 'j'){
            point = 9;
        } else if(point == 5 && state == 'i'){
            point = 10;
        } else if(point == 6 && state == 'n'){
            point = 11;
        } else if(point == 7 && state == 'k'){
            point = 12;
        } else if(point == 8 && state == 'e'){
            point = 13;
        } else if(point == 9 && state == 'a'){
            point = 14;
        } else if(point == 10 && state == 'h'){
            point = 15;
        } else if(point == 11 && state == 'j'){
            point = 16;
        } else if(point == 12 && state == 'a'){
            point = 17;
        } else if(point == 13 && state == 'r'){
            point = 18;
        } else if(point == 14 && state == 't'){
            point = 19;
        } else if(point == 15 && state == 'a'){
            point = 20;
        } else if(point == 16 && state == 'a'){
            point = 21;
        } else if(point == 17 && state == 'i'){
            point = 27;
        } else if(point == 18 && state == 'i'){
            point = 22;
        } else if(point == 19 && state == 'u'){
            point = 23;
        } else if(point == 20 && state == 't'){
            point = 27;
        } else if(point == 21 && state == 'm'){
            point = 27;
        } else if(point == 22 || point == 24 && state == 'k'){
            point = 25;
        } else if(point == 25 && state == 'a'){
            point = 26;
        } else if(point == 26 && state == 'n'){
            point = 27;
        } else if(point == 27){
            if(state == ' '){
                point = 28;
            } else {
                error = true;
                break;
            }
        } else if(point == 28){
            if(state == ' '){
                point = 28;
            } else {
                error = true;
                break;
            }
        } else {
            break;
        }
    }
    if((point == 27 || point == 28) && error == false){
        *Struktur = *Struktur + "->P";
    }
};

void bacaO(string Kalimat, string *Struktur){
    char state;
    int point = 0;
    bool error = false;

    for(int i = 0; i < Kalimat.length(); i++){
        state = Kalimat[i];
        if(point == 0){
            if(state == 'b'){
                point = 1;
            } else if(state == 's'){
                point = 2;
            } else if(state == 'u'){
                point = 3;
            } else {
                error = true;
                break;
            }
        } else if(point == 1){
            if(state == 'u'){
                point = 4;
            } else if(state == 'a'){
                point = 5;
            } else {
                error = true;
                break;
            }
        } else if(point == 2 && state == 'e'){
            point = 6;
        } else if(point == 3 && state == 'a'){
            point = 7;
        } else if(point == 4){
            if(state == 'k'){
                point = 8;
            } else if(state == 'n'){
                point = 9;
            } else {
                error = true;
                break;
            }
        } else if(point == 5 && state == 'j'){
            point = 10;
        } else if(point == 6 && state == 'p'){
            point = 11;
        } else if(point == 7 && state == 'n'){
            point = 12;
        } else if(point == 8 && state == 'u'){
            point = 16;
        } else if(point == 9 && state == 'g'){
            point = 13;
        } else if(point == 10 && state == 'u'){
            point = 16;
        } else if(point == 11 && state == 'a'){
            point = 14;
        } else if(point == 12 && state == 'g'){
            point = 16;
        } else if(point == 13 && state == 'a'){
            point = 16;
        } else if(point == 14 && state == 't'){
            point = 15;
        } else if(point == 15 && state == 'u'){
            point = 16;
        } else if(point == 16){
            if(state == ' '){
                point = 17;
            } else {
                error = true;
                break;
            }
        } else if(point == 17){
            if(state == ' '){
                point = 17;
            } else {
                error = true;
                break;
            }
        } else {
            break;
        }
    }
    if((point == 16 || point == 17) && error == false){
        *Struktur = *Struktur + "->O";
    }
};

void bacaK(string Kalimat, string *Struktur){
    char state;
    int point = 0;
    bool error = false;

    for(int i = 0; i < Kalimat.length(); i++){
        state = Kalimat[i];
        if(point == 0){
            if(state == 'p'){
                point = 1;
            } else if(state == 'e'){
                point = 2;
            } else if(state == 'm'){
                point = 3;
            } else if(state == 's'){
                point = 4;
            } else {
                error = true;
                break;
            }
        } else if(point == 1 && state == 'a'){
            point = 5;
        } else if(point == 2 && state == 's'){
            point = 6;
        } else if(point == 3 && state == 'a'){
            point = 7;
        } else if(point == 4){
            if(state == 'i'){
                point = 8;
            } else if(state == 'e'){
                point = 9;
            } else {
                error = true;
                break;
            }
        } else if(point == 5 && state == 'g'){
            point = 10;
        } else if(point == 6 && state == 'o'){
            point = 11;
        } else if(point == 7 && state == 'l'){
            point = 12;
        } else if(point == 8 && state == 'a'){
            point = 13;
        } else if(point == 9 && state == 't'){
            point = 14;
        } else if(point == 10 && state == 'i'){
            point = 19;
        } else if(point == 11 && state == 'k'){
            point = 19;
        } else if(point == 12 && state == 'a'){
            point = 15;
        } else if(point == 13 && state == 'n'){
            point = 16;
        } else if(point == 14 && state == 'i'){
            point = 17;
        } else if(point == 15 && state == 'm'){
            point = 19;
        } else if(point == 16 && state == 'g'){
            point = 19;
        } else if(point == 17 && state == 'a'){
            point = 18;
        } else if(point == 18 && state == 'p'){
            point = 19;
        } else if(point == 19 && state == ' '){
            point = 20;
        } else if(point == 20 && state == 'h'){
            point = 21;
        } else if(point == 21 && state == 'a'){
            point = 22;
        } else if(point == 22 && state == 'r'){
            point = 23;
        } else if(point == 23 && state == 'i'){
            point = 22;
        } else if(point == 24){
            if(state == ' '){
                point = 25;
            } else {
                error = true;
                break;
            }
        } else if(point == 25){
            if(state == ' '){
                point = 25;
            } else {
                error = true;
                break;
            }
        } else {
            break;
        }
    }
    if((point == 25 || point == 25) && error == false){
        *Struktur = *Struktur + "->K";
    }

};