

Some hints boost-python vs pybind11


- bases is not any longer required. Only its template argument must
  remain, in the same position of what was there before.

- The noncopyable template argument should not be provided (everything
  is noncopyable unless specified) - if something is to be made
  copyable, a copy constructor should be provided to python
  
  
  
- return policies
  https://pybind11.readthedocs.io/en/stable/advanced/functions.html
 
  return_value_policy<reference_existing_object>
  -->
  py::return_value_policy::reference 
  
  return_internal_reference<>()
  -->
  py::return_value_policy::reference_internal
      
  return_value_policy<return_by_value>()
  --> 
  py::return_value_policy::copy	 ??????
  

- add_property
  -->
  .def_readwrite


- debug
  python -q -X faulthandler
