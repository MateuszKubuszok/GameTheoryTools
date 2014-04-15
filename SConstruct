import os
import SCons.Tool

##############################################################################################################

useStaticLink = ARGUMENTS.get('Static',   0)
debugSymbols  = ARGUMENTS.get('Debug',    0)
optimization  = ARGUMENTS.get('Optimize', 0 if debugSymbols else 1)

##############################################################################################################

# Directories configuration

# Main directories
fnb      = 'f_n_b/'
include  = 'include/'
source   = 'src/'
test     = 'test/'
objects  = 'objects/' + ('debug/' if debugSymbols else 'release/')
programs = 'bin/'     + ('debug/' if debugSymbols else 'release/')

# Packages directories
gtl      = 'gt/gtl/'
main     = 'gt/main/'
model    = 'gt/model/'
program  = 'gt/program/'
routines = 'gt/routines/'

##############################################################################################################

# Used flags

GccFlags = {
    'COMMON'       : [ '-std=c++11' ],
    'WARNINGS'     : ['-Wall', '-Wextra', '-Werror', '-pedantic-errors'],
    'DEBUG'        : [ 'g' ],
    'OPTIMIZATION' : [ '-O3' ],
    'STATIC'       : [ '--static' ],
    'PCH'          : [ '-x', 'c++' ]
}

# Select used flags
Flags = GccFlags

##############################################################################################################

# Helpers for building objects and programs

def precompiledStaticHeader(env, module, origin=source, name='inner_common'):
    header     = origin+module+name
    src_suffix = '.hpp'
    suffix     = src_suffix + ('.pch' if (env['CXX'] is 'clang++') else '.gch')
    return env.Object(
        source     = header + src_suffix,
        src_suffix = src_suffix,
        target     = header + suffix,
        suffix     = suffix,
        CPPFLAGS   = env['CPPFLAGS'] + Flags['PCH']
    )

def precompiledStaticTestHeader(testEnv, module):
    return precompiledStaticHeader(testEnv, module, origin=test, name='test_common')

def targetForStatic(file):
    return str(file).replace('.cpp', env['OBJSUFFIX']).replace(source, objects)

def targetForShared(file):
    return str(file).replace('.cpp', env['SHOBJSUFFIX']).replace(source, objects)

def targetForExecutable(file):
    return str(file).replace(env['OBJSUFFIX'], env['PROGSUFFIX']).replace(objects+main, programs+'gtl_')

def targetForTest(file):
    return str(file).replace('.cpp', '_test'+env['OBJSUFFIX']).replace(test, objects)

def allFiles(file):
    return True

def buildModuleFrom(env, sources, module=None, shared=True, PCH=True, returnPCH=False):
    header  = None
    staticObjects = [
        env.StaticObject(
            source=source_cpp,
            target=targetForStatic(source_cpp)
        )
        for source_cpp in sources
    ]
    if PCH:
        header = precompiledStaticHeader(env, module)
        Depends(staticObjects, header)
    if not shared:
        return (staticObjects, header) if returnPCH else (staticObjects)
    sharedObjects = [
        env.SharedObject(
            source=source_cpp,
            target=targetForShared(source_cpp)
        )
        for source_cpp in sources
    ]
    return (staticObjects, sharedObjects, header) if returnPCH else (staticObjects, sharedObjects)

def buildModule(env, module, filter=allFiles, shared=True, PCH=True, returnPCH=False):
    sources = [source_cpp for source_cpp in Glob(source+module+'*.cpp') if filter(source_cpp)]
    return buildModuleFrom(env, sources, module, shared, PCH, returnPCH)

def buildModuleTest(testEnv, module, filter=allFiles, PCH=True, returnPCH=False):
    sources = Glob(test+module+'*.cpp')
    header  = None
    tests = [
        testEnv.StaticObject(
            source=test_cpp,
            target=targetForTest(test_cpp)
        )
        for test_cpp in sources
        if  filter(test_cpp)
    ]
    if PCH:
        header = precompiledStaticTestHeader(testEnv, module)
        Depends(tests, header)
    return (tests, header) if returnPCH else (tests)

