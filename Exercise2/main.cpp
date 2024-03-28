#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

int main()
{
    Vector2d xsol = Vector2d::Constant(-1.0);

    Matrix2d A1 ;
    Vector2d b1;
    A1 << 5.547001962252291e-01, -3.770900990025203e-02,
         8.320502943378437e-01, -9.992887623566787e-01;
    b1 <<-5.169911863249772e-01, 1.672384680188350e-01;
    VectorXd x1PALU = A1.partialPivLu().solve(b1);
    VectorXd x1QR = A1.householderQr().solve(b1);
    double err1PALU = ((x1PALU-xsol).norm())/(xsol).norm();
    double err1QR = ((x1QR-xsol).norm())/(xsol).norm();
    cout<<"1: \n Errore PALU: "<<err1PALU<<"\n Errore QR: " << err1QR <<endl;

    Matrix2d A2 ;
    Vector2d b2;
    A2 << 5.547001962252291e-01, -5.540607316466765e-01,
        8.320502943378437e-01, -8.324762492991313e-01;
    b2 << -6.394645785530173e-04, 4.259549612877223e-04;
    VectorXd x2PALU = A2.partialPivLu().solve(b2);
    VectorXd x2QR = A2.householderQr().solve(b2);
    double err2PALU = ((x2PALU-xsol).norm())/(xsol).norm();
    double err2QR = ((x2QR-xsol).norm())/(xsol).norm();
    cout<<"2: \n Errore PALU: "<<err2PALU<<"\n Errore QR: " << err2QR <<endl;


    Matrix2d A3 ;
    Vector2d b3;
    A3 << 5.547001962252291e-01, -5.547001955851905e-01,
        8.320502943378437e-01, -8.320502947645361e-01;
    b3 << -6.400391328043042e-10, 4.266924591433963e-10;
    VectorXd x3PALU = A3.partialPivLu().solve(b3);
    VectorXd x3QR = A3.householderQr().solve(b3);
    double err3PALU = ((x3PALU-xsol).norm())/(xsol).norm();
    double err3QR = ((x3QR-xsol).norm())/(xsol).norm();
    cout<<"3: \n Errore PALU: "<<err3PALU<<"\n Errore QR: " << err3QR <<endl;


  return 0;
}
