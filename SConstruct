import os

##############################################################################################################

useStaticLink = ARGUMENTS.get('static', 0)

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

def targetForStatic(file):
    return str(file).replace('.cpp', env['OBJSUFFIX']).replace(source, objects)

def targetForShared(file):
    return str(file).replace('.cpp', env['SHOBJSUFFIX']).replace(source, objects)

def targetForExecutable(file):
    return str(file).replace(env['OBJSUFFIX'], env['PROGSUFFIX']).replace(objects+main, programs+'gtl_')

def targetForTest(file):
    return str(file).replace('.cpp', '_test'+env['OBJSUFFIX']).replace(test, objects)

##############################################################################################################

# Production environment configuration

env = Environment()

# Allows overridding default compiler with eg. Clang.
env["CC"]  = os.getenv("CC")  or env["CC"]
env["CXX"] = os.getenv("CXX") or env["CXX"]
env["ENV"].update(x for x in os.environ.items() if x[0].startswith("CCC_"))

# Assuming that instalation is valid unless proved otherwise
validInstallation = True

conf = Configure(env)

# C++ check
if not conf.CheckCXX():
    print('Your environment/C++ compiler is not configured/installed correctly!!')
    validInstallation = False

# Header check
for header in [
    # standard libraries
    'algorithm', 'cstdlib', 'iomanip',
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
    # Flex library
    'FlexLexer.h',
    # GNU Multiple Precision library
    'gmpxx.h'
]:
    if not conf.CheckCXXHeader(header):
        print('Your environment does not seem to have header <'+header+'>!!')
        validInstallation = False

# Libraries
libraries = [
    # GNU Multiple Precision library
    'gmp', 'gmpxx'
]

# Library check
for library in libraries:
    if not conf.CheckLib(library):
        print('Your environment does not seem to have library <'+library+'>!!')
        validInstallation = False

# Sets C++11 standard to be used during compilation.
# Makes executables contain debug information.
conf.env.Append(CPPFLAGS=['-std=c++11', '-g'])

# Adds headers dirs:
# - include/ - public include directory,
# - include/gt/gtl - added for using parser.hpp in GT::GTL::Scanner (poor custom path definitions), as well
#   as for location.hh, position.hh and stack.hh
# - src/ - added for implemetnations headers.
conf.env.Append(CPPPATH=[include, include+gtl, source])

# Sets used libraries.
conf.env.Append(LIBS=libraries)

conf.Finish()

# Creates separate environment for parser and scanner
parserEnv = env.Clone()

# Sets warning informations in main conf.
env.Append(CPPFLAGS=['-Wall', '-Wextra', '-pedantic'])

##############################################################################################################

# Executables environment configuration

executablesEnv  = env.Clone()
executablesConf = Configure(executablesEnv)

executablesLibraries = [
    # boost libraries
    'boost_program_options'
]

# Library check
for library in executablesLibraries:
    if not executablesConf.CheckLib(library):
        print('Your environment does not seem to have library <'+library+'>!!')
        validInstallation = False

# Sets used libraries.
executablesConf.env.Append(LIBS=executablesLibraries)

# Sets up linking method
if useStaticLink:
    executablesConf.env.Append(LINKFLAGS='--static')

executablesConf.Finish()

##############################################################################################################

# Test environment configuration

testEnv  = env.Clone()
testConf = Configure(testEnv)

# Header check
for header in [
    # boost libraries
    'boost/test/unit_test.hpp',
    'boost/test/test_tools.hpp'
]:
    if not testConf.CheckCXXHeader(header):
        print('Your environment does not seem to have header <'+header+'>!!')
        validInstallation = False

# Libraries
testLibraries = [
    # boost libraries
    'boost_unit_test_framework'
]

# Library check
for library in testLibraries:
    if not testConf.CheckLib(library):
        print('Your environment does not seem to have library <'+library+'>!!')
        validInstallation = False

# Adds tests directories to the path:
# - test
testConf.env.Append(CPPPATH=[test])

# Sets used libraries.
testConf.env.Append(LIBS=testLibraries)

testConf.Finish()

logLevel     = 'message'    # log level for Boost Test Framework
randomOrder  = '1'          # whether tests should be run in random order
showProgress = 'yes'        # should progress bar be displayed

##############################################################################################################

# Test executables environment configuration

executablesTestEnv  = testEnv.Clone()
executablesTestConf = Configure(executablesTestEnv)

# Libraries
executablesTestLibraries = [
    # boost libraries
    'boost_program_options'
]

# Library check
for library in list(set(executablesTestLibraries) - set(executablesLibraries) - set(testLibraries)):
    if not executablesTestConf.CheckLib(library):
        print('Your environment does not seem to have library <'+library+'>!!')
        validInstallation = False

# Sets used libraries.
executablesTestConf.env.Append(LIBS=executablesTestLibraries)

executablesTestConf.Finish()

##############################################################################################################

# Validate installation

# Terminate build if installation is not valid
if not validInstallation:
    print('Invalid compiler/libraries installation - build terminated!!')
    Exit(1)

##############################################################################################################

# Build Model objects

Models = [
    env.StaticObject(
        source=Model_cpp,
        target=targetForStatic(Model_cpp)
    )
    for Model_cpp in Glob(source+model+'*.cpp')
]
SharedModels = [
    env.SharedObject(
        source=Model_cpp,
        target=targetForShared(Model_cpp)
    )
    for Model_cpp in Glob(source+model+'*.cpp')
]
env.Alias('buildModels', Models)

##############################################################################################################

# Build Models' Tests objects

