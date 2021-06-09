#include <iostream>
#include "matrix.hpp"
#include <complex>
#include "sparseMatrix.hpp"
#include "templateUtil.h"

using namespace std;

int main() {

    //this is the testing branch
    Matrix<int> m1(4, 4), m2(2, 3);
    int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[] = { 1,2,3,4,5,6};


    
    /*try {
        //m2.Convolve(m1);
        m1.set(16, a);
        m2.set(6, b);
        m1.print();
        cout << endl;
        m1.Slice(0, 2, 1, 2, 0, 1).print();
        
    }
    catch(exception e){
        cout << e.what();
    }*/

    //task_3_test
    Matrix<double> M_1(3, 3);
    Matrix<double> M_2(3, 3);
    Matrix<double> M_Sym(3, 3);
    //vector initialization
    std::vector<double> vector_data_1;
    vector_data_1.push_back(1.0);
    vector_data_1.push_back(2.0);
    vector_data_1.push_back(-2.0);
    std::vector<double> vector_data_2;
    vector_data_2.push_back(3.0);
    vector_data_2.push_back(-4.0);
    vector_data_2.push_back(-1.0);
    std::vector<double> eigenvalues;
    //Matrix<std::complex> M_3(2, 2);
    double m_1[] = {1.0, 2.0, -1.0, 3.0, 4.0, -7.0, 1.0, -2.0, 3.0};
    double m_2[] = {5.0, -6.0, -4.0, 7.0, 8.0, -2.0, 4.0, 6.0, 5.0};
    double m_sym[] = {5.0, -6.0, -4.0, -6.0, 8.0, -2.0, -4.0, -2.0, 5.0};
    //std::complex m_3[] =
    double scalar_1 = 9.0;
    double scalar_2 = 2.0;
    M_1.set (9, m_1);
    /*
     *  {   1.0     2.0     3.0
     *      3.0     4.0    -7.0
     *      1.0    -2.0     3.0     }
     */
    M_2.set (9, m_2);
    /*
     * {    5.0    -6.0     -4.0
     *      7.0     8.0     -2.0
     *      4.0     6.0      5.0     }
     */
    M_Sym.set (9, m_sym);
    Vector<double> v_1_vec(vector_data_1);
    /*
     * {    1.0
     *      2.0
     *      -2.0    }
     */
    Vector<double> v_2_vec(vector_data_2);
    /*
     * {    3.0
     *      -4.0
     *      -1.0    }
     */

    Vector<double> eigenvector_vec(3);

    cout << "testing matrix arithmetic" << endl;

    cout << "addition" << endl;
    (M_1 + M_2).print();

    cout << "subtraction" << endl;
    (M_1 - M_2).print();

    cout << "scalar multiplication" << endl;
    (M_1 * scalar_1).print();
    cout << endl;
    (scalar_1 * M_2).print();
    cout << "scalar division" << endl;
    (M_1 / scalar_2).print();

    cout << "transposition" << endl;
    Matrix<double>::Transpose(M_1).print();
    cout << endl;
    Matrix<double>::Transpose(M_2).print();
    cout << "conjugate" << endl;
    cout << endl;

    cout << "element-wise multiplication" << endl;
    Matrix<double>::Elementwise_Multiplication(M_1, M_2).print();

    cout << "matrix-matrix multiplication" << endl;
    (M_1 * M_2).print();

    cout << "testing vector arithmetic" << endl;

    cout << "addition" << endl;
    (v_1_vec + v_2_vec).print();

    cout << "subtraction" << endl;
    (v_1_vec - v_2_vec).print();

    cout << "scalar multiplication" << endl;
    (v_1_vec * scalar_1).print();
    cout << endl;
    (scalar_2 * v_2_vec).print();

    cout << "scalar division" << endl;
    (v_1_vec / scalar_2).print();

    cout << "dot product" << endl;
    cout << (Vector<double>::Dot_Product(v_1_vec, v_2_vec)) << endl;

    cout << "cross product" << endl;
    (Vector<double>::Cross_Product(v_1_vec, v_2_vec)).print();

    cout << "matrix-vector multiplication" << endl;
    (M_1 * v_1_vec).print();
    cout << endl;
    (v_1_vec * M_2).print();
    cout << endl;
    //test task_5
    cout << "determinant" << endl;
    cout << (Matrix<double>::Determinant(M_2)) << endl;

    cout << "Inverse" << endl;
    (Matrix<double>::Inverse(M_2)).print();

    cout << "eigenvalues" << endl;
    (Matrix<double>::Eigenvalues(M_Sym, eigenvalues));
    for (int i=0; i < 3; i++)
        cout << eigenvalues.at(i) << " ";
    cout << endl;

    cout << "eigenvectors" << endl;
    for (int i = 0; i < 3; i++)
    {
        (Matrix<double>::Eigenvectors(M_Sym,eigenvalues.at(i), eigenvector_vec));
        for (int j = 0; j < 3; j++)
        {
            cout << eigenvector_vec.get(i) << " ";
        }
        cout << endl;
    }

    return 0;


}
