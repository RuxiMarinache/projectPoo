#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

// domeniul ales contine literele M si R: MOBILIER

class Canapea {
private:
    string marca;
    int numarLocuri;
    static int numarTotalCanapele;
    const int capacitateMaxima;
    int* pret;


public:
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

    // Constructor de copiere
    Canapea(const Canapea& other) : marca(other.marca), numarLocuri(other.numarLocuri), capacitateMaxima(other.capacitateMaxima) {
        // Allocați spațiu pentru pointer în heap și copiați valoarea
        this->pret = new int;
        *(this->pret) = *(other.pret);

        // Actualizăm numărul total de canapele
        numarTotalCanapele++;
    }

    // Destructor pt a elibera memoria alocată dinamic
    ~Canapea() {
        delete pret;
        numarTotalCanapele--;
    }

    // Get-eri
    string getMarca() const {
        return marca;
    }

    int getNumarLocuri() const {
        return numarLocuri;
    }

    int getPret() const {
        return *pret;
    }

    // Set-eri
    void setMarca(const string& newMarca) {
        marca = newMarca;
    }

    void setNumarLocuri(int newNumarLocuri) {
        numarLocuri = newNumarLocuri;
    }

    void setPret(int newPret) {
        *pret = newPret;
    }

    static int getNumarTotalCanapele() {
        return numarTotalCanapele;
    }

    // Functie pt afișare 
    void afisareInfoCanapea() {
        cout << "Marca: " << marca << ", Numar locuri: " << numarLocuri << ", Pret: " << *pret << endl;
    }

    // Funcție statică pentru a mari prețul cu 10%
    static void marestePretul(Canapea& canapea) {
        *canapea.pret *= 1.1;
    }

    // Funcție globală prietenă cu clasa Canapea
    friend void afiseazaInformatiiCanapea(const Canapea& canapea);

};

// Inițializare atribut static
int Canapea::numarTotalCanapele = 0;

class Dulap {
private:
    string material;
    int numarRafturi;
    static int numarTotalDulapuri;
    const int capacitateMaxima;
    double* pret;

public:
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

    // Constructor de copiere
    Dulap(const Dulap& d) : material(d.material), numarRafturi(d.numarRafturi), capacitateMaxima(d.capacitateMaxima) {
        this->pret = new double;
        *(this->pret) = *(d.pret);
    }

    // Destructor
    ~Dulap() {
        delete pret;
        numarTotalDulapuri--;
    }

    // Get-eri
    string getMaterial() const {
        return material;
    }

    int getNumarRafturi() const {
        return numarRafturi;
    }

    double getPret() const {
        return *pret;
    }

    // Set-eri
    void setMaterial(const string& newMaterial) {
        material = newMaterial;
    }

    void setNumarRafturi(int newNumarRafturi) {
        numarRafturi = newNumarRafturi;
    }

    void setPret(double newPret) {
        *pret = newPret;
    }

    static int getNumarTotalDulapuri() {
        return numarTotalDulapuri;
    }

    // Functie pt afișare info dulap
    void afisareInfoDulap() {
        cout << "Material: " << material << ", Numar rafturi: " << numarRafturi << ", Pret: " << *pret << endl;
    }

    // Funcție statică pentru a micșora prețul cu 5%
    static void micsoreazaPretul(Dulap& dulap) {
        *(dulap.pret) *= 0.95;
    }

    // Funcție globală prietenă cu clasa Dulap
    friend void calculeazaPretDulap(const Dulap& dulap);


};


// Inițializare atribut static
int Dulap::numarTotalDulapuri = 0;


class Pat {
private:
    string material;
    int dimensiune;
    static int numarTotalPaturi;
    const string stil;
    const int capacitateMaxima;
    double* pret;

public:
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

    // Constructor de copiere
    Pat(const Pat& p) : material(p.material), dimensiune(p.dimensiune), stil(p.stil), capacitateMaxima(p.capacitateMaxima) {
        this->pret = new double;
        *(this->pret) = *(p.pret);
    }

    // Destructor pentru a elibera memoria alocată dinamic
    ~Pat() {
        delete pret;
        numarTotalPaturi--;
    }

