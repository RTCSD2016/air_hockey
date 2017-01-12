find_package(XENOMAI REQUIRED)
if(XENOMAI_FOUND)
    message("xenomai found")
endif()

find_package(ODE REQUIRED)
if(ODE_FOUND)
    message("ode found")
endif()
if(DRAWSTUFF_FOUND)
    message("drawstuff found")
endif()

INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(${XENOMAI_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${ODE_INCLUDE_DIRS})

LINK_DIRECTORIES(${XENOMAI_LIBRARIES_DIRS})
LINK_DIRECTORIES(${ODE_LIBRARIES_DIRS})

ADD_EXECUTABLE(air_hockey main.cpp common.cpp)

ADD_SUBDIRECTORY(interpolation)
#ADD_SUBDIRECTORY(physics_engine)
ADD_SUBDIRECTORY(tasks)

TARGET_LINK_LIBRARIES(air_hockey ${XENOMAI_NATIVE_SKIN_LIBS})
TARGET_LINK_LIBRARIES(air_hockey ${ODE_LIBS})
TARGET_LINK_LIBRARIES(air_hockey tasks interpolation)

# =========== TEST ===========
find_package(CppUnit)
if(CPPUNIT_FOUND)
    message("CppUnit found")
    AUX_SOURCE_DIRECTORY(./test TEST_FILES)
    ADD_EXECUTABLE(unit_test unit_test.cpp ${TEST_FILES})
    target_link_libraries(unit_test interpolation)
    target_link_libraries(unit_test ${CPPUNIT_LIBRARY})
else()
    message("CppUnit not found")
endif()
