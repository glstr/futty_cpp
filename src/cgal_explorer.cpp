
#include "cgal_explorer.h"

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>
//#include <CGAL/Parameterization_polyhedron_adaptor_3.h>
//#include <CGAL/parameterize.h>
#include <iostream>
#include <fstream>

using namespace std;

namespace snow {
typedef CGAL::Simple_cartesian<double>      Kernel;
typedef CGAL::Polyhedron_3<Kernel>          Polyhedron;

void CgalExplorer::simple_test() {
    const char* input_filename  = "/Users/pengbaojiang/pengbaojiang/code/cpp_src/futty_cpp/build/src/test.off";
    //***************************************
    // Read the mesh
    //***************************************
    // Read the mesh
    std::ifstream stream(input_filename);
    Polyhedron mesh;
    stream >> mesh;
    cout << "mesh:" << mesh.is_valid() << "empty:" << mesh.empty();
    if(!stream || !mesh.is_valid() || mesh.empty())
    {
        std::cerr << "Error: cannot read OFF file " << input_filename << std::endl;
        return;
    }
    return;
}

}// end namspace snow;
