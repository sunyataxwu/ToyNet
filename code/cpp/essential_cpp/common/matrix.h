

#ifndef __ESSENTIAL_CPP__MATRIX_H__
#define __ESSENTIAL_CPP__MATRIX_H__

#include <iostream>
class Matrix
{
    friend std::ostream& operator<<(std::ostream &os, const Matrix &rhs);
    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs);
public:
    Matrix(int row, int col);
    Matrix(const Matrix &rhs);
    ~Matrix();

    Matrix& operator=(const Matrix &rhs);
public:
    Matrix& operator+=(const Matrix &rhs);

    int col() const {return col_; }
    int row() const { return row_; }

    double& operator()(int row, int col) { return pmat_[row][col]; }
    double operator()(int row, int col) const { return pmat_[row][col]; }

    std::ostream& Print(std::ostream &os = std::cout)const;
private:
    void Destory();
    void Assign(int row, int col);
private:
    int     row_,col_;
    double  **pmat_;
};

std::ostream& operator<<(std::ostream &os, const Matrix &rhs);
Matrix operator+(const Matrix &lhs, const Matrix &rhs);

#include <assert.h>

namespace common
{
template <typename elemType>
class Matrix 
{
    friend Matrix<elemType> operator+( const Matrix<elemType>&m1, const Matrix<elemType> &m2 )
    {
        assert( m1.comfortable( m2 ) != 0 );
        Matrix<elemType> result( m1.rows(), m2.cols() );
    
        for ( int ix = 0; ix < m1.rows(); ix++ ) {
            for ( int jx = 0; jx < m1.cols(); jx++ ) {
                    result( ix, jx ) = 0;
                    for ( int kx = 0; kx < m1.cols(); kx++ )
                    result( ix, jx ) += m1( ix, kx ) * m2( kx, jx );
            }
        }
        return result;
    }
    friend Matrix<elemType> operator*( const Matrix<elemType> &m1, const Matrix<elemType> &m2 )
    {
        assert( m1.comfortable( m2 ) != 0 );
        Matrix<elemType> result( m1.rows(), m2.cols() );
    
        for ( int ix = 0; ix < m1.rows(); ix++ ) {
            for ( int jx = 0; jx < m1.cols(); jx++ ) {
                    result( ix, jx ) = 0;
                    for ( int kx = 0; kx < m1.cols(); kx++ )
                    result( ix, jx ) += m1( ix, kx ) * m2( kx, jx );
            }
        }
        return result;
    }

public:
    Matrix( int rows, int columns );
    Matrix( const Matrix& );
    ~Matrix(){ delete [] _matrix; }
    Matrix& operator=( const Matrix& );

    void operator+=( const Matrix& );
    elemType& operator()( int row, int column ) { return _matrix[ row * cols() + column ]; }

    const elemType& operator()( int row, int column ) const { return _matrix[ row * cols() + column ]; }

    int rows() const { return _rows; }
    int cols() const { return _cols; }

    bool same_size( const Matrix &m ) const { return rows() == m.rows() && cols() == m.cols(); }
    bool comfortable( const Matrix &m ) const { return ( cols() == m.rows() ); }
    std::ostream& print( std::ostream& ) const;

protected:
    int  _rows;
    int  _cols;
    elemType *_matrix;
};

template <typename elemType>
inline std::ostream& operator<<( std::ostream& os, const Matrix<elemType> &m )
    { return m.print( os ); }

// end of Matrix.h
// template <typename elemType>
// inline Matrix< elemType > operator+( const Matrix<elemType> &m1, const Matrix<elemType> &m2 )
// {
//     assert( m1.same_size( m2 ) != 0 );

//     Matrix<elemType> result( m1 );
//     result += m2;
//     return result;
// }

// template <typename elemType>
// inline Matrix<elemType> operator*( const Matrix<elemType> &m1, const Matrix<elemType> &m2 )
// {
//     assert( m1.comfortable( m2 ) != 0 );
//     Matrix<elemType> result( m1.rows(), m2.cols() );

//     for ( int ix = 0; ix < m1.rows(); ix++ ) {
//         for ( int jx = 0; jx < m1.cols(); jx++ ) {
//                 result( ix, jx ) = 0;
//                 for ( int kx = 0; kx < m1.cols(); kx++ )
//                 result( ix, jx ) += m1( ix, kx ) * m2( kx, jx );
//         }
//     }
//     return result;
// }

template <typename elemType>
void Matrix<elemType>::operator+=( const Matrix &m )
{
    assert( same_size( m ) != 0 );
    register int matrix_size = cols() * rows();

    for ( int ix = 0; ix < matrix_size; ++ix )
        ( *( _matrix + ix )) += ( *( m._matrix + ix ));
}

template <typename elemType>
std::ostream& Matrix<elemType>::print( std::ostream &os ) const
{
    register int col = cols();
    register int matrix_size = col * rows();

    for ( int ix = 0; ix < matrix_size; ++ix )
    {
        if ( ix % col == 0 ) os << std::endl; 
        os << ( *( _matrix + ix )) << ' ';
    }

    os << std::endl;
    return os;
}

template <typename elemType>
Matrix<elemType>::Matrix( const Matrix & rhs )
{ 
    _rows = rhs._rows; _cols = rhs._cols;
    int mat_size = _rows * _cols;
    _matrix = new elemType[ mat_size ];
    for ( int ix = 0; ix < mat_size; ++ix )
            _matrix[ ix ] = rhs._matrix[ ix ]; 

}

template <typename elemType>
Matrix<elemType>& Matrix<elemType>::
operator=( const Matrix &rhs ) 
{
    if ( this != &rhs )
    {
            _rows = rhs._rows; _cols = rhs._cols;
            int mat_size = _rows * _cols;
            delete [] _matrix;
            _matrix = new elemType[ mat_size ];
            for ( int ix = 0; ix < mat_size; ++ix )
                _matrix[ ix ] = rhs._matrix[ ix ]; 
    }
    return *this;
}

template <typename elemType>
Matrix<elemType>::Matrix( int rows, int columns )
            : _rows( rows ), _cols( columns )
{
    int size = _rows * _cols;
    _matrix = new elemType[ size ];
    for ( int ix = 0; ix < size; ++ix )
            _matrix[ ix ] = elemType();
}

}

#endif // __ESSENTIAL_CPP__MATRIX_H__
