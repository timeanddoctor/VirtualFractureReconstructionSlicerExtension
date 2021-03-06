
#ifndef __vtkComputeLocalGeometry_h
#define __vtkComputeLocalGeometry_h

#include "vtkPolyDataAlgorithm.h"
#include "MeshOps.h"

#include <list>

class vtkComputeLocalGeometry : public vtkPolyDataAlgorithm
{
public:
  vtkTypeMacro( vtkComputeLocalGeometry, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Default <TODO>
  static vtkComputeLocalGeometry *New();

  // Description:
  //  Macro for ... ?
  //vtkSetClampMacro( SomeParam,double,0.0,1.0);
  //vtkGetMacro( SomeParam,double);

  // Description:
  // Specify the number of iterations for Laplacian smoothing,
  //vtkSetClampMacro(NumberOfIterations,int,0,VTK_LARGE_INTEGER);
  //vtkGetMacro(NumberOfIterations,int);

  // Description:
  // Specify t..
//  vtkSetMacro(RelaxationFactor,double);
 // vtkGetMacro(RelaxationFactor,double);

  // Description:
  // Turn on/off ....
  //vtkSetMacro(FeatureEdgeSmoothing,int);
  //vtkGetMacro(FeatureEdgeSmoothing,int);
  //vtkBooleanMacro(FeatureEdgeSmoothing,int);

  // Description:
  // Specify the source object ... not needed ??
  void SetSource(vtkPolyData *source);
  vtkPolyData *GetSource();
  
  float* sC;

  int Get_evolve_its() { return evolve_its; }
  int Get_mesh_smooth_its() { return mesh_smooth_its; }
  int Get_H_smooth_its() { return H_smooth_its; }
  int Get_adj_levels() { return adj_levels; }
  int Get_rightHandMesh() { return rightHandMesh; }

  void Set_evolve_its(int param) { evolve_its = param; }
  void Set_mesh_smooth_its(int param) {mesh_smooth_its = param; }
  void Set_H_smooth_its(int param) {H_smooth_its = param; }
  void Set_adj_levels(int param) {adj_levels = param; }
  void Set_rightHandMesh(int param) {rightHandMesh = param; }
  

  MeshDataCustom* GetMeshData() { return myMeshData; }
  void SetMeshData(MeshDataCustom* data) { myMeshData = data; }
  void GetLists(   list<int>& C, list<int>& L_p1,   list<int>& L_n1,   list<int>& L_p2,
    list<int>& L_n2,   vector<int>& map_ ) {
      C = Lz;  L_n1=Ln1 ;   L_p1=Lp1; L_n2 = Ln2; L_p2 = Lp2; map_ = map;
  }

protected:
  vtkComputeLocalGeometry();
  ~vtkComputeLocalGeometry() {};

  virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  virtual int FillInputPortInformation(int port, vtkInformation *info);

private:
  vtkComputeLocalGeometry(const vtkComputeLocalGeometry&);  // Not implemented.
  void operator=(const vtkComputeLocalGeometry&);  // Not implemented.
  MeshDataCustom* myMeshData;
  list<int> Lz;
  list<int> Ln1;
  list<int> Lp1;
  list<int> Ln2;
  list<int> Lp2;
  vector<int> map;

  int evolve_its;
  int mesh_smooth_its;
  int H_smooth_its;
  int adj_levels;
  int rightHandMesh;

};

#endif
