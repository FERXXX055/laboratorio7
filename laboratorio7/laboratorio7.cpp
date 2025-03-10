#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;
    bool activa;
    int intentosFallidos;
    int mesesInactivo;

public:
    CuentaBancaria(string t, double saldoInicial) {
        titular = t;
        saldo = saldoInicial;
        activa = true;
        intentosFallidos = 0;
        mesesInactivo = 0;
    }

    void depositar(double monto) {
        if (!activa) {
            cout << "La cuenta esta bloqueada. No puedes hacer depositos." << endl;
            return;
        }
        if (monto <= 0) {
            cout << "No se pueden depositar montos negativos o cero." << endl;
            return;
        }
        saldo += monto;
        mesesInactivo = 0;
        cout << "Deposito exitoso. Nuevo saldo: Q" << saldo << endl;
    }

    void retirar(double monto) {
        if (!activa) {
            cout << "La cuenta esta bloqueada. No puedes retirar dinero." << endl;
            return;
        }
        if (monto <= 0) {
            cout << "No se pueden retirar montos negativos o cero." << endl;
            return;
        }
        if (monto > saldo) {
            intentosFallidos++;
            cout << "Saldo insuficiente. Intento fallido #" << intentosFallidos << endl;
            if (intentosFallidos == 3) {
                activa = false;
                cout << "La cuenta ha sido bloqueada por intentos fallidos." << endl;
            }
            return;
        }
        saldo -= monto;
        intentosFallidos = 0;
        mesesInactivo = 0;
        cout << "Retiro exitoso. Nuevo saldo: Q" << saldo << endl;
    }

    void consultarSaldo() {
        cout << "Titular: " << titular << endl;
        cout << "Saldo: Q" << saldo << endl;
        cout << "Estado: " << (activa ? "Activa" : "Bloqueada") << endl;
    }

    void pasarMeses(int meses) {
        if (!activa) return;
        mesesInactivo += meses;
        if (mesesInactivo >= 6) {
            activa = false;
            cout << "La cuenta ha sido bloqueada por inactividad." << endl;
        }
    }
};

void mostrarMenu() {
    cout << "\n--- Menu ---" << endl;
    cout << "1. Depositar" << endl;
    cout << "2. Retirar" << endl;
    cout << "3. Consultar Saldo" << endl;
    cout << "4. Cambiar Usuario" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    CuentaBancaria cuenta1("Juan Perez", 500);
    CuentaBancaria cuenta2("Maria Lopez", 600);
    CuentaBancaria cuenta3("Carlos Gomez", 700);
    CuentaBancaria cuenta4("Ana Fernandez", 800);
    CuentaBancaria cuenta5("Luis Ramirez", 900);
    CuentaBancaria cuenta6("Sofia Torres", 1000);
    CuentaBancaria cuenta7("Pedro Martinez", 1100);
    CuentaBancaria cuenta8("Laura Diaz", 1200);
    CuentaBancaria cuenta9("Andres Vargas", 1300);
    CuentaBancaria cuenta10("Marta Rios", 1400);
    CuentaBancaria cuenta11("Diego Castro", 1500);
    CuentaBancaria cuenta12("Elena Solis", 1600);
    CuentaBancaria cuenta13("Fernando Nuñez", 1700);
    CuentaBancaria cuenta14("Gabriela Paredes", 1800);
    CuentaBancaria cuenta15("Hector Maldonado", 1900);
    CuentaBancaria cuenta16("Isabel Jimenez", 2000);
    CuentaBancaria cuenta17("Javier Guzman", 2100);
    CuentaBancaria cuenta18("Karla Ortega", 2200);
    CuentaBancaria cuenta19("Leonardo Peña", 2300);
    CuentaBancaria cuenta20("Monica Estrada", 2400);
    CuentaBancaria cuenta21("Nicolas Herrera", 2500);
    CuentaBancaria cuenta22("Olga Mejia", 2600);
    CuentaBancaria cuenta23("Pablo Suarez", 2700);
    CuentaBancaria cuenta24("Raquel Alvarado", 2800);
    CuentaBancaria cuenta25("Sergio Dominguez", 2900);
    CuentaBancaria cuenta26("Tatiana Flores", 3000);
    CuentaBancaria cuenta27("Ulises Peralta", 3100);
    CuentaBancaria cuenta28("Valeria Soto", 3200);
    CuentaBancaria cuenta29("Wilmer Fuentes", 3300);
    CuentaBancaria cuenta30("Ximena Aguilar", 3400);

    int opcion;
    double monto;
    CuentaBancaria* cuentaActual = &cuenta1;

    while (true) {
        cout << "\nUsuario actual: " << cuentaActual << endl;
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            cuentaActual->depositar(monto);
            break;
        case 2:
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            cuentaActual->retirar(monto);
            break;
        case 3:
            cuentaActual->consultarSaldo();
            break;
        case 4:
            cout << "Seleccione un numero de cuenta (1-30): ";
            int seleccion;
            cin >> seleccion;
            if (seleccion < 1 || seleccion > 30) {
                cout << "Numero invalido. Seleccionando cuenta 1." << endl;
                cuentaActual = &cuenta1;
            }
            else {
                cuentaActual = &cuenta1 + (seleccion - 1);
            }
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            return 0;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
        cuentaActual->pasarMeses(1);
    }
    return 0;
}