def buildTestExecutable(testEnv, name, sources, logLevel, randomOrder, showProgress):
    testProgram_URI = programs+name+env['PROGSUFFIX']
    testProgram_bin = testEnv.Program(
        source=sources,
        target=testProgram_URI
    )
    testProgram_run = Command(
        source=testProgram_bin,
        target=name+'-mock-content',
        action=testProgram_URI+
            ' --log_level='+logLevel+
            ' --random='+randomOrder+
            ' --show_progress='+showProgress
    )
    Depends(testProgram_run, testProgram_bin)
    AlwaysBuild(testProgram_run)
    return testProgram_bin, testProgram_run

##############################################################################################################

# Production environment configuration

env = Environment()

# Allows overridding default compiler with eg. Clang.
env['CC']          = os.getenv('CC')   or env['CC']
env['CXX']         = os.getenv('CXX')  or env['CXX']
env['ENV']['PATH'] = os.getenv('PATH') or env['ENV']['PATH']
env['ENV'].update(x for x in os.environ.items() if x[0].startswith('CCC_'))

# Adding precompiled headers handling

staticPCHBuilding, sharedPCHBuilding = SCons.Tool.createObjBuilders(env)
staticPCHBuilding.add_action('.hpp',  SCons.Defaults.CXXAction)
staticPCHBuilding.add_emitter('.hpp', SCons.Defaults.StaticObjectEmitter)

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
    'limits',    'memory',
    'stdexcept', 'string',  'utility',
    'iostream',  'fstream', 'sstream',
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
    'gmpxx.h',
    # GNU Linear Package Kit
    'glpk.h'
]:
    if not conf.CheckCXXHeader(header):
        print('Your environment does not seem to have header <'+header+'>!!')
        validInstallation = False

# Libraries
libraries = [
    # GNU Multiple Precision library
    'gmp', 'gmpxx',
    # GNU Linear Package Kit
    'glpk'
]

# Library check
for library in libraries:
    if not conf.CheckLib(library=library, language="C"):
        print('Your environment does not seem to have library <'+library+'>!!')
        validInstallation = False

# Sets C++11 standard to be used during compilation.
conf.env.Append(CPPFLAGS=Flags['COMMON'])
# Makes executables contain debug information.
if debugSymbols:
    conf.env.Append(CPPFLAGS=Flags['DEBUG'])
# Turns on optimization.
if optimization:
    conf.env.Append(CPPFLAGS=Flags['OPTIMIZATION'])

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
env.Append(CPPFLAGS=Flags['WARNINGS'])

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
    if not executablesConf.CheckLib(library=library, language="C++"):
        print('Your environment does not seem to have library <'+library+'>!!')
        validInstallation = False

# Sets used libraries.
executablesConf.env.Append(LIBS=executablesLibraries)

# Sets up linking method
if useStaticLink:
    executablesConf.env.Append(LINKFLAGS=Flags['STATIC'])

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
    if not testConf.CheckLib(library=library, language="C++"):
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
    if not executablesTestConf.CheckLib(library=library, language="C++"):
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

Models, SharedModels = buildModule(env, model)
env.Alias('buildModels', Models)

##############################################################################################################

# Build Models' Tests objects

ModelsTests = buildModuleTest(testEnv, model)
testEnv.Alias('buildModelsTests', ModelsTests)

##############################################################################################################

# Build and run Model tests

ModelsTestsProgram_bin, ModelsTestsProgram_run = buildTestExecutable(testEnv,
    name         = 'ModelsTests',
    sources      = Models + ModelsTests,
    logLevel     = logLevel,
    randomOrder  = randomOrder,
    showProgress = showProgress
)
testEnv.Alias('runModelsTests', ModelsTestsProgram_run)

##############################################################################################################

# Build Routines objects

Routines, SharedRoutines = buildModule(env, routines)
Depends(
    [Routines, SharedRoutines],
    ModelsTestsProgram_run
)
env.Alias('buildRoutines', Routines)

##############################################################################################################

# Build Routines' Tests objects

RoutinesTests = buildModuleTest(testEnv, routines)
testEnv.Alias('buildRoutinesTests', RoutinesTests)

##############################################################################################################

# Build and run Routine tests

RoutinesTestsProgram_bin, RoutinesTestsProgram_run = buildTestExecutable(testEnv,
    name         = 'RoutinesTests',
    sources      = Models + Routines + RoutinesTests,
    logLevel     = logLevel,
    randomOrder  = randomOrder,
    showProgress = showProgress
)
testEnv.Alias('runRoutinesTests', RoutinesTestsProgram_run)

##############################################################################################################

