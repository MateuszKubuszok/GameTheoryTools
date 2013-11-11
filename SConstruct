import os

##############################################################################################################

# Directories configuration

# Main directories
fnb      = 'f_n_b/'
include  = 'include/'
source   = 'src/'
test     = 'test/'
objects  = 'objects/'
programs = 'bin/'

# Packages directories
gtl      = 'gt/gtl/'
main     = 'gt/main/'
model    = 'gt/model/'
program  = 'gt/program/'
routines = 'gt/routines/'

##############################################################################################################

# Helpers for building objects and programs

def targetForSource(file):
    return str(file).replace('.cpp', '.o').replace(source, objects)

def targetForExecutable(file):
    return str(file).replace('.o', '').replace(objects+main, programs+'gtl_')

def targetForTest(file):
    return str(file).replace('.cpp', '_test.o').replace(test, objects)

##############################################################################################################

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
    'algorithm', 'cstdlib',
    'iostream',  'fstream', 'sstream',
    'stdexcept', 'string',  'utility',
    # boost libraries
    'boost/scoped_ptr.hpp',
    'boost/shared_ptr.hpp',
    'boost/weak_ptr.hpp',
    'boost/algorithm/string.hpp',
    'boost/assign.hpp',
    'boost/bimap/bimap.hpp',
    'boost/container/map.hpp',
    'boost/container/set.hpp',
    'boost/container/vector.hpp',
    'boost/program_options.hpp',
    'boost/range/adaptor/map.hpp',
    'boost/range/adaptor/reversed.hpp',
    'boost/thread/mutex.hpp',
    # Flex library
    'FlexLexer.h',
    # GNU Multiple Precision library
    'gmpxx.h'
]:
    if not conf.CheckCXXHeader(header):
        print('Your environment does not seem to have header <'+header+'>!!')
        validInstallation = False

# Terminate build if installation is not valid
if not validInstallation:
    print('Invalid compiler/libraries installation - build terminated!!')
    Exit(1)

# Sets C++11 standard to be used during compilation.
# Makes executables contain debug information.
conf.env.Append(CPPFLAGS=['-std=c++11', '-g'])

# Adds headers dirs:
# - include/ - public include directory,
# - include/gt/gtl - added for using parser.hpp in GT::GTL::Scanner (poor custom path definitions), as well
#   as for location.hh, position.hh and stack.hh
# - src/ - added for implemetnations headers.
conf.env.Append(CPPPATH=[include, include+gtl, source])

# Sets used libraries to:
# - gmp - GNU Multiple Precision library,
# - gmpxx - C++ wrappers for GMP.
conf.env.Append(LIBS=['gmp', 'gmpxx'])

conf.Finish()

# Creates separate environment for parser and scanner
parserEnv = env.Clone()

# Sets warning informations in main conf.
env.Append(CPPFLAGS=['-Wall', '-Wextra', '-pedantic'])

##############################################################################################################

# Executables environment configuration

executablesEnv  = env.Clone()
executablesConf = Configure(executablesEnv)

# Makes executables compile with Boost Program Options library.
executablesConf.env.Append(LIBS=['boost_program_options'])

executablesConf.Finish()

##############################################################################################################

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
testConf.env.Append(CPPPATH=[test])
testConf.env.Append(LIBS=['boost_unit_test_framework'])

testConf.Finish()

logLevel     = 'message'    # log level for Boost Test Framework
randomOrder  = '0'          # whether tests should be run in random order
showProgress = 'yes'        # should progress bar be displayed

##############################################################################################################

# Test executables environment configuration

executablesTestEnv  = testEnv.Clone()
executablesTestConf = Configure(executablesTestEnv)

# Makes executables compile with Boost Program Options library.
executablesTestConf.env.Append(LIBS=['boost_program_options'])

executablesTestConf.Finish()

##############################################################################################################

# Build Model objects

Models = [
    env.Object(
        source=Model_cpp,
        target=targetForSource(Model_cpp)
    )
    for Model_cpp in Glob(source+model+'*.cpp')
]
env.Alias('buildModels', Models)

##############################################################################################################

# Build Models' Tests objects

ModelsTests = [
    testEnv.Object(
        source=ModelTest_cpp,
        target=targetForTest(ModelTest_cpp)
    )
    for ModelTest_cpp in Glob(test+model+'*.cpp')
]
testEnv.Alias('buildModelsTests', ModelsTests)

##############################################################################################################

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

##############################################################################################################

# Build Routines objects

Routines = [
    env.Object(
        source=Routine_cpp,
        target=targetForSource(Routine_cpp)
    )
    for Routine_cpp in Glob(source+routines+'*.cpp')
]
Depends(
    Routines,
    ModelsTestsProgram_run
)
env.Alias('buildRoutines', Routines)

##############################################################################################################

# Build Routines' Tests objects

