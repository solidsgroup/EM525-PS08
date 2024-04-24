#include <fstream>
#include <cassert>
#include <filesystem>
#include "Element/Element.H"
#include "Element/CST.H"
#include "Element/LST.H"
#include "Element/Q4.H"
#include "Element/Q9.H"
#include "Mesh/Mesh.H"
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/SparseCore"
#include "eigen3/Eigen/IterativeLinearSolvers"
#include "Model/Isotropic.H"
namespace Mesh
{
template<class MODEL>
class Unstructured : Mesh
{
public:
    Unstructured()
    {};

    Unstructured(std::string vtkfile)
    {
        //
        // TODO: Copy implementation from PS6
        //
    }

    void Print(std::string vtkfile,
               Eigen::VectorXd &disp,
               std::vector<Eigen::Matrix2d> &stress)
    {   
        //
        // TODO: Copy previous implementation 
        //

        // 
        // TODO: Update this function to output the stress tensor for
        //       each element.
        //       The output should look like the following:
        //
        // CELL_DATA [# of elements]
        // TENSORS stress float
        // sig0_xx sig0_xy 0.0
        // sig0_yx sig0_yy 0.0
        // 0.0     0.0     0.0
        //
        // sig1_xx sig1_xy 0.0
        // sig1_yx sig1_yy 0.0
        // 0.0     0.0     0.0
        //
        // ...
        //
    }

    double W(Eigen::VectorXd & u)
    {
        // 
        // TODO: Copy PS07 Implementation 
        // 
    }

    Eigen::VectorXd DW(Eigen::VectorXd & u)
    {
        //
        // TODO: Copy PS07 Implementation 
        // 
    }

    Eigen::SparseMatrix<double> DDW(Eigen::VectorXd & u)
    {
        //
        // TODO: Copy PS07 Implementation 
        // 
    }

    std::vector<Set::Matrix> Stress(Eigen::VectorXd & u)
    {
        //
        // TODO: Finish the implementation of this function for
        //       Q4, LST, Q9 elements.
        //

        std::vector<Set::Matrix> ret = std::vector<Set::Matrix>(nElements());

        for (int e = 0; e < CSTs.size(); e++)
        {
            auto & id = CSTs[e].getid();
            std::array<Eigen::Vector2d, 3> in;
            in[0] << u(2*id[0]), u(2*id[0] + 1);
            in[1] << u(2*id[1]), u(2*id[1] + 1);
            in[2] << u(2*id[2]), u(2*id[2] + 1);

            ret[e] = CSTs[e].Stress(in);
        }
        
        // ... your code goes here ...
        
        return ret;
    }

    // number of nodes
    inline const int size()
    {
        return 2 * Points.size();
    }

    inline const int nPoints()
    {
        return 2 * Points.size();
    }
    
    // Total number of elements in this mesh
    inline const int nElements()
    {
        return CSTs.size() + Q4s.size() + LSTs.size() + Q9s.size();
    }

    // Number of nodes, if not accounting for the fact that
    // some are shared between elements.
    inline const int nElementNodes()
    {
        return 4*CSTs.size() + 5*Q4s.size() + 7*LSTs.size() + 10*Q9s.size();
    }

    std::vector<Eigen::Vector2d> Points;
    std::vector<Element::CST<MODEL>> CSTs;
    std::vector<Element::Q4<MODEL>> Q4s;
    std::vector<Element::LST<MODEL>> LSTs;
    std::vector<Element::Q9<MODEL>> Q9s;

};

}
