#include <iostream>
#include <math.h>

using namespace std;
size_t il_x,il_y;

double EX(double *_x,double **_p){
    double _EX,tmmp,tmp[il_x];
    for(size_t i = 0;i<il_x;i++){
        for(size_t j = 0; j<il_y;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(size_t i=0;i<il_x;i++){
        _EX += _x[i]*tmp[i];
    }
    return _EX;
}
double EY(double *_y,double **_p){
    double _EY,tmmp,tmp[il_y],transponse[il_y][il_x];
    for(size_t i = 0;i<il_x;i++){
        for(size_t j = 0;j<il_y;j++){
            transponse[j][i] = _p[i][j];
        }
    } 
    for(size_t i = 0;i<il_y;i++){
        for(size_t j = 0; j<il_x;j++){
            tmmp += transponse[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(size_t i=0;i<il_y;i++){
        _EY += _y[i]*tmp[i];
    }
    return _EY;
}
double EZ(double *_x,double **_p){
    double _EZ,tmmp,tmp[il_x];
    for(size_t i = 0;i<il_x;i++){
        for(size_t j = 0; j<il_y;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(size_t i=0;i<il_x;i++){
        _EZ += (-2*_x[i]-1)*tmp[i];/* change this */
    }
    return _EZ;
}

double EX2(double *_x,double **_p){
    double _EX2,tmmp,tmp[il_x];
    for(size_t i = 0;i<il_x;i++){
        for(size_t j = 0; j<il_y;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(size_t i=0;i<il_x;i++){
        _EX2 += pow(_x[i],2)*tmp[i];
    }
    return _EX2;
}
double EY2(double *_y,double **_p){
    double _EY2,tmmp,tmp[il_y],transponse[il_y][il_x];
    for(size_t i = 0;i<il_x;i++){
        for(size_t j = 0;j<il_y;j++){
            transponse[j][i] = _p[i][j];
        }
    } 
    for(size_t i = 0;i<il_y;i++){
        for(size_t j = 0; j<il_x;j++){
            tmmp += transponse[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(size_t i=0;i<il_y;i++){
        _EY2 += pow(_y[i],2)*tmp[i];
    }
    return _EY2;
}
double D2X(double *_x,double **_p,double EX){
    double _D2X,tmmp,tmp[il_x];
    for(size_t i = 0;i<il_x;i++){
        for(size_t j = 0; j<il_y;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(size_t i=0;i<il_x;i++){
        _D2X += pow(_x[i]-EX,2)*tmp[i];
    }
    return _D2X;
}
double D2Y(double *_y,double **_p,double EY){
    double _D2Y = 0,tmmp = 0,tmp[il_y],transponse[il_y][il_x];
    for(size_t i = 0;i<il_x;i++){
        for(size_t j = 0;j<il_y;j++){
            transponse[j][i] = _p[i][j];
        }
    } 
    for(size_t i = 0;i<il_y;i++){
        for(size_t j = 0; j<il_x;j++){
            tmmp += transponse[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(size_t i=0;i<il_y;i++){
        _D2Y += pow(_y[i]-EY,2)*tmp[i];
    }
    return _D2Y;
}

double D2Z(double *_x,double **_p,double EZ){
    double _D2Z,tmmp,tmp[il_x];
    for(size_t i = 0;i<il_x;i++){
        for(size_t j = 0; j<il_y;j++){
            tmmp += _p[i][j];
        }
        tmp[i] = tmmp;
        tmmp = 0;
    }
    for(size_t i=0;i<il_x;i++){
        _D2Z += pow((-2*_x[i]-1)-EZ,2)*tmp[i];/* change this */
    }
    return _D2Z;
}
double EXY(double *_x,double *_y,double **_p){
    double EXY = 0;
    for(size_t i = 0; i<il_x; i++){
        for(size_t j = 0; j<il_y; j++){
            EXY += _x[i]*_y[j]*_p[i][j];
        }
    }
    return EXY;
}
float cov(double EXY,double EX,double EY){
    return EXY-EX*EY;
}

float pXY(double cov,double D2Y,double D2X){
    return cov/sqrt(D2X*D2Y);
}

int main(){
    size_t wyb;
    cout<<"Podaj wymiary: "<<endl<<"ile X:";
    cin>>il_x;
    cout<<"ile Y: ";
    cin>>il_y;
    double *_x = new double[il_x],*_y = new double[il_y],**_p = new double*[il_x],licz,mian;
    int select;
    for(size_t i = 0;i<il_x;i++){
        cout<<"X:"<<endl;
        cin>>_x[i];
        _p[i] = new double[il_y];
    }
    for(size_t i = 0;i<il_y;i++){
        cout<<"Y:"<<endl;
        cin>>_y[i];
    }
    cout<<"1. ułamek\n2. liczba";
    cin>>wyb;
    switch(wyb){
        case 1:{
                   for(size_t i =0;i<il_x;i++){
                       for(size_t j =0;j<il_y;j++){
                           cout<<"licz: ";
                           cin>>licz;
                           cout<<"mian: ";
                           cin>>mian;
                           if(mian==0){
                                _p[i][j] = 0;
                           }
                           else{
                                _p[i][j] = licz/mian;
                           }
                           cout<<_p[i][j]<<endl;
                       }
                   }
                       break;
               }
        case 2:{
                   for(size_t i =0;i<il_x;i++){
                       for(size_t j =0;j<il_y;j++){
                           cout<<"liczba: ";
                           cin>>licz;
                           _p[i][j] = licz;
                           cout<<_p[i][j]<<endl;
                       }
                   }
                       break;
               }
               }
               while(select!=3){
                   cout<<"menu: "<<endl<<"1. kalkulator"<<endl<<"2. EZ i D2Z"<<endl<<"3. exit"<<endl;
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
                                  float _cov = cov(_EXY,_EX,_EY);
                                  cout<<"cov(X,Y) = "<<_cov<<endl;
                                  float _pXY = pXY(_cov,_D2Y,_D2X);
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
               }
               return 0;
    }