RoutinesTests = [
    testEnv.Object(
        source=RoutineTest_cpp,
        target=targetForTest(RoutineTest_cpp)
    )
    for RoutineTest_cpp in Glob(test+routines+'*.cpp')
]
testEnv.Alias('buildRoutinesTests', RoutinesTests)

##############################################################################################################

# Build and run Routine tests

RoutinesTestsProgram_URI = programs+'RoutinesTests'
RoutinesTestsProgram_bin = testEnv.Program(
    source=Models + Routines + RoutinesTests,
    target=RoutinesTestsProgram_URI
)
RoutinesTestsProgram_run = Command(
    source=RoutinesTestsProgram_bin,
    target='routines-mock-content',
    action=RoutinesTestsProgram_URI+
        ' --log_level='+logLevel+
        ' --random='+randomOrder+
        ' --show_progress='+showProgress
)
Depends(
    RoutinesTestsProgram_run,
    RoutinesTestsProgram_bin
)
AlwaysBuild(RoutinesTestsProgram_run)
testEnv.Alias('runRoutinesTests', RoutinesTestsProgram_run)

##############################################################################################################

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

CorrectBisonInstallation = [
    env.Command(
        include+gtl+WronglyPlacedBisonHelper_hh.name,
        WronglyPlacedBisonHelper_hh,
        Move("$TARGET", "$SOURCE")
    )
    for WronglyPlacedBisonHelper_hh in Glob(source+gtl+'*.hh')
    if  WronglyPlacedBisonHelper_hh.name in [
        'location.hh',
        'position.hh',
        'stack.hh'
    ]
]
Depends(
    CorrectBisonInstallation,
    [GTL_Parser_cpp, GTL_Scanner_cpp]
)

env.Alias('buildParserClasses', CorrectBisonInstallation)

##############################################################################################################

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
    if  GTL_cpp.name.endswith('scanner.cpp')
    or  GTL_cpp.name.endswith('parser.cpp')
]
Depends(
    GTL,
    [ModelsTestsProgram_run, RoutinesTestsProgram_run, CorrectBisonInstallation]
)
env.Alias('buildGTL', GTL)

##############################################################################################################

# Build GTL's Tests objects

GTLTests = [
    testEnv.Object(
        source=GTLTest_cpp,
        target=targetForTest(GTLTest_cpp)
    )
    for GTLTest_cpp in Glob(test+gtl+'*.cpp')
]
testEnv.Alias('buildGTLTests', GTLTests)

##############################################################################################################

# Build and run GTL tests

GTLTestsProgram_URI = programs+'GTLTests'
GTLTestsProgram_bin = testEnv.Program(
    source=Models + Routines + GTL + GTLTests,
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

##############################################################################################################

# Build Program's objects

Programs = [
    env.Object(
        source=Program_cpp,
        target=targetForSource(Program_cpp)
    )
    for Program_cpp in Glob(source+program+'*.cpp')
]
Depends(
    Programs,
    GTLTestsProgram_run
)
env.Alias('buildPrograms', Programs)

##############################################################################################################

# Build Program's Tests objects

ProgramsTests = [
    testEnv.Object(
        source=ProgramTest_cpp,
        target=targetForTest(ProgramTest_cpp)
    )
    for ProgramTest_cpp in Glob(test+program+'*.cpp')
]
testEnv.Alias('buildProgramsTests', ProgramsTests)

##############################################################################################################

# Build and run Program's tests

ProgramsTestsProgram_URI = programs+'ProgramsTests'
ProgramsTestsProgram_bin = executablesTestEnv.Program(
    source=Models + GTL + Programs + ProgramsTests,
    target=ProgramsTestsProgram_URI
)
ProgramsTestsProgram_run = Command(
    source=ProgramsTestsProgram_bin,
    target='programs-mock-content',
    action=ProgramsTestsProgram_URI+
        ' --log_level='+logLevel+
        ' --random='+randomOrder+
        ' --show_progress='+showProgress
)
Depends(
    ProgramsTestsProgram_run,
    ProgramsTestsProgram_bin
)
AlwaysBuild(ProgramsTestsProgram_run)
executablesTestEnv.Alias('runProgramsTests', ProgramsTestsProgram_run)

##############################################################################################################

# Build main containing objects

Mains = [
    env.Object(
        source=Main_cpp,
        target=targetForSource(Main_cpp)
    )
    for Main_cpp in Glob(source+main+'*.cpp')
]

##############################################################################################################

# Build actual executables

ExecutablesPrograms = [
    executablesEnv.Program(
        source=Models + Routines + GTL + Programs + Main_o,
        target=targetForExecutable(Main_o[0])
    )
    for Main_o in Mains
]
Depends(
    ExecutablesPrograms,
    ProgramsTestsProgram_run
)
env.Alias('buildExecutables', ExecutablesPrograms)
