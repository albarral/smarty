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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/smarty/learn/Learn.o \
	${OBJECTDIR}/src/smarty/learn/State.o \
	${OBJECTDIR}/src/smarty/learn/StatePk.o \
	${OBJECTDIR}/src/smarty/learn/Task.o \
	${OBJECTDIR}/src/smarty/learn/Transition.o \
	${OBJECTDIR}/src/smarty/learn/TransitionPk.o \
	${OBJECTDIR}/src/smarty/learn/db/TransitionDB.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_learn.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_learn.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_learn.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/smarty/learn/Learn.o: src/smarty/learn/Learn.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/learn
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/learn/Learn.o src/smarty/learn/Learn.cpp

${OBJECTDIR}/src/smarty/learn/State.o: src/smarty/learn/State.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/learn
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/learn/State.o src/smarty/learn/State.cpp

${OBJECTDIR}/src/smarty/learn/StatePk.o: src/smarty/learn/StatePk.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/learn
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/learn/StatePk.o src/smarty/learn/StatePk.cpp

${OBJECTDIR}/src/smarty/learn/Task.o: src/smarty/learn/Task.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/learn
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/learn/Task.o src/smarty/learn/Task.cpp

${OBJECTDIR}/src/smarty/learn/Transition.o: src/smarty/learn/Transition.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/learn
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/learn/Transition.o src/smarty/learn/Transition.cpp

${OBJECTDIR}/src/smarty/learn/TransitionPk.o: src/smarty/learn/TransitionPk.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/learn
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/learn/TransitionPk.o src/smarty/learn/TransitionPk.cpp

${OBJECTDIR}/src/smarty/learn/db/TransitionDB.o: src/smarty/learn/db/TransitionDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/smarty/learn/db
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/smarty/learn/db/TransitionDB.o src/smarty/learn/db/TransitionDB.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsmart_learn.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
