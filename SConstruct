import os

################################################################################

# Directories configuration

# Main directories
fnb      = 'f_n_b/'
include  = 'include/'
source   = 'src/'
test     = 'test/'
objects  = 'objects/'
programs = 'bin/'

# Packages directories
gtl   = 'gt/gtl/'
model = 'gt/model/'

################################################################################

# Helpers for building objects and programs

def targetForSource(file):
    return str(file).replace('.cpp', '.o').replace(source, objects)

def targetForTest(file):
    return str(file).replace('.cpp', '_test.o').replace(test, objects)

################################################################################

# Production environment configuration

env = Environment()

# Allows overridding default compiler with eg. Clang.
env["CC"]  = os.getenv("CC")  or env["CC"] 
env["CXX"] = os.getenv("CXX") or env["CXX"]
env["ENV"].update(x for x in os.environ.items() if x[0].startswith("CCC_"))

conf = Configure(env)

validInstallation = True

# C++ check
if not conf.CheckCXX():
    print('Your environment/C++ compiler is not configured/installed correctly!!')
    validInstallation = False

# Header check
for header in [
    # standard libraries
    'cstdlib', 'iostream', 'fstream',
    'stdexcept', 'string', 'utility',
    # boost libraries
    'boost/scoped_ptr.hpp',
    'boost/shared_ptr.hpp',
    'boost/weak_ptr.hpp',
    'boost/bimap/bimap.hpp',
    'boost/container/map.hpp',
    'boost/container/set.hpp',
    'boost/container/vector.hpp',
    'boost/range/adaptor/map.hpp',
    'boost/range/adaptor/reversed.hpp',
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

# Sets C++11 standard to be used during compilation.
conf.env.Append(CPPFLAGS=['-std=c++11'])

# Adds headers dirs:
# - include/ - public include directory,
# - include/gt/gtl - added for using parser.hpp in GT::GTL::Scanner
#   (poor custom path definitions),
# - src/ - added for implemetnations headers,
# - src/gt/gtl - added for using location.hh, position.hh and stack.hh
#   in GT::GTL::Parser (as above).
conf.env.Append(CPPPATH=[include, include+gtl, source, source+gtl])

# Sets used libraries to:
# - gmp - GNU Multiple Precision library,
# - gmpxx - C++ wrappers for GMP.
conf.env.Append(LIBS=['gmp', 'gmpxx'])

conf.Finish()

# Creates separate environment for parser and scanner
parserEnv = env.Clone()

# Sets warning informations in main conf.
env.Append(CPPFLAGS=['-Wall', '-Wextra', '-pedantic'])

################################################################################

# Test environment configuration

testEnv  = env.Clone()
testConf = Configure(testEnv)

validInstallation = True

# Header check
for header in [
    # boost libraries
    'boost/test/unit_test.hpp',
    'boost/test/test_tools.hpp'
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

logLevel     = 'test_suite'
randomOrder  = '0'
showProgress = 'no'

################################################################################

# Build Model objects

Models = [
    env.Object(
        source=Model_cpp,
        target=targetForSource(Model_cpp)
    )
    for Model_cpp in Glob(source+model+'*.cpp')
]
env.Alias('buildModels', Models)

################################################################################

# Build Models' Tests objects

ModelsTests = [
    testEnv.Object(
        source=ModelTest_cpp,
        target=targetForTest(ModelTest_cpp)
    )
    for ModelTest_cpp in Glob(test+model+'*.cpp')
]
testEnv.Alias('buildModelsTests', ModelsTests)

################################################################################

# Build and run Model tests

ModelsTestsProgram_URI = programs+'ModelsTests'
ModelsTestsProgram_bin = testEnv.Program(
    source=Models + ModelsTests,
    target=ModelsTestsProgram_URI
)
ModelsTestsProgram_run = Command(
    source=ModelsTestsProgram_bin,
    target='model-mock-content',
    action=ModelsTestsProgram_URI+
        ' --log_level='+logLevel+
        ' --random='+randomOrder+
        ' --show_progress='+showProgress
)
Depends(
    ModelsTestsProgram_run,
    ModelsTestsProgram_bin
)
AlwaysBuild(ModelsTestsProgram_run)
testEnv.Alias('runModelsTests', ModelsTestsProgram_run)

################################################################################

# Builds parser and scanner classes

FnB_Parser_yy_URI   = fnb        +'parser.yy'
GTL_Parser_cpp_URI  = source +gtl+'parser.cpp'
GTL_Parser_hpp_URI  = include+gtl+'parser.hpp'
FnB_Scanner_ll_URI  = fnb        +'scanner.ll'
GTL_Scanner_cpp_URI = source +gtl+'scanner.cpp'

GTL_Parser_cpp = env.CXXFile(
    source=FnB_Parser_yy_URI,
    target=GTL_Parser_cpp_URI,
    YACCFLAGS=['--defines='+GTL_Parser_hpp_URI, '--verbose']
)
GTL_Scanner_cpp = env.CXXFile(
    source=FnB_Scanner_ll_URI,
    target=GTL_Scanner_cpp_URI
)
env.Alias('buildParserClasses', [GTL_Parser_cpp, GTL_Scanner_cpp])

################################################################################

# Build GTL objects

GTL = [
    env.Object(
        source=GTL_cpp,
        target=targetForSource(GTL_cpp)
    )
    for GTL_cpp in Glob(source+gtl+'*.cpp')
    if  not GTL_cpp.name.endswith('scanner.cpp')
    and not GTL_cpp.name.endswith('parser.cpp')
] + [
    parserEnv.Object(
        source=GTL_cpp,
        target=targetForSource(GTL_cpp)
    )
    for GTL_cpp in Glob(source+gtl+'*.cpp')
    if GTL_cpp.name.endswith('scanner.cpp')
    or GTL_cpp.name.endswith('parser.cpp')
]
Depends(
    GTL,
    ModelsTestsProgram_run
)
env.Alias('buildGTL', GTL)

################################################################################

# Build GTL's Tests objects

GTLTests = [
    testEnv.Object(
        source=GTLTest_cpp,
        target=targetForTest(GTLTest_cpp)
    )
    for GTLTest_cpp in Glob(test+gtl+'*.cpp')
]
testEnv.Alias('buildGTLTests', GTLTests)

################################################################################

# Build and run GTL tests

GTLTestsProgram_URI = programs+'GTLTests'
GTLTestsProgram_bin = testEnv.Program(
    source=Models + GTL + GTLTests,
    target=GTLTestsProgram_URI
)
GTLTestsProgram_run = Command(
    source=GTLTestsProgram_bin,
    target='gtl-mock-content',
    action=GTLTestsProgram_URI+
        ' --log_level='+logLevel+
        ' --random='+randomOrder+
        ' --show_progress='+showProgress
)
Depends(
    GTLTestsProgram_run,
    GTLTestsProgram_bin
)
AlwaysBuild(GTLTestsProgram_run)
testEnv.Alias('runGTLTests', GTLTestsProgram_run)
