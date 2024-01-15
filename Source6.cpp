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
    double* pret;


public:
    // Constructor implicit
    Canapea() : marca("Necunoscuta"), numarLocuri(0), capacitateMaxima(0) {
        pret = new double;
        *pret = 0;

        numarTotalCanapele++;
    }

      
    // Constructor cu 2 parametri
    Canapea(string marca, int numarLocuri) : marca(marca), numarLocuri(numarLocuri), capacitateMaxima(0) {  
        pret = new double;
        *pret = 0;

        numarTotalCanapele++;
    }

    // Constructor cu 3 parametri
    Canapea(string marca, int numarLocuri, int pret) : marca(marca), numarLocuri(numarLocuri), capacitateMaxima(0) {
        this->pret = new double;
        *(this->pret) = pret;

        numarTotalCanapele++;
    }

    // Constructor de copiere
    Canapea(const Canapea& other) : marca(other.marca), numarLocuri(other.numarLocuri), capacitateMaxima(other.capacitateMaxima) {
        // Allocați spațiu pentru pointer în heap și copiați valoarea
        this->pret = new double;
        *(this->pret) = *(other.pret);

        // Actualizăm numărul total de canapele
        numarTotalCanapele++;
    }

    // Destructor pt a elibera memoria alocată dinamic
    ~Canapea() {
        delete pret;
        numarTotalCanapele--;
    }

    // Supraincarcare operator =
    Canapea& operator=(const Canapea& c) {
        if (this != &c) {  
            marca = c.marca;
            numarLocuri = c.numarLocuri;
            delete pret;
            pret = new double;
            *pret = *(c.pret);
        }
        return *this;
    }

    // Operator de comparare pentru numarLocuri
    bool operator<(const Canapea& c) const {
        return numarLocuri < c.numarLocuri;
    }

    // Operator de adunare pentru pret
    Canapea operator+(const Canapea& c) const {
        Canapea suma = *this;
        *(suma.pret) += *(c.pret);
        return suma;
    }

    // Operator de % pentru reducere pentru pret
    Canapea operator%(double discount) const {
        Canapea result = *this;
        *(result.pret) -= *(result.pret) * discount / 100.0;
        return result;
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

    //Scriere in fisier txt
    void scrieInFisier(const string& numeFisier) const {
        ofstream fisier(numeFisier);

        if (!fisier.is_open()) {
            cerr << "Eroare la deschiderea fisierului" << numeFisier << endl;
            return;
        }

        // Scriem atributele în fișier
        fisier << marca << "\n";
        fisier << numarLocuri << "\n";
        fisier << *pret << "\n";

        fisier.close();
    }

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

    // Supraincarcare operator =
    Dulap& operator=(const Dulap& d) {
        if (this != &d) {
            material = d.material;
            numarRafturi = d.numarRafturi;
            delete pret;
            pret = new double;
            *pret = *(d.pret);
        }
        return *this;
    }

    // Operator - 
    Dulap operator-(double reducere) const {
        Dulap result = *this;
        *(result.pret) -= reducere;
        return result;
    }

    // Operator de incrementare ++ 
    Dulap& operator++() {
        ++numarRafturi;
        return *this;
    }

    // Operator * 
    Dulap operator*(double marire) const {
        Dulap result = *this;
        *(result.pret) *= (1 + marire);
        return result;
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
    void afisareInfoDulap() const {
        cout << "Material: " << material << ", Numar rafturi: " << numarRafturi << ", Pret: " << *pret << endl;
    }

    // Funcție statică pentru a micșora prețul cu 5%
    static void micsoreazaPretul(Dulap& dulap) {
        *(dulap.pret) *= 0.95;
    }

    // Funcție globală prietenă cu clasa Dulap
    friend void calculeazaPretDulap(const Dulap& dulap);

    // Funcție friend pentru a decrementa numarul rafturilor
    friend void scadeNumarRafturi(Dulap& dulap);

    //citire din fisier txt
    void citesteDinFisier(const string& numeFisier) {
        ifstream fisier(numeFisier);

        if (!fisier.is_open()) {
            cerr << "Eroare la deschiderea fisierului" << numeFisier << endl;
            return;
        }

        // Citim atributele din fișier
        fisier >> material >> numarRafturi;

        // Alocăm spațiu pentru pretDulap și citim valoarea
        pret = new double;
        fisier >> *pret;

        fisier.close();
    }


};

// Funcția friend 
void scadeNumarRafturi(Dulap& dulap) {
    if (dulap.numarRafturi > 0) {
        --dulap.numarRafturi;
    }
}

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

    // Destructor 
    ~Pat() {
        delete pret;
        numarTotalPaturi--;
    }

    // Supraincarcare operator =
    Pat& operator=(const Pat& p) {
        if (this != &p) {
            material = p.material;
            dimensiune = p.dimensiune;
            delete pret;
            pret = new double;
            *pret = *(p.pret);
        }
        return *this;
    }

    // Operator de comparare <<
    bool operator<(const Pat& comparare) const {
        return dimensiune < comparare.dimensiune;
    }

    //Operator +
    Pat operator+(double marire) const {
        Pat result = *this;
        *(result.pret) += marire;
        return result;
    }

    // Operator % 
    Pat operator%(double discount) const {
        Pat result = *this;
        *(result.pret) -= *(result.pret) * discount / 100.0;
        return result;
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

    void scrieInFisierBinar(const string& numeFisier) const {
        ofstream fisierBinar(numeFisier, ios::binary);

        if (!fisierBinar.is_open()) {
            cerr << "Eroare la deschiderea fisierului pentru scriere binara: " << numeFisier << endl;
            return;
        }

        // Scriem atributele în fișierul binar
        fisierBinar.write(reinterpret_cast<const char*>(&material), sizeof(material));
        fisierBinar.write(reinterpret_cast<const char*>(&dimensiune), sizeof(dimensiune));
        fisierBinar.write(reinterpret_cast<const char*>(&pret), sizeof(pret));

        fisierBinar.close();
    }

};

// Inițializare atribut static
int Pat::numarTotalPaturi = 0;

class MobilaDormitor {
private:
    Dulap dulap;
    double pretMobila;  // atribut nou
    bool areNoptiere; // atribut nou
    int greutateMobila; // atribut nou

public:
    MobilaDormitor(string material, double pret, double pretMobila, bool areNoptiere, int greutateMobila)
        : dulap(material, 6, pret), pretMobila(pretMobila), areNoptiere(areNoptiere), greutateMobila(greutateMobila) {
    }


    void afiseazaInformatii() const {
        cout << "Mobila Dormitor:\n";
        dulap.afisareInfoDulap();  
        cout << "Pret Mobila: " << pretMobila << ", Are Noptiere: " << (areNoptiere ? "Da" : "Nu")
            << ", Greutate Mobila: " << greutateMobila << " kg" << std::endl;
    }

    // Getter
    double getPretMobila() const {
        return pretMobila;
    }

    // Setter
    void setPretMobila(double pret) {
        pretMobila = pret;
    }

    // Getter
    bool getAreNoptiere() const {
        return areNoptiere;
    }

    // Setter
    void setAreNoptiere(bool areNoptiere) {
        this->areNoptiere = areNoptiere;
    }

    // Getter
    int getGreutateMobila() const {
        return greutateMobila;
    }

    // Setter
    void setGreutateMobila(int greutate) {
        greutateMobila = greutate;
    }

    // operator +
    MobilaDormitor operator+(double valoare) const {
        MobilaDormitor rezultat = *this;  
        rezultat.pretMobila += valoare;   
        return rezultat;                
    }

    // Operator - 
    MobilaDormitor operator-(const MobilaDormitor& other) const {
        MobilaDormitor rezultat = *this;
        rezultat.pretMobila -= rezultat.pretMobila * 0.10;
        return rezultat;
    }





};


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
    /*
    cout << "---------------- CANAPELE ----------------" << endl;

    Canapea canapeaImplicita;
    cout << "Marca implicita: " << canapeaImplicita.getMarca() << ", Numar locuri: " << canapeaImplicita.getNumarLocuri() << ", Pret: " << canapeaImplicita.getPret() << endl;

    Canapea canapeaPersonalizata("IKEA", 3, 2500);
    cout << "Marca personalizata: " << canapeaPersonalizata.getMarca() << ", Numar locuri: " << canapeaPersonalizata.getNumarLocuri() << ", Pret: " << canapeaPersonalizata.getPret() << endl;

    // Acces la atributul static
    cout << "Numar total de canapele: " << Canapea::getNumarTotalCanapele() << endl;


    Canapea canapea2;
    canapea2 = canapeaPersonalizata;
    cout << "\nOperatorul =\n";
    cout << "Canapea 1: ";
    canapeaPersonalizata.afisareInfoCanapea();
    cout << "Canapea 2: ";
    canapea2.afisareInfoCanapea();

    Canapea canapea3("Jisk", 3, 2500.0);
    Canapea canapea4("Mobexpert", 2, 1450.0);

    cout << "\nOperatorul <\n";
    cout << "Canapea 3: ";
    canapea3.afisareInfoCanapea();
    cout << "Canapea 4: ";
    canapea4.afisareInfoCanapea();

    // Compararea folosind operatorul <
    if (canapea3 < canapea4) {
        cout << "\nCanapea 3 are mai putine locuri decat Canapea 4.\n";
    }
    else {
        cout << "\nCanapea 4 are mai putine locuri decat Canapea 3.\n";
    }

    cout << "\nOperatorul +\n";
    // Adunarea preturilor canapelelor 3 si 4
    Canapea canapeaSuma = canapea3 + canapea4;
    cout << "Pretul final adunat: ";
    canapeaSuma.afisareInfoCanapea();


    cout << "\nOperatorul %\n";
    cout << "Inainte de reducere:\n";
    canapea2.afisareInfoCanapea();

    // Aplicarea reducerii de 15%
    Canapea canapeaRedusa = canapea2 % 15.0;
    cout << "\nDupa reducere:\n";
    canapeaRedusa.afisareInfoCanapea();

   
   
    //Vector clasa Canapea
    int numarCanapele;
    cout << "Introduceti numarul de canapele: ";
    cin >> numarCanapele;

    Canapea* canapele = new Canapea[numarCanapele];

    for (int i = 0; i < numarCanapele; ++i) {
        string material;
        int numarLocuri;
        double pret;


        cout << "\nIntroduceti informatii pentru Canapea " << i + 1 << ":\n";
        cout << "Material: ";
        cin >> material;
        cout << "Numar locuri: ";
        cin >> numarLocuri;
        cout << "Pret: ";
        cin >> pret;


        canapele[i] = Canapea(material, numarLocuri, pret);
    }

    cout << "\nCanapelele introduse sunt:\n";
    for (int i = 0; i < numarCanapele; ++i) {
        canapele[i].afisareInfoCanapea();
    }

    delete[] canapele;

   
    cout << endl << "---------------- DULAPURI ----------------" << endl;
    
    Dulap dulapImplicit;
    cout << "Material implicit: " << dulapImplicit.getMaterial() << ", Numar rafturi: " << dulapImplicit.getNumarRafturi() << ", Pret: " << dulapImplicit.getPret() << endl;

    Dulap dulapPersonalizat("MDF", 4, 900);
    cout << "Material personalizat: " << dulapPersonalizat.getMaterial() << ", Numar rafturi: " << dulapPersonalizat.getNumarRafturi() << ", Pret: " << dulapPersonalizat.getPret() << endl;

    // Acces la atributul static
    cout << "Numar total de dulapuri: " << Dulap::getNumarTotalDulapuri() << endl;

    Dulap dulap2;
    dulap2 = dulapPersonalizat;
    cout << "\nOperatorul =\n";
    cout << "Dulap1: ";
    dulapPersonalizat.afisareInfoDulap();
    cout << "Dulap2: ";
    dulap2.afisareInfoDulap();

    cout << "\nOperatorul -\n";
    Dulap dulap3("lemn", 3, 750.0);
    cout << "Inainte de reducere:\n";
    dulap3.afisareInfoDulap();
    Dulap dulapCuReducere = dulap3 - 100.0;
    cout << "Dupa reducere:\n";
    dulapCuReducere.afisareInfoDulap();


    cout << "\nOperatorul ++\n";
    cout << "Inainte de incrementare:\n";
    dulap3.afisareInfoDulap();
    ++dulap3;
    cout << "Dupa incrementare:\n";
    dulap3.afisareInfoDulap();

    cout << "\nOperatorul *\n";
    cout << "Inainte de marire:\n";
    dulap3.afisareInfoDulap();
    Dulap dulapCuMarire = dulap3 * 0.05;
    cout << "Dupa marire:\n";
    dulapCuMarire.afisareInfoDulap();


    cout << "\nFunctia friend\n";
    cout << "Inainte de decrementare:\n";
    dulapPersonalizat.afisareInfoDulap();
    scadeNumarRafturi(dulapPersonalizat);
    cout << "Dupa decrementare:\n";
    dulapPersonalizat.afisareInfoDulap();

   

    //Vector clasa Dulap
    int numarDulapuri;
    cout << "Introduceti numarul de dulapuri: ";
    cin >> numarDulapuri;

    Dulap* dulapuri = new Dulap[numarDulapuri];

    for (int i = 0; i < numarDulapuri; ++i) {
        string material;
        int numarRafturi;
        double pret;

        cout << "\nIntroduceti informatii pentru Dulap " << i + 1 << ":\n";
        cout << "Material: ";
        cin >> material;
        cout << "Numar rafturi: ";
        cin >> numarRafturi;
        cout << "Pret: ";
        cin >> pret;

        dulapuri[i] = Dulap(material, numarRafturi, pret);
    }

    cout << "\nDulapurile introduse sunt:\n";
    for (int i = 0; i < numarDulapuri; ++i) {
        dulapuri[i].afisareInfoDulap();
    }

    delete[] dulapuri;

    cout << endl << "---------------- PATURI ----------------" << endl;

    
    Pat patImplicit;
    cout << "Material implicit: " << patImplicit.getMaterial() << ", Dimensiune: " << patImplicit.getDimensiune() << ", Pret: " << patImplicit.getPret() << endl;

    Pat patPersonalizat("Lemn", 180, 1600);
    cout << "Material personalizat: " << patPersonalizat.getMaterial() << ", Dimensiune: " << patPersonalizat.getDimensiune() << ", Pret: " << patPersonalizat.getPret() << endl;

    // Acces la atributul static
    cout << "Numar total de paturi: " << Pat::getNumarTotalPaturi() << endl;

    Pat pat2;
    pat2 = patPersonalizat;
    cout << "\nOperatorul =\n";
    cout << "Pat1: ";
    patPersonalizat.afisareInfoPat();
    cout << "Pat2: ";
    pat2.afisareInfoPat();

    cout << "\nOperatorul <<\n";
    Pat pat3("Lemn", 120, 800.0);
    Pat pat4("Metal", 90, 600.0);

    cout << "Compararea dimensiunilor urmatoarelor Paturi:\n";
    cout << "Primul pat: ";
    pat3.afisareInfoPat();
    cout << "Al doilea pat: ";
    pat4.afisareInfoPat();

    if (pat3 < pat4) {
        cout << "Primul pat are dimensiune mai mica decat al doilea.\n";
    }
    else {
        cout << "Primul pat are dimensiune mai mare decat al doilea pat.\n";
    }

    cout << "\nOperatorul +\n";
    cout << "Inainte de marire:\n";
    pat3.afisareInfoPat();

    Pat patCuMarire = pat3 + 100;
    cout << "Dupa marire:\n";
    patCuMarire.afisareInfoPat();

    cout << "\nOperatorul %\n";
    cout << "Inainte de reducere:\n";
    pat4.afisareInfoPat();

    Pat patCuReducere = pat4 % 10.0;
    cout << "Dupa reducere:\n";
    patCuReducere.afisareInfoPat();

   
    int numarPaturi;
    cout << "Introduceti numarul de paturi: ";
    cin >> numarPaturi;

    Pat* paturi = new Pat[numarPaturi];

    for (int i = 0; i < numarPaturi; ++i) {
        string material;
        int dimensiune;
        double pret;

        cout << "\nIntroduceti informatii pentru Pat " << i + 1 << ":\n";
        cout << "Material: ";
        cin >> material;
        cout << "Dimensiune: ";
        cin >> dimensiune;
        cout << "Pret: ";
        cin >> pret;

        paturi[i] = Pat(material, dimensiune, pret);
    }

    cout << "\nPaturile introduse sunt:\n";
    for (int i = 0; i < numarPaturi; ++i) {
        paturi[i].afisareInfoPat();
    }

    delete[] paturi;
   
    cout << endl << "---------------- functii globale ----------------" << endl;
    // Exemplu de utilizare a funcțiilor globale prietene
    Canapea canapea("Ikea", 3, 3000.0);
    afiseazaInformatiiCanapea(canapea);

    Dulap dulap("PVC", 4, 250.0);
    calculeazaPretDulap(dulap);
    
    */

    // clasa mobilaDormitor - relatie has a
    MobilaDormitor mobila("Lemn", 1200.0, 1600.0, true, 150);
    mobila.afiseazaInformatii();

    // Folosirea operatorului +
    MobilaDormitor mobilaCuAdaos = mobila + 100;

    cout << "\nDupa marirea pretului cu 100 RON: \n";
    mobilaCuAdaos.afiseazaInformatii();

    // Folosirea operatorului -
    MobilaDormitor mobilaRedusa = mobila - mobila;
    cout << "\nDupa micsorarea pretului cu 10%: \n";
    mobilaRedusa.afiseazaInformatii();

    //scriere in fisier txt
    Canapea canapea("Ikea", 3, 3000.0);
    canapea.scrieInFisier("canapea_output.txt");
    cout << "\nInformatii despre canapea scrise in fisier text:\n";
    canapea.afisareInfoCanapea();


    //citire din fisier txt
    Dulap dulap;
    // Adăugăm apelul pentru citirea dintr-un fișier text
    dulap.citesteDinFisier("dulap_input.txt");
    cout << "\nInformatii despre dulap citite din fisier:\n";
    dulap.afisareInfoDulap();

    //scriere in fisier binar
    Pat pat("lemn", 220, 3600);
    pat.scrieInFisierBinar("pat_output.bin");
    cout << "\nInformatii despre pat scrise in fisier binar:\n";
    pat.afisareInfoPat();


    return 0;
}