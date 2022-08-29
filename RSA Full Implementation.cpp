#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

string plainteks, cipherteks;
long int p, q, n, e, d, totient, temp[100];

// Check the number is prime or not
int apakahPrima(long int x)
{
    long int i, j;

    j = sqrt(x);
    for (i = 2; i <= j; i++)
    {
        if (x % i == 0)
        {
            // IF the number is not prime
            return 0;
        }
    }
    // IF the number is prime
    return 1;
}

// Find the private key
int hitung_d(long int e, long int totient)
{
    long int k, h, d;

    k = 1;
    while (1)
    {
        d = k * e;
        h = d % totient;
        if (h == 1)
        {
            cout << " Kunci Priate (d) : " << k << endl;
            return k;
        }
        else
        {
            k = k + 1;
        }
    }
}

// Find GCD of two number(A,B)
int gcd(long int a, long int b)
{
    long int r, temp;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Create public Key E and private key D
void pembangkitanKunci(){
    int test;

    cout << " Input parameter kunci : "<<endl;
    cout << " p : "; cin >> p;

    test = apakahPrima(p);
    if(test==0){
        cout << "Bukan bilangan prima";
        exit(0);
    }

    cout << " q : "; cin >> q;
    test = apakahPrima(q);
    if(test==0){
        cout << "Bukan bilangan prima";
        exit(0);
    }
    
    n = p*q;
    totient = (p-1)*(q-1);
    cout << " Kunci Publik (E) = "; cin >> e;
    cout << endl;
    cout << " Luaran : "<< endl;
    cout << " Totient = "<< totient <<endl;
    test = gcd(e, totient);

    if (test == 1){
        d = hitung_d(e, totient);
    }
    else{
        cout << " e tidak relatif prima dengan totient";
        exit(0);
    }
}

// Random encrypt based on generated keys
void enkripsi(){
    int panjang;
    long int hasil, m,i,j;
    char c;

    cout << " Ketikkan pesan : "<<endl;
    cin.ignore(); getline(cin, plainteks);
    panjang = plainteks.length();

    cipherteks = "";
    for (i=0;i<panjang;i++){
        m = plainteks[i];
        m = m-96;
        hasil = 1;

        for(j=0;j<e;j++){
            hasil = hasil*m;
            hasil = hasil%n;
        }
        temp[i] = hasil;
        c = hasil+96;
        cipherteks = cipherteks+c;
    }
    cout << " Cipherteks : "<<endl << cipherteks <<endl;
}

void dekripsi(){
    int panjang;
    long int c, hasil,i,j;
    char m;

    panjang = plainteks.length();
    plainteks = "";
    for(i=0;i<panjang;i++){
        c = temp[i];
        hasil = 1;

        for(j = 0; j<d;j++){
            hasil = hasil*c;
            hasil = hasil%n;
        }
        m = hasil + 96;
        plainteks = plainteks +m;
    }

    cout << " Plainteks : "<<endl<<plainteks<<endl;
}

main(){
    bool stop;
    int pil;

    stop = false;
    while(!stop){
        cout << " Menu : "<<endl;
        cout << " 1. Pembangkitan Kunci "<<endl;
        cout << " 2. Enkripsi "<<endl;
        cout << " 3. Dekripsi "<<endl;
        cout << " 4. Exit "<<endl;
        cout << " Pilih menu :"; cin >> pil;
        cout << endl;
        switch(pil){
            case 1 : pembangkitanKunci(); break;
            case 2 : enkripsi() ; break;
            case 3 : dekripsi() ; break;
            case 4 : stop = true; break;
        }
    }
}