# Builds parser and scanner classes

FnB_Parser_yy_URI   = fnb        +'parser.yy'
GTL_Parser_cpp_URI  = source +gtl+'parser.cpp'
GTL_Parser_hpp_URI  = include+gtl+'parser.hpp'
FnB_Scanner_ll_URI  = fnb        +'scanner.ll'
GTL_Scanner_cpp_URI = source +gtl+'scanner.cpp'

GTL_Parser_cpp, GTL_Parser_hpp = env.CXXFile(
    source=FnB_Parser_yy_URI,
    target=GTL_Parser_cpp_URI,
    YACCFLAGS=['--defines='+GTL_Parser_hpp_URI, '--verbose']
)
GTL_Scanner_cpp = env.CXXFile(
    source=FnB_Scanner_ll_URI,
    target=GTL_Scanner_cpp_URI
)

# We cant use SideEffect here because due to a bug it makes build fail
WronglyPlacedBisonHelpers = [
    'location.hh',
    'position.hh',
    'stack.hh'
]

CorrectBisonInstallation = [
    env.Command(
        include+gtl+WronglyPlacedBisonHelper_hh,
        source +gtl+WronglyPlacedBisonHelper_hh,
        Copy("$TARGET", "$SOURCE")
    )
    for WronglyPlacedBisonHelper_hh in WronglyPlacedBisonHelpers
]
Depends(
    CorrectBisonInstallation,
    GTL_Parser_hpp
)

env.Alias('buildParserClasses', CorrectBisonInstallation)

##############################################################################################################

# Build GTL objects

def notGenFile(file):
    return not file.name.endswith('scanner.cpp') and not file.name.endswith('parser.cpp')

GTLGenObjects, SharedGTLGenObjects = buildModuleFrom(
    env     = parserEnv,
    sources = [GTL_Parser_cpp, GTL_Scanner_cpp[0]],
    PCH     = False
)
GTLNotGenObjects, SharedGTLNotGenObjects = buildModule(env, gtl, filter=notGenFile, PCH=False)
Depends(precompiledStaticHeader(env, gtl), CorrectBisonInstallation)

GTL       = GTLGenObjects       + GTLNotGenObjects
SharedGTL = SharedGTLGenObjects + SharedGTLNotGenObjects
Depends(
    [GTL, SharedGTL],
    [ModelsTestsProgram_run, RoutinesTestsProgram_run, CorrectBisonInstallation]
)
env.Alias('buildGTL', GTL)

##############################################################################################################

# Build GTL's Tests objects

GTLTests, GTLTestsPCH = buildModuleTest(testEnv, gtl, returnPCH=True)
Depends(GTLTestsPCH, CorrectBisonInstallation)
testEnv.Alias('buildGTLTests', GTLTests)

##############################################################################################################

# Build and run GTL tests

GTLTestsProgram_bin, GTLTestsProgram_run = buildTestExecutable(testEnv,
    name         = 'GTLTests',
    sources      = Models + Routines + GTL + GTLTests,
    logLevel     = logLevel,
    randomOrder  = randomOrder,
    showProgress = showProgress
)
testEnv.Alias('runGTLTests', GTLTestsProgram_run)

##############################################################################################################

# Build Program's objects

Programs, SharedPrograms, ProgramsPCH = buildModule(env, program, returnPCH=True)
Depends(ProgramsPCH, CorrectBisonInstallation)
Depends(
    [Programs, SharedPrograms],
    [ModelsTestsProgram_run, RoutinesTestsProgram_run, CorrectBisonInstallation, GTLTestsProgram_run]
)
env.Alias('buildPrograms', Programs)

##############################################################################################################

# Build Program's Tests objects

ProgramsTests, ProgramsTestsPCH = buildModuleTest(testEnv, program, returnPCH=True)
Depends(ProgramsTestsPCH, CorrectBisonInstallation)
testEnv.Alias('buildProgramsTests', ProgramsTests)

##############################################################################################################

# Build and run Program's tests

ProgramsTestsProgram_bin, ProgramsTestsProgram_run = buildTestExecutable(executablesTestEnv,
    name         = 'ProgramsTests',
    sources      = Models + Routines + GTL + Programs + ProgramsTests,
    logLevel     = logLevel,
    randomOrder  = randomOrder,
    showProgress = showProgress
)
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

Mains = buildModule(env, main, shared=False, PCH=False)

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
