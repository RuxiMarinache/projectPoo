#include<iostream>
#include<fstream>
using namespace std;

// domeniul ales contine literele M si R: MOBILIER

class Canapea {
public:
    // Atribute normale
    string marca;
    int numarLocuri;

    // Atribute statice
    static int numarTotalCanapele;

    // Atribute constante
    const int capacitateMaxima;

    // Pointer alocat dinamic
    int* pret;

    // Constructor implicit
    Canapea() : marca("Necunoscuta"), numarLocuri(0), capacitateMaxima(0) {
        pret = new int;
        *pret = 0;

        numarTotalCanapele++;
    }

      
    // Constructor cu 2 parametri
    Canapea(string marca, int numarLocuri) : marca(marca), numarLocuri(numarLocuri), capacitateMaxima(0) {  
        pret = new int;
        *pret = 0;

        numarTotalCanapele++;
    }

    // Constructor cu 3 parametri
    Canapea(string marca, int numarLocuri, int pret) : marca(marca), numarLocuri(numarLocuri), capacitateMaxima(0) {
        this->pret = new int;
        *(this->pret) = pret;

        numarTotalCanapele++;
    }


    // Destructor pt a elibera memoria alocată dinamic
    ~Canapea() {
        delete pret;
        numarTotalCanapele--;
    }

    // Functie pt afișare 
    void afisareInfoCanapea() {
        cout << "Marca: " << marca << ", Numar locuri: " << numarLocuri << ", Pret: " << *pret << endl;
    }

    // Funcție statică pentru a mari prețul cu 10%
    static void marestePretul(Canapea& canapea) {
        *canapea.pret *= 1.1;
    }

};

// Inițializare atribut static
int Canapea::numarTotalCanapele = 0;

class Dulap {
public:
    // Atribute normale
    string material;
    int numarRafturi;

    // Atribute statice
    static int numarTotalDulapuri;

    // Atribute constante
    const int capacitateMaxima;

    // Pointer alocat dinamic
    double* pret;

    // Constructor implicit
    Dulap() : material("Necunoscut"), numarRafturi(0), capacitateMaxima(0) {
        pret = new double;
        *pret = 0.0;

        numarTotalDulapuri++;
    }

    // Constructor cu 2 parametri
    Dulap(string material, int numarRafturi) : material(material), numarRafturi(numarRafturi), capacitateMaxima(0) {
        pret = new double;
        *pret = 0.0;

        numarTotalDulapuri++;
    }

    // Constructor cu 3 parametri
    Dulap(string material, int numarRafturi, double pret) : material(material), numarRafturi(numarRafturi), capacitateMaxima(10) {
        this->pret = new double;
        *(this->pret) = pret;

        numarTotalDulapuri++;
    }

    // Destructor
    ~Dulap() {
        delete pret;
        numarTotalDulapuri--;
    }

    // Functie pt afișare info dulap
    void afisareInfoDulap() {
        cout << "Material: " << material << ", Numar rafturi: " << numarRafturi << ", Pret: " << *pret << endl;
    }

    // Funcție statică pentru a micșora prețul cu 5%
    static void micsoreazaPretul(Dulap& dulap) {
        *(dulap.pret) *= 0.95;
    }
};


// Inițializare atribut static
int Dulap::numarTotalDulapuri = 0;


class Pat {
public:
    // Atribute normale
    string material;
    int dimensiune;

    // Atribute statice
    static int numarTotalPaturi;

    // Atribute constante
    const string stil;
    const int capacitateMaxima;

    // Pointer alocat dinamic
    double* pret;

    // Constructor implicit
    Pat() : material("Necunoscut"), dimensiune(0), stil("Necunoscut"), capacitateMaxima(0) {
        pret = new double;
        *pret = 0.0;

        numarTotalPaturi++;
    }

    // Constructor cu 2 parametri
    Pat(string material, int dimensiune) : material(material), dimensiune(dimensiune),  stil("Necunoscut"), capacitateMaxima(0) {
        pret = new double;
        *pret = 0.0;

        numarTotalPaturi++;
    }

    // Constructor cu 3 parametri
    Pat(string material, int dimensiune, double pret) : material(material), dimensiune(dimensiune), stil("Necunoscut"), capacitateMaxima(0) {
        this->pret = new double;
        *(this->pret) = pret;

        numarTotalPaturi++;
    }

    // Destructor pentru a elibera memoria alocată dinamic
    ~Pat() {
        delete pret;
        numarTotalPaturi--;
    }

    // Metoda pentru a afișa informații despre pat
    void afisareInfoPat() {
        cout << "Material: " << material << ", Dimensiune: " << dimensiune << ", Pret: " << *pret << endl;
    }

    // Funcție statică pentru a mari prețul cu 200
    static void marestePretulCu200(Pat& pat) {
        *(pat.pret) += 200.0;
    }
};

// Inițializare atribut static
int Pat::numarTotalPaturi = 0;

int main() {
    cout << "---------------- CANAPELE ----------------" << endl;

    Canapea canapeaImplicita;
    canapeaImplicita.afisareInfoCanapea();

    Canapea canapeaPersonalizata("IKEA", 3);
    canapeaPersonalizata.afisareInfoCanapea();

    Canapea canapeaCuPret("Mobexpert", 4, 2500);
    canapeaCuPret.afisareInfoCanapea();

    // Afisare nr total
    cout << "Numar total de canapele: " << Canapea::numarTotalCanapele << endl;

    // Funcția statica canapea
    cout << "Pret initial: " << *canapeaCuPret.pret << endl;
    Canapea::marestePretul(canapeaCuPret);
    cout << "Pret dupa majorare cu 10%: " << *canapeaCuPret.pret << endl;

    cout << endl << "---------------- DULAPURI ----------------" << endl;
    Dulap dulapImplicit;
    dulapImplicit.afisareInfoDulap();

    Dulap dulapPersonalizat("Lemn", 4);
    dulapPersonalizat.afisareInfoDulap();

    Dulap dulapCuPret("Metal", 5, 1000.5);
    dulapCuPret.afisareInfoDulap();

    // Afisare nr total
    cout << "Numar total de dulapuri: " << Dulap::numarTotalDulapuri << endl;

    // Funcția statica dulap
    cout << "Pret initial: " << *dulapCuPret.pret << endl;
    Dulap::micsoreazaPretul(dulapCuPret);
    cout << "Pret dupa micsorare cu 5%: " << *dulapCuPret.pret <<endl;

    cout << endl << "---------------- PATURI ----------------" << endl;
    Pat patImplicit;
    patImplicit.afisareInfoPat();

    Pat patPersonalizat("Lemn", 180);
    patPersonalizat.afisareInfoPat();

    Pat patCuPret("Piele", 220, 1800);
    patCuPret.afisareInfoPat();

    // Afisare nr total
   cout << "Numar total de paturi: " << Pat::numarTotalPaturi << endl;

   // Funcția statica pat
   cout << "Pret initial: " << *patCuPret.pret << endl;
   Pat::marestePretulCu200(patCuPret);
   cout << "Pret dupa majorare cu 200: " << *patCuPret.pret << endl;

    return 0;
}