ModelsTests = [
    testEnv.StaticObject(
        source=ModelTest_cpp,
        target=targetForTest(ModelTest_cpp)
    )
    for ModelTest_cpp in Glob(test+model+'*.cpp')
]
testEnv.Alias('buildModelsTests', ModelsTests)

##############################################################################################################

# Build and run Model tests

ModelsTestsProgram_URI = programs+'ModelsTests'+env['PROGSUFFIX']
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
    env.StaticObject(
        source=Routine_cpp,
        target=targetForStatic(Routine_cpp)
    )
    for Routine_cpp in Glob(source+routines+'*.cpp')
]
SharedRoutines = [
    env.SharedObject(
        source=Routine_cpp,
        target=targetForShared(Routine_cpp)
    )
    for Routine_cpp in Glob(source+routines+'*.cpp')
]
Depends(
    [Routines, SharedRoutines],
    ModelsTestsProgram_run
)
env.Alias('buildRoutines', Routines)

##############################################################################################################

# Build Routines' Tests objects

RoutinesTests = [
    testEnv.StaticObject(
        source=RoutineTest_cpp,
        target=targetForTest(RoutineTest_cpp)
    )
    for RoutineTest_cpp in Glob(test+routines+'*.cpp')
]
testEnv.Alias('buildRoutinesTests', RoutinesTests)

##############################################################################################################

# Build and run Routine tests

RoutinesTestsProgram_URI = programs+'RoutinesTests'+env['PROGSUFFIX']
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
    parserEnv.StaticObject(
        source=GTL_cpp,
        target=targetForStatic(GTL_cpp)
    )
    for GTL_cpp in Glob(source+gtl+'*.cpp')
    if  GTL_cpp.name.endswith('scanner.cpp')
    or  GTL_cpp.name.endswith('parser.cpp')
] + [
    env.StaticObject(
        source=GTL_cpp,
        target=targetForStatic(GTL_cpp)
    )
    for GTL_cpp in Glob(source+gtl+'*.cpp')
    if  not GTL_cpp.name.endswith('scanner.cpp')
    and not GTL_cpp.name.endswith('parser.cpp')
]
SharedGTL = [
    parserEnv.SharedObject(
        source=GTL_cpp,
        target=targetForShared(GTL_cpp)
    )
    for GTL_cpp in Glob(source+gtl+'*.cpp')
    if  GTL_cpp.name.endswith('scanner.cpp')
    or  GTL_cpp.name.endswith('parser.cpp')
] + [
    env.SharedObject(
        source=GTL_cpp,
        target=targetForShared(GTL_cpp)
    )
    for GTL_cpp in Glob(source+gtl+'*.cpp')
    if  not GTL_cpp.name.endswith('scanner.cpp')
    and not GTL_cpp.name.endswith('parser.cpp')
]
Depends(
    [GTL, SharedGTL],
    [ModelsTestsProgram_run, RoutinesTestsProgram_run, CorrectBisonInstallation]
)
env.Alias('buildGTL', GTL)

##############################################################################################################

# Build GTL's Tests objects

GTLTests = [
    testEnv.StaticObject(
        source=GTLTest_cpp,
        target=targetForTest(GTLTest_cpp)
    )
    for GTLTest_cpp in Glob(test+gtl+'*.cpp')
]
testEnv.Alias('buildGTLTests', GTLTests)

##############################################################################################################

# Build and run GTL tests

GTLTestsProgram_URI = programs+'GTLTests'+env['PROGSUFFIX']
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
    env.StaticObject(
        source=Program_cpp,
        target=targetForStatic(Program_cpp)
    )
    for Program_cpp in Glob(source+program+'*.cpp')
]
SharedPrograms = [
    env.SharedObject(
        source=Program_cpp,
        target=targetForShared(Program_cpp)
    )
    for Program_cpp in Glob(source+program+'*.cpp')
]
Depends(
    [Programs, SharedPrograms],
    GTLTestsProgram_run
)
env.Alias('buildPrograms', Programs)

##############################################################################################################

# Build Program's Tests objects

ProgramsTests = [
    testEnv.StaticObject(
        source=ProgramTest_cpp,
        target=targetForTest(ProgramTest_cpp)
    )
    for ProgramTest_cpp in Glob(test+program+'*.cpp')
]
testEnv.Alias('buildProgramsTests', ProgramsTests)

##############################################################################################################

# Build and run Program's tests

ProgramsTestsProgram_URI = programs+'ProgramsTests'+env['PROGSUFFIX']
ProgramsTestsProgram_bin = executablesTestEnv.Program(
    source=Models + Routines + GTL + Programs + ProgramsTests,
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

# Build libraries

GTTStaticLibrary_URI = programs+'GTT'+env['LIBSUFFIX']
GTTStaticLibrary_bin = env.Library(
    source=Models + Routines + GTL + Programs,
    target=GTTStaticLibrary_URI
)
GTTSharedLibrary_URI = programs+'GTT'+env['SHLIBSUFFIX']
GTTSharedLibrary_bin = env.SharedLibrary(
    source=SharedModels + SharedRoutines + SharedGTL + SharedPrograms,
    target=GTTSharedLibrary_URI
)
Depends(
    [GTTStaticLibrary_bin, GTTSharedLibrary_bin],
    [CorrectBisonInstallation, ProgramsTestsProgram_run]
)
env.Alias('buildLibraries', [GTTStaticLibrary_bin, GTTSharedLibrary_bin])

##############################################################################################################

# Build main containing objects

Mains = [
    env.StaticObject(
        source=Main_cpp,
        target=targetForStatic(Main_cpp)
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
