project(HardwareExtensionInterfaceIODemo)



add_executable(${PROJECT_NAME}
	src/main.cpp
)

if(WIN32 AND MSVC)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif(WIN32 AND MSVC)

target_include_directories(${PROJECT_NAME} PRIVATE external/AntilatencySDK/Api)
target_include_directories(${PROJECT_NAME} PRIVATE external/rapidjson/include)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/external/AntilatencySDK/Bin/WindowsDesktop/x64"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
		
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
			${CMAKE_SOURCE_DIR}/configs $<TARGET_FILE_DIR:${PROJECT_NAME}>/configs)