
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

namespace py = pybind11;

#include "G4Version.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4VSolid.hh"
#include "G4FieldManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4UserLimits.hh"
#include "G4SmartVoxelHeader.hh"
#include "G4MaterialCutsCouple.hh"
#include "G4FastSimulationManager.hh"
#include "G4VisAttributes.hh"

//using namespace pyG4LogicalVolume;

void init_G4LogicalVolume(py::module & m) {

  py::class_<G4LogicalVolume>(m, "G4LogicalVolume")
    
    // constructors
    .def(py::init<G4VSolid*, G4Material*, const G4String& >())

    .def(py::init<G4VSolid*, G4Material*, const G4String&,
         G4FieldManager* >())

    .def(py::init<G4VSolid*, G4Material*, const G4String&,
         G4FieldManager*, G4VSensitiveDetector* >())

    .def(py::init<G4VSolid*, G4Material*, const G4String&,
         G4FieldManager*, G4VSensitiveDetector*,
         G4UserLimits* >())

    .def(py::init<G4VSolid*, G4Material*, const G4String&,
         G4FieldManager*, G4VSensitiveDetector*,
         G4UserLimits*, G4bool >())

    
    .def("GetName",         &G4LogicalVolume::GetName, py::return_value_policy::reference)
    //         return_value_policy<reference_existing_object>())
    .def("SetName",         &G4LogicalVolume::SetName)

    
    .def("GetNoDaughters",  &G4LogicalVolume::GetNoDaughters)
    .def("GetDaughter",     &G4LogicalVolume::GetDaughter, py::return_value_policy::reference_internal)//,
    //return_internal_reference<>())
    .def("AddDaughter",     &G4LogicalVolume::AddDaughter)
    .def("IsDaughter",      &G4LogicalVolume::IsDaughter)
    .def("IsAncestor",      &G4LogicalVolume::IsAncestor)
    .def("RemoveDaughter",  &G4LogicalVolume::RemoveDaughter)
    .def("ClearDaughters",  &G4LogicalVolume::ClearDaughters)
    .def("TotalVolumeEntities", &G4LogicalVolume::TotalVolumeEntities)


    // .def("GetSolid",        f1_GetSolid)
    // //return_internal_reference<>())
    // .def("SetSolid",        f1_SetSolid)

    .def("GetMaterial",     &G4LogicalVolume::GetMaterial, py::return_value_policy::reference_internal)
    //	       return_internal_reference<>())
    .def("SetMaterial",     &G4LogicalVolume::SetMaterial)
    .def("UpdateMaterial",  &G4LogicalVolume::UpdateMaterial)


    .def("GetMass",         &G4LogicalVolume::GetMass)//, f_GetMass())
    .def("GetFieldManager", &G4LogicalVolume::GetFieldManager, py::return_value_policy::reference_internal)
    //	       return_internal_reference<>())
    .def("SetFieldManager", &G4LogicalVolume::SetFieldManager)
    .def("GetSensitiveDetector", &G4LogicalVolume::GetSensitiveDetector, py::return_value_policy::reference_internal)
    //	       return_internal_reference<>())
    .def("SetSensitiveDetector", &G4LogicalVolume::SetSensitiveDetector)
    .def("GetUserLimits",   &G4LogicalVolume::GetUserLimits, py::return_value_policy::reference_internal)
    //	       return_internal_reference<>())
    .def("SetUserLimits",   &G4LogicalVolume::SetUserLimits)

    
    .def("GetVoxelHeader",  &G4LogicalVolume::GetVoxelHeader, py::return_value_policy::reference_internal)
    //	       return_internal_reference<>())
    .def("SetVoxelHeader",  &G4LogicalVolume::SetVoxelHeader)
    .def("GetSmartless",    &G4LogicalVolume::GetSmartless)
    .def("SetSmartless",    &G4LogicalVolume::SetSmartless)
    .def("IsToOptimise",    &G4LogicalVolume::IsToOptimise)
    .def("SetOptimisation", &G4LogicalVolume::SetOptimisation)

    
    .def("IsRootRegion",    &G4LogicalVolume::IsRootRegion)
    .def("SetRegionRootFlag", &G4LogicalVolume::SetRegionRootFlag)
    .def("IsRegion",        &G4LogicalVolume::IsRegion)
    .def("SetRegion",       &G4LogicalVolume::SetRegion)
    .def("GetRegion",       &G4LogicalVolume::GetRegion, py::return_value_policy::reference_internal)
    //	       return_internal_reference<>())
    .def("PropagateRegion", &G4LogicalVolume::PropagateRegion)
    .def("GetMaterialCutsCouple", &G4LogicalVolume::GetMaterialCutsCouple, py::return_value_policy::reference_internal)
    //	       return_internal_reference<>())
    .def("SetMaterialCutsCouple", &G4LogicalVolume::SetMaterialCutsCouple)


    .def("GetVisAttributes", &G4LogicalVolume::GetVisAttributes, py::return_value_policy::reference_internal)
    //	       return_internal_reference<>())

    // FIXME 
    //.def("SetVisAttributes", f1_SetVisAttributes)
    //.def("SetVisAttributes", f2_SetVisAttributes)

    .def("GetFastSimulationManager", &G4LogicalVolume::GetFastSimulationManager, py::return_value_policy::reference_internal)
    //	      return_internal_reference<>())
    // ---
    .def("SetBiasWeight",  &G4LogicalVolume::SetBiasWeight)
    .def("GetBiasWeight",  &G4LogicalVolume::GetBiasWeight)

    // debug destructor
    .def("__del__",
         [](const G4LogicalVolume&) -> void { 
           std::cerr << "---------------> deleting G4LogicalVolume" << std::endl;
         })

    
    ;
}
