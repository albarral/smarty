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
	${OBJECTDIR}/src/smarty/agent/AgentModule.o \
	${OBJECTDIR}/src/smarty/agent/core/AgentBus.o \
	${OBJECTDIR}/src/smarty/agent/core/AgentData.o


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
LDLIBSOPTIONS=-Wl,-rpath,../smart_task/dist/Debug/GNU-Linux -L../smart_task/dist/Debug/GNU-Linux -lsmart_task -Wl,-rpath,../../tron/tron_control/dist/Debug/GNU-Linux -L../../tron/tron_control/dist/Debug/GNU-Linux -ltron_control

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT}: ../smart_task/dist/Debug/GNU-Linux/libsmart_task.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT}: ../../tron/tron_control/dist/Debug/GNU-Linux/libtron_control.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/smarty/agent/AgentModule.o: src/smarty/agent/AgentModule.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/agent
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../smart_task/src -I../../tron/tron_control/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/agent/AgentModule.o src/smarty/agent/AgentModule.cpp

${OBJECTDIR}/src/smarty/agent/core/AgentBus.o: src/smarty/agent/core/AgentBus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/agent/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../smart_task/src -I../../tron/tron_control/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/agent/core/AgentBus.o src/smarty/agent/core/AgentBus.cpp

${OBJECTDIR}/src/smarty/agent/core/AgentData.o: src/smarty/agent/core/AgentData.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/agent/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../smart_task/src -I../../tron/tron_control/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/agent/core/AgentData.o src/smarty/agent/core/AgentData.cpp

# Subprojects
.build-subprojects:
	cd ../smart_task && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tron_control && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_agent.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../smart_task && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tron_control && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
