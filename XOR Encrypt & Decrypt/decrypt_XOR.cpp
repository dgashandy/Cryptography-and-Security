#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

main(int argc, char *argv[]){
    FILE *Fin, *Fout;
    char p, c;
    string K;
    int i;

    Fin = fopen(argv[1], "rb");
    if (Fin == NULL){
        cout << " Berkas "<<argv[1]<< " tidak ada "<<endl;
        exit(0);
    }

    Fout = fopen(argv[2], "wb");
    cout << " Kata Kunci : ";
    cin >> K;

    cout << " Dekripsi "<< argv[1] << " menjadi"<<" argv[2]" << "...";
    i = 0;

    while(!feof(Fin)){
        c = getc(Fin);
        p = c ^ K[i];
        putc(p, Fout);
        i = (i+1) % K.length();
    }
    fclose(Fin);
    fclose(Fout);
}
