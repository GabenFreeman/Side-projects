#include <iostream>
#include <math.h>

using namespace std;

class LiczbyWymierne
{
private:
    double L, M;
public:
    //konstruktor bez argumentow
    LiczbyWymierne()
    {
        L = 1;
        M = 1;
    }
    //konstruktor 1 argumentowy
    LiczbyWymierne(double _L)
    {
        L = _L;
        M = 1;
    }
    //konstruktor 2 argumentowy
    LiczbyWymierne(double _L, double _M)
    {
        L = _L;
        if(_M!=0) M = _M;
        else
        {
            cout << "Mianownik nie moze byc 0! Ustawiam na 1" << endl;
            M = 1;
        }
        if(M<0) {M*=-1; L*=-1;}
        else if(L<0 && M<0){M*=-1; L*=-1;}
    }
    //konstruktor kopiujacy
    LiczbyWymierne(const LiczbyWymierne&);
    double getL() { return L; }
    double getM() { return M; }
    double convertToDouble() { return L / M; }
    LiczbyWymierne Skracaj(); //zwraca obiekt LiczbyWymierne
    void setL(double _L) { L = _L; }
    void setM(double _M) {
        if (_M != 0) M = _M;
        else{
            cout << "Mianownik nie moze byc 0! Ustawiam na 1" << endl;
            M = 1;
        }
    }
    void setAll(double _L, double _M){L=_L; M=_M;}
    // =
    LiczbyWymierne operator =(const LiczbyWymierne& L)
    { return LiczbyWymierne(this->L=L.L, this->M=L.M); }
    LiczbyWymierne operator =(const double Liczba)
    { return LiczbyWymierne(this->L=Liczba, this->M=1); }
    // *
    LiczbyWymierne operator *(const LiczbyWymierne& L)
    { return LiczbyWymierne(this->L*=L.L, this->M*=L.M); }
    LiczbyWymierne operator *(const double Liczba)
    { return LiczbyWymierne(this->L*=Liczba, this->M*=1); }
    // /
    LiczbyWymierne operator /(const LiczbyWymierne& L)
    { return LiczbyWymierne(this->L*=L.M, this->M*=L.L); }
    LiczbyWymierne operator /(const double Liczba)
    { return LiczbyWymierne(this->L*=1, this->M*=Liczba); }
    // +
    LiczbyWymierne operator +(const LiczbyWymierne& Liczba)
    {
        double pomL=0, pomM=this->M*Liczba.M;
        pomL = (this->L*Liczba.M)+(this->M*Liczba.L);
        return LiczbyWymierne(pomL, pomM);
    }
    LiczbyWymierne operator +(const double Liczba)
    {
        double pomL=0, pomM=this->M*1;
        pomL = (this->L*1)+(this->M*Liczba);
        return LiczbyWymierne(pomL, pomM);
    }
    // -
    LiczbyWymierne operator -(const LiczbyWymierne& Liczba)
    {
        double pomL=0, pomM=this->M*Liczba.M;
        pomL = (this->L*Liczba.M)-(this->M*Liczba.L);
        return LiczbyWymierne(pomL, pomM);
    }
    LiczbyWymierne operator -(const double Liczba)
    {
        double pomL=0, pomM=this->M*1;
        pomL = (this->L*1)-(this->M*Liczba);
        return LiczbyWymierne(pomL, pomM);
    }
    // ==
    bool operator == (const LiczbyWymierne & L) //porównanie
    {
        LiczbyWymierne Lpom1(this->L, this->M);
        Lpom1=Lpom1.Skracaj();
        LiczbyWymierne Lpom2(L.L, L.M);
        Lpom2=Lpom2.Skracaj();
        if ((Lpom1.L == Lpom2.L) && (Lpom1.M == Lpom2.M)) return true;
        else return false;
    }
    bool operator == (const double L) //porównanie
    {
        LiczbyWymierne Lpom1(this->L, this->M);
        Lpom1=Lpom1.Skracaj();
        LiczbyWymierne Lpom2(L, 1);
        Lpom2=Lpom2.Skracaj();
        if ((Lpom1.L == Lpom2.L) && (Lpom1.M == Lpom2.M)) return true;
        else return false;
    }
    // <
    bool operator < (const LiczbyWymierne & L)
    {
        double L1, L2;
        LiczbyWymierne Lpom1(this->L, this->M);
        L1=Lpom1.convertToDouble();
        LiczbyWymierne Lpom2(L.L, L.M);
        L2=Lpom2.convertToDouble();
        if (L1<L2) return true;
        else return false;
    }
    bool operator < (double L2)
    {
        double L1;
        LiczbyWymierne Lpom1(this->L, this->M);
        L1=Lpom1.convertToDouble();
        if (L1<L2) return true;
        else return false;
    }
    // >
    bool operator > (const LiczbyWymierne & L)
    {
        double L1, L2;
        LiczbyWymierne Lpom1(this->L, this->M);
        L1=Lpom1.convertToDouble();
        LiczbyWymierne Lpom2(L.L, L.M);
        L2=Lpom2.convertToDouble();
        if (L1>L2) return true;
        else return false;
    }
    bool operator > (double L2)
    {
        double L1;
        LiczbyWymierne Lpom1(this->L, this->M);
        L1=Lpom1.convertToDouble();
        if (L1>L2) return true;
        else return false;
    }
};
// konstruktor kopiujacy
LiczbyWymierne::LiczbyWymierne(const LiczbyWymierne& wzorzec)
{
    L = wzorzec.L;
    M = wzorzec.M;
}
// *
LiczbyWymierne operator *(double Liczba,  LiczbyWymierne& L)
{ return LiczbyWymierne(Liczba*L.getL(), L.getM()*1); }
// /
LiczbyWymierne operator /(const double Liczba, LiczbyWymierne& L)
{ return LiczbyWymierne(L.getL()*1, L.getM()*Liczba); }
// +
LiczbyWymierne operator +( double Liczba, LiczbyWymierne & L)
{
    double pomL=0, pomM=L.getL()*1;
    pomL = (L.getL()*1)+(L.getM()*Liczba);
    return LiczbyWymierne(pomL, pomM);
}
// -
LiczbyWymierne operator -(const double Liczba, LiczbyWymierne & L)
{
    double pomL=0, pomM=L.getM()*1;
    pomL = (L.getL()*1)-(L.getM()*Liczba);
    return LiczbyWymierne(pomL, pomM);
}
// ==
bool operator == (const double Liczba, LiczbyWymierne & L)
{
    LiczbyWymierne Lpom1(L.getL(), L.getM());
    Lpom1=Lpom1.Skracaj();
    LiczbyWymierne Lpom2(Liczba, 1);
    Lpom2=Lpom2.Skracaj();
    if ((Lpom1.getL() == Lpom2.getL()) && (Lpom1.getM() == Lpom2.getM())) return true;
    else return false;
}
// <
bool operator < (double L2, LiczbyWymierne & L)
{
    double L1;
    LiczbyWymierne Lpom1(L.getL(), L.getM());
    L1=Lpom1.convertToDouble();
    if (L1<L2) return true;
    else return false;
}
// >
bool operator > (double L2, LiczbyWymierne & L)
{
    double L1;
    LiczbyWymierne Lpom1(L.getL(), L.getM());
    L1=Lpom1.convertToDouble();
    if (L1>L2) return true;
    else return false;
}

