classdef test_class < handle
  properties (GetAccess=private)
    cl_tor
    cl_sphere
  end
  properties (Constant)
    cnst = 12345;
  end
  properties (Dependent)
    dep_val;
  end
  properties
    A
  end
  methods
    function obj = test_class(A, B)
      obj.A = A;
      obj.B = B;
    end
    function otor(obj, rr = 100)
      obj.B = rr;
      rr
      obj.B
      tor(rr)
    end
    function print_val(obj)
      obj.B
    end
    function obj = change_B(obj, b)
      obj.B = b
    end
  end
end
# clear; clear classes; clear functions; clear all;
