# Directories configuration

# Main directories
fnb     = 'f_n_b/'
include = 'include/'
source  = 'src/'
test    = 'test/'
objects = 'objects/'

# Packages directories
gtl   = 'gt/gtl/'
model = 'gt/model/'

################################################################################

# Production environment configuration

env  = Environment()
conf = Configure(env)

validInstallation = True

# C++ check
if not conf.CheckCXX():
    print('Your environment/C++ compiler is not configured/installed correctly!!')
    validInstallation = False

# Header check
for header in [
    # standard libraries
    'cstdlib', 'iostream', 'fstream', 'string',
    # boost libraries
    'boost/shared_ptr.hpp',
    'boost/container/map.hpp',
    'boost/container/vector.hpp',
    'boost/thread/mutex.hpp',
    # Flex library
    'FlexLexer.h',
    # GNU Multiple Precision library
    'gmpxx.h',
]:
    if not conf.CheckCXXHeader(header):
        print('Your environment does not seem to have header <'+header+'>!!')
        validInstallation = False

# Terminate build if installation is not valid
if not validInstallation:
    print('Invalid compiler/libraries installation - build terminated!!')
    Exit(1)

# Adds headers dirs:
# - include/ - public include directory,
# - include/gt/gtl - added for using parser.hpp in GT::GTL::Scanner
#   (poor custom path definitions),
# - src/gt/gtl - added for using location.hh, position.hh and stack.hh
#   in GT::GTL::Parser (as above).
conf.env.Append(CPPPATH=[include, include+gtl, source+gtl])

conf.Finish()

################################################################################

# Test environment configuration

testEnv = env.Clone()
testConf = Configure(env)

validInstallation = True

# Header check
for header in [
    # boost libraries
    'boost/test/unit_test.hpp',
]:
    if not testConf.CheckCXXHeader(header):
        print('Your environment does not seem to have header <'+header+'>!!')
        validInstallation = False

# Terminate build if installation is not valid
if not validInstallation:
    print('Invalid compiler/libraries installation - build terminated!!')
    Exit(1)

# Adds tests directories to the path:
# - test
# - test/gt/model
# - test/gt/gtl
testConf.env.Append(CPPPATH=[test, test+model, test+gtl])
testConf.env.Append(LIBS=['boost_unit_test_framework'])

testConf.Finish()

################################################################################

# Build Model objects

Model_Root_cpp_URI          = source +model+'root.cpp'
Model_Root_o_URI            = objects+model+'root.o'
Model_Player_cpp_URI        = source +model+'player.cpp'
Model_Player_o_URI          = objects+model+'player.o'
Model_ResultFactory_cpp_URI = source +model+'result_factory.cpp'
Model_ResultFactory_o_URI   = objects+model+'result_factory.o'
Model_NullFactory_cpp_URI   = source +model+'null_factory.cpp'
Model_NullFactory_o_URI     = objects+model+'null_factory.o'

Model_Root_o          = env.Object(source=Model_Root_cpp_URI,          target=Model_Root_o_URI)
Model_Player_o        = env.Object(source=Model_Player_cpp_URI,        target=Model_Player_o_URI)
Model_ResultFactory_o = env.Object(source=Model_ResultFactory_cpp_URI, target=Model_ResultFactory_o_URI)
Model_NullFactory_o   = env.Object(source=Model_NullFactory_cpp_URI,   target=Model_NullFactory_o_URI)

################################################################################

# Test Model objects

# TODO

################################################################################

# Builds parser and scanner classes

FnB_Parser_yy_URI   = fnb        +'parser.yy'
GTL_Parser_cpp_URI  = source +gtl+'parser.cpp'
GTL_Parser_hpp_URI  = include+gtl+'parser.hpp'
FnB_Scanner_ll_URI  = fnb        +'scanner.ll'
GTL_Scanner_cpp_URI = source +gtl+'scanner.cpp'

env.Append(YACCFLAGS='--defines='+GTL_Parser_hpp_URI)
GTL_Parser_cpp, GTL_Parser_hpp = env.CXXFile(source=FnB_Parser_yy_URI,  target=GTL_Parser_cpp_URI)
GTL_Scanner_cpp                = env.CXXFile(source=FnB_Scanner_ll_URI, target=GTL_Scanner_cpp_URI)

################################################################################

# Build GTL objects

GTL_Object_cpp_URI       = source +gtl+'object.cpp'
GTL_Object_o_URI         = objects+gtl+'object.o'
GTL_Param_cpp_URI        = source +gtl+'param.cpp'
GTL_Param_o_URI          = objects+gtl+'param.o'
GTL_ParamFactory_cpp_URI = source +gtl+'param_factory.cpp'
GTL_ParamFactory_o_URI   = objects+gtl+'param_factory.o'
GTL_NullFactory_cpp_URI  = source +gtl+'null_factory.cpp'
GTL_NullFactory_o_URI    = objects+gtl+'null_factory.o'

GTL_Object_o        = env.Object(source=GTL_Object_cpp_URI,       target=GTL_Object_o_URI)
GTL_Param_o         = env.Object(source=GTL_Param_cpp_URI,        target=GTL_Param_o_URI)
GTL_ParamFactory_o  = env.Object(source=GTL_ParamFactory_cpp_URI, target=GTL_ParamFactory_o_URI)
GTL_NullFactory_o   = env.Object(source=GTL_NullFactory_cpp_URI,  target=GTL_NullFactory_o_URI)

GTL_Parser_o_URI  = objects+gtl+'parser.o'
GTL_Scanner_o_URI = objects+gtl+'scanner.o'

GTL_Parser_o  = env.Object(source=GTL_Parser_cpp,  target=GTL_Parser_o_URI)
GTL_Scanner_o = env.Object(source=GTL_Scanner_cpp, target=GTL_Scanner_o_URI)


################################################################################

# Test GTL objects

# TODO