LiczbyWymierne LiczbyWymierne::Skracaj()
{
    int pomL=this->L, pomM=this->M;
    double orgL=this->L, orgM=this->M;
    if(L==M){L=1; M=1;}
    else if(L<M)
    {
        if(pomM % pomL==0){pomM=pomM/pomL; pomL=pomL/pomL;}
    }
    else
        {
        if(pomL % pomM==0) {pomL=pomL/pomM; pomM=pomM/pomM;}
        }
    return (LiczbyWymierne(pomL, pomM));
}

ostream & operator << (ostream& str, LiczbyWymierne& Liczba)
{
    int C=0, L=Liczba.getL(), M=Liczba.getM();
    if(L==M){return str <<1;}
    else if(L==0){return str<<0;}
    else if(L<M)
    {
        if(M % L==0)
        {
            M=M/L; L=L/L;
            return str << L << "/" << M;
        }

    }
    else
        {
            if(L % M==0)
            {
                L=L/M; M=M/M;
            }
        }
    C=floor(L/M);
    L-=C*M;
    L=abs(L);
    M=abs(M);

    if (C==0) { return str << L << "/" << M; }
    else if(C!=0 && L==0){return str<<C;}
    else { return str << C << " " << L << "/" << M; }
}

istream & operator >> (istream& istr, LiczbyWymierne& Liczba)
{
    double pomL, pomM;
    cout << "Podaj Licznik: "<<endl; istr >> pomL;
    cout << "Podaj Mianownik: "<<endl; istr >> pomM;
    Liczba.setL(pomL);
    Liczba.setM(pomM);
}

int main()
{
    double dL1=2, dL2=0;
    LiczbyWymierne L1;
    LiczbyWymierne L2(3, 4);
    LiczbyWymierne L3=L2;
    LiczbyWymierne L4(1, 2);
    LiczbyWymierne L5(5, 3);
    LiczbyWymierne L6(100, 10);
    cout<<"dL1: "<<dL1<<endl;
    cout<<"L1: "<<L1<<endl;
    cout<<"L2: "<<L2<<endl;
    cout<<"L3: "<<L3<<endl;
    L1=dL1*L2;
    cout<<"dL1*L2: "<<L1<<endl;
    L1=L2*dL1;
    cout<<"L2*dL1: "<<L1<<endl;
    L1=L2+dL1;
    cout<<"L2+dL1: "<<L1<<endl;
    L1=L2+L4;
    cout<<"L2+4L4: "<<L1<<endl;
    L1=L2-L4;
    cout<<"L2-4L4: "<<L1<<endl;
    L1.setAll(4, 8);
    cout<<"L1=4/8: "<<L1.getL()<<"/"<<L1.getM()<<endl; //operator << od razu juz skraca dlatego trzeba pokazac w taki sposob
    L1=L1.Skracaj();
    cout<<"L1=po skroceniu: "<<L1.getL()<<"/"<<L1.getM()<<endl;
    double a=L1.convertToDouble();
    cout<<"a=L1: "<<a<<endl;
    L2.setAll(71, 10);
    L3.setAll(7, 1);
    L4.setAll(1, 10);
    L1=(L2-L3)-L4;
    cout<<"(7.1 - 7)-0.1: "<<L1<<endl;
}