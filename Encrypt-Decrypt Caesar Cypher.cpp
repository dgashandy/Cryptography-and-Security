#include<iostream>
#include<string.h>

void enkripsi(){
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << " Enter Message : ";
    cin.ignore();
    getline(cin, plainteks);
    cout << " Enter number of move : ";

    //Initiate null string on cypher text
    cipherteks = "";

    for(i=0;i<plainteks.length();i++){
        c = plainteks[i];
        if(isalpha(C)){
            c = toupper(C);
            c = c - 65;
            c = (c+k) % 26;
            c = c + 65;
        }
        cipherteks = cipherteks + c;
    }
    cout << "Cipherteks : "<<cipherteks<<endl;
}

void deskripsi(){
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << " Enter cypher teks : ";
    cin.ignore();
    getline(cin, cipherteks);
    cout << " Enter number of move (0-25) : ";
    cin >> k;

    plainteks = "";

    for (i =0; i<cipherteks.length();i++){
        c = cipherteks[i];
        if(isalpha(c)){
            c = toupper(c);
            c = c - 65;
            if(c-k<0){
                c = 26 + (c-k);
            }
            else{
                c = (c-k) % 26;
                c = c + 65;
                c = tolower(C);
            }
        }
        plainteks = plainteks + c;
    }
    cout << " Plainteks : "<<plainteks<<endl;
    
}

main(){
    int pil; bool stop;
    stop = false;

    while(!stop){
        cout << " Menu : "<<endl;
        cout << " 1.Enkripsi "<<endl;
        cout << " 2.Dekripsi "<<endl;
        cout << " 3.Exit"<<endl;
        cout << " Pilih menu : ";
        cin >> pil;
        switch(pil){
            case 1 : enkripsi(); break;
            case 2 : dekripsi(); break;
            case 3 : stop = true; break; 
        }
    }
}
