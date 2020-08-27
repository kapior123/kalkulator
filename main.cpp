#include <iostream>
#include <math.h>

using namespace std;

double EX(double _x[3],double _p[3][3]){
    double _EX,tmmp,tmp[3];
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(int i=0;i<3;i++){
        _EX += _x[i]*tmp[i];
    }
    return _EX;
}
double EY(double _y[3],double _p[3][3]){
    double _EY,tmmp,tmp[3];
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            tmmp += _p[j][i];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(int i=0;i<3;i++){
        _EY += _y[i]*tmp[i];
    }
    return _EY;
}
double EZ(double _x[3],double _p[3][3]){
    double _EZ,tmmp,tmp[3];
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(int i=0;i<3;i++){
        _EZ += (-2*_x[i]-1)*tmp[i];/* change this */
    }
    return _EZ;
}

double EX2(double _x[3],double _p[3][3]){
    double _EX2,tmp[3],tmmp;
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(int i=0;i<3;i++){
        _EX2 += pow(_x[i],2)*tmp[i];
    }
    return _EX2;
}
double EY2(double _y[3],double _p[3][3]){
    double _EY2,tmp[3],tmmp;
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            tmmp += _p[j][i];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(int i=0;i<3;i++){
        _EY2 += pow(_y[i],2)*tmp[i];
    }
    return _EY2;
}
double D2X(double _x[3],double _p[3][3],double EX){
    double _D2X,tmp[3],tmmp;
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(int i=0;i<3;i++){
        _D2X += pow(_x[i]-EX,2)*tmp[i];
    }
    return _D2X;
}
double D2Y(double _y[3],double _p[3][3],double EY){
    double _D2Y,tmp[3],tmmp;
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            tmmp += _p[j][i];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(int i=0;i<3;i++){
        _D2Y += pow(_y[i]-EY,2)*tmp[i];
    }
    return _D2Y;
}

double D2Z(double _x[3],double _p[3][3],double EZ){
    double _D2Z,tmp[3],tmmp;
    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(int i=0;i<3;i++){
        _D2Z += pow((-2*_x[i]-1)-EZ,2)*tmp[i];/* change this */
    }
    return _D2Z;
}
double EXY(double _x[3],double _y[3],double _p[3][3]){
    double EXY;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            EXY += _x[i]*_y[j]*_p[i][j];
        }
    }
    return EXY;
}
double cov(double EXY,double EX,double EY){
    return EXY-(EX*EY);
}

double pXY(double cov,double D2Y,double D2X){
    return cov/sqrt(D2X*D2Y);
}

int main(){
    double _x[3],_y[3],_p[3][3],licz,mian;
    int select;
    for(int i = 0;i<3;i++){
        cout<<"X:"<<endl;
        cin>>_x[i];
        cout<<"Y:"<<endl;
        cin>>_y[i];
    }
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            cout<<"licz: ";
            cin>>licz;
            cout<<"mian: ";
            cin>>mian;
            _p[i][j] = licz/mian;
            cout<<_p[i][j]<<endl;
        }
    }
    cin>>select;

    switch(select){
        case 1:{
                   double _EX = EX(_x,_p);
                   cout<<"EX = "<<_EX<<endl;
                   double _EY = EY(_y,_p);
                   cout<<"EY = "<<_EY<<endl;
                   cout<<"EX2 = "<<EX2(_x,_p)<<endl;
                   cout<<"EY2 = "<<EY2(_y,_p)<<endl;
                   double _D2X = D2X(_x,_p,_EX);
                   cout<<"D2X = "<<_D2X<<endl;
                   double _D2Y = D2Y(_y,_p,_EY);
                   cout<<"D2Y = "<<_D2Y<<endl;
                   double _EXY = EXY(_x,_y,_p);
                   cout<<"E(X*Y) = "<<_EXY<<endl;
                   double _cov = cov(_EXY,_EX,_EY);
                   cout<<"cov(X,Y) = "<<_cov<<endl;
                   double _pXY = pXY(_cov,_D2Y,_D2X);
                   cout<<"p(X,Y) = "<<_pXY<<endl;
                   break;
               }
        case 2:{
                   double _EZ = EZ(_x,_p);
                   cout<<"EZ = "<<_EZ<<endl;
                   cout<<"D2Z = "<<D2Z(_x,_p,_EZ)<<endl;
                   break;
               }
    }

    return 0;
}
