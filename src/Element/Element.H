#ifndef ELEMENT_ELEMENT_H
#define ELEMENT_ELEMENT_H
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/LU"
#include <time.h>
#include "Util/Exception.H"
#include "Model/Model.H"

namespace Element
{
template<int D, int N, int Q, class MODEL>
class Element
{
public:

    Element()
    {}
                
    Element(std::vector<Set::Vector> &a_X0, std::array<int,N> a_id) :
        X0(&a_X0), id(a_id)
    {}

    Element(std::array<Set::Vector,N> &a_X0) 
    {
        X0 = new std::vector<Set::Vector>();
        for (int n = 0 ; n < N ; n++)
        {
            X0->push_back(a_X0[n]);
            id[n] = n;
        }
    }

    double W(std::array<Set::Vector,N> &u)
    {
        //
        // TODO: Copy previous implementation
        //
    }


    std::array<Set::Vector,N> DW(std::array<Set::Vector,N> &u)
    {
        //
        // TODO: Copy previous implementation
        //
    }

    std::array<std::array<Set::Matrix,N>,N> DDW(std::array<Set::Vector,N> &u)
    {
        //
        // TODO: Copy previous implementation
        //
    }


    Set::Matrix Stress(std::array<Set::Vector,N> &u)
    {
        //
        // TODO: Implement the Element Stress Function
        //
        // Calculate the average stress in the element by integrating 
        // DW over the element and dividing by the volume.
        // 
        // Return the stres as a matrix.
        //
    }


    virtual std::array<double,N> eta(Set::Vector y) = 0;

    virtual std::array<Set::Vector,N> Deta(Set::Vector y) = 0;

    Set::Matrix Jacobian(Set::Vector Y)
    {
        //
        // TODO: copy your previous implementation.
        //
    }

public:
    constexpr int getN() {return N;}
    virtual const std::array<Set::Vector,N> & getY0() = 0;
    virtual const std::array<Set::Vector,Q> & getQp() = 0;
    virtual const std::array<double,Q> & getQw() = 0;
    virtual const double getArea() = 0;
    virtual const std::array<int,N> & getid() {return id;};

    static const int _D = D; // The DIMENSION of the space (2d or 3d)
    static const int _N = N; // The number of NODES in the element
    static const int _Q = Q; // The number of QUADRATURE POINTS in the element

private:
    std::vector<Set::Vector> *X0;
    std::array<int,N> id;
    std::array<MODEL,Q> model; 

public:

    static const int vtkid = 0;

};



}
#endif
