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
    CuentaBancaria(string titular, double saldoInicial) {
        this->titular = titular;
        this->saldo = saldoInicial;
        this->activa = true;         
        this->intentosFallidos = 0;  
        this->mesesInactivo = 0;     
    }

    void depositar(double monto) {
        if (monto <= 0) {  
            cout << "No se pueden hacer depositos con montos negativos o cero." << endl;
        }
        else if (!activa) {  
            cout << "La cuenta esta bloqueada, no se pueden hacer depositos." << endl;
        }
        else {  
            saldo += monto;
            cout << "Deposito exitoso. Nuevo saldo: Q" << saldo << endl;
        }
    }

    void retirar(double monto) {
        if (!activa) {  
            cout << "La cuenta esta bloqueada, no se pueden hacer retiros." << endl;
            return; 
        }

        if (monto <= 0) { 
            cout << "No se pueden hacer retiros con montos negativos o cero." << endl;
            return; 
        }

        if (monto > saldo) {  
            intentosFallidos++;  
            cout << "Saldo insuficiente. Intento fallido #" << intentosFallidos << endl;

            if (intentosFallidos >= 3) {
                activa = false;
                cout << "La cuenta ha sido bloqueada por intentos fallidos." << endl;
            }
        }
        else {
            saldo -= monto;  
            intentosFallidos = 0; 
            if (saldo < 100) { 
                cout << "Advertencia: El saldo ha caido por debajo de Q100." << endl;
            }
            cout << "Retiro exitoso. Nuevo saldo: Q" << saldo << endl;
        }
    }

    void consultarSaldo() {
        cout << "Titular: " << titular << endl;
        cout << "Saldo: Q" << saldo << endl;
        cout << "Estado: " << (activa ? "Activa" : "Bloqueada") << endl;
    }

    void simularInactividad(int meses) {
        mesesInactivo += meses;  
        if (mesesInactivo >= 6) {  
            activa = false;  
            cout << "La cuenta ha sido bloqueada por inactividad." << endl;
        }
    }
};

int main() {
    CuentaBancaria cuenta("Juan Perez", 500);
    int opcion;
    double monto;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Depositar" << endl;
        cout << "2. Retirar" << endl;
        cout << "3. Consultar Saldo" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            cuenta.depositar(monto);
            break;

        case 2:
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            cuenta.retirar(monto);
            break;

        case 3:
            cuenta.consultarSaldo();
            break;

        case 4:
            cout << "Saliendo del programa." << endl;
            break;

        default:
            cout << "Opcion no valida, intente nuevamente." << endl;
            break;
        }
    } while (opcion != 4);  

    return 0;
}