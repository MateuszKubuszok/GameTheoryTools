# Directories configuration

# Main directories
fnb     = 'f_n_b/'
headers = 'headers/'
source  = 'src/'
objects = 'objects/'

# Packages directories
gtl   = 'gt/gtl/'
model = 'gt/model/'

################################################################################

# Begining of Environment configuration
env  = Environment()
conf = Configure(env)

validInstallation = True

# C++ check
if not conf.CheckCXX():
    print('Your Environment/C++ compiler is not configured/installed correctly!!')
    validInstallation = False

# Header check
for header in [
    # standard libraries
    'iostream', 'fstream', 'cstdlib',
    # boost libraries
    'boost/shared_ptr.hpp',
    'boost/container/map.hpp',
    'boost/container/vector.hpp',
    'boost/thread/mutex.hpp',
    # Flex library
    'FlexLexer.h',
    # GNU MultiPrecision library
    'gmpxx.h',
]:
    if not conf.CheckCXXHeader(header):
        print('Your environment does not seem to have header <'+header+'>!!')
        validInstallation = False

if not validInstallation:
    Exit(1)

# Adds headers dirs:
# - headers/ - public headers directory,
# - headers/gt/gtl - added for using parser.hpp in GT::GTL::Scanner
#   (poor custom path definitions),
# - src/gt/gtl - added for using location.hh, position.hh and stack.hh
#   in GT::GTL::Parser (as above).
conf.env.Append(CPPPATH=[headers, headers+gtl, source+gtl])

conf.Finish()
# End of Environment configuration

################################################################################

# Builds parser and scanner classes

parserYYPath   = fnb        +'parser.yy'
parserCppPath  = source +gtl+'parser.cpp'
parserHppPath  = headers+gtl+'parser.hpp'
scannerLLPath  = fnb        +'scanner.ll'
scannerCppPath = source +gtl+'scanner.cpp'

env.Append(YACCFLAGS='--defines='+parserHppPath)
parserCpp, parserHpp = env.CXXFile(source=parserYYPath,  target=parserCppPath)
scannerCpp           = env.CXXFile(source=scannerLLPath, target=scannerCppPath)

################################################################################

# Builds GTL objects

objectCppPath = source +gtl+'object.cpp'
objectOPath   = objects+gtl+'object.o'
paramCppPath  = source +gtl+'param.cpp'
paramOPath    = objects+gtl+'param.o'

objectO = env.Object(source=objectCppPath, target=objectOPath)
paramO  = env.Object(source=paramCppPath,  target=paramOPath)

parserOPath  = objects+gtl+'parser.o'
scannerOPath = objects+gtl+'scanner.o'

parserO  = env.Object(source=parserCpp,  target=parserOPath)
scannerO = env.Object(source=scannerCpp, target=scannerOPath)
