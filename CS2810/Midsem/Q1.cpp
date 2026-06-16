#include <iostream>
#include <vector>
using namespace std;
class Matrix{
public:
int row;
int col;
int **mat;
public:
Matrix(int row,int col) {
    this->row=row;
    this->col=col;
    mat=new int*[row];
    for(int i=0;i<row;i++) {
        mat[i]=new int[col];
    }
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            mat[i][j]=0;
        }
    }
}
void input(){
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cin>>mat[i][j];
        }
    }
}
void display(){
     for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
virtual void compute(){

};
Matrix& operator+(Matrix &b);
Matrix& operator*(Matrix &b);
bool operator==(Matrix &b);
};
Matrix& Matrix::operator+(Matrix &b) {
Matrix c(b.row,b.col);
for(int i=0;i<row;i++) {
    for(int j=0;j<col;j++) {
        c.mat[i][j]=mat[i][j]+b.mat[i][j];
    }
}
c.display();
return c;
}
Matrix& Matrix::operator*(Matrix &b) {
Matrix c(row,b.col);
for(int i=0;i<c.row;i++) {
    for(int j=0;j<c.col;j++) {
        c.mat[i][j]=0;
        for(int k=0;k<col;k++) {
            c.mat[i][j]+=(mat[i][k]*b.mat[k][j]);
        }
    }
}
c.display();
return c;
}
bool Matrix::operator==(Matrix &b) {
if(row!=b.row || col !=b.col) return false;
for(int i=0;i<row;i++) {
    for(int j=0;j<col;j++) {
        if(mat[i][j]!= b.mat[i][j]) return false;
    }
}
return true;
}
class SquareMatrix:public Matrix {
    public:
    SquareMatrix(int r,int c):Matrix(r,c) {
    }
    void compute(){

    }
};
class DiagonalMatrix:public SquareMatrix {
    public:
    DiagonalMatrix(int r,int c):SquareMatrix(r,c) {
    }
    void compute(){
        int flag=0;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(mat[i][j]!=0 && i!=j) flag=1;
            }
        }
        if(flag==0) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
};

int main(){
    string s;
    cin>>s;
    if(s=="P1") {
        int r,c;cin>>r>>c;
        Matrix m(r,c);m.input();
        m.display();
    }
    else if(s=="P2") {
        int r1,c1;cin>>r1>>c1;
        Matrix a(r1,c1);a.input();
        int r2,c2;cin>>r2>>c2;
        Matrix b(r2,c2);b.input();
        int op;cin>>op;
        if(op==1) {
            if(r1==r2 && c1==c2) {
           Matrix c=a+b;
            }
            else {
                cout<<"incompatable matrices"<<endl;
            }
        }
        else if(op==2) {
            if(c1==r2) {
           Matrix c=a*b;
            }
            else {
                cout<<"incompatable matrices"<<endl;
            }
        }
        else {
            if(a==b) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
    }
    else {
        Matrix* m;
        int type;cin>>type;
        int r,c;cin>>r>>c;
        if(type==1) m=new SquareMatrix(r,c);
        else m=new DiagonalMatrix(r,c);
        m->input();
        m->compute();
    }
    return 0;
}
