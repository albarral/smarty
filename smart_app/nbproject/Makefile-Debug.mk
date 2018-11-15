#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/smart/app/Smarty.o \
	${OBJECTDIR}/src/smart/app/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,../smart_agent/dist/Debug/GNU-Linux -L../smart_agent/dist/Debug/GNU-Linux -lsmart_agent -Wl,-rpath,../../tron/tron_control/dist/Debug/GNU-Linux -L../../tron/tron_control/dist/Debug/GNU-Linux -ltron_control -Wl,-rpath,../../tron/tron_space/dist/Debug/GNU-Linux -L../../tron/tron_space/dist/Debug/GNU-Linux -ltron_space -llog4cxx

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smarty

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smarty: ../smart_agent/dist/Debug/GNU-Linux/libsmart_agent.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smarty: ../../tron/tron_control/dist/Debug/GNU-Linux/libtron_control.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smarty: ../../tron/tron_space/dist/Debug/GNU-Linux/libtron_space.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smarty: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smarty ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/smart/app/Smarty.o: src/smart/app/Smarty.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smart/app
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../smart_agent/src -I../../tron/tron_control/src -I../../tron/tron_space/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smart/app/Smarty.o src/smart/app/Smarty.cpp

${OBJECTDIR}/src/smart/app/main.o: src/smart/app/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smart/app
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../smart_agent/src -I../../tron/tron_control/src -I../../tron/tron_space/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smart/app/main.o src/smart/app/main.cpp

# Subprojects
.build-subprojects:
	cd ../smart_agent && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tron_control && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tron_space && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smarty

# Subprojects
.clean-subprojects:
	cd ../smart_agent && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tron_control && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tron_space && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
