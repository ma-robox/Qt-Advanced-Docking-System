#
#	Libreria: ads
#

add_compile_definitions(ADS_SHARED_EXPORT)

set(R_RCFILE
	)

set(R_SOURCES
	ads_globals.cpp
	AutoHideDockContainer.cpp
	AutoHideSideBar.cpp
	AutoHideTab.cpp
	DockAreaTabBar.cpp
	DockAreaTitleBar.cpp
	DockAreaWidget.cpp
	DockComponentsFactory.cpp
	DockContainerWidget.cpp
	DockFocusController.cpp
	DockingStateReader.cpp
	DockManager.cpp
	DockOverlay.cpp
	DockSplitter.cpp
	DockWidget.cpp
	DockWidgetTab.cpp
	ElidingLabel.cpp
	FloatingDockContainer.cpp
	FloatingDragPreview.cpp
	IconProvider.cpp
	PushButton.cpp
	ResizeHandle.cpp
	)

set(R_HEADERS
	ads_globals.h
	AutoHideDockContainer.h
	AutoHideSideBar.h
	AutoHideTab.h
	DockAreaTabBar.h
	DockAreaTitleBar.h
	DockAreaTitleBar_p.h
	DockAreaWidget.h
	DockComponentsFactory.h
	DockContainerWidget.h
	DockFocusController.h
	DockingStateReader.h
	DockManager.h
	DockOverlay.h
	DockSplitter.h
	DockWidget.h
	DockWidgetTab.h
	ElidingLabel.h
	FloatingDockContainer.h
	FloatingDragPreview.h
	IconProvider.h
	PushButton.h
	ResizeHandle.h
	)
	
set(R_PCH
	pch.h
	)

set(R_RESOURCES
	ads.qrc
	)

set(R_FORMS
	)

set(R_TRANSLATIONS
	ts/${RDE_LIB_PREFIX}ads_it.ts
	ts/${RDE_LIB_PREFIX}ads_zh.ts
	)

set(R_QT_COMPONENTS
	Widgets
	)

set(R_LINK_LIBRARIES
	tool
	)

if(UNIX AND NOT APPLE)
	list(APPEND R_HEADERS linux/FloatingWidgetTitleBar.h)
	list(APPEND R_SOURCES linux/FloatingWidgetTitleBar.cpp)
	list(APPEND R_LINK_LIBRARIES xcb)
	# QT += gui-private
	# TODO include_directories(${Qt${QT_VERSION_MAJOR}Quick_PRIVATE_INCLUDE_DIRS})
endif()

#
#	Libreria ads
#
add_rde_lib(ads)
