#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Complex {
private:
    float real_part;
    float imaginary_part;

public:
    Complex() : real_part(0.0), imaginary_part(0.0) {}
    Complex(float real, float imag) : real_part(real), imaginary_part(imag) {}

    Complex operator+(const Complex &second_operand) const {
        return Complex(real_part + second_operand.real_part, imaginary_part + second_operand.imaginary_part);
    }

    Complex operator-(const Complex &second_operand) const {
        return Complex(real_part - second_operand.real_part, imaginary_part - second_operand.imaginary_part);
    }

    Complex operator*(const Complex &second_operand) const {
        return Complex(
            real_part * second_operand.real_part - imaginary_part * second_operand.imaginary_part,
            real_part * second_operand.imaginary_part + imaginary_part * second_operand.real_part);
    }

    Complex operator/(const Complex &second_operand) const {
        float denominator = pow(second_operand.real_part, 2.0) + pow(second_operand.imaginary_part, 2.0);
        return Complex(
            (real_part * second_operand.real_part + imaginary_part * second_operand.imaginary_part) / denominator,
            (imaginary_part * second_operand.real_part - real_part * second_operand.imaginary_part) / denominator);
    }

    float modulus() const {
        return sqrtf(pow(real_part, 2.0) + pow(imaginary_part, 2.0));
    }

    void show() const {
        cout << "\t[" << fixed << setprecision(2) << real_part << "] + i [" << fixed << setprecision(2) << imaginary_part << "]" << endl;
    }

    friend ostream& operator<<(ostream &output, const Complex &a);
    friend istream& operator>>(istream &input, Complex &a);
};

ostream& operator<<(ostream &output, const Complex &a) {
    output << "\t● [Answer] -> (" << fixed << setprecision(2) << a.real_part 
           << ") + i (" << fixed << setprecision(2) << a.imaginary_part << ")";
    return output;
}

istream& operator>>(istream &input, Complex &a) {
    cout << "\t● Enter Real Part Of the Complex Number: ";
    input >> a.real_part;
    cout << "\t● Enter Imaginary Part Of the Complex Number: ";
    input >> a.imaginary_part;
    return input;
}

int main() {
    Complex x, y, z;
    int choice;

    cout << "Enter Data For Complex Number 1:\n";
    cin >> x;
    cout << "Enter Data For Complex Number 2:\n";
    cin >> y;

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. ADD Complex Number " << endl;
        cout << "2. SUBTRACT Complex Number" << endl;
        cout << "3. MULTIPLY Complex Number " << endl;
        cout << "4. DIVIDE Complex Number " << endl;
        cout << "5. MODULUS of Complex Numbers" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                z = x + y;
                cout << z << endl;
                break;
            case 2:
                z = x - y;
                cout << z << endl;
                break;
            case 3:
                z = x * y;
                cout << z << endl;
                break;
            case 4:
                z = x / y;
                cout << z << endl;
                break;
            case 5:
                cout << fixed << setprecision(2) << "\nModulus of X is: " << x.modulus() << endl;
                cout << fixed << setprecision(2) << "Modulus of Y is: " << y.modulus() << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
