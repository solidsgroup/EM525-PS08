# FEM Coding Assignment: Stresses and Convergence Study


## Initial setup (same as before)

1. Check out the problem repository
    
         git clone https://github.com/solidsgroup/EM525-PS08.git
   
2. Change into the problem directory

         cd EM525-PS07
   
3. Use this command to install eigen (optional: you can skip this if you have eigen installed)

         make eigen

4. Now, compile the code

         make

   The code **will not compile** because there are missing files.
   These files must be copied as specified below before you can compile.


## Part 0: Copying previous implementation

Copy the following files directly from PS05. 

- `src/Element/LST.H`
- `src/Element/CST.H`
- `src/Element/Q4.H`
- `src/Element/Q9.H`
- `src/Model/Isotropic.H`

If you do this correctly the code will compile.

## Part 1: Calculate element stresses

Edit the following file

- `src/Element/Element.H`

* Update the missing code with your code from PS07.

* Implement the `Stress` function, which calculates the average stress over the element and returns
  the corresponding stress tensor as a matrix.

Edit the following file

- `src/Mesh/Unstructured.H`

* Update the missing code with your code from PS07

* Complete the implementation of the `Stress` function, which calculates the stresses for all elements
  and stores them in a vector.

* Complete the implementation of the `Print` function to include stress as an ouptut.


## Part 2: Mesh convergence

The following mesh files are included:

- `platehole_cst.vtk`
- `platehole_cst_refine1.vtk`
- `platehole_cst_refine2.vtk`
- `platehole_lst.vtk`
- `platehole_lst_refine1.vtk`
- `platehole_lst_refine2.vtk`
- `platehole_q4.vtk`
- `platehole_q4_refine1.vtk`
- `platehole_q4_refine2.vtk`
- `platehole_q9.vtk`
- `platehole_q9_refine1.vtk`
- `platehole_q9_refine2.vtk`

(Note: the `q9_refine2` may take a little while to run, especially on older computers.)

All meshes have the same geometry, but different elements and differing resolutions.
Run the code for each of these meshes, and report the convergence (via a plot) of the solution with respect to average element size and element order.



