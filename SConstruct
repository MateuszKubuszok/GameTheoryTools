# Begining of Environment configuration
env  = Environment()
conf = Configure(env)

validInstallation = True

# C++ check
if not conf.CheckCXX():
    print('Your Environment/C++ compiler is not configured installed correctly!!')
    validInstallation = False

# Header check
for header in [
    'iostream', 'fstream', 'cstdlib',
    'boost/container/map.hpp',
    'boost/container/slist.hpp',
    'boost/thread/mutex.hpp',
    'FlexLexer.h',
    'gmpxx.h',
]:
    if not conf.CheckCXXHeader(header):
        print('Your environment does not seem to have header '+header+'!!')
        validInstallation = False

if not validInstallation:
    Exit(1)

conf.Finish()
# End of Environment configuration

################################################################################

# Main directories
fnb     = 'f_n_b/'
headers = 'headers/'
source  = 'src/'

# Packages directories
gtl   = 'gt/gtl/'
model = 'gt/model/'

################################################################################

# Builds parser and scanner classes

parserYY   = fnb+'parser.yy'
parserCpp  = source+gtl+'parser.cpp'
parserHpp  = headers+gtl+'parser.hpp'
scannerLL  = fnb+'scanner.ll'
scannerCpp = source+gtl+'scanner.cpp'

env.Append(YACCFLAGS='--defines='+parserHpp)
parserCppBuilder, parserHppBuilder = env.CXXFile(source=parserYY,  target=parserCpp)
scannerCppBuilder                  = env.CXXFile(source=scannerLL, target=scannerCpp)

################################################################################