    //Get-eri
    string getMaterial() const {
        return material;
    }

    int getDimensiune() const {
        return dimensiune;
    }

    double getPret() const {
        return *pret;
    }

    //Set-eri
    void setMaterial(const string& newMaterial) {
        material = newMaterial;
    }

    void setDimensiune(int newDimensiune) {
        dimensiune = newDimensiune;
    }

    void setPret(double newPret) {
        *pret = newPret;
    }

    static int getNumarTotalPaturi() {
        return numarTotalPaturi;
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

// Funcție globală pentru afișarea informațiilor despre o Canapea
//void afiseazaInformatiiCanapea(const Canapea& canapea);

// Funcție globală pentru calcularea și afișarea prețului total pentru un Dulap
//void calculeazaPretDulap(const Dulap& dulap);

// Definirea funcției pentru afișarea informațiilor despre o Canapea
void afiseazaInformatiiCanapea(const Canapea& canapea) {
    cout << "Informatii Canapea:\n";
    cout << "Marca: " << canapea.marca << "\n";
    cout << "Numar locuri: " << canapea.numarLocuri << "\n";
    cout << "Pret: " << *(canapea.pret) << "\n\n";
}

// Definirea funcției pentru calcularea și afișarea prețului total pentru un Dulap
void calculeazaPretDulap(const Dulap& dulap) {
    double pretTotal = *(dulap.pret) * dulap.numarRafturi;
    cout << "Pret total pentru Dulap: " << pretTotal << "\n\n";
}

int main() {
    cout << "---------------- CANAPELE ----------------" << endl;
    Canapea canapeaImplicita;
    cout << "Marca implicita: " << canapeaImplicita.getMarca() << ", Numar locuri: " << canapeaImplicita.getNumarLocuri() << ", Pret: " << canapeaImplicita.getPret() << endl;

    Canapea canapeaPersonalizata("IKEA", 3, 2500);
    cout << "Marca personalizata: " << canapeaPersonalizata.getMarca() << ", Numar locuri: " << canapeaPersonalizata.getNumarLocuri() << ", Pret: " << canapeaPersonalizata.getPret() << endl;

    // Acces la atributul static
    cout << "Numar total de canapele: " << Canapea::getNumarTotalCanapele() << endl;


    cout << endl << "---------------- DULAPURI ----------------" << endl;
    Dulap dulapImplicit;
    cout << "Material implicit: " << dulapImplicit.getMaterial() << ", Numar rafturi: " << dulapImplicit.getNumarRafturi() << ", Pret: " << dulapImplicit.getPret() << endl;

    Dulap dulapPersonalizat("MDF", 4, 900);
    cout << "Material personalizat: " << dulapPersonalizat.getMaterial() << ", Numar rafturi: " << dulapPersonalizat.getNumarRafturi() << ", Pret: " << dulapPersonalizat.getPret() << endl;

    // Acces la atributul static
    cout << "Numar total de dulapuri: " << Dulap::getNumarTotalDulapuri() << endl;


    cout << endl << "---------------- PATURI ----------------" << endl;
    Pat patImplicit;
    cout << "Material implicit: " << patImplicit.getMaterial() << ", Dimensiune: " << patImplicit.getDimensiune() << ", Pret: " << patImplicit.getPret() << endl;

    Pat patPersonalizat("Lemn", 180, 1600);
    cout << "Material personalizat: " << patPersonalizat.getMaterial() << ", Dimensiune: " << patPersonalizat.getDimensiune() << ", Pret: " << patPersonalizat.getPret() << endl;

    // Acces la atributul static
    cout << "Numar total de paturi: " << Pat::getNumarTotalPaturi() << endl;

    cout << endl << "---------------- functii globale ----------------" << endl;
    // Exemplu de utilizare a funcțiilor globale prietene
    Canapea canapea("Ikea", 3, 3000.0);
    afiseazaInformatiiCanapea(canapea);

    Dulap dulap("PVC", 4, 250.0);
    calculeazaPretDulap(dulap);


    return 0;
}