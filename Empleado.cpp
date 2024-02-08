#include <iostream>
#include <iomanip>

using namespace std;

class Persona {
protected:
    int Cedula;
    string Nombre;
    string Apellido;
    int Edad;
    int NroHijos;
};

class Empleado : public Persona {
private:
    double SueldoDiario;
    string Cargo;
    int AnosServicio;
    int DiasTrabajados;
    double SueldoMensual;
    double Asignaciones;
    double Deducciones;

public:
    Empleado(int cedula,string nombre, string apellido, int edad, int hijos, double sueldo, string cargo, int anos, int dias) {
        Cedula = cedula;
        Nombre = nombre;
        Apellido = apellido;
        Edad = edad;
        NroHijos = hijos;
        SueldoDiario = sueldo;
        Cargo = cargo;
        AnosServicio = anos;
        DiasTrabajados = dias;
    }

    void CalcularSueldoMensual() {
        Asignaciones = NroHijos * 10;
        Deducciones = SueldoDiario * DiasTrabajados * (0.01 + 0.03);
        SueldoMensual = SueldoDiario * DiasTrabajados + Asignaciones - Deducciones;
    }

    void MostrarDatos() {
        cout << "Asignaciones: $" << Asignaciones << std::endl;
        cout << "Deducciones: $" << Deducciones << std::endl;
        cout << "Sueldo Mensual: Bs. " << fixed << setprecision(2) << SueldoMensual << " (Tasa de cambio oficial BCV)\n";
    }
};

int main() {
    Empleado empleado(1234567, "Juan", "Perez", 30, 2, 20.0, "Gerente", 5, 22);
    empleado.CalcularSueldoMensual();
    empleado.MostrarDatos();

    return 0;
}
