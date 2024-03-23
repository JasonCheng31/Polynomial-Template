#include <iostream>
using namespace std;

template <typename T>
class Polynomial {
public:
    Polynomial(T c[], int d) {
    	degree = d;
        coefficients = new T[degree + 1];
        for (int i = degree; i >= 0; i--) {
            coefficients[i] = c[i];
        }
    }

    void print() const {
        for (int i = degree; i >= 1; i--) {
            cout << coefficients[i] << "*x^" << i << " + ";
        }
        cout << coefficients[0] << endl;
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    Polynomial(const Polynomial &orig) {
    	degree = orig.degree;
        coefficients = new T[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = orig.coefficients[i];
        }
    }

    Polynomial &operator=(const Polynomial &rhs) {
        if (this == &rhs) return *this;
        delete[] coefficients;
        degree = rhs.degree;
        coefficients = new T[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = rhs.coefficients[i];
        }
        return *this;
    }

    Polynomial operator+(const Polynomial &p) const {
		int maxDegree = degree;
		if(maxDegree < p.degree) maxDegree = p.degree;

        T *newCoefficients = new T[maxDegree + 1];
        for (int i = 0; i <= maxDegree; i++) {
            T coefficient = 0;
            if (i <= degree) {
                coefficient += coefficients[i];
            }
            if (i <= p.degree) {
                coefficient += p.coefficients[i];
            }
            newCoefficients[i] = coefficient;
        }
        Polynomial result(newCoefficients, maxDegree);
        delete[] newCoefficients;
        return result;
    }

private:
    T *coefficients;
    int degree;
};

int main() {
    // Double Polynomial
    double a1[3] = {1.1, 2.2, 3.3}, a2[2] = {2, 1};
    Polynomial<double> p1(a1, 2), p2(a2, 1);

    cout << "Double Polynomial:\n";
    cout << "p1: ";
    p1.print();
    cout << "p2: ";
    p2.print();

    Polynomial<double> p4 = p1;
    cout << "\nCopy Constructor:\n";
    cout << "p4 (copy of p1): ";
    p4.print();

    Polynomial<double> p5(a2, 1);
    p5 = p2;
    cout << "\nAssignment Operator:\n";
    cout << "p5 (assigned p2): ";
    p5.print();

    Polynomial<double> p6 = p1 + p2;
    cout << "\nOperator+ overloading:\n";
    cout << "p6 = p1 + p2: ";
    p6.print();
    cout << "\n--------------------------------\n";

    // Integer Polynomial
    int b1[3] = {1, 2, 3}, b2[2] = {2, 1};
    Polynomial<int> p7(b1, 2), p8(b2, 1);

    cout << "Integer Polynomial:\n";
    cout << "p7: ";
    p7.print();
    cout << "p8: ";
    p8.print();

    Polynomial<int> p9 = p7;
    cout << "\nCopy Constructor:\n";
    cout << "p9 (copy of p7): ";
    p9.print();

    Polynomial<int> p10(b2, 1);
    p10 = p8;
    cout << "\nAssignment Operator:\n";
    cout << "p10 (assigned p8): ";
    p10.print();

    Polynomial<int> p11 = p7 + p8;
    cout << "\nOperator+ overloading:\n";
    cout << "p11 = p7 + p8: ";
    p11.print();

    return 0;
}
