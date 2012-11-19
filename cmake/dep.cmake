#here we include the dependencies required for the project
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#PKGConfig and GTK+
FIND_PACKAGE(PkgConfig REQUIRED)

PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

#LibCurl
PKG_CHECK_MODULES(CURL REQUIRED libcurl)
INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIRS})
LINK_DIRECTORIES(${CURL_LIBRARIES})
MESSAGE(STATUS "CURL FOUND: '${CURL_LIBRARIES}'")

#LibOAUTH
PKG_CHECK_MODULES(OAuth REQUIRED oauth)
INCLUDE_DIRECTORIES(${OAuth_INCLUDE_DIR})
LINK_DIRECTORIES(${OAuth_LIBRARIES})
MESSAGE(STATUS "OAUTH FOUND: '${OAuth_LIBRARIES}'")

#LibNotify
PKG_CHECK_MODULES(LIBNOTIFY REQUIRED libnotify)
INCLUDE_DIRECTORIES (${LIBNOTIFY_INCLUDE_DIR})
LINK_DIRECTORIES (${LIBNOTIFY_LIBRARIES})
MESSAGE(STATUS "NOTIFY FOUND: '${LIBNOTIFY_LIBRARIES}'")

#gthread-2.0
PKG_CHECK_MODULES(GTHREAD REQUIRED gthread-2.0 )
INCLUDE_DIRECTORIES (${GTHREAD_INCLUDE_DIR})
LINK_DIRECTORIES (${GTHREAD_LIBRARIES})
MESSAGE(STATUS "NOTIFY FOUND: '${LIBNOTIFY_LIBRARIES}'")


#LibXML2
FIND_PACKAGE (LibXml2 REQUIRED)
INCLUDE_DIRECTORIES (${LIBXML2_INCLUDE_DIR})
ADD_DEFINITIONS (${LIBXML2_DEFINITIONS})
