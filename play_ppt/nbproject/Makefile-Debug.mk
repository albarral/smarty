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
	${OBJECTDIR}/src/play/ppt/WorldPPT.o


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
LDLIBSOPTIONS=-Wl,-rpath,../play_utils/dist/Debug/GNU-Linux -L../play_utils/dist/Debug/GNU-Linux -lplay_utils -Wl,-rpath,../../tron/tron_control/dist/Debug/GNU-Linux -L../../tron/tron_control/dist/Debug/GNU-Linux -ltron_control -Wl,-rpath,../../tron/tron_display/dist/Debug/GNU-Linux -L../../tron/tron_display/dist/Debug/GNU-Linux -ltron_display -Wl,-rpath,../../tron/tron_tools/dist/Debug/GNU-Linux -L../../tron/tron_tools/dist/Debug/GNU-Linux -ltron_tools -llog4cxx -lopencv_core -lopencv_highgui

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/playPPT

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/playPPT: ../play_utils/dist/Debug/GNU-Linux/libplay_utils.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/playPPT: ../../tron/tron_control/dist/Debug/GNU-Linux/libtron_control.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/playPPT: ../../tron/tron_display/dist/Debug/GNU-Linux/libtron_display.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/playPPT: ../../tron/tron_tools/dist/Debug/GNU-Linux/libtron_tools.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/playPPT: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/playPPT ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/play/ppt/WorldPPT.o: src/play/ppt/WorldPPT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/play/ppt
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../play_utils/src -I../../tron/tron_control/src -I../../tron/tron_display/src -I../../tron/tron_tools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/play/ppt/WorldPPT.o src/play/ppt/WorldPPT.cpp

# Subprojects
.build-subprojects:
	cd ../play_utils && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tron_control && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tron_display && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tron_tools && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/playPPT

# Subprojects
.clean-subprojects:
	cd ../play_utils && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tron_control && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tron_display && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tron_tools && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
